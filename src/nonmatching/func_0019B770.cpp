// NONMATCHING: func_0019B770 -- retail 617 / ours 617 instructions, 380 in changed runs
// draftI: 617/617, 380 changed; calls, CFG, stores and VU op counts identical (lq 12/14, vmove 6/4); residue: VU register numbering of the -30/2020 lane offsets, the vertex/cross GPR choice (cross result stored from asm output: a separate t local adds a qmtc2/qmfc2 pair per site), GetSquaredLength 1.0 placed after the normal store, loop reloads top[1] from the stack in retail, frame 0xD0 vs 0x190 (16 dead by-value cross slots)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the asm: table search, lane walk, IncrementSegmentIndexClamped step, both windings and the chained-segment loop accounted for store by store

// func_0019B770 -- draftI (0x19B770, 0x9A4). In B3WrongWayWall.cpp [C asm: between CB3WrongWayWall::Release 0x19B760 and
// CB3WrongWayWall::Update 0x19C120, its only caller (0x19C698: a0 = this, a1 = the Update's s7)]. Not in the E maps (the DNAT
// build has no such function) -> placeholder name. Types/fields [G] (instruction widths).
// What it does [L, from the asm]: picks this track's (D_0064D370) row of D_00488220, finds which of its two unit-ID ranges the
// car's current streamed-track unit falls in, walks the wall's lane (field_1F8C / field_1F90) back to the first segment of its
// chain, steps forward (IncrementSegmentIndexClamped) by the range's offset, then builds two triangles per lane segment
// (the segment's two edge vertices lowered by 30 and raised by 2020) along the chain into the 0x40-byte triangle array at
// +0xA80 (p0, p1, p2, unit normal), winding chosen by the range's flag.
#include "b3/GtMathPs2.h"
#include "b3/GtMath.h"
#include "b3/GtMathPs2Quat.h"
using namespace GtMathPs2;

struct UnkStruct_0019B770_pair { unsigned short field_0; unsigned short field_2; };          // vertex indices of a segment edge
struct UnkStruct_0019B770_seg {                                                               // 10-byte lane segment record
    short field_0;
    unsigned char pad_2[0x2];
    unsigned char field_4;      // previous lane (0xFF = none)
    unsigned char field_5;      // next lane (0xFF = none)
    unsigned short field_6;     // previous segment
    unsigned short field_8;     // next segment
};
struct UnkStruct_0019B770_ls { UnkStruct_0019B770_pair * field_0; unsigned char pad_4[0x4]; UnkStruct_0019B770_seg * field_8; };
class CB3AILane {
public:
    unsigned char pad_0[0x4];
    UnkStruct_0019B770_ls * field_4;
};
struct UnkStruct_0019B770_tri { CGtV3d field_0; CGtV3d field_10; CGtV3d field_20; CGtV3d field_30; };
struct UnkStruct_0019B770 {
    unsigned char pad_0[0xA80];
    UnkStruct_0019B770_tri field_A80[42];
    unsigned char pad_1500[0xA88];
    int field_1F88;
    CB3AILane * field_1F8C;
    unsigned short field_1F90;
};
struct UnkStruct_0019B770_car { unsigned char pad_0[0x216]; signed char field_216; signed char field_217; unsigned char pad_218[0x4378]; };
struct UnkStruct_0019B770_pm { unsigned char pad_0[0x1CB80]; UnkStruct_0019B770_car field_1CB80[1]; };   // [G] count unknown
struct UnkStruct_0019B770_trk { unsigned char pad_0[0x1CC]; };                                          // CB3StreamedTrack
struct UnkStruct_0019B770_w {
    unsigned char pad_0[0x2C];
    CB3AILane field_2C[1];                  // [G] count unknown
    unsigned char pad_34[0x12A314];
    UnkStruct_0019B770_trk field_12A348[1]; // [G] count unknown
};
struct UnkStruct_0019B770_rng { int field_0; int field_4; int field_8; int field_C; };
struct UnkStruct_0019B770_row { unsigned long field_0; UnkStruct_0019B770_rng field_8[2]; };

struct UnkStruct_0019B770_gi { int field_0; unsigned char pad_4[0xC]; };            // [G] sized to keep it out of $gp
struct UnkStruct_0019B770_gl { unsigned long field_0; unsigned char pad_8[0x8]; };
struct UnkStruct_0019B770_gv { CGtV3d * field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_0019B770_gi D_00645170;
extern UnkStruct_0019B770_pm D_0055EF70;
extern UnkStruct_0019B770_w D_00522660;
extern UnkStruct_0019B770_gl D_0064D370;
extern UnkStruct_0019B770_row D_00488220[2];
extern UnkStruct_0019B770_gv D_0064D354;

extern "C" int GetUnitOriginalID__16CB3StreamedTrackFi(UnkStruct_0019B770_trk *, int);
extern "C" unsigned short IncrementSegmentIndexClamped__9CB3AILaneCFUss(const CB3AILane *, unsigned short, short);

// [L] N185 stand-in: CGtV3d::operator-(const CGtV3d&) on compiler-chosen registers (header body: hard $vf1/$vf2)
static inline CGtV3d func_0019B770_inl1(const CGtV3d& a, const CGtV3d& b)
{
    u_long128 r;
    asm("vsub.xyz %0, %1, %2" : "=j"(r) : "j"(a.mData), "j"(b.mData));
    return CGtV3d(r);
}

// [L] N256 open item stand-in: CrossProduct(a, b) with the result written over a's register (retail
// `vopmula.xyz $ACC, a, b; vopmsub.xyz a, b, a`; the header writes over b)
static inline void func_0019B770_inl3(CGtV3d& d, CGtV3d a, CGtV3d b)
{
    asm(".set noreorder");
    asm("vopmula.xyz $ACC, %1, %2" "\n\t" "vopmsub.xyz %1, %2, %1" "\n\t" "qmfc2.i %0, %1" : "=r"(d.mData), "+j"(a.mData), "+j"(b.mData));
    asm(".set reorder");
}

// [G] operator+(YAxisType, float) with the sum written over the scalar's register (retail 0x19B9DC `vaddx.y $vf2,$vf6,$vf2x`)
static inline YAxisType func_0019B770_inl4(YAxisType a, float f)
{
    u_long128 s;
    asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f));
    asm("vaddx.y %0, %1, %0x" : "+j"(s) : "j"(a.lVector));
    return YAxisType(s);
}

