// NONMATCHING: func_003AB430 -- retail 68 / ours 68 instructions, 4 in changed runs
// sig1: 9 -> 4. func_003B0870 is (void*, int, float) as in siblings (retail's a2 = lui 1.0f is the GPR staging of the 1.0 constant, not an arg); 'float v = 1.0f; v -= K * d;' reproduces the lui a2/mtc1 + adda/msub(K,d). Left: d (sub.s) on f2 and 1.0 on f4, retail the reverse; tried stmt/decl orders, clamp in steps, 219 as local, d*=K
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// NONMATCHING: func_003AB430 -- retail 68 / ours 68 instructions, 9 in changed runs
// near14: still 9 (sub.s/address scheduling, msub operand regs). D_004E06AC/07E8/07EC are .lit4 (0.899999976f, 0.100000024f, 9.99999809f) but literals give 10. Callee never reads a2 (siblings func_003AB2E0/AB640 pass (void*,int,float)), yet dropping the 0x3F800000 a2 arg gives 12: retail's 1.0f for adda really sits in a2. K*d vs d*K flips the FP numbering with the operand order
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// func_003AB430 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

#include "b3/GtMath.h"

struct UnkStruct_003AB430;
struct UnkStruct_003AB430_e0;
struct UnkStruct_D_004E06AC;
struct UnkStruct_D_004E07E8;
struct UnkStruct_D_004E07EC;

struct UnkStruct_D_004E06AC {
    float field_0;
};

struct UnkStruct_D_004E07E8 {
    float field_0;
};

struct UnkStruct_D_004E07EC {
    float field_0;
};

struct UnkStruct_003AB430_e0 {
    unsigned char pad_0[0x10];
};

struct UnkStruct_003AB430 {
    UnkStruct_003AB430_e0 field_0[1];  // [G] element count unknown
    unsigned char pad_10[0x23C];
    int field_24C;
    unsigned char pad_250[0x2];
    unsigned short field_252;
    unsigned char pad_254[0x4AC];
    int field_700;
};

extern UnkStruct_D_004E06AC D_004E06AC;
extern UnkStruct_D_004E07E8 D_004E07E8;
extern UnkStruct_D_004E07EC D_004E07EC;

extern "C" void * memset(void *, int, unsigned int);
extern "C" void func_003B0870(void *, int, float);
extern "C" void func_003AB540(UnkStruct_003AB430 *, float);

// 0x003AB430
extern "C" void func_003AB430(UnkStruct_003AB430 * self, float f0)
{
    if (self->field_24C == 0) return;
    float step = D_004E06AC.field_0 / (float)(int)self->field_252;
    self->field_700 = 0;
    memset(((char *)self + 0x544), 0, 56);
    for (int i = 0; i < self->field_252; i++) {
        float x = step * (float)i;
        float hi = D_004E07E8.field_0 + x;
        float c = GtMath::Min(GtMath::Max(f0, x), hi);
        float d = c - x;
        float v = 1.0f;
        v -= D_004E07EC.field_0 * d;
        func_003B0870(((char *)&self->field_0[i] + 0xA4), 0, 219.0f * v);
    }
    self->field_700 = 0;
    func_003AB540(self, f0);
}
