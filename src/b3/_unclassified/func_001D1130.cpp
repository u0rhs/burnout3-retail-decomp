// Hand-written; the lifter refused it (two copies of the nearest-car loop (c declared before j in the second), squared length via a by-value inline, a+t*(b-a) inline for adda/madd, D_004E0B18 global at the reload site).

// func_001D1130 -- hand-matched (v310). Unnamed in every table: a placeholder with C linkage (the asm label).
// [L] neighbour of func_001D0F50 = DNAT CB3AICar::AdjustOutOfRange(CB3PlayerCar*, float, CAIRangeAttribs&)
// (research/proto/new_names.csv, low): its a2 is the 12-byte attribute block on our stack. Types are [G].

#include "b3/GtMathPs2.h"

using namespace GtMathPs2;

struct UnkStruct_001D1130_attr {
    float field_0;
    float field_4;
    unsigned char field_8;
    unsigned char field_9;
    unsigned char field_A;
};

struct UnkStruct_001D1130_rc {
    unsigned char pad_0[0x1910];
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18();
    virtual CGtV3d vfunc_1C();
};

struct UnkStruct_001D1130_car {
    unsigned char pad_0[0x1678];
    unsigned char field_1678;
    unsigned char pad_1679[0x1914 - 0x1679];
    int field_1914;
    unsigned char pad_1918[0x1B83 - 0x1918];
    unsigned char field_1B83;
    unsigned char pad_1B84[0x20F0 - 0x1B84];
    float field_20F0;
    unsigned char pad_20F4[0x2188 - 0x20F4];
    unsigned char field_2188;
    unsigned char pad_2189[0x244D - 0x2189];
    unsigned char field_244D;
    unsigned char pad_244E[0x27C9 - 0x244E];
    unsigned char field_27C9;
};

struct UnkStruct_001D1130_best {
    unsigned char pad_0[0x19AC];
    signed char field_19AC;
};

struct UnkStruct_001D1130_obj {
    unsigned char pad_0[0x30];
    CGtV3d field_30;
};

struct UnkStruct_001D1130 {
    unsigned char pad_0[0x204];
    UnkStruct_001D1130_obj * field_204;
    unsigned char pad_208[0xE];
    signed char field_216;
    signed char field_217;
    unsigned char pad_218[0x1353 - 0x218];
    unsigned char field_1353;
    unsigned char pad_1354[0x1534 - 0x1354];
    float field_1534;
    unsigned char pad_1538[0x1550 - 0x1538];
    unsigned char field_1550;
    unsigned char pad_1551[2];
    unsigned char field_1553;
    unsigned char pad_1554[0x1558 - 0x1554];
    int field_1558;
    float field_155C;
    float field_1560[2];
    UnkStruct_001D1130_car * field_1568;
};

struct UnkStruct_001D1130_pmc { unsigned char pad_0[0x458C]; int field_458C; };

struct UnkStruct_001D1130_pm {
    struct { UnkStruct_001D1130_pmc * field_0; unsigned char pad_4[0x2C]; } field_0[1];
};

struct UnkStruct_001D1130_g { int field_0; unsigned char pad_4[0xC]; };

extern UnkStruct_001D1130_g D_0064D3A0;
extern unsigned char D_00522660[];
extern UnkStruct_001D1130_pm D_0055EFEC;

extern float D_004E0B18;
extern "C" int TestPosition__16CB3StreamedTrackFQ29GtMathPs26CGtV3d(void *, void *);
extern "C" void func_001D0F50(UnkStruct_001D1130 *, void *, float, UnkStruct_001D1130_attr *);
extern "C" void func_001D0D00(UnkStruct_001D1130 *);
extern "C" void func_001D0E00(UnkStruct_001D1130 *);

// [G] unnamed inlined helpers: a squared length taking its vector by value (the by-value parameter puts the
// difference vectors below both call-result temporaries, as retail's frame), and an a + t*(b - a) blend
// ([L] GtMath::Interpolate(float,float,float), E map 0x14CCF0 -- the N221 body; inlined with constants it gives
// retail's adda/madd operand order).
static inline float func_001D1130_inl4(CGtV3d d) { return d.GetSquaredLength(); }
static inline float func_001D1130_inl7(float a, float b, float t) { float d = b - a; return a + t * d; }

