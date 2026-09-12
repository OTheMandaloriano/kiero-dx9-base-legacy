#include "includes.h"

#ifdef _WIN64
#define GWL_WNDPROC_INDEX GWLP_WNDPROC
#else
#define GWL_WNDPROC_INDEX GWL_WNDPROC
#endif

extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

static EndScene_t oEndScene = nullptr;
static Reset_t    oReset    = nullptr;
static WNDPROC    oWndProc  = nullptr;
static HWND       g_hWindow = nullptr;
static bool       g_bInit   = false;

// ============================================================================
// HOOK: Reset (Alt+Tab / Redimensionamento de Janela)
// ============================================================================
static long __stdcall hkReset(LPDIRECT3DDEVICE9 pDevice, D3DPRESENT_PARAMETERS* pPresentationParameters) {
    GUI::InvalidateDeviceObjects();
    long hr = oReset(pDevice, pPresentationParameters);
    if (hr >= 0) {
        GUI::CreateDeviceObjects();
    }
    return hr;
}

// ============================================================================
// HOOK: EndScene (Renderização do ImGui com StateBlock)
// ============================================================================
static long __stdcall hkEndScene(LPDIRECT3DDEVICE9 pDevice) {
    if (!pDevice)
        return oEndScene(pDevice);

    if (!g_bInit) {
        GUI::Initialize(g_hWindow, pDevice);
        g_bInit = true;
    }

    IDirect3DStateBlock9* pStateBlock = nullptr;
    if (pDevice->CreateStateBlock(D3DSBT_ALL, &pStateBlock) == D3D_OK && pStateBlock) {
        pStateBlock->Capture();
    }

    ImGui_ImplDX9_NewFrame();
    ImGui_ImplWin32_NewFrame();
    ImGui::NewFrame();

    GUI::Render();

    ImGui::EndFrame();
    ImGui::Render();
    ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());

    if (pStateBlock) {
        pStateBlock->Apply();
        pStateBlock->Release();
    }

    return oEndScene(pDevice);
}

// ============================================================================
// HOOK: WndProc (Controle de Teclas e Mouse)
// ============================================================================
static LRESULT CALLBACK hkWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    if (uMsg == WM_KEYDOWN && (wParam == VK_INSERT || wParam == VK_DELETE)) {
        Config::bMenuOpen = !Config::bMenuOpen;
        return TRUE;
    }

    if (Config::bMenuOpen && g_bInit) {
        ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam);

        ImGuiIO& io = ImGui::GetIO();
        if (io.WantCaptureMouse && (uMsg >= WM_MOUSEFIRST && uMsg <= WM_MOUSELAST))
            return TRUE;
        if (io.WantCaptureKeyboard && (uMsg == WM_KEYDOWN || uMsg == WM_KEYUP || uMsg == WM_CHAR))
            return TRUE;
    }

    return CallWindowProc(oWndProc, hWnd, uMsg, wParam, lParam);
}

// ============================================================================
// AUXILIAR: Encontrar a Janela do Processo
// ============================================================================
static BOOL CALLBACK EnumWindowsCallback(HWND handle, LPARAM lParam) {
    DWORD wndProcId = 0;
    GetWindowThreadProcessId(handle, &wndProcId);
    if (GetCurrentProcessId() != wndProcId)
        return TRUE;
    g_hWindow = handle;
    return FALSE;
}

static HWND GetProcessWindow() {
    g_hWindow = nullptr;
    EnumWindows(EnumWindowsCallback, 0);
    return g_hWindow;
}

// ============================================================================
// THREAD PRINCIPAL DE INJEÇÃO
// ============================================================================
static DWORD WINAPI MainThread(LPVOID lpReserved) {
    bool bAttached = false;
    do {
        if (kiero::init(kiero::RenderType::D3D9) == kiero::Status::Success) {
            kiero::bind(16, (void**)&oReset, (void*)hkReset);
            kiero::bind(42, (void**)&oEndScene, (void*)hkEndScene);

            do {
                g_hWindow = GetProcessWindow();
                if (!g_hWindow) Sleep(50);
            } while (g_hWindow == nullptr);

            oWndProc = (WNDPROC)SetWindowLongPtr(g_hWindow, GWL_WNDPROC_INDEX, (LONG_PTR)hkWndProc);
            bAttached = true;
        } else {
            Sleep(100);
        }
    } while (!bAttached);

    return 0;
}

// ============================================================================
// PONTO DE ENTRADA DA DLL
// ============================================================================
BOOL APIENTRY DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpReserved) {
    if (dwReason == DLL_PROCESS_ATTACH) {
        DisableThreadLibraryCalls(hModule);
        CreateThread(nullptr, 0, MainThread, hModule, 0, nullptr);
    } else if (dwReason == DLL_PROCESS_DETACH) {
        GUI::Shutdown();
        kiero::shutdown();
    }
    return TRUE;
}
