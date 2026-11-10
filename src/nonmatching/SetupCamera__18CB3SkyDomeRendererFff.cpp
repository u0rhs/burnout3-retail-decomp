// NONMATCHING: SetupCamera__18CB3SkyDomeRendererFff -- retail 91 / ours 91 instructions, 128 in changed runs
// fix1 (2026-11-01): field_40/field_60 z,w pairs were swapped (port6 checker/replay); now as retail 0x21E0A0 | Before: ghvu3: logic exact, 91/91 instrs; [L] N185 stand-ins (CGtV4d Zero/SetY compiler-chosen, SetGtV3d src on $vf2, SetPlus(ZAxisType) src on $vf1). Left: retail loads each camera row twice (lqc2 $vf2 / lqc2 $vf1), ours folds the 2nd into vmove -> scheduling differs; frame 0x90 vs 0xC0 (by-value params read through address give 6 of 9 dead slots)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [C] fix1 (2026-11-01): 24/24 port6 live captures pass the Burn3 checker at tolerance 0; 6 replay identical on the host (capture_replay) -- on those inputs


// Hand-written (ghvu3, Ghidra draft); the lifter refused it. The sky dome's camera block: the current camera's three
// rotation rows (each with its z lane in w), a (0, -h, 0, 0) offset, three packed float quads; then a fractional phase.
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
struct UnkStruct_mCameraParams {
    CGtV3dPlus field_0;
    CGtV3dPlus field_10;
    CGtV3dPlus field_20;
    CGtV4d field_30;
    CGtV4d field_40;
    CGtV4d field_50;
    CGtV4d field_60;
};
struct UnkStruct_maParams { unsigned char pad_0[0x140]; float field_140; };
struct UnkStruct_00665EC0_cam {
    CGtV3d field_0;
    CGtV3d field_10;
    CGtV3d field_20;
    unsigned char pad_30[0x60];
    float field_90;
    float field_94;
    unsigned char pad_98[8];
    float field_A0;
    float field_A4;
    unsigned char pad_A8[8];
    float field_B0;
    float field_B4;
    unsigned char pad_B8[0x80];
    float field_138;
    float field_13C;
    unsigned char pad_140[0xF0];
};
struct UnkStruct_D_00665EC0 { unsigned char pad_0[0x550]; UnkStruct_00665EC0_cam field_550[1]; };
struct UnkStruct_D_00667050 { int field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_00665EC0 D_00665EC0;
extern UnkStruct_D_00667050 D_00667050;
class CB3SkyDomeRenderer {
public:
    static void SetupCamera(float t, float h);
    static UnkStruct_mCameraParams mCameraParams;
    static UnkStruct_maParams maParams;
};
// [L] N185: stands in for CGtV3dPlus::SetPlus(ZAxisType) (B3O0PCH map, 80 bytes): as the header's SetPlus(YAxisType), lane z
static inline void func_0021DF80_inl1(CGtV3dPlus &p, ZAxisType z) { asm("qmtc2 %1, $vf1" "\n\t" "vsubw.w %0, $vf0, $vf0w" "\n\t" "vaddz.w %0, %0, $vf1z" : "+j"(p.mData) : "r"(*(const u_long128 *)&z.lVector)); }
// [L] N185: CGtV3dPlus::SetGtV3d(CGtV3d) with the source on a hard-coded $vf2 (retail reloads each row for it and reuses $vf2)
static inline void func_0021DF80_inl4(CGtV3dPlus &p, CGtV3d v) { asm("qmtc2 %1, $vf2" "\n\t" "vadd.xyz %0, $vf0, $vf2" : "+j"(p.mData) : "r"(*(const u_long128 *)&v.mData)); }
// [L] N185: CGtV4d::SetY(float) with compiler-chosen registers (retail `qmtc2.ni s,$vf1; vaddx.y $vf2,$vf0,$vf1x`; the header body
// hard-codes this vector on $vf1 and the scalar on $vf2), as the header CGtV3d::SetY(float)
static inline void func_0021DF80_inl2(CGtV4d &v, float y) { u_long128 s; asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(y)); asm("vaddx.y %0, $vf0, %1x" : "+j"(v.mData) : "j"(s)); }
// [L] N185: CGtV4d::Zero() on a compiler-chosen register (retail `vsub.xyzw $vf2, $vf0, $vf0`; the header hard-codes $vf1)
static inline void func_0021DF80_inl3(CGtV4d &v) { asm("vsub.xyzw %0, $vf0, $vf0" : "=j"(v.mData)); }
// 0x0021DF80
void CB3SkyDomeRenderer::SetupCamera(float t, float h)
{
    UnkStruct_00665EC0_cam *cam = (UnkStruct_00665EC0_cam *)((char *)&D_00665EC0 + 0x550 + D_00667050.field_0 * 0x230);
    CGtV4d o;
    func_0021DF80_inl3(o);
    func_0021DF80_inl2(o, -h);
    mCameraParams.field_30 = o;
    func_0021DF80_inl4(mCameraParams.field_0, cam->field_0);
    func_0021DF80_inl1(mCameraParams.field_0, cam->field_0.Z());
    func_0021DF80_inl4(mCameraParams.field_10, cam->field_10);
    func_0021DF80_inl1(mCameraParams.field_10, cam->field_10.Z());
    func_0021DF80_inl4(mCameraParams.field_20, cam->field_20);
    func_0021DF80_inl1(mCameraParams.field_20, cam->field_20.Z());
    mCameraParams.field_50 = CGtV4d(cam->field_A0, cam->field_A4, -0.0002000039967f, 5.0f);
    // fix1: z/w pairs as retail [C] 0x21E0A0..: +0x60 from sp+0x10 = (B0, B4, D_004E0F10, D_004E0E88), +0x40 from sp+0 = (138, 13C, 90, 94)
    mCameraParams.field_60 = CGtV4d(cam->field_B0, cam->field_B4, 1.000040054f, 9.999999747e-05f);
    mCameraParams.field_40 = CGtV4d(cam->field_138, cam->field_13C, cam->field_90, cam->field_94);
    float f = 2.0f * t;
    maParams.field_140 = f - ((float)(int)f + 1.0f);
}
