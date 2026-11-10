// B3RaceCar.cpp -- translation unit regrouped by tools/tu_merge.py from 10 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 7 function(s) named in research/retail_names.csv -> B3RaceCar.cpp, 3 placed between two of them by address contiguity (N2).
// Area: src/b3/gamesource/World, [L] Revenge (SLUS_212.42) GameSource/World/B4RaceCar.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

typedef unsigned int u_long128 __attribute__((mode(TI)));
#include "b3/GtMathPs2.h"

#include "b3/classes/CAsyncLoadManager.h"
#include "b3/classes/CB3CollidingBody.h"
#include "b3/classes/CB3CrashStartInfo.h"
#include "b3/classes/CB3RaceCar.h"
#include "b3/classes/CB3SoundRaceCar.h"
#include "b3/classes/CB3SoundRaceCarManager.h"
#include "b3/classes/CB3VehicleEssentialParams.h"
#include "b3/classes/CB3VehicleParams.h"
#include "b3/classes/EB3RaceCarType.h"
#include "b3/classes/EB3ScoreFinishState.h"
#include "b3/classes/UnkStruct_D_0055EFEC.h"
#include "b3/classes/UnkStruct_D_0064D370.h"
#include "b3/classes/UnkStruct_gVdbDatabase.h"
#include "b3/classes/UnkStruct_gaVehicleReflectivityData.h"
#include "b3/classes/UnkStruct_theMemMgr.h"

struct UnkStruct_00150E20;
struct UnkStruct_00151100;
struct UnkStruct_00151A30;
struct UnkStruct_00151A30_a1;
struct UnkStruct_00395A00_a1;

struct UnkStruct_00150E20 {
    unsigned char pad_0[0x178C];
    int field_178C;
    unsigned char pad_1790[0x21C];
    signed char field_19AC;
};

struct UnkStruct_00151100 {
    unsigned char pad_0[0x1960];
    unsigned long field_1960;
    unsigned char pad_1968[0x8];
    int field_1970;
};

struct UnkStruct_00151A20 {
    unsigned char pad_0[0x18C0];
    int field_18C0;
};

struct UnkStruct_00151A30_a1 {
    unsigned char pad_0[0x30];
    u_long128 field_30;
};

struct UnkStruct_00151A30 {
    u_long128 field_0;
};

extern UnkStruct_D_0055EFEC D_0055EFEC;
extern UnkStruct_gaVehicleReflectivityData gaVehicleReflectivityData;
extern UnkStruct_gVdbDatabase mpToolBase__Q27GtComms16CGtCommsToolBase;
extern UnkStruct_D_0064D370 D_0064D370;
extern CAsyncLoadManager D_004F6100;
extern CB3SoundRaceCarManager D_01E77550;
extern UnkStruct_theMemMgr theMemMgr;
extern "C" void * memset(void *, int, unsigned int);
extern "C" void StopImmediately__16CB3CollidingBodyFv(void *);  // CB3CollidingBody::StopImmediately()
extern "C" void Construct__16CB3VehicleDeformFv(void *);  // CB3VehicleDeform::Construct()
extern "C" int func_003EB060(unsigned long);
extern "C" int GetRaceVehicleSeries__23CB3HardCodedVehicleListFi(int);
extern "C" void Reset__16CB3VehicleDeformFP25CB3VehicleEssentialParamsP16CB3VehicleParams(void *, void *, void *);  // CB3VehicleDeform::Reset(CB3VehicleEssentialParams*,CB3VehicleParams*)
extern "C" void RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(int, void *);
extern "C" void ReleaseBlock__19CB3MemoryManagerPS2F14EB3MemoryBlocki(void *, int, signed char);

// func_00150E20 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00150E20
extern "C" void func_00150E20(UnkStruct_00150E20 * self, int p0)
{
    signed char t0 = self->field_19AC;
    UnkStruct_00150E20_3 * t1 = D_0055EFEC.field_0[t0].field_0;
    if (p0 == 0) {
        t1->field_1353 = (t1->field_1353 | 16);
        t1->field_1353 = (t1->field_1353 | 8);
        t1->field_1353 = (t1->field_1353 | 4);
        t1->field_212 = 0;
        memset(((char *)t1 + 0x160), 0, 96);
        t1->field_160.Zero();
        t1->field_170.Zero();
        t1->field_190 = 0;
        t1->field_194 = 0;
        t1->field_198 = 0;
        self->field_178C = 3;
    } else {
        self->field_178C = 1;
    }
    StopImmediately__16CB3CollidingBodyFv(t1);
}

