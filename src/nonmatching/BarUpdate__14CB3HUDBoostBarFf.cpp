// NONMATCHING: BarUpdate__14CB3HUDBoostBarFf -- retail 628 / ours 628 instructions, 7 in changed runs
// pass3c: first full draft (was never archived); 7 off: retail 1.0/field_100 on f1/f2 (ours f2/f1), extra andi 0xFF after the materialised field_104>=field_110 flag, retail reloads field_104 after the join. SinCosFast via a local stand-in with int-local trig constants (VU region exact), XAxisType temp avoided (frame exact).
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Trig.h"
#include "b3/GtMath.h"
#include "b3/_unclassified/GtRandom.h"

using namespace GtMathPs2;

extern "C" int func_00131E40(void *);  // CB3Game::IsCrashMode() [E map, high]
extern "C" void func_00285A60(void *);
extern "C" void func_00285B00(void *);
extern char D_004EE040[];
extern char D_01E7A800[];

struct UnkStruct_001A4900_p {
    float field_0;
    float field_4;
    float field_8;
    float field_C;
    float field_10;
    float field_14;
    float field_18;
    float field_1C;
};
struct UnkStruct_001A4900_c {
    unsigned char pad_0[0xFC];
    int field_FC;
    float field_100;
    float field_104;
    float field_108;
    unsigned char pad_10C[0x4];
    float field_110;
    unsigned char pad_114[0xA];
    unsigned char field_11E;
};

class CB3HUDComponent {
public:
    unsigned char pad_0[0x20];
};

class CB3HUDBoostBar : public CB3HUDComponent {
public:
    void BarUpdate(float dt);
    UnkStruct_001A4900_p field_20[20];
    UnkStruct_001A4900_p field_2A0[20];
    float field_520;
    float field_524;
    float field_528;
    float field_52C;
    float field_530;
    float field_534;
    unsigned char field_538;
    unsigned char field_539;
    unsigned char field_53A;
    unsigned char pad_53B[0x1];
    float field_53C;
    float field_540;
    unsigned char pad_544[0x4];
    int field_548;
    unsigned char pad_54C[0x4];
    CGtRandom field_550;
    CGtV2d field_558;
    CGtV2d * field_560;
    unsigned char pad_564[0x7];
    unsigned char field_56B;
    unsigned char pad_56C[0x120];
    UnkStruct_001A4900_c * field_68C;
    unsigned char pad_690[0x4];
    float field_694;
    unsigned char pad_698[0x4];
    CGtV2d * field_69C;
    CGtV2d field_6A0;
    unsigned char field_6A8;
};

// CB3HUDBoostBar::BarUpdate(float) -- hand-written (pass3c) from the Ghidra draft and retail; sibling of
// UpdateTransition__14CB3HUDBoostBar (same 0x694 / 0x69C / 0x6A0 position shape). Every type and field is [G].
// Two 20-entry particle arrays (this+0x20, this+0x2A0, 0x20 bytes each); CGtRandom at 0x550 (GtRandom.h).
// [G] the bar-position block as an inline (the same shape closes UpdateTransition__14CB3HUDBoostBar): its CGtV2d local
// then sits between operator+'s two temporaries in the frame, as retail (0x68 / 0x70 / 0x78).
static inline void func_001A4900_inl1(CB3HUDBoostBar *self)
{
    CGtV2d v = self->field_6A0;
    float t = self->field_694;
    if (t < 1.0f) {
        v.SetY((150.0f + v.Y()) - 150.0f * t);
    }
    *self->field_69C = v;
}

