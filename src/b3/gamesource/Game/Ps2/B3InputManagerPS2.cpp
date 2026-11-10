// B3InputManagerPS2.cpp -- translation unit regrouped by tools/tu_merge.py from 4 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 3 function(s) named in research/retail_names.csv -> B3InputManagerPS2.cpp, 1 placed between two of them by address contiguity (N2).
// Area: src/b3/gamesource/Game/Ps2, [L] Revenge (SLUS_212.42) GameSource/Game/Ps2/B4InputManagerPS2.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3InputManager.h"
#include "b3/classes/CGtInputDevicePS2DualShock.h"
#include "b3/classes/CGtInputDevicePS2DualShock2.h"
#include "b3/classes/CGtInputManagerPS2Pad2.h"

struct UnkStruct_00213EB0;
struct UnkStruct_002144B0_e1;
struct UnkStruct_00214560_e1;
struct UnkStruct_002142A0;
struct UnkStruct_002142A0_e4;

struct UnkStruct_00213EB0 {
    unsigned char pad_0[0xFE0];
    unsigned char field_FE0;
};

struct UnkStruct_002144B0_e1 {
    unsigned char pad_0[0x208];
};

struct UnkStruct_00214560_e1 {
    unsigned char pad_0[0x208];
};

struct UnkStruct_002142A0_e4 {
    unsigned char pad_0[0xEC];
};

struct UnkStruct_002142A0 {
    UnkStruct_002142A0_e4 field_0[1];  // [G] element count unknown
    unsigned char pad_EC[0xEB5];
    signed char field_FA1[1];  // [G] element count unknown
    unsigned char pad_FA2[0x1];
    unsigned char field_FA3[1];  // [G] element count unknown
    unsigned char pad_FA4[0x4];
    float field_FA8[1];  // [G] element count unknown
    unsigned char pad_FAC[0x4];
    float field_FB0[1];  // [G] element count unknown
};

extern "C" void SetPause__22CGtInputManagerPS2Pad2Fb(void *, unsigned char);  // CGtInputManagerPS2Pad2::SetPause(bool)
extern "C" void func_00442510(void *, int);
extern "C" void Prepare__22CGtInputManagerPS2Pad2Fv(void *);  // CGtInputManagerPS2Pad2::Prepare()
extern "C" void Prepare__27CGtInputDevicePS2DualShock2Fv(void *);  // CGtInputDevicePS2DualShock2::Prepare()
extern "C" int func_00442720(void *);
extern "C" int func_00443830(void *);
extern "C" void Construct__22CGtInputManagerPS2Pad2Fb(void *, bool);  // CGtInputManagerPS2Pad2::Construct(bool)
extern "C" void Construct__26CGtInputDevicePS2DualShockFv(void *);  // CGtInputDevicePS2DualShock::Construct()
extern "C" void func_00442880(void *);
extern "C" void func_00443860(void *);
extern "C" int IsConnected__26CGtInputDevicePS2DualShockFv(void *);  // CGtInputDevicePS2DualShock::IsConnected()
extern "C" void func_0022BD50(UnkStruct_002142A0 *, int);
extern "C" int func_0022C340(UnkStruct_002142A0 *, int);
extern "C" void func_00217200(void *, float);
extern "C" void func_002171D0(void *, bool);
extern "C" void func_0022D160(UnkStruct_002142A0 *, int);

// SetPause__15CB3InputManagerFb -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00213EB0
extern "C" void SetPause__15CB3InputManagerFb(UnkStruct_00213EB0 * self, int p0)
{
    SetPause__22CGtInputManagerPS2Pad2Fb(self, (p0 & 255));
    func_00442510(((char *)self + 0x8F0), (p0 & 255));
    self->field_FE0 = (p0 & 255);
}

// func_002142A0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x002142A0
extern "C" void func_002142A0(UnkStruct_002142A0 * self, int p0)
{
    func_0022BD50(self, p0);
    if (self->field_FA3[((signed char)p0)] != 0) {
        int r1 = func_0022C340(self, p0);
        if (r1 != 0) {
            signed char t0 = self->field_FA1[((signed char)p0)];
            int r2 = IsConnected__26CGtInputDevicePS2DualShockFv(((char *)&self->field_0[t0] + 0x280));
            if (r2 != 0) {
                func_00217200(((char *)&self->field_0[t0] + 0x280), self->field_FB0[((signed char)p0)]);
                func_002171D0(((char *)&self->field_0[t0] + 0x280), (((int)self->field_FA8[((signed char)p0)]) != 0));
            }
        }
    }
    func_0022D160(self, p0);
}

// CB3InputManager::Prepare() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3InputManagerPS2.cpp.
// 0x002144B0
int CB3InputManager::Prepare()
{
    Prepare__22CGtInputManagerPS2Pad2Fv(this);
    func_00442720(((char *)this + 0x8F0));
    int m0 = 0;
    do {
        Prepare__27CGtInputDevicePS2DualShock2Fv(((char *)&field_0[((signed char)m0)] + 0x280));
        func_00443830(((char *)((char *)this + ((((signed char)m0) * 65) << 3)) + 0x938));
        m0 = ((signed char)(m0 + 1));
    } while (m0 < 2);
    GenericPrepare();
    return 1;
}

// CB3InputManager::Construct() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3InputManagerPS2.cpp.
// 0x00214560
void CB3InputManager::Construct()
{
    Construct__22CGtInputManagerPS2Pad2Fb(this, 0);
    func_00442880(((char *)this + 0x8F0));
    int m0 = 0;
    do {
        Construct__26CGtInputDevicePS2DualShockFv(((char *)&field_0[((signed char)m0)] + 0x280));
        func_00443860(((char *)((char *)this + ((((signed char)m0) * 65) << 3)) + 0x938));
        m0 = ((signed char)(m0 + 1));
    } while (m0 < 2);
    GenericConstruct();
}
