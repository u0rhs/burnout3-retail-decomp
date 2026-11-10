// CB3VehicleList -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3VEHICLELIST_H
#define B3_CLASSES_CB3VEHICLELIST_H

#include "b3/GtMath.h"

#include "b3/classes/EB3MenuCarClasses.h"

class CB3VehicleList;

class CB3VehicleList {
public:
    void CreateVehiclePathFromIndex(int p0, char* p1, int p2);
    int DoesVehicleExist(unsigned long);
    unsigned long GetCarID(EB3MenuCarClasses p0, int p1);
    int GetVehicleBoostBarSize(unsigned long p0);
    int GetVehicleIndexFromID(unsigned long p0);
    bool IsVehicleDriveable(unsigned long p0);
    static int GetClassFromID(unsigned long);

    unsigned char pad_0[0x4];
    int field_4;
    int field_8[1];  // [G] element count unknown
    unsigned char pad_C[0x1FC];
    int field_208[1];  // [G] element count unknown
    unsigned char pad_20C[0x1FC];
    unsigned long field_408[1];  // [G] element count unknown
};

#endif
