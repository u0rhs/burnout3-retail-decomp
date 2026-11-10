// CB3HardCodedRaceStageList -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3HARDCODEDRACESTAGELIST_H
#define B3_CLASSES_CB3HARDCODEDRACESTAGELIST_H

class CB3HardCodedRaceStageList;

class CB3HardCodedRaceStageList {
public:
    static unsigned long GetStageTrackID(unsigned long p0);  // w64: static, 64-bit result (GtIDCompress__FPCc)
    static unsigned char DoesChallengeUnlockTracks(int p0);

    unsigned char pad_0[0x1];
};

#endif
