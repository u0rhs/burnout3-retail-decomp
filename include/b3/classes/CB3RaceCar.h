// CB3RaceCar -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3RACECAR_H
#define B3_CLASSES_CB3RACECAR_H

#include "b3/GtMath.h"

#include "b3/classes/CB3Score.h"
#include "b3/classes/EB3ScoreFinishState.h"

class CB3CrashStartInfo;
class CB3RaceCar;
struct UnkStruct_00151C40_4;

struct UnkStruct_00151C40_4 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
};

class CB3RaceCar {
public:
    void Construct();
    int PrepareSound();
    void Release();
    void SetActive(bool p0);
    void SetFinished(EB3ScoreFinishState);
    void StartCrashing(CB3CrashStartInfo* p0);
    void StopCrashing();
    void Update();

    unsigned char pad_0[0x40];
    int field_40;
    int field_44;
    float field_48;
    int field_4C;
    float field_50;
    unsigned char pad_54[0x106C];
    CB3Score field_10C0;
    unsigned char pad_10C1[0x9F];
    unsigned char field_1160;
    unsigned char pad_1161[0x5B];
    int field_11BC;
    unsigned char pad_11C0[0x1C];
    unsigned char field_11DC;
    unsigned char pad_11DD[0x4EB];
    int field_16C8;
    unsigned char pad_16CC[0x1C4];
    int field_1890;
    unsigned char pad_1894[0x56];
    unsigned char field_18EA;
    unsigned char field_18EB;
    unsigned char pad_18EC[0x24];
    // vptr at +0x1910: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18();
    virtual void vfunc_1C();
    virtual void vfunc_20();
    virtual void vfunc_24();
    virtual void vfunc_28(unsigned char, int);
    unsigned char pad_1914[0x4];
    UnkStruct_00151C40_4 * field_1918;
    unsigned char pad_191C[0x44];
    unsigned long field_1960;
    int field_1968;
    int field_196C;
    int field_1970;
    unsigned char pad_1974[0x20];
    int field_1994;
    unsigned char field_1998;
    unsigned char pad_1999[0x1];
    unsigned char field_199A;
    unsigned char field_199B;
    unsigned char pad_199C[0x10];
    signed char field_19AC;
};

#endif
