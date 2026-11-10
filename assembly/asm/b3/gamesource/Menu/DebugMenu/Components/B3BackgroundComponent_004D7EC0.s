.include "macro.inc"

.set noat
.set noreorder

/* B3BackgroundComponent.cpp's static data and initializer (C source: B3BackgroundComponent_004D7EC0.cpp), split out
   of data/game/unit_0031CDA0.rodata.s (0x4C5210-0x4C52A0), data/game/unit_0031CDA0.bss.s (all of it),
   sinit_004D7EC0.s and data/ctor_004DD8E4.ctor.s. */

.section .rodata, "a"
.balign 16
dlabel D_004C5210
    .word 0x00000000
    .word 0x00000000
enddlabel D_004C5210
dlabel D_004C5218
    .word 0x00000000
    .word 0x00000000
enddlabel D_004C5218
dlabel D_004C5220
    .word 0x00000000
    .word 0x00000000
enddlabel D_004C5220
dlabel D_004C5228
    .word 0x00000000
    .word 0x00000000
enddlabel D_004C5228
dlabel D_004C5230
    .word 0x00000000
    .word 0x00000000
    .word 0x00000000
    .word 0x00000000
enddlabel D_004C5230
dlabel kBackgroundBorderColourScale
    .word 0x00000000
    .word 0x00000000
    .word 0x00000000
    .word 0x00000000
enddlabel kBackgroundBorderColourScale
dlabel D_004C5250
    .word 0x00000000
    .word 0x00000000
    .word 0x00000000
    .word 0x00000000
enddlabel D_004C5250
dlabel kB3DNASImageBackgroundPos
    .word 0x00000000
    .word 0x00000000
enddlabel kB3DNASImageBackgroundPos
dlabel kB3DNASImageBackgroundHandle
    .word 0x00000000
    .word 0x00000000
enddlabel kB3DNASImageBackgroundHandle
dlabel kB3DNASImageBackgroundSize
    .word 0x00000000
    .word 0x00000000
enddlabel kB3DNASImageBackgroundSize
dlabel kB3DNASImageTextPos
    .word 0x00000000
    .word 0x00000000
enddlabel kB3DNASImageTextPos
dlabel kB3DNASImageBTextHandle
    .word 0x00000000
    .word 0x00000000
enddlabel kB3DNASImageBTextHandle
dlabel kB3DNASImagePos
    .word 0x00000000
    .word 0x00000000
enddlabel kB3DNASImagePos
dlabel kB3DNASImageHandle
    .word 0x00000000
    .word 0x00000000
enddlabel kB3DNASImageHandle
dlabel kB3DNASImageSize
    .word 0x00000000
    .word 0x00000000
enddlabel kB3DNASImageSize

.section .bss, "wa"
.balign 16
dlabel D_01EA3190
    .space 0x08
enddlabel D_01EA3190
dlabel D_01EA3198
    .space 0x08
enddlabel D_01EA3198
dlabel D_01EA31A0
    .space 0x08
enddlabel D_01EA31A0
dlabel D_01EA31A8
    .space 0x08
enddlabel D_01EA31A8
dlabel D_01EA31B0
    .space 0x08
enddlabel D_01EA31B0
dlabel D_01EA31B8
    .space 0x08
enddlabel D_01EA31B8

.section .init, "ax"
.balign 16
nonmatching func_004D7EC0, 0x23C

