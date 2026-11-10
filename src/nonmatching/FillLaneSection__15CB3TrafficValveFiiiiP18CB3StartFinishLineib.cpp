// NONMATCHING: FillLaneSection__15CB3TrafficValveFiiiiP18CB3StartFinishLineib -- retail 656 / ours 657 instructions, 285 in changed runs
// draftAK C-first (Revenge STABS local names): section bounds (hull fill: next/prev params on the lane), flow/speed car count, per car jittered position along the lane, unlocked-segment check, category by flow weight (default 1), vehicle id/colour (fixed ids on special valves), trailer for category 4 (id/colour persist across iterations as retail), Generate, formation slot and speed, removal within 160 of a start line; 657/656, calls identical; left: frame 0x140 vs 0x150, block order
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm; every branch sense, RNG step order, call argument (IsSegmentLocked gets the 4th argument, Revenge's EPlayerCarIndex) and store traced; formation modulo unsigned as retail's divu

// CB3TrafficValve::FillLaneSection(int, int, int, int, CB3StartFinishLine*, int, bool) -- draftAK (C-first draft). 0x266AE0, 0xA40.
// [C] name: the mangled symbol in retail's tables. Written from the retail asm; local names [L] from the Revenge STABS of
// FillLaneSection__15CB4TrafficValve (lnValveLaneIndex, lnStartSegment, lpNextParam, lrMetresPerVehicle, ...;
// tools/stabs_lookup.py; Revenge's 4th argument is an EPlayerCarIndex, passed on to IsSegmentLocked here too). Layout and the
// vehicle-id / colour / Generate / param set-up blocks follow the archived UpdateGeneration__15CB3TrafficValveFiiUsf.
// What it does [L]: fills a section of one valve lane with traffic at race start: the section length (in the hull-fill case
// bounded by the neighbouring params on the lane), the car count from the lane flow (sum of the six category flows) and
// speed, then per car a jittered position along the lane, a free (unlocked) segment check, a category by flow weight, the
// vehicle id and colour (fixed ids for special valves), a trailer for category 4, Generate, the param's formation index
// and speed; cars generated within 160 of a start line (horizontal distance) are removed again.
#include "b3/GtMath.h"
#include "b3/GtMathPs2.h"
#include "b3/_unclassified/GtRandom.h"
using namespace GtMathPs2;

enum ETrafficVehicleCategories {};
class CB3TrafficLane;
class CB3StartFinishLine { public: CGtV3d *field_0; unsigned char pad_4[0xC]; };   // [G] 16 bytes, position pointer first

struct UnkStruct_00266AE0_spd { float field_0; };                          // [G] lane speed (mph)
struct UnkStruct_00266AE0_form { unsigned char pad_0[0x10]; int field_10; };  // [G] a formation: count at +0x10
struct UnkStruct_00266AE0_ctl {
    int *field_0;                           // per valve lane: the traffic lane index
    int *field_4;
    int field_8;
    unsigned char field_C;                  // 2: special valve (fixed vehicle ids)
    unsigned char field_D;
};
struct UnkStruct_00266AE0_seg { float field_0; unsigned char pad_4[4]; };   // [G] per segment: distance along the lane
struct UnkStruct_00266AE0_ld { unsigned char pad_0[0x4]; UnkStruct_00266AE0_seg *field_4; unsigned char pad_8[0x8]; int field_10; };
struct UnkStruct_00266AE0_lane {            // [G] 0x4C-byte lane record at gWorld+0x22C
    UnkStruct_00266AE0_ld *field_0;
    unsigned short field_4;                 // first segment id
    unsigned char pad_6[0x40];
    unsigned char field_46;                 // [G] last param on the lane
};
struct UnkStruct_00266AE0_param {           // CB3TrafficParam (0x50)
    float field_0;                          // speed
    unsigned char pad_4[0x2C];
    float field_30;                         // segment position
    unsigned char pad_34[0x4];
    UnkStruct_00266AE0_form *field_38;
    unsigned char pad_3C[0x9];
    unsigned char field_45;                 // [G] previous param
    unsigned char pad_46;
    unsigned char field_47;                 // formation slot
    unsigned char pad_48[0x8];
};
struct UnkStruct_00266AE0_veh { unsigned char pad_0[0xA0]; CGtV3d field_A0; unsigned char pad_B0[0x64]; UnkStruct_00266AE0_param *field_114; };
struct UnkStruct_00266AE0_ent { unsigned long field_0; unsigned char field_8[8]; };   // vehicle id + colour weights
struct UnkStruct_00266AE0_tbl { unsigned long field_0[5]; };
struct UnkStruct_D_0055D788 { CGtRandom r; unsigned char pad[0x8]; };
struct UnkStruct_D_0055D7DC { unsigned char *field_0; unsigned char pad_4[0xC]; };   // [G] param index per segment id
struct UnkStruct_D_0055D7F7 { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_00266AE0_lr { unsigned char pad_0[0x4C]; };
struct UnkStruct_D_00522660 {               // gWorld
    UnkStruct_00266AE0_lr field_0[1];       // lanes at +0x22C (0x4C each)
};
struct UnkStruct_D_00522660_p { unsigned char pad_0[0x2F2B0]; UnkStruct_00266AE0_param field_2F2B0[254]; };

class CB3TrafficSystem {
public:
    bool IsSegmentLocked(int, unsigned short);
    UnkStruct_00266AE0_veh *Generate(ETrafficVehicleCategories, unsigned long, ETrafficVehicleCategories, unsigned long,
                                     CB3TrafficLane *, float, float, float, unsigned char, unsigned char, unsigned char);
    UnkStruct_00266AE0_tbl *field_0;
    unsigned char pad_4[0xC];
};

class CB3TrafficValve {
public:
    UnkStruct_00266AE0_ent *GetRandomVehicleID(ETrafficVehicleCategories);
    void FillLaneSection(int, int, int, int, CB3StartFinishLine *, int, bool);

    UnkStruct_00266AE0_spd *field_0[4];
    float *field_10[4];                     // per valve lane: six category flows
    UnkStruct_00266AE0_form *field_20[4];
    unsigned char pad_30[0x10];
    UnkStruct_00266AE0_ctl *field_40;
    unsigned char pad_44[0xC8];
    unsigned char field_10C[4];             // next formation slot
    unsigned char pad_110[4];
    unsigned char field_114;                // [G] segment 0 always free
};

extern UnkStruct_D_0055D788 D_0055D788;
extern UnkStruct_D_0055D7DC D_0055D7DC;
extern UnkStruct_D_0055D7F7 D_0055D7F7;
extern UnkStruct_D_0055D7F7 D_0055D7F8;
extern UnkStruct_D_00522660 D_00522660;
extern CB3TrafficSystem D_00527440;
extern "C" float GetParamFromDist__14CB3TrafficLaneFf(UnkStruct_00266AE0_lane *, float);
extern "C" void func_00160B40(UnkStruct_00266AE0_param *);
extern "C" void func_00173D30(UnkStruct_00266AE0_veh *);   // [L] E map: CB3TrafficVehicle::Remove()

static inline UnkStruct_00266AE0_lane *func_00266AE0_lane(int idx)
{
    if (idx == 255)
        return 0;
    return (UnkStruct_00266AE0_lane *)((char *)&D_00522660.field_0[idx] + 0x22C);
}
static inline UnkStruct_00266AE0_param *func_00266AE0_param(unsigned char idx)
{
    if (idx == 255)
        return 0;
    return &((UnkStruct_D_00522660_p *)&D_00522660)->field_2F2B0[idx];
}
// [L] the colour pick by percentage weights (UpdateGeneration's loop)
static inline unsigned char func_00266AE0_colour(const UnkStruct_00266AE0_ent *e, unsigned int r)
{
    int sum = 0;
    unsigned char k = 0;
    while (k < 8) {
        sum += e->field_8[k];
        if (!(sum < (int)(r % 100)))
            break;
        k = k + 1;
    }
    return k;
}

void CB3TrafficValve::FillLaneSection(int lnValveLaneIndex, int lnStartSegmentInput, int lnEndSegmentInput, int lePlayerIndex,
                                      CB3StartFinishLine *laStartLinePos, int lnNumStartLines, bool lbIsHullFill)
{
    unsigned long lTrailerID = 0;
    unsigned char lu8TrailerColour = 0;
    UnkStruct_00266AE0_lane *lpLane = func_00266AE0_lane(field_40->field_0[lnValveLaneIndex]);
    if (field_40->field_C & 2)
        return;
    int lnStartSegment;
    int lnEndSegment;
    if (lnStartSegmentInput < lnEndSegmentInput) {
        lnStartSegment = lnStartSegmentInput;
        lnEndSegment = lnEndSegmentInput;
    } else {
        lnStartSegment = lnEndSegmentInput;
        lnEndSegment = lnStartSegmentInput;
    }
    float lrLaneSectionLength;
    if (lbIsHullFill) {
        unsigned char lu8ParamIndex = D_0055D7DC.field_0[lpLane->field_4 + lnStartSegment];
        UnkStruct_00266AE0_param *lpPrevParam = 0;
        int lnNextParamSegment;
        if (lu8ParamIndex != 255) {
            UnkStruct_00266AE0_param *lpNextParam = func_00266AE0_param(lu8ParamIndex);
            lnNextParamSegment = (int)lpNextParam->field_30;
            lpPrevParam = func_00266AE0_param(lpNextParam->field_45);
        } else {
            lnNextParamSegment = lpLane->field_0->field_10 - 1;
            lpPrevParam = func_00266AE0_param(lpLane->field_46);
        }
        int lnPrevParamSegment;
        if (lpPrevParam == 0)
            lnPrevParamSegment = 0;
        else
            lnPrevParamSegment = (int)lpPrevParam->field_30;
        if (lnNextParamSegment < lnEndSegment)
            lrLaneSectionLength = lpLane->field_0->field_4[lnEndSegment].field_0 - lpLane->field_0->field_4[lnStartSegment].field_0;
        else if (lnNextParamSegment - lnEndSegment < lnStartSegment - lnPrevParamSegment)
            lrLaneSectionLength = lpLane->field_0->field_4[lnNextParamSegment].field_0 - lpLane->field_0->field_4[lnStartSegment].field_0;
        else
            lrLaneSectionLength = lpLane->field_0->field_4[lnEndSegment].field_0 - lpLane->field_0->field_4[lnPrevParamSegment].field_0;
    } else {
        lrLaneSectionLength = lpLane->field_0->field_4[lnEndSegment].field_0 - lpLane->field_0->field_4[lnStartSegment].field_0;
    }

    float lrTotalLaneFlow = 0.0f;
    for (int k = 0; k < 6; k++)
        lrTotalLaneFlow += field_10[lnValveLaneIndex][k];
    if (lrTotalLaneFlow <= 0.0f)
        return;
    float lrLaneSpeed = 0.44704f * field_0[lnValveLaneIndex]->field_0;
    if (lrLaneSpeed <= 0.0f)
        return;
    float lrTraversalTime = lrLaneSectionLength / lrLaneSpeed;
    float lrCarCount = lrTotalLaneFlow * (lrTraversalTime / 60.0f);
    if (lrCarCount < 0.5f)
        return;
    float lrMetresPerVehicle = lrLaneSectionLength / lrCarCount;
    int lnNumVehiclesToGenerate = (int)(lrCarCount + 0.5f);
    for (int lnGenerationIndex = 0; lnGenerationIndex < lnNumVehiclesToGenerate; lnGenerationIndex++) {
        float lrVehicleGap;
        if (D_0055D7F7.field_0 == 0 && D_0055D7F8.field_0 == 0)
            lrVehicleGap = lrMetresPerVehicle * D_0055D788.r.RandomReal();
        else
            lrVehicleGap = lrMetresPerVehicle;
        float lrParamAlong = (float)lnStartSegment + GetParamFromDist__14CB3TrafficLaneFf(lpLane, lrVehicleGap * (float)lnGenerationIndex);
        float lrRandom = (D_0055D788.r.RandomReal() - 0.5f) * 2.0f;
        lrParamAlong = 0.0f + lrParamAlong + lrRandom * (0.3f * lrParamAlong);
        if (lrParamAlong < (float)lnStartSegment)
            lrParamAlong = (float)lnStartSegment;
        if (!(lrParamAlong <= (float)lnEndSegment))
            lrParamAlong = (float)lnEndSegment;

        UnkStruct_00266AE0_lane *lane = func_00266AE0_lane(field_40->field_0[lnValveLaneIndex]);
        int lnNextSegment = (int)lrParamAlong;
        bool ok;
        if (lnNextSegment < lane->field_0->field_10) {
            if (lnNextSegment == 0 && field_114 != 0)
                ok = true;
            else
                ok = !D_00527440.IsSegmentLocked(lePlayerIndex, (unsigned short)(lnNextSegment + lane->field_4));
        } else {
            ok = false;
        }
        if (!ok)
            continue;

        float lrPick = lrTotalLaneFlow * D_0055D788.r.RandomReal();
        int lnVehicleCategoryIndex;
        float lrSum = 0.0f;
        for (lnVehicleCategoryIndex = 0; lnVehicleCategoryIndex < 6; lnVehicleCategoryIndex++) {
            if (lnVehicleCategoryIndex == 11)
                continue;
            lrSum += field_10[lnValveLaneIndex][lnVehicleCategoryIndex];
            if (!(lrSum <= lrPick))
                goto found;
        }
        lnVehicleCategoryIndex = 1;
    found:
        unsigned long lVehicleID;
        unsigned char lu8VehicleColour;
        if (field_40->field_C & 2) {
            unsigned char fl = field_40->field_D;
            UnkStruct_00266AE0_tbl *tb = D_00527440.field_0;
            if (fl & 1)
                lVehicleID = tb->field_0[0];
            else if (fl & 2)
                lVehicleID = tb->field_0[1];
            else if (fl & 4)
                lVehicleID = tb->field_0[2];
            else if (fl & 8)
                lVehicleID = tb->field_0[3];
            else if (fl & 0x10)
                lVehicleID = tb->field_0[4];
            else
                lVehicleID = 0;
            lu8VehicleColour = 0;
        } else {
            UnkStruct_00266AE0_ent *e = GetRandomVehicleID((ETrafficVehicleCategories)lnVehicleCategoryIndex);
            unsigned int r = D_0055D788.r.Random();
            lVehicleID = e->field_0;
            lu8VehicleColour = func_00266AE0_colour(e, r);
        }
        int leTrailerClass;
        if (lnVehicleCategoryIndex == 4) {
            leTrailerClass = 11;
            UnkStruct_00266AE0_ent *e = GetRandomVehicleID((ETrafficVehicleCategories)leTrailerClass);
            unsigned int r = D_0055D788.r.Random();
            lTrailerID = e->field_0;
            lu8TrailerColour = func_00266AE0_colour(e, r);
        } else {
            leTrailerClass = 0;
        }
        UnkStruct_00266AE0_veh *lpTrafficVehicle = D_00527440.Generate(
            (ETrafficVehicleCategories)lnVehicleCategoryIndex, lVehicleID, (ETrafficVehicleCategories)leTrailerClass, lTrailerID,
            (CB3TrafficLane *)lpLane, lrParamAlong, field_0[lnValveLaneIndex]->field_0,
            field_10[lnValveLaneIndex][lnVehicleCategoryIndex], lu8VehicleColour, lu8TrailerColour, 0);
        if (lpTrafficVehicle == 0)
            return;
        UnkStruct_00266AE0_param *o = lpTrafficVehicle->field_114;
        if (field_20[lnValveLaneIndex]->field_10 > 0) {
            o->field_47 = field_10C[lnValveLaneIndex];
            field_10C[lnValveLaneIndex] = field_10C[lnValveLaneIndex] + 1;
            field_10C[lnValveLaneIndex] = field_10C[lnValveLaneIndex] % (unsigned int)field_20[lnValveLaneIndex]->field_10;   // [C] divu in retail
            if (field_20[lnValveLaneIndex] == 0)
                o->field_47 = 0xFF;
            lpTrafficVehicle->field_114->field_38 = field_20[lnValveLaneIndex];
        } else {
            o->field_47 = 0xFF;
            lpTrafficVehicle->field_114->field_38 = 0;
        }
        lpTrafficVehicle->field_114->field_0 = field_0[lnValveLaneIndex]->field_0;
        func_00160B40(lpTrafficVehicle->field_114);
        for (int lnStartLineIndex = 0; lnStartLineIndex < lnNumStartLines; lnStartLineIndex++) {
            CGtV3d d = *laStartLinePos[lnStartLineIndex].field_0 - lpTrafficVehicle->field_A0;
            d.SetY(0.0f);
            if ((float)d.GetLength() < 160.0f) {
                func_00173D30(lpTrafficVehicle);
                break;
            }
        }
    }
}
