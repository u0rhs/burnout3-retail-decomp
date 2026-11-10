// NONMATCHING: func_002BD6A0 -- retail 79 / ours 79 instructions, 25 in changed runs
// near20: old archive re-runs at 28 (its header's 20 is stale); cnt declared before arr in the outer loop gives 25. Left: t-register naming of fl/fc/arr/cnt/arrm and head schedule (retail puts i=0 first). 48 declaration permutations tried (build/vt/hand/near20_v21.txt).
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// NONMATCHING: func_002BD6A0 -- retail 79 / ours 79 instructions, 20 in changed runs
// a220: j declared before i, arr/cnt/arrm in retail order: 20 in changed runs, only fl/fc (retail t0/a3, ours t2/t1) and arr/arrm shifted; decl order of fl/fc no effect
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// a66: 79/79 instrs, 25 in changed runs, all register naming (fl/fc/i/j/arr/cnt/arrm permuted; retail i=t4 j=t5 arr=t3 cnt=t2 arrm=t1 fl=t0 fc=a3). Bool diamond solved with an enum-typed local (see a66). Layout: lifter's field_13AD8[i].field_130/field_134 + field_13CE0[i].field_12C (stride 0x208); true layout is probably one struct {void*arr[128]; int count; int cap;} at +0x13C0C but that gives arrm=arr-1 as addiu (77 instrs)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// from build/vt\try_func_002BD6A0_best.cpp
// func_002BD6A0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

enum UnkEnum_002BD6A0 { UnkEnum_002BD6A0_0 = 0, UnkEnum_002BD6A0_1 = 1 };
struct UnkStruct_002BD6A0;
struct UnkStruct_002BD6A0_5;
struct UnkStruct_002BD6A0_6;
struct UnkStruct_002BD6A0_e0;
struct UnkStruct_002BD6A0_e1;
struct UnkStruct_D_00522680;

struct UnkStruct_002BD6A0_e0 {
    unsigned char pad_0[0x12C];
    int field_12C;
    unsigned char pad_130[0xD8];
};

struct UnkStruct_002BD6A0_e1 {
    unsigned char pad_0[0x130];
    int field_130[1];  // [G] element count unknown
    UnkStruct_002BD6A0_5 * field_134[1];  // [G] element count unknown
    unsigned char pad_138[0xD0];
};

struct UnkStruct_D_00522680 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_002BD6A0_5 {
    float field_0;
    UnkStruct_002BD6A0_6 * field_4;
    unsigned char pad_8[0x9];
    signed char field_11;
};

struct UnkStruct_002BD6A0_6 {
    unsigned char pad_0[0x4C];
    float field_4C;
};

struct UnkStruct_002BD6A0 {
    unsigned char pad_0[0x13A00];
    void * * field_13A00;
    int field_13A04;
    unsigned char pad_13A08[0xD0];
    UnkStruct_002BD6A0_e1 field_13AD8[1];  // [G] element count unknown
    UnkStruct_002BD6A0_e0 field_13CE0[1];  // [G] element count unknown
};

extern UnkStruct_D_00522680 D_00522680;

// 0x002BD6A0
extern "C" void func_002BD6A0(UnkStruct_002BD6A0 * self)
{
    void * * * const fl = &self->field_13A00;
    int * const fc = &self->field_13A04;
    int j;
    int i = 0;
    do {
        int * const cnt = &self->field_13CE0[i].field_12C;
        UnkStruct_002BD6A0_5 ** const arr = self->field_13AD8[i].field_134;
        int * const arrm = self->field_13AD8[i].field_130;
        j = 0;
        for (; ; j++) {
            if (j >= *cnt) break;
            UnkStruct_002BD6A0_5 * e = arr[j];
            UnkEnum_002BD6A0 v;
            if (D_00522680.field_0 - e->field_0 > e->field_4->field_4C) v = UnkEnum_002BD6A0_1; else v = UnkEnum_002BD6A0_0;
            if (v == UnkEnum_002BD6A0_1) {
                e->field_11 = -1;
                if (j == *cnt - 1) {
                    arr[j] = 0;
                } else {
                    arr[j] = (UnkStruct_002BD6A0_5 *)arrm[*cnt];
                    arrm[*cnt] = 0;
                }
                (*cnt)--;
                j--;
                (*fl)[(*fc)++] = e;
            }
        }
        i++;
    } while (i < 5);
}