// [L] N185 stand-in for GtMathPs2::SinCosFast(float) (GtMathPs2Trig.h, B3O0PCH map) returning the raw quad: the
// header body's per-statement noreorder regions keep the trig I-constants below vabs / the c3 vmul / vmula, where
// retail loads 0xBE22F983 / 0x3F000000 above the first vabs, 0x4B400000 after it, 0xC2255DE0 above qmfc2 c3 and
// 0x40C90FDA above vmula. [G] those constants as int locals declared where retail's scheduler lets them rise, and
// the first vabs, the y vabs and the c3 vmul outside regions (pass3c). The CGtV4d return + .X() + operator*(XAxisType,
// float) add an XAxisType temp slot retail lacks (frame 0x90 vs 0x80), hence u_long128 and inl3.
static inline u_long128 func_001A4900_inl2(float a)
{
    CGtV4d v;
    u_long128 w;
    u_long128 x, one, f, y, t, t2, t4, t8, c1, c3, ca, cb, cc, r;
    asm("qmtc2.ni %1, $vf1\n\tvaddx.x %0, $vf0, $vf1x" : "+j"(v.mData) : "r"(a));
    asm("vaddx.y %0, $vf0, %0x" : "+j"(v.mData));
    asm(".set noreorder");
    asm("ctc2 %0, $vi21\n\tvnop" : : "r"(0x3FC90FDB));
    asm(".set reorder");
    asm(".set noreorder");
    asm("vsubi.xz %0, %1, $I" : "=j"(w) : "j"(v.mData));
    asm(".set reorder");
    int k3 = 0x3F000000;
    int k1 = 0xBE22F983;
    asm("vabs.xyzw %0, %1" : "=j"(x) : "j"(w));
    int k2 = 0x4B400000;
    asm(".set noreorder");
    asm("vmaxw.xyzw %0, $vf0, $vf0w" : "=j"(one));
    asm(".set reorder");
    asm(".set noreorder");
    asm("ctc2 %0, $vi21\n\tvnop" : : "r"(k1));
    asm(".set reorder");
    asm(".set noreorder");
    asm("vmulai.xyzw $ACC, %0, $I" : : "j"(x));
    asm(".set reorder");
    asm(".set noreorder");
    asm("nop\n\tctc2 %0, $vi21\n\tvnop" : : "r"(k2));
    asm(".set reorder");
    asm(".set noreorder");
    asm("vmsubai.xyzw $ACC, %0, $I\n\tvmaddai.xyzw $ACC, %0, $I" : : "j"(one));
    asm(".set reorder");
    asm(".set noreorder");
    asm("nop\n\tctc2 %0, $vi21\n\tvnop" : : "r"(k1));
    asm(".set reorder");
    asm(".set noreorder");
    asm("vmsubai.xyzw $ACC, %0, $I" : : "j"(x));
    asm(".set reorder");
    asm(".set noreorder");
    asm("nop\n\tctc2 %0, $vi21\n\tvnop" : : "r"(k3));
    asm(".set reorder");
    asm(".set noreorder");
    asm("vmsubi.xyzw %0, %1, $I" : "=j"(f) : "j"(one));
    asm(".set reorder");
    asm("vabs.xyzw %0, %1" : "=j"(y) : "j"(f));
    asm(".set noreorder");
    asm("ctc2 %0, $vi21\n\tvnop" : : "r"(0x3E800000));
    asm(".set reorder");
    asm(".set noreorder");
    asm("vsubi.xyzw %0, %1, $I" : "=j"(t) : "j"(y));
    asm(".set reorder");
    asm("vmul.xyzw %0, %1, %1" : "=j"(t2) : "j"(t));
    asm("vmul.xyzw %0, %1, %1" : "=j"(t4) : "j"(t2));
    asm("vmul.xyzw %0, %1, %1" : "=j"(t8) : "j"(t4));
    asm(".set noreorder");
    asm("ctc2 %0, $vi21\n\tvnop" : : "r"(0xC2992661));
    asm(".set reorder");
    asm(".set noreorder");
    asm("vmuli.xyzw %0, %1, $I" : "=j"(c1) : "j"(t));
    asm(".set reorder");
    asm("vmul.xyzw %0, %1, %2" : "=j"(c3) : "j"(c1), "j"(t2));
    asm(".set noreorder");
    asm("ctc2 %0, $vi21\n\tvnop" : : "r"(0xC2255DE0));
    asm(".set reorder");
    asm(".set noreorder");
    asm("vmuli.xyzw %0, %1, $I" : "=j"(ca) : "j"(t));
    asm(".set reorder");
    asm(".set noreorder");
    asm("nop\n\tctc2 %0, $vi21\n\tvnop" : : "r"(0x42A33457));
    asm(".set reorder");
    asm(".set noreorder");
    asm("vmuli.xyzw %0, %1, $I" : "=j"(cb) : "j"(t));
    asm(".set reorder");
    asm(".set noreorder");
    asm("nop\n\tctc2 %0, $vi21\n\tvnop" : : "r"(0x421ED7B7));
    asm(".set reorder");
    asm(".set noreorder");
    asm("vmuli.xyzw %0, %1, $I" : "=j"(cc) : "j"(t));
    asm(".set reorder");
    int k4 = 0x40C90FDA;
    asm("vmula.xyzw $ACC, %0, %1" : : "j"(ca), "j"(t2));
    asm("vmadda.xyzw $ACC, %0, %1" : : "j"(c3), "j"(t4));
    asm(".set noreorder");
    asm("ctc2 %0, $vi21" : : "r"(k4));
    asm(".set reorder");
    asm(".set noreorder");
    asm("vmadda.xyzw $ACC, %0, %1" : : "j"(cb), "j"(t4));
    asm(".set reorder");
    asm(".set noreorder");
    asm("vmaddai.xyzw $ACC, %0, $I" : : "j"(t));
    asm(".set reorder");
    asm(".set noreorder");
    asm("vmadd.xyzw %0, %1, %2" : "=j"(r) : "j"(cc), "j"(t8));
    asm(".set reorder");
    return r;
}

// [L] N185 stand-in for `XAxisType * float` read as a float (operator*(XAxisType, float) + operator float, header bodies):
// same instructions, no class temporaries.
static inline float func_001A4900_inl3(u_long128 a, float f)
{
    u_long128 s, r;
    float x;
    asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f));
    asm("vmulx.x %0, %1, %2x" : "=j"(r) : "j"(a), "j"(s));
    asm("mtc1 %1, %0" : "=f"(x) : "r"(r));
    return x;
}

