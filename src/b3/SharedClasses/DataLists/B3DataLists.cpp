// B3DataLists.cpp -- translation unit regrouped by tools/tu_merge.py from 13 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 13 function(s) named in research/retail_names.csv -> B3DataLists.cpp.
// Area: src/b3/SharedClasses/DataLists, [L] Revenge (SLUS_212.42) SharedClasses/DataLists/B4DataLists.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3TrackList.h"
#include "b3/classes/CB3VehicleList.h"
#include "b3/classes/EB3MenuCarClasses.h"
#include "b3/classes/UnkStruct_D_004BB770.h"
#include "b3/classes/UnkStruct_D_004BB778.h"
#include "b3/classes/UnkStruct_D_004BB780.h"
#include "b3/classes/UnkStruct_D_004BB7D0.h"

struct UnkStruct_00251870_0;
struct UnkStruct_00251A00_0;
struct UnkStruct_00251A30_2;
struct UnkStruct_00251AE0_0;
struct UnkStruct_00251F40_2;

struct UnkStruct_00251870_0 {
    signed char field_0;
    unsigned char pad_1[0xF];
};

struct UnkStruct_00251A00_0 {
    unsigned char pad_0[0x3];
    signed char field_3;
    unsigned char pad_4[0xC];
};

struct UnkStruct_00251A30_2 {
    unsigned char pad_0[0x10];
};

struct UnkStruct_00251AE0_0 {
    unsigned char pad_0[0x10];
};

struct UnkStruct_00251F40_2 {
    signed char field_0[1];  // [G] element count unknown
    unsigned char pad_1[0xF];
};

extern UnkStruct_D_004BB770 D_004BB770;
extern UnkStruct_D_004BB778 D_004BB778;
extern UnkStruct_D_004BB780 D_004BB780;
extern UnkStruct_D_004BB7D0 D_004BB7D0;
extern char D_004BB788[16];
extern char D_004BB790[16];
extern char D_004BB798[16];
extern char D_004BB7A0[16];
extern char D_004BB7A8[16];
extern char D_004BB7B0[16];
extern char D_004BB7B8[16];
extern char D_004BB7C0[16];
extern char D_004BB7C8[16];
extern "C" void func_0021ADF0(unsigned long, void *);
extern "C" char * strcpy(char *, const char *);
extern "C" char * strcat(char *, const char *);
extern "C" void strncat(char*, void *, int);
extern "C" int func_00127520(const char *, const char *, int);

// CB3TrackList::GetTrackRegion(unsigned long) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3DataLists.cpp.
// 0x00251870
int CB3TrackList::GetTrackRegion(unsigned long p0)
{
    UnkStruct_00251870_0 local;  // [G] the frame's one local (size: up to the frame top)
    func_0021ADF0(p0, &local);
    switch (local.field_0) {
    case 85:
        return 0;
    case 69:
        return 1;
    case 65:
        return 2;
    default:
        return 3;
    }
}

// CB3TrackList::GetTrackIndexFromID(unsigned long) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3DataLists.cpp.
// 0x002518E0
int CB3TrackList::GetTrackIndexFromID(unsigned long p0)
{
    int t0 = field_4;
    for (int i = 0; (i < t0); i++) {
        if (field_408[i] == p0) {
            return i;
        }
    }
    return -1;
}

// CB3TrackList::IsTrackPointToPoint(unsigned long) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3DataLists.cpp.
// 0x002519B0
bool CB3TrackList::IsTrackPointToPoint(unsigned long p0)
{
    int t0 = field_4;
    for (int i = 0; (i < t0); i++) {
        if (field_408[i] == p0) {
            return (field_8[i] != 0);
        }
    }
    return 1;
}

// CB3TrackList::IsTrackMarathon(unsigned long) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3DataLists.cpp.
// 0x00251A00
bool CB3TrackList::IsTrackMarathon(unsigned long p0)
{
    UnkStruct_00251A00_0 local;  // [G] the frame's one local (size: up to the frame top)
    func_0021ADF0(p0, &local);
    return (local.field_3 == 77);
}

// CB3TrackList::CreateTrackPathFromIndex(int,char*,int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3DataLists.cpp.
// 0x00251A30
void CB3TrackList::CreateTrackPathFromIndex(int p0, char* p1, int p2)
{
    UnkStruct_00251A30_2 local;  // [G] the frame's one local (size: up to the frame top)
    unsigned long t0 = field_408[p0];
    strcpy((char *)p1, (const char *)&D_004BB770);
    func_0021ADF0(t0, &local);
    strncat(p1, &local, 2);
    strcat((char *)p1, (const char *)&D_004BB778);
    strncat(p1, ((char *)&local + 0x3), 2);
    strcat((char *)p1, (const char *)&D_004BB780);
    strncat(p1, ((char *)&local + 0x6), 2);
    strcat((char *)p1, (const char *)&D_004BB778);
}

