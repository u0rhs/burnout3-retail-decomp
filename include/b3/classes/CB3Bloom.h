// CB3Bloom -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3BLOOM_H
#define B3_CLASSES_CB3BLOOM_H

class CB3Bloom;

class CB3Bloom {
public:
    void Construct();
    int Prepare();

    float field_0;
    float field_4;
    float field_8;
};

#endif
