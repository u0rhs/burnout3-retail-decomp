// UnkStruct_farFogPlane -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_UNKSTRUCT_FARFOGPLANE_H
#define B3_CLASSES_UNKSTRUCT_FARFOGPLANE_H

typedef unsigned int u_long128 __attribute__((mode(TI)));

struct UnkStruct_00263350_1;
struct UnkStruct_farFogPlane;

struct UnkStruct_00263350_1 {
    u_long128 field_0;
    u_long128 field_10;
    u_long128 field_20;
    u_long128 field_30;
    u_long128 field_40;
};

struct UnkStruct_farFogPlane {
    UnkStruct_00263350_1 * field_0;
};

#endif
