// B3TrafficSystem.cpp -- translation unit regrouped by tools/tu_merge.py from 2 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 1 function(s) named in research/retail_names.csv -> B3TrafficSystem.cpp, 1 placed between two of them by address contiguity (N2).
// Area: src/b3/gamesource/World, [L] Revenge (SLUS_212.42) GameSource/World/B4TrafficSystem.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3PhysicsManager.h"
#include "b3/classes/CB3TrafficSystem.h"
#include "b3/classes/CB3TrafficValve.h"
#include "b3/classes/CB3TrafficVehicle.h"
#include "b3/classes/UnkStruct_D_0055EF70.h"
#include "b3/classes/UnkStruct_D_01E65499.h"

struct UnkStruct_00163E90;
struct UnkStruct_00163E90_3;
struct UnkStruct_00163E90_4;
struct UnkStruct_00163E90_a1;
struct UnkStruct_00167B90_e3;
struct UnkStruct_00167B90_e4;

struct UnkStruct_00163E90_a1 {
    unsigned char pad_0[0x108];
    int field_108;
    int field_10C;
    int field_110;
    unsigned char pad_114[0x5F];
    signed char field_173;
    unsigned char field_174;
    unsigned char pad_175[0x2];
    unsigned char field_177;
};

struct UnkStruct_00163E90_3 {
    unsigned char pad_0[0x108];
    void * field_108;
};

struct UnkStruct_00163E90_4 {
    unsigned char pad_0[0x108];
    void * field_108;
};

struct UnkStruct_00163E90 {
    unsigned char pad_0[0x362E0];
    int field_362E0[1];  // [G] element count unknown
    unsigned char pad_362E4[0x80];
    void * field_36364;
    UnkStruct_00163E90_3 * field_36368;
    unsigned char pad_3636C[0x4];
    void * field_36370;
    UnkStruct_00163E90_4 * field_36374;
    unsigned char field_36378[1];  // [G] element count unknown
    unsigned char pad_36379[0x20];
    unsigned char field_36399;
    unsigned char pad_3639A[0x12];
    unsigned char field_363AC;
};

struct UnkStruct_00167B90_e3 {
    unsigned char pad_0[0x50];
};

struct UnkStruct_00167B90_e4 {
    unsigned char pad_0[0x118];
};

extern UnkStruct_D_01E65499 D_01E65499;
extern UnkStruct_D_0055EF70 D_0055EF70;
extern "C" void RemoveTrafficVehicle__17CB3PhysicsManagerFP17CB3TrafficVehicle(void *, void *);  // CB3PhysicsManager::RemoveTrafficVehicle(CB3TrafficVehicle*), passed 3 more argument(s) [G]
extern "C" void * memset(void *, int, unsigned int);
extern "C" void Construct__17CB3TrafficVehicleFv(void *);  // CB3TrafficVehicle::Construct()
extern "C" void Construct__15CB3TrafficValveFv(void *);  // CB3TrafficValve::Construct()
extern "C" void func_001631E0(void *);
extern "C" void func_00309690(void *, int);

// func_00163E90 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00163E90
extern "C" void func_00163E90(UnkStruct_00163E90 * self, UnkStruct_00163E90_a1 * p0, int p1)
{
    if (D_01E65499.field_0 != 0) {
        if (self->field_36370 == 0) {
            self->field_36370 = (void *)p0;
            self->field_36374 = (UnkStruct_00163E90_4 *)p0;
            p0->field_108 = 0;
        } else {
            self->field_36374->field_108 = (void *)p0;
            p0->field_108 = 0;
            self->field_36374 = (UnkStruct_00163E90_4 *)p0;
        }
        self->field_36378[self->field_36399] = 120;
        self->field_36399++;
        if (self->field_36399 >= 32) {
            self->field_36399 = 0;
        }
    } else {
        if (self->field_36364 == 0) {
            self->field_36364 = (void *)p0;
            self->field_36368 = (UnkStruct_00163E90_3 *)p0;
            p0->field_108 = 0;
        } else {
            self->field_36368->field_108 = (void *)p0;
            p0->field_108 = 0;
            self->field_36368 = (UnkStruct_00163E90_3 *)p0;
        }
        self->field_363AC--;
    }
    unsigned char t1 = p0->field_174;
    if ((t1 & 4) == 0 || p0->field_173 == 8) {
        if ((t1 & 2) == 0 && p1 != 0) {
            RemoveTrafficVehicle__17CB3PhysicsManagerFP17CB3TrafficVehicle(&D_0055EF70, (CB3TrafficVehicle*)p0);
        }
    }
    p0->field_10C = 0;
    p0->field_110 = 0;
    unsigned char uc = p0->field_177;
    self->field_362E0[(unsigned short)(uc / 32)] &= ~(1 << (uc % 32));
    p0->field_174 &= 254;
}

// CB3TrafficSystem::Construct() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3TrafficSystem.cpp.
// 0x00167B90
void CB3TrafficSystem::Construct()
{
    memset(((char *)this + 0x127D0), 0, 0x17D00);
    for (int i = 0; (i < 254); i++) {
        Construct__17CB3TrafficVehicleFv(((char *)&field_0[i] + 0x127D0));
    }
    memset(((char *)this + 0x2A4D0), 0, 20320);
    for (int i1 = 0; (i1 < 254); i1++) {
        func_001631E0(((char *)((char *)this + ((i1 * 5) << 4)) + 0x2A4D0));
    }
    memset(((char *)this + 0x4), 0, 0x116E8);
    for (int i2 = 0; (i2 < 255); i2++) {
        Construct__15CB3TrafficValveFv(((char *)((char *)this + ((i2 * 35) << 3)) + 0x4));
    }
    for (int i3 = 0; (i3 < 12); i3++) {
        field_34390[i3] = 0;
        field_343F0[i3] = 0;
    }
    field_34450 = 0;
    field_374F8 = 1;
    field_374FC = 1;
    func_00309690(((char *)this + 0x37400), 1);
}