// CB3TrackList::CreateTrackPathFromID(unsigned long,char*,int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3DataLists.cpp.
// 0x00251AE0
void CB3TrackList::CreateTrackPathFromID(unsigned long p0, char* p1, int p2)
{
    UnkStruct_00251AE0_0 local;  // [G] the frame's one local (size: up to the frame top)
    strcpy((char *)p1, (const char *)&D_004BB770);
    func_0021ADF0(p0, &local);
    strncat(p1, &local, 2);
    strcat((char *)p1, (const char *)&D_004BB778);
    strncat(p1, ((char *)&local + 0x3), 2);
    strcat((char *)p1, (const char *)&D_004BB780);
    strncat(p1, ((char *)&local + 0x6), 2);
    strcat((char *)p1, (const char *)&D_004BB778);
}

// CB3VehicleList::GetCarID(EB3MenuCarClasses,int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3DataLists.cpp.
// 0x00251C10
unsigned long CB3VehicleList::GetCarID(EB3MenuCarClasses p0, int p1)
{
    int m0 = p1;
    for (int i = 0; (i < field_4); i++) {
        unsigned long t0 = field_408[i];
        int r0 = CB3VehicleList::GetClassFromID(t0);
        if (p0 != r0) {
        } else {
            if (m0 == 0) {
                return t0;
            }
            m0 = (m0 + -1);
        }
    }
    return 0;
}

// CB3VehicleList::GetClassFromID(unsigned long) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3DataLists.cpp.
// 0x00251CB0
int CB3VehicleList::GetClassFromID(unsigned long id)
{
    char buf[16];
    func_0021ADF0(id, buf);
    if (func_00127520(buf, D_004BB788, 4) == 0) return 0;
    if (func_00127520(buf, D_004BB790, 4) == 0) return 1;
    if (func_00127520(buf, D_004BB798, 4) == 0) return 2;
    if (func_00127520(buf, D_004BB7A0, 4) == 0) return 3;
    if (func_00127520(buf, D_004BB7A8, 4) == 0) return 4;
    if (func_00127520(buf, D_004BB7B0, 4) == 0) return 5;
    if (func_00127520(buf, D_004BB7B8, 4) == 0) return 6;
    if (func_00127520(buf, D_004BB7C0, 4) == 0) return 7;
    return func_00127520(buf, D_004BB7C8, 4) == 0 ? 8 : 9;
}

// CB3VehicleList::GetVehicleIndexFromID(unsigned long) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3DataLists.cpp.
// 0x00251E60
int CB3VehicleList::GetVehicleIndexFromID(unsigned long p0)
{
    int t0 = field_4;
    for (int i = 0; (i < t0); i++) {
        if (field_408[i] == p0) {
            return i;
        }
    }
    return 0;
}

// CB3VehicleList::GetVehicleBoostBarSize(unsigned long) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3DataLists.cpp.
// 0x00251EA0
int CB3VehicleList::GetVehicleBoostBarSize(unsigned long p0)
{
    int t0 = field_4;
    for (int i = 0; (i < t0); i++) {
        if (field_408[i] == p0) {
            return field_208[i];
        }
    }
    return 1;
}

// CB3VehicleList::IsVehicleDriveable(unsigned long) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3DataLists.cpp.
// 0x00251EF0
bool CB3VehicleList::IsVehicleDriveable(unsigned long p0)
{
    int t0 = field_4;
    for (int i = 0; (i < t0); i++) {
        if (field_408[i] == p0) {
            return (field_8[i] != 0);
        }
    }
    return 1;
}

// CB3VehicleList::CreateVehiclePathFromIndex(int,char*,int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3DataLists.cpp.
// 0x00251F40
void CB3VehicleList::CreateVehiclePathFromIndex(int p0, char* p1, int p2)
{
    UnkStruct_00251F40_2 local;  // [G] the frame's one local (size: up to the frame top)
    unsigned long t0 = field_408[p0];
    strcpy((char *)p1, (const char *)&D_004BB7D0);
    func_0021ADF0(t0, &local);
    int i = 4;
    goto loop0_test;
loop0_body:
    {
        if (local.field_0[i] != 32) {
            goto loop0_next;
        }
        local.field_0[i] = 0;
        goto loop0_end;
    }
loop0_next:
    i++;
loop0_test:
    if (i < 12) goto loop0_body;
loop0_end:
    strncat(p1, &local, 4);
    strcat((char *)p1, (const char *)&D_004BB778);
    strcat((char *)p1, (const char *)((char *)&local + 0x4));
}

// CB3VehicleList::DoesVehicleExist(unsigned long) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3DataLists.cpp.
// 0x00252000
int CB3VehicleList::DoesVehicleExist(unsigned long p0)
{
    int t0 = field_4;
    for (int i = 0; (i < t0); i++) {
        if (field_408[i] == p0) {
            return 1;
        }
    }
    return 0;
}
