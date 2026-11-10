// CB3SoundRaceCarManager::Construct() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundRaceCarManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (generated from the retail call table: 126 AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi calls in retail order; byte-table stores written in retail's store order).

struct UnkStruct_002ED690_e2 {
    unsigned char pad_0[0xB8];
    int field_B8;
    unsigned char pad_BC[0xDC];
};

struct UnkStruct_002ED690_e3 {
    unsigned char pad_0[0xB8];
    int field_B8;
    unsigned char pad_BC[0xA4];
};

struct UnkStruct_002ED690_s {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

// [G] layout from the offsets: twelve float[10] tables indexed by surface type (each registered once per
// kpc*SurfaceVarDir), a byte table at 0x1E8, then the player-car (stride 0x198) and AI-car (stride 0x160)
// sound objects whose +0xB8 int receives the slot index.
class CB3SoundRaceCarManager {
public:
    void Construct();

    float field_0[10];
    float field_28[10];
    float field_50[10];
    float field_78[10];
    float field_A0[10];
    float field_C8[10];
    float field_F0[10];
    float field_118[10];
    float field_140[10];
    float field_168[10];
    float field_190[10];
    float field_1B8[10];
    unsigned char pad_1E0[0x8];
    unsigned char field_1E8[0x28];
    UnkStruct_002ED690_e2 field_210[2];
    UnkStruct_002ED690_e3 field_540[5];
};

extern float _grVolumeTailoffStartSpeedPercent;
extern float _grVolumeTailoffEndSpeedPercent;
extern float D_004E1CE8;
extern float D_004E1CDC;
extern float D_004E1CD0;
extern float _grVolumeTailoffEndVolume;
extern float D_004E1CD8;
extern int D_004E1CEC;
extern int kpcMiscVarDir;
extern int D_004E1C9C;
extern int kpcNoSurfaceVarDir;
extern int kpcSurfaceVDBFile;
extern int kpcTarmacSurfaceVarDir;
extern int kpcConcreteSurfaceVarDir;
extern int kpcOfflineTarmacSurfaceVarDir;
extern int kpcGravelSurfaceVarDir;
extern int kpcOfflineGravelSurfaceVarDir;
extern int kpcPavementSurfaceVarDir;
extern int kpcSnowSurfaceVarDir;
extern int kpcMetalSurfaceVarDir;
extern int kpcWoodSurfaceVarDir;
extern int mpToolBase__Q27GtComms16CGtCommsToolBase;
extern UnkStruct_002ED690_s D_004C3E40;
extern UnkStruct_002ED690_s D_004C3E70;
extern UnkStruct_002ED690_s D_004C3E90;
extern UnkStruct_002ED690_s D_004C3EA0;
extern UnkStruct_002ED690_s D_004C3EC0;
extern UnkStruct_002ED690_s D_004C3EE0;
extern UnkStruct_002ED690_s D_004C3F00;
extern UnkStruct_002ED690_s D_004C3F20;
extern UnkStruct_002ED690_s D_004C3F38;
extern UnkStruct_002ED690_s D_004C3F48;
extern UnkStruct_002ED690_s D_004C3F60;
extern UnkStruct_002ED690_s D_004C3F80;
extern UnkStruct_002ED690_s D_004C3F98;
extern UnkStruct_002ED690_s D_004C3FA8;
extern UnkStruct_002ED690_s D_004C3FB8;
extern UnkStruct_002ED690_s D_004C3FC0;
extern UnkStruct_002ED690_s D_004C3FC8;
extern UnkStruct_002ED690_s D_004C3FD8;
extern "C" void AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(int, void *, void *, int, int, int, float, float, int);
extern "C" void func_0028CD10(void *);
extern "C" void Construct__13CB3SoundAICarFv(void *);  // CB3SoundAICar::Construct()

// 0x002ED690
void CB3SoundRaceCarManager::Construct()
{
    unsigned int i;
    for (i = 0; i < 2; i++) {
        func_0028CD10(&field_210[i]);
        field_210[i].field_B8 = i;
    }
    for (i = 0; i < 5; i++) {
        Construct__13CB3SoundAICarFv(&field_540[i]);
        field_540[i].field_B8 = i;
    }
    for (i = 0; i < 10; i++) {
        field_0[i] = 0.0f;
        field_28[i] = 100.0f;
        field_50[i] = 0.0f;
        field_78[i] = 1.0f;
        field_A0[i] = 0.5f;
        field_C8[i] = 1.0f;
        field_F0[i] = 0.0f;
        field_118[i] = 100.0f;
        field_140[i] = 0.0f;
        field_168[i] = 1.0f;
        field_190[i] = 0.5f;
        field_1B8[i] = 1.0f;
    }
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &_grVolumeTailoffStartSpeedPercent, &D_004C3E40, kpcMiscVarDir, D_004E1C9C, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &_grVolumeTailoffEndSpeedPercent, &D_004C3E70, kpcMiscVarDir, D_004E1C9C, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &D_004E1CE8, &D_004C3E90, kpcMiscVarDir, D_004E1C9C, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &D_004E1CDC, &D_004C3EA0, kpcMiscVarDir, D_004E1C9C, 0, 0.0f, 0.0f, 0);
    D_004E1CDC *= D_004E1CD8;
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &D_004E1CD0, &D_004C3EC0, kpcMiscVarDir, D_004E1C9C, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &_grVolumeTailoffEndVolume, &D_004C3EE0, kpcMiscVarDir, D_004E1C9C, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, field_0, &D_004C3F00, kpcNoSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_28[0], &D_004C3F20, kpcNoSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_50[0], &D_004C3F38, kpcNoSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_78[0], &D_004C3F48, kpcNoSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_A0[0], &D_004C3F60, kpcNoSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_C8[0], &D_004C3F80, kpcNoSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_0[1], &D_004C3F00, kpcTarmacSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_28[1], &D_004C3F20, kpcTarmacSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_50[1], &D_004C3F38, kpcTarmacSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_78[1], &D_004C3F48, kpcTarmacSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_A0[1], &D_004C3F60, kpcTarmacSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_C8[1], &D_004C3F80, kpcTarmacSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_0[2], &D_004C3F00, kpcConcreteSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_28[2], &D_004C3F20, kpcConcreteSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_50[2], &D_004C3F38, kpcConcreteSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_78[2], &D_004C3F48, kpcConcreteSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_A0[2], &D_004C3F60, kpcConcreteSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_C8[2], &D_004C3F80, kpcConcreteSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_0[3], &D_004C3F00, kpcOfflineTarmacSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_28[3], &D_004C3F20, kpcOfflineTarmacSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_50[3], &D_004C3F38, kpcOfflineTarmacSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_78[3], &D_004C3F48, kpcOfflineTarmacSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_A0[3], &D_004C3F60, kpcOfflineTarmacSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_C8[3], &D_004C3F80, kpcOfflineTarmacSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_0[4], &D_004C3F00, kpcGravelSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_28[4], &D_004C3F20, kpcGravelSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_50[4], &D_004C3F38, kpcGravelSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_78[4], &D_004C3F48, kpcGravelSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_A0[4], &D_004C3F60, kpcGravelSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_C8[4], &D_004C3F80, kpcGravelSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_0[7], &D_004C3F00, kpcOfflineGravelSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_28[7], &D_004C3F20, kpcOfflineGravelSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_50[7], &D_004C3F38, kpcOfflineGravelSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_78[7], &D_004C3F48, kpcOfflineGravelSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_A0[7], &D_004C3F60, kpcOfflineGravelSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_C8[7], &D_004C3F80, kpcOfflineGravelSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_0[5], &D_004C3F00, kpcPavementSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_28[5], &D_004C3F20, kpcPavementSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_50[5], &D_004C3F38, kpcPavementSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_78[5], &D_004C3F48, kpcPavementSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_A0[5], &D_004C3F60, kpcPavementSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_C8[5], &D_004C3F80, kpcPavementSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_0[6], &D_004C3F00, kpcSnowSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_28[6], &D_004C3F20, kpcSnowSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_50[6], &D_004C3F38, kpcSnowSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_78[6], &D_004C3F48, kpcSnowSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_A0[6], &D_004C3F60, kpcSnowSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_C8[6], &D_004C3F80, kpcSnowSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_0[8], &D_004C3F00, kpcMetalSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_28[8], &D_004C3F20, kpcMetalSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_50[8], &D_004C3F38, kpcMetalSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_78[8], &D_004C3F48, kpcMetalSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_A0[8], &D_004C3F60, kpcMetalSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_C8[8], &D_004C3F80, kpcMetalSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_0[9], &D_004C3F00, kpcWoodSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_28[9], &D_004C3F20, kpcWoodSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_50[9], &D_004C3F38, kpcWoodSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_78[9], &D_004C3F48, kpcWoodSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_A0[9], &D_004C3F60, kpcWoodSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_C8[9], &D_004C3F80, kpcWoodSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_F0[0], &D_004C3F98, kpcNoSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_118[0], &D_004C3FA8, kpcNoSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_140[0], &D_004C3FB8, kpcNoSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_168[0], &D_004C3FC0, kpcNoSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_190[0], &D_004C3FC8, kpcNoSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_1B8[0], &D_004C3FD8, kpcNoSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_F0[1], &D_004C3F98, kpcTarmacSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_118[1], &D_004C3FA8, kpcTarmacSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_140[1], &D_004C3FB8, kpcTarmacSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_168[1], &D_004C3FC0, kpcTarmacSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_190[1], &D_004C3FC8, kpcTarmacSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_1B8[1], &D_004C3FD8, kpcTarmacSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_F0[2], &D_004C3F98, kpcConcreteSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_118[2], &D_004C3FA8, kpcConcreteSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_140[2], &D_004C3FB8, kpcConcreteSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_168[2], &D_004C3FC0, kpcConcreteSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_190[2], &D_004C3FC8, kpcConcreteSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_1B8[2], &D_004C3FD8, kpcConcreteSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_F0[3], &D_004C3F98, kpcOfflineTarmacSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_118[3], &D_004C3FA8, kpcOfflineTarmacSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_140[3], &D_004C3FB8, kpcOfflineTarmacSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_168[3], &D_004C3FC0, kpcOfflineTarmacSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_190[3], &D_004C3FC8, kpcOfflineTarmacSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_1B8[3], &D_004C3FD8, kpcOfflineTarmacSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_F0[4], &D_004C3F98, kpcGravelSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_118[4], &D_004C3FA8, kpcGravelSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_140[4], &D_004C3FB8, kpcGravelSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_168[4], &D_004C3FC0, kpcGravelSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_190[4], &D_004C3FC8, kpcGravelSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_1B8[4], &D_004C3FD8, kpcGravelSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_F0[7], &D_004C3F98, kpcOfflineGravelSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_118[7], &D_004C3FA8, kpcOfflineGravelSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_140[7], &D_004C3FB8, kpcOfflineGravelSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_168[7], &D_004C3FC0, kpcOfflineGravelSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_190[7], &D_004C3FC8, kpcOfflineGravelSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_1B8[7], &D_004C3FD8, kpcOfflineGravelSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_F0[5], &D_004C3F98, kpcPavementSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_118[5], &D_004C3FA8, kpcPavementSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_140[5], &D_004C3FB8, kpcPavementSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_168[5], &D_004C3FC0, kpcPavementSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_190[5], &D_004C3FC8, kpcPavementSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_1B8[5], &D_004C3FD8, kpcPavementSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_F0[6], &D_004C3F98, kpcSnowSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_118[6], &D_004C3FA8, kpcSnowSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_140[6], &D_004C3FB8, kpcSnowSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_168[6], &D_004C3FC0, kpcSnowSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_190[6], &D_004C3FC8, kpcSnowSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_1B8[6], &D_004C3FD8, kpcSnowSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_F0[8], &D_004C3F98, kpcMetalSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_118[8], &D_004C3FA8, kpcMetalSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_140[8], &D_004C3FB8, kpcMetalSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_168[8], &D_004C3FC0, kpcMetalSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_190[8], &D_004C3FC8, kpcMetalSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_1B8[8], &D_004C3FD8, kpcMetalSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_F0[9], &D_004C3F98, kpcWoodSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_118[9], &D_004C3FA8, kpcWoodSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_140[9], &D_004C3FB8, kpcWoodSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_168[9], &D_004C3FC0, kpcWoodSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_190[9], &D_004C3FC8, kpcWoodSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_1B8[9], &D_004C3FD8, kpcWoodSurfaceVarDir, kpcSurfaceVDBFile, 0, 0.0f, 0.0f, 0);
    field_1E8[0] = 0;
    field_1E8[1] = 1;
    field_1E8[3] = 1;
    field_1E8[12] = 1;
    field_1E8[4] = 4;
    field_1E8[5] = 4;
    field_1E8[2] = 2;
    field_1E8[13] = 2;
    field_1E8[14] = 4;
    field_1E8[15] = 4;
    field_1E8[16] = 4;
    field_1E8[37] = 4;
    field_1E8[8] = 5;
    field_1E8[17] = 5;
    field_1E8[11] = 6;
    field_1E8[19] = 6;
    field_1E8[6] = 9;
    field_1E8[7] = 9;
    field_1E8[9] = 9;
    field_1E8[20] = 9;
    field_1E8[10] = 8;
    if (D_004E1CEC == -1) {
        D_004E1CEC = 0;
    }
}
