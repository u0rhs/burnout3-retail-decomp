// NONMATCHING: BuildPacketToSendRasterToGS__15CGtTextureCacheFP8RwRasterUi -- retail 108 / ours 108 instructions, 27 in changed runs
// pass2b: DI() now in eekernel.h shape (.p2align 3, [L] N230), still 27: loop quad3 ptr lw scheduled after pcpyld (retail before daddu, t1/t3 swap); tail: retail builds q0, loads ptr, q1, q2, DI mask lui before first sq; ours after. Tried locals/order/z/operand swaps: no gain
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)


// 001 t0
// inbp a c
// CGtTextureCache::BuildPacketToSendRasterToGS(RwRaster*, unsigned int) -- hand-matched (gif4).
typedef unsigned int u_long128 __attribute__((mode(TI)));
struct RwRaster {
    unsigned char pad_0[0x24];
    unsigned int *field_24;
};
struct UnkStruct_00221E80_ext {
    volatile int field_0;
    volatile int field_4;
};
class CGtTextureCache {
public:
    unsigned char pad_0[0x1C8];
    u_long128 *field_1C8;
    void BuildPacketToSendRasterToGS(RwRaster *, unsigned int);
};
extern int skyRasterExt;
extern u_long128 *_gOldRasterShowRasterFunc;
extern "C" void _rwDMAAddPURef(int *);

// 0x00221E80
void CGtTextureCache::BuildPacketToSendRasterToGS(RwRaster *raster, unsigned int addr)
{
    UnkStruct_00221E80_ext *ext = (UnkStruct_00221E80_ext *)((char *)raster + skyRasterExt);
    if (field_1C8) {
        u_long128 q;
        asm("pcpyld %0, %2, %1" : "=r"(q) : "r"(0x1000000000000001UL), "r"(14));
        *field_1C8 = q;
    }
    unsigned int *src = raster->field_24;
    unsigned int i = 0;
    unsigned int n = src[0];
    unsigned long bp = (unsigned long)(addr & ~0x3F) << 26;
    u_long128 *s = (u_long128 *)(src + 4);
    goto test;
body:
    {
        i++;
        *_gOldRasterShowRasterFunc++ = s[0];
        *_gOldRasterShowRasterFunc++ = s[1];
        u_long128 q;
        unsigned long *l = (unsigned long *)&s[2];
        asm("pcpyld %0, %2, %1" : "=r"(q) : "r"(l[0] + bp), "r"(l[1]));
        *_gOldRasterShowRasterFunc++ = q;
        *_gOldRasterShowRasterFunc++ = s[3];
        s += 4;
    }
test:
    if (i < n) goto body;
    u_long128 q0, q1;
    asm("pcpyld %0, %2, %1" : "=r"(q0) : "r"(0x10000002UL), "r"(0x5000000200000000UL));
    asm("pcpyld %0, %2, %1" : "=r"(q1) : "r"(0x1000000000008001UL), "r"(14));
    *_gOldRasterShowRasterFunc++ = q0;
    field_1C8 = _gOldRasterShowRasterFunc;
    *_gOldRasterShowRasterFunc++ = q1;
    asm("pcpyld %0, %1, %2" : "=r"(*_gOldRasterShowRasterFunc++) : "r"(0x7F), "r"(0UL));
    {   // DI(): eekernel.h-shaped equivalent, asm volatile allowed [L] N230
        unsigned int stat;
        do {
            asm volatile (".p2align 3");
            asm volatile ("di");
            asm volatile ("sync.p");
            asm volatile ("mfc0 %0, $12" : "=r"(stat));
        } while (stat & 0x10000);
    }
    ext->field_0++;
    asm volatile ("ei");
    ext->field_4++;
    if (ext->field_4 == 1) {
        _rwDMAAddPURef((int *)ext);
    }
}

