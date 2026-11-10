// func_002C0410 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CGtNetworkHeadset.h"
#include "b3/classes/EHeadsetTalkControlStatus.h"

struct UnkStruct_002C0410;
struct UnkStruct_002C0410_1;

struct UnkStruct_002C0410_1 {
    unsigned char pad_0[0x14];
    // vptr at +0x14: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18();
    virtual void vfunc_1C();
    virtual void vfunc_20();
    virtual int vfunc_24();
};

struct UnkStruct_002C0410 {
    unsigned char pad_0[0x4];
    UnkStruct_002C0410_1 * field_4;
    int field_8;
    unsigned char pad_C[0x8174];
    float field_8180;
    int field_8184;
    unsigned char pad_8188[0x4];
    int field_818C[1];  // [G] element count unknown
    unsigned char pad_8190[0x1C];
    int field_81AC;
};

extern "C" void SetStatusToSend__17CGtNetworkHeadsetF25EHeadsetTalkControlStatusi(void *, EHeadsetTalkControlStatus, int);  // CGtNetworkHeadset::SetStatusToSend(EHeadsetTalkControlStatus,int)

// 0x002C0410
extern "C" void func_002C0410(UnkStruct_002C0410 * self)
{
    if (((!(self->field_8180 <= 0.0f)) || (self->field_8 != 0)) || (self->field_4->vfunc_24() != 2)) {
        self->field_4->vfunc_24();
        return;
    }
    self->field_8 = 1;
    self->field_8184 = 0;
    *(int *)&self->field_8180 = 0x3F800000;
    for (int i = 0; (i < 8); i++) {
        self->field_818C[i] = -1;
    }
    self->field_81AC = 0;
    SetStatusToSend__17CGtNetworkHeadsetF25EHeadsetTalkControlStatusi(self, (EHeadsetTalkControlStatus)1, -1);
}
