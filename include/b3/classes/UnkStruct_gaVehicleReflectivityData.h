// UnkStruct_gaVehicleReflectivityData -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_UNKSTRUCT_GAVEHICLEREFLECTIVITYDATA_H
#define B3_CLASSES_UNKSTRUCT_GAVEHICLEREFLECTIVITYDATA_H

#include "b3/GtMath.h"

struct UnkStruct_00151C40_e0;
struct UnkStruct_gaVehicleReflectivityData;

struct UnkStruct_00151C40_e0 {
    unsigned long field_0;
    unsigned char pad_8[0xE8];
};

struct UnkStruct_gaVehicleReflectivityData {
    UnkStruct_00151C40_e0 field_0[1];  // [G] element count unknown
};

#endif
