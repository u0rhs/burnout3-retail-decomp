// func_0038B2B0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3CrashCombo.h"

struct UnkStruct_0038B2B0_1;
struct UnkStruct_0038B2B0_a1;

struct UnkStruct_0038B2B0_a1 {
    unsigned char pad_0[0x13F4];
    UnkStruct_0038B2B0_1 * field_13F4;
};

struct UnkStruct_0038B2B0_1 {
    unsigned char pad_0[0x1338];
    CB3CrashCombo * field_1338;
};

// 0x0038B2B0
extern "C" void func_0038B2B0(int n0, UnkStruct_0038B2B0_a1 * p0)
{
    UnkStruct_0038B2B0_1 * t0 = p0->field_13F4;
    CB3CrashCombo * t1 = t0->field_1338;
    if (t1 == 0) return;
    t1->OnCrashFinishing();
}
