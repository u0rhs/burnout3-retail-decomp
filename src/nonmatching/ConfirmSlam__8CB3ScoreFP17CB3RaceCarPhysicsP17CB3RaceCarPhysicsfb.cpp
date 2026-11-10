// NONMATCHING: ConfirmSlam__8CB3ScoreFP17CB3RaceCarPhysicsP17CB3RaceCarPhysicsfb -- retail 148 / ours 148 instructions, 5 in changed runs
// near35: whole function in goto form (helper's 0-stubs and return-false stubs as labels after 'return true', retail block order) + scoped opt_repositioncode off [G] + per-arm (idx+r)[0x4EFD]/[0x4F03] address (retail repeats addu in each p3 arm). 148/148. Left 5: a (p0->field_13F4) / t (field_1914) a0<->v1 swap after OnSlam -- same open swap as OnTradePaint/ConfirmTradePaint; decl/def order, const, no-local CSE form, OnSlam bool return tried
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// NONMATCHING: ConfirmSlam__8CB3ScoreFP17CB3RaceCarPhysicsP17CB3RaceCarPhysicsfb -- retail 148 / ours 145 instructions, 70 in changed runs
// a231: c0,s0,c1,s1 decl order (c0;s0;c1;s1) fixes a1/a2/a3 regs; A-arm return true; left: t==2 arm out of line in ours (retail inline, bne t,2), add.s operand order (field+1.0 -> f2,f1), 4 b/daddu stubs
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// NONMATCHING: ConfirmSlam__8CB3ScoreFP17CB3RaceCarPhysicsP17CB3RaceCarPhysicsfb -- retail 148 / ours 146 instructions, 80 in changed runs
// a92: 146 vs 148 instrs, 80 in changed runs; static, logic right (inline 'other car' helper x2, A/B slam loops); left: retail routes the helper's 0 results through separate 'b join; daddu v1,zero' stubs (4 of them) + 3 more instrs, car1 lands in a1 not a2, 'then' of t==2 is inline in retail but out of line in ours, add.s operand order (5F0 + 1.0)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

class CB3RaceCar;
class CB3RaceCarPhysics;
struct UnkStruct_D_01E32AE0 {
    unsigned char pad_0[0x10];
};
struct UnkStruct_D_01E32B08 {
    int field_0;
    unsigned char pad_4[0xC];
};
class CB3Score {
public:
    static bool ConfirmSlam(CB3RaceCarPhysics * p0, CB3RaceCarPhysics * p1, float p2, bool p3);
    static void OnSlam(CB3RaceCarPhysics * p0, CB3RaceCarPhysics * p1, float p2, bool p3);
    unsigned char pad_0[0xC];
    float field_C;
    unsigned char pad_10[0x26C];
    int field_27C;
    unsigned char pad_280[0x36C];
    CB3RaceCar * field_5EC;
    float field_5F0;
};
class CB3RaceCar {
public:
    unsigned char pad_0[0x10C0];
    CB3Score field_10C0;
    unsigned char pad_16B4[0x260];
    int field_1914;
    unsigned char pad_1918[0x94];
    signed char field_19AC;
};
class CB3RaceCarPhysics {
public:
    unsigned char pad_0[0x13F4];
    CB3RaceCar * field_13F4;
};
extern UnkStruct_D_01E32AE0 D_01E32AE0;
extern UnkStruct_D_01E32B08 D_01E32B08;
extern "C" int func_002366D0(void *, int);

static inline CB3RaceCar * func_00156BD0_inl1(CB3Score * s)
{
    float one = 1.0f;
    if (s->field_5F0 == -1.0f) {
        return 0;
    }
    if (s->field_5F0 + one < s->field_C) {
        return 0;
    }
    return s->field_5EC;
}

// N182: [G] scoped to this function
#pragma push
#pragma opt_repositioncode off
// 0x00156BD0
bool CB3Score::ConfirmSlam(CB3RaceCarPhysics * p0, CB3RaceCarPhysics * p1, float p2, bool p3)
{
    CB3RaceCar * c0 = p0->field_13F4;
    CB3Score * s0 = &c0->field_10C0;
    CB3RaceCar * c1 = p1->field_13F4;
    CB3Score * s1 = &c1->field_10C0;
    CB3RaceCar * x0;
    CB3RaceCar * x1;
    float one;
    if (*(int *)((char *)c0 + 0x133C) == 3) goto rf1;
    if (s1->field_27C == 3) goto rf1;
    one = 1.0f;
    if (s0->field_5F0 == -1.0f) goto z0a;
    if (s0->field_5F0 + one < s0->field_C) goto z0b;
    x0 = s0->field_5EC;
j0:
    one = 1.0f;
    if (s1->field_5F0 == -1.0f) goto z1a;
    if (s1->field_5F0 + one < s1->field_C) goto z1b;
    x1 = s1->field_5EC;
j1:
    if (x1 == c0) goto rf2;
    if (x0 == c1) goto rf3;
    OnSlam(p0, p1, p2, p3);
    CB3RaceCar * a = p0->field_13F4;
    int t = a->field_1914;
    if (t == 2 && p1->field_13F4->field_1914 == 0) {
        int idx = a->field_19AC;
        for (int i = 0; i < D_01E32B08.field_0; i++) {
            int r = func_002366D0(&D_01E32AE0, i);
            if (r != 0) {
                if (p3) {
                    ((unsigned char *)(idx + r))[0x4EFD] |= 4;
                } else {
                    ((unsigned char *)(idx + r))[0x4EFD] |= 2;
                }
            }
        }
    } else if (t == 0) {
        CB3RaceCar * b = p1->field_13F4;
        if (b->field_1914 == 2) {
            int idx = b->field_19AC;
            for (int i = 0; i < D_01E32B08.field_0; i++) {
                int r = func_002366D0(&D_01E32AE0, i);
                if (r != 0) {
                    if (p3) {
                        ((unsigned char *)(idx + r))[0x4F03] |= 4;
                    } else {
                        ((unsigned char *)(idx + r))[0x4F03] |= 2;
                    }
                }
            }
        }
    }
    return true;
rf1:
    return false;
z0a:
    x0 = 0;
    goto j0;
z0b:
    x0 = 0;
    goto j0;
z1a:
    x1 = 0;
    goto j1;
z1b:
    x1 = 0;
    goto j1;
rf2:
    return false;
rf3:
    return false;
}
#pragma pop
