// GtPS2LibNet.cpp -- translation unit regrouped by tools/tu_merge.py from 7 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 2 function(s) named in research/retail_names.csv -> GtPS2LibNet.cpp, 1 by a medium-confidence name confirmed by a neighbour, 4 placed between two of them by address contiguity (N2).
// Area: src/b3/GameShared/GameClasses/System/Networking/Packeting/Ps2, [L] Revenge (SLUS_212.42) GameShared/GameClasses/System/Networking/Packeting/Ps2/GtPS2LibNet.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CGtPS2LibNet.h"
#include "b3/classes/UnkStruct_D_01D7AF00.h"

struct UnkStruct_0022E6C0_a1;
struct UnkStruct_0022E790;
struct UnkStruct_0022E790_e0;
struct UnkStruct_0022EB40_1;

struct UnkStruct_0022E6C0_a1 {
    int field_0;
    int field_4;
    int field_8;
};

struct UnkStruct_0022E790_e0 {
    unsigned char pad_0[0xC];
    int field_C;
    unsigned char pad_10[0x8];
};

struct UnkStruct_0022E790 {
    unsigned char pad_0[0x3C];
    int field_3C;
    unsigned char pad_40[0x5C];
    int field_9C;
    unsigned char pad_A0[0x8];
    UnkStruct_0022E790_e0 field_A8[1];  // [G] element count unknown
    unsigned char pad_C0[0x2F4];
    int field_3B4;
    int field_3B8;
};

struct UnkStruct_0022EB20 {
    unsigned char pad_0[0x710];
    int field_710;
};

struct UnkStruct_0022EB40_1 {
    unsigned char pad_0[0x1];
    unsigned char field_1;
    short field_2;
    int field_4;
    unsigned char pad_8[0x8];
};

extern UnkStruct_D_01D7AF00 D_01D7AF00;
extern int D_0049B540[];  // [G] element count unknown
extern int D_0049B5C0[];  // [G] element count unknown
extern int D_0049B640[];  // [G] element count unknown
extern int D_0049B580[];  // [G] element count unknown
extern int D_0049B600[];  // [G] element count unknown
extern "C" unsigned int strlen(const char *);
extern "C" void WaitSema(int);
extern "C" void SignalSema(int);
extern "C" void * memset(void *, int, unsigned int);
extern "C" int func_00237320(int);
extern "C" int sceInsockSocket(int, int, int);
extern "C" void sceInsockBind(int, UnkStruct_0022EB40_1 *, int);
extern "C" void ResumeThread(int);
extern "C" void SuspendThread(int);
extern "C" void sceInsockShutdown(int, int);

// func_0022E6B0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x0022E6B0
extern "C" void * func_0022E6B0(void *a0 /* passed by every caller, not read here */)
{
    return &D_01D7AF00;
}

// func_0022E6C0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x0022E6C0
extern "C" int func_0022E6C0(void *n0_, UnkStruct_0022E6C0_a1 * p0, int p1, int p2)
{
    int n0 = (int)n0_;
    unsigned int r0 = strlen((const char *)D_0049B540[p1]);
    if (r0 != 0) {
        p0->field_0 = D_0049B540[p1];
        if (p2 != 0) {
            p0->field_4 = D_0049B5C0[p1];
            p0->field_8 = D_0049B640[p1];
        } else {
            p0->field_4 = D_0049B580[p1];
            p0->field_8 = D_0049B600[p1];
        }
        return 1;
    }
    return 0;
}

// ClearSendBuffer__12CGtPS2LibNetFv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x0022E790
extern "C" void ClearSendBuffer__12CGtPS2LibNetFv(UnkStruct_0022E790 * self)
{
    WaitSema(self->field_9C);
    for (int i = 0; (i < 32); i++) {
        int t0 = self->field_3C;
        if (t0 != 0) {
            int t1 = self->field_A8[i].field_C;
            if (t1 != 0) {
                ((void (*)(int))t0)(t1);
            }
        }
        self->field_A8[i].field_C = 0;
    }
    self->field_3B4 = 0;
    self->field_3B8 = 0;
    SignalSema(self->field_9C);
}

// TCPDestroy__12CGtPS2LibNetFv -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x0022EB20
extern "C" void TCPDestroy__12CGtPS2LibNetFv(UnkStruct_0022EB20 *self)
{
    self->field_710 = 5;
}

// CGtPS2LibNet::ResumeSocket(int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> GtPS2LibNet.cpp.
// 0x0022EB40
void CGtPS2LibNet::ResumeSocket(int p0)
{
    UnkStruct_0022EB40_1 local;  // [G] the frame's one local (size: up to the frame top)
    field_70C = (field_70C + -1);
    if (field_70C == 0) {
        field_704 = p0;
        memset(&local, 0, 16);
        local.field_1 = 2;
        int r1 = func_00237320((p0 & 65535));
        local.field_2 = r1;
        local.field_4 = field_A8;
        int r2 = sceInsockSocket(2, 2, 0);
        field_AC = r2;
        sceInsockBind(field_AC, &local, 16);
        field_4C = 1;
        ResumeThread(field_8C);
        ResumeThread(field_90);
    }
}

// CGtPS2LibNet::SuspendSocket() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtPS2LibNet.cpp.
// 0x0022EC00
void CGtPS2LibNet::SuspendSocket()
{
    if (field_70C == 0) {
        SuspendThread(field_8C);
        SuspendThread(field_90);
        sceInsockShutdown(field_AC, 2);
        field_AC = -1;
    }
    field_70C = (field_70C + 1);
}

// CGtPS2LibNet::UpInterface(int) -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtPS2LibNet.cpp.
// 0x0022F000
int CGtPS2LibNet::UpInterface(int p0)
{
    field_A4 = p0;
    field_48 = 5;
    field_14 = 1;
    field_4C = 0;
    return field_14;
}
