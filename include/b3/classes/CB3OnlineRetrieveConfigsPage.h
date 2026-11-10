// CB3OnlineRetrieveConfigsPage -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3ONLINERETRIEVECONFIGSPAGE_H
#define B3_CLASSES_CB3ONLINERETRIEVECONFIGSPAGE_H

#include "b3/GtMath.h"

class CB3OnlineRetrieveConfigsPage;

class CB3OnlineRetrieveConfigsPage {
public:
    int Prepare();

    unsigned char pad_0[0x4];
    unsigned char field_4;
};

#endif
