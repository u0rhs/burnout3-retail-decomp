// CGtSphereTree -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CGTSPHERETREE_H
#define B3_CLASSES_CGTSPHERETREE_H

class CGtSphereTree;
struct CGtSphereTreeSphere;
struct UnkStruct_0035D1C0_4;

struct UnkStruct_0035D1C0_4 {
    unsigned char pad_0[0x4];
    void * field_4;
};

class CGtSphereTree {
public:
    void FreeParentSphere(CGtSphereTreeSphere* p0);
    void SetMaxParentSize(int p0, float p1);

    unsigned char pad_0[0x18];
    UnkStruct_0035D1C0_4 * field_18;
    unsigned char pad_1C[0x8];
    float field_24[1];  // [G] element count unknown
    unsigned char pad_28[0x14];
    int field_3C;
};

#endif
