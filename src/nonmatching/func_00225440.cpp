// NONMATCHING: func_00225440 -- retail 443 / ours 401 instructions, 498 in changed runs
// draftAO (2026-11-01): complete: [L] CB3CameraData::ConstructEnvMap(CGtMatrix3x4, EB3RenderableCamera, bool lbCubeMap, int w, int h, unsigned offset) (DNAT map + Revenge register list; layout Revenge CB4CameraData); decoded the view matrix (x / y columns = right / up x -0.5 recip window + at x skew (0.5 -+ scale x view offset), at as z, translations 0.5 - (skew + pos.column) and -(pos.at), built lane by lane in lViewMatrix, rows widened (x,y,z,z) into VU1Data[0..3]) and the guard-band rows +0x180..+0x1B0 (half size + 5 / 2047.94 - half size, reciprocals, z -0.020002 / 0.010001 x 100.01, w far 100 / near 0.01); GS FRAME/ZBUF/XYOFFSET/SCISSOR, z scale/shift, InitialisePerspective call and the returned offset as before; 401/443, calls identical, every VU op count equal (lane types), frame 0x160 vs 0x550 (byte-loop matrix copies) | Before: son7 PARTIAL first archive: packet stores (+0x1C0..0x1F0), envmap window (+0x200..), +0x160/0x170 constants, call to func_00334950 and return value are decoded; NOT done: the VU0 matrix products filling +0xE0..0x11C and the +0x180..0x1B0 vectors (retail 443 instrs vs ours 165)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm 0x225440..0x225B28: every lane op of the view matrix and the four VU1 rows, the cube-map branch (beqz = envmap window), the GS bit packing and the call arguments traced; mViewMatrix's w lanes are unset stack words in retail (the VU1 rows replace w by z)

// func_00225440 -- [L] CB3CameraData::ConstructEnvMap(CGtMatrix3x4 lMatrix, EB3RenderableCamera leCamera, bool lbCubeMap,
// int lnWidth, int lnHeight, unsigned int luMemoryOffset): the DNAT E map lists CB3CameraData::ConstructEnvMap(CGtMatrix3x4,
// EB3RenderableCamera, ..) in B3GraphicsManagerPS2.cpp beside Construct(RwCamera *) (= retail 0x225B30, the next function), and
// Revenge's ConstructEnvMap__13CB4CameraDataGQ29GtMathPs212CGtMatrix3x419EB4RenderableCamerabiiUi has this register list (a1 the
// matrix, a2 the camera (unread here), a3 the cube-map flag, t0 / t1 the size, t2 the VRAM offset; returns the next offset)
// [C retail 0x225440..0x225B28; caller BuildCustomCameraData]. Layout: Revenge CB4CameraData (types.h:5026, 0x230) [L], B3's slot
// stride 0x230 [C]. Label kept (no B3 symbol). Field names placeholders with Revenge's names in comments.
// draftAO fork B (2026-11-01): complete; the son7 archive left the view matrix (+0xE0..+0x11C) and the guard-band rows
// (+0x180..+0x1B0) undecoded.
#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Quat.h"
using namespace GtMathPs2;

class CB3CameraData {
public:
    unsigned char pad_0[0xA0];                 // [L] mFrustum (CGtCameraFrustum)
    CGtMatrix3x4 field_A0;                     // [L] mMatrix
    CGtMatrix3x4 field_E0;                     // [L] mViewMatrix
    u_long128 field_120[4];                    // [L] mau128VU1Data[0..3]: the view rows widened (x, y, z, z)
    CGtV4d field_160;                          // [L] mau128VU1Data[4]: XYZ scale
    CGtV4d field_170;                          // [L] mau128VU1Data[5]: XYZ shift
    CGtV4d field_180;                          // [L] mau128VU1Data[6..9]: guard-band / clip rows
    CGtV4d field_190;
    CGtV4d field_1A0;
    CGtV4d field_1B0;
    u_long128 field_1C0;                       // [L] mau128RegisterData[0..3]: GS FRAME_1, ZBUF_1, XYOFFSET_1, SCISSOR_1
    u_long128 field_1D0;
    u_long128 field_1E0;
    u_long128 field_1F0;
    CGtV2d field_200;                          // [L] mViewWindow
    CGtV2d field_208;                          // [L] mRecipViewWindow
    CGtV2d field_210;                          // [L] mViewOffset
    CGtV2d field_218;                          // [L] mFrameBufferSize
    CGtV2d field_220;                          // [L] mFrameBufferOffset
};
extern float krEnvmapViewWindow;               // [C] symbol_addrs (0x4B9DA0)
extern unsigned char skyUploadedCode;          // [C] RW sky2 driver global
extern unsigned int D_006662D8;                // [G] the env-map z buffer's VRAM base (bytes)
extern unsigned int D_006662DC;                // [G] the env-map frame buffer's VRAM base (bytes)
extern float D_004E0A64, D_004E0A68, D_004E0A6C, D_004E0A70, D_004E0A74, D_004E0A78, D_004E0A7C, D_004E091C;
    // [C] 2047.9374, -1677.7214, -99.99 (near - far), 100.01 (far + near), -0.020002, 0.010001, -2.55, 0.01 (near)
