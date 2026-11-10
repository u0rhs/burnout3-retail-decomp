// CB3CameraAttribs::RegisterVariables() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3CameraAttribs.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (draftAK: C-first from a symbolic evaluator of the lane sets / stores / vdb calls (retail keeps 0.0 lanes in VU registers across the calls, so field_110/140 are (0,0,-20)/(0,0,20)); exact 639/639, relocs OK).

// CB3CameraAttribs::RegisterVariables() -- draftAK (C-first draft). 0x2F7E70, 0x9FC.
// [C] name: the mangled symbol in retail's tables. Written from the retail asm with a small symbolic evaluator (the lane sets,
// float stores and vdb calls in order); shapes from the proven sibling CB3CameraAttribsCar::RegisterVariables
// (B3CameraAttribs_002F8870.cpp). What it does [L]: builds the attribs' ValueDB path (kacPathPrefixCamera + D_004C42F0), sets
// the defaults of 32 vectors and two floats and registers each with the debug value database under its group/name strings.
// [C] retail keeps the 0.0 lanes of field_B0 / field_E0 in $vf5 across the vdb calls (vmove $vf9,$vf5): their x, y are 0.
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

struct UnkStruct_gVdbDatabase { int field_0; };
extern UnkStruct_gVdbDatabase mpToolBase__Q27GtComms16CGtCommsToolBase;
extern char kacPathPrefixCamera[];
extern char D_004C42F0[];
extern char D_004C4300[];
extern char D_004C4310[];
extern char D_004C4320[];
extern char D_004C4328[];
extern char D_004C4338[];
extern char D_004C4350[];
extern char D_004C4370[];
extern char D_004C4380[];
extern char D_004C43A0[];
extern char D_004C43C0[];
extern char D_004C43E0[];
extern char D_004C4400[];
extern char D_004C4420[];
extern char D_004C4440[];
extern char D_004C4460[];
extern char D_004C4480[];
extern "C" char * strcpy(char *, const char *);
extern "C" char * strcat(char *, const char *);
extern "C" void AddEntry__Q27GtComms16CGtCommsDatabaseFPQ29GtMathPs26CGtV3dPCcPCcPCc(int, void *, void *, void *, void *);
extern "C" void AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(int, void *, void *, void *, void *, int, int, float, float);

class CB3CameraAttribs {
public:
    void RegisterVariables();

    CGtV3d field_0;
    CGtV3d field_10;
    float field_20;
    float field_24;
    unsigned char pad_28[0x8];
    CGtV3d field_30;
    CGtV3d field_40;
    CGtV3d field_50;
    CGtV3d field_60;
    CGtV3d field_70;
    CGtV3d field_80;
    CGtV3d field_90;
    CGtV3d field_A0;
    CGtV3d field_B0;
    CGtV3d field_C0;
    CGtV3d field_D0;
    CGtV3d field_E0;
    CGtV3d field_F0;
    CGtV3d field_100;
    CGtV3d field_110;
    CGtV3d field_120;
    CGtV3d field_130;
    CGtV3d field_140;
    CGtV3d field_150;
    CGtV3d field_160;
    CGtV3d field_170;
    CGtV3d field_180;
    CGtV3d field_190;
    CGtV3d field_1A0;
    CGtV3d field_1B0;
    CGtV3d field_1C0;
    CGtV3d field_1D0;
    CGtV3d field_1E0;
    CGtV3d field_1F0;
    CGtV3d field_200;
    unsigned char pad_210[0x30];
    char field_240[0x100];
};

