// CB3TrafficPhysics -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3TRAFFICPHYSICS_H
#define B3_CLASSES_CB3TRAFFICPHYSICS_H

#include "b3/GtMath.h"

class CB3TrafficPhysics;

class CB3TrafficPhysics {
public:
    void Construct();
    void Destruct();
    void Release();
    void StopCrashing();

    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    unsigned char pad_4[0x20C];
    unsigned char field_210;
    unsigned char pad_211[0x4];
    unsigned char field_215;
};

#endif
