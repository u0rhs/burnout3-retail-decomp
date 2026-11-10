// BUILD-HOST: wine
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/GtMath.h"

#include "b3/classes/CGtInputDevicePS2DualShock.h"
#include "b3/classes/UnkStruct_D_004E0C98.h"
#include "b3/classes/UnkStruct_D_004E1944.h"
#include "b3/classes/UnkStruct_D_004E1948.h"

struct UnkStruct_00214380;
struct UnkStruct_00214380_e4;

struct UnkStruct_00214380_e4 {
    unsigned char pad_0[0xEC];
};

struct UnkStruct_00214380 {
    UnkStruct_00214380_e4 field_0[1];  // [G] element count unknown
    unsigned char pad_EC[0xEB5];
    signed char field_FA1[1];  // [G] element count unknown
    unsigned char pad_FA2[0x1];
    unsigned char field_FA3[1];  // [G] element count unknown
    unsigned char pad_FA4[0x4];
    float field_FA8[1];  // [G] element count unknown
    unsigned char pad_FAC[0x4];
    float field_FB0[1];  // [G] element count unknown
};

extern UnkStruct_D_004E0C98 D_004E0C98;
extern UnkStruct_D_004E1944 D_004E1944;
extern UnkStruct_D_004E1948 D_004E1948;
extern "C" int IsConnected__26CGtInputDevicePS2DualShockFv(void *);  // CGtInputDevicePS2DualShock::IsConnected()
extern "C" void func_0022BE00(UnkStruct_00214380 *);
extern "C" int func_0022C340(UnkStruct_00214380 *, int);
extern "C" void func_00217200(void *, float);
extern "C" void func_002171D0(void *, bool);
extern "C" void GenericPreparePlayerLocks__15CB3InputManagerFv(UnkStruct_00214380 *);

// 0x00214380
extern "C" void func_00214380(UnkStruct_00214380 * self)
{
    func_0022BE00(self);
    float z = 0.0f;
    float t0 = 0.9999f;
    int m0 = 0;
    do {
        if (self->field_FA3[m0] != 0) {
            int r1 = func_0022C340(self, ((signed char)m0));
            if (r1 == 0) {
            } else {
                signed char t1 = self->field_FA1[m0];
                int r2 = IsConnected__26CGtInputDevicePS2DualShockFv(((char *)&self->field_0[t1] + 0x280));
                if (r2 == 0) {
                } else {
                    float mm0 = (self->field_FB0[m0] * D_004E1944.field_0);
                    float mm1 = t0;
                    func_00217200(((char *)&self->field_0[t1] + 0x280), GtMath::Min(GtMath::Max(mm0, z), mm1));
                    float mm2 = (self->field_FA8[m0] * D_004E1948.field_0);
                    float mm3 = t0;
                    func_002171D0(((char *)&self->field_0[t1] + 0x280), GtMath::Min(GtMath::Max(mm2, z), mm3));
                }
            }
        } else {
        }
        m0 = (m0 + 1);
    } while ((unsigned int)m0 < (unsigned int)2);
    GenericPreparePlayerLocks__15CB3InputManagerFv(self);
}
