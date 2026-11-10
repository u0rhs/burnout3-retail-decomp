// NONMATCHING: RenderCellWithTriangle__28CB3OnScreenKeyboardComponentFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv -- retail 263 / ours 280 instructions, 193 in changed runs
// draftAN fork B C-first (shape of the archived sibling RenderCell): +0x39 visibility, the box (RenderBox with the cell data, or for the unselected colour a CB3Panel2dObject at pos + size*anchor through its callback in frame space), then an 8x16 RenderTriStripFlatUntex triangle in Min(+0x20 colour * WorldColour, 1) at WorldPos + WorldScale*pos + size*fraction(+0x30), apex left when +0x3A is set; 280/263, calls identical (callback through t9 vs v0)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm against RenderCell: the 4-lane colour compare, both box branches' argument lists, the triangle vertices (constant-first adds 4 + x / 8 + y kept) and the +0x3A sense traced; behaviour_audit: only the operator== stand-in's bool-chain shape (andi 0xFF / materialised flags, as the sibling RenderCell)

// CB3OnScreenKeyboardComponent::RenderCellWithTriangle(const CGtV2d&, const CGtV2d&, unsigned short*, const CGt2dFrame&, const void*)
// -- draftAN fork B (C-first draft). 0x34DAD0, 0x41C. [C] name: the mangled symbol in retail's tables (a table cell render callback,
// static: no this). Shape from the archived sibling RenderCell (0x34DEF0: the operator== stand-in, the Panel2dObject branch, the
// frame transform as func_0033E220).
// What it draws [L]: nothing unless the cell's +0x39 flag is set; the cell box (RenderBox with the cell data, or for the unselected
// box colour a CB3Panel2dObject at pos + size x anchor), then a 3-vertex RenderTriStripFlatUntex triangle 8 wide / 16 high in the
// cell's +0x20 colour (x frame colour, clamped to 1) at the frame position of pos + the cell size x the +0x30 fraction, pointing left
// when +0x3A is set, right otherwise. Types and field meanings [G].
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dFrame.h"
using namespace GtMathPs2;

struct UnkStruct_0034DAD0 {                 // the cell data block (offsets from retail's loads)
    CGtV4d field_0;                         // box colour (compared with the unselected colour; RenderBox reads it)
    CGtV2d field_10;                        // box anchor
    CGtV2d field_18;                        // box size
    CGtV4d field_20;                        // triangle colour
    CGtV2d field_30;                        // [G] triangle position, fraction of field_18
    unsigned char pad_38[1];
    bool field_39;                          // [G] cell visible
    bool field_3A;                          // [G] triangle points left
};
class CB3Panel2dObject : public CGt2dObject {
public:
    void Prepare(const CGtV2d &, const CGtV2d &, const CGtV2d &, bool, bool);
    unsigned char pad_40[0x40];
};
extern const CGtV4d kB3OnScreenKeyboardUnSelectedBoxColour;
extern "C" void RenderBox__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv(const CGtV2d &, const CGtV2d &, unsigned short *, const CGt2dFrame &, const void *);

// [L] N185: stand-in for GtMathPs2::Min(CGtV4d, CGtV4d) (as RenderCell)
static inline CGtV4d func_0034DAD0_min(const CGtV4d &a, const CGtV4d &b)
{
    u_long128 r;
    asm("vmini.xyzw %0, %1, %2" : "=j"(r) : "j"(a.mData), "j"(b.mData));
    return CGtV4d(r);
}
// [L] stands in for GtMathPs2::CGtV4d::operator==(CGtV4d) (B3O0PCH map, not in the header): lane-wise (as RenderCell)
static inline int func_0034DAD0_eq(const CGtV4d &a, const CGtV4d &b)
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
    static void RenderCellWithTriangle(const CGtV2d &pos, const CGtV2d &size, unsigned short *text, const CGt2dFrame &frame, const void *data);
};

// 0x0034DAD0
void CB3OnScreenKeyboardComponent::RenderCellWithTriangle(const CGtV2d &pos, const CGtV2d &size, unsigned short *text,
                                                          const CGt2dFrame &frame, const void *data)
{
    const UnkStruct_0034DAD0 *d = (const UnkStruct_0034DAD0 *)data;
    CGtV4d white(1.0f, 1.0f, 1.0f, 1.0f);
    if (!d->field_39) return;
    if (!func_0034DAD0_eq(d->field_0, kB3OnScreenKeyboardUnSelectedBoxColour)) {
        RenderBox__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv(pos, size, text, frame, data);
    } else {
        CB3Panel2dObject obj;
        CGt2dObject::CGt2dObjectSpace sp;
        CGtV4d white2(1.0f, 1.0f, 1.0f, 1.0f);
        CGtV2d p = pos + size * d->field_10;
        obj.Prepare(p, d->field_10, d->field_18, true, false);
        sp = obj.ObjectSpace();
        sp.mTopLeftPos = frame.WorldPos() + frame.WorldScale() * sp.mTopLeftPos;
        sp.mSize = sp.mSize * frame.WorldScale();
        sp.mColour = func_0034DAD0_min(sp.mColour * frame.WorldColour(), white2);
        obj.Render(sp);
    }
    CGtV4d c = func_0034DAD0_min(d->field_20 * frame.WorldColour(), white);
    CGtV2d lPos = frame.WorldPos() + frame.WorldScale() * pos;
    CGtV2d t = lPos + d->field_18 * d->field_30;
    CGtV2d tri[3];
    if (d->field_3A) {
        tri[0] = t;
        tri[1].Set(4.0f + t.X(), t.Y());
        tri[2].Set(4.0f + t.X(), t.Y());
        tri[0].Set(tri[0].X() - 4.0f, tri[0].Y());
        tri[1].Set(tri[1].X(), tri[1].Y() - 8.0f);
        tri[2].Set(tri[2].X(), 8.0f + tri[2].Y());
    } else {
        tri[0] = t;
        tri[1].Set(t.X() - 4.0f, t.Y());
        tri[2].Set(t.X() - 4.0f, t.Y());
        tri[0].Set(4.0f + tri[0].X(), tri[0].Y());
        tri[1].Set(tri[1].X(), tri[1].Y() - 8.0f);
        tri[2].Set(tri[2].X(), 8.0f + tri[2].Y());
    }
    Gt2dRenderer::RenderTriStripFlatUntex(c, CGtV2d(0.0f, 0.0f), 3, tri);
}
