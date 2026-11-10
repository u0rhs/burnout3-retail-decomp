// CB3MyBurnoutRewardsHeadlinesPage -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3MYBURNOUTREWARDSHEADLINESPAGE_H
#define B3_CLASSES_CB3MYBURNOUTREWARDSHEADLINESPAGE_H

#include "b3/classes/EB3RewardImageType.h"

class CB3MyBurnoutRewardsHeadlinesPage;

class CB3MyBurnoutRewardsHeadlinesPage {
public:
    int Prepare(EB3RewardImageType p0);

    unsigned char pad_0[0x4];
    int field_4;
};

#endif
