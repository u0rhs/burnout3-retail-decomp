// CB3NetworkManager -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3NETWORKMANAGER_H
#define B3_CLASSES_CB3NETWORKMANAGER_H

class CB3NetworkManager;

class CB3NetworkManager {
public:
    int GetDirtySockErrorString(int e);
    int GetErrorString(int e);

    unsigned char pad_0[0x1];
};

#endif
