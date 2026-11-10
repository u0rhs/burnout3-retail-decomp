// GTMemoryDevicePS2_MC2.cpp -- translation unit regrouped by tools/tu_merge.py from 9 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 8 function(s) named in research/retail_names.csv -> GTMemoryDevicePS2_MC2.cpp, 1 placed between two of them by address contiguity (N2).
// Area: src/b3/GameShared/GameClasses/System/MemoryCard/ps2, [L] Revenge (SLUS_212.42) GameShared/GameClasses/System/MemoryCard/ps2/GTMemoryDevicePS2_MC2.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CMemoryDevicePS2.h"
#include "b3/classes/EMemDevPollOrWait.h"
#include "b3/classes/UnkStruct_D_01E88980.h"

struct UnkStruct_0030A8E0;
struct UnkStruct_0030A8E0_1;

struct UnkStruct_0030A8C0 {
    unsigned char pad_0[0x58];
    int field_58;
};

struct UnkStruct_0030A8E0_1 {
    int field_0;
    int field_4;
    int field_8;
    unsigned char pad_C[0x14];
};

struct UnkStruct_0030A8E0 {
    int field_0;
    unsigned char pad_4[0x48];
    int field_4C;
    int field_50;
    int field_54;
    int field_58;
    unsigned char pad_5C[0x74];
    int field_D0;
    int field_D4;
    int field_D8;
};

extern UnkStruct_D_01E88980 D_01E88980;
extern "C" int func_00242688(int, const char*);
extern "C" int sceMc2GetDirAsync(int, const char*, int, int, void *, void *);
extern "C" int func_00242128(int, const char*, void *);
extern "C" int sceMc2Init(int);
extern "C" int sceMc2CreateSocket(UnkStruct_0030A8E0_1 *, void *);
extern "C" int func_00242268(int, void *, char*, unsigned int, unsigned int);

// CMemoryDevicePS2::MkDir(const char*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GTMemoryDevicePS2_MC2.cpp.
// 0x0030A310
int CMemoryDevicePS2::MkDir(const char* p0)
{
    int r0 = func_00242688(field_54, p0);
    if (r0 == 0) {
        return 1;
    }
    field_4C = 0;
    field_50 = 14;
    field_58 = 13;
    field_D0 = 0;
    field_D8 = -1;
    field_D4 = 1;
    return 0;
}

// CMemoryDevicePS2::Read(char*,unsigned int,unsigned int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GTMemoryDevicePS2_MC2.cpp.
// 0x0030A4D0
int CMemoryDevicePS2::Read(char* p0, unsigned int p1, unsigned int p2)
{
    if ((field_4C & 1) == 0) {
        field_4C = 0;
        field_50 = 14;
        field_58 = 13;
        field_D0 = 0;
        field_D8 = -1;
        field_D4 = 1;
        return 0;
    }
    if (func_00242268(field_54, ((char *)this + 0x4), p0, p2, p1) == 0) {
        return 1;
    }
    field_4C = 0;
    field_50 = 14;
    field_58 = 13;
    field_D0 = 0;
    field_D8 = -1;
    field_D4 = 1;
    return 0;
}

// CMemoryDevicePS2::CloseFile() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GTMemoryDevicePS2_MC2.cpp.
// 0x0030A580
int CMemoryDevicePS2::CloseFile()
{
    int v0;
    if (field_4C == 0) {
        field_4C = 0;
        field_50 = 14;
        field_58 = 13;
        field_D0 = 0;
        field_D8 = -1;
        field_D4 = 1;
        v0 = 0;
    } else {
        field_4C = 0;
        field_50 = 5;
        v0 = 1;
    }
    return v0;
}

// CMemoryDevicePS2::GetFreeSpace() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GTMemoryDevicePS2_MC2.cpp.
// 0x0030A7B0
int CMemoryDevicePS2::GetFreeSpace()
{
    int t0 = field_D8;
    int v0;
    if (t0 < 0) {
        v0 = -1;
    } else {
        v0 = (t0 << 10);
    }
    return v0;
}

// CMemoryDevicePS2::GetFileSize(const char*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GTMemoryDevicePS2_MC2.cpp.
// 0x0030A7D0
int CMemoryDevicePS2::GetFileSize(const char* p0)
{
    int r0 = sceMc2GetDirAsync(field_54, p0, 0, 1, ((char *)this + 0x94), ((char *)this + 0xCC));
    if (r0 == 0) {
        return 1;
    }
    field_4C = 0;
    field_50 = 14;
    field_58 = 13;
    field_D0 = 0;
    field_D8 = -1;
    field_D4 = 1;
    return 0;
}

// CMemoryDevicePS2::FileExists(const char*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GTMemoryDevicePS2_MC2.cpp.
// 0x0030A850
int CMemoryDevicePS2::FileExists(const char* p0)
{
    int r0 = func_00242128(field_54, p0, ((char *)this + 0x5C));
    if (r0 == 0) {
        return 1;
    }
    field_4C = 0;
    field_50 = 14;
    field_58 = 13;
    field_D0 = 0;
    field_D8 = -1;
    field_D4 = 1;
    return 0;
}

// func_0030A8C0 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x0030A8C0
extern "C" int func_0030A8C0(UnkStruct_0030A8C0 *self)
{
    return self->field_58;
}

// CMemoryDevicePS2::GetError() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GTMemoryDevicePS2_MC2.cpp.
// 0x0030A8D0
int CMemoryDevicePS2::GetError()
{
    return field_0;
}

// Init__16CMemoryDevicePS2Fv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x0030A8E0
extern "C" int Init__16CMemoryDevicePS2Fv(UnkStruct_0030A8E0 * self)
{
    UnkStruct_0030A8E0_1 local;  // [G] the frame's one local (size: up to the frame top)
    self->field_0 = 0;
    self->field_4C = 0;
    self->field_50 = 14;
    self->field_58 = 0;
    self->field_D0 = 0;
    self->field_D8 = -1;
    self->field_D4 = 1;
    int r0 = sceMc2Init(0);
    if (r0 != 0) {
        return 0;
    }
    local.field_0 = 2;
    local.field_4 = 2;
    local.field_8 = 0;
    int r1 = sceMc2CreateSocket(&local, &D_01E88980);
    self->field_54 = r1;
    return ((self->field_54 < 0) ^ 1);
}
