#pragma once

#include <Windows.h>
#include <d3d9.h>
#include <d3dx9.h>

#include "kiero/kiero.h"
#include "kiero/minhook/include/MinHook.h"

#include "imgui/imgui.h"
#include "imgui/imgui_impl_win32.h"
#include "imgui/imgui_impl_dx9.h"

#include "config.h"
#include "offsets.h"
#include "classes.h"
#include "gui.h"

typedef long(__stdcall* EndScene_t)(LPDIRECT3DDEVICE9);
typedef long(__stdcall* Reset_t)(LPDIRECT3DDEVICE9, D3DPRESENT_PARAMETERS*);
typedef LRESULT(CALLBACK* WNDPROC_t)(HWND, UINT, WPARAM, LPARAM);
