// B3SoundDistPS2.cpp -- translation unit regrouped by tools/tu_merge.py from 4 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 4 function(s) named in research/retail_names.csv -> B3SoundDistPS2.cpp.
// Area: src/b3/gamesource/Sound/Dsp, [L] Revenge (SLUS_212.42) GameSource/Sound/Dsp/B4SoundDistPS2.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3SoundDistortion.h"
#include "b3/classes/UnkStruct_D_0064ED5C.h"

struct UnkStruct_002FCF00_3;
struct UnkStruct_002FCFC0_4;

struct UnkStruct_002FCF00_3 {
    int field_0;
};

struct UnkStruct_002FCFC0_4 {
    int field_0;
};

extern UnkStruct_D_0064ED5C D_0064ED5C;
extern "C" int sceSifCheckStatRpc(void *);
extern "C" void sceSifCallRpc(void *, int, int, void *, int, int, int, int, int);

// Hand-written; the lifter refused it (whole function hand-written asm).
// 0x002FC820
extern "C" asm void func_002FC820(int, short*, short*, int, int, int)
{
    .set noreorder
    .set noat
    addiu      $sp, $sp, -0x80
    lui        $v0, 0x3000
    sq         $s7, 0x70($sp)
    or         $a1, $a1, $v0
    sq         $s6, 0x60($sp)
    or         $a2, $a2, $v0
    sq         $s5, 0x50($sp)
    sra        $a3, $t0, 1
    sq         $s4, 0x40($sp)
    sq         $s3, 0x30($sp)
    sq         $s2, 0x20($sp)
    sq         $s1, 0x10($sp)
    bgez       $t0, @L002FC860
    sq        $s0, 0x0($sp)
    addiu      $v0, $t0, 0x1
    sra        $a3, $v0, 1
@L002FC860:
    bgez       $t1, @L002FC870
    sra       $v1, $t1, 1
    addiu      $v0, $t1, 0x1
    sra        $v1, $v0, 1
@L002FC870:
    ori        $at, $zero, 0x8000
    slt        $at, $a3, $at
    bnez       $at, @L002FC884
    addiu     $v0, $zero, 0x7FFF
    daddu      $a3, $v0, $zero
@L002FC884:
    ori        $at, $zero, 0x8000
    slt        $at, $v1, $at
    bnez       $at, @L002FC898
    nop
    addiu      $v1, $zero, 0x7FFF
@L002FC898:
    addiu      $v0, $zero, 0x7FFF
    daddu      $s3, $a2, $zero
    daddu      $s4, $a1, $zero
    daddu      $s5, $a0, $zero
    pcpyld     $s2, $v0, $v0
    mtsah      $zero, 0x2
    qfsrv      $t0, $s2, $s2
    paddw      $s2, $t0, $s2
    pcpyld     $s1, $a3, $a3
    mtsah      $zero, 0x2
    qfsrv      $t0, $s1, $s1
    paddw      $s1, $t0, $s1
    pcpyld     $s0, $v1, $v1
    mtsah      $zero, 0x2
    qfsrv      $t0, $s0, $s0
    paddw      $s0, $t0, $s0
@L002FC8D8:
    lq         $t0, 0x0($s4)
    lq         $a0, 0x10($s4)
    lq         $a1, 0x20($s4)
    lq         $a2, 0x30($s4)
    lq         $a3, 0x40($s4)
    lq         $t8, 0x50($s4)
    lq         $t9, 0x60($s4)
    lq         $v0, 0x70($s4)
    lq         $t1, 0x0($s3)
    lq         $v1, 0x10($s3)
    lq         $t4, 0x20($s3)
    lq         $t5, 0x30($s3)
    lq         $t6, 0x40($s3)
    lq         $t7, 0x50($s3)
    lq         $s6, 0x60($s3)
    lq         $s7, 0x70($s3)
@L002FC918:
    pextlh     $t2, $t1, $zero
    pextuh     $t3, $t1, $zero
    pextuh     $t1, $t0, $zero
    pextlh     $t0, $t0, $zero
    psraw      $t0, $t0, 16
    psraw      $t1, $t1, 16
    psraw      $t2, $t2, 16
    psraw      $t3, $t3, 16
    paddw      $t0, $t0, $t2
    paddw      $t1, $t1, $t3
    psraw      $t0, $t0, 1
    psraw      $t1, $t1, 1
    pmulth     $t0, $t0, $s2
    pmulth     $t1, $t1, $s2
    psraw      $t0, $t0, 15
    psraw      $t1, $t1, 15
    paddw      $t2, $t0, $zero
    paddw      $t3, $t1, $zero
    pmulth     $t0, $t0, $s1
    pmulth     $t1, $t1, $s1
    psraw      $t0, $t0, 15
    psraw      $t1, $t1, 15
    pmulth     $t2, $t2, $s0
    pmulth     $t3, $t3, $s0
    psraw      $t2, $t2, 15
    psraw      $t3, $t3, 15
    ppach      $t1, $t1, $t0
    ppach      $t3, $t3, $t2
    paddh      $t0, $a0, $zero
    paddh      $a0, $a1, $zero
    paddh      $a1, $a2, $zero
    paddh      $a2, $a3, $zero
    paddh      $a3, $t8, $zero
    paddh      $t8, $t9, $zero
    paddh      $t9, $v0, $zero
    paddh      $v0, $t1, $zero
    paddh      $t1, $v1, $zero
    paddh      $v1, $t4, $zero
    paddh      $t4, $t5, $zero
    paddh      $t5, $t6, $zero
    paddh      $t6, $t7, $zero
    paddh      $t7, $s6, $zero
    paddh      $s6, $s7, $zero
    paddh      $s7, $t3, $zero
    addi       $s5, $s5, -0x8
    andi       $t3, $s5, 0x3F
    bnez       $t3, @L002FC918
    nop
    nop
    sq         $t0, 0x0($s4)
    sq         $a0, 0x10($s4)
    sq         $a1, 0x20($s4)
    sq         $a2, 0x30($s4)
    sq         $a3, 0x40($s4)
    sq         $t8, 0x50($s4)
    sq         $t9, 0x60($s4)
    sq         $v0, 0x70($s4)
    sq         $t1, 0x0($s3)
    sq         $v1, 0x10($s3)
    sq         $t4, 0x20($s3)
    sq         $t5, 0x30($s3)
    sq         $t6, 0x40($s3)
    sq         $t7, 0x50($s3)
    sq         $s6, 0x60($s3)
    sq         $s7, 0x70($s3)
    addi       $s4, $s4, 0x80
    bnez       $s5, @L002FC8D8
    addi      $s3, $s3, 0x80
    nop
    lq         $s7, 0x70($sp)
    lq         $s6, 0x60($sp)
    lq         $s5, 0x50($sp)
    lq         $s4, 0x40($sp)
    lq         $s3, 0x30($sp)
    lq         $s2, 0x20($sp)
    lq         $s1, 0x10($sp)
    lq         $s0, 0x0($sp)
    jr         $ra
    addiu     $sp, $sp, 0x80
    .set at
    .set reorder
}

