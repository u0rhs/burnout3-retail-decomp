// NONMATCHING: Prepare__8CB3ScoreFi -- retail 408 / ours 406 instructions, 27 in changed runs
// draftAL C-first: finished-score base, race car, burn (boost bar size), score bonus, race state from the game mode's vfunc_C0, every counter/flag/timer reset, start position/lap, eight inlined CB3ScoreCategory::Prepare (E-map name and parameters), race length from UpdateCurrentAILaneSegment; 406/408, 27 changed, calls identical; returns 1 (retail v0); left: three categories' 0.0 stores via a zero FPR (swc1) where ours uses sw zero, frame 0x60 vs 0x50
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm; all 200+ stores traced to field/value (incl. -1000.0 near-miss times, the five 6/8-element reset loops, the -1 ints vs -1.0 floats), the category arguments (type 0..7, threshold table, count 3/4), the lane-walk arguments and the checkpoint distance difference

// CB3Score::Prepare(int) -- draftAL (C-first draft). 0x15C340, 0x660. [C] name: the mangled symbol in retail's tables (E map:
// CB3Score::Prepare(int), B3Score.cpp). Written from the retail asm. No Revenge counterpart (stabs_lookup).
// [C] the eight score categories are set up by an inlined CB3ScoreCategory::Prepare(EScoreCategoryType, const CB3Score*,
// const float*, int) (E map name and parameter list; which argument lands in which field [L]: the type 0..7 at +0x14, the
// threshold count at +0x13).
// What it does [L]: the finished-score base part, the race car (D_0064D388[index]), the burn (boost bar size from the
// vehicle list), the score bonus; the race state (0 if the game mode's vfunc_C0 says so, else 1), every per-race counter,
// flag and timer back to its start value (-1.0 = unset, -1000.0 for the near-miss times), the start position / lap
// (second half of the grid starts one lap behind: field_350 = -1), the eight categories (air, oncoming, drift, speed,
// near miss, rubbing, tailgate, grinding with their gmarMin* threshold tables), and the race length left from the car's
// start AI-lane segment (UpdateCurrentAILaneSegment) to the last checkpoint distance. Types and field meanings [G].
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

