// NONMATCHING: Prepare__10CB3RaceCarFv -- retail 412 / ours 411 instructions, 41 in changed runs
// fix2 (2026-11-01): virtual calls on the right slots: field_1B4's F8 (the draft declared vfunc_0/F0/F4/F8, putting F8 at +0x14) and the game object's own +0x20 through its vtable at +0x1B0 (the draft called through field_1B0 as an object) [C] retail 0x152B64, 0x152C10; field_199C is a float (-1.0f, retail 0x152FDC 0xBF800000) | Before: psweep: scoped #pragma opt_dead_assignments off [G] improves 55 -> 54
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)



#include "b3/GtMathPs2.h"
// [G] N182: scoped optimiser pragma found by the pragma sweep (psweep_all.py)
#pragma push
#pragma opt_dead_assignments off
using namespace GtMathPs2;

struct UnkStruct_00152AF0_vd {   // [G] vehicle data blob loaded asynchronously (field_40)
    unsigned char pad_0[0xC];
    signed char field_C;
    signed char field_D;
    unsigned char pad_E[0xA];
    float field_18;
    float field_1C[6];   // [G] count
    unsigned char pad_34[0x60 - 0x34 - 0];
    struct UnkStruct_00152AF0_vp { unsigned char pad_0[0xA0]; signed char field_A0; } *field_60;
    unsigned char pad_64[0xB80 - 0x64];
    CGtMatrix3x4 field_B80[1];   // [G] count; stride 0x40
    unsigned char pad_BC0[0xD00 - 0xBC0];
    CGtMatrix3x4 field_D00[1];   // [G] count; stride 0x40
};
// fix2: MWCC's first virtual sits at vtable +8 (vfunc_XX = slot offset); the draft's vfunc_0/F0/F4/F8 put F8 at +0x14
class UnkStruct_00152AF0_vobj {
public:
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18();
    virtual void vfunc_1C();
    virtual void vfunc_20();
    virtual void vfunc_24();
    virtual void vfunc_28();
    virtual void vfunc_2C();
    virtual void vfunc_30();
    virtual void vfunc_34();
    virtual void vfunc_38();
    virtual void vfunc_3C();
    virtual void vfunc_40();
    virtual void vfunc_44();
    virtual void vfunc_48();
    virtual void vfunc_4C();
    virtual void vfunc_50();
    virtual void vfunc_54();
    virtual void vfunc_58();
    virtual void vfunc_5C();
    virtual void vfunc_60();
    virtual void vfunc_64();
    virtual void vfunc_68();
    virtual void vfunc_6C();
    virtual void vfunc_70();
    virtual void vfunc_74();
    virtual void vfunc_78();
    virtual void vfunc_7C();
    virtual void vfunc_80();
    virtual void vfunc_84();
    virtual void vfunc_88();
    virtual void vfunc_8C();
    virtual void vfunc_90();
    virtual void vfunc_94();
    virtual void vfunc_98();
    virtual void vfunc_9C();
    virtual void vfunc_A0();
    virtual void vfunc_A4();
    virtual void vfunc_A8();
    virtual void vfunc_AC();
    virtual void vfunc_B0();
    virtual void vfunc_B4();
    virtual void vfunc_B8();
    virtual void vfunc_BC();
    virtual void vfunc_C0();
    virtual void vfunc_C4();
    virtual void vfunc_C8();
    virtual void vfunc_CC();
    virtual void vfunc_D0();
    virtual void vfunc_D4();
    virtual void vfunc_D8();
    virtual void vfunc_DC();
    virtual void vfunc_E0();
    virtual void vfunc_E4();
    virtual void vfunc_E8();
    virtual void vfunc_EC();
    virtual void vfunc_F0();
    virtual void vfunc_F4();
    virtual int vfunc_F8(int);              // [C] retail 0x152B64..0x152B6C
};
// [C] the game object's vtable pointer sits at +0x1B0 (retail 0x152C10..0x152C1C: *(*(gm + 0x1B0) + 0x20) with a0 = gm),
// as UpdateSmallMessage__11CB3HUDScoreFf's; the draft called through a field_1B0 object pointer
struct UnkStruct_00152AF0_game {
    unsigned char pad_0[0x1B0];
    virtual void vfunc_8(); virtual void vfunc_C(); virtual void vfunc_10(); virtual void vfunc_14();
    virtual void vfunc_18(); virtual void vfunc_1C(); virtual int vfunc_20();
    UnkStruct_00152AF0_vobj *field_1B4;
};
struct UnkStruct_00152AF0_lane { unsigned char pad_0[4]; struct UnkStruct_00152AF0_seg { unsigned char pad_0[8]; short *field_8; } *field_4; };

