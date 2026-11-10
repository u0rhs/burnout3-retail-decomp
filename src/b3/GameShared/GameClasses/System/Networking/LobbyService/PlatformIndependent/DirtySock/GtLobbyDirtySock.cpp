// GtLobbyDirtySock.cpp -- translation unit regrouped by tools/tu_merge.py from 37 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 16 function(s) named in research/retail_names.csv -> GtLobbyDirtySock.cpp, 13 by a medium-confidence name confirmed by a neighbour, 32 placed between two of them by address contiguity (N2).
// Area: src/b3/GameShared/GameClasses/System/Networking/LobbyService/PlatformIndependent/DirtySock, [L] Revenge (SLUS_212.42) GameShared/GameClasses/System/Networking/LobbyService/PlatformIndependent/DirtySock/GtLobbyDirtySock.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CGtLobbyDirtySockCachedPlayerParams.h"
#include "b3/classes/CGtLobbyPS2DirtySock.h"
#include "b3/classes/CGtMalloc.h"
#include "b3/classes/UnkStruct_D_004C57C8.h"
#include "b3/classes/UnkStruct_D_004C5978.h"
#include "b3/classes/UnkStruct_D_004C5980.h"
#include "b3/classes/UnkStruct_D_004C5990.h"
#include "b3/classes/UnkStruct_D_004C59A8.h"
#include "b3/classes/UnkStruct_D_004E2DAC.h"

struct UnkStruct_00335F40;
struct UnkStruct_00335F40_1;
struct UnkStruct_00336150;
struct UnkStruct_00338C10_a2;
struct UnkStruct_00339380;
struct UnkStruct_00339380_1;
struct UnkStruct_00339380_a1;
struct UnkStruct_0033AC60_a1;
struct UnkStruct_0033AC60_a2;
struct UnkStruct_0033ACD0;
struct UnkStruct_0033ACD0_a1;
struct UnkStruct_0033BD80;
struct UnkStruct_0033C670_a1;
struct UnkStruct_0033C670_a2;
struct UnkStruct_0033B400_1;
struct UnkStruct_003365E0;
struct UnkStruct_00336640;
struct UnkStruct_00336DF0;
struct UnkStruct_0033BB90;
struct UnkStruct_00336B20;
struct UnkStruct_func_003366E0;
struct UnkStruct_0033C8D0_1;

