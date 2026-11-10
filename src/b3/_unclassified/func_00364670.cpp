// Hand-written; the lifter refused it (v273: RenderLinelist clone + matrix transform inside retail's hand-written (addi) loop blocks).

// Hand-written (v273); the lifter refused it. func_00364670 -- the transformed twin of B3Im3d::RenderLinelist (0x364920,
// v257): a GIF packet for a line list whose vertices are put through a 3x4 matrix (a0) first [L]. [C] the two vertex
// loops are hand-written asm in retail (`addi`, which MWCC never emits), as RenderLinelist's; the matrix rows are loaded
// into $vf5-$vf8 / $vf3-$vf6 inside them. Types and names placeholders [G].
typedef unsigned int u_long128 __attribute__((mode(TI)));
struct UnkStruct_farFogPlane { u_long128 * field_0; };
extern UnkStruct_farFogPlane farFogPlane;
extern "C" void _rwDMAOpenVIFPkt(int, int);
class CB3Im3dVertex;
class B3Im3d {
public:
    static bool _gbTextured;
    static bool _gbBFC;
    static bool _gbLineAA;
};

// 0x00364670
extern "C" void func_00364670(const void * m, const CB3Im3dVertex * v, int n)
{
    int q = n * 3;
    _rwDMAOpenVIFPkt(0, q + 6);
    u_long128 * p = farFogPlane.field_0;
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"((long)(int)((q + 1) | 0x10000000)), "r"(0));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0x0500000000000000), "r"(((unsigned long)(unsigned int)((q << 16) | 0x6C008000) << 32) | 0x01000303));
    if (B3Im3d::_gbTextured) {
        int c = n;
        asm volatile(".set noreorder" "\n\t"
            "lqc2 $vf5, 0x0(%3)" "\n\t"
            "lqc2 $vf6, 0x10(%3)" "\n\t"
            "lqc2 $vf7, 0x20(%3)" "\n\t"
            "lqc2 $vf8, 0x30(%3)" "\n"
            "1:" "\n\t"
            "lqc2 $vf1, 0x0(%0)" "\n\t"
            "lqc2 $vf3, 0x20(%0)" "\n\t"
            "lqc2 $vf2, 0x10(%0)" "\n\t"
            "lqc2 $vf4, 0x40(%0)" "\n\t"
            "vmulax.xyz $ACC, $vf5, $vf1x" "\n\t"
            "vmadday.xyz $ACC, $vf6, $vf1y" "\n\t"
            "vmaddaz.xyz $ACC, $vf7, $vf1z" "\n\t"
            "vmaddw.xyz $vf1, $vf8, $vf0w" "\n\t"
            "vmulax.xyz $ACC, $vf5, $vf3x" "\n\t"
            "vmadday.xyz $ACC, $vf6, $vf3y" "\n\t"
            "vmaddaz.xyz $ACC, $vf7, $vf3z" "\n\t"
            "vmaddw.xyz $vf3, $vf8, $vf0w" "\n\t"
            "vftoi12.xy $vf2, $vf2" "\n\t"
            "vftoi12.xy $vf4, $vf4" "\n\t"
            "lw $a0, 0x18(%0)" "\n\t"
            "pextlb $a0, $0, $a0" "\n\t"
            "pextlh $a0, $0, $a0" "\n\t"
            "sq $a0, 0x20(%1)" "\n\t"
            "lw $a0, 0x38(%0)" "\n\t"
            "pextlb $a0, $0, $a0" "\n\t"
            "pextlh $a0, $0, $a0" "\n\t"
            "sq $a0, 0x50(%1)" "\n\t"
            "addiu %1, %1, 0x60" "\n\t"
            "addiu %0, %0, 0x40" "\n\t"
            "addi %2, %2, -0x2" "\n\t"
            "sqc2 $vf1, -0x60(%1)" "\n\t"
            "sqc2 $vf2, -0x50(%1)" "\n\t"
            "sqc2 $vf3, -0x30(%1)" "\n\t"
            "sqc2 $vf4, -0x20(%1)" "\n\t"
            "bgtz %2, 1b" "\n\t"
            "nop" "\n"
            ".set reorder"
            : "+r"(v), "+r"(p), "+r"(c) : "r"(m));
    } else {
        int c = n;
        int mk = 0x80FFFFFF;
        asm volatile(".set noreorder" "\n\t"
            "lqc2 $vf3, 0x0(%4)" "\n\t"
            "lqc2 $vf4, 0x10(%4)" "\n\t"
            "lqc2 $vf5, 0x20(%4)" "\n\t"
            "lqc2 $vf6, 0x30(%4)" "\n\t"
            "pextlb %3, $0, %3" "\n\t"
            "pextlh %3, $0, %3" "\n"
            "1:" "\n\t"
            "lqc2 $vf1, 0x0(%0)" "\n\t"
            "lqc2 $vf2, 0x20(%0)" "\n\t"
            "vmulax.xyz $ACC, $vf3, $vf1x" "\n\t"
            "vmadday.xyz $ACC, $vf4, $vf1y" "\n\t"
            "vmaddaz.xyz $ACC, $vf5, $vf1z" "\n\t"
            "vmaddw.xyz $vf1, $vf6, $vf0w" "\n\t"
            "vmulax.xyz $ACC, $vf3, $vf2x" "\n\t"
            "vmadday.xyz $ACC, $vf4, $vf2y" "\n\t"
            "vmaddaz.xyz $ACC, $vf5, $vf2z" "\n\t"
            "vmaddw.xyz $vf2, $vf6, $vf0w" "\n\t"
            "lw $a1, 0x18(%0)" "\n\t"
            "pextlb $a1, $0, $a1" "\n\t"
            "pextlh $a1, $0, $a1" "\n\t"
            "paddw $a1, $a1, $a1" "\n\t"
            "pminw $a1, $a1, %3" "\n\t"
            "sq $a1, 0x20(%1)" "\n\t"
            "lw $a1, 0x38(%0)" "\n\t"
            "pextlb $a1, $0, $a1" "\n\t"
            "pextlh $a1, $0, $a1" "\n\t"
            "paddw $a1, $a1, $a1" "\n\t"
            "pminw $a1, $a1, %3" "\n\t"
            "sq $a1, 0x50(%1)" "\n\t"
            "addiu %1, %1, 0x60" "\n\t"
            "addiu %0, %0, 0x40" "\n\t"
            "addi %2, %2, -0x2" "\n\t"
            "sqc2 $vf1, -0x60(%1)" "\n\t"
            "sqc2 $vf2, -0x30(%1)" "\n\t"
            "bgtz %2, 1b" "\n\t"
            "nop" "\n"
            ".set reorder"
            : "+r"(v), "+r"(p), "+r"(c), "+r"(mk) : "r"(m));
    }
    asm("pcpyld %0, %2, %1" : "=r"(p[0]) : "r"(0x10000002), "r"(0x6C0203F401000404));
    unsigned long prim;
    if (B3Im3d::_gbLineAA)
        prim = ((long)(int)B3Im3d::_gbTextured << 4) | 0xC9;
    else
        prim = ((long)(int)B3Im3d::_gbTextured << 4) | 0x49;
    asm("pcpyld %0, %2, %1" : "=r"(p[1]) : "r"(((prim << 15) | 0x30004000) << 32), "r"(0x412));
    asm("pcpyld %0, %2, %1" : "=r"(p[2]) : "r"((unsigned long)B3Im3d::_gbBFC << 32), "r"(1));
    asm("pcpyld %0, %2, %1" : "=r"(p[3]) : "r"(0x10000000), "r"(0x1700000000000000 | (unsigned int)(n | 0x04000000)));
    farFogPlane.field_0 = p + 4;
}
