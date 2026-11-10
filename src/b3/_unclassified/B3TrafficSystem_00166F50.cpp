// CB3TrafficSystem::Prepare() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3TrafficSystem.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (draftAD: hand-written from asm+Ghidra (resumable 4-state switch with case fall-through, state-4 body inside case 4; gGame +0x2DA48 run-time offset assigned per arm, before the call; reset loop reuses lnValveIndex; own light-corona counter)).

// CB3TrafficSystem::Prepare() -- hand-written (draftAD, 2026-10-31); the lifter refused it. Local names [L]: Revenge STABS
// Prepare__16CB4TrafficSystem (lnVehicleIndex, lnParamIndex, lnStopJunctionIndex, lnValveIndex, lnValveLaneIndex, lnSplitterIndex,
// lnLightIndex, i; bool return; tools/stabs_lookup.py).
// [L] reading: a resumable prepare (state at +0x374F8): 1/0x18 take the 12 memory blocks; 2 collect the vehicle ids (six id lists of
// the track's traffic data plus five optional ids by flag bits); 3 prepare the vehicle data and register a physics-attribs entry per
// id; 4 prepare the 254 vehicles and params, reset, then (with track data) the flags, ids, the trigger data, stop junctions, valves
// (each registering itself with its lanes), splitters, lights (their corona bits), and the track's payloads.
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

struct UnkStruct_00166F50_ids { unsigned long field_0; unsigned char pad_8[0x10]; };   // [G] 0x18-byte id entry
struct UnkStruct_00166F50_td {   // [G] the track's traffic data
    unsigned long field_0;
    unsigned long field_8;
    unsigned long field_10;
    unsigned long field_18;
    unsigned long field_20;
    unsigned char pad_28[0x4];
    void * field_2C;       // stop junction structs (0x58 each)
    int field_30;
    void * field_34;       // traffic light position structs (0x18 each)
    int field_38;
    void * field_3C;       // valve position structs (0x10 each)
    int field_40;
    void * field_44;       // splitter structs (8 each)
    int field_48;
    unsigned char pad_4C[0x8];
    UnkStruct_00166F50_ids * field_54; int field_58; unsigned char pad_5C[4];
    UnkStruct_00166F50_ids * field_60; int field_64; unsigned char pad_68[4];
    UnkStruct_00166F50_ids * field_6C; int field_70; unsigned char pad_74[4];
    UnkStruct_00166F50_ids * field_78; int field_7C; unsigned char pad_80[4];
    UnkStruct_00166F50_ids * field_84; int field_88; unsigned char pad_8C[4];
    UnkStruct_00166F50_ids * field_90; int field_94;
    unsigned char pad_98[0x1C];
    unsigned char field_B4;
    unsigned char field_B5;
};
class CB3StopJunctionStruct;
class CB3TrafficValvePositionStruct;
class CB3TrafficLightPositionStruct;
struct UnkStruct_00166F50_vl { int * field_0; int pad_4; int field_8; };   // [G] a valve's lane list
class CB3TrafficValve {
public:
    bool Prepare(CB3TrafficValvePositionStruct *);
    void ResetCrashmodeData();
    unsigned char pad_0[0x40];
    UnkStruct_00166F50_vl * field_40;
    unsigned char pad_44[0xD4];
};
class CB3StopJunction {
public:
    bool Prepare(CB3StopJunctionStruct *);
    unsigned char pad_0[0x20];
};
struct UnkStruct_00166F50_lp { unsigned char pad_0[0x10]; unsigned char field_10[4]; unsigned char field_14; };
class CB3TrafficLight {
public:
    bool Prepare(CB3TrafficLightPositionStruct *);
    UnkStruct_00166F50_lp * field_0;
    unsigned char pad_4[0x14];
};
struct UnkStruct_00166F50_sp { void * field_0; int * field_4; };   // [G] a splitter: its lane
class CB3TrafficVehicle {
public:
    void Prepare();
    unsigned char pad_0[0x177];
    unsigned char field_177;   // index
    unsigned char pad_178[0x8];
};
class CB3TrafficParam {
public:
    void Prepare();
    unsigned char pad_0[0x49];
    unsigned char field_49;    // index
    unsigned char pad_4A[0x6];
};
struct UnkStruct_00166F50_m { CGtMatrix3x4 field_0; CGtV3d field_40; };
class CB3VehiclePhysicsAttribs {
public:
    void Construct();
    void Register(unsigned long);
    unsigned char pad_0[0xB0];
};
struct UnkStruct_00166F50_lane {   // [G] 0x4C-byte lane record at D_00522660 + 0x22C
    unsigned char pad_0[0x6];
    unsigned char field_6[0x18];   // valves on this lane
    unsigned char field_1E[0x18];  // the lane's index in each valve
    unsigned char field_36[0x12];  // splitters on this lane
    unsigned char field_48;
    unsigned char field_49;
    unsigned char pad_4A[2];
};
struct UnkStruct_D_00522660 { unsigned char pad_0[0x22C]; UnkStruct_00166F50_lane field_22C[1]; };
struct UnkStruct_D_004EE040 { unsigned char pad_0[0x2DA48]; void * field_2DA48; };   // [L] gGame: field_2DA48 = the current logic (D_0051BA88)
struct UnkStruct_D_0064D344 { unsigned char pad_0[8]; int field_8; };
struct UnkStruct_theMemMgr { unsigned char pad_0[0x10]; };
class CB3HardCodedTrackList {
public:
    static void GetPayloadsForTrack(unsigned long, unsigned char *, unsigned char *, unsigned char *);
};

