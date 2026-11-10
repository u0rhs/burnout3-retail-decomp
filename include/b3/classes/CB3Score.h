// CB3Score -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3SCORE_H
#define B3_CLASSES_CB3SCORE_H

#include "b3/GtMath.h"

class CB3RaceCar;
class CB3Score;

class CB3Score {
public:
    static float gmrTakedownBurnValue;
    static int gmnBurningSlamExtraBP;
    static int gmnDeniedBP;
    static int gmnTradingPaintBP;
    static int gmnYouWereLuckyBP;
    void Construct();
    void OnTakeDown(CB3RaceCar*);
    void Release();

    unsigned char pad_0[0x1];
};

#endif
