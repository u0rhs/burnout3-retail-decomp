// NONMATCHING: func_001AA3F0 -- retail 153 / ours 156 instructions, 82 in changed runs
// draftAN fork C C-first: [L] one crashing-traffic entry of the network race update message (callee of func_001A9D70 = [L] AddCrashingTraffic): byte angles via func_001AAAD0, position clamped into the widened track box and normalised by its size (VU0 lane divide, stand-in), velocity / second vector clamped and packed by func_00389700, id byte last; 156/153, calls identical, non-stack stores identical
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm, mirror of the archived readers func_001A8800/func_001A9200; every call argument (bits table, signed flag, lane), clamp order (max then min) and store traced

// func_001AA3F0 -- draftAN fork C (C-first draft). 0x1AA3F0, 0x264. Unnamed in every table: the asm label, C linkage.
// [L] one crashing-traffic entry (0x16 bytes) of the network race update message: called only by func_001A9D70 (the
// [L] E-build CB3NetworkRaceUpdateMessage::AddCrashingTraffic(unsigned char, const CGtMatrix3x4*, const CGtV3d*, const
// CGtV3d*): it passes &entries[count] (this + 0x30 + 0x16 * count) and forwards its own a1..t0 unchanged). The packing is
// the mirror of the matched/archived readers: func_001A8800 ([L] RetrieveCrashingTraffic) and func_001A9200 ([L] Retrieve):
// three byte angles (func_001AAAD0), the position clamped into the track box (D_00665E80/90 widened by kPosSafetyOffset
// D_004B7A60, kept D_004B7A70 inside it) and normalised to 0..1 by the box size, then velocity / second vector clamped to
// D_0066C550.. (func_001AA1A0 sets those ranges) and each lane fixed-point packed by func_00389700. Types [G] from widths.
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

struct UnkStruct_001AA3F0 {            // [L] = func_001A8800's crashing-traffic entry
    unsigned char field_0;              // three byte angles (func_001AAAD0)
    unsigned char field_1;
    unsigned char field_2;
    unsigned char field_3;              // the id byte (a1)
    unsigned short field_4;             // position lanes, unsigned fixed point (D_004B7A40 frac bits)
    unsigned short field_6;
    unsigned short field_8;
    unsigned short field_A;             // velocity lanes, signed (kan8VelocityNumFracBits)
    unsigned short field_C;
    unsigned short field_E;
    unsigned short field_10;            // second vector lanes, signed (kan8PositionNumFracBits, as retail's table name)
    unsigned short field_12;
    unsigned short field_14;
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
extern "C" unsigned short func_00389700(signed char bits, bool isSigned, float f);

// [L] stand-in: lane-wise a / b as retail does it on VU0 (Q = 1 / b.lane; r.lane = a.lane * Q), no GtMathPs2 API.
// [C] retail's w lane is whatever the destination register held (a callee-saved GPR's caller value): never read.
static inline CGtV3d func_001AA3F0_inl1(const CGtV3d &a, const CGtV3d &b)
{
    u_long128 r;
    asm("vdiv $Q, $vf0w, %2x" "\n\t" "vwaitq" "\n\t" "vmulq.x %0, %1, $Q" : "+j"(r) : "j"(a.mData), "j"(b.mData));
    asm("vdiv $Q, $vf0w, %2y" "\n\t" "vwaitq" "\n\t" "vmulq.y %0, %1, $Q" : "+j"(r) : "j"(a.mData), "j"(b.mData));
    asm("vdiv $Q, $vf0w, %2z" "\n\t" "vwaitq" "\n\t" "vmulq.z %0, %1, $Q" : "+j"(r) : "j"(a.mData), "j"(b.mData));
    return CGtV3d(r);
}

// 0x001AA3F0
extern "C" void func_001AA3F0(UnkStruct_001AA3F0 *e, unsigned char id, const CGtMatrix3x4 *m, const CGtV3d *vel,
                              const CGtV3d *ang)
{
    func_001AAAD0(m, &e->field_0, &e->field_1, &e->field_2);
    CGtV3d lo = D_00665E80;
    lo -= D_004B7A60;
    CGtV3d hi = D_00665E90;
    hi += D_004B7A60;
    CGtV3d p = Min(hi - D_004B7A70, Max(lo + D_004B7A70, m->mPos));
    CGtV3d f = func_001AA3F0_inl1(p - lo, hi - lo);
    e->field_4 = func_00389700(D_004B7A40[0], false, f.X());
    e->field_6 = func_00389700(D_004B7A40[1], false, f.Y());
    e->field_8 = func_00389700(D_004B7A40[2], false, f.Z());
    CGtV3d v = Min(Max(*vel, gMinLinearVelocity), D_0066C550);
    CGtV3d a = Min(Max(*ang, D_0066C560), D_0066C570);
    e->field_A = func_00389700(kan8VelocityNumFracBits[0], true, v.X());
    e->field_C = func_00389700(kan8VelocityNumFracBits[1], true, v.Y());
    e->field_E = func_00389700(kan8VelocityNumFracBits[2], true, v.Z());
    e->field_10 = func_00389700(kan8PositionNumFracBits[0], true, a.X());
    e->field_12 = func_00389700(kan8PositionNumFracBits[1], true, a.Y());
    e->field_14 = func_00389700(kan8PositionNumFracBits[2], true, a.Z());
    e->field_3 = id;
}
