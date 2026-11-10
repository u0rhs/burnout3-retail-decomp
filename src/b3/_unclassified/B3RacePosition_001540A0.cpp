// CB3RacePosition::DrawSingleVehicleValue(CB3VehiclePhysics*,int,int,float,bool) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3RacePosition.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (ghvu4: Ghidra draft; [L] N185 Y+Y stand-in (=j result, a/b inputs) + 2 N140 pads).

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

struct UnkStruct_001540A0_bb { unsigned char pad_0[0xE80]; CGtV3d field_E80; };
struct UnkStruct_001540A0_att { unsigned char pad_0[0x40]; UnkStruct_001540A0_bb * field_40; };
struct UnkStruct_001540A0_net { unsigned char pad_0[0x1960]; unsigned long field_1960; };
class CB3VehiclePhysics {
public:
    unsigned char pad_0[0x204];
    CGtMatrix3x4 * field_204;
    unsigned char pad_208[0xD];
    signed char field_215;
    unsigned char pad_216[0xAAA];
    UnkStruct_001540A0_att * field_CC0;
    unsigned char pad_CC4[0x730];
    UnkStruct_001540A0_net * field_13F4;
    unsigned char pad_13F8[0x1032];
    unsigned char field_242A;
};
struct UnkStruct_001540A0_ent { unsigned char pad_0[0x24]; unsigned short field_24[0x2E]; };
class CB3RaceCar;
class CB3RacePosition {
public:
    void DrawSingleVehicleValue(CB3VehiclePhysics *, int, int, float, bool);
    UnkStruct_001540A0_ent field_0[4];
};
struct UnkStruct_D_0051BA44 { unsigned char pad_0[0x10]; };
extern UnkStruct_D_0051BA44 D_0051BA44;
extern unsigned short D_0051D740[];
extern unsigned long D_0055B7D0[];
extern float D_004E26A8;
extern "C" void func_003B8840(unsigned short *, int);  // [G] retail sets a1 although the callee reads only a0
extern "C" int func_003EB060(unsigned long);
extern "C" int func_003EAE40(int, int);
extern "C" int func_003EACC0(int, int);
extern "C" int FindTrafficVehicle__23CB3HardCodedVehicleListFUl(unsigned long);
extern "C" unsigned short * func_00271A00(void *, int);
extern "C" void CopyN__10CGtUnicodeFPUsiPCUs(unsigned short *, int, unsigned short *);
// [G] link-name call (as the Draw archive): retail passes the position by address and leaves the third bool unset;
// the int parameter is passed raw where the mangled name says bool.
extern "C" void DrawPositionMarker__15CB3RacePositionFQ29GtMathPs26CGtV3dPCUsiP10CB3RaceCarP10CB3RaceCarfbbbf(CB3RacePosition *, const CGtV3d &, const unsigned short *, int, CB3RaceCar *, CB3RaceCar *, float, int, bool, float);

// [G] N140 frame pads: retail's frame keeps two unused 16-byte slots (one named, one inside the inline below).
struct UnkStruct_001540A0_pad { int x[4]; UnkStruct_001540A0_pad() {} ~UnkStruct_001540A0_pad() {} };
// [L] N185: stands in for the header operator+(YAxisType, YAxisType) with retail's register order
static inline YAxisType func_001540A0_inl2(YAxisType a, YAxisType b) { u_long128 r; asm("vaddy.y %0, %1, %2y" : "=j"(r) : "j"(a.lVector), "j"(b.lVector)); return YAxisType(r); }
// [G] placeholder inline for the marker-height adjust (pos.y += the attachment's E80.y); its pad lands below the Y() copy.
static inline void func_001540A0_inl4(CGtV3d &v, const CGtV3d &e) { UnkStruct_001540A0_pad p; v.SetY(func_001540A0_inl2(v.Y(), e.Y())); }

// 0x001540A0
void CB3RacePosition::DrawSingleVehicleValue(CB3VehiclePhysics * veh, int idx, int k, float f, bool half)
{
    D_004E26A8 = veh->field_CC0->field_40->field_E80.Y();
    CGtV3d v = veh->field_204->mPos;
    UnkStruct_001540A0_pad p0;
    func_001540A0_inl4(v, veh->field_CC0->field_40->field_E80);
    func_003B8840(field_0[idx].field_24, k);
    int id;
    if (veh->field_215 == 1) {
        id = func_003EAE40(func_003EB060(veh->field_13F4->field_1960), 0);
    } else {
        id = func_003EACC0(FindTrafficVehicle__23CB3HardCodedVehicleListFUl(D_0055B7D0[veh->field_242A]), 0);
    }
    func_00271A00(&D_0051BA44, id);
    CopyN__10CGtUnicodeFPUsiPCUs(D_0051D740, 0x40, func_00271A00(&D_0051BA44, id));
    DrawPositionMarker__15CB3RacePositionFQ29GtMathPs26CGtV3dPCUsiP10CB3RaceCarP10CB3RaceCarfbbbf(this, v, field_0[idx].field_24, -1, 0, 0, f, k, true, half ? 0.5f : 0.0f);
}