struct UnkStruct_00335F40_1 {
    unsigned char pad_0[0x114];
    int field_114;
};
struct UnkStruct_00335F40 {
    unsigned char pad_0[0x134];
    UnkStruct_00335F40_1 * field_134;
};
struct UnkStruct_00335FC0 {
    unsigned char pad_0[0x644];
    int field_644;
};
struct UnkStruct_00336150 {
    unsigned char pad_0[0x638];
    int field_638;
    int field_63C;
    int field_640;
    int field_644;
    short field_648;
};
struct UnkStruct_00336790 {
    unsigned char pad_0[0x61C];
    void * field_61C;
};
struct UnkStruct_003379C0 {
    unsigned char pad_0[0x604];
    int field_604;
    int field_608;
};
struct UnkStruct_00338950 {
    unsigned char pad_0[0x588];
    int field_588;
    int field_58C;
};
struct UnkStruct_00338C10_a2 {
    unsigned char pad_0[0x8];
    int field_8;
};
struct UnkStruct_00339380_1 {
    unsigned char pad_0[0x24];
    int field_24;
};
struct UnkStruct_00339380_a1 {
    int field_0;
};
struct UnkStruct_00339380 {
    unsigned char pad_0[0x104];
    int field_104;
};
struct UnkStruct_0033AC60_a1 {
    unsigned char pad_0[0xC];
    CGtLobbyPS2DirtySock * field_C;
    int field_10;
};
struct UnkStruct_0033AC60_a2 {
    unsigned char pad_0[0x110];
    unsigned char field_110;
    unsigned char field_111;
    unsigned char field_112;
    unsigned char pad_113[0x1];
    int field_114;
    unsigned char pad_118[0x148];
    int field_260;
};
struct UnkStruct_0033ACD0_a1 {
    void * field_0;
    void * field_4;
    void * field_8;
    unsigned char pad_C[0x4];
    int field_10;
    int field_14;
    int field_18;
    int field_1C;
    unsigned char field_20;
    unsigned char field_21;
};
struct UnkStruct_0033ACD0 {
    unsigned char pad_0[0x545];
    unsigned char field_545;
    unsigned char field_546;
};
struct UnkStruct_0033BD80 {
    unsigned char pad_0[0x264];
    unsigned char field_264;
};
struct UnkStruct_0033C670_a1 {
    unsigned char pad_0[0x8];
    int field_8;
    CGtLobbyPS2DirtySock * field_C;
    int field_10;
};
struct UnkStruct_0033C670_a2 {
    unsigned char pad_0[0x110];
    unsigned char field_110;
    unsigned char field_111;
    unsigned char field_112;
    unsigned char pad_113[0x1];
    int field_114;
    unsigned char pad_118[0x4];
    unsigned char field_11C;
    unsigned char pad_11D[0x1];
    unsigned char field_11E;
    unsigned char field_11F;
    unsigned char field_120;
    unsigned char field_121;
    unsigned char pad_122[0x2];
    int field_124;
    int field_128;
    int field_12C;
    int field_130;
    int field_134;
};
struct UnkStruct_0033B400_1 {
    int field_0;
};
struct UnkStruct_003365E0 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual int vfunc_14();
    unsigned char pad_4[0x628];
    int field_62C;
};
struct UnkStruct_00336640 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual int vfunc_14();
    unsigned char pad_4[0x10C];
    unsigned char field_110;
    unsigned char field_111;
    unsigned char field_112;
    unsigned char pad_113[0x1];
    int field_114;
    unsigned char pad_118[0x8];
    unsigned char field_120;
    unsigned char pad_121[0x50B];
    int field_62C;
    unsigned char field_630;
};
struct UnkStruct_00336DF0 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual int vfunc_14();
    unsigned char pad_4[0x10D];
    unsigned char field_111;
    unsigned char pad_112[0x50A];
    void * field_61C;
};
struct UnkStruct_0033BB90 {
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
    unsigned char pad_4[0x118];
    unsigned char field_11C;
    unsigned char field_11D;
    unsigned char pad_11E[0x2];
    unsigned char field_120;
    unsigned char field_121;
    unsigned char pad_122[0x2];
    int field_124;
    unsigned char pad_128[0x4];
    int field_12C;
    int field_130;
    int field_134;
    unsigned char pad_138[0x124];
    int field_25C;
    unsigned char pad_260[0x1E4];
    unsigned char field_444;
    unsigned char pad_445[0x143];
    void (*field_588)(int, int);  // [G] callback, called with (-1, field_58C)
    int field_58C;
};
struct UnkStruct_func_003366E0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};
struct UnkStruct_00336B20 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual int vfunc_14();
    unsigned char pad_4[0x10C];
    unsigned char field_110;
    unsigned char field_111;
    unsigned char field_112;
    unsigned char pad_113[0x1];
    int field_114;
    unsigned char pad_118[0x8];
    unsigned char field_120;
    unsigned char pad_121[0x4FB];
    int field_61C;
};
struct UnkStruct_0033BC20 {
    unsigned char pad_0[0x10C];
    int field_10C;
    unsigned char field_110;
    unsigned char field_111;
    unsigned char field_112;
};
struct UnkStruct_0033C8D0_1 {
    unsigned char pad_0[0x90];
};

extern UnkStruct_D_004E2DAC D_004E2DAC;
extern UnkStruct_D_004C5978 D_004C5978;
extern UnkStruct_D_004C5980 D_004C5980;
extern UnkStruct_D_004C59A8 D_004C59A8;
extern CGtMalloc _gMemoryAllocator;
extern UnkStruct_D_004C57C8 D_004C57C8;
extern UnkStruct_func_003366E0 func_003366E0;
extern UnkStruct_D_004C5990 D_004C5990;

