// NONMATCHING: func_003CD140 -- retail 143 / ours 145 instructions, 93 in changed runs
// a250: logic complete; u32->float via 'float v4=(float)t2' (unsigned int) gives single bltz path; m0+=v9 shared add; bottom-tested while loop via 'int i=0; while(i<field_4AF)'. Remaining: constant-hoist order in prologue (retail li t4,1 held in reg and v10 select kept in loop; ours hoists p0==0 computation), schedule. Scheduling/hoisting. lit4 park was 1.69f/0.1f gp pool order.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// lifter variant 0
// func_003CD140 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_003CD140;
struct UnkStruct_003CD140_3;
struct UnkStruct_003CD140_4;
struct UnkStruct_003CD140_e2;

struct UnkStruct_003CD140_3 {
    unsigned char pad_0[0xCC4];
    UnkStruct_003CD140_4 * field_CC4;
};

struct UnkStruct_003CD140_4 {
    unsigned char pad_0[0x370];
    float field_370;
};

struct UnkStruct_003CD140_e2 {
    unsigned char pad_0[0x18];
    float field_18[1];  // [G] element count unknown
    unsigned char pad_1C[0xEC];
};

struct UnkStruct_003CD140 {
    unsigned char pad_0[0x10];
    int field_10;
    int field_14;
    UnkStruct_003CD140_3 * field_18[1];  // [G] element count unknown
    unsigned char pad_1C[0x104];
    int field_120[1];  // [G] element count unknown
    unsigned char pad_124[0xEC];
    UnkStruct_003CD140_e2 field_210[1];  // [G] element count unknown
    unsigned char pad_318[0x197];
    unsigned char field_4AF;
    unsigned char pad_4B0[0x48];
    unsigned char field_4F8;
};

// 0x003CD140
extern "C" int func_003CD140(UnkStruct_003CD140 * self, int p0)
{
    int m0 = 0;
    int i = 0;
    while (i < self->field_4AF) {
        unsigned char t0 = self->field_4AF;
        UnkStruct_003CD140_3 * t1 = self->field_18[i];
        int v0;
        for (int i1 = 0; (i1 < t0); i1++) {
            if (self->field_18[i1] == t1) {
                v0 = i1;
                goto g40;
            }
        }
        v0 = -1;
g40:;
        int v9;
        if (v0 == -1) {
            v9 = 0;
        } else {
            float v1 = t1->field_CC4->field_370;
            if (t1->field_CC4->field_370 < 0.1f) {
                v1 = 0.1f;
            }
            float v2 = (v1 * 1.69f);
            if (!((v1 * 1.69f) <= 1.0f)) {
                v2 = 1.0f;
            }
            int v3 = ((int)(((float)self->field_120[v0]) * v2));
            if (((int)(((float)self->field_120[v0]) * v2)) >= 0x186A1) {
                v3 = 0x186A0;
            }
            self->field_10 = ((self->field_10 << 16) + (self->field_10 >> 16));
            self->field_10 = (self->field_10 + self->field_14);
            self->field_14 = (self->field_14 + self->field_10);
            int t2 = self->field_10;
            float v4 = (float)(unsigned int)t2;
            v9 = (v3 + ((int)(25.0f * (-1.0f * (2.3283064e-10f * v4)))));
        }
        if (v9 > 0) {
            if (self->field_4F8 != 0) {
                float t3 = self->field_210[p0].field_18[i];
                if (t3 <= 0.0f) { i++; continue; }
                int v10;
                if (p0 != 0) v10 = 0; else v10 = 1;
                float v13;
                if (!(t3 < 0.1f)) {
                    v13 = (self->field_210[p0].field_18[i] / (self->field_210[p0].field_18[i] + self->field_210[v10].field_18[i]));
                } else {
                    v13 = 0.0f;
                }
                v9 = (int)((float)v9 * v13);
            }
            m0 = m0 + v9;
        }
        i++;
    }
    return m0;
}

