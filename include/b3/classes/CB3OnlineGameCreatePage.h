// CB3OnlineGameCreatePage -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3ONLINEGAMECREATEPAGE_H
#define B3_CLASSES_CB3ONLINEGAMECREATEPAGE_H

class CB3OnlineGameCreatePage;

class CB3OnlineGameCreatePage {
public:
    void Release();

    unsigned char pad_0[0x1];
};

#endif
