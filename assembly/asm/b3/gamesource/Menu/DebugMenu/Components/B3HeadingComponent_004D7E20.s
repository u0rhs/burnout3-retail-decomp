.include "macro.inc"

.set noat
.set noreorder

/* B3HeadingComponent.cpp's static data and initializer (C source: B3HeadingComponent_004D7E20.cpp), split out of data/game/unit_003192F0.rodata.s (0x4C5170-0x4C5190; the rest after it is now unit_003193D0.rodata), sinit.s and data/ctor.ctor.s. */

.section .rodata, "a"
.balign 16
dlabel krHeadingBarBigCurveEffectiveImageSize
    .word 0x00000000
    .word 0x00000000
enddlabel krHeadingBarBigCurveEffectiveImageSize
    .word 0x00000000
    .word 0x00000000
dlabel kHeadingTextBarFillColourScale
    .word 0x00000000
    .word 0x00000000
    .word 0x00000000
    .word 0x00000000
enddlabel kHeadingTextBarFillColourScale

.section .init, "ax"
.balign 16
nonmatching func_004D7E20, 0x48

glabel func_004D7E20
    /* 3D7E20 004D7E20 F0FFBD27 */  addiu      $sp, $sp, -0x10
    /* 3D7E24 004D7E24 0843053C */  lui        $a1, (0x43080000 >> 16)
    /* 3D7E28 004D7E28 4C00033C */  lui        $v1, %hi(krHeadingBarBigCurveEffectiveImageSize)
    /* 3D7E2C 004D7E2C 3043043C */  lui        $a0, (0x43300000 >> 16)
    /* 3D7E30 004D7E30 705165AC */  sw         $a1, %lo(krHeadingBarBigCurveEffectiveImageSize)($v1)
    /* 3D7E34 004D7E34 4C00033C */  lui        $v1, %hi(krHeadingBarBigCurveEffectiveImageSize + 0x4)
    /* 3D7E38 004D7E38 745164AC */  sw         $a0, %lo(krHeadingBarBigCurveEffectiveImageSize + 0x4)($v1)
    /* 3D7E3C 004D7E3C 803F043C */  lui        $a0, (0x3F800000 >> 16)
    /* 3D7E40 004D7E40 003F033C */  lui        $v1, (0x3F000000 >> 16)
    /* 3D7E44 004D7E44 0C00A3AF */  sw         $v1, 0xC($sp)
    /* 3D7E48 004D7E48 0000A4AF */  sw         $a0, 0x0($sp)
    /* 3D7E4C 004D7E4C 4C00033C */  lui        $v1, %hi(kHeadingTextBarFillColourScale)
    /* 3D7E50 004D7E50 0400A4AF */  sw         $a0, 0x4($sp)
    /* 3D7E54 004D7E54 0800A4AF */  sw         $a0, 0x8($sp)
    /* 3D7E58 004D7E58 0000A47B */  lq         $a0, 0x0($sp)
    /* 3D7E5C 004D7E5C 8051647C */  sq         $a0, %lo(kHeadingTextBarFillColourScale)($v1)
    /* 3D7E60 004D7E60 0800E003 */  jr         $ra
    /* 3D7E64 004D7E64 1000BD27 */   addiu     $sp, $sp, 0x10
endlabel func_004D7E20

.section .ctor, "a"
.balign 4
    .word func_004D7E20
