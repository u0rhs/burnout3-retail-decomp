// NONMATCHING: DispatchBuffer__17CB3DebrisRendererFv -- retail 398 / ours 393 instructions, 267 in changed runs
// draftAH C-first: VIF packet sizing, one-time code/camera upload, DMA cnt + STCYCL/UNPACK header, per particle CreateRotationMatrix3x4(axis, deg->rad) rows + position/clip flag + colour ints in Revenge's lPack union, static data, BASE/OFFSET/ITOP/MSCNT trailer, buffer flip; 393/398, calls identical, VU op counts equal (trunc.w.s = retail's cvt.w.s word, N97); left: stack copies (sqc2 17/20, sq 21/22), frame 0x310 vs 0x480
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm with Revenge STABS locals (same function, 367 instrs); every packet word traced (rows/position go out as x,y,lane2,z exactly as retail); op counts per kind equal for VU

// CB3DebrisRenderer::DispatchBuffer() -- draftAH (C-first draft; the lifter refused it). 0x2F3C80, 0x638.
// [C] name: retail symbol table; static member (no this: the batch is the global D_01E866D0, as RenderDebrisArray's archive).
// Revenge counterpart DispatchBuffer__17CB4DebrisRenderer (STABS, DebrisRenderer/Ps2/B4DebrisRendererPS2.cpp, 367 instrs):
// local names lPack (union marFloats / manInts / mu128Pack), lpPosClip, lpAxisAngle, lpuColour, luPackedColour, lnNumQW,
// lnMatricesNumQW, lnCount, lbFlush, leResult, lRotateMatrix [L]. Written from the retail asm.
// What it does [L]: open a VIF packet sized for the batch (5 qwords per particle + 3, + 17 for the microcode/camera upload the
// first time, + 1-2 for the debris array's static data), upload code + camera once, then a DMA cnt + STCYCL/UNPACK V4-32 header
// and per particle: its rotation (axis-angle, degrees -> CreateRotationMatrix3x4) as three packed rows, its position with
// a clip flag (intersection result != 2) and its colour as four ints; then the array's static data, a BASE/OFFSET/ITOP/MSCNT
// trailer, empty the batch and flip the double-buffer base (0x118 - base).
// Packing [C asm]: rows and the position go out as (x, y, lane 2, z) -- z lands in lane 3 and lane 2 keeps its previous
// value (the position's flag, or the previous particle's colour b) for the rows; transcribed as is.
#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Trig.h"
using namespace GtMathPs2;

typedef unsigned int RwUInt32;
class CB3DebrisArray {
public:
    void UploadStaticDataAndGeometry(bool) const;
};
struct UnkStruct_D_01E866D0 {      // the particle batch (as RenderDebrisArray's archive)
    CGtV3dPlus field_0[16];         // position, intersection result in w (lpPosClip)
    CGtV3dPlus field_100[16];       // rotation axis, angle in degrees in w (lpAxisAngle)
    unsigned char pad_200[0x400];
    unsigned int field_600[16];     // packed colours (lpuColour)
    int field_640;                  // D_01E86D10: VU memory base of the current buffer
    int field_644;                  // D_01E86D14: particles in the batch
    CB3DebrisArray *field_648;      // D_01E86D18: the array whose static data still has to go
    unsigned char field_64C;        // D_01E86D1C: code and camera uploaded
    unsigned char pad_64D[3];
};
extern UnkStruct_D_01E866D0 D_01E866D0;
struct UnkStruct_farFogPlane { u_long128 *field_0; };   // [L] the DMA packet write pointer (as UploadCodeAndCameraData)
extern UnkStruct_farFogPlane farFogPlane;
extern float D_004E0F74;            // [G] degrees -> radians
extern "C" void _rwDMAOpenVIFPkt(unsigned int, int);
class CB3DebrisRenderer {
public:
    static void DispatchBuffer();
    static void UploadCodeAndCameraData();
};

