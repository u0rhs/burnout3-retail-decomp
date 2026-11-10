// HostMigrationEnterGame__17CB3NetworkManagerFv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CGtNetworkPlayerManager.h"
#include "b3/classes/UnkStruct__gnQuickSortHostPlayerID.h"

struct UnkStruct_0026CAB0;
struct UnkStruct_0026CAB0_2;
struct UnkStruct_func_0026CBE0;

struct UnkStruct_0026CAB0_2 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18();
    virtual void vfunc_1C();
    virtual void vfunc_20();
    virtual void vfunc_24();
    virtual void vfunc_28();
    virtual void vfunc_2C();
    virtual void vfunc_30();
    virtual void vfunc_34();
    virtual void vfunc_38();
    virtual void vfunc_3C();
    virtual void vfunc_40();
    virtual void vfunc_44();
    virtual void vfunc_48();
    virtual void vfunc_4C();
    virtual void vfunc_50();
    virtual void vfunc_54();
    virtual void vfunc_58();
    virtual void vfunc_5C();
    virtual void vfunc_60();
    virtual void vfunc_64();
    virtual void vfunc_68();
    virtual void vfunc_6C();
    virtual void vfunc_70();
    virtual void vfunc_74();
    virtual void vfunc_78();
    virtual void vfunc_7C();
    virtual int vfunc_80();
};

struct UnkStruct_func_0026CBE0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0026CAB0 {
    unsigned char pad_0[0x28];
    int field_28;
    unsigned char pad_2C[0x32954];
    int field_32980[1];  // [G] element count unknown
    unsigned char pad_32984[0x35];
    unsigned char field_329B9;
};

extern UnkStruct__gnQuickSortHostPlayerID _gnQuickSortHostPlayerID;
extern UnkStruct_func_0026CBE0 func_0026CBE0;
extern "C" int GetMyPlayerID__23CGtNetworkPlayerManagerCFv(void *);  // CGtNetworkPlayerManager::GetMyPlayerID() const
extern "C" int GetHostPlayerID__23CGtNetworkPlayerManagerFv(void *);  // CGtNetworkPlayerManager::GetHostPlayerID()
extern "C" int func_002366D0(UnkStruct_0026CAB0 *, int);
extern "C" int func_0022FBB0(void *);
extern "C" void qsort(void *, int, int, void *);

// 0x0026CAB0
extern "C" void HostMigrationEnterGame__17CB3NetworkManagerFv(UnkStruct_0026CAB0 * self)
{
    int i;
    int n = self->field_28;
    for (i = 0; i < n; i++) {
        int r0 = func_002366D0(self, i);
        if (r0 == 0) {
            self->field_32980[i] = GetMyPlayerID__23CGtNetworkPlayerManagerCFv(self);
        } else {
            self->field_32980[i] = func_0022FBB0((void *)(r0));
        }
    }
    int v3;
    if (self->field_329B9 != 0) {
        v3 = GetHostPlayerID__23CGtNetworkPlayerManagerFv(self);
    } else {
        v3 = ((UnkStruct_0026CAB0_2 *)((char *)self + 0xA264))->vfunc_80();
    }
    _gnQuickSortHostPlayerID.field_0 = v3;
    qsort(((char *)self + 0x32980), n, 4, &func_0026CBE0);
    _gnQuickSortHostPlayerID.field_0 = -1;
    for (; n < 8; n++) {
        self->field_32980[n] = -1;
    }
}
