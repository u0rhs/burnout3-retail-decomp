// NONMATCHING: func_00453680 -- retail 151 / ours 151 instructions, 14 in changed runs
// 18 instrs, prologue scheduling only (retail interleaves lui 1.0/600.0, row ptr, lh base, s-reg moves differently); all blocks/switch/copy exact | mwperm: 18 -> 14 (+'int v8 = a2; int v7 = v8; UnkStruct_00453680 * v6 = self; int v5 = v7; unsigned '; +'float ax; ax = 1.0f; CGtV2d pos; char * t7 = ((char *)v2 + 0x24 * v0) + 0xC; Unk'; 'UnkStruct_00453680_row *r = (UnkStruct_00453680_row *)((char' -> ''; +'CGtV2d anchor;'; 'CGtV2d pos; CGtV2d anchor;' -> 'void * t5 = v2->field_12C;'; 'int base1 = self->field_8 + 1; r->field_8 = ConstructChild__' -> 'unsigned int)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"

using namespace GtMathPs2;

struct UnkStruct_D_16 { unsigned char pad_0[0x10]; };
extern UnkStruct_D_16 D_01E903E0;
extern UnkStruct_D_16 D_004D3160;
extern UnkStruct_D_16 D_004D3150;
struct UnkStruct_D_01E90240 { unsigned char pad_0[0x110]; CGtV4d field_110; };
extern UnkStruct_D_01E90240 D_01E90240;
extern "C" void *ConstructChild__10CGt2dFrameFv(void *);
extern "C" void SetIdentity__Q210CGt2dFrame15CGt2dFrameSpaceFv(void *);
extern "C" CGt2dObject *ConstructObject__10CGt2dSceneFiP10CGt2dFrame(void *, int, void *);
extern "C" void Prepare__24CB3HUDBackground2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dUi(void *, const CGtV2d &, const CGtV2d &, const CGtV2d &, CGtV4d, unsigned int);
struct UnkStruct_00453680_obj {
    u_long128 field_0;
    u_long128 field_10;
    int field_20[6];
    int field_38;
    int field_3C;
};
struct UnkStruct_00453680_q2 { u_long128 q[2]; };
struct UnkStruct_00453680_d6 { int d[6]; };
struct UnkStruct_00453680_row {
    CGt2dObject *field_0;
    CGt2dObject *field_4;
    void *field_8;
};
struct UnkStruct_D_01E903F4 { void *field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_00453680 {
    unsigned char pad_0[8];
    short field_8;
    unsigned char pad_A[0x122];
    void *field_12C;
    unsigned char pad_130[0x98];
    unsigned char field_1C8[8];
    unsigned char field_1D0[8];
};

// 0x00453680
extern "C" void func_00453680(UnkStruct_00453680 *self, int row, int a2, int type)
{
    int v8 = a2;
    int v7 = v8;
    UnkStruct_00453680 * v6 = self;
    int v5 = v7;
    unsigned int v4 = type;
    UnkStruct_00453680 * v2 = v6;
    UnkStruct_00453680_d6 * t1;
    const unsigned int v3 = row;
    UnkStruct_00453680_obj *o;
    CGt2dObject * t0;
    UnkStruct_00453680_obj *m;
    int v1 = v3;
    unsigned int v0 = v1;
    void *const scene = &D_01E903E0;
    float ax;
    ax = 1.0f;
    CGtV2d pos;
    char * t7 = ((char *)v2 + 0x24 * v0) + 0xC;
    UnkStruct_00453680_row *const r = (UnkStruct_00453680_row *)(t7);
    UnkStruct_D_01E90240 *const mgr = &D_01E90240;
    float px = 600.0f;
    CGtV2d anchor;
    float w;
    void * t5 = v2->field_12C;
    CGtV2d size;
    unsigned int t4 = (unsigned int)v2->field_8;
    const unsigned int base1 = (int)((unsigned int)1 + t4);
    bool t3;
    r->field_8 = ConstructChild__10CGt2dFrameFv(t5);
    SetIdentity__Q210CGt2dFrame15CGt2dFrameSpaceFv(r->field_8);
    self->field_1C8[row] = a2;
    self->field_1D0[row] = type;
    r->field_0 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, base1, r->field_8);
    switch (v4) {
    case 0: w = 300.0f; break;
    case 1: w = 340.0f; break;
    case 2: w = 380.0f; break;
    case 3: w = 480.0f; ax = 0.5f; px = 320.0f; break;
    case 4: w = 560.0f; break;
    }
    size.marValues[0] = w;
    size.marValues[1] = 30.0f;
    anchor.marValues[0] = ax;
    anchor.marValues[1] = 0.5f;
    pos.marValues[0] = px;
    pos.marValues[1] = 0.0f;
    Prepare__24CB3HUDBackground2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dUi(r->field_0, pos, anchor, size, mgr->field_110, 3);
    t3 = 6 <= v5;
    if (a2 >= 6) {
        r->field_4 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, self->field_8, r->field_8);
        t0 = r->field_4;
        o = (UnkStruct_00453680_obj *)r->field_0;
        m = (UnkStruct_00453680_obj *)r->field_4;
        UnkStruct_00453680_q2 * t2;
        t2 = (UnkStruct_00453680_q2 *)m;
        *t2 = *(UnkStruct_00453680_q2 *)o;
        t1 = (UnkStruct_00453680_d6 *)o->field_20;
        *(UnkStruct_00453680_d6 *)m->field_20 = *(UnkStruct_00453680_d6 *)o->field_20;
        m->field_38 = o->field_38;
        m->field_3C = o->field_3C;
        r->field_4->mObjectSpace.mColour = *(const CGtV4d *)&D_004D3160;
        r->field_0->mObjectSpace.mColour = *(const CGtV4d *)&D_004D3150;
    }
}
