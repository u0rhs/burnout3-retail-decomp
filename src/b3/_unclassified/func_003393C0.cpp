// GetPlayerInLobby__20CGtLobbyPS2DirtySockFiPFPcibiiiPcbPv_bPv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_004C5968.h"

struct UnkStruct_003393C0;
struct UnkStruct_003393C0_1;

struct UnkStruct_003393C0_1 {
    int field_0;
    unsigned char pad_4[0x4];
    char field_8[16];  // [G] length unknown
};

struct UnkStruct_003393C0 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    unsigned char pad_4[0x118];
    unsigned char field_11C;
    unsigned char pad_11D[0x387];
    char field_4A4[16];  // [G] length unknown
    unsigned char pad_4B4[0xB8];
    int field_56C;
};

extern UnkStruct_D_004C5968 D_004C5968;
extern "C" void DispListOrder(int);
extern "C" UnkStruct_003393C0_1 * DispListIndex(int, int);
extern "C" int strcasecmp(const char *, const char *);

// 0x003393C0
extern "C" void GetPlayerInLobby__20CGtLobbyPS2DirtySockFiPFPcibiiiPcbPv_bPv(UnkStruct_003393C0 * self, int p0, void (*p1)(char *, int, int, int, int, int, void *, int, int), int p2)
{
    if (self->field_11C == 0) {
        DispListOrder(self->field_56C);
        UnkStruct_003393C0_1 * r1 = DispListIndex(self->field_56C, p0);
        if (r1 != 0) {
            int r2 = strcasecmp(self->field_4A4, r1->field_8);
            p1(r1->field_8, r1->field_0, ((r2 != 0) ^ 1), 0, 0, 0, &D_004C5968, 1, p2);
        }
    }
    self->vfunc_14();
}
