// CB3FlashText2dObject -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3FLASHTEXT2DOBJECT_H
#define B3_CLASSES_CB3FLASHTEXT2DOBJECT_H

class CB3FlashText2dObject;

class CB3FlashText2dObject {
public:
    void SetHFlashTimeScale(float p0);

    unsigned char pad_0[0x2C];
    float field_2C;
};

#endif
