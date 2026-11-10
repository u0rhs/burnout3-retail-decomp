// func_0037B400 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_004C9148.h"
#include "b3/classes/UnkStruct_D_004C9150.h"
#include "b3/classes/UnkStruct_D_004C9158.h"
#include "b3/classes/UnkStruct_D_004C9160.h"
#include "b3/classes/UnkStruct_D_004C9168.h"
#include "b3/classes/UnkStruct_D_0051BA44.h"
#include "b3/classes/UnkStruct_D_01E89788.h"
#include "b3/classes/UnkStruct_D_01E8D450.h"
#include "b3/classes/UnkStruct_D_01E8D45A.h"
#include "b3/classes/UnkStruct_D_01E8D490.h"
#include "b3/classes/UnkStruct_D_01E8D49A.h"
#include "b3/classes/UnkStruct_D_01E8D4B0.h"
#include "b3/classes/UnkStruct_D_01E8D4BA.h"
#include "b3/classes/UnkStruct_D_01E8EAF8.h"
#include "b3/classes/UnkStruct_D_01E8EB02.h"

struct UnkStruct_0037B400;
struct UnkStruct_0037B400_9;

struct UnkStruct_0037B400_9 {
    unsigned char pad_0[0x4C];
    void * field_4C;
};

struct UnkStruct_0037B400 {
    unsigned char pad_0[0x1574];
    int field_1574;
    unsigned char pad_1578[0x3CA];
    unsigned char field_1942;
};

extern UnkStruct_D_01E8D45A D_01E8D45A;
extern UnkStruct_D_01E8D450 D_01E8D450;
extern UnkStruct_D_01E8D49A D_01E8D49A;
extern UnkStruct_D_01E8D490 D_01E8D490;
extern UnkStruct_D_01E8D4BA D_01E8D4BA;
extern UnkStruct_D_01E8D4B0 D_01E8D4B0;
extern UnkStruct_D_01E8EB02 D_01E8EB02;
extern UnkStruct_D_01E8EAF8 D_01E8EAF8;
extern UnkStruct_D_0051BA44 D_0051BA44;
extern UnkStruct_D_01E89788 D_01E89788;
extern UnkStruct_D_004C9148 D_004C9148;
extern UnkStruct_D_004C9150 D_004C9150;
extern UnkStruct_D_004C9158 D_004C9158;
extern UnkStruct_D_004C9160 D_004C9160;
extern UnkStruct_D_004C9168 D_004C9168;
extern "C" void SetString__19CB3HelpBarComponentFPCUsbbf(void *, const unsigned short*, bool, bool, float);  // CB3HelpBarComponent::SetString(const unsigned short*,bool,bool,float)
extern "C" int CacheGameParams__26CB3OnlineOptimatchMenuPageFi(UnkStruct_0037B400 *, int);
extern "C" void ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(void *, UnkStruct_0037B400_9 *, int);
extern "C" int func_00271A00(void *, int);
extern "C" void func_003180A0(void *, void *, void *);
extern "C" bool func_00351E40(void *, void *, void *, void *, void *, void *, void *, int, int, int, int, float, float);

// 0x0037B400
// pass1: a1 (callers func_0037A920 / func_0037BCF0 pass an index) goes to CacheGameParams(int) untouched
extern "C" int func_0037B400(UnkStruct_0037B400 * self, int p0)
{
    UnkStruct_0037B400_9 local;  // [G] the frame's one local (size: up to the frame top)
    int r0 = CacheGameParams__26CB3OnlineOptimatchMenuPageFi(self, p0);
    if (r0 == 0) {
        return 0;
    }
    self->field_1942 = 7;
    if (D_01E8D45A.field_0 != 0) {
        ((UnkStruct_D_01E8D450 *)&D_01E8D450)->vfunc_C();
    }
    if (D_01E8D49A.field_0 != 0) {
        ((UnkStruct_D_01E8D490 *)&D_01E8D490)->vfunc_C();
    }
    if (D_01E8D4BA.field_0 != 0) {
        ((UnkStruct_D_01E8D4B0 *)&D_01E8D4B0)->vfunc_C();
    }
    if (D_01E8EB02.field_0 != 0) {
        ((UnkStruct_D_01E8EAF8 *)&D_01E8EAF8)->vfunc_C();
    }
    ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(((char *)self + 0x18), &local, 32);
    local.field_4C = (void *)&local;
    int r6 = func_00271A00(&D_0051BA44, 98);
    func_003180A0((void *)(self->field_1574), (void *)(r6), ((char *)&local + 0x4C));
    SetString__19CB3HelpBarComponentFPCUsbbf(&D_01E89788, (const unsigned short*)self->field_1574, 0, 0, 80.0f);
    func_00351E40(&D_01E8D4B0, &D_004C9148, &D_004C9150, &D_004C9158, &D_004C9160, &D_004C9168, (void *)(self->field_1574), 3, 1, 103, 0, 32.0f, 496.0f);
    return 1;
}
