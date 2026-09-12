#include "gui.h"
#include "config.h"
#include "imgui/imgui.h"
#include "imgui/imgui_impl_win32.h"
#include "imgui/imgui_impl_dx9.h"

// Definição das variáveis de configuração centralizadas
namespace Config {
    bool  bMenuOpen      = true;
    bool  bExampleToggle = false;
    float fExampleSlider = 1.0f;
    float colExample[4]  = { 0.2f, 0.6f, 1.0f, 1.0f };
}

namespace GUI {
    static bool g_bInitialized = false;

    void Initialize(HWND hWindow, LPDIRECT3DDEVICE9 pDevice) {
        if (g_bInitialized)
            return;

        ImGui::CreateContext();
        ImGuiIO& io = ImGui::GetIO();
        io.ConfigFlags |= ImGuiConfigFlags_NoMouseCursorChange;

        // Estilização Dark moderna
        ImGui::StyleColorsDark();

        ImGui_ImplWin32_Init(hWindow);
        ImGui_ImplDX9_Init(pDevice);

        g_bInitialized = true;
    }

    void Render() {
        if (!Config::bMenuOpen)
            return;

        ImGui::SetNextWindowSize(ImVec2(450, 300), ImGuiCond_FirstUseEver);

        if (ImGui::Begin("Kiero D3D9 Base", &Config::bMenuOpen)) {
            if (ImGui::BeginTabBar("MainTabBar")) {
                
                // Aba 1: Geral
                if (ImGui::BeginTabItem("Geral")) {
                    ImGui::Text("Opcoes Gerais da Aplicacao");
                    ImGui::Separator();
                    ImGui::Checkbox("Habilitar Recurso de Exemplo", &Config::bExampleToggle);
                    ImGui::SliderFloat("Fator de Multiplicacao", &Config::fExampleSlider, 0.0f, 10.0f, "%.1f");
                    ImGui::EndTabItem();
                }

                // Aba 2: Visual
                if (ImGui::BeginTabItem("Visual")) {
                    ImGui::Text("Configuracoes Visuais e Cores");
                    ImGui::Separator();
                    ImGui::ColorEdit4("Cor de Destaque", Config::colExample);
                    ImGui::EndTabItem();
                }

                // Aba 3: Configuracoes
                if (ImGui::BeginTabItem("Configuracoes")) {
                    ImGui::Text("Informacoes e Teclas de Atalho");
                    ImGui::Separator();
                    ImGui::BulletText("Atalho para abrir/fechar: [INSERT] ou [DELETE]");
                    ImGui::BulletText("Hook: DirectX 9 (EndScene + Reset)");
                    ImGui::EndTabItem();
                }

                ImGui::EndTabBar();
            }
        }
        ImGui::End();
    }

    void InvalidateDeviceObjects() {
        if (g_bInitialized) {
            ImGui_ImplDX9_InvalidateDeviceObjects();
        }
    }

    void CreateDeviceObjects() {
        if (g_bInitialized) {
            ImGui_ImplDX9_CreateDeviceObjects();
        }
    }

    void Shutdown() {
        if (g_bInitialized) {
            ImGui_ImplDX9_Shutdown();
            ImGui_ImplWin32_Shutdown();
            ImGui::DestroyContext();
            g_bInitialized = false;
        }
    }
}
