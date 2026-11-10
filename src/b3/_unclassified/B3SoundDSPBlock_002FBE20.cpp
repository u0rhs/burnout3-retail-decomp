// CB3SoundDSPDataBlock::ProcessB2Distortion(short*,short*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundDSPBlock.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (draftAC exact; re-queued (parked 12:26 with func_002FC530's group compile error)).

// CB3SoundDSPDataBlock::ProcessB2Distortion(short*, short*) -- hand-written assembly in retail (draftAC).
// [C] name: config/symbol_addrs_b3names.txt; Revenge STABS: CB4SoundDSPDataBlock::ProcessB2Distortion(RwInt16 *lp16Input,
// RwInt16 *lp16Output), B4SoundDSPBlock.cpp (no code there). [C] retail's body is hand-written: trapping add/addi/sub
// (never emitted by MWCC), explicit `.set noreorder` delay-slot nops, a qfsrv shift register through all eight quads.
// Written as one CodeWarrior asm function definition (Targeting_PlayStation2 "Function-level Inline Assembly"), prologue
// and epilogue included: byte-identical (146 words, draftAC). [G] that Criterion wrote the prologue by hand too (a C
// prologue around an asm {} block is the alternative); a gcc-style asm volatile inside a C body adds a second s-register
// prologue (154 words).
// What it does [L]: a 16-bit sample filter (state field_14/field_18, coefficients field_C/10/34/38..44, Q12 fixed
// point), soft clip to +-0x7FFF per sample, eight samples per quad, 64 samples per 0x80-byte block.

class CB3SoundDSPDataBlock {
public:
    void ProcessB2Distortion(short *lp16Input, short *lp16Output);
};

// 0x002FBE20
asm void CB3SoundDSPDataBlock::ProcessB2Distortion(short *lp16Input, short *lp16Output)
{
    .set noreorder
    .set noat
    addiu	$sp, $sp, -0x70
    daddu	$t9, $a0, $zero
    sq	$s6, 0x60($sp)
    daddu	$t8, $a1, $zero
    sq	$s5, 0x50($sp)
    daddu	$a3, $a2, $zero
    sq	$s4, 0x40($sp)
    sq	$s3, 0x30($sp)
    sq	$s2, 0x20($sp)
    sq	$s1, 0x10($sp)
    sq	$s0, 0x0($sp)
    lw	$s0, 0x14($t9)
    lw	$s1, 0x18($t9)
    lw	$s2, 0xC($t9)
    lw	$s3, 0x10($t9)
    lw	$s4, 0x34($t9)
    lw	$s6, 0x38($t9)
    lw	$v1, 0x3C($t9)
    mult	$v0, $v1, $s6
    mfhi	$v1
    srl	$v0, $v0, 16
    sll	$v1, $v1, 16
    or	$s5, $v0, $v1
    lw	$v1, 0x40($t9)
    mult1	$v0, $v1, $s6
    mfhi1	$v1
    srl	$v0, $v0, 16
    sll	$v1, $v1, 16
    or	$s6, $v0, $v1
    lw	$v0, 0x0($t9)
    lui	$v1, 0x1
    add	$v0, $v0, $v1
    sll	$v0, $v0, 1
    lw	$v1, 0x44($t9)
    sra	$v0, $v0, 4
    sra	$s2, $s2, 4
    sra	$s3, $s3, 4
    sra	$s4, $s4, 4
    sra	$s5, $s5, 4
    sra	$s6, $s6, 4
@L1:
    lq	$t0, 0x0($t8)
    lq	$t1, 0x10($t8)
    lq	$t2, 0x20($t8)
    lq	$t3, 0x30($t8)
    lq	$t4, 0x40($t8)
    lq	$t5, 0x50($t8)
    lq	$t6, 0x60($t8)
    lq	$t7, 0x70($t8)
@L2:
    mult	$a1, $s2, $s0
    sra	$a1, $a1, 12
    add	$s1, $a1, $s1
    andi	$a0, $t0, 0xFFFF
    sll	$a0, $a0, 16
    sra	$a0, $a0, 16
    mult1	$a1, $s3, $s0
    sra	$a1, $a1, 12
    sub	$a0, $a0, $s1
    sub	$a0, $a0, $a1
    mult	$a0, $a0, $s2
    sra	$a0, $a0, 12
    add	$s0, $a0, $s0
    mult	$a0, $s1, $v0
    sra	$a0, $a0, 12
    lui	$a1, 0x1
    lui	$a2, 0x2
    add	$a1, $a1, $a0
    sll	$a1, $a1, 14
    sra	$a1, $a1, 31
    xor	$a0, $a0, $a1
    and	$a1, $a2, $a1
    xor	$a0, $a0, $a1
    sll	$a0, $a0, 14
    sra	$a0, $a0, 14
    mult	$a0, $a0, $s4
    sra	$a0, $a0, 12
    addi	$a1, $zero, 0x7FFF
    lui	$a2, 0xffff
    ori	$a2, $a2, 0x8000
    pminw	$a0, $a0, $a1
    pmaxw	$a0, $a0, $a2
    mult	$a0, $s5, $a0
    sra	$a0, $a0, 12
    andi	$a1, $t0, 0xFFFF
    sll	$a1, $a1, 16
    sra	$a1, $a1, 16
    mult1	$a1, $a1, $s6
    sra	$a1, $a1, 12
    add	$a0, $a1, $a0
    addi	$a1, $zero, 0x7FFF
    lui	$a2, 0xffff
    ori	$a2, $a2, 0x8000
    pminw	$a0, $a0, $a1
    pmaxw	$a0, $a0, $a2
    ori	$at, $zero, 0xFFFF
    addu	$a1, $zero, $at
    pcpyh	$a1, $a1
    pextlh	$a1, $a1, $a1
    paddh	$a2, $a1, $zero
    xori	$a2, $a2, 0xFFFF
    pand	$t0, $t0, $a2
    pxor	$a2, $a2, $a1
    pand	$a0, $a2, $a0
    por	$t0, $t0, $a0
    mtsab	$zero, 0x2
    qfsrv	$t0, $t0, $t0
    addi	$v1, $v1, -0x1
    andi	$a0, $v1, 0x7
    bnez	$a0, @L2
    nop
    nop
    paddh	$a0, $t0, $zero
    paddh	$t0, $t1, $zero
    paddh	$t1, $t2, $zero
    paddh	$t2, $t3, $zero
    paddh	$t3, $t4, $zero
    paddh	$t4, $t5, $zero
    paddh	$t5, $t6, $zero
    paddh	$t6, $t7, $zero
    paddh	$t7, $a0, $zero
    andi	$a0, $v1, 0x3F
    bnez	$a0, @L2
    nop
    nop
    sq	$t0, 0x0($a3)
    sq	$t1, 0x10($a3)
    sq	$t2, 0x20($a3)
    sq	$t3, 0x30($a3)
    sq	$t4, 0x40($a3)
    sq	$t5, 0x50($a3)
    sq	$t6, 0x60($a3)
    sq	$t7, 0x70($a3)
    addi	$t8, $t8, 0x80
    bnez	$v1, @L1
    addi	$a3, $a3, 0x80
    nop
    sw	$s0, 0x14($t9)
    sw	$s1, 0x18($t9)
    lq	$s6, 0x60($sp)
    lq	$s5, 0x50($sp)
    lq	$s4, 0x40($sp)
    lq	$s3, 0x30($sp)
    lq	$s2, 0x20($sp)
    lq	$s1, 0x10($sp)
    lq	$s0, 0x0($sp)
    jr	$ra
    addiu	$sp, $sp, 0x70
    .set at
    .set reorder
}
