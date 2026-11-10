// NONMATCHING: _Render__16CGt2dObjectTableFRCQ211CGt2dObject16CGt2dObjectSpacePCv -- retail 122 / ours 122 instructions, 9 in changed runs
// prag1: LOGIC FIX -- j, cols and t1 are int (retail's inner test is slt, the mwperm source had unsigned -> sltu); this archive compiles to 9 today, not the 5 in its old header. Left: s2/s6 swap (cols vs &cur.y), addu fp,v1 order; second-pragma sweep, decl/definition order of cols no change
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// frame/layout exact (base assigned from temp gives the extra slot); 11 instrs: s2/s6 swap (cols vs &cur.y pointer), add.s operand order (retail elem+cursor f1,f0; ours f0,f1; commutes identically for += / a+b / b+a), addu fp,v1 order; &cur.y ref/ptr locals worse | mwperm: 11 -> 5 (+'// N182: `#pragma opt_arithtransformation off` ([G] scoped to this function; fou'; 'const UnkStruct_RT_20 *d = (const UnkStruct_RT_20 *)data;' -> 'float t7; float t17; const void * v1; const void * v2 = data; float t6; v1 = v2;'; +'UnkStruct_RT_Cell *cell;'; +'float t12; v0 = v1; const UnkStruct_RT_20 *d = (const UnkStruct_RT_20 *)v0;'; 'base = (space.mTopLeftPos - d->field_14->field_20) / d->fi)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

#include "b3/GtMathPs2.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"
using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;
struct UnkStruct_RT_Frame { unsigned char pad_0[0x20]; CGtV2d field_20; CGtV2d field_28; };
struct UnkStruct_RT_Vec { float field_0; float field_4; float field_8; };
struct UnkStruct_RT_Cell { void (*field_0)(CGtV2d *, CGtV2d *, int, UnkStruct_RT_Frame *, int); int field_4; int field_8; };
struct UnkStruct_RT_Data {
    unsigned char pad_0[8];
    int field_8;
    int field_C;
    UnkStruct_RT_Vec *field_10;
    UnkStruct_RT_Vec *field_14;
    UnkStruct_RT_Cell *field_18;
    int field_1C;
};
struct UnkStruct_RT_20 {
    CGtV2d field_0;
    CGtV2d field_8;
    UnkStruct_RT_Data *field_10;
    UnkStruct_RT_Frame *field_14;
};
class CGt2dObjectTable : public CGt2dObject {
public:
    static void _Render(const CGt2dObjectSpace &, const void *);
};
// N182: `#pragma opt_arithtransformation off` ([G] scoped to this function; found by mwperm).
#pragma push
#pragma opt_arithtransformation off
// 0x0033ED30
void CGt2dObjectTable::_Render(const CGt2dObjectSpace &space, const void *data)
{
    float t7;
    float t17;
    const void * v1;
    const void * v2 = data;
    float t6;
    v1 = v2;
    int cols;
    int rowOff;
    int t16;
    float t2;
    bool t0;
    const void * v0;
    int t1;
    CGtV2d cur;
    UnkStruct_RT_Cell *cell;
    CGtV2d sz;
    float t12;
    v0 = v1;
    const UnkStruct_RT_20 *d = (const UnkStruct_RT_20 *)v0;
    CGtV2d base;
    UnkStruct_RT_Frame *const t19 = d->field_14;
    UnkStruct_RT_Frame *const t9 = t19;
    int i = 0;
    base = (space.mTopLeftPos - t9->field_20) / d->field_14->field_28;
    UnkStruct_RT_Data *const t3 = d->field_10;
    cur = base;
    const unsigned int t5 = t3->field_8;
    const int rows = t5;
    int t18 = d->field_10->field_C;
    cols = t18;
    goto loop0_t;
loop0:
    const float t10 = base.marValues[0];
    cur.marValues[0] = t10;
    t12 = cur.marValues[1];
    float t23 = d->field_10->field_10[i].field_0;
    float t22 = t23;
    t7 = t22 + t12;
    cur.marValues[1] = t7;
    int j = 0;
    rowOff = ((i * cols) * 12);
    goto loop1_t;
loop1:
    t1 = (12 * j);
    float t25 = d->field_10->field_14[j].field_0;
    cur.marValues[0] = ((t25 + cur.marValues[0]));
    const UnkStruct_RT_Data *const t13 = d->field_10;
    sz.marValues[0] = t13->field_14[j].field_4;
    float t21 = d->field_10->field_10[i].field_4;
    sz.marValues[1] = t21;
    char * t11 = ((((char *)d->field_10->field_18) + rowOff)) + t1;
    cell = ((UnkStruct_RT_Cell *)(t11));
    t0 = 0 != cell->field_0;
    if (t0) {
        cell->field_0(&cur, &sz, d->field_10->field_1C, d->field_14, cell->field_8);
    }
    UnkStruct_RT_Vec * t8 = d->field_10->field_14;
    t2 = t8[j].field_4;
    float t14 = cur.marValues[0];
    cur.marValues[0] = t2 + t14;
    const int t24 = j + 1;
    j = t24;
loop1_t:
    t16 = j < cols;
    if (t16 == 0) {
    } else {
        goto loop1;
    }
    t6 = cur.marValues[1];
    t17 = d->field_10->field_10[i].field_4;
    const float t4 = t6;
    float t15 = t17 + t4;
    i += 1;
    cur.marValues[1] = t15;
loop0_t:
    const bool t20 = i < rows;
    if (t20) {
        goto loop0;
    }
}
