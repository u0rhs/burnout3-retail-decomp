// NONMATCHING: PrepareRenderStatesForRenderingTrack__16CB3TrackRendererFv -- retail 111 / ours 112 instructions, 55 in changed runs
// a234: 111/112 instrs, 55 in changed runs, frame 0x80 OK (5 N140 pads). VU numbering of the vector section matches (hard-coded $vf1 via header -operator()/SetGtV3d; consts defined late; stand-ins: qmtc2.i scalar to VU, SetPlus with compiler-chosen scalar reg (header SetPlus hard-codes $vf1), Y-lane add+SetY(Y) pair 'vaddx.y $vf1,v,sx; vaddy.y v,$vf0,$vf1y'). Left: GPR assignment/scheduling of 0x70002C00 / 1 / loop-base constants (retail hoists lui t4,t3 + li after the call), float k/field mul operand regs, loop i in v1 vs a1
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
// [L] N185 stand-ins (header gaps): compiler-chosen scalar-lane forms
static inline u_long128 a234_vs(float f) { u_long128 sv; asm("qmtc2.i %1, %0" : "=j"(sv) : "r"(f)); return sv; }
static inline void a234_setplus(u_long128 &d, u_long128 sv) { asm("vsubw.w %0, $vf0, $vf0w" "\n\t" "vaddx.w %0, %0, %1x" : "+j"(d) : "j"(sv)); }
static inline void a234_yplus(u_long128 &d, u_long128 sv) { asm("vaddx.y $vf1, %0, %1x" "\n\t" "vaddy.y %0, $vf0, $vf1y" : "+j"(d) : "j"(sv)); }
struct UnkStruct_0026B8E0_pad { int x[4]; UnkStruct_0026B8E0_pad() {} ~UnkStruct_0026B8E0_pad() {} };
struct UnkStruct_mesh { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_00666270 { unsigned char pad_0[0x6C]; float field_6C; };
struct UnkStruct_00666330 { unsigned char pad_0[0xA0]; u_long128 field_A0; unsigned char pad_B0[0x20]; u_long128 field_D0; };
struct UnkStruct_D_01E85900 { unsigned char pad_0[0xB0]; u_long128 field_B0; };
struct UnkStruct_flt { float field_0; };
struct UnkStruct_int { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_00665EC0 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01E327D0 { u_long128 q[6]; };
extern UnkStruct_mesh *_gpMeshCache;
extern UnkStruct_D_00666270 *D_00666270;
extern UnkStruct_00666330 D_00666330;
extern UnkStruct_D_01E85900 D_01E85900[];
extern UnkStruct_int D_01E85A30;
extern UnkStruct_int D_00667054;
extern UnkStruct_D_00665EC0 D_00665EC0;
extern UnkStruct_D_01E327D0 D_01E327D0[];
extern UnkStruct_flt D_004E0F18;
extern UnkStruct_flt D_004E0F1C;
extern "C" void RpSkyRenderStateGet(int, int *);
extern "C" float func_0011E370(float);
class CB3TrackRenderer { public:
    void PrepareRenderStatesForRenderingTrack();
    unsigned char pad_0[0x30];
    CGtV3dPlus field_30;
    CGtV3dPlus field_40;
    CGtV3dPlus field_50;
    u_long128 field_60;
    unsigned char pad_70[0x24];
    int field_94;
    unsigned char field_98;
    signed char field_99;
    unsigned char field_9A;
    unsigned char pad_9B;
    unsigned char field_9C;
    unsigned char pad_9D[3];
    unsigned long field_A0;
    unsigned long field_A8;
    unsigned long field_B0;
    unsigned long field_B8;
    int field_C0;
    int field_C4;
    float field_C8;
};
// 0x0026B8E0
void CB3TrackRenderer::PrepareRenderStatesForRenderingTrack()
{
    UnkStruct_0026B8E0_pad pp0;
    UnkStruct_0026B8E0_pad pp1;
    UnkStruct_0026B8E0_pad pp2;
    UnkStruct_0026B8E0_pad pp3;
    UnkStruct_0026B8E0_pad pp4;
    UnkStruct_00666330 * const s = &D_00666330;
    RpSkyRenderStateGet(2, &field_C0);
    RpSkyRenderStateGet(3, &field_C4);
    float k = D_004E0F18.field_0;
    field_30.SetGtV3d(-CGtV3d(D_01E85900[D_01E85A30.field_0].field_B0));
    u_long128 v = s->field_D0;
    field_50.SetGtV3d(CGtV3d(v));
    field_60 = s->field_A0;
    u_long128 one = a234_vs(1.0f);
    u_long128 ten = a234_vs(10.0f);
    a234_yplus(v, ten);
    field_40.SetGtV3d(CGtV3d(v));
    a234_setplus(field_30.mData, ten);
    a234_setplus(field_40.mData, one);
    _gpMeshCache = (UnkStruct_mesh *)0x70002C00;
    field_94 = 0;
    _gpMeshCache->field_0 = 0;
    field_98 = 0;
    field_A0 = 0;
    field_A8 = 0;
    field_B0 = 0;
    field_B8 = 0;
    field_99 = -1;
    field_C8 = func_0011E370(D_00666270->field_6C * k) / D_004E0F1C.field_0;
    field_9A = 1;
    field_9C = 0;
    char * const srcb = (char *)&D_00665EC0;
    UnkStruct_D_01E327D0 * const dstb = D_01E327D0;
    int n = D_00667054.field_0;
    for (int i = 0; i < n; i++) {
        u_long128 *src = (u_long128 *)(srcb + i * 0x230 + 0x470);
        UnkStruct_D_01E327D0 *dst = &dstb[i];
        dst->q[0] = src[0];
        dst->q[1] = src[1];
        dst->q[2] = src[2];
        dst->q[3] = src[3];
        dst->q[4] = src[4];
        dst->q[5] = src[5];
    }
}
