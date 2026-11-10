// CB3SFIOCallbacks -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3SFIOCALLBACKS_H
#define B3_CLASSES_CB3SFIOCALLBACKS_H

class CB3SFIOCallbacks;
class SLoginProcessE;

class CB3SFIOCallbacks {
public:
    static int gmeError;
    static int gmeLastOperation;
    static int gmeProcess;
    static int gmnFreeSpace;
    static int gmnOffset;
    static unsigned char gmbOpenedFile;
    void * GetSharedNetworkLoginName();
    void * GetSharedNetworkLoginPassword();
    void SFIOReadCallback(int p0, void* p1, unsigned int p2);
    int SharedNetworkLoginUpdate(SLoginProcessE* p0);

    unsigned char pad_0[0x1];
};

#endif
