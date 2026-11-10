// B3NetworkManager.cpp -- translation unit regrouped by tools/tu_merge.py from 7 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 1 function(s) named in research/retail_names.csv -> B3NetworkManager.cpp, 11 placed between two of them by address contiguity (N2).
// Area: src/b3/gamesource/Network, [L] Revenge (SLUS_212.42) GameSource/Network/B4NetworkManager.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/UnkStruct__gnQuickSortHostPlayerID.h"

struct UnkStruct_0026CBE0;
struct UnkStruct_0026CBE0_a1;
struct UnkStruct_0026D260;
struct UnkStruct_0026EC50;
struct UnkStruct_0026EC50_1;
struct UnkStruct_0026EC50_a2;
struct UnkStruct_0026ECC0;
struct UnkStruct_0026ECC0_1;
struct UnkStruct_00270C90;
struct UnkStruct_00270C90_e0;
struct UnkStruct_002709D0;
struct UnkStruct_002709D0_1;
struct UnkStruct_002709D0_2;
struct UnkStruct_00270AC0;
struct UnkStruct_00270AC0_1;

struct UnkStruct_0026CBE0_a1 {
    int field_0;
};
struct UnkStruct_0026CBE0 {
    int field_0;
};
struct UnkStruct_0026D260 {
    unsigned char pad_0[0x329E2];
    unsigned char field_329E2;
    unsigned char field_329E3;
    unsigned char pad_329E4[0x4];
    int field_329E8;
    int field_329EC;
};
struct UnkStruct_0026EC50_1 {
    unsigned char pad_0[0x4F4];
    unsigned char field_4F4;
};
struct UnkStruct_0026EC50_a2 {
    unsigned char pad_0[0x329BC];
    int field_329BC;
};
struct UnkStruct_0026EC50 {
    unsigned char pad_0[0x4];
    int field_4;
};
struct UnkStruct_0026ECC0_1 {
    unsigned char pad_0[0x4F0];
    int field_4F0;
    unsigned char pad_4F4[0xCC];
    unsigned char field_5C0;
};
struct UnkStruct_0026ECC0 {
    unsigned char pad_0[0x28];
    int field_28;
    unsigned char pad_2C[0xAA84];
    int field_AAB0;
    unsigned char pad_AAB4[0x4];
    unsigned short field_AAB8;
};
struct UnkStruct_00270C90_e0 {
    unsigned char pad_0[0x4F20];
};
struct UnkStruct_00270C90 {
    UnkStruct_00270C90_e0 field_0[1];  // [G] element count unknown
};
struct UnkStruct_002709D0_1 {
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
    virtual void vfunc_80();
    virtual void vfunc_84();
    virtual void vfunc_88();
    virtual void vfunc_8C();
    virtual void vfunc_90();
    virtual void vfunc_94();
    virtual void vfunc_98();
    virtual void vfunc_9C();
    virtual void vfunc_A0();
    virtual void vfunc_A4();
    virtual void vfunc_A8();
    virtual bool vfunc_AC();
    virtual void vfunc_B0();
    virtual void vfunc_B4();
    virtual void vfunc_B8();
    virtual void vfunc_BC();
    virtual void vfunc_C0();
    virtual void vfunc_C4();
    virtual void vfunc_C8();
    virtual void vfunc_CC();
    virtual void vfunc_D0();
    virtual void vfunc_D4();
    virtual int vfunc_D8();
};
struct UnkStruct_002709D0_2 {
    unsigned char pad_0[0xAC];
    int field_AC;
};
struct UnkStruct_002709D0 {
    unsigned char pad_0[0xA264];
    UnkStruct_002709D0_1 field_A264;
    unsigned char pad_A268[0x329B9 - 0xA268];
    unsigned char field_329B9;
    unsigned char field_329BA;
};
struct UnkStruct_00270AC0_1 {
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
    virtual void vfunc_80();
    virtual void vfunc_84();
    virtual void vfunc_88();
    virtual void vfunc_8C();
    virtual void vfunc_90();
    virtual void vfunc_94();
    virtual void vfunc_98();
    virtual void vfunc_9C();
    virtual void vfunc_A0();
    virtual void vfunc_A4();
    virtual void vfunc_A8();
    virtual bool vfunc_AC();
    virtual void vfunc_B0();
    virtual void vfunc_B4();
    virtual void vfunc_B8();
    virtual void vfunc_BC();
    virtual void vfunc_C0();
    virtual void vfunc_C4();
    virtual void vfunc_C8();
    virtual void vfunc_CC();
    virtual void vfunc_D0();
    virtual void vfunc_D4();
    virtual int vfunc_D8();
};
struct UnkStruct_00270AC0 {
    unsigned char pad_0[0xA264];
    UnkStruct_00270AC0_1 field_A264;
    unsigned char pad_A268[0x328F0 - 0xA268];
    unsigned char field_328F0[0x80];
    unsigned char field_32970[0x38];
    unsigned char field_329A8;
    unsigned char pad_329A9[0x10];
    unsigned char field_329B9;
    unsigned char field_329BA;
};

extern UnkStruct__gnQuickSortHostPlayerID _gnQuickSortHostPlayerID;