extern "C" int func_00403768(int);
extern "C" void func_004038A8(int, int, int);
extern "C" int func_0040DA90(void *, int, int);
extern "C" int func_0040D730(void *);
extern "C" void strcasecmp(int, int);
extern "C" void TagFieldSetString(UnkStruct_003362B0_1 *, int, void *, char*);
extern "C" void TagFieldSetFlags(UnkStruct_003362B0_1 *, int, void *, int);
extern "C" void LobbyApiRequestCB(int, int, UnkStruct_003362B0_1 *, int, int);
extern "C" void DispListOrder(int);
extern "C" void func_0040A5D0(int);
extern "C" UnkStruct_00339380_1 * LobbyApiInfoPtr(int, int);
extern "C" int TagFieldFind(int, void *);
extern "C" int TagFieldGetNumber(int, int);
extern "C" void * memset(void *, int, unsigned int);
extern "C" char * strncpy(char *, const char *, unsigned int);
extern "C" int DispListCount(int);
extern "C" UnkStruct_0033B400_1 * DispListIndex(int, int);
extern "C" int func_0040E800(int, int, int, int, int);
extern "C" int func_0040E8B0(int);
extern "C" int func_0040E638(int, int, int);
extern "C" int func_0040C9D0(void *, int);
extern "C" void func_0040C848(void *);
extern "C" void func_0040CF08(int, int);
extern "C" int func_0040CDB8(int, int, int, int);
extern "C" int func_0040D020(int, int, int, int, int, int, void *, UnkStruct_00336B20 *);
extern "C" char * strcpy(char *, const char *);
extern "C" unsigned int strlen(const char *);
extern "C" void func_00128BE8(UnkStruct_0033C8D0_1 *, void *);
extern "C" int atoi(UnkStruct_0033C8D0_1 *);

// func_00335F40 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00335F40
extern "C" bool func_00335F40(UnkStruct_00335F40 * self)
{
    return ((self->field_134->field_114 & 4096) != 0);
}

// func_00335FC0 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00335FC0
extern "C" int func_00335FC0(UnkStruct_00335FC0 *self)
{
    return self->field_644;
}

// func_00336150 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00336150
extern "C" void func_00336150(UnkStruct_00336150 * self, void *p0_, int p1)
{
    int p0 = (int)p0_;
    int r0 = func_00403768(8192);
    self->field_638 = r0;
    self->field_63C = 0;
    self->field_640 = 0;
    self->field_648 = p1;
    func_004038A8(self->field_638, p0, 3);
    self->field_644 = 0;
}

// func_003365E0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x003365E0
extern "C" int func_003365E0(UnkStruct_003365E0 * self, int p0, void *p1_, int p2)
{
    int p1 = (int)p1_;
    if (func_0040E800(self->field_62C, 0, p0, p1, p2) != 0) {
        return self->vfunc_14();
    }
    return 1;
}

// func_00336640 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00336640
extern "C" int func_00336640(UnkStruct_00336640 * self, int p0)
{
    if (func_0040E8B0(self->field_62C) <= 0) {
        return 1;
    }
    if (func_0040E638(self->field_62C, 0, p0) != 0) {
        self->field_630 = 0;
        return 1;
    }
    self->field_110 = 1;
    self->field_111 = 0;
    self->field_112 = 0;
    self->field_120 = 0;
    self->field_114 = 0;
    self->field_630 = 1;
    return self->vfunc_14();
}

// func_00336780 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00336780
extern "C" int func_00336780(void *a0 /* passed by every caller, not read here */)
{
    return 1;
}

// func_00336790 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00336790
extern "C" int func_00336790(UnkStruct_00336790 *self)
{
    return func_0040DA90(self->field_61C, 0, -91);
}

// CGtLobbyPS2DirtySock::GetNumberRankRecords() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtLobbyDirtySock.cpp.
// 0x003367A0
// [C] returns func_0040D730's result: retail 0x3367A0 is `j func_0040D730` (a tail call, so v0 is the callee's), and
// func_00377E30 compares it at 0x377F30 (`slti $at, $v0, 0x6`) and 0x377F58 and adds it at 0x377FD4.
int CGtLobbyPS2DirtySock::GetNumberRankRecords()
{
    return func_0040D730(field_61C);
}

