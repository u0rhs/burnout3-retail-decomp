// func_00135DA0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_0051BFA0.h"

extern UnkStruct_D_0051BFA0 D_0051BFA0;
extern "C" int func_003E8E60(int);
extern "C" int func_00135F30(void *, int, int);
extern "C" int IsCorrectRegion__26CB3HardCodedCrashStageListF14EB3TrackRegioni(int, int);
extern "C" int func_003E96E0(int);
extern "C" int func_00136110(void *, int, int);
extern "C" int IsCorrectRegion__25CB3HardCodedRaceStageListF14EB3TrackRegioni(int, int);

// 0x00135DA0
extern "C" int func_00135DA0(void *n0, int p0, int p1)
{
    if (p1 != 0) {
        int m = -1;
        int i;
        for (i = 0; i < 100; i++) {
            if (D_0051BFA0.field_A0[i] != 0) {
                if (m < func_003E8E60(i)) {
                    m = func_003E8E60(i);
                }
            }
        }
        for (i = 0; i < 100; i++) {
            if (func_00135F30((void *)(n0), i, m) != 0) {
                if (IsCorrectRegion__26CB3HardCodedCrashStageListF14EB3TrackRegioni(p0, i) != 0) {
                    return 1;
                }
            }
        }
    } else {
        int m = -1;
        int i;
        for (i = 0; i < 73; i++) {
            if (D_0051BFA0.field_57[i] != 0) {
                if (m < func_003E96E0(i)) {
                    m = func_003E96E0(i);
                }
            }
        }
        for (i = 0; i < 73; i++) {
            if (func_00136110((void *)(n0), i, m) != 0) {
                if (IsCorrectRegion__25CB3HardCodedRaceStageListF14EB3TrackRegioni(p0, i) != 0) {
                    return 1;
                }
            }
        }
    }
    return 0;
}
