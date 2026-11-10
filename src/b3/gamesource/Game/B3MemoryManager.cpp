// B3MemoryManager.cpp -- translation unit regrouped by tools/tu_merge.py from 8 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 3 function(s) named in research/retail_names.csv -> B3MemoryManager.cpp, 3 by a medium-confidence name confirmed by a neighbour, 2 placed between two of them by address contiguity (N2).
// Area: src/b3/gamesource/Game, [L] Revenge (SLUS_212.42) GameSource/Game/B4MemoryManager.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3ManagedMemoryBlock.h"
#include "b3/classes/CB3MemoryManager.h"
#include "b3/classes/EB3MemoryLayout.h"

struct UnkStruct_003E8B80;
struct UnkStruct_003E87A0;
struct UnkStruct_003E87A0_e0;
struct UnkStruct_003E87A0_e1;
struct UnkStruct_003E87A0_e2;
struct UnkStruct_003E87A0_e3;
struct UnkStruct_003E87A0_e4;
struct UnkStruct_003E87A0_e5;
struct UnkStruct_003E87A0_e6;
struct UnkStruct_003E87A0_e7;
struct UnkStruct_003E87A0_e8;

struct UnkStruct_003E8750 {
    unsigned char pad_0[0x988];
    int field_988;
};

struct UnkStruct_003E8B70 {
    unsigned char pad_0[0x8];
    int field_8;
};

struct UnkStruct_003E8B80 {
    int field_0;
};

struct UnkStruct_003E8C00 {
    int field_0;
    int field_4;
    int field_8;
    int field_C;
};

struct UnkStruct_003E87A0_e0 {
    unsigned char pad_0[0x4];
    int field_4;
    unsigned char pad_8[0x8];
};

struct UnkStruct_003E87A0_e1 {
    unsigned char pad_0[0x4];
    int field_4;
    unsigned char pad_8[0x8];
};

struct UnkStruct_003E87A0_e2 {
    unsigned char pad_0[0x4];
    int field_4;
    unsigned char pad_8[0x8];
};

struct UnkStruct_003E87A0_e3 {
    unsigned char pad_0[0x4];
    int field_4;
    unsigned char pad_8[0x8];
};

struct UnkStruct_003E87A0_e4 {
    unsigned char pad_0[0x4];
    int field_4;
    unsigned char pad_8[0x8];
};

struct UnkStruct_003E87A0_e5 {
    unsigned char pad_0[0x4];
    int field_4;
    unsigned char pad_8[0x8];
};

struct UnkStruct_003E87A0_e6 {
    unsigned char pad_0[0x4];
    int field_4;
    unsigned char pad_8[0x8];
};

struct UnkStruct_003E87A0_e7 {
    unsigned char pad_0[0x4];
    int field_4;
    unsigned char pad_8[0x8];
};

struct UnkStruct_003E87A0_e8 {
    unsigned char pad_0[0x4];
    int field_4;
    unsigned char pad_8[0x8];
};