// [L] N175 stand-in (RW's MAKE128 as one pcpyld): a quadword from two 64-bit halves
static inline u_long128 func_002F3C80_inl1(unsigned long lo, unsigned long hi)
{
    u_long128 q;
    asm("pcpyld %0, %2, %1" : "=r"(q) : "r"(lo), "r"(hi));
    return q;
}
union UnkStruct_002F3C80_pack {     // [L] Revenge's lPack (an unnamed union)
    float marFloats[4];
    int manInts[4];
    u_long128 mu128Pack;
};
// [G] one row or position: x, y into lanes 0/1, z into lane 3
static inline void func_002F3C80_inl2(UnkStruct_002F3C80_pack &lPack, const CGtV3d &v)
{
    lPack.marFloats[1] = v.Y();
    lPack.marFloats[3] = v.Z();
    lPack.marFloats[0] = v.X();
}

// 0x002F3C80
void CB3DebrisRenderer::DispatchBuffer()
{
    UnkStruct_002F3C80_pack lPack;
    bool lbFlush = false;
    int lnMatricesNumQW = D_01E866D0.field_644 * 5;
    int lnNumQW = lnMatricesNumQW + 3;
    if (!D_01E866D0.field_64C)
        lnNumQW += 0x11;
    if (D_01E866D0.field_648) {
        lnNumQW++;
        if (D_01E866D0.field_64C) {
            lbFlush = true;
            lnNumQW++;
        }
    }
    _rwDMAOpenVIFPkt(0, lnNumQW);
    if (!D_01E866D0.field_64C) {
        UploadCodeAndCameraData();
        D_01E866D0.field_64C = 1;
    }
    u_long128 *p = farFogPlane.field_0;
    *p++ = func_002F3C80_inl1((long)(int)(0x10000000 | lnMatricesNumQW),
                              ((unsigned long)(unsigned int)(D_01E866D0.field_640 | (lnMatricesNumQW << 16) | 0x6C000000) << 32) | 0x01000101);
    CGtV3dPlus *lpPosClip = D_01E866D0.field_0;
    CGtV3dPlus *lpAxisAngle = D_01E866D0.field_100;
    RwUInt32 *lpuColour = D_01E866D0.field_600;
    int lnCount = D_01E866D0.field_644;
    do {
        CGtV4d lAxisAngle(lpAxisAngle->mData);
        CGtMatrix3x4 lRotateMatrix = CreateRotationMatrix3x4(CGtV3d(lpAxisAngle->mData), D_004E0F74 * (float)lAxisAngle.W());
        func_002F3C80_inl2(lPack, lRotateMatrix.mRight);
        *p++ = lPack.mu128Pack;
        func_002F3C80_inl2(lPack, lRotateMatrix.mUp);
        *p++ = lPack.mu128Pack;
        func_002F3C80_inl2(lPack, lRotateMatrix.mAt);
        *p++ = lPack.mu128Pack;
        CGtV4d lPos(lpPosClip->mData);
        func_002F3C80_inl2(lPack, CGtV3d(lpPosClip->mData));
        int leResult = (int)(float)lPos.W();
        if (leResult == 2)
            lPack.manInts[2] = 0;
        else
            lPack.manInts[2] = 1;
        *p++ = lPack.mu128Pack;
        RwUInt32 luPackedColour = *lpuColour;
        lPack.manInts[0] = luPackedColour & 0xFF;
        lPack.manInts[1] = (luPackedColour & 0xFF00) >> 8;
        lPack.manInts[2] = (luPackedColour & 0xFF0000) >> 16;
        lPack.manInts[3] = (luPackedColour & 0xFF000000) >> 24;
        *p++ = lPack.mu128Pack;
        lpPosClip++;
        lpAxisAngle++;
        lpuColour++;
    } while (--lnCount != 0);
    farFogPlane.field_0 = p;
    if (D_01E866D0.field_648) {
        D_01E866D0.field_648->UploadStaticDataAndGeometry(lbFlush);
        D_01E866D0.field_648 = 0;
    }
    p = farFogPlane.field_0;
    p[0] = func_002F3C80_inl1(0x10000001, 0);
    p[1] = func_002F3C80_inl1(((unsigned long)(unsigned int)(D_01E866D0.field_640 | 0x03000000)) | (0x02000000UL << 32),
                              ((unsigned long)(unsigned int)(D_01E866D0.field_644 | 0x04000000)) | (0x17000000UL << 32));
    farFogPlane.field_0 = p + 2;
    D_01E866D0.field_644 = 0;
    D_01E866D0.field_640 = 0x118 - D_01E866D0.field_640;
}
