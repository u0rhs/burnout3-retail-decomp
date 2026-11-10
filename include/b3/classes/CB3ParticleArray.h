// CB3ParticleArray -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3PARTICLEARRAY_H
#define B3_CLASSES_CB3PARTICLEARRAY_H

class CB3ParticleArray;

class CB3ParticleArray {
public:
    void BeginUpdate(float p0);
    void Destruct();
    void Release();

    unsigned char pad_0[0x7C];
    float field_7C;
};

#endif
