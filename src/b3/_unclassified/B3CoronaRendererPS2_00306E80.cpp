// CB3CoronaRenderer::UploadCodeAndStaticData(float) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3CoronaRendererPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (Ghidra draft + Debris UploadCodeAndCameraData sibling; lane-setter stand-ins (scalar on vf1), SetPlus(Z) stand-in, ZAxisType(p->mData) lane read, p[k] stores, large N140 pad (12 slots)).

// CB3CoronaRenderer::UploadCodeAndStaticData(float) -- hand-written (ghvu7) from the Ghidra draft and the sibling
// CB3DebrisRenderer::UploadCodeAndCameraData (B3DebrisRendererPS2_002F3B60.cpp). [C] name: the mangled symbol in
// retail's tables. Field names are placeholders and every type is [G].
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

struct UnkStruct_farFogPlane { u_long128 *field_0; };
struct UnkStruct_skyUserSwitch1 { void *field_0; };
struct UnkStruct_D_00667050 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_00665EC0 { unsigned char pad_0[0x10]; };
extern UnkStruct_farFogPlane farFogPlane;
extern UnkStruct_skyUserSwitch1 skyUserSwitch1;
extern UnkStruct_D_00667050 D_00667050;
extern UnkStruct_D_00665EC0 D_00665EC0;
extern char vu_game_00478260[];
struct UnkStruct_00306E80_cam {
    unsigned char pad_0[0x550];
    CGtV3d field_550[4];
    unsigned char pad_590[0x48];
    float field_5D8;
    unsigned char pad_5DC[4];
    float field_5E0;
    float field_5E4;
    float field_5E8;
    unsigned char pad_5EC[0xC];
    float field_5F8;
    unsigned char pad_5FC[0xC];
    float field_608;
    unsigned char pad_60C[0x64];
    float field_670;
    float field_674;
    float field_678;
    unsigned char pad_67C[0xC];
    float field_688;
    float field_68C;
};

// [L] N185: stand-ins for CGtV4d lane setters with the scalar on $vf1 and the vector on a compiler-chosen register.
static inline void func_00306E80_inl1(CGtV4d &v, float f) { asm("qmtc2.ni %1, $vf1" "\n\t" "vaddx.x %0, $vf0, $vf1x" : "+j"(v.mData) : "r"(f)); }
static inline void func_00306E80_inl2(CGtV4d &v, float f) { asm("qmtc2.ni %1, $vf1" "\n\t" "vaddx.y %0, $vf0, $vf1x" : "+j"(v.mData) : "r"(f)); }
static inline void func_00306E80_inl3(CGtV4d &v, float f) { asm("qmtc2.ni %1, $vf1" "\n\t" "vaddx.z %0, $vf0, $vf1x" : "+j"(v.mData) : "r"(f)); }
static inline void func_00306E80_inl4(CGtV4d &v, float f) { asm("qmtc2.ni %1, $vf1" "\n\t" "vmulx.w %0, $vf0, $vf1x" : "+j"(v.mData) : "r"(f)); }
// [L] N185: CGtV3dPlus::SetPlus(ZAxisType) stand-in (w = 0 + z; the API exists for Y in the header).
static inline void func_00306E80_inl5(CGtV3dPlus &v, ZAxisType z) { asm("vsubw.w %0, $vf0, $vf0w" "\n\t" "vaddz.w %0, %0, %1z" : "+j"(v.mData) : "j"(z.lVector)); }

// N140 pad (large, 0xC0 bytes): stands in for twelve dead 16-byte frame slots retail keeps below the two vector
// locals (by-value inline temporaries of the original lane setters [G]); it emits no code.
struct UnkStruct_00306E80_pad { int x[48]; UnkStruct_00306E80_pad() {} ~UnkStruct_00306E80_pad() {} };
class CB3CoronaRenderer { public: void UploadCodeAndStaticData(float); };
// 0x00306E80
void CB3CoronaRenderer::UploadCodeAndStaticData(float)
{
    CGtV4d v;
    CGtV3dPlus row;
    UnkStruct_00306E80_pad pad;
    UnkStruct_00306E80_cam *c = (UnkStruct_00306E80_cam *)((char *)&D_00665EC0 + D_00667050.field_0 * 0x230);
    u_long128 *p = farFogPlane.field_0;
    asm("pcpyld %0, %2, %1" : "=r"(p[0]) : "r"(((unsigned long)(unsigned int)vu_game_00478260 << 32) | 0x50000000UL), "r"(0x0200009003000000UL));
    skyUserSwitch1.field_0 = vu_game_00478260;
    asm("pcpyld %0, %2, %1" : "=r"(p[1]) : "r"(0x10000009UL), "r"(0x6C0903F701000101UL));
    row.SetGtV3d(c->field_550[0]);
    func_00306E80_inl5(row, ZAxisType(c->field_550[0].mData));
    p[2] = row.mData;
    row.SetGtV3d(c->field_550[1]);
    func_00306E80_inl5(row, ZAxisType(c->field_550[1].mData));
    p[3] = row.mData;
    row.SetGtV3d(c->field_550[2]);
    func_00306E80_inl5(row, ZAxisType(c->field_550[2].mData));
    p[4] = row.mData;
    row.SetGtV3d(c->field_550[3]);
    func_00306E80_inl5(row, ZAxisType(c->field_550[3].mData));
    p[5] = row.mData;
    func_00306E80_inl1(v, c->field_688 + 64.0f);
    func_00306E80_inl2(v, c->field_68C + 64.0f);
    func_00306E80_inl3(v, c->field_608);
    func_00306E80_inl4(v, c->field_5F8);
    p[6] = v.mData;
    func_00306E80_inl1(v, c->field_5E0);
    func_00306E80_inl2(v, c->field_5E4);
    func_00306E80_inl3(v, c->field_5E8);
    func_00306E80_inl4(v, c->field_5D8);
    p[7] = v.mData;
    func_00306E80_inl1(v, c->field_688);
    func_00306E80_inl2(v, c->field_68C);
    func_00306E80_inl3(v, c->field_670);
    func_00306E80_inl4(v, c->field_674);
    p[8] = v.mData;
    func_00306E80_inl1(v, 8.0f);
    func_00306E80_inl3(v, c->field_678);
    p[9] = v.mData;
    asm("pcpyld %0, %2, %1" : "=r"(p[10]) : "r"(0x502B400000000000UL), "r"(0x42412UL));
    farFogPlane.field_0 = p + 11;
}