class CB3TrafficSystem {
public:
    bool Prepare();
    bool PrepareTrafficVehicleData();
    void ResetMemberVariables();
    void VerifyAndLoadVehicleIDs();
    void UseNextTriggerData(float);

    UnkStruct_00166F50_td * field_0;
    CB3TrafficValve field_4[255];
    CB3StopJunction field_116EC[7];
    CB3TrafficLight field_117CC[128];
    UnkStruct_00166F50_sp field_123CC[128];
    unsigned char pad_127CC[4];
    CB3TrafficVehicle field_127D0[254];
    CB3TrafficParam field_2A4D0[254];
    UnkStruct_00166F50_m field_2F430[254];
    unsigned long field_34390[12];   // vehicle ids
    void * field_343F0[12];          // memory blocks
    unsigned char pad_34420[0x30];
    signed char field_34450;         // vehicle id count
    unsigned char pad_34451[0x36320 - 0x34451];
    int field_36320[8];              // traffic-light corona bits
    int field_36340;
    unsigned char pad_36344[0x363AB - 0x36344];
    unsigned char field_363AB;
    unsigned char pad_363AC;
    unsigned char field_363AD;       // valves
    unsigned char field_363AE;       // splitters
    unsigned char field_363AF;       // lights
    unsigned char field_363B0;       // stop junctions
    unsigned char pad_363B1;
    unsigned char field_363B2;
    unsigned char field_363B3;
    unsigned char field_363B4;
    unsigned char field_363B5;
    unsigned char field_363B6;
    unsigned char field_363B7;
    unsigned char field_363B8;
    unsigned char field_363B9;
    unsigned char field_363BA;
    unsigned char pad_363BB[2];
    unsigned char field_363BD;       // trigger data pending
    unsigned char field_363BE;
    unsigned char pad_363BF[0x374F8 - 0x363BF];
    int field_374F8;                 // prepare state
};

extern UnkStruct_D_00522660 D_00522660;
extern UnkStruct_D_004EE040 D_004EE040;
extern unsigned char D_0051AEC0[];
extern UnkStruct_D_0064D344 * D_0064D344[];
extern unsigned long D_0064D370[];
extern CB3VehiclePhysicsAttribs D_01D9BB10[];
extern UnkStruct_theMemMgr theMemMgr;
extern "C" void * AcquireBlock__19CB3MemoryManagerPS2F14EB3MemoryBlocki(void *, int, int);
extern "C" int func_00131E40(void *);
extern "C" bool func_0026BE80(UnkStruct_00166F50_sp *, void *);

// [G] one id list into the vehicle id table
#define ADD_IDS(list, count) \
    for (i = 0; i < field_0->count; i++) { \
        field_34390[field_34450] = field_0->list[i].field_0; \
        field_34450++; \
    }
#define ADD_ID(bit, id) \
    if ((field_0->field_B5 & bit) && field_0->id != 0) { \
        field_34390[field_34450] = field_0->id; \
        field_34450++; \
    }

