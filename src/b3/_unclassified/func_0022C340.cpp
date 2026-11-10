// func_0022C340 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (near36: signed char i = p0 local (stops self+i*4 CSE as retail), FA5 test as early return r, retail branch senses (> 0 positive arms), FC8 -= then re-read for the FD8 compare).

// lifter variant 0
// func_0022C340 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_0022C340;
struct UnkStruct_0022C340_e12;
struct UnkStruct_0022C340_e3;
struct UnkStruct_0022C340_e4;
struct UnkStruct_D_004F509C;
struct UnkStruct_D_0051A6A8;
struct UnkStruct_D_0051BA88;
struct UnkStruct_D_00522660;
struct UnkStruct_D_0064D3A0;
struct UnkStruct_D_00665E53;
struct UnkStruct_D_00665EA0;

struct UnkStruct_D_0051BA88 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0064D3A0 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0022C340_e3 {
    unsigned char pad_0[0x3C8];
    unsigned char field_3C8;
    unsigned char pad_3C9[0x2407];
};

struct UnkStruct_0022C340_e12 {
    unsigned char pad_0[0x27D0];
};

struct UnkStruct_0022C340_e4 {
    unsigned char pad_0[0x170C];
    int field_170C;
    unsigned char pad_1710[0x10C0];
};

struct UnkStruct_D_00522660 {
    UnkStruct_0022C340_e12 field_0[1];  // [G] element count unknown
    unsigned char pad_27D0[0x1281B0];
    UnkStruct_0022C340_e4 field_12A980[1];  // [G] element count unknown
    UnkStruct_0022C340_e3 field_12D150[1];  // [G] element count unknown
};

struct UnkStruct_D_00665EA0 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_00665E53 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004F509C {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0051A6A8 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_Rec {
    unsigned char pad_0[0x133C];
    int field_133C;
    unsigned char pad_1340[0x1488];
    unsigned char field_27C8;
    unsigned char pad_27C9[7];
};

struct UnkStruct_0022C340 {
    unsigned char pad_0[0xFA1];
    signed char field_FA1[1];  // [G] element count unknown
    unsigned char pad_FA2[0x3];
    unsigned char field_FA5[1];  // [G] element count unknown
    unsigned char pad_FA6[0x2];
    float field_FA8[1];  // [G] element count unknown
    unsigned char pad_FAC[0x4];
    float field_FB0[1];  // [G] element count unknown
    unsigned char pad_FB4[0x4];
    float field_FB8[1];  // [G] element count unknown
    unsigned char pad_FBC[0x4];
    float field_FC0[1];  // [G] element count unknown
    unsigned char pad_FC4[0x4];
    float field_FC8[1];  // [G] element count unknown
    unsigned char pad_FCC[0x4];
    float field_FD0[1];  // [G] element count unknown
    unsigned char pad_FD4[0x4];
    float field_FD8[1];  // [G] element count unknown
    unsigned char pad_FDC[0x5];
    unsigned char field_FE1[1];  // [G] element count unknown
};

extern UnkStruct_D_0051BA88 D_0051BA88;
extern UnkStruct_D_0064D3A0 D_0064D3A0;
extern UnkStruct_D_00522660 D_00522660;
extern UnkStruct_D_00665EA0 D_00665EA0;
extern UnkStruct_D_00665E53 D_00665E53;
extern UnkStruct_D_004F509C D_004F509C;
extern UnkStruct_D_0051A6A8 D_0051A6A8;

// 0x0022C340
extern "C" bool func_0022C340(UnkStruct_0022C340 * self, int p0)
{
    signed char i = p0;
    bool r = false;
    if (self->field_FA5[self->field_FA1[i]] == 0) return r;
    int t0 = D_0051BA88.field_0;
    if (t0 != 0) {
        if (t0 != (int)&D_0051A6A8) {
            if (i < D_0064D3A0.field_0) {
                UnkStruct_Rec *rc = (UnkStruct_Rec *)((char *)&D_00522660 + i * 0x27D0 + 0x12AD50);
                if (rc != 0) {
                    if (rc->field_27C8 != 0 || rc->field_133C == 3) {
                        self->field_FE1[i] = 1;
                    }
                }
                if (D_00665EA0.field_0 != 0 || D_00665E53.field_0 != 0 || rc->field_133C == 0) {
                    self->field_FE1[i] = 1;
                }
            } else {
                self->field_FE1[i] = 1;
            }
        }
    }
    if (self->field_FE1[i] != 0) {
        self->field_FA8[i] = 0.0f;
        self->field_FB0[i] = 0.0f;
        self->field_FC0[i] = 0.0f;
        self->field_FC8[i] = 0.0f;
        self->field_FB8[i] = 0.0f;
        self->field_FD0[i] = 0.0f;
        self->field_FD8[i] = 0.0f;
        self->field_FE1[i] = 0;
        return true;
    }
    if (self->field_FC0[i] > 0.0f) {
        float n = self->field_FC0[i] - D_004F509C.field_0;
        self->field_FC0[i] = n;
        if (n > 0.0f) {
            if (1.0f != self->field_FA8[i]) {
                self->field_FA8[i] = 1.0f;
                r = true;
            }
        } else {
            self->field_FA8[i] = 0.0f;
            r = true;
        }
    }
    if (self->field_FC8[i] > 0.0f) {
        self->field_FC8[i] -= D_004F509C.field_0;
        float t4 = self->field_FC8[i];
        if (t4 > 0.0f) {
            if (self->field_FC8[i] > self->field_FD8[i]) {
                if (self->field_FB0[i] != self->field_FD0[i]) {
                    self->field_FB0[i] = self->field_FD0[i];
                    r = true;
                }
            } else {
                float q = self->field_FD0[i] / 3.2f;
                if (q > self->field_FB8[i]) {
                    if (self->field_FB0[i] != q) {
                        self->field_FB0[i] = q;
                        r = true;
                        self->field_FD0[i] = q;
                    }
                } else {
                    if (self->field_FB0[i] != self->field_FB8[i]) {
                        self->field_FB0[i] = self->field_FB8[i];
                        r = true;
                        self->field_FD0[i] = self->field_FB8[i];
                    }
                }
            }
        } else {
            if (self->field_FB8[i] != self->field_FB0[i]) {
                self->field_FB0[i] = self->field_FB8[i];
                r = true;
            }
            self->field_FD0[i] = 0.0f;
        }
    } else if (self->field_FB8[i] != self->field_FB0[i]) {
        self->field_FB0[i] = self->field_FB8[i];
        r = true;
    }
    return r;
}
