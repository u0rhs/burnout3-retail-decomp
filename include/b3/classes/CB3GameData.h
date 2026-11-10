// CB3GameData -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3GAMEDATA_H
#define B3_CLASSES_CB3GAMEDATA_H

#include "b3/GtMath.h"

class CB3GameData;
struct UnkStruct_0014E8A0_1;
struct UnkStruct_0014ECB0_e0;

struct UnkStruct_0014E8A0_1 {
    unsigned char pad_0[0x3EC];
    int field_3EC;
};

struct UnkStruct_0014ECB0_e0 {
    unsigned char pad_0[0x4];
};

class CB3GameData {
public:
    void Construct();
    void Destruct();
    int GetNumStartLines();
    void Release();
    void SetGameDataFileName(char* p0);
    void SetStageID(unsigned long p0);

    UnkStruct_0014ECB0_e0 field_0[1];  // [G] element count unknown
    unsigned char pad_4[0x554];
    unsigned long field_558;
    int field_560;
    unsigned char pad_564[0x8];
    UnkStruct_0014E8A0_1 * field_56C;
    unsigned char pad_570[0xC];
    int field_57C;
    int field_580;
    int field_584;
    unsigned char field_588;
    unsigned char field_589;
    unsigned char field_58A;
    unsigned char field_58B;
};

#endif
