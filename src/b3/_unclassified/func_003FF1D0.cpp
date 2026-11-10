// func_003FF1D0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_01ECD950.h"
#include "b3/classes/UnkStruct_D_01ECD954.h"
#include "b3/classes/UnkStruct_D_01ECD960.h"
#include "b3/classes/UnkStruct_D_01ECD964.h"

struct UnkStruct_003FF1D0_5;
struct UnkStruct_003FF1D0_6;
struct UnkStruct_003FF1D0_7;
struct UnkStruct_003FF1D0_8;

struct UnkStruct_003FF1D0_5 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_003FF1D0_6 {
    unsigned char pad_0[0x10];
    int field_10;
    unsigned char pad_14[0x4];
    int field_18;
    int field_1C;
};

struct UnkStruct_003FF1D0_7 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_003FF1D0_8 {
    unsigned char pad_0[0x8];
    float field_8;
};

extern UnkStruct_D_01ECD954 D_01ECD954;
extern UnkStruct_D_01ECD950 D_01ECD950;
extern UnkStruct_D_01ECD960 D_01ECD960;
extern UnkStruct_D_01ECD964 D_01ECD964;
extern "C" void * GetStateFromID__6CGtFSMFUl(void *, unsigned long);
extern "C" void ApplyEvent__29CB3MemCardFSMFlowCommunicatorFUiPv(int, void *);

// 0x003FF1D0
extern "C" void func_003FF1D0(int n0, int p0, int p1, int p2, int p3)
{
    switch (p0) {
    case 3:
        UnkStruct_003FF1D0_5 * r0 = (UnkStruct_003FF1D0_5 *)GetStateFromID__6CGtFSMFUl(&D_01ECD950, 0x93D12267C53B0B63);
        if (D_01ECD954.field_0 != r0) {
            ((UnkStruct_D_01ECD950 *)&D_01ECD950)->vfunc_18(r0, p3);
            void * t0 = D_01ECD954.field_0;
            D_01ECD954.field_0 = (void *)r0;
            UnkStruct_003FF1D0_3 * t1 = D_01ECD960.field_0;
            if (t1 != 0) {
                D_01ECD964.field_0 = t1->field_20;
                if (r0 != 0) {
                    r0->field_8 = t1->field_20;
                }
            }
            ((UnkStruct_D_01ECD950 *)&D_01ECD950)->vfunc_1C(t0, p3);
        }
        break;
    case 4:
        ((UnkStruct_D_01ECD950 *)&D_01ECD950)->vfunc_10();
        break;
    case 5:
        switch (p2) {
        case 0:
            ApplyEvent__29CB3MemCardFSMFlowCommunicatorFUiPv(48, (void *)(0));
            return;
        case 11:
            UnkStruct_003FF1D0_7 * r5 = (UnkStruct_003FF1D0_7 *)GetStateFromID__6CGtFSMFUl(&D_01ECD950, 0x93D12267661960F7);
            if (D_01ECD954.field_0 != r5) {
                ((UnkStruct_D_01ECD950 *)&D_01ECD950)->vfunc_18(r5, 0);
                void * t2 = D_01ECD954.field_0;
                D_01ECD954.field_0 = (void *)r5;
                UnkStruct_003FF1D0_3 * t3 = D_01ECD960.field_0;
                if (t3 != 0) {
                    D_01ECD964.field_0 = t3->field_20;
                    if (r5 != 0) {
                        r5->field_8 = t3->field_20;
                    }
                }
                ((UnkStruct_D_01ECD950 *)&D_01ECD950)->vfunc_1C(t2, 0);
            }
            ApplyEvent__29CB3MemCardFSMFlowCommunicatorFUiPv(50, (void *)(0));
            return;
        case 10:
            ApplyEvent__29CB3MemCardFSMFlowCommunicatorFUiPv(52, (void *)(0));
            return;
        case 12:
            ApplyEvent__29CB3MemCardFSMFlowCommunicatorFUiPv(53, (void *)(0));
            return;
        case 14:
            ApplyEvent__29CB3MemCardFSMFlowCommunicatorFUiPv(60, (void *)(0));
            return;
        case 13:
            UnkStruct_003FF1D0_8 * r12 = (UnkStruct_003FF1D0_8 *)GetStateFromID__6CGtFSMFUl(&D_01ECD950, 0x93D12267661960F7);
            if (D_01ECD954.field_0 != r12) {
                ((UnkStruct_D_01ECD950 *)&D_01ECD950)->vfunc_18(r12, 0);
                void * t4 = D_01ECD954.field_0;
                D_01ECD954.field_0 = (void *)r12;
                UnkStruct_003FF1D0_3 * t5 = D_01ECD960.field_0;
                if (t5 != 0) {
                    D_01ECD964.field_0 = t5->field_20;
                    if (r12 != 0) {
                        r12->field_8 = t5->field_20;
                    }
                }
                ((UnkStruct_D_01ECD950 *)&D_01ECD950)->vfunc_1C(t4, 0);
            }
            ApplyEvent__29CB3MemCardFSMFlowCommunicatorFUiPv(59, (void *)(0));
            return;
        case 1:
            ApplyEvent__29CB3MemCardFSMFlowCommunicatorFUiPv(49, (void *)(0));
            return;
        case 2:
            ApplyEvent__29CB3MemCardFSMFlowCommunicatorFUiPv(50, (void *)(0));
            return;
        }
        break;
    case 2:
        break;
    default:
        break;
    }
}
