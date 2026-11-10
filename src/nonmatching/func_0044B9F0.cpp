// NONMATCHING: func_0044B9F0 -- retail 894 / ours 876 instructions, 615 in changed runs
// draft4: call sequence identical; frame 0x250 vs 0x2C0 (retail keeps more by-value CGtV2d/CGtV4d slots); state dispatch compare order; the pulse/italic-text/row-centre inlines are placeholders (func_0044B9F0_inl1-4)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the asm and Ghidra draft, every branch, store and call accounted for (incl. retail's unused clamp of the uninitialised-when-field_134!=1 f21); call sequence identical (calls.sh)

// func_0044B9F0 -- draft4 (breadth-first draft): a table component's Update(float dt) [L: a0 = self, f12 = dt; same row
// layout as func_0044C960 / func_0044FE00 -- 8 rows of 0x24 bytes from +0xC]. Field names are placeholders, types [G].
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dFont.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dFrame.h"
#include "b3/GtMath.h"
extern "C" float cosf(float);
using namespace GtMathPs2;

struct UnkStruct_D_00665ED0 { CGt2dFont *pFont; unsigned char pad[0x100]; };
extern UnkStruct_D_00665ED0 D_00665ED0;
struct UnkStruct_D_16 { unsigned char pad_0[0x10]; };
extern UnkStruct_D_16 D_01E903E0;   // [C] the menu's CGt2dScene (D_01E90240 + 0x1A0)
extern UnkStruct_D_16 D_0051BA44;   // [C] the string table (B3Strings)
extern UnkStruct_D_16 D_01E7A800;   // [C] the HUD sound manager
extern CGtV4d D_01E90350;           // [C] page manager colour (D_01E90240 + 0x110)
extern CGtV4d D_01E903C0;           // [C] page manager colour (D_01E90240 + 0x180)
extern float D_01E90420[];          // [C] menu transition progress
struct UnkStruct_D_01E90424 { int field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_01E90424 D_01E90424;  // [C] menu transition state
struct UnkStruct_D_004D3130 { float field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_004D3134 { float field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_004D3130 D_004D3130;
extern UnkStruct_D_004D3134 D_004D3134;
extern const CGtV4d D_004D3150;     // [C] 16-byte colours (lqc2 / lq)
extern const CGtV4d D_004D3170;

extern "C" const unsigned short *func_00271A00(void *strings, int id);  // [L] string lookup by id
extern "C" void func_00284390(void *sound);                             // [G] a HUD sound (tick)
extern "C" void DestructObject__10CGt2dSceneFiP11CGt2dObject(void *, int, void *);
extern "C" void func_00453980(const CGt2dObject::CGt2dObjectSpace &, const void *);  // the italic text's render callback
extern "C" void PrepareCommonData__21CGt2dObjectItalicTextFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dfQ29GtMathPs26CGtV4dPC9CGt2dFontPCUsPFRCQ211CGt2dObject16CGt2dObjectSpacePCv_v(
    CGt2dObject *, const CGtV2d &, const CGtV2d &, float, CGtV4d, const CGt2dFont *, const unsigned short *,
    void (*)(const CGt2dObject::CGt2dObjectSpace &, const void *));

struct UnkStruct_0044B9F0;
extern "C" void func_0044CB20(UnkStruct_0044B9F0 *self, int n);
extern "C" void func_0044CF90(UnkStruct_0044B9F0 *self, int idx, float frac);
extern "C" void func_0044C7F0(UnkStruct_0044B9F0 *self, int a, int b);
extern "C" void func_0044C960(UnkStruct_0044B9F0 *self, int row, int flag);

struct UnkStruct_0044B9F0_data { unsigned char pad_0[0xC]; float field_C; CGtV2d field_10; };  // italic text block (+0x20)
struct UnkStruct_0044B9F0_row {
    CGt2dObject *field_0;    // [C] background (colour pulses)
    CGt2dObject *field_4;    // [C] shadow: placed at field_0's position + 6 * pulse
    CGt2dFrame *field_8;     // [C] the row frame (its y is the row position)
    CGt2dFrame *field_C;     // [C] scaled 1.0 .. 1.08 by the pulse
    CGt2dObject *field_10;   // [C] italic texts: title (string id 0x25F + row)
    CGt2dObject *field_14;
    CGt2dObject *field_18;
    CGt2dObject *field_1C;   // [C] value text (field_140[row]); colour pulses
    CGt2dObject *field_20;   // [C] second value text (field_160[row]) when field_134 == 1
};
struct UnkStruct_0044B9F0 {
    unsigned char pad_0[8];
    short field_8;                         // [C] scene layer
    unsigned char pad_A[2];
    UnkStruct_0044B9F0_row field_C[8];
    CGt2dObject *field_12C;                // [C] faded with the menu transition
    unsigned char pad_130[4];
    int field_134;                         // [C] 1 = two value columns and the highlight pulse
    int field_138;                         // [C] row count
    float field_13C;                       // [C] animation timer
    const unsigned short *field_140[8];
    const unsigned short *field_160[8];
    int field_180[8];                      // [C] compared pairwise with field_1A0 (a tick per changed row)
    int field_1A0[8];
    unsigned char pad_1C0[0x38];
    signed char field_1F8;                 // [C] < 0: the reveal is running
    signed char field_1F9;                 // [C] row being moved up one place, < 0 none
    signed char field_1FA;                 // [C] highlighted row, < 0 none
    unsigned char field_1FB;               // [C] swap state toggled with func_0044C960
    unsigned char field_1FC;               // [C] highlight pulse finished
    unsigned char field_1FD;               // [C] reveal enabled
    unsigned char pad_1FE[6];
    unsigned char field_204;               // [C] the intro is over: only the highlight pulse runs
};

// [L] inline (repeated in retail at each use): give an italic text a new string, or destroy it when there is none.
static inline void func_0044B9F0_inl1(UnkStruct_0044B9F0 *self, CGt2dObject **slot, const unsigned short *text, float ax)
{
    CGt2dObject *o = *slot;
    if (o != 0) {
        if (text == 0) {
            DestructObject__10CGt2dSceneFiP11CGt2dObject(&D_01E903E0, self->field_8 + 2, o);
            *slot = 0;
        } else {
            CGtV2d size = o->mObjectSpace.mSize;
            CGtV2d anchor(ax, 0.5f);
            CGtV2d pos(0.0f + o->mObjectSpace.mTopLeftPos.marValues[0] + ax * size.marValues[0], 0.0f);
            PrepareCommonData__21CGt2dObjectItalicTextFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dfQ29GtMathPs26CGtV4dPC9CGt2dFontPCUsPFRCQ211CGt2dObject16CGt2dObjectSpacePCv_v(
                o, pos, anchor, size.marValues[1], o->mObjectSpace.mColour, D_00665ED0.pFont, text, func_00453980);
            UnkStruct_0044B9F0_data *d = (UnkStruct_0044B9F0_data *)o->mauDataBlock;
            d->field_10 = CGtV2d(D_004D3130.field_0, D_004D3134.field_0) / o->mObjectSpace.mSize;
            d->field_C = 0.0f;
        }
    }
}

// [L] inline: the highlighted row's pulse at phase ph (0..1).
static inline void func_0044B9F0_inl2(UnkStruct_0044B9F0 *self, float ph)
{
    float f = (1.0f - cosf(0.017453292f * (360.0f * ph))) * 0.5f;
    UnkStruct_0044B9F0_row *r = &self->field_C[self->field_1FA];
    if (r->field_C != 0) {
        float s = 0.0f + 1.0f + 0.08f * f;
        CGtV2d sc(s, s);
        r->field_C->field_0.field_8 = sc;
    }
    if (r->field_4 != 0 && r->field_0 != 0) {
        r->field_4->mObjectSpace.mTopLeftPos = r->field_0->mObjectSpace.mTopLeftPos + CGtV2d(6.0f * f, 6.0f * f);
        r->field_0->mObjectSpace.mColour = Interpolate(D_004D3150, D_01E90350, f);
    }
    r->field_1C->mObjectSpace.mColour = Interpolate(D_01E903C0, D_004D3170, f);
}

// [L] inline: move every object of a row to y (centred on its height).
static inline void func_0044B9F0_inl3(UnkStruct_0044B9F0_row *r, float y)
{
    CGt2dObject *o = r->field_0;
    for (int j = -1; j < 5;) {
        if (o != 0) {
            CGtV2d p(o->mObjectSpace.mTopLeftPos.marValues[0], 0.0f + y - 0.5f * o->mObjectSpace.mSize.marValues[1]);
            o->mObjectSpace.mTopLeftPos = p;
        }
        j++;
        o = (&r->field_10)[j];
    }
}

static inline float func_0044B9F0_inl4(float a, float b) { return 0.0f + a - b * (float)(int)(a / b); }  // fmod [L]

// 0x0044B9F0
extern "C" void func_0044B9F0(UnkStruct_0044B9F0 *self, float dt)
{
    int state = D_01E90424.field_0;
    switch (state) {
    case 5: {
        if (self->field_204) {
            if (self->field_1FA >= 0) {
                self->field_13C = func_0044B9F0_inl4(self->field_13C + dt, 1.0f);
                func_0044B9F0_inl2(self, self->field_13C);
            }
            return;
        }
        float base = 0.0f;
        float e;  // [C] only set when field_134 == 1 (retail reads f21 regardless)
        self->field_13C += dt;
        if (self->field_134 == 1) {
            e = self->field_13C - base;
            if (!(e < base) && !self->field_1FC) {
                float ph = 0.0f;
                if (e < 2.0f)
                    ph = 0.0f + e - 1.0f * (float)(int)(e / 1.0f);
                else
                    self->field_1FC = 1;
                func_0044B9F0_inl2(self, ph);
            }
            base += 2.0f;
        }
        if (self->field_1FD) {
            if (self->field_1F8 < 0) {
                float u = self->field_13C - base;
                if (u <= 1.0f) {
                    u = GtMath::Min(GtMath::Max(u, 0.0f), 1.0f);
                    float p = GtMath::Min(GtMath::Max(e, 0.0f), 1.0f);  // [C] computed, unused
                    (void)p;
                    if (!(u <= 0.0f) && u < 1.0f) {
                        for (int i = 0; i < 8; i++) {
                            if (self->field_180[i] != self->field_1A0[i])
                                func_00284390(&D_01E7A800);
                        }
                    }
                } else {
                    self->field_1F8 = 0;
                    if (e <= 1.0f) {
                        for (int i = 0; i < 8; i++) {
                            if (self->field_180[i] != self->field_1A0[i])
                                func_00284390(&D_01E7A800);
                        }
                    }
                    u = 1.0f;
                }
                for (int i = 0; i < self->field_138; i++) {
                    func_0044CF90(self, i, u);
                    func_0044B9F0_inl1(self, &self->field_C[i].field_1C, self->field_140[i], 1.0f);
                    if (self->field_134 == 1)
                        func_0044B9F0_inl1(self, &self->field_C[i].field_20, self->field_160[i], 1.0f);
                }
            }
            if (self->field_1F8 < 0)
                return;
            base += 1.0f;
        }
        base += 0.25f;
        while (base < self->field_13C) {
            func_0044CB20(self, self->field_138);
            if (self->field_1F9 < 0) {
                self->field_204 = 1;
                if (self->field_1FA >= 0)
                    self->field_13C = 0.0f;
                return;
            }
            float u = self->field_13C - base;
            bool over = !(u <= 0.25f);
            if (self->field_1FB == over) {
                self->field_1FB = !self->field_1FB;
                func_0044C960(self, self->field_1F9, self->field_1FB);
            }
            int k = self->field_1F9;
            UnkStruct_0044B9F0_row *ra = &self->field_C[k];
            UnkStruct_0044B9F0_row *rb = &self->field_C[k - 1];
            if (!over) {
                float v = GtMath::Min(GtMath::Max(u, 0.0f), 0.25f) * 4.0f;
                float d = (ra->field_8->field_0.field_0.marValues[1] - rb->field_8->field_0.field_0.marValues[1]) * v;
                if (v >= 0.5f) {
                    const unsigned short *s = func_00271A00(&D_0051BA44, k + 0x25F);
                    func_0044B9F0_inl1(self, &ra->field_10, s, 0.0f);
                    s = func_00271A00(&D_0051BA44, k + 0x260);
                    func_0044B9F0_inl1(self, &rb->field_10, s, 0.0f);
                }
                func_0044B9F0_inl3(ra, -d);
                func_0044B9F0_inl3(rb, d);
                return;
            }
            const unsigned short *s = func_00271A00(&D_0051BA44, k + 0x25F);
            func_0044B9F0_inl1(self, &ra->field_10, s, 0.0f);
            s = func_00271A00(&D_0051BA44, k + 0x260);
            func_0044B9F0_inl1(self, &rb->field_10, s, 0.0f);
            func_0044C7F0(self, k, k - 1);
            func_0044B9F0_inl3(ra, 0.0f);
            func_0044B9F0_inl3(rb, 0.0f);
            self->field_1F9 = -1;
            self->field_13C -= 0.25f;
        }
    } break;
    case 2:
    case 3:
    case 4: {
        CGtV4d c(D_01E90350);
        c.SetA(D_01E90420[0]);
        self->field_12C->mObjectSpace.mColour = c;
    } break;
    }
}
