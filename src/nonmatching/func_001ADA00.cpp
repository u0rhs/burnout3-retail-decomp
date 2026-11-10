// NONMATCHING: func_001ADA00 -- retail 155 / ours 155 instructions, 28 in changed runs
// draftAN fork C C-first: [L] CB3CrashActionDirector::DoTankerExplosion (Revenge stabs/register list): effect block position+time and flag bits, physics-manager report, network cars tagged (state 5, id) unless network-triggered, crash impulses by the race car's z against the box min z * +-0.3 (trailer too), func_00250160 when it has a trailer; 155/155, call multiset identical (func_00250160 placed elsewhere), non-stack stores identical
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm; every compare sense (c.le/bc1f, c.le/bc1t), the 0.5/int arguments per call, the trailer pointer (lw 0x2424) as the second call's a0, and every store traced

// func_001ADA00 -- draftAN fork C (C-first draft). 0x1ADA00, 0x26C. Not in our name tables: the asm label, C linkage.
// [L] CB3CrashActionDirector::DoTankerExplosion(CB3TrafficPhysics*, float, CGtAxisAlignedBox*, bool): Revenge has
// DoTankerExplosion__22CB4CrashActionDirectorP17CB4TrafficPhysicsfP17CGtAxisAlignedBoxb (0x204, B4CrashActionDirector.cpp;
// stabs params lpTankerVehicle, lrRaceCarPosInTankerSpaceZ, lpBBox, lbNetworkTriggered) with the same register list (a0
// this, a1 tanker, f12, a2 box, a3 bool); Nahelam's unverified list has the B3 spelling at this address (N90, verdict
// unknown). Callers: func_0023D0F0 (network: box 0, triggered 1, z 0) and HandleCrashingVehicleVehicleCollision. Parameter
// names from Revenge's stabs [L]; fields placeholders, types [G] from widths. Meaning [G]: mark the tanker's explosion
// (position + time into its effect block, flag bits), report it to the physics manager, tag every network player's car
// with state 5 / the tanker's id unless the explosion came from the network, then apply crash impulses by where the race
// car sits along the tanker (front / middle / back third of the box), the trailer too, and finish via func_00250160.
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

struct CGtAxisAlignedBox { CGtV3d field_0; CGtV3d field_10; };   // [L] min, max (B3CrashActionDirector_001B0E10.cpp)
struct UnkStruct_001ADA00_fx {
    unsigned char pad_0[0x1000];
    CGtV3dPlus field_1000;              // xyz = explosion position, w = time (D_00522680)
    unsigned char field_1010[4];
    unsigned char field_1014;           // state: 2
    unsigned char field_1015;           // flag bits: |= 0x18, &= ~6, |= 1 on the first explosion
    unsigned char field_1016;           // |= 0xF0
};
struct UnkStruct_001ADA00_veh {         // [L] CB3TrafficPhysics (fields seen here only)
    unsigned char pad_0[0x204];
    CGtMatrix3x4 *field_204;            // the vehicle matrix (mPos read)
    unsigned char pad_208[0xCC4 - 0x208];
    UnkStruct_001ADA00_fx *field_CC4;
    unsigned char pad_CC8[0x2424 - 0xCC8];
    UnkStruct_001ADA00_veh *field_2424; // [G] the trailer, impulsed with it when field_2428
    unsigned char field_2428;           // [G] has a trailer
    unsigned char field_2429;           // id byte copied to the network cars
};
struct UnkStruct_001ADA00_pl {          // the network player entry from func_002366D0
    unsigned char pad_0[0x4F0C];
    unsigned char field_4F0C;
    unsigned char pad_4F0D[3];
    int field_4F10;
};

extern float D_00522680;                // [G] game time (as BeginInstanceRender's archive)
extern unsigned char D_004EE040[];
extern unsigned char D_0055EF70[];      // the physics manager (func_001B2BA0's self)
extern unsigned char D_01E32AE0[];
extern int D_01E32B08;                  // network player count
extern unsigned char D_01E65499;
extern "C" bool func_00131E40(void *);
extern "C" void func_001B2BA0(void *, UnkStruct_001ADA00_veh *, int, int);
extern "C" UnkStruct_001ADA00_pl *func_002366D0(void *, int);
extern "C" void func_001CC4C0(void *, int, int, float);
extern "C" void func_00250160(UnkStruct_001ADA00_veh *);

// 0x001ADA00
extern "C" void func_001ADA00(void *self, UnkStruct_001ADA00_veh *lpTankerVehicle, float lrRaceCarPosInTankerSpaceZ,
                              CGtAxisAlignedBox *lpBBox, bool lbNetworkTriggered)
{
    UnkStruct_001ADA00_fx *fx = lpTankerVehicle->field_CC4;
    fx->field_1000.SetGtV3d(lpTankerVehicle->field_204->mPos);
    fx->field_1000.SetPlus(D_00522680);
    fx->field_1015 |= 0x18;
    lpTankerVehicle->field_CC4->field_1016 |= 0xF0;
    fx->field_1015 &= 0xF9;
    if (fx->field_1014 != 2) {
        fx->field_1014 = 2;
        fx->field_1015 |= 1;
    }
    if (!func_00131E40(D_004EE040)) return;
    func_001B2BA0(D_0055EF70, lpTankerVehicle, 1, 0);
    if (!lbNetworkTriggered) {
        unsigned char id = lpTankerVehicle->field_2429;
        for (int i = 0; i < D_01E32B08; i++) {
            UnkStruct_001ADA00_pl *p = func_002366D0(D_01E32AE0, i);
            if (p) {
                p->field_4F10 = 5;
                p->field_4F0C = id;
            }
        }
    }
    if (D_01E65499) {
        func_001CC4C0(lpTankerVehicle, 0x10, 1, 0.5f);
    } else if (lrRaceCarPosInTankerSpaceZ <= lpBBox->field_0.Z() * 0.3f) {
        if (!(lrRaceCarPosInTankerSpaceZ <= lpBBox->field_0.Z() * -0.3f))
            func_001CC4C0(lpTankerVehicle, 0x10, 1, 0.5f);
        else
            func_001CC4C0(lpTankerVehicle, 2, 1, 0.5f);
    } else {
        func_001CC4C0(lpTankerVehicle, 1, 1, 0.5f);
        if (lpTankerVehicle->field_2428) func_001CC4C0(lpTankerVehicle->field_2424, 2, 1, 0.5f);
    }
    if (lpTankerVehicle->field_2428) func_00250160(lpTankerVehicle);
}
