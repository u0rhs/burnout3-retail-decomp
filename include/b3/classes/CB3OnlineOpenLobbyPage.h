// CB3OnlineOpenLobbyPage -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3ONLINEOPENLOBBYPAGE_H
#define B3_CLASSES_CB3ONLINEOPENLOBBYPAGE_H

class CB3OnlineOpenLobbyPage;

class CB3OnlineOpenLobbyPage {
public:
    static bool GetSelectedLobbyPlayerCallback(char* p0, int p1, bool p2, int p3, int p4, int p5, char* p6, bool p7, void* p8);

    unsigned char pad_0[0x1];
};

#endif
