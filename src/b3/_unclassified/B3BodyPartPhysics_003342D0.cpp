// CB3BodyPartPhysics::Prepare(CB3VehiclePhysics*,int,EBodyPartType) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3BodyPartPhysics.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (ghvu13: Ghidra draft; else-if chain on the type, header GetLength/SetA/Set, N185 SetA(XAxisType) + =j Zero stand-ins, N140 0x50 pad).

// CB3BodyPartPhysics::Prepare(CB3VehiclePhysics*, int, EBodyPartType) -- hand-written by ghvu13 from the Ghidra draft.
// [C] name: the mangled symbol in retail's tables. Field names are placeholders and every type is [G].
// ghvu13: if/else-if chain on the stored type (0: sized box from the vehicle's row, 1: matrix + bounding box from the
// vehicle's tables, 2: matrix copied from the CC4 list entry); header GetLength / SetA / Set / SetX-Z / operator+ / operator*;
// [L] N185 stand-ins for SetA(XAxisType) and a compiler-chosen Zero(); `m = &field_220` taken after the entry pointer and
// `(field_2B8 + base)[0xADC]` fix register / addu order; an N140 pad stands in for retail's five dead frame slots.
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

enum EBodyPartType {};   // [C] type name from the mangled symbol; values not evidenced (compared as 0/1/2)

extern "C" bool func_001AD380(void *);   // [L] CB3CollidingBody::Prepare (B3VehiclePhysics_001CFC00 calls it the same way)
extern "C" void Initialise__21CB3ConvexHullBodyPartFv(void *);
extern "C" void MakeFromBoundingBox__13CB3ConvexHullFQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3d12EB3HullShape(void *, const void *, const void *, int);
extern "C" void SetRealisticMomentsOfInertia__16CB3CollidingBodyFv(void *);

struct UnkStruct_003342D0_m { CGtV3d field_0; CGtV3d field_10; CGtV3d field_20; CGtV3d field_30; };
struct UnkStruct_003342D0_bb { CGtV3d field_0; CGtV3d field_10; };
struct UnkStruct_003342D0_e {
    unsigned char pad_0[0xC];
    signed char field_C;
    unsigned char pad_D[3];
    UnkStruct_003342D0_m field_10;
};
struct UnkStruct_003342D0_l { unsigned char pad_0[0x8]; UnkStruct_003342D0_e *field_8; };
struct UnkStruct_003342D0_cc4 {
    unsigned char pad_0[0x180];
    UnkStruct_003342D0_m field_180[1];   // [G] count
    unsigned char pad_1C0[0x1024 - 0x1C0];
    UnkStruct_003342D0_l *field_1024;
};
struct UnkStruct_003342D0_cc0 { unsigned char pad_0[0x40]; unsigned char *field_40; };
struct UnkStruct_003342D0_row { float field_0; unsigned char pad_4[0xBC]; };

class CB3VehiclePhysics {
public:
    unsigned char pad_0[0x870];
    UnkStruct_003342D0_row field_870[1];   // [G] count; rows of 0xC0
    unsigned char pad_930[0xCC0 - 0x930];
    UnkStruct_003342D0_cc0 *field_CC0;
    UnkStruct_003342D0_cc4 *field_CC4;
    void *field_CC8[1];   // [G] count
};

class CB3BodyPartPhysics {
public:
    bool Prepare(CB3VehiclePhysics *veh, int i, EBodyPartType type);

    unsigned char pad_0[0x1C0];
    CGtV4d field_1C0;
    CGtV3d field_1D0;
    CGtV3d field_1E0;
    float field_1F0;
    unsigned char pad_1F4[4];
    float field_1F8;
    unsigned char pad_1FC[8];
    void *field_204;
    void *field_208;
    unsigned char field_20C;
    unsigned char pad_20D[0x13];
    UnkStruct_003342D0_m field_220;
    CGtV3d field_260;
    unsigned char pad_270[0x40];
    CB3VehiclePhysics *field_2B0;
    int field_2B4;
    short field_2B8;
    unsigned char field_2BA;
    unsigned char field_2BB;
    unsigned char pad_2BC[4];
    unsigned char field_2C0[0x210];
    unsigned char field_4D0;
};

