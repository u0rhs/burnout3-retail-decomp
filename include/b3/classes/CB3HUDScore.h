// CB3HUDScore -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3HUDSCORE_H
#define B3_CLASSES_CB3HUDSCORE_H

class CB3HUDScore;

class CB3HUDScore {
public:
    void Update(float p0);
    void UpdateScoreObject(float);
    void UpdateSmallMessage(float);

    unsigned char pad_0[0x1];
};

#endif
