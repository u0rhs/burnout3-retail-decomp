// CB3PlayerCarPhysics::GetDrivingControls() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3PlayerCarPhysics.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (hand-matched; mask via int local, bool fields, padded D_00665ECC).

// CB3PlayerCarPhysics::GetDrivingControls -- hand-matched (a159). Types [G]. `int mk = ~7` keeps retail's li -8 / and mask.
#include "b3/GtMathPs2.h"
struct UnkStruct_GDP_vt {
    virtual int vfunc_8();
    virtual int vfunc_C();
    virtual int vfunc_10();
    virtual int vfunc_14();
    virtual int vfunc_18();
    virtual int vfunc_1C();
    virtual int vfunc_20();
    virtual int vfunc_24();
    virtual int vfunc_28();
    virtual int vfunc_2C();
    virtual int vfunc_30();
    virtual int vfunc_34();
    virtual int vfunc_38();
    virtual int vfunc_3C();
    virtual int vfunc_40();
    virtual int vfunc_44();
    virtual int vfunc_48();
    virtual int vfunc_4C();
    virtual int vfunc_50();
    virtual int vfunc_54();
    virtual int vfunc_58();
    virtual int vfunc_5C();
    virtual int vfunc_60();
    virtual int vfunc_64();
    virtual int vfunc_68();
    virtual int vfunc_6C();
    virtual int vfunc_70();
    virtual int vfunc_74();
    virtual int vfunc_78();
    virtual int vfunc_7C();
    virtual int vfunc_80();
    virtual int vfunc_84();
    virtual int vfunc_88();
    virtual int vfunc_8C();
    virtual int vfunc_90();
    virtual int vfunc_94();
    virtual int vfunc_98();
    virtual int vfunc_9C();
    virtual int vfunc_A0();
    virtual int vfunc_A4();
    virtual int vfunc_A8();
    virtual int vfunc_AC();
    virtual int vfunc_B0();
    virtual int vfunc_B4();
    virtual int vfunc_B8();
    virtual int vfunc_BC();
};
struct UnkStruct_GDP_score { unsigned char pad_0[0x10C0]; unsigned char field_10C0[0xCC]; unsigned char field_118C[0x52]; unsigned char field_11DE; unsigned char pad_11DF[2]; unsigned char field_11E1; };
struct UnkStruct_GDP_P {
    unsigned char pad_0[0x118C];
    unsigned char field_118C[0x52];
    unsigned char field_11DE;
    unsigned char pad_11DF[2];
    unsigned char field_11E1;
    unsigned char pad_11E2[0x70B];
    unsigned char field_18ED;
    unsigned char pad_18EE[0xBE];
    signed char field_19AC;
    unsigned char field_19AD;
    unsigned char pad_19AE[0xAB2];
    int field_2460;
    unsigned char field_2464[4];
    unsigned char pad_2468[0x360];
    unsigned char field_27C8;
};
struct UnkStruct_GDP_self {
    unsigned char pad_0[0x13BC];
    float field_13BC;
    unsigned char pad_13C0[0x34];
    UnkStruct_GDP_score * field_13F4;
    unsigned char pad_13F8[4];
    unsigned char field_13FC;
    unsigned char pad_13FD[3];
    float field_1400;
    float field_1404;
    float field_1408;
    unsigned char pad_140C[8];
    float field_1414;
    unsigned char pad_1418[0xB0];
    int field_14C8;
    unsigned char pad_14CC[0x68];
    float field_1534;
    unsigned char pad_1538[0x48];
    UnkStruct_GDP_P * field_1580;
    unsigned char pad_1584[0x2FFC];
    unsigned char field_4580;
    unsigned char pad_4581;
    bool field_4582;
    unsigned char pad_4583;
    bool field_4584;
};
struct UnkStruct_GDP_G { unsigned char pad_0[0x1B4]; UnkStruct_GDP_vt * field_1B4; };
struct UnkStruct_GDP_G0 { UnkStruct_GDP_G * field_0; int pad[3]; };
extern UnkStruct_GDP_G0 D_0051BA88;
extern "C" float GetAccelerator__20CB3ControllerMappingFv(void *);
extern "C" float GetBrake__20CB3ControllerMappingFv(void *);
extern "C" float func_0012F850(void *);
extern "C" float func_0012F610(void *);
extern "C" float func_0012F4E0(void *);
extern "C" float func_0012F240(void *);
extern "C" float func_0012F160(void *);
extern "C" float func_0012F6B0(void *);
extern "C" void NextFrame__15CB3ReplaySystemFP16CDrivingControlsb(void *, void *, bool);
extern "C" void StartBurn__7CB3BurnFP17CB3RaceCarPhysics(void *, void *);
extern "C" void StopBurn__7CB3BurnFv(void *);
extern "C" void StartRaceCarCrashing__22CB3CrashActionDirectorFP17CB3RaceCarPhysicsiP16CB3CollidingPairP17CB3CrashStartInfo(void *, void *, int, void *, void *);
extern "C" void func_001CC520(void *, int, int, float);
extern "C" bool WasSlammedWithinTime__8CB3ScoreFf(void *, float);
extern "C" bool WasResetWithinTime__8CB3ScoreFf(void *, float);
extern "C" void GetDrivingControls__17CB3RaceCarPhysicsFv(void *);
extern "C" void GetDrivingControls__15CB3AICarPhysicsFv(void *);
struct UnkStruct_D_00665ECC_gdp { unsigned char field_0; unsigned char pad[15]; };
extern UnkStruct_D_00665ECC_gdp D_00665ECC;
extern float D_004E0C18;
extern float D_004E0CC8;
extern float D_004E0AAC;
struct UnkStruct_D_0055E948_gdp { unsigned char pad_0[0x10]; };
extern UnkStruct_D_0055E948_gdp D_0055E948;
extern UnkStruct_D_0055E948_gdp D_0055EEE8;

