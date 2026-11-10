// CB3CameraAttribsCar::RegisterVariables() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3CameraAttribs.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (near20: header CGtV3d::Set(float,float,float) for all six vectors (stand-ins dropped) + .lit4 externs written as literals).

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

struct UnkStruct_gVdbDatabase { int field_0; };
extern UnkStruct_gVdbDatabase mpToolBase__Q27GtComms16CGtCommsToolBase;
extern char kacPathPrefixCamera[];
extern char D_004C44A0[];
extern char D_004C44A8[];
extern char D_004C44B8[];
extern char D_004C44D0[];
extern char D_004C44E8[];
extern char D_004C44F8[];
extern char D_004C4300[];
extern char D_004C4508[];
extern "C" void func_0021AB40(unsigned long, char *);
extern "C" char * strcpy(char *, const char *);
extern "C" char * strcat(char *, const char *);
extern "C" void AddEntry__Q27GtComms16CGtCommsDatabaseFPQ29GtMathPs26CGtV3dPCcPCcPCc(int, void *, void *, void *, void *);
extern "C" void AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(int, void *, void *, void *, void *, int, int, float, float);

class CB3CameraAttribsCar {
public:
    void RegisterVariables();
    void SetRaceCarPath();

    CGtV3d field_0;
    CGtV3d field_10;
    unsigned char pad_20[0x10];
    CGtV3d field_30;
    CGtV3d field_40;
    unsigned char pad_50[0x10];
    CGtV3d field_60;
    CGtV3d field_70;
    CGtV3d field_80;
    float field_90;
    unsigned char pad_94[0xC];
    unsigned long field_A0;
    char field_A8[0x108];
};

inline void CB3CameraAttribsCar::SetRaceCarPath()
{
    char buf[16];
    func_0021AB40(field_A0, buf);
    strcpy(field_A8, kacPathPrefixCamera);
    strcat(field_A8, buf);
    strcat(field_A8, D_004C44A0);
}
// 0x002F8870
void CB3CameraAttribsCar::RegisterVariables()
{
    SetRaceCarPath();
    field_30.Set(0.0f, 0.0f, 0.0f);
    field_40.Set(0.0f, 0.0f, 0.0f);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPQ29GtMathPs26CGtV3dPCcPCcPCc(mpToolBase__Q27GtComms16CGtCommsToolBase.field_0 + 16, &field_30, D_004C44A8, D_004C44B8, field_A8);
    field_0.Set(0.0f, 0.0f, 0.0f);
    field_10.Set(0.0f, 0.0f, 0.0f);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPQ29GtMathPs26CGtV3dPCcPCcPCc(mpToolBase__Q27GtComms16CGtCommsToolBase.field_0 + 16, &field_0, D_004C44A8, D_004C44D0, field_A8);
    field_60.Set(0.0f, 0.95f, -6.8f);
    field_70.Set(0.0f, 0.35f, 2.0f);
    field_80.Set(0.06f, 0.1f, 5.0f);
    field_90 = 1.8f;
    AddEntry__Q27GtComms16CGtCommsDatabaseFPQ29GtMathPs26CGtV3dPCcPCcPCc(mpToolBase__Q27GtComms16CGtCommsToolBase.field_0 + 16, &field_60, D_004C44A8, D_004C44E8, field_A8);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPQ29GtMathPs26CGtV3dPCcPCcPCc(mpToolBase__Q27GtComms16CGtCommsToolBase.field_0 + 16, &field_70, D_004C44F8, D_004C44E8, field_A8);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPQ29GtMathPs26CGtV3dPCcPCcPCc(mpToolBase__Q27GtComms16CGtCommsToolBase.field_0 + 16, &field_80, D_004C4300, D_004C44E8, field_A8);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase.field_0 + 16, &field_90, D_004C4508, D_004C44E8, field_A8, 0, 0, 0.0f, 0.0f);
}