// CB3RaceCar::SetActive(bool) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3RaceCar.cpp.
// 0x00150EE0
void CB3RaceCar::SetActive(bool p0)
{
    if ((p0 & 255) == field_1998) return;
    field_1998 = p0;
    vfunc_28(field_1998, (p0 & 255));
}

// SetCarID__10CB3RaceCarFUl -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00151100
extern "C" void SetCarID__10CB3RaceCarFUl(UnkStruct_00151100 * self, unsigned long p0)
{
    self->field_1960 = p0;
    int r0 = func_003EB060(self->field_1960);
    if (r0 != -1) {
        int r1 = GetRaceVehicleSeries__23CB3HardCodedVehicleListFi(r0);
        self->field_1970 = r1;
    } else {
        self->field_1970 = 0;
    }
}

// CB3RaceCar::PrepareSound() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3RaceCar.cpp.
// 0x00151770
int CB3RaceCar::PrepareSound()
{
    return 1;
}

// CB3RaceCar::StopCrashing() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3RaceCar.cpp.
// 0x001519E0
void CB3RaceCar::StopCrashing()
{
    field_18EA = 0;
    field_18EB = 1;
}

// CB3RaceCar::StartCrashing(CB3CrashStartInfo*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3RaceCar.cpp.
// 0x001519F0
void CB3RaceCar::StartCrashing(CB3CrashStartInfo* p0)
{
    field_199B = 0;
    field_44 = 0;
    field_48 = 1.0f;
    field_4C = 0;
    field_50 = 1.0f;
    field_18EA = 1;
}

// func_00151A20 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00151A20
extern "C" int func_00151A20(UnkStruct_00151A20 *self)
{
    return self->field_18C0;
}

// func_00151A30 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00151A30
extern "C" void func_00151A30(UnkStruct_00151A30 * self, UnkStruct_00151A30_a1 * p0)
{
    self->field_0 = p0->field_30;
}

// CB3RaceCar::Release() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3RaceCar.cpp.
// 0x00151C40
void CB3RaceCar::Release()
{
    if (field_199A == 0) {
        D_004F6100.Abort(field_1994);
        field_1994 = 0;
    }
    unsigned long t0 = field_1960;
    int i = 0;
    goto loop0_test;
loop0_body:
    {
        if (t0 != gaVehicleReflectivityData.field_0[i].field_0) {
            goto loop0_next;
        }
        RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv((mpToolBase__Q27GtComms16CGtCommsToolBase.field_0 + 16), ((char *)&gaVehicleReflectivityData.field_0[i] + 0x8));
        RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv((mpToolBase__Q27GtComms16CGtCommsToolBase.field_0 + 16), ((char *)&gaVehicleReflectivityData.field_0[i] + 0x28));
        RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv((mpToolBase__Q27GtComms16CGtCommsToolBase.field_0 + 16), ((char *)&gaVehicleReflectivityData.field_0[i] + 0x48));
        RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv((mpToolBase__Q27GtComms16CGtCommsToolBase.field_0 + 16), ((char *)&gaVehicleReflectivityData.field_0[i] + 0x68));
        RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv((mpToolBase__Q27GtComms16CGtCommsToolBase.field_0 + 16), ((char *)&gaVehicleReflectivityData.field_0[i] + 0x6C));
        gaVehicleReflectivityData.field_0[i].field_0 = 0;
        goto loop0_end;
    }
loop0_next:
    i++;
loop0_test:
    if (i < 18) goto loop0_body;
loop0_end:
    UnkStruct_00151C40_4 * t1 = field_1918;
    if (t1 != 0) {
        t1->vfunc_10();
        D_01E77550.RelinquishRaceCar((CB3SoundRaceCar*)field_1918);
        field_1918 = 0;
    }
    ReleaseBlock__19CB3MemoryManagerPS2F14EB3MemoryBlocki(&theMemMgr, 1, field_19AC);
    if (field_40 != 0) {
        Reset__16CB3VehicleDeformFP25CB3VehicleEssentialParamsP16CB3VehicleParams(((char *)this + 0x380), (CB3VehicleEssentialParams*)this, (CB3VehicleParams*)((char *)this + 0x80));
        field_40 = 0;
    }
    if (D_0064D370.field_0 != 0) {
        field_10C0.Release();
    } else {
    }
    field_1968 = 24;
}

// CB3RaceCar::Construct() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3RaceCar.cpp.
// 0x00153160
void CB3RaceCar::Construct()
{
    field_1960 = 0;
    field_1970 = 8;
    field_40 = 0;
    Construct__16CB3VehicleDeformFv(((char *)this + 0x380));
    field_1918 = 0;
    field_10C0.Construct();
    field_199A = 1;
    field_1994 = 0;
    field_1890 = 0;
    field_196C = 0;
    field_1968 = 1;
}
