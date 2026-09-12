<div align="center">

# Kiero DirectX 9 + Dear ImGui Base (Legacy)

<p><b>Versão clássica e minimalista da base de injeção de DLL com Dear ImGui sobre DirectX 9 em C++ (x86 / x64).</b></p>

<a href="README.md"><img src="https://api.iconify.design/flag/br-4x3.svg?width=26" alt="Português" title="Português" /></a>
&nbsp;
<a href="docs/idiomas/README.en.md"><img src="https://api.iconify.design/flag/us-4x3.svg?width=26" alt="English" title="English" /></a>
&nbsp;
<a href="docs/idiomas/README.es.md"><img src="https://api.iconify.design/flag/es-4x3.svg?width=26" alt="Español" title="Español" /></a>
&nbsp;
<a href="docs/idiomas/README.ru.md"><img src="https://api.iconify.design/flag/ru-4x3.svg?width=26" alt="Русский" title="Русский" /></a>

<br /><br />

[![C++](https://img.shields.io/badge/C++-17-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)](https://isocpp.org)
[![DirectX 9](https://img.shields.io/badge/DirectX-9.0c-0078D4?style=for-the-badge&logo=windows&logoColor=white)](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics)
[![Dear ImGui](https://img.shields.io/badge/Dear_ImGui-v1.89-7B1FA2?style=for-the-badge&logo=imgui&logoColor=white)](https://github.com/ocornut/imgui)
[![MinHook](https://img.shields.io/badge/MinHook-v1.3.3-2E7D32?style=for-the-badge&logo=github&logoColor=white)](https://github.com/TsudaKageyu/minhook)
[![Visual Studio](https://img.shields.io/badge/Visual_Studio-2022+-5C2D91?style=for-the-badge&logo=visualstudio&logoColor=white)](https://visualstudio.microsoft.com)

<br />

[![Versão](https://img.shields.io/badge/versão-1.0.0--legacy-00D96A?style=flat-square)](memory/PROJECT_STATE.md)
[![Arquitetura](https://img.shields.io/badge/arquitetura-x86_%7C_x64-3B82F6?style=flat-square)](memory/PROJECT_STATE.md)
[![Status](https://img.shields.io/badge/build-passing-00D96A?style=flat-square)](memory/PROJECT_STATE.md)
[![Licença](https://img.shields.io/badge/licença-MIT-EAB308?style=flat-square)](LICENSE)

</div>

---

## <h2><img src="https://api.iconify.design/solar/widget-bold.svg?color=%233B82F6&width=24" align="top" /> &nbsp;Visão geral</h2>

Este repositório preserva a **versão clássica/legada da base Kiero DX9 + Dear ImGui**, contendo o esqueleto essencial e minimalista para hooking em DirectX 9 sem módulos adicionais de governança ou logging em disco.

### Características desta versão:
- **Hooking direto:** `EndScene` (slot 42), `Reset` (slot 16) e `WndProc` (subclassing) via [Kiero](https://github.com/ReUnion-dev/kiero) e [MinHook](https://github.com/TsudaKageyu/minhook).
- **Interface com abas padrão:** `gui.cpp` implementado com abas de exemplo (*Geral*, *Visual*, *Configurações*) via `ImGui::BeginTabBar`.
- **Suporte bimodal nativo:** Projetos configurados para compilação em `Win32` (x86) e `x64`.
- **Preservação de StateBlock:** Hook de renderização com captura e restauração de `IDirect3DStateBlock9` para evitar artefatos no jogo.

---

## <h2><img src="https://api.iconify.design/solar/folder-with-files-bold.svg?color=%233B82F6&width=24" align="top" /> &nbsp;Estrutura do projeto</h2>

```text
kiero-dx9-base-legacy/
├── main.cpp            → DllMain + hooks EndScene, Reset e WndProc
├── gui.h / gui.cpp     → Renderização ImGui com abas clássicas
├── config.h            → Variáveis de configuração centralizadas
├── offsets.h           → Header para anotação de offsets
├── classes.h           → Header para structs e SDK básico
├── includes.h          → Inclusão centralizada de cabeçalhos
├── kiero-dx9-base.vcxproj → Configuração de build MSBuild (Win32 / x64)
├── docs/idiomas/       → Documentação em múltiplos idiomas
├── dump/               → Pasta local para arquivos de análise (.gitkeep)
├── memory/             → Documentação e controle de offsets (OFFSETS.md, PROJECT_STATE.md)
├── imgui/              → Biblioteca Dear ImGui
└── kiero/              → Kiero hooking + MinHook
```

---

## <h2><img src="https://api.iconify.design/solar/settings-bold.svg?color=%233B82F6&width=24" align="top" /> &nbsp;Compilação</h2>

### Requisitos
- **Sistema Operacional:** Windows 10 / 11 (x86 ou x64)
- **Compilador:** Visual Studio 2022+ com suporte a C++17
- **SDK:** Windows 10/11 SDK + DirectX 9 SDK headers

### Linha de comando (MSBuild)

```bat
:: Compilação para 32-bit (x86)
MSBuild kiero-dx9-base.vcxproj /p:Configuration=Release /p:Platform=Win32 /t:Rebuild

:: Compilação para 64-bit (x64)
MSBuild kiero-dx9-base.vcxproj /p:Configuration=Release /p:Platform=x64 /t:Rebuild
```

Os binários compilados serão gerados em:
- `build/Release_Win32/kiero-dx9-base.dll`
- `build/Release_x64/kiero-dx9-base.dll`

---

## <h2><img src="https://api.iconify.design/solar/keyboard-bold.svg?color=%233B82F6&width=24" align="top" /> &nbsp;Atalhos padrão</h2>

| Tecla | Função |
|---|---|
| <kbd>INSERT</kbd> ou <kbd>DELETE</kbd> | Alterna a visibilidade da janela do menu |

---

## <h2><img src="https://api.iconify.design/solar/user-bold.svg?color=%233B82F6&width=24" align="top" /> &nbsp;Autor</h2>

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

## <h2><img src="https://api.iconify.design/solar/document-text-bold.svg?color=%233B82F6&width=24" align="top" /> &nbsp;Licenciamento</h2>

Distribuído sob a licença [MIT](LICENSE). Bibliotecas de terceiros ([Dear ImGui](https://github.com/ocornut/imgui), [MinHook](https://github.com/TsudaKageyu/minhook) e [Kiero](https://github.com/ReUnion-dev/kiero)) mantêm suas respectivas licenças originais.
