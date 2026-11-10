// CGtHiResSystemTimer -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CGTHIRESSYSTEMTIMER_H
#define B3_CLASSES_CGTHIRESSYSTEMTIMER_H

class CGtHiResSystemTimer;

class CGtHiResSystemTimer {
public:
    static int gmnLastVsyncCount;
    static int gmnTimeMSP;
    static int gmuTimeLSP;
    static unsigned char gmbVsyncAt60Hz;

    unsigned char pad_0[0x1];
};

#endif
