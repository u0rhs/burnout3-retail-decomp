// B3Im3d::RenderTristrip(const CB3Im3dVertex*,int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3Im3DPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (whole function asm).

// RenderTristrip__6B3Im3dFPC13CB3Im3dVertexi -- hand-written asm (CodeWarrior asm function, as ProcessB2Distortion)
// [C] hand-written asm: trapping add/addi at 0x003650D8-0x00365158
namespace GtMathPs2 { class CGtMatrix3x4; }
class CB3Im3dVertex;
class B3Im3d { public:
 static void RenderTrilist(const CB3Im3dVertex*, int);
 static void RenderTristrip(const CB3Im3dVertex*, int);
 static void RenderTristrip(const GtMathPs2::CGtMatrix3x4&, const CB3Im3dVertex*, int);
 static unsigned char _gbTextured; static unsigned char _gbBFC; };
extern "C" void _rwDMAOpenVIFPkt(void);
extern "C" unsigned char _gbTextured__6B3Im3d, _gbBFC__6B3Im3d; extern "C" int farFogPlane; extern "C" float D_004E0E50;


// 0x00365040
asm void B3Im3d::RenderTristrip(const CB3Im3dVertex*, int)
{
    .set noreorder
    .set noat
    addiu      $sp, $sp, -0x40
    sd         $ra, 0x30($sp)
    sq         $s2, 0x20($sp)
    sq         $s1, 0x10($sp)
    daddu      $s1, $a1, $zero
    sq         $s0, 0x0($sp)
    sll        $v0, $s1, 1
    daddu      $s0, $a0, $zero
    addu       $s2, $v0, $s1
    daddu      $a0, $zero, $zero
    jal        _rwDMAOpenVIFPkt
    addiu     $a1, $s2, 0x7
    addiu      $a1, $s2, 0x1
    lui        $v1, (0x10000000 >> 16)
    or         $v1, $a1, $v1
    lw         $a3, farFogPlane
    dsll32     $a2, $v1, 0
    daddu      $a1, $zero, $zero
    dsra32     $a2, $a2, 0
    lui        $v1, (0x5000000 >> 16)
    pcpyld     $a1, $a1, $a2
    dsll32     $a2, $v1, 0
    sll        $a0, $s2, 16
    lui        $v1, (0x6C008000 >> 16)
    ori        $v1, $v1, (0x6C008000 & 0xFFFF)
    sq         $a1, 0x0($a3)
    or         $a0, $a0, $v1
    dsll32     $a0, $a0, 0
    lui        $v1, (0x1000303 >> 16)
    dsrl32     $a0, $a0, 0
    ori        $v1, $v1, (0x1000303 & 0xFFFF)
    dsll32     $a1, $a0, 0
    or         $v1, $a1, $v1
    pcpyld     $v1, $v1, $a2
    sq         $v1, 0x10($a3)
    lbu        $v1, _gbTextured__6B3Im3d
    beqz       $v1, @L00365120
    addiu     $a0, $a3, 0x20
    add        $t7, $zero, $s0
    add        $t6, $zero, $s1
@L003650E0:
    lw         $v1, 0x18($t7)
    lqc2       $vf1, 0x10($t7)
    pextlb     $v1, $zero, $v1
    lq         $a1, 0x0($t7)
    vftoi12.xy $vf1, $vf1
    pextlh     $v1, $zero, $v1
    addiu      $a0, $a0, 0x30
    addiu      $t7, $t7, 0x20
    addi       $t6, $t6, -0x1
    sq         $a1, -0x30($a0)
    sqc2       $vf1, -0x20($a0)
    sq         $v1, -0x10($a0)
    bgtz       $t6, @L003650E0
    nop
    b          @L00365170
    lui       $a1, (0x6C0203F4 >> 16)
@L00365120:
    lui        $v1, (0x80FFFFFF >> 16)
    ori        $v1, $v1, (0x80FFFFFF & 0xFFFF)
    pextlb     $v1, $zero, $v1
    pextlh     $v1, $zero, $v1
    add        $t7, $zero, $s0
    add        $t6, $zero, $s1
@L00365138:
    lw         $a1, 0x18($t7)
    lq         $a2, 0x0($t7)
    pextlb     $a1, $zero, $a1
    pextlh     $a1, $zero, $a1
    paddw      $a1, $a1, $a1
    pminw      $a1, $a1, $v1
    addiu      $a0, $a0, 0x30
    addiu      $t7, $t7, 0x20
    addi       $t6, $t6, -0x1
    sq         $a2, -0x30($a0)
    sq         $a1, -0x10($a0)
    bgtz       $t6, @L00365138
    nop
    lui        $a1, (0x6C0203F4 >> 16)
@L00365170:
    lui        $v1, (0x10000002 >> 16)
    ori        $a1, $a1, (0x6C0203F4 & 0xFFFF)
    ori        $t0, $v1, (0x10000002 & 0xFFFF)
    dsll32     $a3, $a1, 0
    lui        $a1, (0x1000404 >> 16)
    ori        $a2, $a1, (0x1000404 & 0xFFFF)
    lui        $a1, (0x30004000 >> 16)
    or         $a2, $a2, $a3
    ori        $t1, $a1, 0x4000
    pcpyld     $a1, $a2, $t0
    pcpyld     $a2, $v1, $v1
    sq         $a2, 0x0($a0)
    addiu      $t0, $zero, 0x412
    sq         $a1, 0x10($a0)
    lui        $a2, (0x4000000 >> 16)
    lbu        $t2, _gbTextured__6B3Im3d
    or         $a3, $s1, $a2
    lui        $a2, (0x17000000 >> 16)
    dsll32     $a3, $a3, 0
    dsrl32     $a3, $a3, 0
    dsll32     $a2, $a2, 0
    or         $a3, $a3, $a2
    daddu      $a1, $zero, $zero
    pcpyld     $a3, $a3, $v1
    addiu      $a2, $a0, 0x50
    dsll32     $v1, $t2, 0
    dsra32     $v1, $v1, 0
    dsll       $v1, $v1, 4
    ori        $v1, $v1, 0x4C
    dsll       $v1, $v1, 15
    or         $v1, $v1, $t1
    dsll32     $v1, $v1, 0
    pcpyld     $v1, $t0, $v1
    sq         $v1, 0x20($a0)
    lbu        $v1, _gbBFC__6B3Im3d
    dsll32     $v1, $v1, 0
    pcpyld     $v1, $a1, $v1
    sq         $v1, 0x30($a0)
    sq         $a3, 0x40($a0)
    sw         $a2, farFogPlane
    ld         $ra, 0x30($sp)
    lq         $s2, 0x20($sp)
    lq         $s1, 0x10($sp)
    lq         $s0, 0x0($sp)
    jr         $ra
    addiu     $sp, $sp, 0x40
    .set at
    .set reorder
}
