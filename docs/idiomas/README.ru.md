<div align="center">

# Базовый проект Kiero DirectX 9 + Dear ImGui (Legacy)

<p><b>Классическая и минималистичная версия базы внедряемой DLL с графическим интерфейсом Dear ImGui на базе DirectX 9 в C++ (x86 / x64).</b></p>

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

[![Версия](https://img.shields.io/badge/версия-1.0.0--legacy-00D96A?style=flat-square)](../../memory/PROJECT_STATE.md)
[![Архитектура](https://img.shields.io/badge/архитектура-x86_%7C_x64-3B82F6?style=flat-square)](../../memory/PROJECT_STATE.md)
[![Статус сборки](https://img.shields.io/badge/сборка-passing-00D96A?style=flat-square)](../../memory/PROJECT_STATE.md)
[![Лицензия](https://img.shields.io/badge/лицензия-MIT-EAB308?style=flat-square)](../../LICENSE)

</div>

---

## <h2><img src="https://api.iconify.design/solar/widget-bold.svg?color=%233B82F6&width=24" align="top" /> &nbsp;Обзор проекта</h2>

Этот репозиторий сохраняет **классическую (legacy) версию основы Kiero DX9 + Dear ImGui**, предоставляя минималистичный скелет для хукинга в DirectX 9 без дополнительных модулей журналирования на диск и расширенной документации.

### Особенности:
- **Прямой перехват (Hooking):** `EndScene` (слот 42), `Reset` (слот 16) и `WndProc` через [Kiero](https://github.com/ReUnion-dev/kiero) и [MinHook](https://github.com/TsudaKageyu/minhook).
- **Интерфейс с вкладками:** `gui.cpp` с примерами вкладок (*Общие*, *Визуал*, *Настройки*) через `ImGui::BeginTabBar`.
- **Поддержка x86 и x64:** Нативная сборка проектов `Win32` и `x64`.
- **Сохранение StateBlock:** Захват и восстановление `IDirect3DStateBlock9` для предотвращения графических артефактов.

---

## <h2><img src="https://api.iconify.design/solar/folder-with-files-bold.svg?color=%233B82F6&width=24" align="top" /> &nbsp;Структура репозитория</h2>

```text
kiero-dx9-base-legacy/
├── main.cpp            → DllMain + хуки EndScene, Reset и WndProc
├── gui.h / gui.cpp     → Отрисовка ImGui с классическими вкладками
├── config.h            → Глобальные переменные состояния
├── offsets.h           → Заголовочный файл для смещений (Offsets)
├── classes.h           → Заголовочный файл для структур и SDK
├── includes.h          → Единый заголовочный файл
├── kiero-dx9-base.vcxproj → Файл проекта MSBuild (Win32 / x64)
├── docs/idiomas/       → Документация на разных языках
├── dump/               → Локальная папка для дампов (.gitkeep)
├── memory/             → Техническая документация (OFFSETS.md, PROJECT_STATE.md)
├── imgui/              → Библиотека Dear ImGui
└── kiero/              → Kiero + MinHook
```

---

## <h2><img src="https://api.iconify.design/solar/settings-bold.svg?color=%233B82F6&width=24" align="top" /> &nbsp;Сборка проекта</h2>

### Требования
- **ОС:** Windows 10 / 11 (x86 или x64)
- **Компилятор:** Visual Studio 2022+ с поддержкой C++17
- **SDK:** Windows 10/11 SDK + DirectX 9 SDK headers

### Командная строка (MSBuild)

```bat
:: Сборка для 32-бит (x86)
MSBuild kiero-dx9-base.vcxproj /p:Configuration=Release /p:Platform=Win32 /t:Rebuild

:: Сборка для 64-бит (x64)
MSBuild kiero-dx9-base.vcxproj /p:Configuration=Release /p:Platform=x64 /t:Rebuild
```

Скомпилированные файлы появятся в:
- `build/Release_Win32/kiero-dx9-base.dll`
- `build/Release_x64/kiero-dx9-base.dll`

---

## <h2><img src="https://api.iconify.design/solar/keyboard-bold.svg?color=%233B82F6&width=24" align="top" /> &nbsp;Горячие клавиши по умолчанию</h2>

| Клавиша | Действие |
|---|---|
| <kbd>INSERT</kbd> или <kbd>DELETE</kbd> | Открыть / скрыть меню ImGui |

---

## <h2><img src="https://api.iconify.design/solar/user-bold.svg?color=%233B82F6&width=24" align="top" /> &nbsp;Автор</h2>

<table align="center">
  <tr>
    <td align="center">
      <a href="https://github.com/OTheMandaloriano">
        <img src="https://avatars.githubusercontent.com/u/252971432?v=4" width="100px;" alt="The Mandalorian" style="border-radius: 50%;" /><br />
        <sub><b>The Mandalorian</b></sub>
      </a><br />
      <sub>@OTheMandaloriano</sub>
    </td>
  </tr>
</table>

---

## <h2><img src="https://api.iconify.design/solar/document-text-bold.svg?color=%233B82F6&width=24" align="top" /> &nbsp;Лицензия</h2>

Распространяется под лицензией [MIT](LICENSE). Сторонние библиотеки сохраняют свои оригинальные лицензии.