extern "C" UnkStruct_0026EC50_1 * GetPlayerByID__23CGtNetworkPlayerManagerCFi(void *, int);  // CGtNetworkPlayerManager::GetPlayerByID(int) const
extern "C" UnkStruct_0026ECC0_1 * func_002366D0(UnkStruct_0026ECC0 *, int);
extern "C" void func_00235BA0(UnkStruct_0026ECC0 *);
extern "C" void func_0023B870(void *);
extern "C" void func_0022F510(void *);
extern "C" void func_00236E20(UnkStruct_00270C90 *);
extern "C" int GetHostPlayerID__23CGtNetworkPlayerManagerFv(void *);  // CGtNetworkPlayerManager::GetHostPlayerID()
extern "C" int GetMyPlayerID__23CGtNetworkPlayerManagerCFv(void *);  // CGtNetworkPlayerManager::GetMyPlayerID() const
extern "C" void func_00240960(void *);
extern "C" void func_00240B70(void *);
extern "C" void func_002409B0(void *);
extern "C" void func_00240C00(void *);

// func_0026CBE0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x0026CBE0
extern "C" int func_0026CBE0(UnkStruct_0026CBE0 * self, UnkStruct_0026CBE0_a1 * p0)
{
    int a = self->field_0;
    int h = _gnQuickSortHostPlayerID.field_0;
    if (a == h) return -1;
    int b = p0->field_0;
    if (b == h) return 1;
    if (a > h && b < h) return -1;
    if (a < h && b > h) return 1;
    if (a < b) return -1;
    return b < a;
}

// func_0026D260 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x0026D260
extern "C" void func_0026D260(UnkStruct_0026D260 * self)
{
    self->field_329E8 = 0;
    self->field_329EC = 0;
    self->field_329E2 = 0;
    self->field_329E3 = 0;
}

// RaceReadyMessageArrivedCallback__17CB3NetworkManagerFP17CGtNetworkMessageiPv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x0026EC50
extern "C" void RaceReadyMessageArrivedCallback__17CB3NetworkManagerFP17CGtNetworkMessageiPv(UnkStruct_0026EC50 * self, int p0, UnkStruct_0026EC50_a2 * p1)
{
    UnkStruct_0026EC50_1 * r0 = GetPlayerByID__23CGtNetworkPlayerManagerCFi(p1, self->field_4);
    if (r0->field_4F4 == 0) {
        p1->field_329BC = (p1->field_329BC + 1);
        r0->field_4F4 = 1;
    }
}

// RestNATStatusData__17CB3NetworkManagerFv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x0026ECC0
extern "C" void RestNATStatusData__17CB3NetworkManagerFv(UnkStruct_0026ECC0 * self)
{
    for (int i = 0; (i < self->field_28); i++) {
        UnkStruct_0026ECC0_1 * r0 = func_002366D0(self, i);
        if (r0 != 0) {
            r0->field_5C0 = 0;
            r0->field_4F0 = 0;
        }
    }
    func_00235BA0(self);
    self->field_AAB0 = 0;
    self->field_AAB8 = 65535;
}

// func_002709D0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x002709D0
extern "C" void func_002709D0(UnkStruct_002709D0 * self)
{
    bool v;
    if (self->field_A264.vfunc_D8() != 0 || self->field_329B9 != 0) {
        if (self->field_329BA != 0) {
            v = self->field_A264.vfunc_AC();
        } else if (GetHostPlayerID__23CGtNetworkPlayerManagerFv(self) == GetMyPlayerID__23CGtNetworkPlayerManagerCFv(self)) {
            v = true;
        } else {
            v = false;
        }
    } else {
        v = false;
    }
    if (v) {
        func_00240B70((char *)self + 0x32970);
    } else {
        func_00240960((char *)self + 0x328F0);
    }
}

// func_00270AC0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00270AC0
extern "C" int func_00270AC0(UnkStruct_00270AC0 * self)
{
    bool v;
    if (self->field_A264.vfunc_D8() != 0 || self->field_329B9 != 0) {
        if (self->field_329BA != 0) {
            v = self->field_A264.vfunc_AC();
        } else if (GetHostPlayerID__23CGtNetworkPlayerManagerFv(self) == GetMyPlayerID__23CGtNetworkPlayerManagerCFv(self)) {
            v = true;
        } else {
            v = false;
        }
    } else {
        v = false;
    }
    if (v) {
        func_00240B70(self->field_32970);
    } else {
        func_00240960(self->field_328F0);
    }
    if (self->field_A264.vfunc_D8() != 0 || self->field_329B9 != 0) {
        if (self->field_329BA != 0) {
            v = self->field_A264.vfunc_AC();
        } else if (GetHostPlayerID__23CGtNetworkPlayerManagerFv(self) == GetMyPlayerID__23CGtNetworkPlayerManagerCFv(self)) {
            v = true;
        } else {
            v = false;
        }
    } else {
        v = false;
    }
    if (v) {
        func_00240C00(self->field_32970);
    } else {
        func_002409B0(self->field_328F0);
    }
    self->field_329A8 = 1;
    return 1;
}

// func_00270C90 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00270C90
extern "C" void func_00270C90(UnkStruct_00270C90 * self)
{
    for (int i = 0; (i < 8); i++) {
        func_0023B870(((char *)&self->field_0[i] + 0xAAC0));
    }
    func_0022F510(((char *)self + 0x9B40));
    func_00236E20(self);
}
