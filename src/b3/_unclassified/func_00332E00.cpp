// BUILD-HOST: wine
// N165 [C]: temporary exception -- this source matches retail only under wine; under the reference host
// (native Windows / wibo) two registers swap. To do: re-shape the source to match natively, then drop the marker.
// Prepare__14CB3StaticTrackFv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (rewritten from asm: switch 1/24 -> 2 fallthrough, 3, 22, 23 (MWCC reuses the 22 compare register for the case-3 store); || shares the return 1; name/path buffers in declaration order).

// lifter variant 0
// Prepare__14CB3StaticTrackFv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

class CAsyncLoadManager;
class CB3StaticTrackData;
class CB3TrackList;
struct UnkStruct_00332E00;
struct UnkStruct_00332E00_2;
struct UnkStruct_00332E00_e1;
struct UnkStruct_D_004C5770;
struct UnkStruct_D_004C5778;
struct UnkStruct_D_004C5790;
struct UnkStruct_D_004C57A8;
struct UnkStruct_D_004C57B8;
struct UnkStruct_D_0064D370;
struct UnkStruct_D_01EA3240;
struct UnkStruct_gVdbDatabase;
struct UnkStruct_kpacTrackBloomParamsPath;
struct UnkStruct_theMemMgr;

class CB3TrackList {
public:
    void CreateTrackPathFromID(unsigned long, char*, int);
    int GetTrackIndexFromID(unsigned long);
    void CreateTrackPathFromIndex(int, char*, int);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CAsyncLoadManager {
public:
    int QueueLoadRequest(const char*, bool*, void*, unsigned int);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3TrackMaterial {
public:
    void Prepare();
    unsigned char pad_0[0x28];  // [G] size: element stride 0x28 (lh index * 40)
};

class CB3StaticTrackData {
public:
    void FixUp();

    unsigned char pad_0[0x8];
    CB3TrackMaterial * field_8;
    unsigned char pad_C[0x2];
    short field_E;
    short * field_10;
};

struct UnkStruct_D_0064D370 {
    unsigned long field_0;
    unsigned char pad_8[0x8];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00332E00_2 {
    unsigned char pad_0[0x120];
};

struct UnkStruct_kpacTrackBloomParamsPath {
    int field_0;
};

struct UnkStruct_gVdbDatabase {
    int field_0;
};

struct UnkStruct_D_01EA3240 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004C5770 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004C5778 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004C5790 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004C57A8 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_theMemMgr {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004C57B8 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00332E00_e1 {
    unsigned char pad_0[0x28];
};

struct UnkStruct_00332E00 {
    unsigned char field_0;
    unsigned char field_1;
    unsigned char pad_2[0x2];
    CB3StaticTrackData * field_4;
    int field_8;
    int field_C;
    float field_10;
    float field_14;
};

extern UnkStruct_D_0064D370 D_0064D370;
extern UnkStruct_kpacTrackBloomParamsPath kpacTrackBloomParamsPath;
extern UnkStruct_gVdbDatabase mpToolBase__Q27GtComms16CGtCommsToolBase;
extern UnkStruct_D_01EA3240 D_01EA3240;
extern UnkStruct_D_004C5770 D_004C5770;
extern UnkStruct_D_004C5778 D_004C5778;
extern UnkStruct_D_004C5790 D_004C5790;
extern UnkStruct_D_004C57A8 D_004C57A8;
extern UnkStruct_theMemMgr theMemMgr;
extern CB3TrackList D_005196A0;
extern UnkStruct_D_004C57B8 D_004C57B8;
extern CAsyncLoadManager D_004F6100;

extern "C" char * strcpy(char *, const char *);
extern "C" char * strcat(char *, const char *);
extern "C" void func_0021AB40(unsigned long, void *);
extern "C" void AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(int, void *, void *, void *, void *, int, int, float, float);
extern "C" int AcquireBlock__19CB3MemoryManagerPS2F14EB3MemoryBlocki(void *, int, int);
extern "C" int GetBlockSize__19CB3MemoryManagerPS2CF14EB3MemoryBlock(void *, int);

// 0x00332E00
extern "C" int Prepare__14CB3StaticTrackFv(UnkStruct_00332E00 * self)
{
    char name[0x20];
    char path[0x100];
    switch (self->field_8) {
    case 1:
    case 24:
        if (self->field_C != 0 || self->field_0 == 1) return 1;
        func_0021AB40(D_0064D370.field_0, name);
        strcpy((char *)&D_01EA3240, (const char *)kpacTrackBloomParamsPath.field_0);
        strcat((char *)&D_01EA3240, name);
        strcat((char *)&D_01EA3240, (const char *)&D_004C5770);
        self->field_10 = 0.75f;
        self->field_14 = 1.0f;
        AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase.field_0 + 16, &self->field_10, &D_004C5778, &D_004C5790, &D_01EA3240, 2, 0, 0.0f, 1.0f);
        AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase.field_0 + 16, &self->field_14, &D_004C57A8, &D_004C5790, &D_01EA3240, 2, 0, 0.0f, 1.0f);
        self->field_1 = 0;
        self->field_0 = 0;
        self->field_8 = 2;
        // falls through: retail's case 1/24 body runs straight into case 2's
    case 2:
        self->field_4 = (CB3StaticTrackData *)AcquireBlock__19CB3MemoryManagerPS2F14EB3MemoryBlocki(&theMemMgr, 5, 0);
        if (self->field_4 == 0) return 0;
        if (D_0064D370.field_0 != 0) {
            D_005196A0.CreateTrackPathFromIndex(D_005196A0.GetTrackIndexFromID(D_0064D370.field_0), path, 256);
        } else {
            D_005196A0.CreateTrackPathFromID(0xC4BD5916359D4000, path, 256);
        }
        strcat(path, (const char *)&D_004C57B8);
        self->field_C = D_004F6100.QueueLoadRequest(path, (bool *)self, self->field_4, GetBlockSize__19CB3MemoryManagerPS2CF14EB3MemoryBlock(&theMemMgr, 5));
        self->field_8 = 3;
        return 0;
    case 3:
        if (self->field_0 != 0) self->field_8 = 22;
        return 0;
    case 22:
        self->field_C = 0;
        if (self->field_1 == 0) {
            self->field_4->FixUp();
            self->field_1 = 1;
        }
        self->field_8 = 23;
        return 1;
    case 23:
        for (int i = 0; i < self->field_4->field_E; i++) {
            self->field_4->field_8[self->field_4->field_10[i]].Prepare();
        }
        return 1;
    }
    return 0;
}