// [L] CGtCameraFrustum::InitialisePerspective(matrix, frame buffer size, view window, view offset, near, far) (archive)
extern "C" void func_00334950(CB3CameraData *self, const CGtMatrix3x4 &m, const CGtV2d &size, const CGtV2d &window,
                              const CGtV2d &offset, float n, float f);

// [L] N185 lane setters on compiler-chosen registers (as Construct__13CB3CameraData's func_00225B30_inl1..4)
static inline void func_00225440_inl1(CGtV4d &v, float f) { u_long128 s; asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f)); asm("vaddx.x %0, $vf0, %1x" : "+j"(v.mData) : "j"(s)); }
static inline void func_00225440_inl2(CGtV4d &v, float f) { u_long128 s; asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f)); asm("vaddx.y %0, $vf0, %1x" : "+j"(v.mData) : "j"(s)); }
static inline void func_00225440_inl3(CGtV4d &v, float f) { u_long128 s; asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f)); asm("vaddx.z %0, $vf0, %1x" : "+j"(v.mData) : "j"(s)); }
static inline void func_00225440_inl4(CGtV4d &v, float f) { u_long128 s; asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f)); asm("vmulx.w %0, $vf0, %1x" : "+j"(v.mData) : "j"(s)); }
// [G] a CGtV3d row widened to a quad (x | y << 32, z | z << 32), as Construct's func_00225B30_inl5 (retail lwu x3, pcpyld)
static inline u_long128 func_00225440_inl5(CGtV3d r)
{
    const unsigned int *p = (const unsigned int *)&r;
    unsigned long lo = (unsigned long)p[0] | ((unsigned long)p[1] << 32);
    unsigned long hi = (unsigned long)p[2] | ((unsigned long)p[2] << 32);
    u_long128 q;
    asm("pcpyld %0, %2, %1" : "=r"(q) : "r"(lo), "r"(hi));
    return q;
}
static inline u_long128 func_00225440_inl6(unsigned long lo, unsigned long hi)
{
    u_long128 q;
    asm("pcpyld %0, %2, %1" : "=r"(q) : "r"(lo), "r"(hi));
    return q;
}

