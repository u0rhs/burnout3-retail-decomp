#include "b3/gamesource/Race/B3StreamedTrack.h"

extern int D_004E2D48;   // unnamed global, no evidence of its real name yet

// 0x003030E0 (Target #19)
void CB3StreamedTrack::Destruct()
{
    field_10 = 0x19;
}

// Field writes are in retail's own instruction order, not ascending offset order -- CodeWarrior
// does not reorder independent stores for a plain leaf function like this one (same lesson as
// N38, minus the asm-barrier complication: here it's just straight preservation of source order).
void CB3StreamedTrack::Construct()
{
    int invalid = -1;
    int one = 1;
    field_18 = 0;
    field_44 = 0;
    field_45 = 0;
    field_46 = 0;
    field_47 = 0;
    field_19 = 0;
    field_38 = 0;
    field_3C = 0;
    field_40 = 0;
    field_1C = invalid;
    field_14 = 0;
    field_34 = invalid;
    field_30 = invalid;
    field_54 = invalid;
    field_50 = invalid;
    field_4 = invalid;
    field_0 = invalid;
    field_24 = invalid;
    field_20 = invalid;
    field_4C = invalid;
    field_48 = invalid;
    field_C = invalid;
    field_8 = invalid;
    field_2C = invalid;
    field_28 = invalid;
    D_004E2D48 = invalid;
    field_10 = one;
}
