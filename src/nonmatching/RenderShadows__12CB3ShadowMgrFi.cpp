// NONMATCHING: RenderShadows__12CB3ShadowMgrFi -- retail 214 / ours 214 instructions, 102 in changed runs
// fix2 (2026-11-01): car pad_520 0x19C8 -> 0x13C8 (field_18E8/field_1914 were read 0x600 high) [C] retail 0x3034F4/0x303500; RenderAmbientShadow declared with CB3VehicleEssentialParams* (the placeholder type mangled to a symbol retail does not have) | Before: lit4fix: .lit4 externs rewritten as literals; was: a204: vehicle call passes &w->field_80 raw (POD link-name decl, retail has no copy there) -> 214 instrs; left: frame 0x140 vs 0x130 (each by-value CGtV3d arg temp leaves a dead 16B slot; retail has none), reg numbering
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)


// NONMATCHING: RenderShadows__12CB3ShadowMgrFi -- retail 214 / ours 216 instructions, 115 in changed runs
// a189: structure/logic complete (m2c-guided; 3 loops, RenderAmbientShadow(params, CGtV3d(vec.mData), vec.W(), f)), but 216 vs 214 instrs and register numbering off from the prologue (retail this=s4,p0=s3,n=s1,view idx=s0; ours this=s1,p0=s0), frame 0x150 vs retail 0x130 (two extra 16B temps from the CGtV3d(..)/W() copies). Not tuned further: >=8 saved regs.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// CB3ShadowMgr::RenderShadows(int) -- hand-written (a189); the lifter refused it.
// [C] name: the mangled symbol in retail's tables. Layout [G] from instruction widths; field names are placeholders.
#include "b3/GtMathPs2.h"

using namespace GtMathPs2;

struct UnkStruct_001_params { unsigned char pad_0[1]; };
struct UnkStruct_001_car {
    unsigned char pad_0[0x510];
    CGtV4d field_510;
    unsigned char pad_520[0x13C8];   // fix2: was 0x19C8 (field_18E8/1914 landed 0x600 high) [C] retail 0x3034F4/0x303500
    unsigned char field_18E8;
    unsigned char pad_18E9[0x2B];
    int field_1914;
};
struct UnkStruct_001_race {
    unsigned char pad_0[0x1360];
    unsigned char pad_1360[0x510];
    CGtV4d field_1870;
    unsigned char pad_1880[0x0];
};
struct UnkStruct_001_race2 {
    unsigned char pad_0[0x13BB];
    signed char field_13BB;
};
struct UnkStruct_001_viewer { unsigned char pad_0[0x19AC]; signed char field_19AC; };
struct UnkStruct_001_66270_b { unsigned char pad_0[0x20]; CGtV4d field_20; };
struct UnkStruct_D_00666270 { unsigned char pad_0[0x68]; UnkStruct_001_66270_b * field_68; unsigned char pad_6C[0xC]; };
struct UnkStruct_D_01E85900_e { unsigned char pad_0[0xB0]; CGtV3d field_B0; };

struct a204_pod { u_long128 q; };
class CB3ShadowMgr;
class CB3VehicleEssentialParams;
extern "C" void RenderAmbientShadow__12CB3ShadowMgrFP25CB3VehicleEssentialParamsQ29GtMathPs26CGtV3dff(CB3ShadowMgr *, UnkStruct_001_params *, a204_pod, float, float);
class CB3ShadowMgr {
public:
    void RenderShadows(int p0);
    void RenderAmbientShadow(CB3VehicleEssentialParams * p0, CGtV3d p1, float p2, float p3);   // [C] retail symbol ...FP25CB3VehicleEssentialParams...

    CGtV4d field_0;
    void * field_10;
    unsigned char pad_14[0xC];
    CGtV3d field_20;
};

