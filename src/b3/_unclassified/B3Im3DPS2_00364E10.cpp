// B3Im3d::RenderTristrip(const GtMathPs2::CGtMatrix3x4&,const CB3Im3dVertex*,int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3Im3DPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (whole function asm).

// RenderTristrip__6B3Im3dFRCQ29GtMathPs212CGtMatrix3x4PC13CB3Im3dVertexi -- hand-written asm (CodeWarrior asm function, as ProcessB2Distortion)
// [C] hand-written asm: trapping addi at 0x00364EF8, 0x00364F6C
namespace GtMathPs2 { class CGtMatrix3x4; }
class CB3Im3dVertex;
class B3Im3d { public:
 static void RenderTrilist(const CB3Im3dVertex*, int);
 static void RenderTristrip(const CB3Im3dVertex*, int);
 static void RenderTristrip(const GtMathPs2::CGtMatrix3x4&, const CB3Im3dVertex*, int);
 static unsigned char _gbTextured; static unsigned char _gbBFC; };
extern "C" void _rwDMAOpenVIFPkt(void);
extern "C" unsigned char _gbTextured__6B3Im3d, _gbBFC__6B3Im3d; extern "C" int farFogPlane; extern "C" float D_004E0E50;

// 0x00364E10
asm void B3Im3d::RenderTristrip(const GtMathPs2::CGtMatrix3x4&, const CB3Im3dVertex*, int)
{
    .set noreorder
    .set noat
    addiu      $sp, $sp, -0x50
    sd         $ra, 0x40($sp)
    sq         $s3, 0x30($sp)
    sq         $s2, 0x20($sp)
    sq         $s1, 0x10($sp)
    daddu      $s2, $a0, $zero
    sq         $s0, 0x0($sp)
    daddu      $s1, $a1, $zero
    daddu      $s0, $a2, $zero
    daddu      $a0, $zero, $zero
    sll        $v0, $s0, 1
    addu       $s3, $v0, $s0
    jal        _rwDMAOpenVIFPkt
    addiu     $a1, $s3, 0x6
    addiu      $a1, $s3, 0x1
    lui        $a0, (0x10000000 >> 16)
    or         $a0, $a1, $a0
    lw         $v1, farFogPlane
    dsll32     $a3, $a0, 0
    daddu      $a1, $zero, $zero
    dsra32     $a3, $a3, 0
    lui        $a0, (0x5000000 >> 16)
    pcpyld     $a1, $a1, $a3
    dsll32     $a3, $a0, 0
    sll        $a2, $s3, 16
    lui        $a0, (0x6C008000 >> 16)
    sq         $a1, 0x0($v1)
    ori        $a0, $a0, (0x6C008000 & 0xFFFF)
    or         $a1, $a2, $a0
    dsll32     $a2, $a1, 0
    lui        $a0, (0x1000303 >> 16)
    dsrl32     $a2, $a2, 0
    ori        $a1, $a0, (0x1000303 & 0xFFFF)
    dsll32     $a2, $a2, 0
    addiu      $a0, $v1, 0x20
    or         $a1, $a2, $a1
    pcpyld     $a1, $a1, $a3
    sq         $a1, 0x10($v1)
    lbu        $v1, _gbTextured__6B3Im3d
    beqz       $v1, @L00364F18
    nop
    daddu      $a1, $s0, $zero
    lqc2       $vf3, 0x0($s2)
    lqc2       $vf4, 0x10($s2)
    lqc2       $vf5, 0x20($s2)
    lqc2       $vf6, 0x30($s2)
@L00364EC8:
    lqc2       $vf2, 0x10($s1)
    lqc2       $vf1, 0x0($s1)
    lw         $v1, 0x18($s1)
    vmulax.xyz $ACC, $vf3, $vf1x
    vmadday.xyz $ACC, $vf4, $vf1y
    vmaddaz.xyz $ACC, $vf5, $vf1z
    vmaddw.xyz $vf1, $vf6, $vf0w
    pextlb     $v1, $zero, $v1
    vftoi12.xy $vf2, $vf2
    pextlh     $v1, $zero, $v1
    addiu      $a0, $a0, 0x30
    addiu      $s1, $s1, 0x20
    addi       $a1, $a1, -0x1
    sqc2       $vf1, -0x30($a0)
    sqc2       $vf2, -0x20($a0)
    sq         $v1, -0x10($a0)
    bgtz       $a1, @L00364EC8
    nop
    b          @L00364F84
    lui       $v1, (0x6C0203F4 >> 16)
@L00364F18:
    lui        $v1, (0x80FFFFFF >> 16)
    daddu      $a2, $s0, $zero
    ori        $v1, $v1, (0x80FFFFFF & 0xFFFF)
    lqc2       $vf2, 0x0($s2)
    lqc2       $vf3, 0x10($s2)
    lqc2       $vf4, 0x20($s2)
    lqc2       $vf5, 0x30($s2)
    pextlb     $v1, $zero, $v1
    pextlh     $v1, $zero, $v1
@L00364F3C:
    lqc2       $vf1, 0x0($s1)
    lw         $a1, 0x18($s1)
    vmulax.xyz $ACC, $vf2, $vf1x
    vmadday.xyz $ACC, $vf3, $vf1y
    vmaddaz.xyz $ACC, $vf4, $vf1z
    vmaddw.xyz $vf1, $vf5, $vf0w
    pextlb     $a1, $zero, $a1
    pextlh     $a1, $zero, $a1
    paddw      $a1, $a1, $a1
    pminw      $a1, $a1, $v1
    addiu      $a0, $a0, 0x30
    addiu      $s1, $s1, 0x20
    addi       $a2, $a2, -0x1
    sqc2       $vf1, -0x30($a0)
    sq         $a1, -0x10($a0)
    bgtz       $a2, @L00364F3C
    nop
    lui        $v1, (0x6C0203F4 >> 16)
@L00364F84:
    lui        $t3, (0x10000002 >> 16)
    ori        $v1, $v1, (0x6C0203F4 & 0xFFFF)
    ori        $a3, $t3, (0x10000002 & 0xFFFF)
    dsll32     $a2, $v1, 0
    addiu      $t0, $zero, 0x412
    lui        $v1, (0x1000404 >> 16)
    ori        $a1, $v1, (0x1000404 & 0xFFFF)
    lui        $v1, (0x30004000 >> 16)
    or         $a1, $a1, $a2
    ori        $t1, $v1, 0x4000
    lui        $a2, (0x4000000 >> 16)
    pcpyld     $v1, $a1, $a3
    sq         $v1, 0x0($a0)
    or         $a3, $s0, $a2
    lbu        $t2, _gbTextured__6B3Im3d
    lui        $v1, (0x17000000 >> 16)
    dsll32     $a3, $a3, 0
    dsll32     $a2, $v1, 0
    dsrl32     $a3, $a3, 0
    daddu      $a1, $zero, $zero
    or         $a2, $a3, $a2
    addiu      $v1, $a0, 0x40
    pcpyld     $a3, $a2, $t3
    dsll32     $a2, $t2, 0
    dsra32     $a2, $a2, 0
    dsll       $a2, $a2, 4
    ori        $a2, $a2, 0x4C
    dsll       $a2, $a2, 15
    or         $a2, $a2, $t1
    dsll32     $a2, $a2, 0
    pcpyld     $a2, $t0, $a2
    sq         $a2, 0x10($a0)
    lbu        $a2, _gbBFC__6B3Im3d
    dsll32     $a2, $a2, 0
    pcpyld     $a1, $a1, $a2
    sq         $a1, 0x20($a0)
    sq         $a3, 0x30($a0)
    sw         $v1, farFogPlane
    ld         $ra, 0x40($sp)
    lq         $s3, 0x30($sp)
    lq         $s2, 0x20($sp)
    lq         $s1, 0x10($sp)
    lq         $s0, 0x0($sp)
    jr         $ra
    addiu     $sp, $sp, 0x50
    .set at
    .set reorder
}
