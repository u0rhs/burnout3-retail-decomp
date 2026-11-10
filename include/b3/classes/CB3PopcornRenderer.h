// CB3PopcornRenderer -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3POPCORNRENDERER_H
#define B3_CLASSES_CB3POPCORNRENDERER_H

class CB3PopcornRenderer;

class CB3PopcornRenderer {
public:
    static int mnNumRenderableArrays;
    void BeginRender();
    void EndRender();

    unsigned char pad_0[0x1];
};

#endif
