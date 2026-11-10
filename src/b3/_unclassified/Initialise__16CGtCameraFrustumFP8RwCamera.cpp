// Hand-written; the lifter refused it (ghvu4: Ghidra draft; [L] N185 compiler-chosen CGtV4d SetX/Y/Z/W(float) stand-ins, 16 unrolled lane writes).

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

struct RwCamera;
// [L] 0x14-byte records = RwFrustumPlane (RW 3.5 SDK: RwPlane normal+distance, then closestX/Y/Z + pad); the rows below are the planes transposed [G]
struct UnkStruct_00334EA0_pl { float field_0[5]; };
struct UnkStruct_00334EA0_ext { unsigned char pad_0[0x88]; UnkStruct_00334EA0_pl field_88[4]; };
class CGtCameraFrustumBase {
public:
    void Initialise(RwCamera *);
    unsigned char pad_0[0x60];
};
class CGtCameraFrustum : public CGtCameraFrustumBase {
public:
    void Initialise(RwCamera *);
    CGtV4d field_60[4];
};
extern int skyCameraExt;
// [L] N185: CGtV4d lane setters with compiler-chosen registers (the CGtV3d::SetX(float) shape; SetW as SetA's vmulx.w)
static inline void func_00334EA0_inl0(CGtV4d &v, float f) { u_long128 s; asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f)); asm("vaddx.x %0, $vf0, %1x" : "+j"(v.mData) : "j"(s)); }
static inline void func_00334EA0_inl1(CGtV4d &v, float f) { u_long128 s; asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f)); asm("vaddx.y %0, $vf0, %1x" : "+j"(v.mData) : "j"(s)); }
static inline void func_00334EA0_inl2(CGtV4d &v, float f) { u_long128 s; asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f)); asm("vaddx.z %0, $vf0, %1x" : "+j"(v.mData) : "j"(s)); }
static inline void func_00334EA0_inl3(CGtV4d &v, float f) { u_long128 s; asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f)); asm("vmulx.w %0, $vf0, %1x" : "+j"(v.mData) : "j"(s)); }

// 0x00334EA0
void CGtCameraFrustum::Initialise(RwCamera * cam)
{
    CGtCameraFrustumBase::Initialise(cam);
    UnkStruct_00334EA0_ext * e = (UnkStruct_00334EA0_ext *)((char *)cam + skyCameraExt);
    func_00334EA0_inl0(field_60[0], e->field_88[0].field_0[0]);
    func_00334EA0_inl1(field_60[0], e->field_88[1].field_0[0]);
    func_00334EA0_inl2(field_60[0], e->field_88[2].field_0[0]);
    func_00334EA0_inl3(field_60[0], e->field_88[3].field_0[0]);
    func_00334EA0_inl0(field_60[1], e->field_88[0].field_0[1]);
    func_00334EA0_inl1(field_60[1], e->field_88[1].field_0[1]);
    func_00334EA0_inl2(field_60[1], e->field_88[2].field_0[1]);
    func_00334EA0_inl3(field_60[1], e->field_88[3].field_0[1]);
    func_00334EA0_inl0(field_60[2], e->field_88[0].field_0[2]);
    func_00334EA0_inl1(field_60[2], e->field_88[1].field_0[2]);
    func_00334EA0_inl2(field_60[2], e->field_88[2].field_0[2]);
    func_00334EA0_inl3(field_60[2], e->field_88[3].field_0[2]);
    func_00334EA0_inl0(field_60[3], e->field_88[0].field_0[3]);
    func_00334EA0_inl1(field_60[3], e->field_88[1].field_0[3]);
    func_00334EA0_inl2(field_60[3], e->field_88[2].field_0[3]);
    func_00334EA0_inl3(field_60[3], e->field_88[3].field_0[3]);
}