struct UnkStruct_world_veh {
    unsigned char pad_0[0x70];
    UnkStruct_001_params field_70;
    unsigned char pad_71[0xF];
    CGtV3d field_80;
    unsigned char pad_90[0x3B];
    signed char field_CB;
    unsigned char pad_CC[0xA8];
    unsigned char field_174;
    unsigned char pad_175[1];
    unsigned char field_176;
    unsigned char pad_177[3];
    unsigned char field_17A;
};
struct UnkStruct_world_p { unsigned char pad_0[0x18]; float field_18; };
struct UnkStruct_D_004EE040_e { unsigned char pad_0[0xBB0]; };
struct UnkStruct_D_0064D37C { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_00665F27 { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_01E85A30 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_00522660 { unsigned char pad_0[0x27D0]; };
struct UnkStruct_D_00527440 { unsigned char pad_0[0x10]; };

extern UnkStruct_D_00522660 D_00522660;
extern UnkStruct_D_00527440 D_00527440;
extern UnkStruct_D_004EE040_e D_004EE040[];
extern UnkStruct_D_0064D37C D_0064D37C;
extern UnkStruct_D_00665F27 D_00665F27;
extern UnkStruct_D_00666270 * D_00666270;
extern UnkStruct_D_01E85A30 D_01E85A30;
extern UnkStruct_D_01E85900_e D_01E85900[];

extern "C" void BeginShadowRendering__17CB3ShadowRendererFv(void *);
extern "C" void BeginShadowPlaneRendering__17CB3ShadowRendererFv();
extern "C" void EndShadowPlaneRendering__17CB3ShadowRendererFv();
extern "C" void EndShadowRendering__17CB3ShadowRendererFv();
extern "C" int IsPlayerVisible__22CB3PlayerCameraManagerFv(void *);

// 0x003033F0
void CB3ShadowMgr::RenderShadows(int p0)
{
    int n = D_0064D37C.field_0;
    if (D_00665F27.field_0 == 0) return;
    {
        field_10 = (char *)&D_00522660 + p0 * 0x1CC + 0x12A348;
        UnkStruct_001_viewer * v = (UnkStruct_001_viewer *)((char *)&D_00522660 + p0 * 0x27D0 + 0x12AD50);
        field_0 = D_00666270->field_68->field_20;
        field_20 = -D_01E85900[D_01E85A30.field_0].field_B0;
        int s = v->field_19AC;
        BeginShadowRendering__17CB3ShadowRendererFv(v);
        BeginShadowPlaneRendering__17CB3ShadowRendererFv();
        float f = 0.06f;
        for (int i = 0; i < n; i++) {
            UnkStruct_001_car * c = *(UnkStruct_001_car **)((char *)&D_00522660 + i * 4 + 0x12AD28);
            if (c->field_18E8 != 0) {
                if (c->field_1914 == 0) {
                    if (IsPlayerVisible__22CB3PlayerCameraManagerFv((char *)&D_004EE040[p0] + 0x28E00) != 0) {
                        RenderAmbientShadow((CB3VehicleEssentialParams *)c, CGtV3d(c->field_510.mData), c->field_510.W(), f);
                    }
                } else {
                    RenderAmbientShadow((CB3VehicleEssentialParams *)c, CGtV3d(c->field_510.mData), c->field_510.W(), f);
                }
            }
        }
        for (int j = 0; j < *((unsigned char *)&D_00527440 + s + 0x36350); j++) {
            UnkStruct_world_veh * w = (UnkStruct_world_veh *)((char *)&D_00527440 + *((unsigned char *)&D_00527440 + s * 0xFE + j + 0x35C24) * 0x180 + 0x127D0);
            if ((w->field_174 & 4) == 0 && (w->field_17A & 2) == 0 && w->field_CB != 0) {
                UnkStruct_world_p * q = *(UnkStruct_world_p **)((char *)&D_00527440 + w->field_176 * 4 + 0x343F0);
                if (q != 0) {
                    RenderAmbientShadow__12CB3ShadowMgrFP25CB3VehicleEssentialParamsQ29GtMathPs26CGtV3dff(this, &w->field_70, *(a204_pod *)&w->field_80, q->field_18, f);
                }
            }
        }
        for (int k = 0; k < *(int *)((char *)&D_00522660 + 0x122B1C); k++) {
            UnkStruct_001_race2 * r = *(UnkStruct_001_race2 **)((char *)&D_00522660 + k * 4 + 0x122A10);
            if (r->field_13BB != 0) {
                UnkStruct_001_race * rr = (UnkStruct_001_race *)r;
                RenderAmbientShadow((CB3VehicleEssentialParams *)((char *)r + 0x1360), CGtV3d(rr->field_1870.mData), rr->field_1870.W(), f);
            }
        }
        EndShadowPlaneRendering__17CB3ShadowRendererFv();
        EndShadowRendering__17CB3ShadowRendererFv();
    }
}
