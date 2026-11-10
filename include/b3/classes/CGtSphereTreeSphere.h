// CGtSphereTreeSphere -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CGTSPHERETREESPHERE_H
#define B3_CLASSES_CGTSPHERETREESPHERE_H

struct CGtSphereTreeSphere;
struct UnkStruct_0035D1C0_1;
struct UnkStruct_0035D1C0_2;

struct UnkStruct_0035D1C0_1 {
    void * field_0;
};

struct UnkStruct_0035D1C0_2 {
    unsigned char pad_0[0x4];
    void * field_4;
};

struct CGtSphereTreeSphere {
    unsigned char pad_0[0x14];
    void * field_14;
    void * field_18;
    UnkStruct_0035D1C0_2 * field_1C;
    UnkStruct_0035D1C0_1 * field_20;
};

#endif