// 0x00166F50
bool CB3TrafficSystem::Prepare()
{
    int i;
    switch (field_374F8) {
    case 1:
    case 0x18:
        for (i = 0; i < 12; i++) {
            if (field_343F0[i] == 0) field_343F0[i] = AcquireBlock__19CB3MemoryManagerPS2F14EB3MemoryBlocki(&theMemMgr, 2, i);
            if (field_343F0[i] == 0) return false;
        }
        field_374F8 = 2;
    case 2:
        if (field_0 != 0) {
            ADD_IDS(field_54, field_58)
            ADD_IDS(field_60, field_64)
            ADD_IDS(field_6C, field_70)
            ADD_IDS(field_78, field_7C)
            ADD_IDS(field_84, field_88)
            ADD_IDS(field_90, field_94)
            ADD_ID(1, field_0)
            ADD_ID(2, field_8)
            ADD_ID(4, field_10)
            ADD_ID(8, field_18)
            ADD_ID(0x10, field_20)
        }
        field_374F8 = 3;
    case 3:
        if (!PrepareTrafficVehicleData()) return false;
        for (i = 0; i < field_34450; i++) {
            CB3VehiclePhysicsAttribs * a = &D_01D9BB10[i];
            a->Construct();
            a->Register(field_34390[i]);
        }
        field_374F8 = 4;
    case 4:
    {

        int lnVehicleIndex;
        for (lnVehicleIndex = 0; lnVehicleIndex < 254; lnVehicleIndex++) {
            field_127D0[lnVehicleIndex].Prepare();
            field_127D0[lnVehicleIndex].field_177 = lnVehicleIndex;
        }
        int lnParamIndex;
        for (lnParamIndex = 0; lnParamIndex < 254; lnParamIndex++) {
            field_2F430[lnParamIndex].field_0.SetIdentity();
            field_2F430[lnParamIndex].field_40.Zero();
            field_2A4D0[lnParamIndex].Prepare();
            field_2A4D0[lnParamIndex].field_49 = lnParamIndex;
        }
        ResetMemberVariables();
        field_36340 = D_0064D344[0]->field_8 / 2;
        field_363AB = 254;
        if (field_0 != 0) {
            int lnValveIndex;
            int off;   // [C] retail adds gGame's member offset at run time (as func_0037F640's D_004EE040 + 0x2DA04)
            if ((field_0->field_B4 & 1) == 0) {
                off = 0x2DA48;
                field_363B7 = 0;
            } else {
                off = 0x2DA48;
                func_00131E40(&D_004EE040);
                field_363B7 = 1;
            }
            if (field_0->field_B4 & 2) field_363BA = 1;
            else field_363BA = 0;
            if ((field_0->field_B4 & 4) == 0) {
                field_363B8 = 0;
            } else {
                field_363B8 = 1;
                for (lnValveIndex = 0; lnValveIndex < 255; lnValveIndex++) field_4[lnValveIndex].ResetCrashmodeData();
            }
            if (*(void **)((char *)&D_004EE040 + off) != (void *)D_0051AEC0) field_363B9 = 0;
            else field_363B9 = 1;
            field_363BE = 0;
            VerifyAndLoadVehicleIDs();
            field_363BD = 1;
            field_363B2 = 0;
            field_363B3 = 0;
            while (field_363BD) UseNextTriggerData(0.0f);

            field_363B0 = field_0->field_30;
            int lnStopJunctionIndex;
            for (lnStopJunctionIndex = 0; lnStopJunctionIndex < field_363B0; lnStopJunctionIndex++) {
                if (!field_116EC[lnStopJunctionIndex].Prepare((CB3StopJunctionStruct *)((char *)field_0->field_2C + lnStopJunctionIndex * 0x58)))
                    return false;
            }
            field_363AD = field_0->field_40;
                for (lnValveIndex = 0; lnValveIndex < field_363AD; lnValveIndex++) {
                if (!field_4[lnValveIndex].Prepare((CB3TrafficValvePositionStruct *)((char *)field_0->field_3C + lnValveIndex * 0x10)))
                    return false;
                int lnValveLaneIndex;
                for (lnValveLaneIndex = 0; lnValveLaneIndex < field_4[lnValveIndex].field_40->field_8; lnValveLaneIndex++) {
                    UnkStruct_00166F50_lane * l = &D_00522660.field_22C[field_4[lnValveIndex].field_40->field_0[lnValveLaneIndex]];
                    l->field_6[l->field_48] = lnValveIndex;
                    l->field_1E[l->field_48] = lnValveLaneIndex;
                    l->field_48++;
                }
            }
            field_363AE = field_0->field_48;
            int lnSplitterIndex;
            for (lnSplitterIndex = 0; lnSplitterIndex < field_363AE; lnSplitterIndex++) {
                UnkStruct_00166F50_sp * s = &field_123CC[lnSplitterIndex];
                if (!func_0026BE80(s, (char *)field_0->field_44 + lnSplitterIndex * 8))
                    return false;
                UnkStruct_00166F50_lane * l = &D_00522660.field_22C[*field_123CC[lnSplitterIndex].field_4];
                l->field_36[l->field_49] = lnSplitterIndex;
                l->field_49++;
            }
            field_363AF = field_0->field_38;
            int lnLightIndex;
            for (lnLightIndex = 0; lnLightIndex < field_363AF; lnLightIndex++) {
                if (!field_117CC[lnLightIndex].Prepare((CB3TrafficLightPositionStruct *)((char *)field_0->field_34 + lnLightIndex * 0x18)))
                    return false;
            }
            for (lnLightIndex = 0; lnLightIndex < field_363AF; lnLightIndex++) {
                for (int lnTLCoronaIndex = 0; lnTLCoronaIndex < field_117CC[lnLightIndex].field_0->field_14; lnTLCoronaIndex++) {
                    int b = field_117CC[lnLightIndex].field_0->field_10[lnTLCoronaIndex];
                    field_36320[b / 32] |= 1 << (b % 32);
                }
            }
        } else {
            field_363B0 = 0;
            field_363AD = 0;
            field_363AE = 0;
            field_363AF = 0;
        }
        CB3HardCodedTrackList::GetPayloadsForTrack(D_0064D370[0], &field_363B4, &field_363B5, &field_363B6);
    }
    }
    return true;
}