// func_00336B20 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00336B20
extern "C" int func_00336B20(UnkStruct_00336B20 * self, int p0, int p1, int p2, int p3, int p4, int p5)
{
    func_0040CF08(self->field_61C, 1);
    if (func_0040CDB8(self->field_61C, p0, p1, p2) != 0) {
        return 1;
    }
    self->field_110 = 1;
    self->field_111 = 0;
    self->field_112 = 0;
    self->field_120 = 0;
    self->field_114 = 0;
    if (func_0040D020(self->field_61C, 0, p3, p5, p4, p5, &func_003366E0, self) != 0) {
        return 1;
    }
    return self->vfunc_14();
}

// func_00336DF0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00336DF0
extern "C" int func_00336DF0(UnkStruct_00336DF0 * self)
{
    if (!self->field_61C) {
        return 1;
    }
    if (self->vfunc_14() != 2) {
        if (func_0040C9D0(self->field_61C, 0x63617465) == 0 || func_0040C9D0(self->field_61C, 0x6C697374) == 0) {
            self->field_111 = 1;
        }
    }
    if (self->field_61C != 0) {
        func_0040C848(self->field_61C);
        self->field_61C = 0;
    }
    return 1;
}

// CGtLobbyPS2DirtySock::GetCurrentLobbyName() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> GtLobbyDirtySock.cpp.
// 0x00337860
int CGtLobbyPS2DirtySock::GetCurrentLobbyName()
{
    return (field_25C + 28);
}

// func_003379B0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x003379B0
extern "C" void func_003379B0(int n0, int p0, int p1, int p2)
{
    strcasecmp((p1 + 8), (p2 + 8));
}

// func_003379C0 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x003379C0
extern "C" int func_003379C0(UnkStruct_003379C0 *self, int p0, int p1)
{
    self->field_604 = p0;
    self->field_608 = p1;
    return 1;
}

// CGtLobbyPS2DirtySock::SendChatMessage(char*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtLobbyDirtySock.cpp.
// 0x003379D0
int CGtLobbyPS2DirtySock::SendChatMessage(char* p0)
{
    if ((field_104 == 0) || (field_11E == 0)) {
        return 0;
    }
    D_004E2DAC.field_0->field_0 = 0;
    TagFieldSetString(D_004E2DAC.field_0, 1024, &D_004C5978, p0);
    if (field_11C != 0) {
        TagFieldSetFlags(D_004E2DAC.field_0, 1024, &D_004C5980, 0x40000088);
    } else {
        TagFieldSetFlags(D_004E2DAC.field_0, 1024, &D_004C5980, 0x40000008);
    }
    LobbyApiRequestCB(field_104, 0x6D657367, D_004E2DAC.field_0, 0, 0);
    return 1;
}

// CGtLobbyPS2DirtySock::IsLoggedIntoLobby() const -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> GtLobbyDirtySock.cpp.
// 0x00337AA0
unsigned char CGtLobbyPS2DirtySock::IsLoggedIntoLobby() const
{
    return field_11E;
}

// CGtLobbyPS2DirtySock::GetGameID() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> GtLobbyDirtySock.cpp.
// 0x00337AB0
int CGtLobbyPS2DirtySock::GetGameID()
{
    return field_12C;
}

// CGtLobbyPS2DirtySock::AmIInGame() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> GtLobbyDirtySock.cpp.
// 0x00337AC0
unsigned char CGtLobbyPS2DirtySock::AmIInGame()
{
    return field_11C;
}

// CGtLobbyPS2DirtySock::GetSessionKey() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> GtLobbyDirtySock.cpp.
// 0x00337B00
void * CGtLobbyPS2DirtySock::GetSessionKey()
{
    return (char *)this + 0x3C0;
}

// CGtLobbyPS2DirtySock::GetAlternateAccountName(int) const -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtLobbyDirtySock.cpp.
// 0x003380D0
void * CGtLobbyPS2DirtySock::GetAlternateAccountName(int p0) const
{
    return ((char *)&field_0[p0] + 0x370);
}