extern "C" void GetDrivingControls__19CB3PlayerCarPhysicsFv(UnkStruct_GDP_self * self)
{
    if (self->field_1580->field_19AD == 0) {
        self->field_1404 = 0.0f;
        self->field_1400 = 0.0f;
        self->field_1414 = 0.0f;
        GetDrivingControls__17CB3RaceCarPhysicsFv(self);
        return;
    }
    if (self->field_1580->field_27C8 != 0) {
        GetDrivingControls__15CB3AICarPhysicsFv(self);
        return;
    }
    void * m = *(void **)self->field_1580->field_2460;
    self->field_1414 = GetAccelerator__20CB3ControllerMappingFv(m);
    self->field_1404 = GetBrake__20CB3ControllerMappingFv(m);
    self->field_1408 = func_0012F850(m);
    self->field_13FC = 0;
    if (self->field_13F4->field_11DE != 0) self->field_1414 = 1.0f;
    if (!(func_0012F610(m) <= D_004E0C18)) self->field_13FC |= 1;
    if (!(func_0012F4E0(m) <= D_004E0C18)) self->field_13FC |= 2;
    if (!(func_0012F240(m) <= D_004E0C18)) self->field_13FC |= 0x10;
    if (D_00665ECC.field_0 != 0) self->field_1408 = -self->field_1408;
    bool s0 = self->field_4584;
    if (self->field_13F4->field_11E1 != 0 && self->field_13F4->field_11DE != 0) s0 = true;
    if (!(func_0012F160(m) <= D_004E0C18) && self->field_14C8 > 0 || s0) self->field_13FC |= 4;
    if (!(func_0012F6B0(m) <= D_004E0C18)) self->field_13FC |= 8;
    NextFrame__15CB3ReplaySystemFP16CDrivingControlsb(&D_0055EEE8, &self->field_13FC, false);
    if (self->field_13FC & 4) {
        if (self->field_1580->field_11DE == 0) StartBurn__7CB3BurnFP17CB3RaceCarPhysics(self->field_1580->field_118C, self);
    } else {
        if (self->field_1580->field_11DE != 0) StopBurn__7CB3BurnFv(self->field_1580->field_118C);
    }
    if (!(self->field_13FC & 8)) self->field_4580 = 0;
    if (self->field_1580->field_11DE == 0) self->field_13FC &= 0xFB;
    float x = self->field_1414 * self->field_13BC;
    self->field_1400 = x;
    if (!(x <= 1.0f)) self->field_1400 = 1.0f;
    if (self->field_4582 != 0) {
        if (self->field_13FC & 4) {
            StartRaceCarCrashing__22CB3CrashActionDirectorFP17CB3RaceCarPhysicsiP16CB3CollidingPairP17CB3CrashStartInfo(&D_0055E948, self, self->field_1580->field_19AC, 0, 0);
            func_001CC520(self, 9, 0, D_004E0CC8);
        } else if (self->field_13FC & 0x10) {
            StartRaceCarCrashing__22CB3CrashActionDirectorFP17CB3RaceCarPhysicsiP16CB3CollidingPairP17CB3CrashStartInfo(&D_0055E948, self, self->field_1580->field_19AC, 0, 0);
            func_001CC520(self, 5, 0, D_004E0CC8);
        } else if (self->field_13FC & 1) {
            StartRaceCarCrashing__22CB3CrashActionDirectorFP17CB3RaceCarPhysicsiP16CB3CollidingPairP17CB3CrashStartInfo(&D_0055E948, self, self->field_1580->field_19AC, 0, 0);
            func_001CC520(self, 0xA, 0, D_004E0CC8);
        } else if (self->field_13FC & 2) {
            StartRaceCarCrashing__22CB3CrashActionDirectorFP17CB3RaceCarPhysicsiP16CB3CollidingPairP17CB3CrashStartInfo(&D_0055E948, self, self->field_1580->field_19AC, 0, 0);
            func_001CC520(self, 6, 0, D_004E0CC8);
        }
    }
    if (self->field_13FC & 8) self->field_1580->field_18ED = 1;
    else self->field_1580->field_18ED = 0;
    UnkStruct_GDP_P * pa = self->field_1580;
    unsigned char ta = (unsigned char)(int)(31.0f * self->field_1414);
    pa->field_2464[0] &= 0xE0;
    pa->field_2464[0] += ta;
    UnkStruct_GDP_P * pb = self->field_1580;
    unsigned char tb = (unsigned char)(int)(7.0f * self->field_1404);
    pb->field_2464[0] &= 0x1F;
    pb->field_2464[0] += (unsigned char)(tb << 5);
    self->field_1580->field_2464[1] = (signed char)(int)(127.0f * self->field_1408);
    unsigned char * q = self->field_1580->field_2464;
    if ((self->field_13FC & 8) == 8) q[2] |= 0x10; else q[2] &= 0xEF;
    q = self->field_1580->field_2464;
    if ((self->field_13FC & 4) == 4) q[2] |= 8; else q[2] &= 0xF7;
    int r = self->field_14C8;
    unsigned char * q2 = self->field_1580->field_2464;
    unsigned char a2;
    if (r >= 0) a2 = r; else a2 = 7;
    int mk = ~7;
    unsigned char qq = q2[2];
    qq = qq & mk;
    q2[2] = qq;
    q2[2] |= a2;
    UnkStruct_GDP_vt * o = D_0051BA88.field_0->field_1B4;
    if (o->vfunc_94() != 0 && WasSlammedWithinTime__8CB3ScoreFf(self->field_13F4->field_10C0, 1.0f) && !WasResetWithinTime__8CB3ScoreFf(self->field_13F4->field_10C0, 1.0f)) {
        self->field_1534 = D_004E0AAC;
    } else {
        if (self->field_13F4->field_11E1 != 0 && self->field_13F4->field_11DE != 0) {
            *(int *)&self->field_1534 = 0x3E800000;
        } else if (o->vfunc_BC() != 0) {
            *(int *)&self->field_1534 = 0x3F000000;
        } else {
            *(int *)&self->field_1534 = 0x3F800000;
        }
    }
    GetDrivingControls__17CB3RaceCarPhysicsFv(self);
}