struct UnkStruct_003E87A0 {
    unsigned char pad_0[0x4];
    int field_4;
    unsigned char pad_8[0xC];
    int field_14;
    unsigned char pad_18[0xC];
    int field_24;
    unsigned char pad_28[0xC];
    int field_34;
    unsigned char pad_38[0xC];
    int field_44;
    unsigned char pad_48[0xC];
    int field_54;
    unsigned char pad_58[0xC];
    int field_64;
    unsigned char pad_68[0x8];
    UnkStruct_003E87A0_e0 field_70[1];  // [G] element count unknown
    unsigned char pad_80[0x74];
    int field_F4;
    unsigned char pad_F8[0x8];
    UnkStruct_003E87A0_e7 field_100[1];  // [G] element count unknown
    unsigned char pad_110[0x54];
    int field_164;
    unsigned char pad_168[0xC];
    int field_174;
    unsigned char pad_178[0x8];
    UnkStruct_003E87A0_e1 field_180[1];  // [G] element count unknown
    unsigned char pad_190[0x90];
    UnkStruct_003E87A0_e2 field_220[1];  // [G] element count unknown
    unsigned char pad_230[0x114];
    int field_344;
    unsigned char pad_348[0xC];
    int field_354;
    unsigned char pad_358[0x8];
    UnkStruct_003E87A0_e5 field_360[1];  // [G] element count unknown
    unsigned char pad_370[0xB0];
    UnkStruct_003E87A0_e8 field_420[1];  // [G] element count unknown
    unsigned char pad_430[0x54];
    int field_484;
    unsigned char pad_488[0xC];
    int field_494;
    unsigned char pad_498[0x8];
    UnkStruct_003E87A0_e3 field_4A0[1];  // [G] element count unknown
    unsigned char pad_4B0[0x120];
    UnkStruct_003E87A0_e4 field_5D0[1];  // [G] element count unknown
    unsigned char pad_5E0[0x224];
    int field_804;
    unsigned char pad_808[0xC];
    int field_814;
    unsigned char pad_818[0x8];
    UnkStruct_003E87A0_e6 field_820[1];  // [G] element count unknown
    unsigned char pad_830[0xB4];
    int field_8E4;
    unsigned char pad_8E8[0xC];
    int field_8F4;
    unsigned char pad_8F8[0xC];
    int field_904;
    unsigned char pad_908[0xC];
    int field_914;
    unsigned char pad_918[0xC];
    int field_924;
    unsigned char pad_928[0xC];
    int field_934;
    unsigned char pad_938[0xC];
    int field_944;
    unsigned char pad_948[0xC];
    int field_954;
    unsigned char pad_958[0xC];
    int field_964;
    unsigned char pad_968[0xC];
    int field_974;
    unsigned char pad_978[0xC];
    int field_984;
    int field_988;
};

// func_003E8750 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x003E8750
extern "C" void func_003E8750(UnkStruct_003E8750 *self)
{
    self->field_988 = 2;
}

// CB3MemoryManager::AcquireMemoryLayout(EB3MemoryLayout) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3MemoryManager.cpp.
// 0x003E8760
int CB3MemoryManager::AcquireMemoryLayout(EB3MemoryLayout p0)
{
    if (field_988 <= 0) {
        if (field_984 != p0) {
            field_984 = p0;
            return 1;
        }
        return 1;
    }
    return 0;
}

