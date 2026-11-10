// func_003FC2E0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_004CEA90.h"
#include "b3/classes/UnkStruct_D_004E1F08.h"
#include "b3/classes/UnkStruct_D_004E1F0C.h"
#include "b3/classes/UnkStruct_D_004E1F10.h"
#include "b3/classes/UnkStruct_D_004E1F14.h"
#include "b3/classes/UnkStruct_D_004E1F18.h"
#include "b3/classes/UnkStruct_D_004E1F1C.h"
#include "b3/classes/UnkStruct_D_004EE040.h"
#include "b3/classes/UnkStruct_D_01E774E0.h"

struct UnkStruct_003FC2E0;

struct UnkStruct_003FC2E0 {
    unsigned char pad_0[0x8];
    unsigned char field_8[0x40];
    char field_48[0x74];
    unsigned char field_BC;
    unsigned char pad_BD[0x3];
    int field_C0;
    unsigned char pad_C4[0x4];
    int field_C8;
    unsigned char pad_CC[0x4];
    int field_D0;
    int field_D4;
    int field_D8;
    unsigned char pad_DC[0x4];
    int field_E0;
    unsigned char pad_E4[0x4];
    unsigned char field_E8;
};

extern UnkStruct_D_004E1F10 D_004E1F10;
extern UnkStruct_D_004E1F18 D_004E1F18;
extern UnkStruct_D_004E1F14 D_004E1F14;
extern UnkStruct_D_004E1F08 D_004E1F08;
extern UnkStruct_D_004E1F0C D_004E1F0C;
extern UnkStruct_D_004E1F1C D_004E1F1C;
extern UnkStruct_D_004EE040 D_004EE040;
extern UnkStruct_D_01E774E0 D_01E774E0;
extern UnkStruct_D_004CEA90 D_004CEA90;
extern "C" void func_0042B570(void *);
extern "C" int func_00131E40(void *);
extern "C" int func_00386080(void *, int);
extern "C" int func_00386020(int, int);
extern "C" void func_003FC700(UnkStruct_003FC2E0 *);
extern "C" void Stop__14CGtSoundStreamFv(void *);
extern "C" int Release__14CGtSoundStreamFv(void *);
extern "C" void FreeStream__21CGtSoundStreamManagerFP14CGtSoundStream(void *, void *);
extern "C" int func_00127BF8(char *, int);
extern "C" int sprintf(char *, const void *, ...);

// 0x003FC2E0
extern "C" void func_003FC2E0(UnkStruct_003FC2E0 * self)
{
    if (self->field_D8 == -1) {
        return;
    }
    self->field_E8 &= ~1;
    if (self->field_BC != 0) {
        if (self->field_C0 != 0) {
            if (self->field_C8 == 3) {
                int v1;
                if (func_00131E40(&D_004EE040) != 0) {
                    v1 = 0;
                } else {
                    v1 = func_00386080((void *)(self->field_C0), 0);
                }
                int r3 = func_00386020(self->field_C0, 2);
                self->field_D4 = r3 * ((v1 + r3 - 1) / r3);
            } else {
                self->field_D4 = 0;
            }
            if (self->field_D0 == 4) {
                self->field_D0 = 5;
                func_003FC700(self);
            }
            Stop__14CGtSoundStreamFv((void *)(self->field_C0));
            Release__14CGtSoundStreamFv((void *)(self->field_C0));
            FreeStream__21CGtSoundStreamManagerFP14CGtSoundStream(&D_01E774E0, (void *)(self->field_C0));
            self->field_C0 = 0;
        } else {
            self->field_D4 = 0;
        }
        self->field_C8 = 4;
        if (func_00127BF8(self->field_48, D_004E1F10.field_0) == 0) {
            return;
        }
        int v7;
        if (self->field_D8 <= 21) {
            v7 = D_004E1F14.field_0;
            self->field_E0 = 0;
        } else {
            v7 = D_004E1F18.field_0;
            self->field_E0 = 1;
        }
        sprintf(self->field_48, &D_004CEA90, D_004E1F08.field_0, D_004E1F0C.field_0, v7, D_004E1F1C.field_0);
    } else {
        func_0042B570(self->field_8);
    }
}
