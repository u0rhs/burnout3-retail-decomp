// func_001BE990 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (two CGtV3d by-value args built by a static inline (x,y,z) helper (CGtV3d(x,y,z) stand-in)).

// from build/vt\try_func_001BE990_best.cpp
// func_001BE990 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.


#include "b3/GtMathPs2.h"

using GtMathPs2::CGtV3d;

struct UnkStruct_001BE990;
struct UnkStruct_001BE990_0;
struct UnkStruct_001BE990_2;
struct UnkStruct_D_0055EF70;
struct UnkStruct_D_0064CE40;

struct UnkStruct_001BE990_0 {
    int field_0;
    float field_4;
    int field_8;
    unsigned char pad_C[0x4];
    int field_10;
    float field_14;
    float field_18;
    unsigned char pad_1C[0x4];
    u_long128 field_20;
    u_long128 field_30;
};

struct UnkStruct_001BE990_2 {
    unsigned char pad_0[0x19AC];
    signed char field_19AC;
};

struct UnkStruct_D_0055EF70 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0064CE40 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_001BE990 {
    unsigned char pad_0[0x13F4];
    UnkStruct_001BE990_2 * field_13F4;
};

extern UnkStruct_D_0055EF70 D_0055EF70;
extern UnkStruct_D_0064CE40 D_0064CE40;

extern "C" void DetachAll__17CB3VehiclePhysicsFb(void *, bool);  // CB3VehiclePhysics::DetachAll(bool)
extern "C" void func_001C8120(UnkStruct_001BE990 *, CGtV3d, CGtV3d, float);
extern "C" void func_001B2BA0(void *, UnkStruct_001BE990 *, int, int);
extern "C" void func_003CCC50(void *, signed char);

union UnkStruct_001BE990_v {
    float field_0[4];
    u_long128 field_q;
};

// [G] stands for a CGtV3d(x, y, z) constructor (not in GtMathPs2.h): three lanes stored to a stack temporary
static inline CGtV3d func_001BE990_inl1(float x, float y, float z)
{
    UnkStruct_001BE990_v t;
    t.field_0[0] = x;
    t.field_0[1] = y;
    t.field_0[2] = z;
    return CGtV3d(t.field_q);
}

// 0x001BE990
extern "C" void func_001BE990(UnkStruct_001BE990 * self, int p0)
{
    func_001C8120(self, func_001BE990_inl1(0.5f, 1.0f, 0.5f), func_001BE990_inl1(0.0f, -1.0f, 0.0f), (float)100000);
    DetachAll__17CB3VehiclePhysicsFb(self, 0);
    func_001B2BA0(&D_0055EF70, self, 0, p0);
    if (p0 == 0) {
        func_003CCC50(&D_0064CE40, self->field_13F4->field_19AC);
    }
}