// func_003E87A0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x003E87A0
extern "C" void func_003E87A0(UnkStruct_003E87A0 * self)
{
    int t0 = self->field_988;
    if (t0 > 0) {
        self->field_988 = (t0 + -1);
        if (self->field_988 == 0) {
            self->field_984 = -1;
        }
    }
    int t1 = self->field_54;
    if (t1 > 0) {
        self->field_54 = (t1 + -1);
    }
    int t2 = self->field_64;
    if (t2 > 0) {
        self->field_64 = (t2 + -1);
    }
    for (int i = 0; (i < 8); i++) {
        int t3 = self->field_70[i].field_4;
        if (t3 > 0) {
            self->field_70[i].field_4 = (t3 + -1);
        }
    }
    int t4 = self->field_F4;
    if (t4 > 0) {
        self->field_F4 = (t4 + -1);
    }
    int t5 = self->field_14;
    if (t5 > 0) {
        self->field_14 = (t5 + -1);
    }
    int t6 = self->field_24;
    if (t6 > 0) {
        self->field_24 = (t6 + -1);
    }
    int t7 = self->field_34;
    if (t7 > 0) {
        self->field_34 = (t7 + -1);
    }
    int t8 = self->field_344;
    if (t8 > 0) {
        self->field_344 = (t8 + -1);
    }
    int t9 = self->field_174;
    if (t9 > 0) {
        self->field_174 = (t9 + -1);
    }
    int t10 = self->field_164;
    if (t10 > 0) {
        self->field_164 = (t10 + -1);
    }
    int t11 = self->field_354;
    if (t11 > 0) {
        self->field_354 = (t11 + -1);
    }
    for (int i1 = 0; (i1 < 10); i1++) {
        int t12 = self->field_180[i1].field_4;
        if (t12 > 0) {
            self->field_180[i1].field_4 = (t12 + -1);
        }
    }
    for (int i2 = 0; (i2 < 18); i2++) {
        int t13 = self->field_220[i2].field_4;
        if (t13 > 0) {
            self->field_220[i2].field_4 = (t13 + -1);
        }
    }
    int t14 = self->field_804;
    if (t14 > 0) {
        self->field_804 = (t14 + -1);
    }
    int t15 = self->field_494;
    if (t15 > 0) {
        self->field_494 = (t15 + -1);
    }
    int t16 = self->field_484;
    if (t16 > 0) {
        self->field_484 = (t16 + -1);
    }
    int t17 = self->field_814;
    if (t17 > 0) {
        self->field_814 = (t17 + -1);
    }
    for (int i3 = 0; (i3 < 19); i3++) {
        int t18 = self->field_4A0[i3].field_4;
        if (t18 > 0) {
            self->field_4A0[i3].field_4 = (t18 + -1);
        }
    }
    for (int i4 = 0; (i4 < 35); i4++) {
        int t19 = self->field_5D0[i4].field_4;
        if (t19 > 0) {
            self->field_5D0[i4].field_4 = (t19 + -1);
        }
    }
    int t20 = self->field_4;
    if (t20 > 0) {
        self->field_4 = (t20 + -1);
    }
    int t21 = self->field_44;
    if (t21 > 0) {
        self->field_44 = (t21 + -1);
    }
    for (int i5 = 0; (i5 < 12); i5++) {
        int t22 = self->field_360[i5].field_4;
        if (t22 > 0) {
            self->field_360[i5].field_4 = (t22 + -1);
        }
        int t23 = self->field_820[i5].field_4;
        if (t23 > 0) {
            self->field_820[i5].field_4 = (t23 + -1);
        }
    }
    for (int i6 = 0; (i6 < 6); i6++) {
        int t24 = self->field_100[i6].field_4;
        if (t24 > 0) {
            self->field_100[i6].field_4 = (t24 + -1);
        }
        int t25 = self->field_420[i6].field_4;
        if (t25 > 0) {
            self->field_420[i6].field_4 = (t25 + -1);
        }
    }
    int t26 = self->field_8E4;
    if (t26 > 0) {
        self->field_8E4 = (t26 + -1);
    }
    int t27 = self->field_8F4;
    if (t27 > 0) {
        self->field_8F4 = (t27 + -1);
    }
    int t28 = self->field_924;
    if (t28 > 0) {
        self->field_924 = (t28 + -1);
    }
    int t29 = self->field_914;
    if (t29 > 0) {
        self->field_914 = (t29 + -1);
    }
    int t30 = self->field_934;
    if (t30 > 0) {
        self->field_934 = (t30 + -1);
    }
    int t31 = self->field_944;
    if (t31 > 0) {
        self->field_944 = (t31 + -1);
    }
    int t32 = self->field_964;
    if (t32 > 0) {
        self->field_964 = (t32 + -1);
    }
    int t33 = self->field_974;
    if (t33 > 0) {
        self->field_974 = (t33 + -1);
    }
    int t34 = self->field_904;
    if (t34 > 0) {
        self->field_904 = (t34 + -1);
    }
    int t35 = self->field_954;
    if (t35 <= 0) return;
    self->field_954 = (t35 + -1);
}

// func_003E8B70 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x003E8B70
extern "C" int func_003E8B70(UnkStruct_003E8B70 *self)
{
    return self->field_8;
}

// Update__21CB3ManagedMemoryBlockFi -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x003E8B80
extern "C" void Update__21CB3ManagedMemoryBlockFi(UnkStruct_003E8B80 * self)
{
    int t0 = self->field_0;
    if (t0 <= 0) return;
    self->field_0 = (t0 + -1);
}

// CB3ManagedMemoryBlock::ReleaseMemoryBlock(int) -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3MemoryManager.cpp.
// 0x003E8BA0
void CB3ManagedMemoryBlock::ReleaseMemoryBlock(int p0)
{
    field_0 = 2;
}

// CB3ManagedMemoryBlock::GetMemoryBlock(int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3MemoryManager.cpp.
// 0x003E8BB0
int CB3ManagedMemoryBlock::GetMemoryBlock(int p0)
{
    int t0 = field_4;
    if ((t0 < 0) || (t0 == p0)) {
        if (field_0 == 0) {
            field_0 = -1;
            return field_C;
        }
        return 0;
    }
    return 0;
}

// Construct__21CB3ManagedMemoryBlockFPvii -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x003E8C00
extern "C" void Construct__21CB3ManagedMemoryBlockFPvii(UnkStruct_003E8C00 *self, int p0, int p1, int p2)
{
    self->field_0 = 0;
    self->field_C = p0;
    self->field_4 = p1;
    self->field_8 = p2;
}