struct UnkStruct_003342D0_pad { int x[20]; UnkStruct_003342D0_pad() {} ~UnkStruct_003342D0_pad() {} };

// [L] N185: stands in for a missing GtMathPs2 inline (CGtV4d::SetA taking the XAxisType lane straight: vmulx.w from it).
static inline void func_003342D0_inl1(CGtV4d &v, XAxisType a)
{
    asm("vmulx.w %0, $vf0, %1x" : "+j"(v.mData) : "j"(a.lVector));
}

// [L] N185: CGtV3d::Zero() on a compiler-chosen register (the header's hard-codes $vf1).
static inline void func_003342D0_inl2(CGtV3d &v) { u_long128 r; asm("vadd.xyz %0, $vf0, $vf0" : "=j"(r)); v.mData = r; }

// 0x003342D0
bool CB3BodyPartPhysics::Prepare(CB3VehiclePhysics *veh, int i, EBodyPartType type)
{
    UnkStruct_003342D0_pad pad;  // N140 [G]: retail's five dead 16-byte frame slots
    func_001AD380(this);
    field_2B0 = veh;
    field_2B8 = i;
    field_2BA = type;
    field_2B4 = 0;
    field_2BB = 0xFF;
    field_4D0 = 0;
    if (field_2BA == 0) {
        field_204 = veh->field_CC8[i];
        float f = veh->field_870[i].field_0;
        field_20C = 1;
        field_208 = field_2C0;
        field_1C0.SetA(f);
        field_1E0.Set(-0.1f, -f, -f);
        field_1D0.Set(0.1f, f, f);
        Initialise__21CB3ConvexHullBodyPartFv(field_2C0);
        MakeFromBoundingBox__13CB3ConvexHullFQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3d12EB3HullShape(field_2C0, &field_1E0, &field_1D0, 0);
        func_003342D0_inl2(field_260);
        field_1F8 = 0.7f;
    } else if (field_2BA == 1) {
        field_204 = &veh->field_CC4->field_180[i];
        field_20C = 1;
        field_208 = field_2C0;
        UnkStruct_003342D0_bb *bb = (UnkStruct_003342D0_bb *)(veh->field_CC0->field_40 + i * 0x20 + 0xEA0);
        field_1D0 = bb->field_0;
        field_1E0 = bb->field_10;
        Initialise__21CB3ConvexHullBodyPartFv(field_2C0);
        MakeFromBoundingBox__13CB3ConvexHullFQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3d12EB3HullShape(field_2C0, &field_1E0, &field_1D0, 0);
        func_003342D0_inl1(field_1C0, field_1D0.GetLength());
        field_260 = (field_1E0 + field_1D0) * 0.5f;
        unsigned char c = (field_2B8 + veh->field_CC0->field_40)[0xADC];
        if (c == 0) {
            field_260.SetY(0.0f);
        } else if (c == 1) {
            field_260.SetX(0.0f);
        } else if (c == 2) {
            field_260.SetZ(0.0f);
            field_260.SetY(0.0f);
        }
    } else if (field_2BA == 2) {
        UnkStruct_003342D0_e *e = &veh->field_CC4->field_1024->field_8[i];
        UnkStruct_003342D0_m *m = &field_220;
        *m = e->field_10;
        field_204 = m;
        field_20C = 1;
        field_208 = field_2C0;
        UnkStruct_003342D0_bb *bb = (UnkStruct_003342D0_bb *)(veh->field_CC0->field_40 + e->field_C * 0x20 + 0xF60);
        field_1D0 = bb->field_0;
        field_1E0 = bb->field_10;
        Initialise__21CB3ConvexHullBodyPartFv(field_2C0);
        MakeFromBoundingBox__13CB3ConvexHullFQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3d12EB3HullShape(field_2C0, &field_1E0, &field_1D0, 0);
        func_003342D0_inl1(field_1C0, field_1D0.GetLength());
    }
    field_1F0 = 260.0f;
    SetRealisticMomentsOfInertia__16CB3CollidingBodyFv(this);
    return true;
}
