// UnkStruct_D_01E8E5D8 -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_UNKSTRUCT_D_01E8E5D8_H
#define B3_CLASSES_UNKSTRUCT_D_01E8E5D8_H

#include "b3/GtMath.h"

struct UnkStruct_D_01E8E5D8;

struct UnkStruct_D_01E8E5D8 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

#endif
