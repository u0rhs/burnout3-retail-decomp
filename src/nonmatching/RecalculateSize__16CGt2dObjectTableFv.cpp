// NONMATCHING: RecalculateSize__16CGt2dObjectTableFv -- retail 226 / ours 226 instructions, 13 in changed runs
// son4: sum loops read field_4 then field_0 through locals (15 -> 13); left: FP numbering th f1/f4 f2/f0 f0 and the clamp join
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)



#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dFrame.h"
#include "b3/GtMath.h"

using namespace GtMathPs2;

struct UnkStruct_0033D890_line { float field_0; float field_4; unsigned char field_8; unsigned char pad_9[3]; };
struct UnkStruct_0033D890_cell { float field_0; void (*field_4)(CGtV2d *, const CGt2dFrame &, const void *); const void *field_8; };
struct UnkStruct_0033D890_td {
    float field_0;
    float field_4;
    int field_8;
    int field_C;
    UnkStruct_0033D890_line *field_10;
    UnkStruct_0033D890_line *field_14;
    UnkStruct_0033D890_cell *field_18;
};
struct UnkStruct_0033D890_data {
    CGtV2d field_0;
    CGtV2d field_8;
    UnkStruct_0033D890_td *field_10;
    const CGt2dFrame *field_14;
};
static inline CGtV2d func_0033D890_inl(const CGtV2d &pos, const CGtV2d &size, const CGtV2d &anchor)
{
    return pos - size * anchor;
}
class CGt2dObjectTable : public CGt2dObject {
public:
    UnkStruct_0033D890_data &Data() { return *(UnkStruct_0033D890_data *)mauDataBlock; }
    void RecalculateSize();
};
void CGt2dObjectTable::RecalculateSize()
{
    UnkStruct_0033D890_data &d = Data();
    int rows = d.field_10->field_8;
    int cols = d.field_10->field_C;
    int i;
    int r;
    int c;
    CGtV2d tmp;
    CGtV2d total;
    for (i = 0; i < rows; i++) {
        if (d.field_10->field_10[i].field_8 != 0) d.field_10->field_10[i].field_4 = 0.0f;
    }
    for (i = 0; i < cols; i++) {
        if (d.field_10->field_14[i].field_8 != 0) d.field_10->field_14[i].field_4 = 0.0f;
    }
    for (r = 0; r < rows; r++) {
        c = 0;
        int ro = r * cols * 12;
        int rl = r * 12;
        for (; c < cols; c++) {
            int cl = c * 12;
            UnkStruct_0033D890_cell *cell = (UnkStruct_0033D890_cell *)((char *)(ro + (int)d.field_10->field_18) + cl);
            if (cell->field_4 != 0) {
                cell->field_4(&tmp, *d.field_14, cell->field_8);
                if (((UnkStruct_0033D890_line *)(rl + (int)d.field_10->field_10))->field_8 != 0) {
                    UnkStruct_0033D890_line *l = (UnkStruct_0033D890_line *)(rl + (int)d.field_10->field_10);
                    l->field_4 = GtMath::Max(l->field_4, tmp.marValues[1]);
                }
                if (((UnkStruct_0033D890_line *)((char *)d.field_10->field_14 + cl))->field_8 != 0) {
                    UnkStruct_0033D890_line *l = (UnkStruct_0033D890_line *)((char *)d.field_10->field_14 + cl);
                    l->field_4 = GtMath::Max(l->field_4, tmp.marValues[0]);
                }
            }
        }
    }
    float &th = total.marValues[1];
    total.marValues[0] = 0.0f;
    th = 0.0f;
    for (i = 0; i < rows; i++) {
        { UnkStruct_0033D890_line *l = &d.field_10->field_10[i]; float a = l->field_4; float b = l->field_0; th = b + (a + th); }
    }
    for (i = 0; i < cols; i++) {
        { UnkStruct_0033D890_line *l = &d.field_10->field_14[i]; float a = l->field_4; float b = l->field_0; total.marValues[0] = b + (a + total.marValues[0]); }
    }
    if (d.field_10->field_0 != -1.0f) {
        if (!(total.marValues[0] <= d.field_10->field_0)) {
            d.field_10->field_14[cols - 1].field_4 -= total.marValues[0] - d.field_10->field_0;
            total.marValues[0] = d.field_10->field_0;
        }
        if (!(th <= d.field_10->field_4)) {
            d.field_10->field_10[rows - 1].field_4 -= th - d.field_10->field_4;
            th = d.field_10->field_4;
        }
    }
    mObjectSpace.mSize = total;
    mObjectSpace.mTopLeftPos = func_0033D890_inl(d.field_0, total, d.field_8);
}

