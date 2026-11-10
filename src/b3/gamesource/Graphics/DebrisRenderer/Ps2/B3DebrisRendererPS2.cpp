// B3DebrisRendererPS2.cpp -- translation unit regrouped by tools/tu_merge.py from 6 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 6 function(s) named in research/retail_names.csv -> B3DebrisRendererPS2.cpp.
// Area: src/b3/gamesource/Graphics/DebrisRenderer/Ps2, [L] Revenge (SLUS_212.42) GameSource/Graphics/DebrisRenderer/Ps2/B4DebrisRendererPS2.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3DebrisArray.h"
#include "b3/classes/CB3DebrisRenderer.h"
#include "b3/classes/UnkStruct_D_01E86D10.h"
#include "b3/classes/UnkStruct_D_01E86D14.h"
#include "b3/classes/UnkStruct_D_01E86D18.h"
#include "b3/classes/UnkStruct_D_01E86D1C.h"

extern UnkStruct_D_01E86D1C D_01E86D1C;
extern UnkStruct_D_01E86D10 D_01E86D10;
extern UnkStruct_D_01E86D14 D_01E86D14;
extern UnkStruct_D_01E86D18 D_01E86D18;

// CB3DebrisRenderer::BeginRender() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3DebrisRendererPS2.cpp.
// 0x002F4600
void CB3DebrisRenderer::BeginRender()
{
    D_01E86D1C.field_0 = 0;
    D_01E86D10.field_0 = 0;
}

// CB3DebrisRenderer::Destruct() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3DebrisRendererPS2.cpp.
// 0x002F4620
void CB3DebrisRenderer::Destruct()
{
}

// CB3DebrisRenderer::Construct() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3DebrisRendererPS2.cpp.
// 0x002F4630
void CB3DebrisRenderer::Construct()
{
    D_01E86D14.field_0 = 0;
    D_01E86D18.field_0 = 0;
    D_01E86D10.field_0 = 0;
}

// CB3DebrisArray::Release() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3DebrisRendererPS2.cpp.
// 0x002F4930
void CB3DebrisArray::Release()
{
}

// CB3DebrisArray::Prepare() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3DebrisRendererPS2.cpp.
// 0x002F4940
int CB3DebrisArray::Prepare()
{
    void * m0 = (void *)-9999;
    for (int i = 0; ((unsigned int)i < (unsigned int)field_18); i++) {
        UnkStruct_002F4940_e0 * t0 = field_14;
        t0[i].field_30 = ((float)-9999);
        m0 = &t0[i];
    }
    field_1C = 0;
    return 1;
}

// CB3DebrisArray::Destruct() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3DebrisRendererPS2.cpp.
// 0x002F4990
void CB3DebrisArray::Destruct()
{
}
