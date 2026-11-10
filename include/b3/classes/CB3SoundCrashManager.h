// CB3SoundCrashManager -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3SOUNDCRASHMANAGER_H
#define B3_CLASSES_CB3SOUNDCRASHMANAGER_H

class CB3SoundCrashManager;

class CB3SoundCrashManager {
public:
    void FadeOutCrashStream();
    void SetPlayerCarSpeed(float p0);

    unsigned char pad_0[0x8A8];
    float field_8A8;
    unsigned char pad_8AC[0x31];
    unsigned char field_8DD;
};

#endif