glabel func_004D7EC0
    /* 3D7EC0 004D7EC0 C0FFBD27 */  addiu      $sp, $sp, -0x40
    /* 3D7EC4 004D7EC4 2042023C */  lui        $v0, (0x42200000 >> 16)
    /* 3D7EC8 004D7EC8 00708244 */  mtc1       $v0, $f14
    /* 3D7ECC 004D7ECC EA01043C */  lui        $a0, %hi(D_01EA3190)
    /* 3D7ED0 004D7ED0 00608044 */  mtc1       $zero, $f12
    /* 3D7ED4 004D7ED4 0000BFFF */  sd         $ra, 0x0($sp)
    /* 3D7ED8 004D7ED8 8040023C */  lui        $v0, (0x40800000 >> 16)
    /* 3D7EDC 004D7EDC 90318424 */  addiu      $a0, $a0, %lo(D_01EA3190)
    /* 3D7EE0 004D7EE0 00788244 */  mtc1       $v0, $f15
    /* 3D7EE4 004D7EE4 2D280000 */  daddu      $a1, $zero, $zero
    /* 3D7EE8 004D7EE8 8042023C */  lui        $v0, (0x42800000 >> 16)
    /* 3D7EEC 004D7EEC 00808244 */  mtc1       $v0, $f16
    /* 3D7EF0 004D7EF0 0042023C */  lui        $v0, (0x42000000 >> 16)
    /* 3D7EF4 004D7EF4 00888244 */  mtc1       $v0, $f17
    /* 3D7EF8 004D7EF8 E8C40D0C */  jal        _CalculateUV__15CB3MenuImageUVsFffffffUi
    /* 3D7EFC 004D7EFC 46630046 */   mov.s     $f13, $f12
    /* 3D7F00 004D7F00 D041023C */  lui        $v0, (0x41D00000 >> 16)
    /* 3D7F04 004D7F04 EA01043C */  lui        $a0, %hi(D_01EA31A0)
    /* 3D7F08 004D7F08 00688244 */  mtc1       $v0, $f13
    /* 3D7F0C 004D7F0C A0318424 */  addiu      $a0, $a0, %lo(D_01EA31A0)
    /* 3D7F10 004D7F10 00608044 */  mtc1       $zero, $f12
    /* 3D7F14 004D7F14 2042023C */  lui        $v0, (0x42200000 >> 16)
    /* 3D7F18 004D7F18 00708244 */  mtc1       $v0, $f14
    /* 3D7F1C 004D7F1C 8040023C */  lui        $v0, (0x40800000 >> 16)
    /* 3D7F20 004D7F20 00788244 */  mtc1       $v0, $f15
    /* 3D7F24 004D7F24 8042023C */  lui        $v0, (0x42800000 >> 16)
    /* 3D7F28 004D7F28 00808244 */  mtc1       $v0, $f16
    /* 3D7F2C 004D7F2C 0042023C */  lui        $v0, (0x42000000 >> 16)
    /* 3D7F30 004D7F30 00888244 */  mtc1       $v0, $f17
    /* 3D7F34 004D7F34 E8C40D0C */  jal        _CalculateUV__15CB3MenuImageUVsFffffffUi
    /* 3D7F38 004D7F38 2D280000 */   daddu     $a1, $zero, $zero
    /* 3D7F3C 004D7F3C 8040023C */  lui        $v0, (0x40800000 >> 16)
    /* 3D7F40 004D7F40 4C00043C */  lui        $a0, %hi(D_004C5210)
    /* 3D7F44 004D7F44 00688244 */  mtc1       $v0, $f13
    /* 3D7F48 004D7F48 10528424 */  addiu      $a0, $a0, %lo(D_004C5210)
    /* 3D7F4C 004D7F4C 00608044 */  mtc1       $zero, $f12
    /* 3D7F50 004D7F50 2042023C */  lui        $v0, (0x42200000 >> 16)
    /* 3D7F54 004D7F54 00708244 */  mtc1       $v0, $f14
    /* 3D7F58 004D7F58 0040023C */  lui        $v0, (0x40000000 >> 16)
    /* 3D7F5C 004D7F5C 00788244 */  mtc1       $v0, $f15
    /* 3D7F60 004D7F60 8042023C */  lui        $v0, (0x42800000 >> 16)
    /* 3D7F64 004D7F64 00808244 */  mtc1       $v0, $f16
    /* 3D7F68 004D7F68 0042023C */  lui        $v0, (0x42000000 >> 16)
    /* 3D7F6C 004D7F6C 00888244 */  mtc1       $v0, $f17
    /* 3D7F70 004D7F70 E8C40D0C */  jal        _CalculateUV__15CB3MenuImageUVsFffffffUi
    /* 3D7F74 004D7F74 2D280000 */   daddu     $a1, $zero, $zero
    /* 3D7F78 004D7F78 C041023C */  lui        $v0, (0x41C00000 >> 16)
    /* 3D7F7C 004D7F7C EA01043C */  lui        $a0, %hi(D_01EA31B0)
    /* 3D7F80 004D7F80 00688244 */  mtc1       $v0, $f13
    /* 3D7F84 004D7F84 B0318424 */  addiu      $a0, $a0, %lo(D_01EA31B0)
    /* 3D7F88 004D7F88 00608044 */  mtc1       $zero, $f12
    /* 3D7F8C 004D7F8C 2042023C */  lui        $v0, (0x42200000 >> 16)
    /* 3D7F90 004D7F90 00708244 */  mtc1       $v0, $f14
    /* 3D7F94 004D7F94 0040023C */  lui        $v0, (0x40000000 >> 16)
    /* 3D7F98 004D7F98 00788244 */  mtc1       $v0, $f15
    /* 3D7F9C 004D7F9C 8042023C */  lui        $v0, (0x42800000 >> 16)
    /* 3D7FA0 004D7FA0 00808244 */  mtc1       $v0, $f16
    /* 3D7FA4 004D7FA4 0042023C */  lui        $v0, (0x42000000 >> 16)
    /* 3D7FA8 004D7FA8 00888244 */  mtc1       $v0, $f17
    /* 3D7FAC 004D7FAC E8C40D0C */  jal        _CalculateUV__15CB3MenuImageUVsFffffffUi
    /* 3D7FB0 004D7FB0 2D280000 */   daddu     $a1, $zero, $zero
    /* 3D7FB4 004D7FB4 C040023C */  lui        $v0, (0x40C00000 >> 16)
    /* 3D7FB8 004D7FB8 4C00043C */  lui        $a0, %hi(D_004C5220)
    /* 3D7FBC 004D7FBC 00688244 */  mtc1       $v0, $f13
    /* 3D7FC0 004D7FC0 20528424 */  addiu      $a0, $a0, %lo(D_004C5220)
    /* 3D7FC4 004D7FC4 00608044 */  mtc1       $zero, $f12
    /* 3D7FC8 004D7FC8 2042023C */  lui        $v0, (0x42200000 >> 16)
    /* 3D7FCC 004D7FCC 00708244 */  mtc1       $v0, $f14
    /* 3D7FD0 004D7FD0 9041023C */  lui        $v0, (0x41900000 >> 16)
    /* 3D7FD4 004D7FD4 00788244 */  mtc1       $v0, $f15
    /* 3D7FD8 004D7FD8 8042023C */  lui        $v0, (0x42800000 >> 16)
    /* 3D7FDC 004D7FDC 00808244 */  mtc1       $v0, $f16
    /* 3D7FE0 004D7FE0 0042023C */  lui        $v0, (0x42000000 >> 16)
    /* 3D7FE4 004D7FE4 00888244 */  mtc1       $v0, $f17
    /* 3D7FE8 004D7FE8 E8C40D0C */  jal        _CalculateUV__15CB3MenuImageUVsFffffffUi
    /* 3D7FEC 004D7FEC 2D280000 */   daddu     $a1, $zero, $zero
    /* 3D7FF0 004D7FF0 8242053C */  lui        $a1, (0x42820000 >> 16)
    /* 3D7FF4 004D7FF4 4C00043C */  lui        $a0, %hi(kB3DNASImageBackgroundPos)
    /* 3D7FF8 004D7FF8 605285AC */  sw         $a1, %lo(kB3DNASImageBackgroundPos)($a0)
    /* 3D7FFC 004D7FFC 803F093C */  lui        $t1, (0x3F800000 >> 16)
    /* 3D8000 004D8000 C242053C */  lui        $a1, (0x42C20000 >> 16)
    /* 3D8004 004D8004 4C00043C */  lui        $a0, %hi(kB3DNASImageBackgroundPos + 0x4)
    /* 3D8008 004D8008 645285AC */  sw         $a1, %lo(kB3DNASImageBackgroundPos + 0x4)($a0)
    /* 3D800C 004D800C 803E0A3C */  lui        $t2, (0x3E800000 >> 16)
    /* 3D8010 004D8010 4C00043C */  lui        $a0, %hi(kB3DNASImageBackgroundHandle)
    /* 3D8014 004D8014 003F033C */  lui        $v1, (0x3F000000 >> 16)
    /* 3D8018 004D8018 685280AC */  sw         $zero, %lo(kB3DNASImageBackgroundHandle)($a0)
    /* 3D801C 004D801C 0044053C */  lui        $a1, (0x44000000 >> 16)
    /* 3D8020 004D8020 4C00043C */  lui        $a0, %hi(kB3DNASImageBackgroundHandle + 0x4)
    /* 3D8024 004D8024 3000A9AF */  sw         $t1, 0x30($sp)
    /* 3D8028 004D8028 6C5280AC */  sw         $zero, %lo(kB3DNASImageBackgroundHandle + 0x4)($a0)
    /* 3D802C 004D802C 4C00083C */  lui        $t0, %hi(D_004C5230)
    /* 3D8030 004D8030 4C00043C */  lui        $a0, %hi(kB3DNASImageBackgroundSize)
    /* 3D8034 004D8034 3400A9AF */  sw         $t1, 0x34($sp)
    /* 3D8038 004D8038 705285AC */  sw         $a1, %lo(kB3DNASImageBackgroundSize)($a0)
    /* 3D803C 004D803C 4C00073C */  lui        $a3, %hi(kBackgroundBorderColourScale)
    /* 3D8040 004D8040 4043053C */  lui        $a1, (0x43400000 >> 16)
    /* 3D8044 004D8044 4C00043C */  lui        $a0, %hi(kB3DNASImageBackgroundSize + 0x4)
    /* 3D8048 004D8048 745285AC */  sw         $a1, %lo(kB3DNASImageBackgroundSize + 0x4)($a0)
    /* 3D804C 004D804C 4C00063C */  lui        $a2, %hi(D_004C5250)
    /* 3D8050 004D8050 3800A9AF */  sw         $t1, 0x38($sp)
    /* 3D8054 004D8054 4C00043C */  lui        $a0, %hi(kB3DNASImageTextPos)
    /* 3D8058 004D8058 2000A9AF */  sw         $t1, 0x20($sp)
    /* 3D805C 004D805C 8A43053C */  lui        $a1, (0x438A0000 >> 16)
    /* 3D8060 004D8060 2400A9AF */  sw         $t1, 0x24($sp)
    /* 3D8064 004D8064 2800A9AF */  sw         $t1, 0x28($sp)
    /* 3D8068 004D8068 2C00A9AF */  sw         $t1, 0x2C($sp)
    /* 3D806C 004D806C 1C00A9AF */  sw         $t1, 0x1C($sp)
    /* 3D8070 004D8070 A043093C */  lui        $t1, (0x43A00000 >> 16)
    /* 3D8074 004D8074 3C00A3AF */  sw         $v1, 0x3C($sp)
    /* 3D8078 004D8078 785289AC */  sw         $t1, %lo(kB3DNASImageTextPos)($a0)
    /* 3D807C 004D807C 4C00043C */  lui        $a0, %hi(kB3DNASImageTextPos + 0x4)
    /* 3D8080 004D8080 1000AAAF */  sw         $t2, 0x10($sp)
    /* 3D8084 004D8084 7C5285AC */  sw         $a1, %lo(kB3DNASImageTextPos + 0x4)($a0)
    /* 3D8088 004D8088 4C00043C */  lui        $a0, %hi(kB3DNASImageBTextHandle)
    /* 3D808C 004D808C 4C00053C */  lui        $a1, %hi(kB3DNASImageBTextHandle + 0x4)
    /* 3D8090 004D8090 805283AC */  sw         $v1, %lo(kB3DNASImageBTextHandle)($a0)
    /* 3D8094 004D8094 4C00043C */  lui        $a0, %hi(kB3DNASImagePos)
    /* 3D8098 004D8098 8452A3AC */  sw         $v1, %lo(kB3DNASImageBTextHandle + 0x4)($a1)
    /* 3D809C 004D809C 885289AC */  sw         $t1, %lo(kB3DNASImagePos)($a0)
    /* 3D80A0 004D80A0 3043093C */  lui        $t1, (0x43300000 >> 16)
    /* 3D80A4 004D80A4 4C00043C */  lui        $a0, %hi(kB3DNASImagePos + 0x4)
    /* 3D80A8 004D80A8 8C5289AC */  sw         $t1, %lo(kB3DNASImagePos + 0x4)($a0)
    /* 3D80AC 004D80AC 4C00043C */  lui        $a0, %hi(kB3DNASImageHandle)
    /* 3D80B0 004D80B0 3000A57B */  lq         $a1, 0x30($sp)
    /* 3D80B4 004D80B4 905283AC */  sw         $v1, %lo(kB3DNASImageHandle)($a0)
    /* 3D80B8 004D80B8 4C00043C */  lui        $a0, %hi(kB3DNASImageHandle + 0x4)
    /* 3D80BC 004D80BC 1400AAAF */  sw         $t2, 0x14($sp)
    /* 3D80C0 004D80C0 945283AC */  sw         $v1, %lo(kB3DNASImageHandle + 0x4)($a0)
    /* 3D80C4 004D80C4 0043043C */  lui        $a0, (0x43000000 >> 16)
    /* 3D80C8 004D80C8 4C00033C */  lui        $v1, %hi(kB3DNASImageSize)
    /* 3D80CC 004D80CC 985264AC */  sw         $a0, %lo(kB3DNASImageSize)($v1)
    /* 3D80D0 004D80D0 4C00033C */  lui        $v1, %hi(kB3DNASImageSize + 0x4)
    /* 3D80D4 004D80D4 1800AAAF */  sw         $t2, 0x18($sp)
    /* 3D80D8 004D80D8 9C5264AC */  sw         $a0, %lo(kB3DNASImageSize + 0x4)($v1)
    /* 3D80DC 004D80DC 2000A47B */  lq         $a0, 0x20($sp)
    /* 3D80E0 004D80E0 1000A37B */  lq         $v1, 0x10($sp)
    /* 3D80E4 004D80E4 3052057D */  sq         $a1, %lo(D_004C5230)($t0)
    /* 3D80E8 004D80E8 4052E47C */  sq         $a0, %lo(kBackgroundBorderColourScale)($a3)
    /* 3D80EC 004D80EC 5052C37C */  sq         $v1, %lo(D_004C5250)($a2)
    /* 3D80F0 004D80F0 0000BFDF */  ld         $ra, 0x0($sp)
    /* 3D80F4 004D80F4 0800E003 */  jr         $ra
    /* 3D80F8 004D80F8 4000BD27 */   addiu     $sp, $sp, 0x40
endlabel func_004D7EC0

.section .ctor, "a"
.balign 4
    .word func_004D7EC0
