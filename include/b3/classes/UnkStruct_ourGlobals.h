// UnkStruct_ourGlobals -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_UNKSTRUCT_OURGLOBALS_H
#define B3_CLASSES_UNKSTRUCT_OURGLOBALS_H

struct UnkStruct_ourGlobals;

struct UnkStruct_ourGlobals {
    unsigned char pad_0[0x138];
    int field_138;
};

#endif
