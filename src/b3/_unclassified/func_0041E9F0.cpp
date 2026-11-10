// func_0041E9F0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CGtNetworkHeadset.h"
#include "b3/classes/CGtNetworkPlayerManager.h"
#include "b3/classes/UnkStruct_D_004E2A14.h"
#include "b3/classes/UnkStruct_D_004F509C.h"
#include "b3/classes/UnkStruct_D_01E7A800.h"

struct UnkStruct_0041E9F0;
struct UnkStruct_0041E9F0_3;

struct UnkStruct_0041E9F0_3 {
    int field_0;
};

struct UnkStruct_0041E9F0 {
    unsigned char pad_0[0x81D8];
    CGtNetworkPlayerManager * field_81D8;
    unsigned char pad_81DC[0x2C];
    float field_8208;
};

extern UnkStruct_D_004F509C D_004F509C;
extern UnkStruct_D_004E2A14 D_004E2A14;
extern UnkStruct_D_01E7A800 D_01E7A800;
extern "C" int GetIDOfTalkingNetworkPlayer__17CGtNetworkHeadsetFPi(void *, int*);  // CGtNetworkHeadset::GetIDOfTalkingNetworkPlayer(int*)
extern "C" int IsTalking__17CGtNetworkHeadsetFv(void *);  // CGtNetworkHeadset::IsTalking()
extern "C" void func_002C16A0(UnkStruct_0041E9F0 *, int, float);
extern "C" void func_00283E70(void *, int);

// 0x0041E9F0
extern "C" void func_0041E9F0(UnkStruct_0041E9F0 * self)
{
    UnkStruct_0041E9F0_3 local;  // [G] the frame's one local (size: up to the frame top)
    self->field_8208 = -1.0f;
    float t0 = D_004F509C.field_0;
    unsigned short v0 = D_004E2A14.field_0;
    if (D_004E2A14.field_0 == 65535) {
        v0 = 0;
    }
    func_002C16A0(self, (v0 & 65535), t0);
    int id;
    if (GetIDOfTalkingNetworkPlayer__17CGtNetworkHeadsetFPi(self, &local.field_0) != 0) {
        id = local.field_0;
    } else if (IsTalking__17CGtNetworkHeadsetFv(self) != 0) {
        id = self->field_81D8->GetMyPlayerID();
    } else {
        id = -1;
    }
    func_00283E70(&D_01E7A800, id >= 0);
}