struct UnkStruct_D_0051BA88 { UnkStruct_00152AF0_game *field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_0051BA88 D_0051BA88;
extern unsigned char D_00522660[];
extern unsigned char D_006481A0[];
extern unsigned char D_00648568[];
extern unsigned char D_005186A0[];
extern unsigned char D_004F6100[];
extern unsigned char theMemMgr[];
extern unsigned char gVehicleRenderer[];
extern const char D_004B6228[];
extern unsigned long D_004B6170[2];
extern unsigned long kaRedIndicatorCarIDs[5];
struct UnkStruct_D_0064D358 { int field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_0064D358 D_0064D358;
struct UnkStruct_D_0064D370 { long field_0; unsigned char pad_8[8]; };
extern UnkStruct_D_0064D370 D_0064D370;
struct UnkStruct_D_00665E52 { unsigned char field_0; unsigned char pad_1[0xF]; };
extern UnkStruct_D_00665E52 D_00665E52;
extern float D_004E0E60;

extern "C" int GetNumStartLines__11CB3GameDataFv(void *);
extern "C" int GetNumSplitTimeCheckpoints__11CB3GameDataFv(void *);
extern "C" void *AcquireBlock__19CB3MemoryManagerPS2F14EB3MemoryBlocki(void *, int, int);
extern "C" int GetBlockSize__19CB3MemoryManagerPS2CF14EB3MemoryBlock(void *, int);
extern "C" int GetVehicleIndexFromID__14CB3VehicleListFUl(void *, unsigned long);
extern "C" void CreateVehiclePathFromIndex__14CB3VehicleListFiPci(void *, int, char *, int);
extern "C" char *strcat(char *, const char *);
extern "C" int QueueLoadRequest__17CAsyncLoadManagerFPCcPbPvUi(void *, const char *, bool *, void *, unsigned int);
extern "C" void FixUpVehicleData__18CB3VehicleRendererFP14CB3VehicleData(void *, void *);
extern "C" void Prepare__16CB3VehicleDeformFP25CB3VehicleEssentialParamsP16CB3VehicleParams(void *, void *, void *);
extern "C" void UpdateCurrentAILaneSegment__9CB3AILaneFPP9CB3AILanePUsPScPfQ29GtMathPs26CGtV3db(void *, unsigned short *, signed char *, float *, const void *, bool);
extern "C" void Prepare__8CB3ScoreFi(void *, int);
extern "C" void Prepare__16CB3FinishedScoreFi(void *, int);

class CB3RaceCar {
public:
    int Prepare();
    void Register();

