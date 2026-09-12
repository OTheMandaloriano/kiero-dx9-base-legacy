<div align="center">

# Kiero DirectX 9 + Dear ImGui Base (Legacy)

<p><b>Classic, minimalist base for DLL injection with Dear ImGui over DirectX 9 in C++ (x86 / x64).</b></p>

<a href="../../README.md"><img src="https://api.iconify.design/flag/br-4x3.svg?width=26" alt="Português" title="Português" /></a>
&nbsp;
<a href="README.en.md"><img src="https://api.iconify.design/flag/us-4x3.svg?width=26" alt="English" title="English" /></a>
&nbsp;
<a href="README.es.md"><img src="https://api.iconify.design/flag/es-4x3.svg?width=26" alt="Español" title="Español" /></a>
&nbsp;
<a href="README.ru.md"><img src="https://api.iconify.design/flag/ru-4x3.svg?width=26" alt="Русский" title="Русский" /></a>

<br /><br />

[![C++](https://img.shields.io/badge/C++-17-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)](https://isocpp.org)
[![DirectX 9](https://img.shields.io/badge/DirectX-9.0c-0078D4?style=for-the-badge&logo=windows&logoColor=white)](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics)
[![Dear ImGui](https://img.shields.io/badge/Dear_ImGui-v1.89-7B1FA2?style=for-the-badge&logo=imgui&logoColor=white)](https://github.com/ocornut/imgui)
[![MinHook](https://img.shields.io/badge/MinHook-v1.3.3-2E7D32?style=for-the-badge&logo=github&logoColor=white)](https://github.com/TsudaKageyu/minhook)
[![Visual Studio](https://img.shields.io/badge/Visual_Studio-2022+-5C2D91?style=for-the-badge&logo=visualstudio&logoColor=white)](https://visualstudio.microsoft.com)

<br />

[![Version](https://img.shields.io/badge/version-1.0.0--legacy-00D96A?style=flat-square)](../../memory/PROJECT_STATE.md)
[![Architecture](https://img.shields.io/badge/architecture-x86_%7C_x64-3B82F6?style=flat-square)](../../memory/PROJECT_STATE.md)
[![Status](https://img.shields.io/badge/build-passing-00D96A?style=flat-square)](../../memory/PROJECT_STATE.md)
[![License](https://img.shields.io/badge/license-MIT-EAB308?style=flat-square)](../../LICENSE)

</div>

---

## <h2><img src="https://api.iconify.design/solar/widget-bold.svg?color=%233B82F6&width=24" align="top" /> &nbsp;Overview</h2>

This repository preserves the **classic/legacy edition of the Kiero DX9 + Dear ImGui base**, providing an essential, lightweight skeleton for DirectX 9 hooking without additional disk logging or extended governance files.

### Key Features:
- **Direct hooking:** `EndScene` (slot 42), `Reset` (slot 16), and `WndProc` (subclassing) via [Kiero](https://github.com/ReUnion-dev/kiero) and [MinHook](https://github.com/TsudaKageyu/minhook).
- **Default tabbed UI:** `gui.cpp` pre-configured with sample tabs (*General*, *Visual*, *Settings*) via `ImGui::BeginTabBar`.
- **Native dual-architecture support:** Configured for `Win32` (x86) and `x64` builds.
- **StateBlock preservation:** Render hook captures and restores `IDirect3DStateBlock9` to eliminate graphical corruption.

---

## <h2><img src="https://api.iconify.design/solar/folder-with-files-bold.svg?color=%233B82F6&width=24" align="top" /> &nbsp;Repository structure</h2>

```text
kiero-dx9-base-legacy/
├── main.cpp            → DllMain + EndScene, Reset, and WndProc hooks
├── gui.h / gui.cpp     → ImGui rendering layer with classic tabs
├── config.h            → Centralized configuration variables
├── offsets.h           → Header stub for memory offsets
├── classes.h           → Header stub for SDK / classes
├── includes.h          → Centralized header inclusion
├── kiero-dx9-base.vcxproj → MSBuild project file (Win32 / x64)
├── docs/idiomas/       → Multi-language documentation
├── dump/               → Local folder for reversing binaries (.gitkeep)
├── memory/             → Technical docs (OFFSETS.md, PROJECT_STATE.md)
├── imgui/              → Dear ImGui library
└── kiero/              → Kiero hooking + MinHook
```

---

## <h2><img src="https://api.iconify.design/solar/settings-bold.svg?color=%233B82F6&width=24" align="top" /> &nbsp;Building</h2>

### Requirements
- **OS:** Windows 10 / 11 (x86 or x64)
- **Compiler:** Visual Studio 2022+ with C++17 support
- **SDK:** Windows 10/11 SDK + DirectX 9 SDK headers

### Command line (MSBuild)

```bat
:: Build for 32-bit (x86)
MSBuild kiero-dx9-base.vcxproj /p:Configuration=Release /p:Platform=Win32 /t:Rebuild

:: Build for 64-bit (x64)
MSBuild kiero-dx9-base.vcxproj /p:Configuration=Release /p:Platform=x64 /t:Rebuild
```

Compiled binaries will be generated under:
- `build/Release_Win32/kiero-dx9-base.dll`
- `build/Release_x64/kiero-dx9-base.dll`

---

## <h2><img src="https://api.iconify.design/solar/keyboard-bold.svg?color=%233B82F6&width=24" align="top" /> &nbsp;Default hotkeys</h2>

| Key | Action |
|---|---|
| <kbd>INSERT</kbd> or <kbd>DELETE</kbd> | Toggle menu visibility |

---

## <h2><img src="https://api.iconify.design/solar/user-bold.svg?color=%233B82F6&width=24" align="top" /> &nbsp;Credits & acknowledgments</h2>

<table align="center">
  <tr>
    <td align="center" width="160">
      <a href="https://github.com/OTheMandaloriano">
        <img src="https://avatars.githubusercontent.com/u/252971432?v=4" width="100px;" alt="The Mandalorian" style="border-radius: 50%;" /><br />
        <sub><b>The Mandalorian</b></sub>
      </a><br />
      <sub>@OTheMandaloriano</sub><br />
      <sub><i>Author & Maintainer</i></sub>
    </td>
    <td align="center" width="160">
      <a href="https://github.com/rdbo">
        <img src="https://avatars.githubusercontent.com/u/57117082?v=4" width="100px;" alt="rdbo" style="border-radius: 50%;" /><br />
        <sub><b>rdbo</b></sub>
      </a><br />
      <sub>@rdbo</sub><br />
      <sub><i>Kiero Creator</i></sub>
    </td>
  </tr>
</table>

---

## <h2><img src="https://api.iconify.design/solar/document-text-bold.svg?color=%233B82F6&width=24" align="top" /> &nbsp;License</h2>

Distributed under the [MIT](LICENSE) License. Third-party libraries maintain their original licenses.
