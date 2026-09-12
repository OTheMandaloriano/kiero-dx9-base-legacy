<div align="center">

# Base Kiero DirectX 9 + Dear ImGui (Legado)

<p><b>Versión clásica y minimalista de la base de inyección de DLL con Dear ImGui sobre DirectX 9 en C++ (x86 / x64).</b></p>

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

[![Versión](https://img.shields.io/badge/versión-1.0.0--legacy-00D96A?style=flat-square)](../../memory/PROJECT_STATE.md)
[![Arquitectura](https://img.shields.io/badge/arquitectura-x86_%7C_x64-3B82F6?style=flat-square)](../../memory/PROJECT_STATE.md)
[![Estado](https://img.shields.io/badge/build-passing-00D96A?style=flat-square)](../../memory/PROJECT_STATE.md)
[![Licencia](https://img.shields.io/badge/licencia-MIT-EAB308?style=flat-square)](../../LICENSE)

</div>

---

## <h2><img src="https://api.iconify.design/solar/widget-bold.svg?color=%233B82F6&width=24" align="top" /> &nbsp;Visión general</h2>

Este repositorio preserva la **versión clásica y ligera de la base Kiero DX9 + Dear ImGui**, proporcionando el esqueleto esencial para hooking en DirectX 9 sin módulos adicionales de registro en disco ni archivos extendidos de gobernanza.

### Características:
- **Hooking directo:** `EndScene` (slot 42), `Reset` (slot 16) y `WndProc` (subclasificación) mediante [Kiero](https://github.com/ReUnion-dev/kiero) y [MinHook](https://github.com/TsudaKageyu/minhook).
- **Interfaz con pestañas predeterminada:** `gui.cpp` configurado con pestañas de ejemplo (*General*, *Visual*, *Configuración*) mediante `ImGui::BeginTabBar`.
- **Soporte bimodal nativo:** Proyectos configurados para compilar en `Win32` (x86) y `x64`.
- **Preservación de StateBlock:** Hook de renderizado con captura y restauración de `IDirect3DStateBlock9` para evitar fallos gráficos.

---

## <h2><img src="https://api.iconify.design/solar/folder-with-files-bold.svg?color=%233B82F6&width=24" align="top" /> &nbsp;Estructura del repositorio</h2>

```text
kiero-dx9-base-legacy/
├── main.cpp            → DllMain + hooks EndScene, Reset y WndProc
├── gui.h / gui.cpp     → Renderizado ImGui con pestañas clásicas
├── config.h            → Variables globales centralizadas
├── offsets.h           → Cabecera para offsets
├── classes.h           → Cabecera para structs y SDK
├── includes.h          → Inclusión unificada de cabeceras
├── kiero-dx9-base.vcxproj → Proyecto MSBuild (Win32 / x64)
├── docs/idiomas/       → Documentación en múltiples idiomas
├── dump/               → Carpeta para volcados locales (.gitkeep)
├── memory/             → Documentación técnica (OFFSETS.md, PROJECT_STATE.md)
├── imgui/              → Biblioteca Dear ImGui
└── kiero/              → Kiero hooking + MinHook
```

---

## <h2><img src="https://api.iconify.design/solar/settings-bold.svg?color=%233B82F6&width=24" align="top" /> &nbsp;Compilación</h2>

### Requisitos
- **Sistema Operativo:** Windows 10 / 11 (x86 o x64)
- **Compilador:** Visual Studio 2022+ con soporte C++17
- **SDK:** Windows 10/11 SDK + DirectX 9 SDK headers

### Línea de comandos (MSBuild)

```bat
:: Compilación para 32-bit (x86)
MSBuild kiero-dx9-base.vcxproj /p:Configuration=Release /p:Platform=Win32 /t:Rebuild

:: Compilación para 64-bit (x64)
MSBuild kiero-dx9-base.vcxproj /p:Configuration=Release /p:Platform=x64 /t:Rebuild
```

Los binarios compilados se generarán en:
- `build/Release_Win32/kiero-dx9-base.dll`
- `build/Release_x64/kiero-dx9-base.dll`

---

## <h2><img src="https://api.iconify.design/solar/keyboard-bold.svg?color=%233B82F6&width=24" align="top" /> &nbsp;Atajos predeterminados</h2>

| Tecla | Acción |
|---|---|
| <kbd>INSERT</kbd> o <kbd>DELETE</kbd> | Alterna la visibilidad del menú |

---

## <h2><img src="https://api.iconify.design/solar/user-bold.svg?color=%233B82F6&width=24" align="top" /> &nbsp;Créditos y agradecimientos</h2>

<table align="center">
  <tr>
    <td align="center" width="160">
      <a href="https://github.com/OTheMandaloriano">
        <img src="https://avatars.githubusercontent.com/u/252971432?v=4" width="100px;" alt="The Mandalorian" style="border-radius: 50%;" /><br />
        <sub><b>The Mandalorian</b></sub>
      </a><br />
      <sub>@OTheMandaloriano</sub><br />
      <sub><i>Autor & Mantenedor</i></sub>
    </td>
    <td align="center" width="160">
      <a href="https://github.com/rdbo">
        <img src="https://avatars.githubusercontent.com/u/57117082?v=4" width="100px;" alt="rdbo" style="border-radius: 50%;" /><br />
        <sub><b>rdbo</b></sub>
      </a><br />
      <sub>@rdbo</sub><br />
      <sub><i>Creador de Kiero</i></sub>
    </td>
  </tr>
</table>

---

## <h2><img src="https://api.iconify.design/solar/document-text-bold.svg?color=%233B82F6&width=24" align="top" /> &nbsp;Licencia</h2>

Distribuido bajo la licencia [MIT](LICENSE). Las bibliotecas de terceros conservan sus licencias originales.
