// GtSphereTree.cpp -- translation unit regrouped by tools/tu_merge.py from 4 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 3 function(s) named in research/retail_names.csv -> GtSphereTree.cpp, 1 placed between two of them by address contiguity (N2).
// Area: src/b3/GameShared/GameClasses/Containers, [L] Revenge (SLUS_212.42) GameShared/GameClasses/Containers/GtSphereTree.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CGtIntersectionResult.h"
#include "b3/classes/CGtSphereTree.h"
#include "b3/classes/CGtSphereTreeSphere.h"

struct UnkStruct_0035EDB0;
struct UnkStruct_0035EDB0_2;
struct UnkStruct_0035EDB0_e0;

struct UnkStruct_0035EDB0_e0 {
    unsigned char pad_0[0x10];
    int field_10;
    void * field_14;
    void * field_18;
    unsigned char pad_1C[0x8];
    int field_24;
    void * field_28;
    void * field_2C;
    unsigned char pad_30[0x10];
};

struct UnkStruct_0035EDB0_2 {
    unsigned char pad_0[0x4];
    void * field_4;
};

struct UnkStruct_0035EDB0 {
    void * field_0;
    void * field_4;
    void * field_8;
    void * field_C;
    void * field_10;
    void * field_14;
    UnkStruct_0035EDB0_2 * field_18;
    void * field_1C;
    unsigned char pad_20[0x18];
    int field_38;
    int field_3C;
    UnkStruct_0035EDB0_e0 * field_40;
};

// CGtIntersectionResult::CGtIntersectionResult() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtSphereTree.cpp.
// 0x0035C3D0
CGtIntersectionResult::CGtIntersectionResult()
{
}

// CGtSphereTree::FreeParentSphere(CGtSphereTreeSphere*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtSphereTree.cpp.
// 0x0035D1C0
void CGtSphereTree::FreeParentSphere(CGtSphereTreeSphere* p0)
{
    UnkStruct_0035D1C0_2 * t0 = p0->field_1C;
    if (t0 != 0) {
        p0->field_20->field_0 = (void *)t0;
        p0->field_1C->field_4 = (void *)p0->field_20;
    }
    p0->field_14 = (void *)field_18;
    p0->field_18 = ((char *)this + 0x18);
    field_18->field_4 = ((char *)p0 + 0x14);
    field_18 = (UnkStruct_0035D1C0_4 *)((char *)p0 + 0x14);
    field_3C = (field_3C + 1);
}

// CGtSphereTree::SetMaxParentSize(int,float) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtSphereTree.cpp.
// 0x0035EDA0
void CGtSphereTree::SetMaxParentSize(int p0, float p1)
{
    field_24[p0] = p1;
}

// func_0035EDB0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x0035EDB0
extern "C" int func_0035EDB0(UnkStruct_0035EDB0 * self)
{
    self->field_8 = ((char *)self + 0x8);
    self->field_C = ((char *)self + 0x8);
    self->field_10 = ((char *)self + 0x10);
    self->field_14 = ((char *)self + 0x10);
    self->field_0 = (void *)self;
    self->field_4 = (void *)self;
    self->field_18 = (UnkStruct_0035EDB0_2 *)((char *)self + 0x18);
    self->field_1C = ((char *)self + 0x18);
    self->field_3C = self->field_38;
    for (int i = 0; (i < self->field_38); i++) {
        UnkStruct_0035EDB0_e0 * t0 = self->field_40;
        t0[i].field_24 = 0;
        t0[i].field_10 = 0;
        t0[i].field_28 = ((char *)&t0[i] + 0x28);
        t0[i].field_2C = ((char *)&t0[i] + 0x28);
        t0[i].field_14 = (void *)self->field_18;
        t0[i].field_18 = ((char *)self + 0x18);
        self->field_18->field_4 = ((char *)&t0[i] + 0x14);
        self->field_18 = (UnkStruct_0035EDB0_2 *)((char *)&t0[i] + 0x14);
    }
    return 1;
}
