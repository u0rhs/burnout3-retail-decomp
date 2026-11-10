// CB3RaceCar::Update() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3RaceCar.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (near26: bool b with if/else (daddiu), bool e = true declared before the segment-flag test, the flag byte read through the e2-row view (as the field_18C0 read), field_18E8 clear as an out-of-line goto block).

// logic complete; open: retail parks every '== 0'/null-test then-block (field_1998 reset, !UpdateCurrentAILaneSegment -> field_18F4++, lane == 0 block, field_18E8 = 0) out of line, ours keeps them inline (empty-else/!x/bool forms tried); CGtV3d::Normalise inline differs (header gap N136: retail keeps the .ni qmfc2/qmtc2 round trips). By-value CGtV3d passed by address via POD link-name decl.

// lifter variant 0
// CB3RaceCar::Update() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3RaceCar.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

#include "b3/GtMathPs2.h"

class CB3AILane;
class CB3RaceCarPhysics;

class CB3AILane;
class CB3RaceCar;
class CB3RaceCarPhysics;
struct UnkStruct_00152770_11;
struct UnkStruct_00152770_15;
struct UnkStruct_00152770_1;
struct UnkStruct_00152770_4;
struct UnkStruct_00152770_6;
struct UnkStruct_00152770_9;
struct UnkStruct_00152770_e0;
struct UnkStruct_00152770_e1;
struct UnkStruct_00152770_e2;
struct UnkStruct_D_004F50C0;
struct UnkStruct_D_0055E948;
struct UnkStruct_D_0055EFEC;
struct UnkStruct_D_0064D358;
struct UnkStruct_D_0064D368;
struct UnkStruct_D_0064D378;

struct UnkStruct_00152770_v3 {
    u_long128 field_0;
};

class CB3AILane;
// [G] called by link name: a POD by-value vector is passed by address like retail (CGtV3d's user copy ctor forces a copy)
extern "C" bool UpdateCurrentAILaneSegment__9CB3AILaneFPP9CB3AILanePUsPScPfQ29GtMathPs26CGtV3db(CB3AILane**, unsigned short*, signed char*, float*, UnkStruct_00152770_v3, bool);

class CB3AILane {
public:
    void GetAvgForwardsVector(unsigned short, GtMathPs2::CGtV3d*) const;

    unsigned char pad_0[0x4];
    UnkStruct_00152770_9 * field_4;
};

class CB3RaceCarPhysics {
public:
    void ResetOnTrack(bool, CB3RaceCarPhysics*);

    unsigned char pad_0[0x160];
    GtMathPs2::CGtV3d field_160;
    GtMathPs2::CGtV3d field_170;
    unsigned char pad_180[0x10];
    short field_190;
    unsigned char pad_192[0x2];
    int field_194;
    int field_198;
    unsigned char pad_19C[0x76];
    unsigned char field_212;
    unsigned char pad_213[0x5];
    signed char field_218;
    unsigned char pad_219[0x113A];
    unsigned char field_1353;
};

struct UnkStruct_00152770_1 {
    int field_0;
};

struct UnkStruct_00152770_e0 {
    CB3RaceCarPhysics * field_0;
    unsigned char pad_4[0x2C];
};

struct UnkStruct_D_0055EFEC {
    UnkStruct_00152770_e0 field_0[1];  // [G] element count unknown
};

struct UnkStruct_00152770_4 {
    unsigned char pad_0[0x160];
    GtMathPs2::CGtV3d field_160;
    GtMathPs2::CGtV3d field_170;
    unsigned char pad_180[0x10];
    short field_190;
    unsigned char pad_192[0x2];
    int field_194;
    int field_198;
    unsigned char pad_19C[0x76];
    unsigned char field_212;
    unsigned char pad_213[0x1140];
    unsigned char field_1353;
};

struct UnkStruct_D_0064D358 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00152770_6 {
    float field_0;
    int field_4;
    unsigned short field_8;
    unsigned char pad_A[0x1];
    signed char field_B;
};

struct UnkStruct_00152770_9 {
    unsigned char pad_0[0x8];
    UnkStruct_00152770_e1 * field_8;
};

struct UnkStruct_00152770_e1 {
    unsigned char pad_0[0x3];
    unsigned char field_3;
    unsigned char pad_4[0x6];
};

struct UnkStruct_00152770_11 {
    unsigned char pad_0[0x8];
    UnkStruct_00152770_e2 * field_8;
};

struct UnkStruct_00152770_e2 {
    short field_0;
    unsigned char pad_2[0x8];
};

struct UnkStruct_D_0064D378 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0064D368 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00152770_15 {
    unsigned char pad_0[0x28];
    int field_28;
};

struct UnkStruct_D_0055E948 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004F50C0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3RaceCar {
public:
    void Update();
    void CalcRaceDistFromRaceCars();
    void UpdateLastPositions();

