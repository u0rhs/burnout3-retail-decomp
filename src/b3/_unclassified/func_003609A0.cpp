// func_003609A0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CGtBuddies.h"
#include "b3/classes/CGtBuddiesPS2DirtySock.h"
#include "b3/classes/UnkStruct_D_004C7390.h"
#include "b3/classes/UnkStruct_D_004C73A0.h"

struct UnkStruct_003609A0;
struct UnkStruct_func_0035F230;
struct UnkStruct_func_0035F240;
struct UnkStruct_func_00360290;
struct UnkStruct_func_00360360;

struct UnkStruct_func_00360360 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_func_00360290 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_func_0035F230 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_func_0035F240 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003609A0 {
    unsigned char pad_0[0x118];
    int field_118;
    unsigned char pad_11C[0x4];
    unsigned char field_120;
    unsigned char field_121;
    unsigned char field_122;
};

extern UnkStruct_D_004C7390 D_004C7390;
extern UnkStruct_D_004C73A0 D_004C73A0;
extern UnkStruct_func_00360360 func_00360360;
extern UnkStruct_func_00360290 func_00360290;
extern UnkStruct_func_0035F230 func_0035F230;
extern UnkStruct_func_0035F240 func_0035F240;
extern "C" void Prepare__10CGtBuddiesFv(void *);  // CGtBuddies::Prepare()
extern "C" void SetPresenceDetail__10CGtBuddiesFPcPcPc(void *, char*, char*, char*);  // CGtBuddies::SetPresenceDetail(char*,char*,char*)
extern "C" void _ConnectCallback__22CGtBuddiesPS2DirtySockFPQ29DirtySock10HLBApiRefTiiPv(void *, int, int, void*);  // CGtBuddiesPS2DirtySock::_ConnectCallback(DirtySock::HLBApiRefT*,int,int,void*), its address taken
extern "C" void _MessageCallback__22CGtBuddiesPS2DirtySockFPQ29DirtySock10HLBApiRefTPQ29DirtySock12BuddyApiMsgTPv(void *, void *, void*);  // CGtBuddiesPS2DirtySock::_MessageCallback(DirtySock::HLBApiRefT*,DirtySock::BuddyApiMsgT*,void*), its address taken
extern "C" int func_00418898(void *, void *);
extern "C" void func_004189B0(int, int, void *);
extern "C" void func_00418B10(int, void *, UnkStruct_003609A0 *);
extern "C" void func_00418E80(int, void *, UnkStruct_003609A0 *);
extern "C" void func_00418EC8(int, void *, UnkStruct_003609A0 *);
extern "C" void func_00418F10(int, void *, UnkStruct_003609A0 *);
extern "C" void func_00419D10(int, void *);

// 0x003609A0
extern "C" int func_003609A0(UnkStruct_003609A0 * self, void *p0, void *p1, void *p2, int p3, int p4)
{
    if (self->field_121 != 1) {
        Prepare__10CGtBuddiesFv(self);
        self->field_120 = 0;
        self->field_121 = 1;
        self->field_122 = p4;
        SetPresenceDetail__10CGtBuddiesFPcPcPc(self, (char*)p0, (char*)p1, (char*)p2);
        int r2 = func_00418898(&D_004C7390, &D_004C73A0);
        self->field_118 = r2;
        func_004189B0(self->field_118, 0, &func_00360360);
        func_00418B10(self->field_118, (void *)&_ConnectCallback__22CGtBuddiesPS2DirtySockFPQ29DirtySock10HLBApiRefTiiPv, self);
        func_00418E80(self->field_118, (void *)&_MessageCallback__22CGtBuddiesPS2DirtySockFPQ29DirtySock10HLBApiRefTPQ29DirtySock12BuddyApiMsgTPv, self);
        func_00418EC8(self->field_118, &func_00360290, self);
        func_00418F10(self->field_118, &func_0035F230, self);
        func_00419D10(self->field_118, &func_0035F240);
        return 1;
    }
    return 1;
}
