#pragma once
#include <d3d9.h>

namespace GUI {
    void Initialize(HWND hWindow, LPDIRECT3DDEVICE9 pDevice);
    void Render();
    void InvalidateDeviceObjects();
    void CreateDeviceObjects();
    void Shutdown();
}