    unsigned char pad_0[0x20];
    u_long128 field_20;
    UnkStruct_00152770_v3 field_30;
    unsigned char pad_40[0x1088];
    int field_10C8;
    unsigned char pad_10CC[0x6BC];
    UnkStruct_00152770_1 * field_1788;
    unsigned char pad_178C[0x128];
    CB3AILane * field_18B4;
    unsigned short field_18B8;
    signed char field_18BA;
    unsigned char pad_18BB[0x1];
    float field_18BC;
    int field_18C0;
    unsigned char pad_18C4[0xC];
    GtMathPs2::CGtV3d field_18D0;
    unsigned char pad_18E0[0x8];
    unsigned char field_18E8;
    unsigned char pad_18E9[0x1];
    unsigned char field_18EA;
    unsigned char field_18EB;
    unsigned char field_18EC;
    unsigned char pad_18ED[0x2];
    unsigned char field_18EF;
    unsigned char pad_18F0[0x4];
    int field_18F4;
    unsigned char pad_18F8[0x18];
    // vptr at +0x1910: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18();
    virtual void vfunc_1C();
    virtual void vfunc_20();
    virtual void vfunc_24();
    virtual void vfunc_28(unsigned char);
    int field_1914;
    unsigned char pad_1918[0x80];
    unsigned char field_1998;
    unsigned char pad_1999[0x2];
    unsigned char field_199B;
    unsigned char pad_199C[0x10];
    signed char field_19AC;
    unsigned char field_19AD;
    unsigned char pad_19AE[0xE12];
    signed char field_27C0;
};

extern UnkStruct_D_0055EFEC D_0055EFEC;
extern UnkStruct_D_0064D358 D_0064D358;
extern UnkStruct_D_0064D378 D_0064D378;
extern UnkStruct_D_0064D368 D_0064D368;

extern UnkStruct_D_004F50C0 D_004F50C0;

extern "C" void * memset(void *, int, unsigned int);
class CB3CrashActionDirector {
public:
    void StopRaceCarCrashing(int);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};
extern CB3CrashActionDirector D_0055E948;
extern "C" void func_0022BEE0(void *, signed char, int, float);

// 0x00152770
void CB3RaceCar::Update()
{
    if (field_1788->field_0 == 0) return;
    if (field_1998 == 0) {
        CB3RaceCarPhysics * p = D_0055EFEC.field_0[field_19AC].field_0;
        p->field_1353 |= 16;
        p->field_1353 |= 8;
        p->field_1353 |= 4;
        p->field_212 = 0;
        memset(&p->field_160, 0, 0x60);
        p->field_160.Zero();
        p->field_170.Zero();
        p->field_190 = 0;
        p->field_194 = 0;
        p->field_198 = 0;
    }
    if (D_0064D358.field_0 > 0) {
    CB3AILane * lane = field_18B4;
    unsigned short seg = field_18B8;
    signed char c = field_18BA;
    float f = field_18BC;
    if (!UpdateCurrentAILaneSegment__9CB3AILaneFPP9CB3AILanePUsPScPfQ29GtMathPs26CGtV3db(&lane, &seg, &c, &f, field_30, field_1914 != 0)) {
        field_18F4++;
    }
    if (lane == 0) {
        CB3RaceCarPhysics * p = D_0055EFEC.field_0[field_19AC].field_0;
        if (field_1914 != 2) {
            if (field_18EA != 0) {
                D_0055E948.StopRaceCarCrashing(p->field_218);
            } else {
                bool b = true; if (field_19AD == 0) b = false;
                vfunc_18();
                p->ResetOnTrack(b, 0);
            }
            field_18D0.mData = field_20;
            field_18EB = 1;
        }
    } else {
        field_18B4 = lane;
        field_18B8 = seg;
        field_18BA = c;
        field_18BC = f;
        bool e = true;
        int t = ((UnkStruct_00152770_e1 *)&((UnkStruct_00152770_11 *)field_18B4->field_4)->field_8[field_18B8])->field_3 & 7;
        if (t != 1 && t != 3) e = false;
        field_18EC = e;
        field_18C0 = ((UnkStruct_00152770_11 *)field_18B4->field_4)->field_8[field_18B8].field_0;
        field_18B4->GetAvgForwardsVector(field_18B8, &field_18D0);
        field_18D0.Normalise();
    }
    if (field_10C8 != 0 && D_0064D378.field_0 != 0 && field_18C0 >= D_0064D368.field_0 - 16 && field_1998 != 0) {
        field_1998 = 0;
        vfunc_28(field_1998);
    }
    CalcRaceDistFromRaceCars();
    field_18EF = 0;
    if (field_18EA != 0 && field_1914 == 0) {
        func_0022BEE0(&D_004F50C0, field_27C0, 0xFFFF, 0.0f);
    }
    if (field_1998 == 0) goto clr;  // [G] goto: retail keeps this then-block out of line after the return
upd:
    UpdateLastPositions();
    field_18EB = 0;
    field_199B = 0;
    return;
clr:
    field_18E8 = 0;
    goto upd;
    } else {
        field_18EC = 0;
        field_18C0 = -1;
    }
}
