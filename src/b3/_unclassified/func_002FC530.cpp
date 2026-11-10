// Hand-written; the lifter refused it (asm1's hand-written asm (187/187, bytes identical); re-queued by tidy1 after diff_vs_retail.py learned the branch-likely zero compares (bgtzl label vs address text)).

extern "C" void func_002FC820(void);
extern "C" void Process__20CB3SoundDSPDataBlockFPsPs(void *, void *);
// [C] hand-written asm: trapping addi at 0x002FC610,0x002FC614,0x002FC61C (copy loops, x4) and ei at 0x002FC7EC
extern "C" void isceSifSetDma(void);
// func_002FC530 -- hand-written asm; see evidence below
// [C] hand-written asm: trapping add/addi at the addi/ei instructions marked handwritten by splat

// 0x002FC530
extern "C" asm void func_002FC530(void*, void*)
{
    .set noreorder
    .set noat
    addiu      $sp, $sp, -0xA0
    lui        $a3, 0x3000
    sd         $ra, 0x80($sp)
    sq         $s7, 0x70($sp)
    sq         $s6, 0x60($sp)
    sq         $s5, 0x50($sp)
    sq         $s4, 0x40($sp)
    sq         $s3, 0x30($sp)
    daddu      $s4, $a1, $zero
    sq         $s2, 0x20($sp)
    addiu      $v1, $s4, 0x240
    sq         $s1, 0x10($sp)
    or         $a1, $v1, $a3
    sq         $s0, 0x0($sp)
    addiu      $v1, $s4, 0x840
    lw         $s5, 0xC($a0)
    or         $s3, $v1, $a3
    addiu      $v0, $s4, 0x640
    addiu      $a2, $s4, 0x1040
    or         $s6, $v0, $a3
    or         $s7, $a2, $a3
    addiu      $v0, $s4, 0xA40
    addiu      $a2, $s4, 0x1640
    or         $s0, $a2, $a3
    addiu      $v1, $s4, 0xE40
    or         $v0, $v0, $a3
    addiu      $a2, $zero, 0x1
    addiu      $a0, $s4, 0xC40
    or         $s2, $a0, $a3
    or         $a0, $v1, $a3
    addiu      $v1, $s4, 0x1240
    or         $s1, $v1, $a3
    addiu      $v1, $s4, 0x1440
    or         $v1, $v1, $a3
    andi       $a3, $s5, 0x1
    bne        $a3, $a2, @L002FC6C0
    nop
    addiu      $s5, $s5, -0x1
    addiu      $v1, $zero, 0x200
    daddu      $a2, $s1, $zero
@L002FC5D0:
    lq         $t0, 0x0($a2)
    lq         $t1, 0x10($a2)
    lq         $t2, 0x20($a2)
    lq         $t3, 0x30($a2)
    lq         $t4, 0x40($a2)
    lq         $t5, 0x50($a2)
    lq         $t6, 0x60($a2)
    lq         $t7, 0x70($a2)
    sq         $t0, 0x0($v0)
    sq         $t1, 0x10($v0)
    sq         $t2, 0x20($v0)
    sq         $t3, 0x30($v0)
    sq         $t4, 0x40($v0)
    sq         $t5, 0x50($v0)
    sq         $t6, 0x60($v0)
    sq         $t7, 0x70($v0)
    addi       $v1, $v1, -0x80
    addi       $v0, $v0, 0x80
    bgtzl      $v1, @L002FC5D0
    addi      $a2, $a2, 0x80
    nop
    addiu      $v0, $zero, 0x200
    daddu      $v1, $s0, $zero
@L002FC62C:
    lq         $t0, 0x0($v1)
    lq         $t1, 0x10($v1)
    lq         $t2, 0x20($v1)
    lq         $t3, 0x30($v1)
    lq         $t4, 0x40($v1)
    lq         $t5, 0x50($v1)
    lq         $t6, 0x60($v1)
    lq         $t7, 0x70($v1)
    sq         $t0, 0x0($a0)
    sq         $t1, 0x10($a0)
    sq         $t2, 0x20($a0)
    sq         $t3, 0x30($a0)
    sq         $t4, 0x40($a0)
    sq         $t5, 0x50($a0)
    sq         $t6, 0x60($a0)
    sq         $t7, 0x70($a0)
    addi       $v0, $v0, -0x80
    addi       $a0, $a0, 0x80
    bgtzl      $v0, @L002FC62C
    addi      $v1, $v1, 0x80
    nop
    daddu      $a0, $s4, $zero
    jal        Process__20CB3SoundDSPDataBlockFPsPs
    daddu     $a2, $s1, $zero
    daddu      $a1, $s6, $zero
    addiu      $a0, $s4, 0x110
    jal        Process__20CB3SoundDSPDataBlockFPsPs
    daddu     $a2, $s0, $zero
    lw         $a3, 0x1848($s4)
    daddu      $a1, $s1, $zero
    lw         $t0, 0x1840($s4)
    daddu      $a2, $s0, $zero
    lw         $t1, 0x1844($s4)
    jal        func_002FC820
    addiu     $a0, $zero, 0x100
    b          @L002FC7B8
    sw        $s3, 0x90($sp)
@L002FC6C0:
    addiu      $v0, $zero, 0x200
    daddu      $a0, $s3, $zero
    daddu      $a2, $s7, $zero
@L002FC6CC:
    lq         $t0, 0x0($a0)
    lq         $t1, 0x10($a0)
    lq         $t2, 0x20($a0)
    lq         $t3, 0x30($a0)
    lq         $t4, 0x40($a0)
    lq         $t5, 0x50($a0)
    lq         $t6, 0x60($a0)
    lq         $t7, 0x70($a0)
    sq         $t0, 0x0($a2)
    sq         $t1, 0x10($a2)
    sq         $t2, 0x20($a2)
    sq         $t3, 0x30($a2)
    sq         $t4, 0x40($a2)
    sq         $t5, 0x50($a2)
    sq         $t6, 0x60($a2)
    sq         $t7, 0x70($a2)
    addi       $v0, $v0, -0x80
    addi       $a2, $a2, 0x80
    bgtzl      $v0, @L002FC6CC
    addi      $a0, $a0, 0x80
    nop
    addiu      $v0, $zero, 0x200
    daddu      $a0, $s2, $zero
@L002FC728:
    lq         $t0, 0x0($a0)
    lq         $t1, 0x10($a0)
    lq         $t2, 0x20($a0)
    lq         $t3, 0x30($a0)
    lq         $t4, 0x40($a0)
    lq         $t5, 0x50($a0)
    lq         $t6, 0x60($a0)
    lq         $t7, 0x70($a0)
    sq         $t0, 0x0($v1)
    sq         $t1, 0x10($v1)
    sq         $t2, 0x20($v1)
    sq         $t3, 0x30($v1)
    sq         $t4, 0x40($v1)
    sq         $t5, 0x50($v1)
    sq         $t6, 0x60($v1)
    sq         $t7, 0x70($v1)
    addi       $v0, $v0, -0x80
    addi       $v1, $v1, 0x80
    bgtzl      $v0, @L002FC728
    addi      $a0, $a0, 0x80
    nop
    daddu      $a0, $s4, $zero
    jal        Process__20CB3SoundDSPDataBlockFPsPs
    daddu     $a2, $s3, $zero
    daddu      $a1, $s6, $zero
    addiu      $a0, $s4, 0x110
    jal        Process__20CB3SoundDSPDataBlockFPsPs
    daddu     $a2, $s2, $zero
    lw         $a3, 0x1848($s4)
    daddu      $a1, $s3, $zero
    lw         $t0, 0x1840($s4)
    daddu      $a2, $s2, $zero
    lw         $t1, 0x1844($s4)
    jal        func_002FC820
    addiu     $a0, $zero, 0x100
    sw         $s7, 0x90($sp)
@L002FC7B8:
    lw         $a2, 0x90($sp)
    lui        $v0, 0x2FFF
    ori        $v1, $v0, 0xFFFF
    addiu      $a0, $sp, 0x90
    addiu      $v0, $zero, 0x800
    addiu      $a1, $zero, 0x1
    sw         $v0, 0x98($sp)
    sw         $s5, 0x94($sp)
    sw         $zero, 0x9C($sp)
    and        $v0, $a2, $v1
    jal        isceSifSetDma
    sw        $v0, 0x90($sp)
    sync
    ei
    ld         $ra, 0x80($sp)
    lq         $s7, 0x70($sp)
    lq         $s6, 0x60($sp)
    lq         $s5, 0x50($sp)
    lq         $s4, 0x40($sp)
    lq         $s3, 0x30($sp)
    lq         $s2, 0x20($sp)
    lq         $s1, 0x10($sp)
    lq         $s0, 0x0($sp)
    jr         $ra
    addiu     $sp, $sp, 0xA0
    .set at
    .set reorder
}