// func_00338950 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00338950
extern "C" int func_00338950(UnkStruct_00338950 *self, int p0, int p1)
{
    self->field_588 = p0;
    self->field_58C = p1;
    return 1;
}

// func_00338C10 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00338C10
extern "C" int func_00338C10(int n0, int p0, UnkStruct_00338C10_a2 * p1)
{
    return (p1->field_8 & 8);
}

// CGtLobbyPS2DirtySock::HasLaunched() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> GtLobbyDirtySock.cpp.
// 0x00338DF0
bool CGtLobbyPS2DirtySock::HasLaunched()
{
    return ((field_134->field_114 & 0x80000) != 0);
}

// func_00338E10 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00338E10
extern "C" void func_00338E10()
{
}

// CGtLobbyPS2DirtySock::GetLastError() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> GtLobbyDirtySock.cpp.
// 0x00338E80
int CGtLobbyPS2DirtySock::GetLastError()
{
    field_112 = 0;
    field_110 = 0;
    field_111 = 1;
    return field_114;
}

// CGtLobbyPS2DirtySock::GetNumPlayersInLobby() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtLobbyDirtySock.cpp.
// 0x003391A0
void CGtLobbyPS2DirtySock::GetNumPlayersInLobby()
{
    DispListOrder(field_56C);
    func_0040A5D0(field_56C);
}

// func_00339380 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00339380
extern "C" int func_00339380(UnkStruct_00339380 * self, UnkStruct_00339380_a1 * p0)
{
    UnkStruct_00339380_1 * r0 = LobbyApiInfoPtr(self->field_104, 0x73656C66);
    p0->field_0 = r0->field_24;
    return 1;
}

// func_0033AC60 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x0033AC60
extern "C" void func_0033AC60(void *n0_, UnkStruct_0033AC60_a1 * p0, UnkStruct_0033AC60_a2 * p1)
{
    int n0 = (int)n0_;
    CGtLobbyPS2DirtySock * t0 = p0->field_C;
    if (t0 == 0) {
        int r0 = TagFieldFind(p0->field_10, &D_004C59A8);
        int r1 = TagFieldGetNumber(r0, -1);
        p1->field_260 = r1;
        p1->field_111 = 1;
    } else {
        int r2 = t0->ConvertDirtySockError((int)p0);
        p1->field_112 = 1;
        p1->field_110 = 0;
        p1->field_114 = r2;
    }
}

// func_0033ACD0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x0033ACD0
extern "C" void func_0033ACD0(UnkStruct_0033ACD0 * self, UnkStruct_0033ACD0_a1 * p0)
{
    p0->field_0 = ((char *)self + 0x484);
    p0->field_4 = ((char *)self + 0x505);
    p0->field_8 = ((char *)self + 0x4C5);
    p0->field_10 = 0;
    p0->field_14 = 0;
    p0->field_18 = 0;
    p0->field_1C = 0;
    p0->field_20 = self->field_545;
    p0->field_21 = self->field_546;
}

// CGtLobbyPS2DirtySock::CheckGameStillExists() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtLobbyDirtySock.cpp.
// 0x0033B400
int CGtLobbyPS2DirtySock::CheckGameStillExists()
{
    DispListOrder(field_564);
    for (int i = 0; (i < DispListCount(field_564)); i++) {
        UnkStruct_0033B400_1 * r1 = DispListIndex(field_564, i);
        if (r1->field_0 == field_12C) {
            return 1;
        }
    }
    field_11C = 0;
    field_11D = 0;
    field_12C = -1;
    field_134 = 0;
    field_121 = 0;
    field_124 = 0;
    field_130 = 0;
    field_444 = 0;
    ((void (*)(int, int))field_558)(1, field_55C);
    return 0;
}

// func_0033BB90 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x0033BB90
extern "C" int func_0033BB90(UnkStruct_0033BB90 * self)
{
    if (self->field_120 == 0) {
        return 0;
    }
    self->field_120 = 0;
    self->field_11C = 0;
    self->field_11D = 0;
    self->field_12C = -1;
    self->field_134 = 0;
    self->field_121 = 0;
    self->field_124 = 0;
    self->field_130 = 0;
    self->field_25C = 0;
    self->field_444 = 0;
    self->vfunc_2C();
    if (self->field_588 != 0) {
        self->field_588(-1, self->field_58C);
    }
    return 1;
}

