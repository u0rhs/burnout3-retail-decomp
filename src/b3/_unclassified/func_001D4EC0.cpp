// Hand-written; the lifter refused it (CGtV4d::operator*(CGtV4d) out-of-line copy via header inline (N155/N160)).

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
// 0x001D4EC0
extern "C" void __ml__Q29GtMathPs26CGtV4dCFQ29GtMathPs26CGtV4d(CGtV4d * r, const CGtV4d * a, const CGtV4d * b)
{
    *r = a->operator*(*b);
}
