// B3ConvexHull.cpp -- translation unit regrouped by tools/tu_merge.py from 5 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 5 function(s) named in research/retail_names.csv -> B3ConvexHull.cpp.
// Area: src/b3/SharedClasses/PhysicsData, [L] Revenge (SLUS_212.42) SharedClasses/PhysicsData/B4ConvexHull.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3ConvexHull.h"
#include "b3/classes/CB3ConvexHullBodyPart.h"
#include "b3/classes/CB3ConvexHullProp.h"
#include "b3/classes/CB3ConvexHullVehicle.h"

struct UnkStruct_002BAEE0 {
    unsigned char pad_0[0x18];
    unsigned char field_18;
    unsigned char field_19;
    unsigned char field_1A;
};

// CB3ConvexHullBodyPart::Initialise() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3ConvexHull.cpp.
// 0x002B9640
void CB3ConvexHullBodyPart::Initialise()
{
    field_4 = ((char *)this + 0x40);
    field_0 = ((char *)this + 0x1C);
    field_8 = ((char *)this + 0x100);
    field_C = ((char *)this + 0x180);
    field_10 = ((char *)this + 0x1A4);
}

// CB3ConvexHullProp::Initialise() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3ConvexHull.cpp.
// 0x002B9670
void CB3ConvexHullProp::Initialise()
{
    field_4 = ((char *)this + 0x40);
    field_0 = ((char *)this + 0x1C);
    field_8 = ((char *)this + 0x100);
    field_C = ((char *)this + 0x180);
    field_10 = ((char *)this + 0x1A4);
}

// CB3ConvexHullVehicle::Initialise() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3ConvexHull.cpp.
// 0x002B96A0
void CB3ConvexHullVehicle::Initialise()
{
    field_4 = ((char *)this + 0xA0);
    field_0 = ((char *)this + 0x1C);
    field_8 = ((char *)this + 0x320);
    field_C = ((char *)this + 0x480);
    field_10 = ((char *)this + 0x4F8);
}

// func_002BAEE0 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x002BAEE0
extern "C" void func_002BAEE0(UnkStruct_002BAEE0 *self)
{
    self->field_18 = 0;
    self->field_19 = 0;
    self->field_1A = 0;
}

// CB3ConvexHull::Fixup() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3ConvexHull.cpp.
// 0x002BAEF0
void CB3ConvexHull::Fixup()
{
    field_0 = (int)(field_0 + (int)this);
    field_4 = (int)(field_4 + (int)this);
    field_8 = (int)(field_8 + (int)this);
    field_C = (int)(field_C + (int)this);
    field_10 = (int)(field_10 + (int)this);
}