// 0x001D1130
extern "C" void func_001D1130(UnkStruct_001D1130 * self)
{
    UnkStruct_001D1130_attr attr;
    attr.field_0 = 0.0f;
    float best = 3.402823466e+38f;
    attr.field_8 = 0;
    attr.field_9 = 0;
    attr.field_A = 0;
    attr.field_4 = 0.0f;
    UnkStruct_001D1130_rc * bc = 0;
    int i;
    if (self->field_1568->field_1914 == 0) {
        if (self->field_1568->field_27C9 != 0) {
        self->field_1558 = 0;
        self->field_155C = 1.0f;
        for (i = 0; i < D_0064D3A0.field_0; i++) {
            UnkStruct_001D1130_rc * c = (UnkStruct_001D1130_rc *)(D_00522660 + i * 0x27D0 + 0x12AD50);
            CGtV3d * mp = &self->field_204->field_30;
            float d = func_001D1130_inl4(c->vfunc_1C() - *mp);
            self->field_1560[i] = d;
            if (TestPosition__16CB3StreamedTrackFQ29GtMathPs26CGtV3d(D_00522660 + i * 0x1CC + 0x12A348, &self->field_204->field_30) != -1 && d < best) {
                bc = c;
                best = d;
            }
        }
        if (bc != 0) {
            self->field_217 = D_0055EFEC.field_0[((UnkStruct_001D1130_best *)bc)->field_19AC].field_0->field_458C;
            self->field_216 = TestPosition__16CB3StreamedTrackFQ29GtMathPs26CGtV3d(D_00522660 + self->field_217 * 0x1CC + 0x12A348, &self->field_204->field_30);
        } else {
            self->field_216 = -1;
        }
        func_001D0F50(self, bc, best, &attr);
        } else {
        attr.field_8 = 1;
        attr.field_9 = 1;
        attr.field_A = 1;
        attr.field_0 = 1.0f;
        attr.field_4 = 1.0f;
        }
    } else {
        UnkStruct_001D1130_rc * c;  // declared before j: retail's s4/s3 for this copy of the loop
        int j;
        self->field_1558 = 0;
        self->field_155C = 1.0f;
        for (j = 0; j < D_0064D3A0.field_0; j++) {
            c = (UnkStruct_001D1130_rc *)(D_00522660 + j * 0x27D0 + 0x12AD50);
            CGtV3d * mp = &self->field_204->field_30;
            float d = func_001D1130_inl4(c->vfunc_1C() - *mp);
            self->field_1560[j] = d;
            if (TestPosition__16CB3StreamedTrackFQ29GtMathPs26CGtV3d(D_00522660 + j * 0x1CC + 0x12A348, &self->field_204->field_30) != -1 && d < best) {
                bc = c;
                best = d;
            }
        }
        if (bc != 0) {
            self->field_217 = D_0055EFEC.field_0[((UnkStruct_001D1130_best *)bc)->field_19AC].field_0->field_458C;
            self->field_216 = TestPosition__16CB3StreamedTrackFQ29GtMathPs26CGtV3d(D_00522660 + self->field_217 * 0x1CC + 0x12A348, &self->field_204->field_30);
        } else {
            self->field_216 = -1;
        }
        func_001D0F50(self, bc, best, &attr);
    }
    if (self->field_1568->field_1678 != 0) {
        attr.field_A = 1;
    } else if (self->field_1568->field_244D != 0 || self->field_1568->field_1B83 == 0) {
        attr.field_A = 0;
    }
    self->field_1568->field_244D = 0;
    if (attr.field_8) {
        self->field_1568->field_20F0 = 1.0f - attr.field_0;
        self->field_1568->field_2188 = attr.field_0 != 1.0f;
        self->field_1534 = func_001D1130_inl7(0.03f, 1.0f, attr.field_4);
    } else {
        self->field_1568->field_20F0 = 0.0f;
        self->field_1568->field_2188 = 1;
        self->field_1534 = 0.03f;
    }
    // [G] D_004E0B18 (= 0.03f, .lit4) read as the global here: retail reloads it after the field_1534 stores, which a
    // literal does not
    if (self->field_1568->field_1678 != 0) self->field_1534 = D_004E0B18;
    if (attr.field_9 == 0) self->field_1353 |= 2;
    if (self->field_1553 != 0 && attr.field_8 != 0) {
        self->field_1553 = 0;
    } else if (attr.field_A == 0) {
        self->field_1353 |= 0x10;
        self->field_1353 |= 8;
    }
    if (self->field_1550 != attr.field_8) {
        if (attr.field_8) func_001D0D00(self);
        else func_001D0E00(self);
    }
}
