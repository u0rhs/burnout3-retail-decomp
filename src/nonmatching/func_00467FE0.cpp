// NONMATCHING: func_00467FE0 -- retail 238 / ours 238 instructions, 10 in changed runs
// near24 (27->10, length exact): range test !(v < 8 && !(0 > v)) gives slt/beqz, inner do-while (j <= 7) gives slti at. Left: loop value v in a1 vs retail a0 (swapped with the i&0xFF compare temp); decl/loop-form/inline/type variants inert
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// sdra: const pointee on a read-only param [G] (const loads are not ordered after stores, sdra rule 1)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// logic complete (237/238 instrs); remaining: loop value register (ours a1, retail a0 -> shifts temps), bgez vs slt/beqz for v>=0, hoisted const t0/t1 numbering
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// func_00467FE0 -- placeholder (a184, hand-matched).
struct UnkStruct_00467FE0_A {
    unsigned short field_0;
    unsigned char pad_2[2];
    int field_4[18];
    int field_4C;
    int field_50;
    unsigned char pad_54[0x3D8];
    int field_42C;
};

struct UnkStruct_00467FE0_B {
    int field_0;
    int field_4;
};

struct UnkStruct_D_004E2FCC {
    UnkStruct_00467FE0_A * field_0;
};

struct UnkStruct_D_004E2FC8 {
    UnkStruct_00467FE0_B * field_0;
};

extern UnkStruct_D_004E2FCC D_004E2FCC;
extern UnkStruct_D_004E2FC8 D_004E2FC8;
extern unsigned char D_004B12D0[];
extern unsigned char D_004B1310[];
extern "C" UnkStruct_00467FE0_A * func_00360AE0(int, int, int);

static inline int func_00467FE0_inl0()
{
    return D_004E2FCC.field_0 != 0;
}

// 0x00467FE0
extern "C" int func_00467FE0(int * p0, const int * p1, int p2)
{
    unsigned char i = 0;
    if (func_00467FE0_inl0()) {
        return 1;
    }
    if (p0 == 0) return 0xC;
    if (p0[0] == -1) return 0xC;
    if (p1 == 0) return 0xC;
    if (p1[0] == 0 ||
        p1[1] == 0 ||
        p1[2] == 0 ||
        p1[3] == 0 ||
        p1[4] == 0 ||
        p1[5] == 0 ||
        p1[6] == 0 ||
        p1[7] == 0 ||
        p1[8] == 0 ||
        p1[9] == 0 ||
        p1[10] == 0 ||
        p1[11] == 0 ||
        p1[12] == 0 ||
        p1[13] == 0 ||
        p1[14] == 0 ||
        p1[15] == 0 ||
        p1[16] == 0 ||
        p1[17] == 0) {
        return 0xC;
    }
    if (D_004E2FCC.field_0 != 0 || D_004E2FC8.field_0 != 0) {
        return 1;
    }
    D_004E2FCC.field_0 = func_00360AE0(p2, 0x430, 4);
    if (D_004E2FCC.field_0 == 0) {
        return 7;
    }
    D_004E2FC8.field_0 = (UnkStruct_00467FE0_B *)func_00360AE0(p2, 0x74, 4);
    if (D_004E2FC8.field_0 == 0) {
        return 7;
    }
    D_004E2FCC.field_0->field_42C = p2;
    D_004E2FCC.field_0->field_0 = 0;
    int v;
    while ((v = *p0) != -1) {
        if (!(v < 8 && !(0 > v)) && v != 9) {
            return 9;
        }
        if (i == 8) {
            return 0xC;
        }
        if (v != 9) {
            D_004E2FCC.field_0->field_0 |= (unsigned short)(1 << (unsigned short)v);
        } else {
            signed char j = 0;
            do {
                D_004E2FCC.field_0->field_0 |= (unsigned short)(1 << (unsigned short)j);
                j++;
            } while (j <= 7);
        }
        i++;
        p0++;
    }
    D_004E2FCC.field_0->field_4[0] = p1[0];
    D_004E2FCC.field_0->field_4[1] = p1[1];
    D_004E2FCC.field_0->field_4[2] = p1[2];
    D_004E2FCC.field_0->field_4[3] = p1[3];
    D_004E2FCC.field_0->field_4[4] = p1[4];
    D_004E2FCC.field_0->field_4[5] = p1[5];
    D_004E2FCC.field_0->field_4[6] = p1[6];
    D_004E2FCC.field_0->field_4[7] = p1[7];
    D_004E2FCC.field_0->field_4[8] = p1[8];
    D_004E2FCC.field_0->field_4[9] = p1[9];
    D_004E2FCC.field_0->field_4[10] = p1[10];
    D_004E2FCC.field_0->field_4[11] = p1[11];
    D_004E2FCC.field_0->field_4[12] = p1[12];
    D_004E2FCC.field_0->field_4[13] = p1[13];
    D_004E2FCC.field_0->field_4[14] = p1[14];
    D_004E2FCC.field_0->field_4[15] = p1[15];
    D_004E2FCC.field_0->field_4[16] = p1[16];
    D_004E2FCC.field_0->field_4[17] = p1[17];
    D_004E2FCC.field_0->field_4C = (int)D_004B12D0;
    D_004E2FCC.field_0->field_50 = (int)D_004B1310;
    D_004E2FC8.field_0->field_0 = 0;
    D_004E2FC8.field_0->field_4 = 0;
    return 0;
}
