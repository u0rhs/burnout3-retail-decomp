// CB3DebugManager -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3DEBUGMANAGER_H
#define B3_CLASSES_CB3DEBUGMANAGER_H

class CB3DebugManager;

class CB3DebugManager {
public:
    static unsigned char gmbRequestPlayAll;
    static unsigned char gmbRequestPlayCameras;
    static unsigned char gmbRequestStepAll;
    static unsigned char gmbRequestStepCameras;
    static unsigned char gmbRequestStopAll;
    static unsigned char gmbRequestStopUpdate;

    unsigned char pad_0[0x1];
};

#endif
