#pragma once
#include <cstdint>
#include "offsets.h"

// ============================================================================
// CLASSES & STRUCTS DO PROJETO (SDK TEMPLATE)
// ============================================================================
// Defina aqui as representações C++ das classes e estruturas de memória.
// Use 'char pad' para preencher espaçamentos de memória entre membros conhecidos.
// ============================================================================

#pragma pack(push, 1)

// Exemplo genérico de estrutura matemática/posicional (se necessário no projeto)
struct Vector3 {
    float x, y, z;
};

// Exemplo genérico de classe de entidade
class ExampleEntity {
public:
    char        pad_0000[0x10]; // 0x0000 - Bytes não mapeados
    int32_t     m_iHealth;      // 0x0010 - Exemplo de campo
    int32_t     m_iTeam;        // 0x0014 - Exemplo de campo
    char        pad_0018[0x20]; // 0x0018 - Espaçamento
    Vector3     m_vecPosition;  // 0x0038 - Posição X, Y, Z
};

#pragma pack(pop)
