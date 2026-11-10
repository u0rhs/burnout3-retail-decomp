.include "macro.inc"

.set noat
.set noreorder

/* B3HelpBarComponent.cpp's static data and initializer (C source: B3HelpBarComponent_004D7E70.cpp), split out of
   data/game/unit_0031B6A0.rodata.s, sinit.s and data/ctor.ctor.s. */

.section .rodata, "a"
.balign 8
dlabel kHelpBarRecipSize
    .word 0x00000000
    .word 0x00000000
enddlabel kHelpBarRecipSize
dlabel D_004C51F8
    .word 0x00000000
enddlabel D_004C51F8
dlabel D_004C51FC
    .word 0x00000000
enddlabel D_004C51FC
dlabel D_004C5200
    .word 0x00000000
enddlabel D_004C5200
dlabel D_004C5204
    .word 0x00000000
enddlabel D_004C5204

.section .init, "ax"
.balign 16
nonmatching func_004D7E70, 0x44

glabel func_004D7E70
    /* 3D7E70 004D7E70 4C00033C */  lui        $v1, %hi(D_004C51F8)
    /* 3D7E74 004D7E74 003F073C */  lui        $a3, (0x3F000000 >> 16)
    /* 3D7E78 004D7E78 F85160AC */  sw         $zero, %lo(D_004C51F8)($v1)
    /* 3D7E7C 004D7E7C B48381C7 */  lwc1       $f1, %gp_rel(D_004E0A24)($gp)
    /* 3D7E80 004D7E80 4C00033C */  lui        $v1, %hi(D_004C51FC)
    /* 3D7E84 004D7E84 4C00053C */  lui        $a1, %hi(kHelpBarRecipSize)
    /* 3D7E88 004D7E88 FC5167AC */  sw         $a3, %lo(D_004C51FC)($v1)
    /* 3D7E8C 004D7E8C B88380C7 */  lwc1       $f0, %gp_rel(D_004E0A28)($gp)
    /* 3D7E90 004D7E90 803F063C */  lui        $a2, (0x3F800000 >> 16)
    /* 3D7E94 004D7E94 4C00033C */  lui        $v1, %hi(D_004C5200)
    /* 3D7E98 004D7E98 005266AC */  sw         $a2, %lo(D_004C5200)($v1)
    /* 3D7E9C 004D7E9C 4C00043C */  lui        $a0, %hi(kHelpBarRecipSize + 0x4)
    /* 3D7EA0 004D7EA0 4C00033C */  lui        $v1, %hi(D_004C5204)
    /* 3D7EA4 004D7EA4 F051A1E4 */  swc1       $f1, %lo(kHelpBarRecipSize)($a1)
    /* 3D7EA8 004D7EA8 045267AC */  sw         $a3, %lo(D_004C5204)($v1)
    /* 3D7EAC 004D7EAC 0800E003 */  jr         $ra
    /* 3D7EB0 004D7EB0 F45180E4 */   swc1      $f0, %lo(kHelpBarRecipSize + 0x4)($a0)
endlabel func_004D7E70

.section .ctor, "a"
.balign 4
    .word func_004D7E70