// CGtLobbyPS2DirtySock::GetLobbyStatus() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> GtLobbyDirtySock.cpp.
// 0x0033BC20
extern "C" int GetLobbyStatus__20CGtLobbyPS2DirtySockFv(UnkStruct_0033BC20 *self)
{
    if (self->field_10C != 0) return 0;
    if (self->field_111 != 0) {
        self->field_110 = 0;
        self->field_111 = 0;
        return 2;
    }
    if (self->field_112 != 0) return 1;
    return self->field_110 ? 0 : 2;
}

// func_0033BD80 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x0033BD80
extern "C" void func_0033BD80(UnkStruct_0033BD80 * self, int p0, int p1)
{
    memset((void *)p0, 0, p1);
    if (self->field_264 == 0) {
        _gMemoryAllocator.Create((void*)p0, p1);
        self->field_264 = 1;
    }
}

// CGtLobbyPS2DirtySock::GetMemoryRequirements(int) -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> GtLobbyDirtySock.cpp.
// 0x0033BDF0
int CGtLobbyPS2DirtySock::GetMemoryRequirements(int p0)
{
    return 0;
}

// func_0033C670 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x0033C670
extern "C" void func_0033C670(void *n0_, UnkStruct_0033C670_a1 * p0, UnkStruct_0033C670_a2 * p1)
{
    int n0 = (int)n0_;
    if (p0->field_8 == 0x64697363) {
        p1->field_110 = 0;
        p1->field_111 = 0;
        p1->field_112 = 0;
        p1->field_11C = 0;
        p1->field_12C = -1;
        p1->field_11E = 0;
        p1->field_134 = 0;
        p1->field_121 = 0;
        p1->field_124 = 0;
        p1->field_128 = 0;
        p1->field_130 = 0;
        p1->field_11F = 0;
        p1->field_120 = 1;
        int r0 = p0->field_C->ConvertDirtySockError((int)p0);
        p1->field_112 = 1;
        p1->field_110 = 0;
        p1->field_114 = r0;
        if ((int)p0->field_C != 0x646F776E) {
        } else {
            strncpy((char *)((char *)p1 + 0x4), (const char *)p0->field_10, 256);
        }
    } else {
    }
}

// CGtLobbyPS2DirtySock::Destruct() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> GtLobbyDirtySock.cpp.
// 0x0033C810
void CGtLobbyPS2DirtySock::Destruct()
{
}

// CGtLobbyPS2DirtySock::Construct(int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> GtLobbyDirtySock.cpp.
// 0x0033C820
void CGtLobbyPS2DirtySock::Construct(int p0)
{
    field_104 = 0;
    field_108 = 0;
    field_114 = 0;
    field_560 = 0;
    field_564 = 0;
    field_568 = 0;
    field_56C = 0;
    field_60C = -1;
    field_610 = -1;
    field_614 = -1;
    field_618 = -1;
    field_634 = &D_004C57C8;
    field_264 = 0;
    field_638 = 0;
    D_004E2DAC.field_0 = 0;
}

// CGtLobbyDirtySockCachedPlayerParams::LoadFromString(char*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtLobbyDirtySock.cpp.
// 0x0033C8D0
void CGtLobbyDirtySockCachedPlayerParams::LoadFromString(char* p0)
{
    UnkStruct_0033C8D0_1 local;  // [G] the frame's one local (size: up to the frame top)
    if (*p0 != 0) {
        for (int i = 0; (i < 3); i++) {
            strcpy((char *)&local, (const char *)p0);
            func_00128BE8(&local, &D_004C5990);
            field_0[i] = atoi(&local);
            p0 += strlen((const char *)&local) + 1;
        }
    } else {
        for (int i1 = 0; (i1 < 3); i1++) {
            field_0[i1] = -1;
        }
    }
}
