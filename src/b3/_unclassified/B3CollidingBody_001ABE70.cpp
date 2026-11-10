// CB3CollidingBody::CacheWorldTriangles() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3CollidingBody.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (b2src: hand-written from asm (lifter refused vmulw.w); shape cross-checked vs Burnout 2 CCollidingBody::CacheWorldTriangles (b3dllc/burnout2@61e466e); N140 pad, pointer-arg TestPosition as proven siblings, D_0051BA88 >8B (N50)).

// Hand-written from the retail asm (the lifter refused it: vmulw.w). Shape cross-checked against
// Burnout 2's CCollidingBody::CacheWorldTriangles (github.com/b3dllc/burnout2 @ 61e466e295e34abf3de7816c220e4b09ba95022d,
// src/nodebug/CCollidingBody.cpp): bounding sphere built, unit found by TestPosition, then a near-unit sphere query with
// a triangle-collecting callback. No Burnout 2 name is used for any Burnout 3 symbol (provenance rule).
// [G] func_001ABE70_inl1: sphere radius copied from another sphere's w lane (vmulw.w); API name not in our tables.
#include "b3/GtMathPs2.h"

struct UnkStruct_001ABE70_cache { int field_0; };
struct UnkStruct_001ABE70_mat { unsigned char pad_0[0x30]; GtMathPs2::CGtV3d field_30; };
struct UnkStruct_001ABE70_trk { unsigned char pad_0[0x1CC]; };
struct UnkStruct_D_00522660_cwt {
    unsigned char pad_0[0x12A348];
    UnkStruct_001ABE70_trk field_12A348[2];
};
class CB3CollidingBody {
public:
    void CacheWorldTriangles();
    unsigned char pad_0[0x1C0];
    GtMathPs2::CGtSphere field_1C0;
    unsigned char pad_1D0[0x30];
    UnkStruct_001ABE70_cache * field_200;
    UnkStruct_001ABE70_mat * field_204;
    unsigned char pad_208[0xD];
    signed char field_215;
    signed char field_216;
    signed char field_217;
};
extern UnkStruct_D_00522660_cwt D_00522660;
extern unsigned char D_004E2704;
struct UnkStruct_D_0051BA88 {
    void * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};
extern UnkStruct_D_0051BA88 D_0051BA88;
extern unsigned char D_0051AEC0[];
extern "C" signed char TestPosition__16CB3StreamedTrackFQ29GtMathPs26CGtV3d(UnkStruct_001ABE70_trk *, const GtMathPs2::CGtV3d *);
extern "C" int func_00301B00(UnkStruct_001ABE70_trk *, int, GtMathPs2::CGtSphere *, void (*)(), CB3CollidingBody *);
extern "C" void func_001ABFC0();

struct UnkStruct_001ABE70_pad { u_long128 x[2]; UnkStruct_001ABE70_pad() {} ~UnkStruct_001ABE70_pad() {} };  // [G] N140 frame pad

// [G] inlined: sphere radius copied from another sphere's w lane (vmulw.w D,$vf0,Sw); no API name in our tables
static inline void func_001ABE70_inl1(GtMathPs2::CGtSphere & d, const GtMathPs2::CGtSphere & s)
{
    asm("vmulw.w %0, $vf0, %1w" : "+j"(d.mData) : "j"(s.mData));
}

// 0x001ABE70
void CB3CollidingBody::CacheWorldTriangles()
{
    GtMathPs2::CGtSphere s;
    UnkStruct_001ABE70_pad g;  // [G] N140 frame pad (retail's unused 0x20 at sp+0x20)
    field_200->field_0 = 0;
    D_004E2704 = 0;
    func_001ABE70_inl1(s, field_1C0);
    s.SetPosition(field_204->field_30);
    field_216 = TestPosition__16CB3StreamedTrackFQ29GtMathPs26CGtV3d(&D_00522660.field_12A348[field_217], &field_204->field_30);
    if (field_216 == -1 && field_215 != 1 && D_0051BA88.field_0 == D_0051AEC0) {
        field_217 = 1 - field_217;
        field_216 = TestPosition__16CB3StreamedTrackFQ29GtMathPs26CGtV3d(&D_00522660.field_12A348[field_217], &field_204->field_30);
    }
    if (field_216 >= 0) {
        func_00301B00(&D_00522660.field_12A348[field_217], field_216, &s, func_001ABFC0, this);
    }
}
