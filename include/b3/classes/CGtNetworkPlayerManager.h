// CGtNetworkPlayerManager -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CGTNETWORKPLAYERMANAGER_H
#define B3_CLASSES_CGTNETWORKPLAYERMANAGER_H

#include "b3/GtMath.h"

class CGtNetworkPlayerManager;

class CGtNetworkPlayerManager {
public:
    int GetHostPlayerID();
    int GetMyPlayerID() const;
    int GetMyPlayerIndex() const;
    int GetPlayerByID(int) const;
    void SetMyPlayerID(int p0);
    void SetMyPlayerIndex(int p0);

    unsigned char pad_0[0x8];
    int field_8[1];  // [G] element count unknown
    unsigned char pad_C[0x1C];
    int field_28;
    unsigned char pad_2C[0x4C];
    int field_78;
    unsigned char pad_7C[0x4];
    int field_80;
};

#endif
