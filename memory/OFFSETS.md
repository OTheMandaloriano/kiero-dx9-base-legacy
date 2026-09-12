# 📑 DOCUMENTAÇÃO DE OFFSETS

Este documento serve como fonte de verdade para os offsets e endereços de memória identificados no processo de engenharia reversa.

---

## 1. Endereços Globais

| Nome do Ponteiro | Tipo | Endereço / Assinatura (Pattern) | Descrição |
|---|---|---|---|
| `g_pGameInstance` | `uintptr_t` | `0x00000000` | Instância principal do jogo |

---

## 2. Estruturas e Classes

### Exemplo: `CPlayer`
| Campo | Tipo | Offset | Descrição |
|---|---|---|---|
| `m_iHealth` | `int32_t` | `+0x00` | Vida atual do jogador |
| `m_vecPosition` | `float[3]` | `+0x00` | Coordenadas globais X, Y, Z |

---

## 3. Métodos Virtuais (VTables)

| Interface | Método | Índice (Slot) | Offset em Bytes |
|---|---|---|---|
| `IRenderer` | `ProjectToScreen` | `0` | `+0x00` |
