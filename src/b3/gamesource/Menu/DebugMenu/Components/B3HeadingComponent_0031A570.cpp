#include "b3/GtMathPs2.h"

// GtMathPs2::CGtMatrix2x3's copy constructor and operator= (API names: B3O0PCH map). Retail has them as
// out-of-line functions here, right after CB3RotatingImage2dObject::_Render, its only caller
// (0x31A570/0x31A590; the E-build DNAT map lists both in B3HeadingComponent.cpp, 32/56 bytes as here).
// Defined as ordinary member functions in this file; in the original they are probably header inlines
// that MWCC emitted out of line because their definitions came after that use [G].

namespace GtMathPs2 {

// 0x0031A570. Three 64-bit moves (ld/sd), not the float-wise copy an implicit CGtV2d assignment
// compiles to here; written with 64-bit (`unsigned long`) accesses to get them [G].
CGtMatrix2x3 &CGtMatrix2x3::operator=(const CGtMatrix2x3 &o)
{
    *(unsigned long *)&mRight = *(const unsigned long *)&o.mRight;
    *(unsigned long *)&mDown = *(const unsigned long *)&o.mDown;
    *(unsigned long *)&mPos = *(const unsigned long *)&o.mPos;
    return *this;
}

// 0x0031A590. Six float copies.
CGtMatrix2x3::CGtMatrix2x3(const CGtMatrix2x3 &o)
{
    mRight.marValues[0] = o.mRight.marValues[0];
    mRight.marValues[1] = o.mRight.marValues[1];
    mDown.marValues[0] = o.mDown.marValues[0];
    mDown.marValues[1] = o.mDown.marValues[1];
    mPos.marValues[0] = o.mPos.marValues[0];
    mPos.marValues[1] = o.mPos.marValues[1];
}

}  // namespace GtMathPs2
