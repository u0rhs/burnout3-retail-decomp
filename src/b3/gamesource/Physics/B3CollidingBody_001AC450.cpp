// CB3CollidingBody.cpp (E map). Split out from the combined game/unit_001ABE70 splat chunk
// 2026-10-20 (N41): Destruct/Release sit between CB3CollidingBody's other not-yet-decompiled
// methods (CacheWorldTriangles/func_001ABFC0/SetRealisticMomentsOfInertia before, Update/
// func_001AD380 after), so they needed their own isolated yaml subsegment to decompile.
#include "b3/gamesource/Physics/B3CollidingBody.h"

// 0x001AC450 (empty body)
void CB3CollidingBody::Destruct()
{
}

// 0x001AC460 (empty body)
void CB3CollidingBody::Release()
{
}
