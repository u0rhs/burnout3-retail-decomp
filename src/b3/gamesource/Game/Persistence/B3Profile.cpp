// B3Profile.cpp -- translation unit regrouped by tools/tu_merge.py from 12 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 1 function(s) named in research/retail_names.csv -> B3Profile.cpp, 2 by a medium-confidence name confirmed by a neighbour, 11 placed between two of them by address contiguity (N2).
// Area: src/b3/gamesource/Game/Persistence, [L] Revenge (SLUS_212.42) GameSource/Game/Persistence/B4Profile.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3HardCodedTrackList.h"
#include "b3/classes/CB3Profile.h"
#include "b3/classes/CB3TrackList.h"
#include "b3/classes/CB3VehicleList.h"
#include "b3/classes/EB3MenuCarClasses.h"
#include "b3/classes/UnkStruct_D_004E26A4.h"
#include "b3/classes/UnkStruct_gCalculatedData.h"

struct UnkStruct_00136E00;
struct UnkStruct_0013A560;
struct UnkStruct_0013A560_a1;
struct UnkStruct_0013A570;
struct UnkStruct_0013A570_0;

struct UnkStruct_00136E00 {
    unsigned char pad_0[0x49C];
    void * field_49C;
};

struct UnkStruct_0013A560_a1 {
    float field_0;
};

struct UnkStruct_0013A560 {
    float field_0;
};

struct UnkStruct_0013A570_0 {
    unsigned char pad_0[0xC];
    int field_C;
};

struct UnkStruct_0013A570 {
    int field_0;
    unsigned char pad_4[0x497];
    unsigned char field_49B;
};

extern UnkStruct_D_004E26A4 D_004E26A4;
extern UnkStruct_gCalculatedData gCalculatedData;
extern unsigned char D_0051C0FF[];  // [G] element count unknown
extern unsigned char D_0051BFE3[];  // [G] element count unknown
extern unsigned char D_0051BFA0[];  // [G] element count unknown
extern CB3VehicleList D_005186A0;
extern unsigned char D_0051C0A4[];  // [G] element count unknown
extern CB3TrackList D_005196A0;
extern "C" void func_00436460(UnkStruct_0013A570_0 *);
extern "C" void func_00436270(void *, UnkStruct_0013A570_0 *);
extern "C" unsigned long GetRaceVehicleGtID__23CB3HardCodedVehicleListFi(int);
extern "C" int func_003EB060(unsigned long);
extern "C" int GetRaceVehicleSeries__23CB3HardCodedVehicleListFi(int);

// func_00136E00 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00136E00
extern "C" void func_00136E00(UnkStruct_00136E00 * self)
{
    D_004E26A4.field_0 = 0;
    self->field_49C = (void *)self;
}

// func_0013A560 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x0013A560
extern "C" float func_0013A560(UnkStruct_0013A560 * self, UnkStruct_0013A560_a1 * p0)
{
    float t0 = p0->field_0;
    self->field_0 = t0;
    return t0;
}

// func_0013A570 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x0013A570
extern "C" void func_0013A570(UnkStruct_0013A570 * self)
{
    UnkStruct_0013A570_0 local;  // [G] the frame's one local (size: up to the frame top)
    func_00436460(&local);
    func_00436270(((char *)&local + 0xC), &local);
    self->field_0 = local.field_C;
    self->field_49B = 0;
}

// func_0013A5B0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x0013A5B0
extern "C" int func_0013A5B0(void *a0 /* passed by every caller, not read here */)
{
    return gCalculatedData.field_24;
}

// func_0013A5C0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x0013A5C0
extern "C" unsigned long func_0013A5C0(void *a0 /* passed by every caller, not read here */)
{
    int t0 = gCalculatedData.field_0;
    if (t0 == -1) {
        return 0;
    }
    unsigned long r0 = GetRaceVehicleGtID__23CB3HardCodedVehicleListFi(t0);
    return r0;
}

// func_0013A600 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x0013A600
extern "C" unsigned char func_0013A600(int n0, int p0)
{
    return D_0051C0FF[p0];
}

// func_0013A620 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x0013A620
extern "C" int func_0013A620(void *a0 /* passed by every caller, not read here */)
{
    return gCalculatedData.field_2C;
}

// func_0013A630 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x0013A630
extern "C" unsigned char func_0013A630(void *n0_, int p0)
{
    int n0 = (int)n0_;
    return D_0051BFE3[p0];
}

// func_0013A650 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x0013A650
extern "C" int func_0013A650(void *a0 /* passed by every caller, not read here */)
{
    return gCalculatedData.field_28;
}

// CB3Profile::IsCarUnlocked(unsigned long) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3Profile.cpp.
// 0x0013A660
unsigned char CB3Profile::IsCarUnlocked(unsigned long p0)
{
    int r0 = D_005186A0.DoesVehicleExist(p0);
    if (r0 == 0) {
        return 0;
    }
    int r1 = func_003EB060(p0);
    unsigned char v0;
    if (r1 == -1) {
        v0 = 1;
    } else {
        v0 = D_0051BFA0[r1];
    }
    return v0;
}

// func_0013A6D0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x0013A6D0
extern "C" int func_0013A6D0(void *n0_, int p0)
{
    int n0 = (int)n0_;
    if (p0 == 7) {
        return 1;
    }
    int i = 0;
    goto loop0_test;
loop0_body:
    {
        int r0 = GetRaceVehicleSeries__23CB3HardCodedVehicleListFi(i);
        if (p0 != r0) {
            goto loop0_next;
        }
        if (D_0051BFA0[i] == 0) {
            goto loop0_next;
        }
        return 1;
    }
loop0_next:
    i++;
loop0_test:
    if (i < 67) goto loop0_body;
    return 0;
}

// CB3Profile::IsTrackUnlocked(unsigned long) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3Profile.cpp.
// 0x0013A760
unsigned char CB3Profile::IsTrackUnlocked(unsigned long p0)
{
    int r0 = D_005196A0.DoesTrackExist(p0);
    if (r0 == 0) {
        return 0;
    }
    int r1 = CB3HardCodedTrackList::FindTrack(p0);
    unsigned char v0;
    if (r1 == -1) {
        v0 = 1;
    } else {
        v0 = D_0051C0A4[r1];
    }
    return v0;
}
