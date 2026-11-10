// CB3ReplayFrame -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3REPLAYFRAME_H
#define B3_CLASSES_CB3REPLAYFRAME_H

class CB3ReplayFrame;
struct CDrivingControls;

class CB3ReplayFrame {
public:
    int RetrieveDrivingControls(CDrivingControls* p0);

    signed char field_0;
    unsigned char field_1;
    unsigned char field_2;
};

#endif
