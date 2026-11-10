.include "macro.inc"

.set noat
.set noreorder

/* B3VSelectComponent.cpp's static data and initializer (C source: B3VSelectComponent_004D81A0.cpp), split out of data/game/unit_0031E1A0.rodata.s (its last 8 bytes), data/game/unit_0031FE70.rodata.s (its first 4), sinit_004D81A0.s and data/ctor_004DD8EC.ctor.s. */

.section .rodata, "a"
.balign 8
dlabel D_004C5388
    .word 0x00000000
enddlabel D_004C5388
dlabel D_004C538C
    .word 0x00000000
enddlabel D_004C538C
dlabel D_004C5390
    .word 0x00000000
enddlabel D_004C5390

.section .init, "ax"
.balign 16
nonmatching func_004D81A0, 0x2C

glabel func_004D81A0
    /* 3D81A0 004D81A0 1C8280C7 */  lwc1       $f0, %gp_rel(D_004E088C)($gp)
    /* 3D81A4 004D81A4 8040043C */  lui        $a0, (0x40800000 >> 16)
    /* 3D81A8 004D81A8 00088444 */  mtc1       $a0, $f1
    /* 3D81AC 004D81AC 4C00033C */  lui        $v1, %hi(D_004C5388)
    /* 3D81B0 004D81B0 885364AC */  sw         $a0, %lo(D_004C5388)($v1)
    /* 3D81B4 004D81B4 4C00033C */  lui        $v1, %hi(D_004C538C)
    /* 3D81B8 004D81B8 8C5364AC */  sw         $a0, %lo(D_004C538C)($v1)
    /* 3D81BC 004D81BC 4C00033C */  lui        $v1, %hi(D_004C5390)
    /* 3D81C0 004D81C0 00000146 */  add.s      $f0, $f0, $f1
    /* 3D81C4 004D81C4 0800E003 */  jr         $ra
    /* 3D81C8 004D81C8 905360E4 */   swc1      $f0, %lo(D_004C5390)($v1)
endlabel func_004D81A0

.section .ctor, "a"
.balign 4
    .word func_004D81A0