// 0x002F7E70
void CB3CameraAttribs::RegisterVariables()
{
    strcpy(field_240, kacPathPrefixCamera);
    strcat(field_240, D_004C42F0);
    field_0.Set(15.0f, 15.0f, 15.0f);
    field_10.Set(10.0f, 10.0f, 10.0f);
    field_20 = 0.1f;
    field_24 = 0.5f;
    AddEntry__Q27GtComms16CGtCommsDatabaseFPQ29GtMathPs26CGtV3dPCcPCcPCc(mpToolBase__Q27GtComms16CGtCommsToolBase.field_0 + 16, &field_0, D_004C4300, D_004C4310, field_240);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPQ29GtMathPs26CGtV3dPCcPCcPCc(mpToolBase__Q27GtComms16CGtCommsToolBase.field_0 + 16, &field_10, D_004C4320, D_004C4310, field_240);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase.field_0 + 16, &field_20, D_004C4328, D_004C4310, field_240, 0, 0, 0.0f, 0.0f);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase.field_0 + 16, &field_24, D_004C4338, D_004C4310, field_240, 0, 0, 0.0f, 0.0f);
    field_30.Set(15.0f, 15.0f, 15.0f);
    field_40.Set(10.0f, 10.0f, 10.0f);
    field_50.Set(0.0f, 0.0f, 50.0f);
    field_60.Set(150.0f, 150.0f, 150.0f);
    field_70.Set(1.0f, 1.0f, 1.0f);
    field_80.Set(0.0f, 0.0f, 0.0f);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPQ29GtMathPs26CGtV3dPCcPCcPCc(mpToolBase__Q27GtComms16CGtCommsToolBase.field_0 + 16, &field_30, D_004C4300, D_004C4350, field_240);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPQ29GtMathPs26CGtV3dPCcPCcPCc(mpToolBase__Q27GtComms16CGtCommsToolBase.field_0 + 16, &field_40, D_004C4320, D_004C4350, field_240);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPQ29GtMathPs26CGtV3dPCcPCcPCc(mpToolBase__Q27GtComms16CGtCommsToolBase.field_0 + 16, &field_50, D_004C4370, D_004C4350, field_240);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPQ29GtMathPs26CGtV3dPCcPCcPCc(mpToolBase__Q27GtComms16CGtCommsToolBase.field_0 + 16, &field_60, D_004C4300, D_004C4380, field_240);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPQ29GtMathPs26CGtV3dPCcPCcPCc(mpToolBase__Q27GtComms16CGtCommsToolBase.field_0 + 16, &field_70, D_004C4320, D_004C4380, field_240);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPQ29GtMathPs26CGtV3dPCcPCcPCc(mpToolBase__Q27GtComms16CGtCommsToolBase.field_0 + 16, &field_80, D_004C4370, D_004C4380, field_240);
    field_90.Set(15.0f, 15.0f, 15.0f);
    field_A0.Set(10.0f, 10.0f, 10.0f);
    field_B0.Set(0.0f, 0.0f, 20.0f);
    field_C0.Set(15.0f, 15.0f, 15.0f);
    field_D0.Set(10.0f, 10.0f, 10.0f);
    field_E0.Set(0.0f, 0.0f, 20.0f);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPQ29GtMathPs26CGtV3dPCcPCcPCc(mpToolBase__Q27GtComms16CGtCommsToolBase.field_0 + 16, &field_90, D_004C4300, D_004C43A0, field_240);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPQ29GtMathPs26CGtV3dPCcPCcPCc(mpToolBase__Q27GtComms16CGtCommsToolBase.field_0 + 16, &field_A0, D_004C4320, D_004C43A0, field_240);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPQ29GtMathPs26CGtV3dPCcPCcPCc(mpToolBase__Q27GtComms16CGtCommsToolBase.field_0 + 16, &field_B0, D_004C4370, D_004C43A0, field_240);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPQ29GtMathPs26CGtV3dPCcPCcPCc(mpToolBase__Q27GtComms16CGtCommsToolBase.field_0 + 16, &field_C0, D_004C4300, D_004C43C0, field_240);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPQ29GtMathPs26CGtV3dPCcPCcPCc(mpToolBase__Q27GtComms16CGtCommsToolBase.field_0 + 16, &field_D0, D_004C4320, D_004C43C0, field_240);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPQ29GtMathPs26CGtV3dPCcPCcPCc(mpToolBase__Q27GtComms16CGtCommsToolBase.field_0 + 16, &field_E0, D_004C4370, D_004C43C0, field_240);
    field_F0.Set(15.0f, 15.0f, 15.0f);
    field_100.Set(10.0f, 10.0f, 10.0f);
    field_110.Set(0.0f, 0.0f, -20.0f);
    field_120.Set(15.0f, 15.0f, 15.0f);
    field_130.Set(10.0f, 10.0f, 10.0f);
    field_140.Set(0.0f, 0.0f, 20.0f);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPQ29GtMathPs26CGtV3dPCcPCcPCc(mpToolBase__Q27GtComms16CGtCommsToolBase.field_0 + 16, &field_F0, D_004C4300, D_004C43E0, field_240);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPQ29GtMathPs26CGtV3dPCcPCcPCc(mpToolBase__Q27GtComms16CGtCommsToolBase.field_0 + 16, &field_100, D_004C4320, D_004C43E0, field_240);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPQ29GtMathPs26CGtV3dPCcPCcPCc(mpToolBase__Q27GtComms16CGtCommsToolBase.field_0 + 16, &field_110, D_004C4370, D_004C43E0, field_240);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPQ29GtMathPs26CGtV3dPCcPCcPCc(mpToolBase__Q27GtComms16CGtCommsToolBase.field_0 + 16, &field_120, D_004C4300, D_004C4400, field_240);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPQ29GtMathPs26CGtV3dPCcPCcPCc(mpToolBase__Q27GtComms16CGtCommsToolBase.field_0 + 16, &field_130, D_004C4320, D_004C4400, field_240);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPQ29GtMathPs26CGtV3dPCcPCcPCc(mpToolBase__Q27GtComms16CGtCommsToolBase.field_0 + 16, &field_140, D_004C4370, D_004C4400, field_240);
    field_150.Set(15.0f, 15.0f, 15.0f);
    field_160.Set(10.0f, 10.0f, 10.0f);
    field_170.Set(0.0f, 0.0f, 0.0f);
    field_180.Set(15.0f, 15.0f, 15.0f);
    field_190.Set(10.0f, 10.0f, 10.0f);
    field_1A0.Set(0.0f, 0.0f, 20.0f);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPQ29GtMathPs26CGtV3dPCcPCcPCc(mpToolBase__Q27GtComms16CGtCommsToolBase.field_0 + 16, &field_150, D_004C4300, D_004C4420, field_240);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPQ29GtMathPs26CGtV3dPCcPCcPCc(mpToolBase__Q27GtComms16CGtCommsToolBase.field_0 + 16, &field_160, D_004C4320, D_004C4420, field_240);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPQ29GtMathPs26CGtV3dPCcPCcPCc(mpToolBase__Q27GtComms16CGtCommsToolBase.field_0 + 16, &field_170, D_004C4370, D_004C4420, field_240);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPQ29GtMathPs26CGtV3dPCcPCcPCc(mpToolBase__Q27GtComms16CGtCommsToolBase.field_0 + 16, &field_180, D_004C4300, D_004C4440, field_240);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPQ29GtMathPs26CGtV3dPCcPCcPCc(mpToolBase__Q27GtComms16CGtCommsToolBase.field_0 + 16, &field_190, D_004C4320, D_004C4440, field_240);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPQ29GtMathPs26CGtV3dPCcPCcPCc(mpToolBase__Q27GtComms16CGtCommsToolBase.field_0 + 16, &field_1A0, D_004C4370, D_004C4440, field_240);
    field_1B0.Set(15.0f, 15.0f, 15.0f);
    field_1C0.Set(10.0f, 10.0f, 10.0f);
    field_1D0.Set(0.0f, 0.0f, 0.0f);
    field_1E0.Set(15.0f, 15.0f, 15.0f);
    field_1F0.Set(10.0f, 10.0f, 10.0f);
    field_200.Set(0.0f, 0.0f, 20.0f);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPQ29GtMathPs26CGtV3dPCcPCcPCc(mpToolBase__Q27GtComms16CGtCommsToolBase.field_0 + 16, &field_1B0, D_004C4300, D_004C4460, field_240);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPQ29GtMathPs26CGtV3dPCcPCcPCc(mpToolBase__Q27GtComms16CGtCommsToolBase.field_0 + 16, &field_1C0, D_004C4320, D_004C4460, field_240);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPQ29GtMathPs26CGtV3dPCcPCcPCc(mpToolBase__Q27GtComms16CGtCommsToolBase.field_0 + 16, &field_1D0, D_004C4370, D_004C4460, field_240);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPQ29GtMathPs26CGtV3dPCcPCcPCc(mpToolBase__Q27GtComms16CGtCommsToolBase.field_0 + 16, &field_1E0, D_004C4300, D_004C4480, field_240);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPQ29GtMathPs26CGtV3dPCcPCcPCc(mpToolBase__Q27GtComms16CGtCommsToolBase.field_0 + 16, &field_1F0, D_004C4320, D_004C4480, field_240);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPQ29GtMathPs26CGtV3dPCcPCcPCc(mpToolBase__Q27GtComms16CGtCommsToolBase.field_0 + 16, &field_200, D_004C4370, D_004C4480, field_240);
}
