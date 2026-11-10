// B3Im3d::RenderTrilist(const CB3Im3dVertex*,int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3Im3DPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (whole function asm).

// RenderTrilist__6B3Im3dFPC13CB3Im3dVertexi -- hand-written asm (CodeWarrior asm function, as ProcessB2Distortion)
// [C] hand-written asm: trapping addi at 0x00364C94, 0x00364D3C
namespace GtMathPs2 { class CGtMatrix3x4; }
class CB3Im3dVertex;
class B3Im3d { public:
 static void RenderTrilist(const CB3Im3dVertex*, int);
 static void RenderTristrip(const CB3Im3dVertex*, int);
 static void RenderTristrip(const GtMathPs2::CGtMatrix3x4&, const CB3Im3dVertex*, int);
 static unsigned char _gbTextured; static unsigned char _gbBFC; };
extern "C" void _rwDMAOpenVIFPkt(void);
extern "C" unsigned char _gbTextured__6B3Im3d, _gbBFC__6B3Im3d; extern "C" int farFogPlane; extern "C" float D_004E0E50;


// 0x00364B70
asm void B3Im3d::RenderTrilist(const CB3Im3dVertex*, int)
{
    .set noreorder
    .set noat
    addiu      $sp, $sp, -0x50
    sd         $ra, 0x30($sp)
    sq         $s2, 0x20($sp)
    sq         $s1, 0x10($sp)
    sq         $s0, 0x0($sp)
    daddu      $s1, $a0, $zero
    daddu      $s0, $a1, $zero
    daddu      $a0, $zero, $zero
    sll        $v0, $s0, 1
    addu       $s2, $v0, $s0
    jal        _rwDMAOpenVIFPkt
    addiu     $a1, $s2, 0x6
    addiu      $a0, $s2, 0x1
    lui        $v1, (0x10000000 >> 16)
    or         $v1, $a0, $v1
    lw         $a3, farFogPlane
    dsll32     $a2, $v1, 0
    daddu      $a0, $zero, $zero
    dsra32     $a2, $a2, 0
    lui        $v1, (0x5000000 >> 16)
    pcpyld     $a0, $a0, $a2
    lw         $t0, D_004E0E50
    dsll32     $a2, $v1, 0
    sll        $a1, $s2, 16
    lui        $v1, (0x6C008000 >> 16)
    sq         $a0, 0x0($a3)
    ori        $v1, $v1, (0x6C008000 & 0xFFFF)
    or         $a0, $a1, $v1
    dsll32     $a1, $a0, 0
    lui        $v1, (0x1000303 >> 16)
    dsrl32     $a1, $a1, 0
    ori        $a0, $v1, (0x1000303 & 0xFFFF)
    dsll32     $a1, $a1, 0
    addiu      $v1, $a3, 0x20
    or         $a0, $a1, $a0
    pcpyld     $a0, $a0, $a2
    sq         $a0, 0x10($a3)
    nop
    lqc2       $vf1, 0x40($sp)
    qmtc2.ni   $t0, $vf2
    vsubw.w    $vf1, $vf0, $vf0w
    lbu        $a0, _gbTextured__6B3Im3d
    vaddx.w    $vf1, $vf1, $vf2x
    sqc2       $vf1, 0x40($sp)
    beqz       $a0, @L00364CC0
    qmfc2.ni  $a1, $vf1
    qmtc2.ni   $a1, $vf7
    daddu      $a2, $s0, $zero
@L00364C30:
    lqc2       $vf1, 0x0($s1)
    lqc2       $vf2, 0x20($s1)
    lqc2       $vf3, 0x40($s1)
    lqc2       $vf4, 0x10($s1)
    lqc2       $vf5, 0x30($s1)
    lqc2       $vf6, 0x50($s1)
    lw         $a0, 0x18($s1)
    pextlb     $a0, $zero, $a0
    pextlh     $a0, $zero, $a0
    sq         $a0, 0x20($v1)
    lw         $a0, 0x38($s1)
    pextlb     $a0, $zero, $a0
    pextlh     $a0, $zero, $a0
    sq         $a0, 0x50($v1)
    lw         $a0, 0x58($s1)
    pextlb     $a0, $zero, $a0
    pextlh     $a0, $zero, $a0
    sq         $a0, 0x80($v1)
    vmove.w    $vf1, $vf7
    vmove.w    $vf2, $vf7
    vftoi12.xy $vf4, $vf4
    vftoi12.xy $vf5, $vf5
    vftoi12.xy $vf6, $vf6
    addiu      $v1, $v1, 0x90
    addiu      $s1, $s1, 0x60
    addi       $a2, $a2, -0x3
    sqc2       $vf1, -0x90($v1)
    sqc2       $vf4, -0x80($v1)
    sqc2       $vf2, -0x60($v1)
    sqc2       $vf5, -0x50($v1)
    sqc2       $vf3, -0x30($v1)
    sqc2       $vf6, -0x20($v1)
    bgtz       $a2, @L00364C30
    nop
    b          @L00364D58
    lui       $a0, (0x6C0203F4 >> 16)
@L00364CC0:
    lui        $a0, (0x80FFFFFF >> 16)
    daddu      $a2, $s0, $zero
    ori        $a0, $a0, (0x80FFFFFF & 0xFFFF)
    pextlb     $a0, $zero, $a0
    pextlh     $a0, $zero, $a0
    qmtc2.ni   $a1, $vf4
@L00364CD8:
    lqc2       $vf1, 0x0($s1)
    lqc2       $vf2, 0x20($s1)
    lqc2       $vf3, 0x40($s1)
    vmove.w    $vf1, $vf4
    vmove.w    $vf2, $vf4
    lw         $a1, 0x18($s1)
    pextlb     $a1, $zero, $a1
    pextlh     $a1, $zero, $a1
    paddw      $a1, $a1, $a1
    pminw      $a1, $a1, $a0
    sq         $a1, 0x20($v1)
    lw         $a1, 0x38($s1)
    pextlb     $a1, $zero, $a1
    pextlh     $a1, $zero, $a1
    paddw      $a1, $a1, $a1
    pminw      $a1, $a1, $a0
    sq         $a1, 0x50($v1)
    lw         $a1, 0x58($s1)
    pextlb     $a1, $zero, $a1
    pextlh     $a1, $zero, $a1
    paddw      $a1, $a1, $a1
    pminw      $a1, $a1, $a0
    sq         $a1, 0x80($v1)
    addiu      $v1, $v1, 0x90
    addiu      $s1, $s1, 0x60
    addi       $a2, $a2, -0x3
    sqc2       $vf1, -0x90($v1)
    sqc2       $vf2, -0x60($v1)
    sqc2       $vf3, -0x30($v1)
    bgtz       $a2, @L00364CD8
    nop
    lui        $a0, (0x6C0203F4 >> 16)
@L00364D58:
    lui        $t3, (0x10000002 >> 16)
    ori        $a0, $a0, (0x6C0203F4 & 0xFFFF)
    ori        $a3, $t3, (0x10000002 & 0xFFFF)
    dsll32     $a2, $a0, 0
    addiu      $t0, $zero, 0x412
    lui        $a0, (0x1000404 >> 16)
    ori        $a1, $a0, (0x1000404 & 0xFFFF)
    lui        $a0, (0x30004000 >> 16)
    or         $a1, $a1, $a2
    ori        $t1, $a0, 0x4000
    lui        $a2, (0x4000000 >> 16)
    pcpyld     $a0, $a1, $a3
    sq         $a0, 0x0($v1)
    or         $a3, $s0, $a2
    lbu        $t2, _gbTextured__6B3Im3d
    lui        $a1, (0x17000000 >> 16)
    dsll32     $a3, $a3, 0
    dsll32     $a2, $a1, 0
    dsrl32     $a3, $a3, 0
    daddu      $a0, $zero, $zero
    or         $a2, $a3, $a2
    addiu      $a1, $v1, 0x40
    pcpyld     $a3, $a2, $t3
    dsll32     $a2, $t2, 0
    dsra32     $a2, $a2, 0
    dsll       $a2, $a2, 4
    ori        $a2, $a2, 0x4C
    dsll       $a2, $a2, 15
    or         $a2, $a2, $t1
    dsll32     $a2, $a2, 0
    pcpyld     $a2, $t0, $a2
    sq         $a2, 0x10($v1)
    lbu        $a2, _gbBFC__6B3Im3d
    dsll32     $a2, $a2, 0
    pcpyld     $a0, $a0, $a2
    sq         $a0, 0x20($v1)
    sq         $a3, 0x30($v1)
    sw         $a1, farFogPlane
    ld         $ra, 0x30($sp)
    lq         $s2, 0x20($sp)
    lq         $s1, 0x10($sp)
    lq         $s0, 0x0($sp)
    jr         $ra
    addiu     $sp, $sp, 0x50
    .set at
    .set reorder
}
