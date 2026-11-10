// NONMATCHING: EndRender__17CB3CoronaRendererFv -- retail 188 / ours 188 instructions, 11 in changed runs
// son4: zero hi as a local 'unsigned long z0 = 0;' before p[6] (15 -> 11); left: register rotation of hoisted q6/q0/q1 (retail t0,a3,a2)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)


// L271: logic exact 188/188, 19 off = register allocation/scheduling of the three hoisted constant quads (0x10000005/0x5000000500000000, 0x1000000000008004/0xE, 0x10000000 x2) before the second loop (retail p0=a3,p7=a1,p1=a2, counter a0). Fixed: extern C link-name (no this; f12 unset for UploadCodeAndStaticData), 2048.5f lit4 + 16*l madd, frame order (arrays then coll), shared int i for both loops (t4/t5), sz=11; sz+=4; sz+=n*8; sz+=4 keeps the unfolded constants. Tried helper arg order, hoisted quad locals, opt_propagation off.

// CB3CoronaRenderer::EndRender() -- hand-written (L271) from the asm; the lifter refused it.
// [C] name: the mangled symbol in retail's tables; file: research/retail_names.csv -> B3CoronaRendererPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Every type is [G] (instruction widths).
// Written as an extern "C" definition of the mangled symbol [G]: retail never keeps `this` (a0 is
// clobbered before the static-style SetRenderstates / UploadCodeAndStaticData calls, f12 is never set).

typedef unsigned int u_long128 __attribute__((mode(TI)));

struct UnkStruct_003070B0_34 {
    unsigned char pad_0[0x18];
    unsigned int field_18;
    unsigned int field_1C;
    unsigned int field_20;
    unsigned int field_24;
};

struct UnkStruct_003070B0_tex {
    unsigned char pad_0[0xC];
    int field_C;
    unsigned char pad_10[0x24];
    UnkStruct_003070B0_34 field_34;
};

struct UnkStruct_003070B0_coll {
    int field_0[12];
};

struct UnkStruct_farFogPlane {
    u_long128 * field_0;
};

extern UnkStruct_farFogPlane farFogPlane;
extern "C" int mnNumPackets__17CB3CoronaRenderer;
extern unsigned int D_01E88900[];
extern UnkStruct_003070B0_tex * D_01E88920[];

extern "C" void Initialise__23CB3TextureCollectionPS2Fv(UnkStruct_003070B0_coll *);
extern "C" void AddTexture__23CB3TextureCollectionPS2FP10CGtTexture(UnkStruct_003070B0_coll *, UnkStruct_003070B0_tex *);
extern "C" void Upload__23CB3TextureCollectionPS2Fv(UnkStruct_003070B0_coll *);
extern "C" void _rwDMAOpenVIFPkt(int, int);
extern "C" void UploadCodeAndStaticData__17CB3CoronaRendererFf();
extern "C" void SetRenderstates__17CB3CoronaRendererFv();
extern "C" void RestoreRenderstates__17CB3CoronaRendererFv();

static inline u_long128 func_003070B0_inl1(unsigned long lo, unsigned long hi)
{
    u_long128 q;
    asm("pcpyld %0, %2, %1" : "=r"(q) : "r"(lo), "r"(hi));
    return q;
}

static inline u_long128 func_003070B0_inl2(unsigned long lo, unsigned long hi)
{
    u_long128 q;
    asm("pcpyld %0, %1, %2" : "=r"(q) : "r"(hi), "r"(lo));
    return q;
}

// 0x003070B0
extern "C" void EndRender__17CB3CoronaRendererFv()
{
    if (mnNumPackets__17CB3CoronaRenderer == 0) return;
    u_long128 qa[8];
    u_long128 qb[8];
    u_long128 qc[8];
    u_long128 qd[8];
    UnkStruct_003070B0_coll coll;
    unsigned long m1;
    int i;
    unsigned long m2;
    Initialise__23CB3TextureCollectionPS2Fv(&coll);
    for (i = 0; i < mnNumPackets__17CB3CoronaRenderer; i++) {
        AddTexture__23CB3TextureCollectionPS2FP10CGtTexture(&coll, D_01E88920[i]);
    }
    Upload__23CB3TextureCollectionPS2Fv(&coll);
    int n = mnNumPackets__17CB3CoronaRenderer;
    for (i = 0; i < n; i++) {
        UnkStruct_003070B0_tex * t = D_01E88920[i];
        UnkStruct_003070B0_34 * r = &t->field_34;
        unsigned long tex0 = *(unsigned int *)((char *)t + 0x3C) | ((unsigned long)*(unsigned int *)((char *)t + 0x40) << 32);
        int lv = *((unsigned char *)t + 0x4A) >> 2;
        unsigned long tex1;
        if (lv > 0) {
            int w = t->field_C;
            float l = -2.5f;
            m1 = r->field_18 | ((unsigned long)r->field_1C << 32);
            m2 = r->field_20 | ((unsigned long)r->field_24 << 32);
            while (w >= 2) {
                w /= 2;
                l += 1.0f;
            }
            int k = (int)(2048.5f + 16.0f * l) - 0x800;
            if (k < -0x800) k = -0x800;
            else if (k > 0x7FF) k = 0x7FF;
            tex1 = ((long)lv << 2 | 0x120) | ((long)(k & 0xFFF) << 32);
        } else {
            tex1 = 0x61;
        }
        qa[i] = func_003070B0_inl1(tex0, 6);
        qb[i] = func_003070B0_inl1(tex1, 0x14);
        qc[i] = func_003070B0_inl1(m1, 0x34);
        qd[i] = func_003070B0_inl1(m2, 0x36);
    }
    int sz = 0xB;
    sz += 4;
    sz += n * 8;
    sz += 4;
    _rwDMAOpenVIFPkt(0, sz);
    UploadCodeAndStaticData__17CB3CoronaRendererFf();
    SetRenderstates__17CB3CoronaRendererFv();
    n = mnNumPackets__17CB3CoronaRenderer;
    for (i = 0; i < n; i++) {
        u_long128 * p = farFogPlane.field_0;
        p[0] = func_003070B0_inl2(0x10000005, 0x5000000500000000);
        p[1] = func_003070B0_inl1(0x1000000000008004, 0xE);
        p[2] = qa[i];
        p[3] = qb[i];
        p[4] = qc[i];
        p[5] = qd[i];
        unsigned long z0 = 0;
        p[6] = func_003070B0_inl1(((unsigned long)D_01E88900[i] << 32) | 0x50000000, z0);
        p[7] = func_003070B0_inl1(0x10000000, 0x10000000);
        farFogPlane.field_0 += 8;
    }
    RestoreRenderstates__17CB3CoronaRendererFv();
    mnNumPackets__17CB3CoronaRenderer = 0;
}

