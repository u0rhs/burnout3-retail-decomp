// Gt2dRenderer -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_GT2DRENDERER_H
#define B3_CLASSES_GT2DRENDERER_H

class Gt2dRenderer;

class Gt2dRenderer {
public:
    static bool _gbIsZTestEnabled;
    static int _gnNearZ;
    static int _gnUserDefinedZ;
    static int _gnZ;
    static void EnableZTest(bool p0);

    unsigned char pad_0[0x1];
};

#endif
