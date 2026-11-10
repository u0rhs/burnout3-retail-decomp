// CGtInputManagerPS2Pad2 -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CGTINPUTMANAGERPS2PAD2_H
#define B3_CLASSES_CGTINPUTMANAGERPS2PAD2_H

#include "b3/GtMath.h"

class CGtInputManagerPS2Pad2;
struct UnkStruct_00214940_2;

struct UnkStruct_00214940_2 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10(unsigned char);
};

class CGtInputManagerPS2Pad2 {
public:
    void Prepare();
    void SetPause(bool p0);

    unsigned char pad_0[0x200];
    UnkStruct_00214940_2 * field_200[1];  // [G] element count unknown
    unsigned char pad_204[0x8];
    unsigned char field_20C;
    unsigned char pad_20D[0x57];
    int field_264;
};

#endif
