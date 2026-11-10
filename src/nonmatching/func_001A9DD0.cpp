// NONMATCHING: func_001A9DD0 -- retail 244 / ours 247 instructions, 82 in changed runs
// draftAN fork C C-first: [L] E-build CB3NetworkRaceUpdateMessage::Prepare: the message func_001A9200 ([L] Retrieve) reads back; same packing body as func_001AA3F0 plus controls, record ints, flag bits (field_10 1 -> 2, 2 -> 1), func_001A8620, 7th argument at 0x26; 247/244, calls identical, non-stack stores identical
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm; field-for-field inverse of func_001A9200's archive; every flag-bit test (bnez/beq) and store traced

// func_001A9DD0 -- draftAN fork C (C-first draft). 0x1A9DD0, 0x3D0. Unnamed in every table: the asm label, C linkage.
// [L] the E-build (dnat map) CB3NetworkRaceUpdateMessage::Prepare(const CGtMatrix3x4*, const CGtV3d*, const CGtV3d*, const
// CNetworkControls*, ...) (0x5A4 there): the writer of the message func_001A9200 ([L] Retrieve) reads back, field by field
// (angles 0x10-0x12, position 0x14-0x18 unsigned, velocity 0x1A-0x1E, second vector 0x20-0x24, controls 0x28-0x2A, the
// update record's ints at 0x13/0x2E/0x2F, flag bits 0x2C/0x2D, the 7th argument at 0x26), clearing the crashing-traffic
// count 0x2B. Called by func_0023B8C0 with (field_6E4, matrix, &vel, &ang, matrix + 0x2464, &record, int). Names in
// comments only; types [G] from widths. The packing body is func_001AA3F0's (same globals, same order).
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

struct UnkStruct_001A9DD0_msg {         // = func_001A9200's message layout
    unsigned char pad_0[0x10];
    unsigned char field_10;             // three byte angles (func_001AAAD0)
    unsigned char field_11;
    unsigned char field_12;
    unsigned char field_13;
    unsigned short field_14;            // position lanes, unsigned fixed point (D_004B7A40 frac bits)
    unsigned short field_16;
    unsigned short field_18;
    unsigned short field_1A;            // velocity lanes, signed (kan8VelocityNumFracBits)
    unsigned short field_1C;
    unsigned short field_1E;
    unsigned short field_20;            // second vector lanes, signed (kan8PositionNumFracBits)
    unsigned short field_22;
    unsigned short field_24;
    unsigned short field_26;
    unsigned char field_28;
    signed char field_29;
    unsigned char field_2A;
    unsigned char field_2B;             // crashing-traffic entry count (func_001A9D70)
    unsigned char field_2C;             // flag bits
    unsigned char field_2D;             // bit 7 (+ func_001A8620's bits)
    unsigned char field_2E;
    unsigned char field_2F;
};
struct UnkStruct_001A9DD0_ctl {
    unsigned char field_0;
    signed char field_1;
    unsigned char field_2;
};
struct UnkStruct_001A9DD0_upd {         // = func_001A9200's update record
    int field_0;
    int field_4;
    int field_8;
    unsigned char field_C;
    unsigned char pad_D[0x3];
    int field_10;                       // 1 -> flag 2, 2 -> flag 1
    unsigned char field_14;
    unsigned char field_15;
    unsigned char field_16;
    unsigned char field_17;
    unsigned char field_18;
    unsigned char field_19;
    unsigned char field_1A;
    unsigned char pad_1B;
    unsigned char *field_1C;            // -> func_001A8620
    unsigned char *field_20;
};

extern const signed char D_004B7A40[];   // [L] E-build kan8PositionNumFracBits (see func_001A9200)
extern const signed char kan8VelocityNumFracBits[];
extern const signed char kan8PositionNumFracBits[];
extern CGtV3d D_004B7A60;               // [L] E-build kPosSafetyOffset
extern CGtV3d D_004B7A70;               // inset kept inside the widened box
extern CGtV3d D_00665E80;               // position range: min
extern CGtV3d D_00665E90;               //                 max
extern CGtV3d gMinLinearVelocity;       // velocity range: min (func_001AA1A0)
extern CGtV3d D_0066C550;               //                 max
extern CGtV3d D_0066C560;               // second vector range: min
extern CGtV3d D_0066C570;               //                      max
extern "C" void func_001AAAD0(const CGtMatrix3x4 *m, unsigned char *a, unsigned char *b, unsigned char *c);
extern "C" void func_001A8620(UnkStruct_001A9DD0_msg *self, unsigned char *p1, unsigned char *p2, int p3);
extern "C" unsigned short func_00389700(signed char bits, bool isSigned, float f);

