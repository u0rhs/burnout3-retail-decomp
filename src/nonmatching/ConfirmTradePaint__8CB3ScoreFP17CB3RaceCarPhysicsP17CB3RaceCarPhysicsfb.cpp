// NONMATCHING: ConfirmTradePaint__8CB3ScoreFP17CB3RaceCarPhysicsP17CB3RaceCarPhysicsfb -- retail 193 / ours 193 instructions, 5 in changed runs
// near35: whole function in goto form in retail block order (prev/recent helpers hand-inlined, their 0-stubs and the x==c0 recheck out of line as labels after 'return true') + scoped opt_repositioncode off [G]; 'one' float local for every 1.0f add; per-arm (idx+r)[off] address. 193/193 (was 68 changed). Left 5: a (p0->field_13F4) v1 / ty (field_1914) a0 swap after OnTradePaint -- same open swap as ConfirmSlam/OnTradePaint; decl/def order, refs, reassign, CSE form, inline accessor/mark tried
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// NONMATCHING: ConfirmTradePaint__8CB3ScoreFP17CB3RaceCarPhysicsP17CB3RaceCarPhysicsfb -- retail 193 / ours 197 instructions, 68 in changed runs
// a137: first 0x128 bytes EXACT (inline recent() with bool local if/else diamond + float one=1.0f local; merged ||). Left: tail after OnTradePaint — retail lays the (t==2 && p1.1914==0) mark-loop inline after 'bne t,2' with the t==0 arm out of line; ours puts that loop out of line (beq t,2) and gets a=a0/t=v1 swapped (retail a=v1,t=a0). 6 layouts tried
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
    static bool ConfirmTradePaint(CB3RaceCarPhysics * p0, CB3RaceCarPhysics * p1, float p2, bool p3);
    static void OnTradePaint(CB3RaceCarPhysics * p0, CB3RaceCarPhysics * p1, float p2, bool p3);
    unsigned char pad_0[0xC];
    float field_C;
    unsigned char pad_10[0xB8];
    CB3RaceCar * field_C8;
    unsigned char pad_CC[0x1B0];
    int field_27C;
    unsigned char pad_280[0x36C];
    CB3RaceCar * field_5EC;
    float field_5F0;
};
class CB3RaceCar {
public:
    unsigned char pad_0[0x10C0];
    CB3Score field_10C0;
};
class CB3RaceCarPhysics {
public:
    unsigned char pad_0[0x13F4];
    CB3RaceCar * field_13F4;
};
extern UnkStruct_D_01E32AE0 D_01E32AE0;
extern UnkStruct_D_01E32B08 D_01E32B08;
extern "C" int func_002366D0(void *, int);

#define CAR_F(c, o) (*(float *)((char *)(c) + (o)))
#define CAR_I(c, o) (*(int *)((char *)(c) + (o)))
// N182: [G] scoped to this function
#pragma push
#pragma opt_repositioncode off
// 0x001568C0 -- goto form in retail's block order (the inlined prev/recent helpers' stubs are out of line)
bool CB3Score::ConfirmTradePaint(CB3RaceCarPhysics * p0, CB3RaceCarPhysics * p1, float p2, bool p3)
{
    CB3RaceCar * c0 = p0->field_13F4;
    CB3RaceCar * c1 = p1->field_13F4;
    CB3Score * s0 = &c0->field_10C0;
    CB3Score * s1 = &c1->field_10C0;
    CB3RaceCar * x;
    float t;
    bool v;
    float one;
    if (CAR_I(c0, 0x133C) == 3) goto rf1;
    if (s1->field_27C == 3) goto rf1;
    if (s1->field_5F0 == -1.0f) goto xz1;
    one = 1.0f;
    if (s1->field_5F0 + one < s1->field_C) goto xz2;
    x = s1->field_5EC;
xj:
    if (x == c0) goto chk;
cont:
    one = 1.0f;
    t = CAR_F(s0->field_C8, 0x157C);
    if (t < 0.0f) goto vz3;
    if (CAR_F(s0->field_C8, 0x10CC) <= t + one) goto rt3;
    v = false;
    goto rj3;
rt3:
    v = true;
rj3:
    if (v) goto rf4;
    one = 1.0f;
    t = CAR_F(s1->field_C8, 0x1588);
    if (t < 0.0f) goto vz4;
    if (CAR_F(s1->field_C8, 0x10CC) <= t + one) goto rt4;
    v = false;
    goto rj4;
rt4:
    v = true;
rj4:
    if (v) goto rf4;
    OnTradePaint(p0, p1, p2, p3);
    {
    CB3RaceCar * a = p0->field_13F4;
    int ty = CAR_I(a, 0x1914);
    if (ty == 2 && CAR_I(p1->field_13F4, 0x1914) == 0) {
    {
        int idx = *((signed char *)a + 0x19AC);
        for (int i = 0; i < D_01E32B08.field_0; i++) {
            int r = func_002366D0(&D_01E32AE0, i);
            if (r != 0) {
                ((unsigned char *)(idx + r))[0x4EFD] |= 8;
            }
        }
    }
    } else if (ty == 0) {
        CB3RaceCar * b = p1->field_13F4;
        if (CAR_I(b, 0x1914) == 2) {
    {
        int idx = *((signed char *)b + 0x19AC);
        for (int i = 0; i < D_01E32B08.field_0; i++) {
            int r = func_002366D0(&D_01E32AE0, i);
            if (r != 0) {
                ((unsigned char *)(idx + r))[0x4F03] |= 8;
            }
        }
    }
        }
    }
    }
    return true;
rf1:
    return false;
xz1:
    x = 0;
    goto xj;
xz2:
    x = 0;
    goto xj;
chk:
    one = 1.0f;
    t = CAR_F(s0->field_C8, 0x1680);
    if (t < 0.0f) goto vz1;
    if (CAR_F(s0->field_C8, 0x10CC) <= t + one) goto rt1;
    v = false;
    goto rj1;
rt1:
    v = true;
rj1:
    if (v) goto rf2;
    one = 1.0f;
    t = CAR_F(s1->field_C8, 0x1680);
    if (t < 0.0f) goto vz2;
    if (CAR_F(s1->field_C8, 0x10CC) <= t + one) goto rt2;
    v = false;
    goto rj2;
rt2:
    v = true;
rj2:
    if (!v) goto cont;
rf2:
    return false;
vz1:
    v = false;
    goto rj1;
vz2:
    v = false;
    goto rj2;
vz3:
    v = false;
    goto rj3;
vz4:
    v = false;
    goto rj4;
rf4:
    return false;
}
#pragma pop
