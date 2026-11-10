// NONMATCHING: func_001A8800 -- retail 639 / ours 637 instructions, 91 in changed runs
// retail 639 / ours 637; own code exact, the 91-instr residue (16 hunks, 20 instrs) is all inside the inlined CGtMatrix3x4::OrthoNormalise: Y()/Z() lane compares stored by sqc2 from a VU reg in retail (sq from GPR here), 2 addiu row pointers, frame 0x5F0 vs 0x3C0; local lane-read probes (sqc2 "j") worse (267)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the asm: every call, branch, store and VU op accounted for; calls identical

// func_001A8800 -- drafted by draftD (2026-10-31) from retail asm + Ghidra. Unnamed at this address in every table, so
// the asm label with C linkage. [L] it is the E-build (dnat map) CB3NetworkRaceUpdateMessage::RetrieveCrashingTraffic(unsigned char*,
// CGtMatrix3x4*, CGtV3d*, CGtV ...) (0x9F8 there vs 0x9FC here; followed by Retrieve ~ func_001A9200, which decodes the same
// fields for the message's own car) -- names in comments only. Twin of func_001A9200 (draftD). Every struct below is a placeholder; types [G] from instruction widths.
#include "b3/GtMathPs2.h"
using GtMathPs2::CGtV3d;
using GtMathPs2::CGtMatrix3x4;

struct UnkStruct_001A8800_rec {       // 22-byte record (idx * 22) from msg + 0x30
    unsigned char field_0;            // three byte angles -> func_001AA680
    unsigned char field_1;
    unsigned char field_2;
    unsigned char field_3;            // -> *p1
    unsigned short field_4;           // position lanes (D_004B7A40 frac bits, unsigned)
    unsigned short field_6;
    unsigned short field_8;
    unsigned short field_A;           // velocity lanes (kan8VelocityNumFracBits, signed)
    unsigned short field_C;
    unsigned short field_E;
    unsigned short field_10;          // second vector lanes (0x4B7A50 frac bits, signed)
    unsigned short field_12;
    unsigned short field_14;
};
struct UnkStruct_001A8800_msg {
    unsigned char pad_0[0x30];
    UnkStruct_001A8800_rec field_30[1];   // count unknown
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

// 0x001A8800
extern "C" void func_001A8800(UnkStruct_001A8800_msg *msg, unsigned char *p1, CGtMatrix3x4 *m, CGtV3d *vel, CGtV3d *ang,
                              void *idx_)
{
    int idx = (int)idx_;
    func_001AA680(m, msg->field_30[idx].field_0, msg->field_30[idx].field_1, msg->field_30[idx].field_2);
    CGtV3d lo = D_00665E80;
    lo -= D_004B7A60;
    CGtV3d hi = D_00665E90;
    hi += D_004B7A60;
    CGtV3d f;
    f.SetX(func_00389600(msg->field_30[idx].field_4, D_004B7A40[0], false));
    f.SetY(func_00389600(msg->field_30[idx].field_6, D_004B7A40[1], false));
    f.SetZ(func_00389600(msg->field_30[idx].field_8, D_004B7A40[2], false));
    hi -= lo;
    CGtV3d p = f * hi;
    p += lo;
    m->mPos = p;
    m->OrthoNormalise();
    vel->SetX(func_00389600(msg->field_30[idx].field_A, kan8VelocityNumFracBits[0], true));
    vel->SetY(func_00389600(msg->field_30[idx].field_C, kan8VelocityNumFracBits[1], true));
    vel->SetZ(func_00389600(msg->field_30[idx].field_E, kan8VelocityNumFracBits[2], true));
    ang->SetX(func_00389600(msg->field_30[idx].field_10, kan8PositionNumFracBits[0], true));
    ang->SetY(func_00389600(msg->field_30[idx].field_12, kan8PositionNumFracBits[1], true));
    ang->SetZ(func_00389600(msg->field_30[idx].field_14, kan8PositionNumFracBits[2], true));
    *p1 = msg->field_30[idx].field_3;
}
