// NONMATCHING: RenderRaceCars__8CB3WorldFii -- retail 220 / ours 211 instructions, 112 in changed runs
// a193: squared-distance loop matched with the explicit 1.0 hoist (pinned inl2); the natural b119p form (1.0 as own =j stmt inside inl2) did NOT hoist here and shifted vf regs (271 diff), so explicit form kept. Left: loop 1 field_12AD28[i] reload (b119 CSEs into s0), out-of-line arms, frame 0xC0 vs 0xA0
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// NONMATCHING: RenderRaceCars__8CB3WorldFii -- retail 220 / ours 211 instructions, 112 in changed runs
// vu0h: hand-written (lifter refused). The squared-distance loop matches retail exactly (cam hoisted in vf1, explicit 1.0 hoist =j -> vf3, tied 'vsub %0,%0,%1' helper + square on a pinned vf2). Left: loop 1 -- retail reloads field_12AD28[i] for each use (b119 CSEs it into s0 and keeps an extra s5 for the camera-manager base; volatile/pun/accessor forms tried), retail puts the 1914/IsPlayerVisible arms and loop 3's body out of line, frame 0xC0 vs 0xA0
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

class CB3VehicleEssentialParams;
class CB3VehicleParams;
class CB3RaceCar {
public:
    void Draw();
    unsigned char pad_0[0x30];
    CGtV3d field_30;
    unsigned char pad_40[0x1A];
    signed char field_5A;
    signed char field_5B;
    unsigned char pad_5C[0x24];
    unsigned char field_80[0x1022];              // [G] the CB3VehicleParams passed with this car
    unsigned char field_10A2;
    unsigned char pad_10A3[0x871];
    int field_1914;
    unsigned char pad_1918[0xEA8];
    int field_27C0;
};
class CB3StreamedTrack {
public:
    bool IsUnitVisibleToMainCamera(int unit);
    void ComputeVehicleRenderData(CB3VehicleEssentialParams* p, float f);
    unsigned char pad_0[0x1CC];                  // [G] stride of CB3World's array
};
class CB3PlayerCameraManager { public: bool IsPlayerVisible(); unsigned char pad_0[0xBB0]; };   // [G] stride
class CB3VehicleRenderer {
public:
    unsigned char pad_0[0x10];                   // [G] size: absolute addressing needs > 8 bytes (N50)
    void SetupCameraData();
    void BeginVehicleRendering();
    void EndVehicleRendering();
    void FrustumTestDamagedVehicle(CB3VehicleEssentialParams* p, CB3VehicleParams* q);
};
extern CB3VehicleRenderer gVehicleRenderer;
struct UnkStruct_D_004EE040 {
    unsigned char pad_0[0x28E00];
    CB3PlayerCameraManager field_28E00[2];       // [G] element count unknown
};
extern UnkStruct_D_004EE040 D_004EE040;
struct UnkStruct_00199A20_c { unsigned char pad_0[0x20]; CGtV3d field_20; };
struct UnkStruct_00199A20_g { unsigned char pad_0[0x68]; UnkStruct_00199A20_c* field_68; };
struct UnkStruct_D_00666270 { UnkStruct_00199A20_g* field_0; unsigned char pad_4[0xC]; };   // [G] size: absolute addressing (N50)
extern UnkStruct_D_00666270 D_00666270;
extern "C" int func_00199D90(const void*, const void*);
extern "C" void qsort(void *, unsigned int, unsigned int, int (*)(const void *, const void *));

struct UnkStruct_00199A20_e { CB3RaceCar* field_0; float field_4; };
class CB3World {
public:
    void RenderRaceCars(int view, int track);
    unsigned char pad_0[0x12A348];
    CB3StreamedTrack field_12A348[5];            // [G] element count unknown
    unsigned char pad_12AC44[0x12AD1C - 0x12AC44];
    int field_12AD1C;
    unsigned char pad_12AD20[0x8];
    CB3RaceCar* field_12AD28[6];
};
extern "C" signed char TestPosition__16CB3StreamedTrackFQ29GtMathPs26CGtV3d(CB3StreamedTrack* self, const CGtV3d* pos);   // CB3StreamedTrack::TestPosition(CGtV3d)
static inline CGtV3d func_00199A20_inl1(CGtV3d a, CGtV3d b)
{
    u_long128 t;
    asm("vsub.xyz %0, %0, %1" : "=j"(t) : "j"(b.mData), "0"(a.mData));
    return CGtV3d(t);
}
static inline float func_00199A20_inl2(CGtV3d a, u_long128 one)
{
    u_long128 t;
    asm("qmtc2 %1, $vf2" "\n\t" "vmul.xyz $vf2, $vf2, $vf2" "\n\t" "vadday.x $ACC, $vf2, $vf2y" "\n\t" "vmaddz.x $vf2, %2, $vf2z" "\n\t" "qmfc2 %0, $vf2" : "=r"(t) : "r"(a.mData), "j"(one));
    return XAxisType(t);
}
// 0x00199A20
void CB3World::RenderRaceCars(int view, int track)
{
    UnkStruct_00199A20_e list[6];
    for (int i = 0; i < field_12AD1C; i++) {
        if (field_12AD28[i]->field_1914 != 0) {
            list[i].field_0 = field_12AD28[i];
        } else if (field_12AD28[i]->field_27C0 == view) {
            if (D_004EE040.field_28E00[view].IsPlayerVisible()) list[i].field_0 = field_12AD28[i];
            else list[i].field_0 = 0;
        } else {
            list[i].field_0 = field_12AD28[i];
        }
    }
    for (int i = 0; i < field_12AD1C; i++) {
        UnkStruct_00199A20_e* e = &list[i];
        if (e->field_0) {
            e->field_0->field_5A = TestPosition__16CB3StreamedTrackFQ29GtMathPs26CGtV3d(&field_12A348[track], &e->field_0->field_30);
            if (!field_12A348[track].IsUnitVisibleToMainCamera(e->field_0->field_5A)) e->field_0 = 0;
        }
    }
    for (int i = 0; i < field_12AD1C; i++) {
        UnkStruct_00199A20_e* e = &list[i];
        if (e->field_0) {
            gVehicleRenderer.FrustumTestDamagedVehicle((CB3VehicleEssentialParams*)e->field_0, (CB3VehicleParams*)e->field_0->field_80);
            if (e->field_0->field_5B == 0 && e->field_0->field_10A2 == 0) e->field_0 = 0;
        }
    }
    CGtV3d cam = D_00666270.field_0->field_68->field_20;
    u_long128 one;
    asm("vaddw.x %0, $vf0, $vf0w" : "=j"(one));   // FAKEMATCH [G] N163: explicit 1.0 hoist
    for (int i = 0; i < field_12AD1C; i++) {
        UnkStruct_00199A20_e* e = &list[i];
        if (e->field_0) e->field_4 = func_00199A20_inl2(func_00199A20_inl1(e->field_0->field_30, cam), one);
        else e->field_4 = 0.0f;
    }
    qsort(list, field_12AD1C, sizeof(UnkStruct_00199A20_e), func_00199D90);
    for (int i = 0; i < field_12AD1C; i++) {
        if (list[i].field_0) field_12A348[track].ComputeVehicleRenderData((CB3VehicleEssentialParams*)list[i].field_0, 20.0f);
    }
    gVehicleRenderer.SetupCameraData();
    gVehicleRenderer.BeginVehicleRendering();
    for (int i = 0; i < field_12AD1C; i++) {
        if (list[i].field_0) list[i].field_0->Draw();
    }
    gVehicleRenderer.EndVehicleRendering();
}
