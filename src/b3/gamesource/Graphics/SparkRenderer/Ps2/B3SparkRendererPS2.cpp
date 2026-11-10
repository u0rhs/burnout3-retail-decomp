// B3SparkRendererPS2.cpp -- translation unit regrouped by tools/tu_merge.py from 6 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 6 function(s) named in research/retail_names.csv -> B3SparkRendererPS2.cpp.
// Area: src/b3/gamesource/Graphics/SparkRenderer/Ps2, [L] Revenge (SLUS_212.42) GameSource/Graphics/SparkRenderer/Ps2/B4SparkRendererPS2.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

typedef unsigned int u_long128 __attribute__((mode(TI)));

#include "b3/classes/CB3SparkArray.h"
#include "b3/classes/CB3SparkRenderer.h"
#include "b3/classes/UnkStruct_D_01E31A20.h"
#include "b3/classes/UnkStruct_farFogPlane.h"

extern UnkStruct_farFogPlane farFogPlane;
extern UnkStruct_D_01E31A20 D_01E31A20;

// CB3SparkRenderer::RestoreRenderstates() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SparkRendererPS2.cpp.
// 0x00263350
void CB3SparkRenderer::RestoreRenderstates()
{
    UnkStruct_00263350_1 * t0 = farFogPlane.field_0;
    u_long128 q0;
    asm("pcpyld %0, %2, %1" : "=r"(q0) : "r"(0x10000001), "r"(0x5000000100000000));
    t0->field_0 = q0;
    u_long128 q1;
    asm("pcpyld %0, %2, %1" : "=r"(q1) : "r"(0x1000000000008000), "r"(14));
    t0->field_10 = q1;
    farFogPlane.field_0 = (UnkStruct_00263350_1 *)((char *)t0 + 0x20);
}

// CB3SparkRenderer::SetRenderstates() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SparkRendererPS2.cpp.
// 0x002633A0
void CB3SparkRenderer::SetRenderstates()
{
    UnkStruct_00263350_1 * t0 = farFogPlane.field_0;
    u_long128 q0;
    asm("pcpyld %0, %2, %1" : "=r"(q0) : "r"(0x10000004), "r"(0x5000000400000000));
    t0->field_0 = q0;
    u_long128 q1;
    asm("pcpyld %0, %2, %1" : "=r"(q1) : "r"(0x1000000000008003), "r"(14));
    t0->field_10 = q1;
    u_long128 q2;
    asm("pcpyld %0, %2, %1" : "=r"(q2) : "r"(0x71001), "r"(71));
    t0->field_20 = q2;
    u_long128 q3;
    asm("pcpyld %0, %2, %1" : "=r"(q3) : "r"(72), "r"(66));
    t0->field_30 = q3;
    u_long128 q4;
    asm("pcpyld %0, %2, %1" : "=r"(q4) : "r"(5), "r"(8));
    t0->field_40 = q4;
    farFogPlane.field_0 = (UnkStruct_00263350_1 *)((char *)t0 + 0x50);
}

// CB3SparkRenderer::Destruct() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SparkRendererPS2.cpp.
// 0x00263C00
void CB3SparkRenderer::Destruct()
{
}

// CB3SparkRenderer::Construct() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SparkRendererPS2.cpp.
// 0x00263C10
void CB3SparkRenderer::Construct()
{
    u_long128 q0;
    asm("pcpyld %0, %2, %1" : "=r"(q0) : "r"(((u_long128)0x802A400000000000)), "r"(0x42424242));
    D_01E31A20.field_0 = q0;
}

// CB3SparkArray::Release() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SparkRendererPS2.cpp.
// 0x00263F70
void CB3SparkArray::Release()
{
    field_9C = 0;
}

// CB3SparkArray::Destruct() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SparkRendererPS2.cpp.
// 0x00264030
void CB3SparkArray::Destruct()
{
}
