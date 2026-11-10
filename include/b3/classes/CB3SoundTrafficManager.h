// CB3SoundTrafficManager -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3SOUNDTRAFFICMANAGER_H
#define B3_CLASSES_CB3SOUNDTRAFFICMANAGER_H

class CB3SoundTrafficManager;

class CB3SoundTrafficManager {
public:
    bool CanStartHorning();

    unsigned char pad_0[0xD4];
    int field_D4;
};

#endif
