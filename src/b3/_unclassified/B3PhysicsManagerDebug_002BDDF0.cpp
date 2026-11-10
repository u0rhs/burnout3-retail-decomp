// CB3PhysicsManagerDebug::DrawCollisionWorld() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3PhysicsManagerDebug.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (ghvu1: header CGtSphere SetPosition+SetRadius wrapped in one [G] inline (slot order + VU numbering)).

// CB3PhysicsManagerDebug::DrawCollisionWorld() -- hand-written (ghvu1, Ghidra-draft trial).
// [C] name: the mangled symbol in retail's tables; class/fields declared here with only what this function touches,
// field names are placeholders and every type is [G] (instruction widths).
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
struct CGtPolygonIntersectionResult;
struct CB3Im3dVertex;
struct CGtTexture;
struct UnkStruct_002BDDF0_rnd { unsigned int field_0; unsigned int field_4; };
extern int _gnNumColWorldPoints;
extern UnkStruct_002BDDF0_rnd _gRandomColour;
extern void *_gpPolySoupVertices;
extern CGtV3d D_0064D3E0;
extern unsigned char D_0064C9A8[];
extern CB3Im3dVertex D_01E85A50[];
extern "C" int TestPosition__16CB3StreamedTrackFQ29GtMathPs26CGtV3d(void *, CGtV3d);
extern "C" int func_00301B00(void *, unsigned int, const CGtSphere &, bool (*)(const CGtPolygonIntersectionResult &, void *), void *);
extern "C" bool func_002BE260(const CGtPolygonIntersectionResult &, void *);
extern "C" bool func_002BDF00(const CGtPolygonIntersectionResult &, void *);
extern "C" void BeginRendering__6B3Im3dFv();
extern "C" void SetTexture__6B3Im3dFP10CGtTexture(CGtTexture *);
extern "C" void RenderTrilist__6B3Im3dFPC13CB3Im3dVertexi(const CB3Im3dVertex *, int);
extern "C" void EndRendering__6B3Im3dFv();
class CB3PhysicsManagerDebug {
public:
    void DrawCollisionWorld();
    unsigned char pad_0[0xA];
    unsigned char field_A;
    unsigned char pad_B[0x9];
    void *field_14;
};
// [G] inline helper (unnamed: a CGtSphere position+radius setter); keeps the SetPosition by-value slot below the TestPosition
// argument copy (N186: inline locals sit below caller temporaries).
static inline void func_002BDDF0_inl1(CGtSphere &s, const CGtV3d &p, float r) { s.SetPosition(p); s.SetRadius(r); }
// 0x002BDDF0
void CB3PhysicsManagerDebug::DrawCollisionWorld()
{
    CGtSphere s;
    func_002BDDF0_inl1(s, D_0064D3E0, 1000.0f);
    _gnNumColWorldPoints = 0;
    int unit = TestPosition__16CB3StreamedTrackFQ29GtMathPs26CGtV3d(D_0064C9A8, s.Position());
    if (field_A == 0) {
        func_00301B00(D_0064C9A8, unit, s, func_002BE260, field_14);
    } else {
        _gRandomColour.field_4 = 0x2B9D6F8;
        _gRandomColour.field_0 = 0xFD462907;
        _gpPolySoupVertices = 0;
        func_00301B00(D_0064C9A8, unit, s, func_002BDF00, 0);
    }
    if (_gnNumColWorldPoints > 0) {
        BeginRendering__6B3Im3dFv();
        SetTexture__6B3Im3dFP10CGtTexture(0);
        RenderTrilist__6B3Im3dFPC13CB3Im3dVertexi(D_01E85A50, _gnNumColWorldPoints);
        EndRendering__6B3Im3dFv();
        _gnNumColWorldPoints = 0;
    }
}
