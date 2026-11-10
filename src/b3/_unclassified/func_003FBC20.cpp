// func_003FBC20 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_004CEA90.h"
#include "b3/classes/UnkStruct_D_004E1F08.h"
#include "b3/classes/UnkStruct_D_004E1F0C.h"
#include "b3/classes/UnkStruct_D_004E1F14.h"
#include "b3/classes/UnkStruct_D_004E1F18.h"
#include "b3/classes/UnkStruct_D_004E1F1C.h"
#include "b3/classes/UnkStruct_D_004F5075.h"
#include "b3/classes/UnkStruct_D_01E774E0.h"

struct UnkStruct_003FBC20;
struct UnkStruct_003FBC20_e0;

struct UnkStruct_003FBC20_e0 {
    unsigned char pad_0[0x18];
};

struct UnkStruct_003FBC20 {
    unsigned char pad_0[0xB4];
    UnkStruct_003FBC20_e0 * field_B4;
    unsigned char pad_B8[0x4];
    unsigned char field_BC;
    unsigned char pad_BD[0x3];
    void * field_C0;
    int field_C4;
    int field_C8;
    unsigned char pad_CC[0x4];
    int field_D0;
    int field_D4;
    int field_D8;
    unsigned char pad_DC[0x4];
    int field_E0;
    unsigned char pad_E4[0x4];
    unsigned char field_E8;
    unsigned char field_E9;
    unsigned char field_EA;
};

extern UnkStruct_D_004E1F18 D_004E1F18;
extern UnkStruct_D_004E1F14 D_004E1F14;
extern UnkStruct_D_004E1F08 D_004E1F08;
extern UnkStruct_D_004E1F0C D_004E1F0C;
extern UnkStruct_D_004E1F1C D_004E1F1C;
extern UnkStruct_D_004F5075 D_004F5075;
extern UnkStruct_D_004CEA90 D_004CEA90;
extern UnkStruct_D_01E774E0 D_01E774E0;
extern "C" void func_0042B500(void *);
extern "C" void sprintf(void *, void *, int, int, int, int, int, int, float, float, float, float, float, float, float, float);
extern "C" void func_003FC700(UnkStruct_003FBC20 *);
extern "C" void func_0042B580(void *);
extern "C" void Stop__14CGtSoundStreamFv(void *);
extern "C" int Release__14CGtSoundStreamFv(void *);
extern "C" void FreeStream__21CGtSoundStreamManagerFP14CGtSoundStream(void *, void *);

// 0x003FBC20
extern "C" void func_003FBC20(UnkStruct_003FBC20 * self, int p0, int p1, int p2, int p3, int p4, int p5, int p6, float f0, float f1, float f2, float f3, float f4, float f5, float f6, float f7)
{
    if (p0 == -1) {
        self->field_E8 = (self->field_E8 & 254);
        if (self->field_BC != 0) {
            void * t2 = self->field_C0;
            if (t2 != 0) {
                Stop__14CGtSoundStreamFv(t2);
                Release__14CGtSoundStreamFv(self->field_C0);
                FreeStream__21CGtSoundStreamManagerFP14CGtSoundStream(&D_01E774E0, self->field_C0);
                self->field_C0 = 0;
            }
            if (self->field_D0 == 4) {
                self->field_D0 = 5;
                func_003FC700(self);
            }
            self->field_C8 = 6;
        } else {
            func_0042B580(((char *)self + 0x8));
        }
        return;
    }
    self->field_EA = 0;
    if (self->field_BC != 0) {
            self->field_D8 = p0;
            self->field_C4 = (int)&self->field_B4[p0];
            self->field_D4 = 0;
            int v0;
            if (self->field_D8 < 22) {
                v0 = D_004E1F14.field_0;
                self->field_E0 = 0;
            } else {
                v0 = D_004E1F18.field_0;
                self->field_E0 = 1;
            }
            sprintf(((char *)self + 0x48), &D_004CEA90, D_004E1F08.field_0, D_004E1F0C.field_0, v0, D_004E1F1C.field_0, p5, p6, f0, f1, f2, f3, f4, f5, f6, f7);
            if (self->field_D0 == 4) {
                self->field_D0 = 5;
                func_003FC700(self);
            }
    if (D_004F5075.field_0 <= 0) {
        self->field_E9 = 1;
    } else {
        self->field_E9 = 0;
    }
    } else {
    func_0042B500(((char *)self + 0x8));
    self->field_E9 = 1;
    }
}
