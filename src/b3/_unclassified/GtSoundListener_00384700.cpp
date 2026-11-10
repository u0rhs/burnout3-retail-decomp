// CGtSoundListener::SetAt(GtMathPs2::CGtV3d) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtSoundListener.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (twin of SetUp).

#include "b3/GtMathPs2.h"
struct F3 { float x, y, z; };
struct UnkStruct_Lis {
    unsigned char pad_0[0x60];
    F3 up;
    F3 at;
    F3 right;
    unsigned int flags;
};
class CGtSoundListener {
public:
    void SetAt(GtMathPs2::CGtV3d p0);
    unsigned char pad_0[0x8];
    UnkStruct_Lis *field_8;
};
struct UnkStruct_00384700_pad {
    unsigned char field_0[0x10];
    UnkStruct_00384700_pad() {}
    ~UnkStruct_00384700_pad() {}
};
// 0x00384700
void CGtSoundListener::SetAt(GtMathPs2::CGtV3d p0)
{
    UnkStruct_00384700_pad pad;
    GtMathPs2::CGtV3d c = p0;
    F3 b;
    F3 a = *(F3 *)&c;
    field_8->at = a;
    b = a;
    UnkStruct_Lis *s = field_8;
    s->right.x = s->up.y * s->at.z - s->up.z * s->at.y;
    s = field_8;
    s->right.y = s->up.z * s->at.x - s->up.x * s->at.z;
    s = field_8;
    s->right.z = s->up.x * s->at.y - s->up.y * s->at.x;
    field_8->flags |= 4;
}