// [L] stand-in: lane-wise a / b as retail does it on VU0 (Q = 1 / b.lane; r.lane = a.lane * Q), no GtMathPs2 API.
// [C] retail's w lane is whatever the destination register held (a callee-saved GPR's caller value): never read.
static inline CGtV3d func_001A9DD0_inl1(const CGtV3d &a, const CGtV3d &b)
{
    u_long128 r;
    asm("vdiv $Q, $vf0w, %2x" "\n\t" "vwaitq" "\n\t" "vmulq.x %0, %1, $Q" : "+j"(r) : "j"(a.mData), "j"(b.mData));
    asm("vdiv $Q, $vf0w, %2y" "\n\t" "vwaitq" "\n\t" "vmulq.y %0, %1, $Q" : "+j"(r) : "j"(a.mData), "j"(b.mData));
    asm("vdiv $Q, $vf0w, %2z" "\n\t" "vwaitq" "\n\t" "vmulq.z %0, %1, $Q" : "+j"(r) : "j"(a.mData), "j"(b.mData));
    return CGtV3d(r);
}

// 0x001A9DD0
extern "C" void func_001A9DD0(UnkStruct_001A9DD0_msg *msg, const CGtMatrix3x4 *m, const CGtV3d *vel, const CGtV3d *ang,
                              const UnkStruct_001A9DD0_ctl *ctl, const UnkStruct_001A9DD0_upd *upd, int p6)
{
    func_001AAAD0(m, &msg->field_10, &msg->field_11, &msg->field_12);
    CGtV3d lo = D_00665E80;
    lo -= D_004B7A60;
    CGtV3d hi = D_00665E90;
    hi += D_004B7A60;
    CGtV3d p = Min(hi - D_004B7A70, Max(lo + D_004B7A70, m->mPos));
    CGtV3d f = func_001A9DD0_inl1(p - lo, hi - lo);
    msg->field_14 = func_00389700(D_004B7A40[0], false, f.X());
    msg->field_16 = func_00389700(D_004B7A40[1], false, f.Y());
    msg->field_18 = func_00389700(D_004B7A40[2], false, f.Z());
    CGtV3d v = Min(Max(*vel, gMinLinearVelocity), D_0066C550);
    CGtV3d a = Min(Max(*ang, D_0066C560), D_0066C570);
    msg->field_1A = func_00389700(kan8VelocityNumFracBits[0], true, v.X());
    msg->field_1C = func_00389700(kan8VelocityNumFracBits[1], true, v.Y());
    msg->field_1E = func_00389700(kan8VelocityNumFracBits[2], true, v.Z());
    msg->field_20 = func_00389700(kan8PositionNumFracBits[0], true, a.X());
    msg->field_22 = func_00389700(kan8PositionNumFracBits[1], true, a.Y());
    msg->field_24 = func_00389700(kan8PositionNumFracBits[2], true, a.Z());
    msg->field_2B = 0;
    msg->field_28 = ctl->field_0;
    msg->field_29 = ctl->field_1;
    msg->field_2A = ctl->field_2;
    msg->field_13 = upd->field_4;
    msg->field_2E = upd->field_8;
    msg->field_2F = upd->field_C;
    msg->field_2C = 0;
    msg->field_2D = 0;
    if (upd->field_14) msg->field_2C |= 4;
    if (upd->field_15) msg->field_2C |= 8;
    if (upd->field_16) msg->field_2C |= 0x10;
    if (upd->field_10 == 1) msg->field_2C |= 2;
    if (upd->field_10 == 2) msg->field_2C |= 1;
    if (upd->field_17) msg->field_2C |= 0x20;
    if (upd->field_18) msg->field_2C |= 0x40;
    if (upd->field_1A) msg->field_2C |= 0x80;
    func_001A8620(msg, upd->field_1C, upd->field_20, upd->field_0);
    if (upd->field_19) msg->field_2D |= 0x80;
    msg->field_26 = p6;
}
