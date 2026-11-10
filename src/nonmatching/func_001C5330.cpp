// NONMATCHING: func_001C5330 -- retail 64 / ours 54 instructions, 36 in changed runs
// gaps1c: hand-drafted from the asm
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// gaps1c (2026-11-02): hand-drafted from the retail asm (0x1C5330..0x1C542C). Unnamed (no retail_names.csv row; in
// B3RaceCarPhysics.cpp's range). CacheWorldTriangles__17CB3RaceCarPhysicsFi's per-triangle callback (a0 = the
// intersection result, a1 = the car): skips (returns 1) surfaces of type 0x22 / 0x23 or flag 0x1000, types 0x15..0x20
// whose normal is more than 0.5 along the car's +0xB0, and normals with y below D_004E0DC4; caches the rest
// (func_001AB090, its result returned).
// TRACK: clean
// EQUIV: [L] written from the asm: every branch accounted for; the dot product as retail's VU form (DotProduct)

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

struct UnkStruct_001C5330_q { float x, y, z, w; };
struct UnkStruct_001C5330_tri { UnkStruct_001C5330_q field_0[4]; };            // [C] 0x40 bytes
struct UnkStruct_001C5330_cache { int field_0; UnkStruct_001C5330_tri * field_4; unsigned short * field_8; };
struct UnkStruct_001C5330_poly { unsigned char pad_0[0x4]; unsigned short field_4; };   // [C] lhu 0x4: the surface flags
struct UnkStruct_001C5330_res {                                              // [C] the polygon-intersection result
    unsigned char pad_0[0x10];
    UnkStruct_001C5330_q field_10;                                           // [G] the normal (dot with the car's +0xB0)
    UnkStruct_001C5330_q field_20;
    UnkStruct_001C5330_q field_30;
    UnkStruct_001C5330_q field_40;
    unsigned char pad_50[0x10];
    UnkStruct_001C5330_poly * field_60;
};
struct UnkStruct_001C5330_car { unsigned char pad_0[0xB0]; CGtV3d field_B0; };

extern float D_004E0DC4;                      // [C] gp-relative

extern "C" int func_001AB090(UnkStruct_001C5330_car *, UnkStruct_001C5330_res *);

// 0x001C5330
extern "C" int func_001C5330(UnkStruct_001C5330_res * res, UnkStruct_001C5330_car * car)
{
    unsigned short flags = res->field_60->field_4;
    int type = flags & 0xFF;
    if (type == 0x23 || type == 0x22 || (flags & 0x1000) != 0) {
        return 1;
    }
    if (type >= 0x15 && type < 0x21) {
        if (!((float)DotProduct(car->field_B0, *(CGtV3d *)&res->field_10) <= 0.5f)) {
            return 1;
        }
    }
    if (res->field_10.y < D_004E0DC4) {
        return 1;
    }
    return func_001AB090(car, res);
}