// 0x00225440
extern "C" unsigned int func_00225440(CB3CameraData *self, CGtMatrix3x4 lMatrix, int leCamera, bool lbCubeMap, int lnWidth,
                                      int lnHeight, unsigned int luMemoryOffset)
{
    self->field_A0 = lMatrix;
    // [C] 0x225474..0x2254E4: Revenge lrZScale / lrZShift (z buffer 0..0xFFFFFF over near 0.01 .. far 100)
    float lrZMax = (float)0xFFFFFF + D_004E0A68;
    float lrZMin = 0.0f - D_004E0A68;
    float lrZScale = (lrZMin - lrZMax) / D_004E0A6C;
    float lrZShift = 0.5f * ((lrZMin + lrZMax) - lrZScale * D_004E0A70);
    if (lbCubeMap) {
        self->field_200.Set(1.0f, 1.0f);
        self->field_208.Set(1.0f, 1.0f);
        self->field_210.Set(0.0f, 0.0f);
    } else {
        float lrWindow = krEnvmapViewWindow;
        float lrRecip = 1.0f / lrWindow;
        self->field_200.Set(lrWindow, lrWindow);
        self->field_208.Set(lrRecip, lrRecip);
        float lrShift = lrWindow - 1.0f;
        self->field_210.Set(-lrShift, lrShift);
    }
    // [C] 0x225540..0x225720: the view matrix: x / y columns from the right / up rows scaled by -0.5 / view window and skewed along
    // the at row by the view offset, the at row as z; translation = 0.5 - (skew + pos . column) per column, -(pos . at) in z.
    // Retail builds it in a stack CGtMatrix3x4 (Revenge lViewMatrix) lane by lane; the w lanes are never written (unset stack
    // words, copied into mViewMatrix's w lanes; the VU1 rows below replace w by z).
    CGtV3d lHalf(-0.5f, 0.5f, 0.0f);          // [C] sp+0x220: w never written
    CGtV3d lOffset;                            // [C] x / y lanes set (lw + lane setter); z / w unset stack bytes
    lOffset.SetX(self->field_210.marValues[0]);
    lOffset.SetY(self->field_210.marValues[1]);
    CGtV3d lRecip;
    lRecip.SetX(self->field_208.marValues[0]);
    lRecip.SetY(self->field_208.marValues[1]);
    CGtMatrix3x4 lViewMatrix;                  // [L] Revenge local; w lanes never written
    CGtV3d lScale;                             // [C] x = scale, y = skew (the at-row weight); z / w unset
    lScale.SetX(lRecip.X() * lHalf.X());
    lScale.SetY(lHalf.Y() - lScale.X() * lOffset.X());
    CGtV3d lColumnX = self->field_A0.mRight * lScale.X() + self->field_A0.mAt * lScale.Y();
    lViewMatrix.mRight.SetX(lColumnX.X());
    lViewMatrix.mUp.SetX(lColumnX.Y());
    lViewMatrix.mAt.SetX(lColumnX.Z());
    lViewMatrix.mPos.SetX(lHalf.Y() - (lScale.Y() + DotProduct(self->field_A0.mPos, lColumnX)));
    lScale.SetX(lRecip.Y() * lHalf.X());
    lScale.SetY(lHalf.Y() + lScale.X() * lOffset.Y());
    CGtV3d lColumnY = self->field_A0.mUp * lScale.X() + self->field_A0.mAt * lScale.Y();
    lViewMatrix.mRight.SetY(lColumnY.X());
    lViewMatrix.mUp.SetY(lColumnY.Y());
    lViewMatrix.mAt.SetY(lColumnY.Z());
    lViewMatrix.mPos.SetY(lHalf.Y() - (lScale.Y() + DotProduct(self->field_A0.mPos, lColumnY)));
    lViewMatrix.mRight.SetZ(self->field_A0.mAt.X());
    lViewMatrix.mUp.SetZ(self->field_A0.mAt.Y());
    lViewMatrix.mAt.SetZ(self->field_A0.mAt.Z());
    lViewMatrix.mPos.SetZ(-DotProduct(self->field_A0.mPos, self->field_A0.mAt));
    self->field_E0 = lViewMatrix;
    self->field_120[0] = func_00225440_inl5(self->field_E0.mRight);
    self->field_120[1] = func_00225440_inl5(self->field_E0.mUp);
    self->field_120[2] = func_00225440_inl5(self->field_E0.mAt);
    self->field_120[3] = func_00225440_inl5(self->field_E0.mPos);
    skyUploadedCode &= ~8;                     // [C] 0x225908: perspective (as Construct's type-1 path)
    // [C] 0x2257AC..0x2259C0: the guard-band rows (as Construct's v0..v3): x = 2047.9374 - half size or half size + 5,
    // y its reciprocal, z / w the clip constants
    int lnHalfWidth = lnWidth >> 1;
    int lnHalfHeight = lnHeight >> 1;
    float lrGuardX = D_004E0A64 - (float)lnHalfWidth;
    float lrGuardY = D_004E0A64 - (float)lnHalfHeight;
    float lrClipX = (float)(lnHalfWidth + 5);
    float lrClipY = (float)(lnHalfHeight + 5);
    float lrFar = 100.0f;
    float lrNear = D_004E091C;
    CGtV4d v0, v1, v2, v3;                     // [C] all four lanes set (the loads are of unset stack slots)
    func_00225440_inl1(v0, lrGuardX);
    func_00225440_inl2(v0, 1.0f / lrGuardX);
    func_00225440_inl4(v0, lrFar);
    func_00225440_inl1(v1, lrGuardY);
    func_00225440_inl2(v1, 1.0f / lrGuardY);
    func_00225440_inl4(v1, lrNear);
    func_00225440_inl1(v2, lrClipX);
    func_00225440_inl2(v2, 1.0f / lrClipX);
    func_00225440_inl4(v2, lrFar);
    func_00225440_inl1(v3, lrClipY);
    func_00225440_inl2(v3, 1.0f / lrClipY);
    func_00225440_inl4(v3, lrNear);
    float lrZ0 = D_004E0A74;
    float lrZ1 = D_004E0A78 * D_004E0A70;
    func_00225440_inl3(v0, lrZ0);
    func_00225440_inl3(v2, lrZ0);
    func_00225440_inl3(v1, lrZ1);
    func_00225440_inl3(v3, lrZ1);
    self->field_1A0 = v0;
    self->field_1B0 = v1;
    self->field_180 = v2;
    self->field_190 = v3;
    // [C] 0x2259C4..0x225AA4: GS registers for the env-map buffers (page-aligned addresses / 32 words; width / 64)
    unsigned int luZBuffer = luMemoryOffset + D_006662D8;
    unsigned int luFrame = luMemoryOffset + D_006662DC;
    unsigned int luNext = luMemoryOffset + lnWidth * lnHeight / 64;
    self->field_1C0 = func_00225440_inl6((unsigned int)((luFrame >> 5) | ((lnWidth / 64) << 16)), 0x4C);
    self->field_1D0 = func_00225440_inl6((unsigned int)((luZBuffer >> 5) | 0x1000000), 0x4E);
    self->field_1E0 = func_00225440_inl6(((unsigned long)(0x800 - (long)lnHalfWidth) << 4) | ((unsigned long)(0x800 - (long)lnHalfHeight) << 36), 0x18);
    self->field_1F0 = func_00225440_inl6(((long)(lnWidth - 1) << 16) | ((long)(lnHeight - 1) << 48), 0x40);
    self->field_160 = CGtV4d((float)lnWidth, (float)lnHeight, lrZScale, D_004E0A7C);
    self->field_170 = CGtV4d(2048.0f, 2048.0f, lrZShift, 100.0f);
    self->field_218.Set((float)lnWidth, (float)lnHeight);
    self->field_220.Set(0.0f, 0.0f);
    func_00334950(self, self->field_A0, self->field_218, self->field_200, self->field_210, D_004E091C, 100.0f);
    return luNext;
}
