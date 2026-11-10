// NONMATCHING: Construct__Q216CB3ParticleArray15CB3ParticleBankFUi -- retail 233 / ours 222 instructions, 191 in changed runs
// a143: logic fully decoded (chunks of 60 particles; per chunk 3 DMA ref tags + 3 UNPACK/STCYCL pairs at 16/8/4 bytes per particle, cnt|0x100 on last chunk, head tag 0x10000000/0x05000000<<32 at chunk 0 and 1, tail 0x60000000 or 0x10000000, trailing cnt|0x04000000 [|0x17000000<<32 for i>0], two SyncDCache); ours 220 vs retail 233 instrs, 264 in changed runs: this/p0 registers swapped (retail this=s4,p0=s3), retail hoists consts 1/60/-2 into s5/s7/fp and keeps lui consts in t8/t9/t1/a0..a3, bank pointers reloaded per chunk; remaining is allocation/scheduling | classic-op fallback | guard: n/a (classic ops) | mwperm: 300 -> 223 ('unsigned int i;' -> 'int i;')
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

class CB3ParticleArray {
public:
    class CB3ParticleBank {
    public:
        void Construct(unsigned int p0);
        unsigned long * field_0;
        unsigned long * field_4;
        unsigned char * field_8;
        unsigned char * field_C;
        unsigned char * field_10;
        unsigned int field_14;
        int field_18;
        unsigned char * field_1C;
        float field_20;
        int field_24;
        unsigned int field_28;
    };
};
extern "C" void * Alloc__17CB3EffectsManagerFUiUi(unsigned int, unsigned int);
extern "C" void SyncDCache(void *, void *);

void CB3ParticleArray::CB3ParticleBank::Construct(unsigned int p0)
{
    field_14 = p0;
    field_18 = 0;
    field_24 = 0;
    field_28 = 0;
    if (p0 == 0) {
        field_0 = 0;
        field_4 = 0;
        field_8 = 0;
        field_C = 0;
        field_10 = 0;
        field_1C = 0;
        return;
    }
    unsigned int n = (p0 + 59) / 60;
    field_0 = (unsigned long *)Alloc__17CB3EffectsManagerFUiUi(0x50, 0x80);
    unsigned int s1;
    if (n < 2) {
        field_4 = 0;
        s1 = 0;
    } else {
        s1 = (n - 1) * 0x40 + 0x10;
        field_4 = (unsigned long *)Alloc__17CB3EffectsManagerFUiUi(s1, 0x80);
    }
    field_8 = (unsigned char *)Alloc__17CB3EffectsManagerFUiUi(p0 * 28 + n * 4, 0x10);
    unsigned int last = n - 1;
    unsigned int lastcnt = p0 - last * 60;
    field_C = field_8 + p0 * 16;
    field_10 = field_C + p0 * 8;
    field_1C = field_10 + p0 * 4;
    unsigned long * p;
    int i;
    for (i = 0; i < n; i++) {
        if (i == 0) {
            p = field_0;
            p[0] = 0x10000000;
            p[1] = 0x0500000000000000UL;
            p += 2;
        } else if (i == 1) {
            p = field_4;
            p[0] = 0x10000000;
            p[1] = 0x0500000000000000UL;
            p += 2;
        }
        unsigned int cnt = (i < last) ? 60 : lastcnt;
        unsigned int a2 = (unsigned int)(field_8 + i * 0x3C0);
        unsigned int a3 = (unsigned int)(field_C + i * 0x1E0);
        unsigned int a4 = (unsigned int)(field_10 + i * 0xF0);
        p[0] = ((unsigned long)a2 << 32) | (unsigned long)(cnt | 0x30000000);
        p[1] = ((unsigned long)((cnt << 16) | 0x6C008000) << 32) | 0x1000103UL;
        int c1 = (cnt + 1) & -2;
        p[2] = ((unsigned long)a3 << 32) | (unsigned long)((c1 >> 1) | 0x30000000);
        p[3] = ((unsigned long)((c1 << 16) | 0x6D008001) << 32) | 0x1000103UL;
        int c2 = (cnt + 3) & -4;
        p[4] = ((unsigned long)a4 << 32) | (unsigned long)((c2 >> 2) | 0x30000000);
        p[5] = ((unsigned long)((c2 << 16) | 0x6E00C002) << 32) | 0x1000103UL;
        if (i == last) cnt |= 0x100;
        if (i == 0 || i == last) {
            p[6] = 0x60000000;
        } else {
            p[6] = 0x10000000;
        }
        p += 7;
        if (i == 0) {
            p[0] = (unsigned long)(cnt | 0x4000000);
        } else {
            p[0] = (unsigned long)(cnt | 0x4000000) | 0x1700000000000000UL;
        }
        p += 1;
    }
    SyncDCache(field_0, (char *)field_0 + 0x4F);
    if (field_4 != 0) {
        SyncDCache(field_4, (char *)field_4 + s1 - 1);
    }
}
