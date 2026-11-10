.include "macro.inc"

.set noat
.set noreorder

/* B3PromptsComponent.cpp's static data and initializer (C source: B3PromptsComponent_004D8100.cpp), split out of
   data/game/unit_0031CDA0.rodata.s (its last 8 bytes), data/game/unit_0031E1A0.rodata.s, sinit_004D7EC0.s and
   data/ctor_004DD8E4.ctor.s. */

.section .rodata, "a"
.balign 8
dlabel D_004C52D8
    .word 0x00000000
enddlabel D_004C52D8
dlabel D_004C52DC
    .word 0x00000000
enddlabel D_004C52DC
dlabel D_004C52E0
    .word 0x00000000
    .word 0x3F800000
    .word 0x3F570A3D
enddlabel D_004C52E0
dlabel D_004C52EC
    .word 0x3F400000
    .word 0x3E800000
    .word 0x00000000
    .word 0x3E75C28F
    .word 0x3E75C28F
    .word 0x00000000
    .word 0x3E2E147B
    .word 0x3F4CCCCD
    .word 0x00000000
enddlabel D_004C52EC
dlabel D_004C5310
    .word 0x00000005
    .word 0x00000008
    .word 0x00000000
    .word 0x00000009
    .word 0x00000006
    .word 0x00000007
    .word 0x00000004
    .word 0x00000003
    .word 0x0000000A
    .word 0x00000002
    .word 0x00000001
    .word 0x00000000
enddlabel D_004C5310
dlabel D_004C5340
    .word 0x00000000
enddlabel D_004C5340
dlabel D_004C5344
    .word 0x00000000
enddlabel D_004C5344
dlabel D_004C5348
    .word 0x00000000
enddlabel D_004C5348
dlabel D_004C534C
    .word 0x00000000
enddlabel D_004C534C
dlabel D_004C5350
    .word 0x00000000
enddlabel D_004C5350
dlabel D_004C5354
    .word 0x00000000
enddlabel D_004C5354
dlabel D_004C5358
    .word 0x00000000
enddlabel D_004C5358
dlabel D_004C535C
    .word 0x00000000
enddlabel D_004C535C
dlabel D_004C5360
    .word 0x00000000
enddlabel D_004C5360
dlabel D_004C5364
    .word 0x00000000
enddlabel D_004C5364

.section .init, "ax"
.balign 16
nonmatching func_004D8100, 0x98

glabel func_004D8100
    /* 3D8100 004D8100 2542053C */  lui        $a1, (0x42250000 >> 16)
    /* 3D8104 004D8104 4C00033C */  lui        $v1, %hi(D_004C52D8)
    /* 3D8108 004D8108 D85265AC */  sw         $a1, %lo(D_004C52D8)($v1)
    /* 3D810C 004D810C C843043C */  lui        $a0, (0x43C80000 >> 16)
    /* 3D8110 004D8110 4C00033C */  lui        $v1, %hi(D_004C52DC)
    /* 3D8114 004D8114 F843053C */  lui        $a1, (0x43F80000 >> 16)
    /* 3D8118 004D8118 DC5264AC */  sw         $a0, %lo(D_004C52DC)($v1)
    /* 3D811C 004D811C B843063C */  lui        $a2, (0x43B80000 >> 16)
    /* 3D8120 004D8120 4C00033C */  lui        $v1, %hi(D_004C5340)
    /* 3D8124 004D8124 4C00043C */  lui        $a0, %hi(D_004C5344)
    /* 3D8128 004D8128 405365AC */  sw         $a1, %lo(D_004C5340)($v1)
    /* 3D812C 004D812C 948380C7 */  lwc1       $f0, %gp_rel(D_004E0A04)($gp)
    /* 3D8130 004D8130 8042053C */  lui        $a1, (0x42800000 >> 16)
    /* 3D8134 004D8134 4C00033C */  lui        $v1, %hi(D_004C5348)
    /* 3D8138 004D8138 485365AC */  sw         $a1, %lo(D_004C5348)($v1)
    /* 3D813C 004D813C 988381C7 */  lwc1       $f1, %gp_rel(D_004E0A08)($gp)
    /* 3D8140 004D8140 4C00033C */  lui        $v1, %hi(D_004C534C)
    /* 3D8144 004D8144 1344053C */  lui        $a1, (0x44130000 >> 16)
    /* 3D8148 004D8148 4C5366AC */  sw         $a2, %lo(D_004C534C)($v1)
    /* 3D814C 004D814C 4C00033C */  lui        $v1, %hi(D_004C5350)
    /* 3D8150 004D8150 D042063C */  lui        $a2, (0x42D00000 >> 16)
    /* 3D8154 004D8154 505365AC */  sw         $a1, %lo(D_004C5350)($v1)
    /* 3D8158 004D8158 445380E4 */  swc1       $f0, %lo(D_004C5344)($a0)
    /* 3D815C 004D815C 4C00033C */  lui        $v1, %hi(D_004C5354)
    /* 3D8160 004D8160 4C00053C */  lui        $a1, %hi(D_004C5358)
    /* 3D8164 004D8164 545366AC */  sw         $a2, %lo(D_004C5354)($v1)
    /* 3D8168 004D8168 4C00043C */  lui        $a0, %hi(D_004C5360)
    /* 3D816C 004D816C 4C00033C */  lui        $v1, %hi(D_004C535C)
    /* 3D8170 004D8170 5C5360E4 */  swc1       $f0, %lo(D_004C535C)($v1)
    /* 3D8174 004D8174 53020324 */  addiu      $v1, $zero, 0x253
    /* 3D8178 004D8178 00008344 */  mtc1       $v1, $f0
    /* 3D817C 004D817C 00000000 */  nop
    /* 3D8180 004D8180 5853A1E4 */  swc1       $f1, %lo(D_004C5358)($a1)
    /* 3D8184 004D8184 20008046 */  cvt.s.w    $f0, $f0
    /* 3D8188 004D8188 4C00033C */  lui        $v1, %hi(D_004C5364)
    /* 3D818C 004D818C 645366AC */  sw         $a2, %lo(D_004C5364)($v1)
    /* 3D8190 004D8190 0800E003 */  jr         $ra
    /* 3D8194 004D8194 605380E4 */   swc1      $f0, %lo(D_004C5360)($a0)
endlabel func_004D8100

.section .ctor, "a"
.balign 4
    .word func_004D8100
