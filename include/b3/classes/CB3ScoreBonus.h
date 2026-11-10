// CB3ScoreBonus -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3SCOREBONUS_H
#define B3_CLASSES_CB3SCOREBONUS_H

#include "b3/GtMath.h"

#include "b3/classes/EB3ScoreMedalType.h"
#include "b3/classes/EScoreBonusEvent.h"

class CB3RaceCar;
class CB3ScoreBonus;
struct CB3ScoreCategory;

class CB3ScoreBonus {
public:
    void ClearAttackData();
    void Construct();
    int GetDuellingCar();
    int OnAward(EScoreBonusEvent p0, int p1, const CB3ScoreCategory* p2);
    void OnCrashReset();
    void OnCrashStart();
    void OnDenied(CB3RaceCar* p0);
    int OnEvent(EScoreBonusEvent, int, int, bool);
    void OnMedal(EB3ScoreMedalType p0, int p1);
    void OnYouWereLucky(CB3RaceCar* p0);
    void Release();
    void SetGamebreakerEvent(EScoreBonusEvent p0);

    unsigned char pad_0[0x10];
    unsigned char field_10;
    unsigned char field_11;
    unsigned char pad_12[0xC2];
    int field_D4;
    unsigned char pad_D8[0xC];
    int field_E4;
    unsigned char pad_E8[0x48];
    int field_130;
    int field_134;
    int field_138;
    int field_13C;
    unsigned char pad_140[0x8];
    int field_148;
    EScoreBonusEvent field_14C;
};

#endif