class CB3Score;
enum EScoreCategoryType { EScoreCategoryType_0 };
enum EB3BoostBarSize { EB3BoostBarSize_0 };
class CB3ScoreCategory {
public:
    void Prepare(EScoreCategoryType, const CB3Score *, const float *, int);   // [C] E map; defined after CB3Score
    float field_0;
    float field_4;                          // the owner's +0xC at prepare time
    float field_8;
    const float * field_C;                  // thresholds
    unsigned char field_10;
    signed char field_11;
    signed char field_12;
    unsigned char field_13;                 // threshold count
    int field_14;                           // EScoreCategoryType
    const CB3Score * field_18;              // owner
};
class CB3Burn { public: void Prepare(EB3BoostBarSize); unsigned char pad_0[0x1]; };
class CB3VehicleList { public: EB3BoostBarSize GetVehicleBoostBarSize(unsigned long); unsigned char pad_0[0x10]; };
extern CB3VehicleList D_005186A0;
struct UnkStruct_0015C340_car { unsigned char pad_0[0x18BC]; float field_18BC; int field_18C0; unsigned char pad_18C4[0x9C]; unsigned long field_1960; };
extern UnkStruct_0015C340_car * D_0064D388[];
struct UnkStruct_0015C340_cp { float field_0; int field_4; };   // checkpoint: race distance
// [C] retail addresses both with lui/%lo (not $gp): padded structs (rules section 5)
struct UnkStruct_0015C340_cpl { UnkStruct_0015C340_cp * field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_0015C340_cpn { int field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_0015C340_cpl D_0064D364;    // the checkpoints
extern UnkStruct_0015C340_cpn D_0064D368;    // their count
struct UnkStruct_0015C340_seg { short field_0; unsigned char pad_2[8]; };   // AI-lane segment, 10 bytes: its checkpoint
struct UnkStruct_0015C340_ls { unsigned char pad_0[8]; UnkStruct_0015C340_seg * field_8; };
class CB3AILane {
public:
    static void UpdateCurrentAILaneSegment(CB3AILane **, unsigned short *, signed char *, float *, CGtV3d, bool);
    unsigned char pad_0[0x4];
    UnkStruct_0015C340_ls * field_4;
};
struct UnkStruct_0015C340_gm {              // the game mode object (vptr at +0)
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
    virtual int vfunc_C0();
    unsigned char pad_4[0x2];
    unsigned char field_6;
};
struct UnkStruct_0015C340_g { unsigned char pad_0[0x1B4]; UnkStruct_0015C340_gm * field_1B4; };
struct UnkStruct_0015C340_D { UnkStruct_0015C340_g * field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_0015C340_D D_0051BA88;
extern const float gmarMinAir__8CB3Score[];
extern const float gmarMinOncoming__8CB3Score[];
extern const float gmarMinDrift__8CB3Score[];
extern const float gmarMinNearMiss__8CB3Score[];
extern const float gmarMinRubbing__8CB3Score[];
extern const float gmarMinTailgate__8CB3Score[];
extern const float gmarMinGrinding__8CB3Score[];
extern const float D_004B62F8[];            // [G] the speed category's thresholds
extern "C" void Prepare__16CB3FinishedScoreFi(CB3Score *, int);
extern "C" void func_00369450(void *, UnkStruct_0015C340_car *);   // [L] the score bonus' prepare (proven B3ScoreBonus.cpp)

class CB3Score {
public:
    bool Prepare(int);                      // [C] retail returns 1 in v0 (its caller Prepare__10CB3RaceCar ignores it)
    unsigned char pad_0[0xC];
    float field_C;                                   // read by each category's Prepare
    unsigned char pad_10[0x94];
    int field_A4;
    int field_A8;
    unsigned char pad_AC[0x1C];
    UnkStruct_0015C340_car * field_C8;              // the race car
    CB3Burn field_CC;
    unsigned char pad_CD[0x57];
    unsigned char field_124[1];                    // [L] CB3ScoreBonus (func_00369450 = its prepare)
    unsigned char pad_125[0x157];
    int field_27C;                                 // race state
    float field_280;
    float field_284;
    int field_288;
    float field_28C;
    unsigned char pad_290[0x4];
    CGtV3d ** field_294;                            // -> the car position
    unsigned char pad_298[0x8];
    CGtV3d field_2A0;
    CGtV3d field_2B0;
    unsigned char field_2C0;
    unsigned char field_2C1;
    unsigned char pad_2C2[0x6];
    int field_2C8;
    int field_2CC;
    float field_2D0;
    unsigned char field_2D4;
    unsigned char field_2D5;
    unsigned char field_2D6;
    unsigned char field_2D7;
    float field_2D8;
    int field_2DC;
    unsigned char pad_2E0[0x8];
    int field_2E8[8];
    unsigned char field_308;
    unsigned char field_309;
    unsigned char pad_30A[0x2];
    int field_30C;
    int field_310;
    int field_314;
    int field_318[8];
    int field_338;
    float field_33C;
    float field_340;
    int field_344;
    float field_348;
    int field_34C;
    int field_350;
    int field_354;
    CB3ScoreCategory field_358;                    // air
    CB3ScoreCategory field_374;                    // oncoming
    CB3ScoreCategory field_390;                    // drift
    CB3ScoreCategory field_3AC;                    // [G] speed (D_004B62F8 thresholds)
    unsigned char field_3C8;
    unsigned char field_3C9;
    unsigned char field_3CA;
    unsigned char field_3CB;
    int field_3CC;
    int field_3D0;
    int field_3D4;
    int field_3D8;
    int field_3DC;
    float field_3E0;
    float field_3E4;
    unsigned char field_3E8[8];
    int field_3F0[8];
    unsigned char field_410[8];
    CB3ScoreCategory field_418;                    // near miss
    int field_434;
    unsigned char field_438[6];
    unsigned char pad_43E[0x2];
    float field_440[6];
    float field_458[6];
    int field_470[6];
    float field_488[6];
    float field_4A0[6];
    int field_4B8;
    float field_4BC;
    int field_4C0;
    int field_4C4;
    float field_4C8;
    unsigned char field_4CC;
    unsigned char pad_4CD[0x3];
    int field_4D0;
    int field_4D4;
    float field_4D8[6];
    unsigned char field_4F0[6];
    unsigned char field_4F6[6];
    unsigned char field_4FC;
    unsigned char pad_4FD[0x3];
    float field_500;
    unsigned char field_504;
    unsigned char field_505;
    unsigned char field_506;
    unsigned char field_507;
    int field_508;
    int field_50C;
    float field_510[6];
    int field_528[6];
    float field_540[6];
    unsigned char field_558[6];
    unsigned char field_55E[6];
    CB3ScoreCategory field_564;                    // rubbing
    int field_580;
    float field_584;
    int field_588;
    float field_58C;
    int field_590;
    int field_594;
    CB3ScoreCategory field_598;                    // tailgate
    int field_5B4;
    unsigned char field_5B8;
    unsigned char field_5B9[6];
    unsigned char field_5BF;
    float field_5C0;
    CB3ScoreCategory field_5C4;                    // grinding
    int field_5E0;
    unsigned char field_5E4;
    unsigned char field_5E5;
    unsigned char field_5E6;
    unsigned char field_5E7;
    float field_5E8;
    int field_5EC;
    float field_5F0;
    float field_5F4;
    int field_5F8;
    float field_5FC;                               // race length left from the start segment

};

// [L] body (inlined at all eight sites)
inline void CB3ScoreCategory::Prepare(EScoreCategoryType type, const CB3Score * owner, const float * table, int n)
{
    field_18 = owner;
    field_C = table;
    field_13 = n;
    field_14 = type;
    field_0 = 0.0f;
    field_4 = field_18->field_C;
    field_8 = 0.0f;
    field_10 = 0;
    field_11 = -1;
    field_12 = -1;
}

// 0x0015C340
bool CB3Score::Prepare(int idx)
{
    Prepare__16CB3FinishedScoreFi(this, idx);
    field_C8 = D_0064D388[idx];
    field_CC.Prepare(D_005186A0.GetVehicleBoostBarSize(field_C8->field_1960));
    func_00369450(field_124, field_C8);
    if (D_0051BA88.field_0->field_1B4->vfunc_C0())
        field_27C = 0;
    else
        field_27C = 1;
    field_280 = -1.0f;
    field_284 = -1.0f;
    field_288 = 0;
    field_28C = -1.0f;
    field_2A0.Zero();
    field_2B0.Zero();
    field_2C0 = 0;
    field_3CB = 0;
    field_2C1 = 0;
    field_2C8 = 0;
    field_2CC = 0;
    field_2D0 = -1.0f;
    field_2D4 = 0;
    field_2D5 = 0;
    field_2D6 = 0;
    field_2D7 = 0;
    field_2D8 = -1.0f;
    field_2DC = 0;
    for (int i = 0; i < 8; i++)
        field_2E8[i] = 0;
    field_308 = 0;
    field_309 = 0;
    field_30C = 0;
    field_310 = 0;
    field_314 = 0;
    for (int i = 0; i < 8; i++)
        field_318[i] = 0;
    field_338 = 0;
    field_33C = -1.0f;
    field_340 = -1.0f;
    int pos = field_C8->field_18C0;
    if (pos >= 0 && D_0064D368.field_0 > 0) {
        field_34C = pos;
        field_348 = field_C8->field_18BC;
        field_344 = field_34C;
        if (field_34C < D_0064D368.field_0 / 2 + 1)
            field_350 = 0;
        else
            field_350 = -1;
    } else {
        field_350 = -1;
        field_34C = -1;
        field_344 = -1;
    }
    field_358.Prepare((EScoreCategoryType)0, this, gmarMinAir__8CB3Score, 4);
    field_3C8 = 0;
    field_354 = 0;
    field_374.Prepare((EScoreCategoryType)1, this, gmarMinOncoming__8CB3Score, 4);
    field_3C9 = 0;
    field_390.Prepare((EScoreCategoryType)2, this, gmarMinDrift__8CB3Score, 4);
    field_3CA = 0;
    field_3AC.Prepare((EScoreCategoryType)7, this, D_004B62F8, 3);
    field_3CC = 0;
    field_3D0 = 0;
    field_3D4 = 0;
    field_3D8 = 0;
    field_3DC = 0;
    field_3E0 = -1.0f;
    field_3E4 = -1.0f;
    for (int i = 0; i < 8; i++) {
        field_3E8[i] = 0xFF;
        field_3F0[i] = 0;
        field_410[i] = 0;
    }
    field_418.Prepare((EScoreCategoryType)6, this, gmarMinNearMiss__8CB3Score, 4);
    field_434 = 0;
    for (int i = 0; i < 6; i++) {
        field_438[i] = 0;
        field_440[i] = -1.0f;
        field_458[i] = -1000.0f;
        field_470[i] = 0;
        field_488[i] = -1.0f;
        field_4A0[i] = -1.0f;
    }
    field_A4 = 0;
    field_4B8 = 0;
    field_4BC = -1.0f;
    field_4C0 = 0;
    field_4C4 = 0;
    field_4C8 = -1.0f;
    field_4CC = 0;
    field_4D0 = 0;
    field_4D4 = 0;
    field_5EC = 0;
    field_5F0 = -1.0f;
    for (int i = 0; i < 6; i++) {
        field_4D8[i] = -1.0f;
        field_4F0[i] = 0;
        field_4F6[i] = 0;
    }
    field_4FC = 0;
    field_500 = -1.0f;
    field_504 = 0;
    field_505 = 0;
    field_506 = 0;
    field_507 = 0;
    field_508 = 0;
    field_50C = 0;
    for (int i = 0; i < 6; i++) {
        field_510[i] = -1.0f;
        field_528[i] = 0;
        field_540[i] = -1.0f;
        field_558[i] = 0;
        field_55E[i] = 0;
    }
    field_564.Prepare((EScoreCategoryType)3, this, gmarMinRubbing__8CB3Score, 3);
    field_580 = -1;
    field_584 = -1.0f;
    field_588 = 0;
    field_58C = -1.0f;
    field_590 = 0;
    field_594 = 0;
    field_598.Prepare((EScoreCategoryType)4, this, gmarMinTailgate__8CB3Score, 3);
    field_5B4 = -1;
    field_5B8 = 0;
    for (int i = 0; i < 6; i++)
        field_5B9[i] = 0;
    field_5BF = 0;
    field_5C0 = -1.0f;
    field_5C4.Prepare((EScoreCategoryType)5, this, gmarMinGrinding__8CB3Score, 3);
    field_5E4 = 0;
    field_5E0 = 0;
    field_5E5 = 0;
    field_5E6 = 0;
    field_5E7 = 0;
    field_5E8 = -1.0f;
    field_5F4 = 1.0f;
    field_5F8 = -1;
    field_A8 = 0;
    CGtV3d lPos = **field_294;
    unsigned short seg = 0xFF;
    signed char dir = -1;
    CB3AILane * lane = 0;
    float f = 0.0f;
    CB3AILane::UpdateCurrentAILaneSegment(&lane, &seg, &dir, &f, lPos, false);
    field_5FC = D_0064D364.field_0[D_0064D368.field_0 - 1].field_0 - D_0064D364.field_0[lane->field_4->field_8[seg].field_0].field_0;
    D_0051BA88.field_0->field_1B4->field_6 = 0;
    return true;
}
