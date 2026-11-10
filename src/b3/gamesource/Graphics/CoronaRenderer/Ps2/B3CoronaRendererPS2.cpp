// B3CoronaRendererPS2.cpp -- translation unit regrouped by tools/tu_merge.py from 5 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 5 function(s) named in research/retail_names.csv -> B3CoronaRendererPS2.cpp.
// Area: src/b3/gamesource/Graphics/CoronaRenderer/Ps2, [L] Revenge (SLUS_212.42) GameSource/Graphics/CoronaRenderer/Ps2/B4CoronaRendererPS2.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

typedef unsigned int u_long128 __attribute__((mode(TI)));

#include "b3/classes/CB3CoronaDynamicArray.h"
#include "b3/classes/CB3CoronaRenderer.h"
#include "b3/classes/UnkStruct_farFogPlane.h"

extern UnkStruct_farFogPlane farFogPlane;

// CB3CoronaRenderer::SetRenderstates() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3CoronaRendererPS2.cpp.
// 0x00306E00
void CB3CoronaRenderer::SetRenderstates()
{
    UnkStruct_00263350_1 * t0 = farFogPlane.field_0;
    u_long128 q0;
    asm("pcpyld %0, %2, %1" : "=r"(q0) : "r"(0x10000003), "r"(0x5000000300000000));
    t0->field_0 = q0;
    u_long128 q1;
    asm("pcpyld %0, %2, %1" : "=r"(q1) : "r"(0x1000000000008002), "r"(14));
    t0->field_10 = q1;
    u_long128 q2;
    asm("pcpyld %0, %2, %1" : "=r"(q2) : "r"(0x8000000068), "r"(66));
    t0->field_20 = q2;
    u_long128 q3;
    asm("pcpyld %0, %2, %1" : "=r"(q3) : "r"(0x53001), "r"(71));
    t0->field_30 = q3;
    farFogPlane.field_0 = (UnkStruct_00263350_1 *)((char *)t0 + 0x40);
}

// CB3CoronaRenderer::Construct() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3CoronaRendererPS2.cpp.
// 0x00307430
void CB3CoronaRenderer::Construct()
{
    CB3CoronaRenderer::mnPlayer = this;
}

// CB3CoronaDynamicArray::BeginUpdate(int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3CoronaRendererPS2.cpp.
// 0x00307500
void CB3CoronaDynamicArray::BeginUpdate(int p0)
{
    field_30 = p0;
    field_2E[field_30] = (field_2E[field_30] ^ 1);
    field_20 = (UnkStruct_00307500_e3 *)(field_10[field_30].field_0[field_2E[field_30]] | 0x30000000);
    field_24 = (int)&field_20[field_28];
}

// CB3CoronaDynamicArray::Destruct() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3CoronaRendererPS2.cpp.
// 0x00307620
void CB3CoronaDynamicArray::Destruct()
{
}

// CB3CoronaDynamicArray::Construct(int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3CoronaRendererPS2.cpp.
// 0x00307630
void CB3CoronaDynamicArray::Construct(int p0)
{
    for (int i = 0; (i < 2); i++) {
        ConstructDMAData(i, 0, p0);
        ConstructDMAData(i, 1, p0);
        field_2E[i] = 0;
        field_2A[i] = 0;
    }
    field_28 = p0;
    field_20 = 0;
    field_24 = 0;
    field_30 = -1;
}