// CB3SoundDistortion::StopDistortion() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundDistPS2.cpp.
// 0x002FCF00
void CB3SoundDistortion::StopDistortion()
{
    if (field_184C == 0) {
        return;
    }
    (field_1D04++)->field_0 = 48;
    field_1D00->field_0++;
    field_184C = 0;
    if (field_1D00->field_0 != 0) {
        if (sceSifCheckStatRpc(field_1D10) != 1) {
            sceSifCallRpc(field_1D10, 0x150276, 1, ((char *)this + 0x1900), 1024, 0, 0, 0, 0);
        }
        ((UnkStruct_002FCF00_3 *)field_1D00)->field_0 = 0;
        field_1D04 = (UnkStruct_002FCF00_1 *)((char *)this + 0x1904);
    }
}

// CB3SoundDistortion::StartDistortion() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundDistPS2.cpp.
// 0x002FCFC0
void CB3SoundDistortion::StartDistortion()
{
    if (field_184C != 0) {
        return;
    }
    field_18D0 = D_0064ED5C.field_0;
    (field_1D04++)->field_0 = 32800;
    field_1D00->field_0++;
    if (field_1D00->field_0 != 0) {
        if (sceSifCheckStatRpc(field_1D10) != 1) {
            sceSifCallRpc(field_1D10, 0x150276, 0, ((char *)this + 0x1900), 1024, 0, 0, 0, 0);
        }
        ((UnkStruct_002FCFC0_4 *)field_1D00)->field_0 = 0;
        field_1D04 = (UnkStruct_002FCF00_1 *)((char *)this + 0x1904);
    }
    field_184C = 1;
}

// CB3SoundDistortion::SetChannels(int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundDistPS2.cpp.
// 0x002FD090
void CB3SoundDistortion::SetChannels(int p0)
{
    if (field_184C != 0) return;
    (field_1D04++)->field_0 = 32848;
    UnkStruct_002FCF00_1 * t1 = field_1D04++;
    field_1D00->field_0++;
    t1->field_0 = p0;
}
