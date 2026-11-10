// CB3SoundStaticPassManager -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3SOUNDSTATICPASSMANAGER_H
#define B3_CLASSES_CB3SOUNDSTATICPASSMANAGER_H

class CB3SoundStaticPassManager;

class CB3SoundStaticPassManager {
public:
    int Prepare();
    void Release();

    int field_0;
    int field_4;
};

#endif
