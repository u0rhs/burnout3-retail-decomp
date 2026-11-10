// NONMATCHING: func_00457B20 -- retail 856 / ours 856 instructions, 143 in changed runs
// draftZ: 856/856, 11 changed (case 11 only: retail tests p6 twice, both to an out-of-line 0x21 loop; ours defers the second test); frame, calls, jump table, every other case exact
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm: 14-case mode switch of the two-slot panel (func_004572B0's class): destroy loops, text prepares via func_003D0710, image slots via the matched func_004589B0 body inlined, state bytes; every call, argument, constant and store accounted for

// func_00457B20 -- hand-written (draftZ) from the retail asm: mode switch (14 cases, jtbl_004D35A0) of the two-slot
// text/image 2D panel whose per-frame update is func_004572B0 (archived). The image helper is the matched
// func_004589B0 inlined (same body); field names are placeholders; every type is [G] (instruction widths).
#include "b3/GtMathPs2.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dScene.h"
using namespace GtMathPs2;
class CGt2dFont;

struct UnkStruct_00457B20_d { int field_0; int field_4; int field_8; unsigned char field_C; unsigned char field_D; };
struct UnkStruct_00457B20 {
    CGt2dScene * field_0;
    int field_4;
    int field_8;
    CGt2dObject * field_C;
    CGt2dObject * field_10[2];
    CGt2dObject * field_18[2];
    CGtV2d field_20[2];
    CGtV2d field_30[2];
    const unsigned short * field_40[2];
    CGt2dFrame * field_48;
    float field_4C;
    unsigned char field_50[2];
    unsigned char field_52[2];
    unsigned char field_54[2];
    unsigned char field_56;
    unsigned char field_57;
    unsigned char field_58;
};
struct UnkStruct_D_00665ED0 { CGt2dFont * pFont; unsigned char pad[0x100]; };
struct UnkStruct_D_0066A4C0 { unsigned char pad_0[0x40]; CGtV4d field_40; };
struct UnkStruct_D_004F50A0 { float field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_00665ED0 D_00665ED0;
extern UnkStruct_D_0066A4C0 D_0066A4C0;
extern UnkStruct_D_004F50A0 D_004F50A0;
extern CGtV4d D_004D3580;

extern "C" void func_00458AE0(void *, const void *);
extern "C" void Prepare__11CGt2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dPFRCQ211CGt2dObject16CGt2dObjectSpacePCv_vUiUi(void *, const CGtV2d &, const CGtV2d &, CGtV4d, const void *, unsigned int, unsigned int);
extern "C" void func_003D0710(CGt2dObject *obj, const CGtV2d &pos, const CGtV2d &anchor, CGtV4d colour, int a, int b,
                              int c, CGt2dFont *font, float size, float d, const unsigned short *text, int e);

static inline CGtV2d func_00457B20_inl0(const CGtV2d &a, const CGtV2d &b) { return a - b; }
// = func_004589B0 (matched), inlined
static inline void func_00457B20_inl1(CGt2dObject ** slot, const CGtV2d & pos, const CGtV2d & anchor, const CGtV2d & size, int p0, int p1,
                                      CGt2dScene * scene, int id, CGt2dFrame * frame)
{
    *slot = scene->ConstructObject(id, frame);
    CGt2dObject * o = *slot;
    UnkStruct_00457B20_d * d = (UnkStruct_00457B20_d *)((char *)o + 0x20);
    CGtV4d white(1.0f, 1.0f, 1.0f, 1.0f);
    CGtV2d tp = func_00457B20_inl0(pos, anchor * size);
    Prepare__11CGt2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dPFRCQ211CGt2dObject16CGt2dObjectSpacePCv_vUiUi(o, tp, size, white, (const void *)&func_00458AE0, 64, 16);
    d->field_0 = p0;
    d->field_4 = p1;
    d->field_8 = 0;
    d->field_C = 0;
    d->field_D = 0;
}
static inline void func_00457B20_inl2(CGt2dObject * o, unsigned char s)
{
    UnkStruct_00457B20_d * d = (UnkStruct_00457B20_d *)((char *)o + 0x20);
    d->field_C = s;
    d->field_8 = 0;
}
static inline void func_00457B20_inl3(UnkStruct_00457B20 * self, CGt2dObject *& slot)
{
    if (slot) {
        self->field_0->DestructObject(self->field_8, slot);
        slot = 0;
    }
}
static inline void func_00457B20_inl9(UnkStruct_00457B20 * self, CGt2dObject *& slot)
{
    if (slot) {
        self->field_0->DestructObject(self->field_4, slot);
        slot = 0;
    }
}
static inline void func_00457B20_inl4(UnkStruct_00457B20 * self)
{
    for (int i = 0; i < 2; i++)
        func_00457B20_inl9(self, self->field_10[i]);
}
static inline void func_00457B20_inl5(UnkStruct_00457B20 * self)
{
    for (int i = 0; i < 2; i++)
        func_00457B20_inl3(self, self->field_18[i]);
}
static inline void func_00457B20_inl6(UnkStruct_00457B20 * self, const unsigned short * text, int n)
{
    func_003D0710(self->field_C, CGtV2d(0.0f, 0.0f), CGtV2d(0.5f, 0.0f), D_004D3580, n, 0, 0, D_00665ED0.pFont, 52.0f,
                  3.402823466e+38f, text, 0);
}
static inline void func_00457B20_inl7(UnkStruct_00457B20 * self, CGt2dObject *& slot, const unsigned short * text, float x,
                                      CGt2dFrame * frame)
{
    if (text) {
        if (slot == 0)
            slot = self->field_0->ConstructObject(self->field_4, frame);
        func_003D0710(slot, CGtV2d(x, 55.0f), CGtV2d(0.5f, 0.0f), D_004D3580, 1, 1, 0, D_00665ED0.pFont, 42.0f,
                      3.402823466e+38f, text, 0);
    }
}
static inline void func_00457B20_inl8(UnkStruct_00457B20 * self, CGt2dObject *& slot, float x, int tex, CGt2dFrame * frame)
{
    func_00457B20_inl3(self, slot);
    func_00457B20_inl1(&slot, CGtV2d(x, 55.0f), CGtV2d(0.5f, 0.0f), CGtV2d(70.0f, 70.0f), tex, 0, self->field_0, self->field_8, frame);
    func_00457B20_inl2(slot, 2);
}

// 0x00457B20
extern "C" void func_00457B20(UnkStruct_00457B20 * self, CGt2dFrame * frame, const unsigned short * p3, const unsigned short * p4,
                              int mode, int p6, int p7)
{
    UnkStruct_D_0066A4C0 * const cols = &D_0066A4C0;
    self->field_48 = frame;
    if (self->field_C == 0)
        self->field_C = self->field_0->ConstructObject(self->field_4, frame);
    switch (mode) {
    case 0:
        func_00457B20_inl5(self);
        func_00457B20_inl4(self);
        func_00457B20_inl6(self, p3, 1);
        break;
    case 1:
        func_00457B20_inl4(self);
        func_00457B20_inl6(self, p3, 4);
        break;
    case 2:
        func_00457B20_inl5(self);
        func_00457B20_inl4(self);
        func_00457B20_inl6(self, p3, 1);
        break;
    case 3:
        func_00457B20_inl5(self);
        func_00457B20_inl4(self);
        func_00457B20_inl6(self, p3, 2);
        break;
    case 4:
        func_00457B20_inl5(self);
        func_00457B20_inl4(self);
        func_00457B20_inl6(self, p3, 3);
        break;
    case 5:
        if (self->field_10[0] == 0)
            func_00457B20_inl7(self, self->field_10[0], p3, 0.0f, frame);
        self->field_20[0] = self->field_10[0]->Pos();
        self->field_30[0] = self->field_10[0]->Size();
        self->field_40[0] = p3;
        self->field_4C = D_004F50A0.field_0;
        self->field_50[0] = 1;
        self->field_52[0] = 0;
        self->field_54[0] = 0;
        self->field_56 = 1;
        break;
    case 6:
        for (int i = 0; i < 2; i++) {
            if (self->field_10[i] == 0) {
                if (i == 0) {
                    if (p3 == 0)
                        continue;
                    func_00457B20_inl7(self, self->field_10[0], p3, -120.0f, frame);
                } else {
                    if (p4 == 0)
                        continue;
                    func_00457B20_inl7(self, self->field_10[1], p4, 120.0f, frame);
                }
            }
            self->field_20[i] = self->field_10[i]->Pos();
            self->field_30[i] = self->field_10[i]->Size();
            if (i == 0)
                self->field_40[i] = p3;
            else
                self->field_40[i] = p4;
            self->field_4C = D_004F50A0.field_0;
            self->field_50[i] = 1;
            self->field_52[i] = 0;
            self->field_54[i] = 0;
            self->field_56 = 0;
        }
        break;
    case 7:
        func_00457B20_inl4(self);
        func_00457B20_inl8(self, self->field_18[0], 0.0f, p6, frame);
        break;
    case 8:
        func_00457B20_inl4(self);
        if (p6)
            func_00457B20_inl8(self, self->field_18[0], -120.0f, p6, frame);
        if (p7)
            func_00457B20_inl8(self, self->field_18[1], 120.0f, p7, frame);
        break;
    case 9:
        for (int i = 0; i < 2; i++) {
            if (self->field_18[i])
                func_00457B20_inl2(self->field_18[i], 1);
        }
        break;
    case 12:
        func_00457B20_inl4(self);
        func_00457B20_inl5(self);
        func_00457B20_inl8(self, self->field_18[0], 0.0f, p6, frame);
        func_003D0710(self->field_C, CGtV2d(0.0f, 0.0f), CGtV2d(0.5f, 0.0f), cols->field_40, 5, 0, 0, D_00665ED0.pFont, 52.0f,
                      3.402823466e+38f, p3, 0);
        break;
    case 13:
        self->field_58 = 1;
        break;
    case 10:
        self->field_57 = 1;
        break;
    case 11:
        if (p6 == 0 || p6 == 0) {
            for (int i = 0; i < 2; i++) {
                CGt2dObject * o = self->field_18[i];
                if (o) {
                    UnkStruct_00457B20_d * d = (UnkStruct_00457B20_d *)((char *)o + 0x20);
                    d->field_C = 0x21;
                    d->field_D |= 1;
                    d->field_8 = 0;
                }
            }
        } else {
            for (int i = 0; i < 2; i++) {
                if (self->field_18[i])
                    func_00457B20_inl2(self->field_18[i], 1);
            }
        }
        break;
    }
}


