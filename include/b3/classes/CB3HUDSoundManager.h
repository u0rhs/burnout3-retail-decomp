// CB3HUDSoundManager -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3HUDSOUNDMANAGER_H
#define B3_CLASSES_CB3HUDSOUNDMANAGER_H

#include "b3/GtMath.h"
#include "b3/GtMathPs2.h"

class CB3HUDSoundManager;
class CB3RaceCarPhysics;

class CB3HUDSoundManager {
public:
    void FEBack();
    void FEOnlineUpdatePlayersInGame(int p0);
    void FESelect();
    void FEVerticalMove();
    void GeneralPopup();
    void Shunt(GtMathPs2::CGtV3d, CB3RaceCarPhysics*, CB3RaceCarPhysics*);

    unsigned char field_0;
    unsigned char pad_1[0xF];
    unsigned char field_10;
    unsigned char field_11;
    unsigned char field_12;
    unsigned char pad_13[0xD];
    float field_20;
    unsigned char pad_24[0x4C];
    int field_70;
    unsigned char pad_74[0x4];
    int field_78;
    int field_7C;
};

#endif