// [G] a materialised `field_104 >= field_110` test (retail: li 1; c.lt; move 0; bnez): an inline returning from each
// arm puts the pointer in a0 and the flag in v1 as retail; retail also reloads field_104 after the join (open).
static inline int func_001A4900_inl4(UnkStruct_001A4900_c *p)
{
    if (p->field_104 >= p->field_110) {
        return 1;
    }
    return 0;
}

// 0x001A4900
void CB3HUDBoostBar::BarUpdate(float dt)
{
    bool fast = false;
    float inv = 1.0f / field_68C->field_100;
    float wob = 0.0f;
    field_520 += dt;
    field_539 = field_550.Random();
    int n = field_68C->field_FC + 1;
    if (field_56B == 0) {
        field_56B = n;
    }
    if (field_694 >= 0.0f) {
        field_694 += dt;
        func_001A4900_inl1(this);
    }
    float a;
    float b;
    float lvl = 0.25f * (float)n;
    field_524 = lvl;
    if (n != field_56B) {
        field_534 = -0.5f;
        if (n < field_56B) {
            field_53A = 1;
            b = 0.416666657f;
            a = 0.5f;
            for (int i = 0; i < 20; i++) {
                UnkStruct_001A4900_p &p = field_2A0[i];
                p.field_10 = a;
                p.field_0 = lvl;
                p.field_4 = 0.5f;
                float c = -0.642857134f * p.field_4;
                p.field_8 = b;
                p.field_C = c;
                p.field_14 = -15.7079639f * (2.3283064e-10f * (float)field_550.Random());
                p.field_18 = 1.0f - 0.025f * (float)i;
                p.field_1C = 1.0f;
                a += 0.0495f;
                b += -0.0119444439f;
            }
        } else {
            field_53A = 2;
        }
    }
    field_56B = n;
    if (field_6A8 != 0 || field_694 > 1.0f) {
        float old = field_534;
        field_534 = old + dt;
        switch (field_53A) {
        case 0:
            break;
        case 1:
            if (old <= 0.0f && field_534 > 0.0f) {
                func_00285A60(D_01E7A800);
            }
            break;
        case 2:
            if (field_534 > 0.3f) {
                if (old <= 0.3f) {
                    func_00285B00(D_01E7A800);
                }
                float c = field_534;
                if (c < 0.7f) {
                    float s = c - 0.3f;
                    float amp = 50.0f - 125.0f * s;
                    u_long128 sc = func_001A4900_inl2(62.8318558f * s);
                    wob = func_001A4900_inl3(sc, amp);
                }
            }
            break;
        }
    }
    if (func_00131E40(D_004EE040)) {
        field_538 = 0;
    } else {
        field_538 = n;
    }
    int full = func_001A4900_inl4(field_68C);
    if (full || field_68C->field_11E != 0) {
        float target = field_524 * (inv * field_68C->field_104);
        if (target > field_528) {
            if (field_53A != 2 || field_534 > 1.2f) {
                if (target - field_528 > 0.025f) {
                    fast = true;
                }
                field_528 += 0.625f * dt;
                if (field_528 > target) {
                    field_528 = target;
                }
            }
        } else {
            field_528 = target;
        }
    } else {
        field_528 = 0.0f;
    }
    if (field_68C->field_11E != 0 || fast) {
        float c = field_530 + 5.0f * dt;
        field_530 = c;
        if (c > 1.0f) {
            field_530 = 1.0f;
        }
        float d = field_540 + 16.0f * dt;
        field_540 = d;
        while (field_540 >= 1.0f) {
            UnkStruct_001A4900_p &q = field_20[field_548];
            q.field_10 = field_520;
            unsigned int r1 = field_550.Random();
            q.field_0 = GtMath::Max(field_528 - 0.05f, 0.0f);
            q.field_4 = 0.5f * (2.3283064e-10f * (float)r1);
            float c2 = -0.642857134f * q.field_4;
            q.field_8 = 0.0902777761f + 0.118055552f * (2.3283064e-10f * (float)field_550.Random());
            q.field_C = c2;
            q.field_14 = -31.4159279f * (2.3283064e-10f * (float)field_550.Random());
            q.field_18 = 1.0f;
            q.field_1C = 1.0f;
            field_548++;
            if (field_548 == 20) {
                field_548 = 0;
            }
            field_540 -= 1.0f;
        }
    } else {
        *field_560 = field_558;
        float c = field_530 - 2.0f * dt;
        field_530 = c;
        if (c < 0.0f) {
            field_530 = 0.0f;
        }
    }
    if (fast || field_68C->field_108 > field_53C) {
        float c = field_52C + 3.0f * dt;
        field_52C = c;
        if (c > 1.0f) {
            field_52C = 1.0f;
        }
    } else {
        float c = field_52C - 0.75f * dt;
        field_52C = c;
        if (c < 0.0f) {
            field_52C = 0.0f;
        }
    }
    field_53C = field_68C->field_108;
    *field_560 = field_558 + CGtV2d(wob, 0.0f);
}

