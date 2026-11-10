// NONMATCHING: func_001A9200 -- retail 728 / ours 726 instructions, 270 in changed runs
// retail 728 / ours 726; own code exact apart from one lhu/vsub swap at 0x1A9298; residue = inlined CGtMatrix3x4::OrthoNormalise (rebuild blocks at the function END in retail, sqc2 vs sq stack temps, frame 0x5F0 vs 0x3C0)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the asm: every call, branch, store and VU op accounted for; calls and the post-OrthoNormalise code identical to retail

// func_001A9200 -- drafted by draftD (2026-10-31) from retail asm + Ghidra. Unnamed at this address in every table, so
// the asm label with C linkage. [L] it is the E-build (dnat map) CB3NetworkRaceUpdateMessage::Retrieve(CGtMatrix3x4*,
// CGtV3d*, CGtV3d*, CNetworkControls*, CUpdateM..*, ...) (0xAC8 there vs 0xB60 here; next to RetrieveCrashingTraffic 0x9F8 ~
// func_001A8800 0x9FC, and SetMatrixFromEulerAngles 0x448 ~ func_001AA680 0x448; the three kan8*NumFracBits tables) -- names
// in comments only. Every struct below is a placeholder; types [G] from instruction widths.
#include "b3/GtMathPs2.h"
using GtMathPs2::CGtV3d;
using GtMathPs2::CGtMatrix3x4;

struct UnkStruct_001A9200_msg {
    unsigned char field_0;            // bit 0: valid
    unsigned char pad_1[0xF];
    unsigned char field_10;           // three byte angles -> func_001AA680
    unsigned char field_11;
    unsigned char field_12;
    unsigned char field_13;
    unsigned short field_14;          // position lanes, fixed point (D_004B7A40 frac bits, unsigned)
    unsigned short field_16;
    unsigned short field_18;
    unsigned short field_1A;          // velocity lanes (kan8VelocityNumFracBits, signed)
    unsigned short field_1C;
    unsigned short field_1E;
    unsigned short field_20;          // second vector lanes (0x4B7A50 frac bits, signed)
    unsigned short field_22;
    unsigned short field_24;
    unsigned short field_26;
    unsigned char field_28;
    signed char field_29;
    unsigned char field_2A;
    unsigned char pad_2B;
    unsigned char field_2C;           // flag bits
    unsigned char field_2D;           // bit 7, bit 6, bits 3-5, bits 0-2
    unsigned char field_2E;
    unsigned char field_2F;
};
struct UnkStruct_001A9200_ctl {
    unsigned char field_0;
    signed char field_1;
    unsigned char field_2;
};
struct UnkStruct_001A9200_upd {
    unsigned char pad_0[0x4];
    int field_4;
    int field_8;
    unsigned char field_C;
    unsigned char pad_D[0x3];
    int field_10;
    unsigned char field_14;
    unsigned char field_15;
    unsigned char field_16;
    unsigned char field_17;
    unsigned char field_18;
    unsigned char field_19;
    unsigned char field_1A;
    unsigned char pad_1B[0x9];
    unsigned char field_24;
    unsigned char pad_25[0x3];
    int field_28;
    int field_2C;
};

// [L] retail 0x4B7A40/48/50 = the E-build's kan8PositionNumFracBits / kan8VelocityNumFracBits / kan8AngVelocityNumFracBits
// (same order and 8-byte spacing, kPosSafetyOffset 0x20 after) -- the repo's config names 0x4B7A50 kan8PositionNumFracBits.
extern const signed char D_004B7A40[];
extern const signed char kan8VelocityNumFracBits[];
extern const signed char kan8PositionNumFracBits[];
extern CGtV3d D_004B7A60;             // [L] = E-build kPosSafetyOffset
extern CGtV3d D_00665E80;             // position range: min
extern CGtV3d D_00665E90;             //                 max
extern "C" float func_00389600(unsigned short n, signed char bits, bool isSigned);
extern "C" void func_001AA680(CGtMatrix3x4 *m, unsigned int a, unsigned int b, unsigned int c);

// 0x001A9200
extern "C" bool func_001A9200(UnkStruct_001A9200_msg *msg, CGtMatrix3x4 *m, CGtV3d *vel, CGtV3d *ang,
                              UnkStruct_001A9200_ctl *ctl, UnkStruct_001A9200_upd *upd, unsigned short *p6)
{
    if ((msg->field_0 & 1) != 1) return false;
    func_001AA680(m, msg->field_10, msg->field_11, msg->field_12);
    CGtV3d hi = D_00665E90;
    hi += D_004B7A60;
    CGtV3d lo = D_00665E80;
    lo -= D_004B7A60;
    CGtV3d f;
    f.SetX(func_00389600(msg->field_14, D_004B7A40[0], false));
    f.SetY(func_00389600(msg->field_16, D_004B7A40[1], false));
    f.SetZ(func_00389600(msg->field_18, D_004B7A40[2], false));
    hi -= lo;
    CGtV3d p = f * hi;
    p += lo;
    m->mPos = p;
    m->OrthoNormalise();
    vel->SetX(func_00389600(msg->field_1A, kan8VelocityNumFracBits[0], true));
    vel->SetY(func_00389600(msg->field_1C, kan8VelocityNumFracBits[1], true));
    vel->SetZ(func_00389600(msg->field_1E, kan8VelocityNumFracBits[2], true));
    ang->SetX(func_00389600(msg->field_20, kan8PositionNumFracBits[0], true));
    ang->SetY(func_00389600(msg->field_22, kan8PositionNumFracBits[1], true));
    ang->SetZ(func_00389600(msg->field_24, kan8PositionNumFracBits[2], true));
    ctl->field_0 = msg->field_28;
    ctl->field_1 = msg->field_29;
    ctl->field_2 = msg->field_2A;
    upd->field_4 = msg->field_13;
    upd->field_8 = msg->field_2E;
    upd->field_C = msg->field_2F;
    upd->field_14 = 0;
    upd->field_15 = 0;
    upd->field_16 = 0;
    upd->field_17 = 0;
    upd->field_18 = 0;
    upd->field_19 = 0;
    upd->field_1A = 0;
    if (msg->field_2C & 4) upd->field_14 = 1;
    if (msg->field_2C & 8) upd->field_15 = 1;
    if (msg->field_2C & 0x10) upd->field_16 = 1;
    if (msg->field_2C & 1) upd->field_10 = 2;
    else if (msg->field_2C & 2) upd->field_10 = 1;
    else upd->field_10 = 0;
    if (msg->field_2C & 0x20) upd->field_17 = 1;
    if (msg->field_2C & 0x40) upd->field_18 = 1;
    if (msg->field_2C & 0x80) upd->field_1A = 1;
    if (msg->field_2D & 0x80) {
        upd->field_19 = 1;
        msg->field_2D &= 0x7F;
    }
    upd->field_24 = 0;
    if ((msg->field_2D & 0x40) == 0x40) upd->field_24 = 1;
    upd->field_2C = (unsigned char)(msg->field_2D >> 3) & 7;
    upd->field_28 = msg->field_2D & 7;
    *p6 = msg->field_26;
    return true;
}
