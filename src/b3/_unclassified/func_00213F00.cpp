// BUILD-HOST: wine
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/GtMath.h"

#include "b3/classes/CB3ControllerMapping.h"
#include "b3/classes/UnkStruct_D_004E0B50.h"
#include "b3/classes/UnkStruct_D_004E1944.h"
#include "b3/classes/UnkStruct_D_004E1948.h"

struct UnkStruct_00213F00;
struct UnkStruct_00213F00_e3;
struct UnkStruct_00213F00_e5;

struct UnkStruct_00213F00_e3 {
    unsigned char pad_0[0x68];
    int field_68;
    unsigned char pad_6C[0xC0];
};

struct UnkStruct_00213F00_e5 {
    unsigned char pad_0[0x12C];
};

struct UnkStruct_00213F00 {
    UnkStruct_00213F00_e5 field_0[1];  // [G] element count unknown
    unsigned char pad_12C[0xBB8];
    UnkStruct_00213F00_e3 field_CE4[1];  // [G] element count unknown
    unsigned char pad_E10[0x191];
    signed char field_FA1[1];  // [G] element count unknown
    unsigned char pad_FA2[0x1];
    unsigned char field_FA3[1];  // [G] element count unknown
    unsigned char pad_FA4[0x4];
    float field_FA8[1];  // [G] element count unknown
    unsigned char pad_FAC[0x4];
    float field_FB0[1];  // [G] element count unknown
    unsigned char pad_FB4[0x2C];
    unsigned char field_FE0;
};

extern UnkStruct_D_004E0B50 D_004E0B50;
extern UnkStruct_D_004E1944 D_004E1944;
extern UnkStruct_D_004E1948 D_004E1948;
extern "C" int PadIsValid__20CB3ControllerMappingFv(void *);  // CB3ControllerMapping::PadIsValid()
extern "C" int func_0022C340(UnkStruct_00213F00 *, int);
extern "C" int func_0012EF20(void *);
extern "C" void func_00217200(void *, float);
extern "C" void func_002171D0(void *, bool);

// 0x00213F00
extern "C" void func_00213F00(UnkStruct_00213F00 * self)
{
    if (self->field_FE0 != 0) {
        return;
    }
    float z = 0.0f;
    float t0 = D_004E0B50.field_0;
    int m0 = 0;
    do {
        if (self->field_FA3[m0] != 0) {
            int r0 = func_0022C340(self, ((signed char)m0));
            if (r0 == 0) {
            } else {
                signed char t1 = self->field_FA1[m0];
                int r1 = PadIsValid__20CB3ControllerMappingFv(((char *)&self->field_0[t1] + 0xD48));
                if (r1 == 0) {
                } else {
                    int r2 = func_0012EF20(((char *)&self->field_0[t1] + 0xD48));
                    if (r2 != 0) {
                    } else {
                        float mm0 = (self->field_FB0[m0] * D_004E1944.field_0);
                        float mm1 = t0;
                        func_00217200((void *)(self->field_CE4[t1].field_68), GtMath::Min(GtMath::Max(mm0, z), mm1));
                        float mm2 = (self->field_FA8[m0] * D_004E1948.field_0);
                        float mm3 = t0;
                        func_002171D0((void *)(self->field_CE4[t1].field_68), GtMath::Min(GtMath::Max(mm2, z), mm3));
                    }
                }
            }
        } else {
        }
        m0 = (m0 + 1);
    } while ((unsigned int)m0 < (unsigned int)2);
}