    CGtMatrix3x4 field_0;
    UnkStruct_00152AF0_vd *field_40;
    float field_44;
    float field_48;
    float field_4C;
    float field_50;
    float field_54;
    unsigned char field_58;
    signed char field_59;
    signed char field_5A;
    unsigned char field_5B;
    unsigned char pad_5C[0x24];
    CGtMatrix3x4 field_80[4];
    unsigned char pad_180[0x80];
    CGtMatrix3x4 field_200[4];
    unsigned char pad_300[0x80];
    unsigned char field_380[0x190];
    CGtV3dPlus field_510;
    unsigned char pad_520[0x30];
    float field_550[6];
    float field_568[6];
    unsigned char pad_580[0xA60];
    int field_FE0[6];
    unsigned char pad_FF8[0xC8];
    unsigned char field_10C0[0x290];
    void *field_1350;
    void *field_1354;
    unsigned char pad_1358[0x2C];
    int field_1384;
    unsigned char pad_1388[0x18];
    int field_13A0;
    void *field_13A4;
    unsigned char pad_13A8[0x318];
    unsigned char field_16C0[0xC0];
    unsigned char pad_1780[0x8];
    void *field_1788;
    int field_178C;
    unsigned char pad_1790[0x100];
    int field_1890;
    int field_1894[6];
    int field_18AC;
    int field_18B0;
    void *field_18B4;
    unsigned short field_18B8;
    signed char field_18BA;
    unsigned char pad_18BB[0x1];
    float field_18BC;
    int field_18C0;
    unsigned char pad_18C4[0x1C];
    int field_18E0;
    int field_18E4;
    unsigned char field_18E8;
    unsigned char field_18E9;
    unsigned char field_18EA;
    unsigned char field_18EB;
    unsigned char field_18EC;
    unsigned char field_18ED;
    unsigned char field_18EE;
    unsigned char field_18EF;
    unsigned char field_18F0;
    unsigned char field_18F1;
    unsigned char pad_18F2[0x2];
    int field_18F4;
    int field_18F8;
    int field_18FC;
    int field_1900[4];
    void **field_1910;
    unsigned char pad_1914[0xC];
    CGtMatrix3x4 field_1920;
    unsigned long field_1960;
    int field_1968;
    unsigned char pad_196C[0x28];
    int field_1994;
    unsigned char field_1998;
    unsigned char field_1999;
    bool field_199A;
    unsigned char field_199B;
    float field_199C;                       // fix2: [C] retail 0x152FDC stores 0xBF800000 (-1.0f)
    int field_19A0;
    int field_19A4;
    float field_19A8;
    signed char field_19AC;
    unsigned char field_19AD;
    unsigned char field_19AE;
};

// 0x00152AF0
int CB3RaceCar::Prepare()
{
    switch (field_1968) {
    case 1:
    case 0x18: {
        field_1999 = 0;
        int idx;
        if (D_0051BA88.field_0 != 0 && D_0051BA88.field_0->field_1B4 != 0) {
            idx = D_0051BA88.field_0->field_1B4->vfunc_F8(field_19AC);
        } else {
            idx = field_19AC;
        }
        field_1788 = D_00522660 + idx * 4 + 0x125EB0;
        if (GetNumStartLines__11CB3GameDataFv(D_006481A0) > 0 && field_1890 >= 0) {
            field_1350 = D_00522660 + field_1890 * 16 + 0x125EC8;
            field_1354 = D_00522660 + field_1890 * 16 + 0x125EE8;
            field_13A0 = GetNumSplitTimeCheckpoints__11CB3GameDataFv(D_006481A0);
            field_13A4 = D_00648568;
        }
        field_1384 = D_0051BA88.field_0->vfunc_20();
        field_1968 = 2;
    }
    case 2: {
        field_40 = (UnkStruct_00152AF0_vd *)AcquireBlock__19CB3MemoryManagerPS2F14EB3MemoryBlocki(theMemMgr, 1, field_19AC);
        if (field_40 == 0) return 0;
        char path[0x28];
        int vi = GetVehicleIndexFromID__14CB3VehicleListFUl(D_005186A0, field_1960);
        CreateVehiclePathFromIndex__14CB3VehicleListFiPci(D_005186A0, vi, path, 0x28);
        strcat(path, D_004B6228);
        int sz = GetBlockSize__19CB3MemoryManagerPS2CF14EB3MemoryBlock(theMemMgr, 1);
        field_1994 = QueueLoadRequest__17CAsyncLoadManagerFPCcPbPvUi(D_004F6100, path, &field_199A, field_40, sz);
        Register();
        field_1968 = 3;
    }
    case 3:
        if (field_199A == 0) return 0;
        if (field_1994 != 0) {
            FixUpVehicleData__18CB3VehicleRendererFP14CB3VehicleData(gVehicleRenderer, field_40);
        }
        field_1994 = 0;
        field_1968 = 0x17;
    case 0x17: {
        field_0.SetIdentity();
        int i;
        for (i = 0; i < field_40->field_D; i++) {
            field_80[i] = field_40->field_B80[i];
        }
        for (i = 0; i < field_40->field_C; i++) {
            field_200[i] = field_40->field_D00[i];
        }
        for (i = 0; i < 6; i++) field_FE0[i] = 0;
        if (field_59 >= field_40->field_60->field_A0) {
            field_59 = field_59 % field_40->field_60->field_A0;
        }
        Prepare__16CB3VehicleDeformFP25CB3VehicleEssentialParamsP16CB3VehicleParams(field_380, this, field_80);
        for (i = 0; i < field_40->field_D; i++) {
            field_550[i] = field_40->field_18 * field_40->field_1C[i];
            field_568[i] = 0;
        }
        field_18EA = 0;
        for (i = 0; i < 6; i++) field_1894[i] = 0;
        field_54 = 0.0f;
        field_58 = 0;
        field_5A = -1;
        field_5B = 0;
        field_18F0 = 0;
        for (i = 0; i < 2; i++) {
            if (field_1960 == D_004B6170[i]) field_18F0 = 1;
        }
        field_18F1 = 0;
        for (i = 0; i < 5; i++) {
            if (field_1960 == kaRedIndicatorCarIDs[i]) field_18F1 = 1;
        }
        field_18AC = 0;
        field_18ED = 0;
        field_18B0 = 0;
        field_178C = 0;
        field_18EC = 0;
        field_1998 = 1;
        field_18B4 = 0;
        field_18B8 = 0xFF;
        field_18BA = -1;
        field_18BC = 0;
        field_18C0 = -1;
        field_199B = 0;
        field_1920.SetIdentity();
        field_44 = 0.0f;
        field_48 = 1.0f;
        field_4C = 0.0f;
        field_50 = 1.0f;
        {
            CGtV3d up(0.0f, 1.0f, 0.0f);
            field_510.SetGtV3d(up);
            field_510.SetPlus(field_40->field_18);
        }
        field_199C = -1.0f;
        field_19A4 = 0;
        field_19A0 = 0;
        field_18E9 = 1;
        field_18E8 = 1;
        field_19A8 = D_004E0E60;
        field_18EF = 0;
        int *lane = (int *)field_1788;
        if (*lane != 0 && D_0064D358.field_0 > 0) {
            UpdateCurrentAILaneSegment__9CB3AILaneFPP9CB3AILanePUsPScPfQ29GtMathPs26CGtV3db(&field_18B4, &field_18B8, &field_18BA, &field_18BC, (char *)*lane + 0x30, false);
            UnkStruct_00152AF0_lane *l = (UnkStruct_00152AF0_lane *)field_18B4;
            field_18C0 = l->field_4->field_8[field_18B8 * 5];
        }
        field_18F4 = 0;
        field_18F8 = 0;
        field_18FC = 0;
        for (i = 0; i < 4; i++) field_1900[i] = 0;
        unsigned char one = 1;
        if (D_0064D370.field_0 != 0) {
            Prepare__8CB3ScoreFi(field_10C0, field_19AC);
            if (D_00665E52.field_0 == 0) {
                Prepare__16CB3FinishedScoreFi(field_16C0, field_19AC);
            }
        }
        field_18EB = one;
        field_18EE = 0;
        field_19AD = one;
        field_19AE = one;
        field_18E0 = -1;
        field_18E4 = -1;
    }
    default:
        return ((int (*)(void *))((int *)field_1910)[0x24 / 4])(this);
    }
}

#pragma pop
