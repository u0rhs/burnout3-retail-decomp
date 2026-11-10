// NONMATCHING: Update__31CB3ConnectionAnimationComponentFf -- retail 249 / ours 249 instructions, 45 in changed runs
// ghvu14: logic + jtbl shape right (pmaxw/pextlw helpers, Interpolate stand-in with own mfc1 statement fixes the t move); 45 off: frame 0xA0 vs 0x1E0 (20 dead slots missing; case-0 zero temps land at 0x00/0x10 not 0x70/0x80), the ==6 loop's CGtV4d(0,0,0,0) is hoisted out of the loop by b119 (retail builds it each pass; no pragma/volatile/form stops it), t2/t3 swap state pointer vs element base
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// CB3ConnectionAnimationComponent::Update(float) -- hand-written (ghvu14, Ghidra draft + retail asm).
// [C] name: the mangled symbol in retail's tables; Area not evidenced, so _unclassified/ (docs/conventions.md).
// Layout as the proven Construct (B3ConnectionAnimationComponent_00352990.cpp: states 0x50.., seven colours 0x70..0xD0,
// timer 0xE0); 0x10 / 0x30 are four pairs of 2d-object pointers whose colour sits at +0x10 [G]. Field names are
// placeholders and every type is [G]. ghvu14: every 0.2 s each of the four lamps steps its state (clamped >= 0 by
// pmaxw/pextlw, [L] a129 helpers) and copies the state's colour; in between, state-1 lamps (and all lamps in states 5/6)
// blend towards the next colour (header Interpolate(CGtV4d)).

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

struct UnkStruct_003525A0_obj { unsigned char pad_0[0x10]; CGtV4d field_10; };
struct UnkStruct_003525A0_pair { UnkStruct_003525A0_obj * field_0; UnkStruct_003525A0_obj * field_4; };
struct UnkStruct_D_01E90424 { int value; unsigned char pad[0x100]; };
extern UnkStruct_D_01E90424 D_01E90424;
struct UnkStruct_D_004F509C { float field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_004F509C D_004F509C;

class CB3ConnectionAnimationComponent {
public:
    void Update(float);

    unsigned char pad_0[0x10];
    UnkStruct_003525A0_pair field_10[4];
    UnkStruct_003525A0_pair field_30[4];
    int field_50[4];
    int field_60[4];
    CGtV4d field_70[7];
    float field_E0;
};

static inline int func_003525A0_inl1(int a, int b) { int r; asm("pmaxw %0, %1, %2" : "=r"(r) : "r"(a), "r"(b)); return r; }
static inline unsigned int func_003525A0_inl2(int a) { unsigned int r; asm("pextlw %0, $0, %1" : "=r"(r) : "r"(a)); return r; }

// [L] N185: the header's Interpolate(CGtV4d) body with t moved to a GPR by its own `mfc1` statement first (v296: retail
// schedules that move ahead of the ACC chain; the header's "r"(t) operand puts it after vaddax plus a hazard nop, v301 open).
static inline CGtV4d func_003525A0_inl3(CGtV4d a, CGtV4d b, float t)
{
    u_long128 tv, r;
    int ti;
    asm("mfc1 %0, %1" : "=r"(ti) : "f"(t));
    asm("vaddax.xyzw $ACC, %1, $vf0x" "\n\t" "qmtc2.ni %2, %0" "\n\t" "vmsubax.xyzw $ACC, %1, %0x" : "=&j"(tv) : "j"(a.mData), "r"(ti));
    asm(".set noreorder");
    asm("qmtc2.i %1, $vf1" "\n\t" "vmaddx.xyzw $vf1, $vf1, %2x" "\n\t" "qmfc2.i %0, $vf1" : "=r"(r) : "r"(b.mData), "j"(tv));
    asm(".set reorder");
    return CGtV4d(r);
}

// 0x003525A0
void CB3ConnectionAnimationComponent::Update(float)
{
    int i;
    if (D_01E90424.value != 5) return;
    field_E0 += D_004F509C.field_0;
    if (field_E0 > 0.2f) {
        for (i = 0; i < 4; i++) {
            field_50[i]++;
            int *p = &field_50[i];
            if (field_50[0] == 5) {
                field_50[1] = 5;
                field_50[2] = 5;
                field_50[3] = 5;
            }
            if (*p == 7) *p = field_60[i];
            unsigned int s = func_003525A0_inl2(func_003525A0_inl1(0, *p));
            switch (s) {
            case 0:
                field_10[i].field_0->field_10 = field_70[s];
                field_10[i].field_4->field_10 = field_70[s];
                field_30[i].field_0->field_10 = CGtV4d(0.0f, 0.0f, 0.0f, 0.0f);
                field_30[i].field_4->field_10 = CGtV4d(0.0f, 0.0f, 0.0f, 0.0f);
                break;
            case 1:
                field_10[i].field_0->field_10 = field_70[s];
                field_10[i].field_4->field_10 = field_70[s];
                break;
            case 2:
                field_10[i].field_0->field_10 = field_70[s];
                field_10[i].field_4->field_10 = field_70[s];
                break;
            case 3:
                field_10[i].field_0->field_10 = field_70[s];
                field_10[i].field_4->field_10 = field_70[s];
                break;
            case 4:
                field_10[i].field_0->field_10 = field_70[s];
                field_10[i].field_4->field_10 = field_70[s];
                break;
            case 5:
                field_10[i].field_0->field_10 = field_70[0];
                field_10[i].field_4->field_10 = field_70[0];
                field_30[i].field_0->field_10 = field_70[5];
                field_30[i].field_4->field_10 = field_70[5];
                break;
            case 6:
                field_30[i].field_0->field_10 = field_70[6];
                field_30[i].field_4->field_10 = field_70[6];
                break;
            }
        }
        field_E0 = 0.0f;
    } else {
        for (i = 0; i < 4; i++) {
            if (field_50[i] == 1) {
                float t = field_E0 / 0.2f;
                CGtV4d c = func_003525A0_inl3(field_70[field_50[i]], field_70[field_50[i] + 1], t);
                field_10[i].field_0->field_10 = c;
                field_10[i].field_4->field_10 = c;
            }
        }
        if (field_50[0] == 5) {
            for (i = 0; i < 4; i++) {
                float t = field_E0 / 0.2f;
                CGtV4d c = func_003525A0_inl3(field_70[field_50[i]], field_70[field_50[i] + 1], t);
                field_30[i].field_0->field_10 = c;
                field_30[i].field_4->field_10 = c;
            }
        } else if (field_50[0] == 6) {
            for (i = 0; i < 4; i++) {
                CGtV4d z(0.0f, 0.0f, 0.0f, 0.0f);
                float t = field_E0 / 0.2f;
                CGtV4d c = func_003525A0_inl3(field_70[field_50[i]], z, t);
                field_30[i].field_0->field_10 = c;
                field_30[i].field_4->field_10 = c;
            }
        }
    }
}
