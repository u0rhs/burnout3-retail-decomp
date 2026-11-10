// CB3PhysicsManagerDebug::DrawHullToHullCollisionPlanes() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3PhysicsManagerDebug.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (ghvu4: Ghidra draft; header TransformPoint in an N188 noreorder region inside a [G] inline holding the N140 pad; decl order fixes s-regs).

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

struct CGtLine { CGtV3d field_0; CGtV3d field_10; CGtLine() {} CGtLine(CGtV3d a, CGtV3d b) { field_0 = a; field_10 = b; } };
struct UnkStruct_002BDA00_hull { unsigned char pad_0[0x8]; CGtV3d * field_8; unsigned char pad_C[0xC]; unsigned char field_18; };
struct UnkStruct_002BDA00_rec { CGtMatrix3x4 field_0; UnkStruct_002BDA00_hull * field_40; unsigned char field_44; unsigned char pad_45[0x2B]; };
struct UnkStruct_D_004EB1E0 { unsigned char pad_0[0x10]; };
extern UnkStruct_D_004EB1E0 D_004EB1E0;
extern "C" void DrawLine__15CB3DebugManagerFRC7CGtLineQ29GtMathPs26CGtV4d(void *, const CGtLine &, CGtV4d);
class CB3PhysicsManagerDebug {
public:
    void DrawHullToHullCollisionPlanes();
    unsigned char pad_0[0x1B50];
    UnkStruct_002BDA00_rec field_1B50[8];
    unsigned int field_1ED0;
};

// [G] N140 frame pad: retail's frame keeps one unused 16-byte slot below the colour (declared in the inline below, N186).
struct UnkStruct_002BDA00_pad { int x[4]; UnkStruct_002BDA00_pad() {} ~UnkStruct_002BDA00_pad() {} };

// [G] placeholder inline: the hull point transform; the N188 noreorder region around the header TransformPoint keeps
// its result qmfc2 straight after the vmaddw, as retail.
static inline CGtV3d func_002BDA00_inl1(const CGtMatrix3x4 &m, const CGtV3d &v) { UnkStruct_002BDA00_pad p; asm(".set noreorder"); CGtV3d r = TransformPoint(m, v); asm(".set reorder"); return r; }

// 0x002BDA00
void CB3PhysicsManagerDebug::DrawHullToHullCollisionPlanes()
{
    CGtV3d pts[22];
    CGtLine line;
    CGtV4d col(1.0f, 1.0f, 1.0f, 1.0f);
    unsigned char k;
    unsigned int i;
    unsigned char a;
    unsigned char b;
    UnkStruct_002BDA00_rec * r;
    for (i = 0; i < field_1ED0; i++) {
        r = &field_1B50[i];
        UnkStruct_002BDA00_hull * h = field_1B50[i].field_40;
        int n = h->field_18;
        CGtV3d * src = h->field_8;
        for (int j = 0; j < n; j++) {
            pts[j] = func_002BDA00_inl1(r->field_0, src[j]);
        }
        for (k = 0; k < r->field_44; k++) {
            a = 0;
            b = 1;
            do {
                line.field_0 = pts[a];
                line.field_10 = pts[b];
                DrawLine__15CB3DebugManagerFRC7CGtLineQ29GtMathPs26CGtV4d(&D_004EB1E0, line, col);
                b = (b + 1) % 3;
                a++;
            } while (a < 3);
        }
    }
    field_1ED0 = 0;
}
