// CB3CrashCombo -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3CRASHCOMBO_H
#define B3_CLASSES_CB3CRASHCOMBO_H

#include "b3/GtMath.h"

class CB3CrashCombo;
class CB3RaceCar;

class CB3CrashCombo {
public:
    void Construct();
    void OnCrashFinishing();
    void OnCrashStop();
    void Prepare(CB3RaceCar*);
    void Release();
    void ResetData();

    unsigned char pad_0[0x119];
    unsigned char field_119;
    unsigned char field_11A;
    unsigned char pad_11B[0x109];
    CB3RaceCar * field_224;
    int field_228;
};

#endif
