// NONMATCHING: RenderCell__28CB3OnScreenKeyboardComponentFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv -- retail 235 / ours 240 instructions, 142 in changed runs
// 142 instrs (240/235): logic per retail (CGtV4d operator== stand-in with eager lane reads, panel tail as func_0033E220, style copy by assignment); remaining: eq stand-in reloads the colour global / extra andi, frame 0x2E0 vs 0x2C0 slot layout
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// CB3OnScreenKeyboardComponent::RenderCell(const CGtV2d&,const CGtV2d&,unsigned short*,const CGt2dFrame&,const void*)
// -- hand-written (fresh6). A table cell render callback (static: no this). [C] name: the mangled symbol. The panel
// tail follows the proven sibling func_0033E220 (ObjectSpace / WorldPos / WorldScale / WorldColour, Min with white).
// Every type is [G] (instruction widths).
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dFrame.h"

using namespace GtMathPs2;

// [G] the table cell's text data block (offsets from retail's loads/copies)
struct UnkStruct_0034DEF0_text {
    CGtV4d field_0;
    CGtV4d field_10;
    CGtV4d field_20;
    CGtV2d field_30;
    CGtV2d field_38;
    float field_40;
    const void *field_44;
    const unsigned short *field_48;
    int field_4C;
};
struct UnkStruct_0034DEF0 {
    UnkStruct_0034DEF0_text field_0;
    CGtV4d field_50;
    CGtV2d field_60;
    CGtV2d field_68;
    CGtV2d field_70;
    float field_78;
    float field_7C;
    bool field_80;
    bool field_81;
};
class CB3Panel2dObject : public CGt2dObject {
public:
    void Prepare(const CGtV2d &, const CGtV2d &, const CGtV2d &, bool, bool);
    unsigned char pad_40[0x40];
};
struct UnkStruct_D_004C7140 { unsigned char pad_0[0x10]; };

extern const CGtV4d kB3OnScreenKeyboardUnSelectedBoxColour;
extern UnkStruct_D_004C7140 D_004C7140;
extern "C" void ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(void *, void *, int);
extern "C" void RenderBox__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv(const CGtV2d &, const CGtV2d &, unsigned short *, const CGt2dFrame &, const void *);
extern "C" void RenderText__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv(const CGtV2d &, const CGtV2d &, unsigned short *, const CGt2dFrame &, const void *);

// [L] N185: stand-in for GtMathPs2::Min(CGtV4d, CGtV4d), both operands by reference (as func_0033E220)
static inline CGtV4d func_0034DEF0_min(const CGtV4d &a, const CGtV4d &b)
{
    u_long128 r;
    asm("vmini.xyzw %0, %1, %2" : "=j"(r) : "j"(a.mData), "j"(b.mData));
    return CGtV4d(r);
}
// [L] stands in for GtMathPs2::CGtV4d::operator==(CGtV4d) (B3O0PCH map, not in the header): lane-wise through the axis reads
static inline int func_0034DEF0_eq(const CGtV4d &a, const CGtV4d &b)
{
    float ax = a.X();
    float ay = a.Y();
    float az = a.Z();
    float aw = a.W();
    float bx = b.X();
    float by = b.Y();
    float bz = b.Z();
    float bw = b.W();
    int r = ax == bx;
    if (r) r = ay == by;
    if (r) r = az == bz;
    if (r) r = aw == bw;
    return r;
}

class CB3OnScreenKeyboardComponent {
public:
    static void RenderCell(const CGtV2d &pos, const CGtV2d &size, unsigned short *text, const CGt2dFrame &frame, const void *data);
};

// 0x0034DEF0
void CB3OnScreenKeyboardComponent::RenderCell(const CGtV2d &pos, const CGtV2d &size, unsigned short *text, const CGt2dFrame &frame, const void *data)
{
    unsigned short buf[2];
    CGtV2d tp;
    CGtV2d p;
    UnkStruct_0034DEF0_text st;
    CB3Panel2dObject obj;
    CGt2dObject::CGt2dObjectSpace sp;
    CGtV4d white;
    const UnkStruct_0034DEF0 *d = (const UnkStruct_0034DEF0 *)data;
    if (!d->field_81) return;
    if (!func_0034DEF0_eq(d->field_50, kB3OnScreenKeyboardUnSelectedBoxColour)) {
        RenderBox__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv(pos, size, text, frame, &d->field_50);
    } else {
        white = CGtV4d(1.0f, 1.0f, 1.0f, 1.0f);
        p = pos + size * d->field_60;
        obj.Prepare(p, d->field_60, d->field_68, true, false);
        sp = obj.ObjectSpace();
        sp.mTopLeftPos = frame.WorldPos() + frame.WorldScale() * sp.mTopLeftPos;
        sp.mSize = sp.mSize * frame.WorldScale();
        sp.mColour = func_0034DEF0_min(sp.mColour * frame.WorldColour(), white);
        obj.Render(sp);
    }
    tp.marValues[0] = pos.marValues[0] + d->field_70.marValues[0];
    tp.marValues[1] = pos.marValues[1];
    tp.marValues[1] = tp.marValues[1] + d->field_70.marValues[1];
    if (d->field_80) {
        RenderText__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv(tp, d->field_68, text, frame, d);
    } else {
        RenderText__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv(tp, size, text, frame, d);
    }
    if (d->field_78 == -1.0f) return;
    st = d->field_0;
    st.field_48 = buf;
    tp.marValues[0] = tp.marValues[0] + d->field_78;
    tp.marValues[1] = tp.marValues[1] + d->field_7C;
    ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(&D_004C7140, buf, 2);
    RenderText__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv(tp, size, text, frame, &st);
}