// [G] one wall quad (two triangles) from a lane segment's edge vertices
static inline void func_0019B770_inl2(UnkStruct_0019B770 * self, const CB3AILane * lane, unsigned short seg, int flip)
{
    CGtV3d top[2];
    CGtV3d bot[2];
    UnkStruct_0019B770_pair * e = &lane->field_4->field_0[seg];
    top[0] = D_0064D354.field_0[e->field_0];
    top[1] = D_0064D354.field_0[e->field_2];
    bot[0] = top[0];
    bot[0].SetY(top[0].Y() + -30.0f);
    top[0].SetY(func_0019B770_inl4(top[0].Y(), (float)2020));
    bot[1] = top[1];
    bot[1].SetY(top[1].Y() + -30.0f);
    top[1].SetY(func_0019B770_inl4(top[1].Y(), (float)2020));
    if (flip == 0) {
        self->field_A80[self->field_1F88].field_0 = bot[0];
        self->field_A80[self->field_1F88].field_10 = bot[1];
        self->field_A80[self->field_1F88].field_20 = top[0];
        func_0019B770_inl3(self->field_A80[self->field_1F88].field_30, func_0019B770_inl1(top[0], bot[0]), func_0019B770_inl1(bot[1], bot[0]));
        self->field_A80[self->field_1F88].field_30.Normalise();
        self->field_1F88++;
        self->field_A80[self->field_1F88].field_0 = top[0];
        self->field_A80[self->field_1F88].field_10 = bot[1];
        self->field_A80[self->field_1F88].field_20 = top[1];
        func_0019B770_inl3(self->field_A80[self->field_1F88].field_30, func_0019B770_inl1(top[1], top[0]), func_0019B770_inl1(bot[1], top[0]));
        self->field_A80[self->field_1F88].field_30.Normalise();
        self->field_1F88++;
    } else {
        self->field_A80[self->field_1F88].field_0 = bot[0];
        self->field_A80[self->field_1F88].field_10 = top[0];
        self->field_A80[self->field_1F88].field_20 = bot[1];
        func_0019B770_inl3(self->field_A80[self->field_1F88].field_30, func_0019B770_inl1(bot[1], bot[0]), func_0019B770_inl1(top[0], bot[0]));
        self->field_A80[self->field_1F88].field_30.Normalise();
        self->field_1F88++;
        self->field_A80[self->field_1F88].field_0 = bot[1];
        self->field_A80[self->field_1F88].field_10 = top[0];
        self->field_A80[self->field_1F88].field_20 = top[1];
        func_0019B770_inl3(self->field_A80[self->field_1F88].field_30, func_0019B770_inl1(bot[1], top[0]), func_0019B770_inl1(top[1], top[0]));
        self->field_A80[self->field_1F88].field_30.Normalise();
        self->field_1F88++;
    }
}

// 0x0019B770
extern "C" void func_0019B770(UnkStruct_0019B770 * self, int car)
{
    self->field_1F88 = 0;
    UnkStruct_0019B770_car * c;
    if (car < D_00645170.field_0)
        c = &D_0055EF70.field_1CB80[car];
    else
        c = 0;
    int id = GetUnitOriginalID__16CB3StreamedTrackFi(&D_00522660.field_12A348[c->field_217], c->field_216);
    bool found = false;
    int target;
    int flip;
    for (int i = 0; i < 2; i++) {
        if (D_00488220[i].field_0 == D_0064D370.field_0) {
            if (D_00488220[i].field_8[0].field_0 < id && id < D_00488220[i].field_8[0].field_4) {
                target = D_00488220[i].field_8[0].field_8;
                flip = D_00488220[i].field_8[0].field_C;
                found = true;
                break;
            }
            if (D_00488220[i].field_8[1].field_0 < id && id < D_00488220[i].field_8[1].field_4) {
                target = D_00488220[i].field_8[1].field_8;
                flip = D_00488220[i].field_8[1].field_C;
                found = true;
                break;
            }
        }
    }
    if (!found)
        return;
    const CB3AILane * lane = self->field_1F8C;
    unsigned short seg = self->field_1F90;
    UnkStruct_0019B770_seg * s = &lane->field_4->field_8[seg];
    int d = target - s->field_0;
    unsigned char l = s->field_4;
    unsigned short n = s->field_6;
    while (l != 0xFF) {
        lane = &D_00522660.field_2C[l];
        seg = n;
        s = &lane->field_4->field_8[seg];
        l = s->field_4;
        n = s->field_6;
    }
    seg = IncrementSegmentIndexClamped__9CB3AILaneCFUss(lane, seg, d);
    func_0019B770_inl2(self, lane, seg, flip);
    s = &lane->field_4->field_8[seg];
    l = s->field_5;
    n = s->field_8;
    while (l != 0xFF) {
        lane = &D_00522660.field_2C[l];
        seg = n;
        func_0019B770_inl2(self, lane, seg, flip);
        s = &lane->field_4->field_8[seg];
        l = s->field_5;
        n = s->field_8;
    }
}
