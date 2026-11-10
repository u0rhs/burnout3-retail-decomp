.include "macro.inc"

.set noat
.set noreorder

/* B3MenuPageManager.cpp's static data and initializer (C source: B3MenuPageManager_004D7120.cpp), split out of data/game/unit_0030E340.rodata.s (0x4C4AC0-0x4C4AD0; what followed is now unit_0030D3B0.rodata), sinit.s and data/ctor.ctor.s. */

.section .rodata, "a"
.balign 16
dlabel D_004C4AC0
    .word 0x00000000
    .word 0x00000000
    .word 0x00000000
    .word 0x00000000
enddlabel D_004C4AC0

.section .init, "ax"
.balign 16
nonmatching func_004D7120, 0x30

glabel func_004D7120
    /* 3D7120 004D7120 F0FFBD27 */  addiu      $sp, $sp, -0x10
    /* 3D7124 004D7124 803F033C */  lui        $v1, (0x3F800000 >> 16)
    /* 3D7128 004D7128 648080C7 */  lwc1       $f0, %gp_rel(D_004E06D4)($gp)
    /* 3D712C 004D712C 0C00A3AF */  sw         $v1, 0xC($sp)
    /* 3D7130 004D7130 4C00033C */  lui        $v1, %hi(D_004C4AC0)
    /* 3D7134 004D7134 0000A0E7 */  swc1       $f0, 0x0($sp)
    /* 3D7138 004D7138 0400A0E7 */  swc1       $f0, 0x4($sp)
    /* 3D713C 004D713C 0800A0E7 */  swc1       $f0, 0x8($sp)
    /* 3D7140 004D7140 0000A47B */  lq         $a0, 0x0($sp)
    /* 3D7144 004D7144 C04A647C */  sq         $a0, %lo(D_004C4AC0)($v1)
    /* 3D7148 004D7148 0800E003 */  jr         $ra
    /* 3D714C 004D714C 1000BD27 */   addiu     $sp, $sp, 0x10
endlabel func_004D7120

.section .ctor, "a"
.balign 4
    .word func_004D7120
