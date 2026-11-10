// B3Im3d::RenderLinelist(const CB3Im3dVertex*,int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3Im3DPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (v257: GIF quads as lo-first pcpyld asm, the two vertex loops as retail's hand-written asm (addi; .set noreorder; fixed scratch a0/a1), prim select if/else).

// Hand-written (v257); the lifter refused it. B3Im3d::RenderLinelist(const CB3Im3dVertex*, int): GIF packet for a line
// list. [C] the two vertex loops are hand-written asm in retail (`addi`, which MWCC never emits); field names and
// types are placeholders [G].
typedef unsigned int u_long128 __attribute__((mode(TI)));
struct UnkStruct_farFogPlane { u_long128 * field_0; };
extern UnkStruct_farFogPlane farFogPlane;
extern "C" void _rwDMAOpenVIFPkt(int, int);
class CB3Im3dVertex;
class B3Im3d {
public:
    static void RenderLinelist(const CB3Im3dVertex * v, int n);
    static bool _gbTextured;
    static bool _gbBFC;
    static bool _gbLineAA;
};

// 0x00364920
void B3Im3d::RenderLinelist(const CB3Im3dVertex * v, int n)
{
    int q = n * 3;
    _rwDMAOpenVIFPkt(0, q + 6);
    u_long128 * p = farFogPlane.field_0;
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"((long)(int)((q + 1) | 0x10000000)), "r"(0));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0x0500000000000000), "r"(((unsigned long)(unsigned int)((q << 16) | 0x6C008000) << 32) | 0x01000303));
    if (_gbTextured) {
        int c = n;
        asm volatile(".set noreorder" "\n"
            "1:" "\n\t"
            "lqc2 $vf1, 0x0(%0)" "\n\t"
            "lqc2 $vf3, 0x30(%0)" "\n\t"
            "lqc2 $vf2, 0x20(%0)" "\n\t"
            "lqc2 $vf4, 0x50(%0)" "\n\t"
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
            : "+r"(v), "+r"(p), "+r"(c));
    } else {
        int c = n;
        unsigned long m;
        asm("pextlb %0, $0, %1" "\n\t" "pextlh %0, $0, %0" : "=r"(m) : "r"(0x80FFFFFF));
        asm volatile(".set noreorder" "\n"
            "1:" "\n\t"
            "lqc2 $vf1, 0x0(%0)" "\n\t"
            "lqc2 $vf2, 0x20(%0)" "\n\t"
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
            : "+r"(v), "+r"(p), "+r"(c) : "r"(m));
    }
    asm("pcpyld %0, %2, %1" : "=r"(p[0]) : "r"(0x10000002), "r"(0x6C0203F401000404));
    unsigned long prim;
    if (_gbLineAA)
        prim = ((long)(int)_gbTextured << 4) | 0xC9;
    else
        prim = ((long)(int)_gbTextured << 4) | 0x49;
    asm("pcpyld %0, %2, %1" : "=r"(p[1]) : "r"(((prim << 15) | 0x30004000) << 32), "r"(0x412));
    asm("pcpyld %0, %2, %1" : "=r"(p[2]) : "r"((unsigned long)_gbBFC << 32), "r"(1));
    asm("pcpyld %0, %2, %1" : "=r"(p[3]) : "r"(0x10000000), "r"(0x1700000000000000 | (unsigned int)(n | 0x04000000)));
    farFogPlane.field_0 = p + 4;
}
