// NONMATCHING: UploadStaticDataAndCallCode__16CB3SparkRendererFPC13CB3SparkArrayb -- retail 164 / ours 164 instructions, 86 in changed runs
// ghvu10: 164/164, frame 0x30 exact; 86 instrs in changed runs, ALL a register rotation (retail i=t0, frame base=a2, &D_01E31A30=v1; ours i=v1, base=t0, &D=a2) that carries into the packet pointer. Tried loop forms (goto/for/while/||), decl orders, direct global indexing, sreg (2 rounds, 86->83 only).
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// CB3SparkRenderer::UploadStaticDataAndCallCode(const CB3SparkArray*, bool) -- hand-written (ghvu10, Ghidra draft).
// [C] name: the mangled symbol in retail's tables; file: research/retail_names.csv -> B3SparkRendererPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Field names are placeholders and every type is [G].
// Static: a0 is the spark array (no `this`), a1 the crash flag (EndRender passes true).

#include "b3/GtMathPs2.h"

using GtMathPs2::CGtV3d;
using GtMathPs2::CGtV4d;

class CB3CameraData { public: unsigned char pad_0[0x168]; float field_168; unsigned char pad_16C[4]; float field_170; float field_174; float field_178; unsigned char pad_17C[0xB4]; };
struct UnkStruct_00263420_prm {
    unsigned char pad_0[0x50];
    float field_50;
    unsigned char pad_54[4];
    float field_58;
    float field_5C;
    unsigned char pad_60[0xC];
    float field_6C;
    float field_70;
    float field_74;
    float field_78;
};
class CB3SparkArray {
public:
    unsigned char pad_0[0x48];
    unsigned int field_48;
    unsigned char pad_4C[0x48];
    unsigned int field_94;
    UnkStruct_00263420_prm *field_98;
    void *field_9C;
    float field_A0;
    unsigned char field_A4;
};
class CB3SparkRenderer {
public:
    static void UploadStaticDataAndCallCode(const CB3SparkArray *, bool);
    static int mnRenderPlayer;
    class CSparkFrameData {
    public:
        u_long128 field_0;
        u_long128 field_10;
        u_long128 field_20;
        u_long128 field_30;
        u_long128 field_40;
        CGtV3d field_50;
    };
};
struct UnkStruct_00263420_sf { CB3SparkRenderer::CSparkFrameData field_0[18]; };
struct UnkStruct_D_00665EC0 { unsigned char pad_0[0x470]; CB3CameraData field_470[1]; };
struct UnkStruct_D_00667050 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01E31A20 { u_long128 field_0; };
struct UnkStruct_farFogPlane { u_long128 *field_0; };
struct UnkStruct_00263420_hd { int field_0; float field_4; float field_8; float field_C; };
union UnkStruct_00263420_q { u_long128 q; UnkStruct_00263420_hd h; };

extern UnkStruct_farFogPlane farFogPlane;
extern UnkStruct_D_00665EC0 D_00665EC0;
extern UnkStruct_D_00667050 D_00667050;
extern UnkStruct_D_01E31A20 D_01E31A20;
extern UnkStruct_00263420_sf D_01E31A30[];

// [L] N185: stand-ins for CGtV4d::SetX/SetY/SetZ/SetA(float) with the scalar on $vf1 and the vector on a
// compiler-chosen register (retail `qmtc2.ni s,$vf1; vaddx.x $vf2,$vf0,$vf1x`; header bodies pin other registers).
static inline void func_00263420_inl1(CGtV4d &v, float x) { asm("qmtc2.ni %1, $vf1\n\tvaddx.x %0, $vf0, $vf1x" : "+j"(v.mData) : "r"(x)); }
static inline void func_00263420_inl2(CGtV4d &v, float y) { asm("qmtc2.ni %1, $vf1\n\tvaddx.y %0, $vf0, $vf1x" : "+j"(v.mData) : "r"(y)); }
static inline void func_00263420_inl3(CGtV4d &v, float z) { asm("qmtc2.ni %1, $vf1\n\tvaddx.z %0, $vf0, $vf1x" : "+j"(v.mData) : "r"(z)); }
static inline void func_00263420_inl4(CGtV4d &v, float w) { asm("qmtc2.ni %1, $vf1\n\tvmulx.w %0, $vf0, $vf1x" : "+j"(v.mData) : "r"(w)); }

// [L] N185: x lane to an FPR straight from the 128-bit value (retail `lq; mtc1`, no stack slot; the header's
// XAxisType::operator float reads through the temporary's address).
static inline float func_00263420_inl5(const CGtV3d &v) { float f; asm("mtc1 %1, %0" : "=f"(f) : "r"(v.mData)); return f; }

// 0x00263420
void CB3SparkRenderer::UploadStaticDataAndCallCode(const CB3SparkArray *a, bool crash)
{
    UnkStruct_00263420_q hd;
    CGtV4d v;
    CSparkFrameData *f = D_01E31A30[mnRenderPlayer].field_0;
    const UnkStruct_00263420_prm *prm = a->field_98;
    int i = 1;
    goto test;
body:
    if (!(func_00263420_inl5(f[i].field_50) - func_00263420_inl5(f[0].field_50) < prm->field_5C)) goto done;
    if (func_00263420_inl5(f[i].field_50) == func_00263420_inl5(f[i + 1].field_50)) goto done;
    i++;
test:
    if (i < 17) goto body;
done:
    int n = crash ? 0x70 : 2;
    u_long128 q0;
    asm("pcpyld %0, %2, %1" : "=r"(q0) : "r"((long)n | 0x10000000), "r"(((unsigned long)(unsigned int)((n << 16) | 0x6C000390) << 32) | 0x1000101));
    u_long128 *p = farFogPlane.field_0;
    *p++ = q0;
    float x = prm->field_6C;
    func_00263420_inl1(v, x);
    func_00263420_inl2(v, prm->field_70);
    func_00263420_inl3(v, prm->field_78);
    func_00263420_inl4(v, (prm->field_74 - x) / prm->field_5C);
    *p++ = v.mData;
    hd.h.field_0 = i;
    hd.h.field_4 = a->field_A0;
    hd.h.field_8 = prm->field_58;
    hd.h.field_C = prm->field_50;
    *p++ = hd.q;
    if (crash) {
        const CB3CameraData *c = &D_00665EC0.field_470[D_00667050.field_0];
        v = CGtV4d(c->field_170, c->field_174, c->field_178, c->field_168);
        *p++ = v.mData;
        *p++ = D_01E31A20.field_0;
        for (int j = 0; j < 18; j++) {
            u_long128 *s = (u_long128 *)&f[j];
            u_long128 q1 = s[1], q2 = s[2], q3 = s[3], q4 = s[4], q5 = s[5], qa = s[0];
            p[0] = qa; p[1] = q1; p[2] = q2; p[3] = q3; p[4] = q4; p[5] = q5;
            p += 6;
        }
    }
    unsigned long z = 0;
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(((unsigned long)a->field_48 << 32) | 0x50000000), "r"(z));
    if (a->field_A4) {
        asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(((unsigned long)a->field_94 << 32) | 0x50000000), "r"(z));
    }
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0x10000000), "r"(0x10000000));
    farFogPlane.field_0 = p;
}
