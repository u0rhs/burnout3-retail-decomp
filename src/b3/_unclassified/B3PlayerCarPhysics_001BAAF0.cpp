// CB3PlayerCarPhysics::DoCrashBreaker() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3PlayerCarPhysics.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (mwperm: +'up.v.x = 0.0f;'; 'up.v.x = 0.0f;' -> '').

typedef unsigned long u_long128 __attribute__((mode(TI)));
struct UnkStruct_D_004EE040 {
    unsigned char pad_0[0x28E00];
};
class UnkStruct_DCB_row {
public:
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14(int, int);
};
struct UnkStruct_D_00522680 {
    float field_0;
    unsigned char pad_4[0xC];
};
struct UnkStruct_D_01E32AE0 {
    unsigned char pad_0[0x10];
};
struct UnkStruct_D_01E32B08 {
    int field_0;
    unsigned char pad_4[0xC];
};
struct UnkStruct_D_0064D336 {
    unsigned char field_0[0x10];
};
struct UnkStruct_DCB_v {
    float x;
    float y;
    float z;
    float w;
};
union UnkStruct_DCB_q {
    u_long128 q;
    UnkStruct_DCB_v v;
};
struct UnkStruct_DCB_pl {
    unsigned char pad_0[0x4F09];
    unsigned char field_4F09;
    unsigned char pad_4F0A[6];
    int field_4F10;
};
struct UnkStruct_DCB_x {
    unsigned char pad_0[0x19AC];
    signed char field_19AC;
    unsigned char pad_19AD[0xE13];
    int field_27C0;
};
struct UnkStruct_DCB_sc {
    unsigned char pad_0[0x10];
};
struct UnkStruct_DCB_c {
    unsigned char pad_0[0x11E4];
    UnkStruct_DCB_sc field_11E4;
};
extern UnkStruct_D_004EE040 D_004EE040;
extern UnkStruct_D_00522680 D_00522680;
extern UnkStruct_D_01E32AE0 D_01E32AE0;
extern UnkStruct_D_01E32B08 D_01E32B08;
extern UnkStruct_D_0064D336 D_0064D336;
extern int D_004E2710;
extern int D_004E2714;
extern "C" bool func_00131CA0(void *);
extern "C" void FireAirRamWithDirection__17CB3VehiclePhysicsFUifQ29GtMathPs26CGtV3db(void *, int, void *, int, float);
extern "C" void func_001CC4C0(void *, int, int, float);
extern "C" UnkStruct_DCB_pl * func_002366D0(void *, int);
extern "C" void func_001BE990(void *, bool);
extern "C" int OnEvent__13CB3ScoreBonusF16EScoreBonusEventiib(void *, int, int, int, bool);

class CB3PlayerCarPhysics {
public:
    void DoCrashBreaker(bool p0);
    unsigned char pad_0[0x13F4];
    UnkStruct_DCB_c * field_13F4;
    unsigned char pad_13F8[0x188];
    UnkStruct_DCB_x * field_1580;
};

// 0x001BAAF0
extern "C" void DoCrashBreaker__19CB3PlayerCarPhysicsFv(CB3PlayerCarPhysics * self, bool p0)
{
    bool v1 = p0;
    bool v0 = v1;
    int row;
    float t1;
    UnkStruct_DCB_x * x;
    float f;
    if (func_00131CA0(&D_004EE040)) f = 1.0f;
    else f = 0.75f;
    UnkStruct_DCB_q cp;
    x = self->field_1580;
    UnkStruct_DCB_q up;
    up.v.y = 1.0f;
    up.v.x = 0.0f;
    up.v.z = 0.0f;
    row = x->field_27C0;
    int idx = x->field_19AC;
    float t2 = f * 2.0f;
    cp.q = up.q;
    FireAirRamWithDirection__17CB3VehiclePhysicsFUifQ29GtMathPs26CGtV3db(self, 0x10, &cp, 1, t2);
    float t3 = D_00522680.field_0;
    t1 = t3;
    int n = (int)(300.0f * D_00522680.field_0);
    int fl;
    int t = ~n;
    int t8 = (t << 16) + (t >> 16);
    int a = (t8 + n);
    D_004E2714 = n + a;
    D_004E2710 = a;
    const int sel = 3 & a;
    if (sel & 1) fl = 1; else fl = 2;
    if (sel & 2) fl |= 4; else fl |= 8;
    char * t6 = (char *)&D_004EE040 + row * 0xBB0 + 0x28E00;
    UnkStruct_DCB_row * t4 = (UnkStruct_DCB_row *)(t6);
    func_001CC4C0(self, fl, 1, f);
    (t4)->vfunc_14(6, 0);
    int i = 0;
    goto loop0_t;
loop0:
    UnkStruct_DCB_pl * pl = func_002366D0(&D_01E32AE0, i);
    if (pl) {
        pl->field_4F10 = 5;
        pl->field_4F09 = 1;
    }
    i++;
loop0_t:
    if (i < D_01E32B08.field_0) goto loop0;
    func_001BE990(self, v0);
    OnEvent__13CB3ScoreBonusF16EScoreBonusEventiib(&self->field_13F4->field_11E4, 0, 0, -1, true);
    if (!p0) {
        *((unsigned char *)&D_0064D336 + idx) = 1;
    }
}
