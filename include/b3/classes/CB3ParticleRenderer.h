// CB3ParticleRenderer -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3PARTICLERENDERER_H
#define B3_CLASSES_CB3PARTICLERENDERER_H

class CB3ParticleRenderer;

class CB3ParticleRenderer {
public:
    static int mnDMANumQW;
    static int mnNumRenderableArrays;
    static unsigned char mbIsCrash;
    void BeginRender(bool p0);
    void Construct();
    void Destruct();

    unsigned char pad_0[0x1];
};

#endif
