// CB3CrashAnalyser -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3CRASHANALYSER_H
#define B3_CLASSES_CB3CRASHANALYSER_H

class CB3CrashAnalyser;
struct UnkStruct_00354260_e0;
struct UnkStruct_00354260_e1;

struct UnkStruct_00354260_e0 {
    unsigned char pad_0[0x4];
    int field_4;
    unsigned char pad_8[0x38];
};

struct UnkStruct_00354260_e1 {
    unsigned char pad_0[0x40];
};

class CB3CrashAnalyser {
public:
    void Destruct();
    void * GetMostInterestingCluster();
    void RenderDebug();

    UnkStruct_00354260_e1 field_0[1];  // [G] element count unknown
    unsigned char pad_40[0x40];
    UnkStruct_00354260_e0 field_80[1];  // [G] element count unknown
    unsigned char pad_C0[0xF89];
    unsigned char field_1049;
};

#endif
