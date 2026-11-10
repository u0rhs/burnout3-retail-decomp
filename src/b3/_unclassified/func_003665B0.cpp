// func_003665B0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (if/else-if up/down chain; highlight block as a static inline helper [G] (CGtV2d declare-then-assign from GetRowPos/GetRowSize by value); field_E7C int (out-of-line then-blocks); int t0; early return for field_E84).

// from build/vt\try_func_003665B0_best.cpp
// func_003665B0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

class CB3InputManager;

class CGt2dObjectTable {
public:
    CGtV2d GetRowPos(int);   // [G] return type: an 8-byte result through a0 (hidden pointer), as func_0033FF10
    CGtV2d GetRowSize(int);  // [G] as GetRowPos
};

class CB3Panel2dObject {
public:
    void Prepare(const CGtV2d &, const CGtV2d &, const CGtV2d &, unsigned int, float);
};

class CGtBuddiesPS2DirtySock;
struct UnkStruct_003665B0;
struct UnkStruct_003665B0_1;
struct UnkStruct_D_01E7A800;
struct UnkStruct_krB3BuddyTableSize;

class CB3InputManager {
public:
    int GetMenuUp(signed char);
    int GetMenuDown(signed char);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CGtBuddiesPS2DirtySock {
public:
    int GetNumBuddies();

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003665B0_1 {
    int field_0;
    int field_4;
    unsigned long field_8;
    unsigned long field_10;
    float field_18;
    unsigned char pad_1C[0x4];
    float field_20;
    unsigned char pad_24[0x4];
    int field_28;
    int field_2C;
    unsigned long field_30;
    unsigned long field_38;
    float field_40;
    unsigned char pad_44[0x4];
    float field_48;
    unsigned char pad_4C[0x4];
    int field_50;
    int field_54;
    unsigned long field_58;
    unsigned long field_60;
    float field_68;
    unsigned char pad_6C[0x4];
    float field_70;
    unsigned char pad_74[0x4];
    int field_78;
    int field_7C;
    unsigned long field_80;
    unsigned long field_88;
    float field_90;
    unsigned char pad_94[0x4];
    float field_98;
    unsigned char pad_9C[0x4];
};

struct UnkStruct_krB3BuddyTableSize {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E7A800 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003665B0 {
    unsigned char pad_0[0xE6C];
    CGt2dObjectTable * field_E6C;
    unsigned char pad_E70[0x8];
    unsigned short field_E78;
    unsigned char pad_E7A[0x2];
    int field_E7C;
    int field_E80;
    unsigned char field_E84;
};

extern UnkStruct_krB3BuddyTableSize krB3BuddyTableSize;
extern CB3InputManager D_004F50C0;
extern UnkStruct_D_01E7A800 D_01E7A800;
extern CGtBuddiesPS2DirtySock D_01E3D390;

extern "C" void FEVerticalMove__18CB3HUDSoundManagerFv(void *, int);  // CB3HUDSoundManager::FEVerticalMove(), passed 1 more argument(s) [G]
extern "C" int func_00319360(unsigned short *);
extern "C" void func_00366980(UnkStruct_003665B0 *, int);
extern "C" int func_00319330(unsigned short *);


// [G] inlined helper (name unknown): re-places the highlight panel on the selected row, then the move sound
static inline void func_003665B0_inl(UnkStruct_003665B0 * self)
{
    if (self->field_E7C != 0) {
        CGtV2d pos;
        pos = self->field_E6C->GetRowPos(self->field_E78 + 1);
        pos.SetX(7.0f);
        CGtV2d size;
        size = self->field_E6C->GetRowSize(self->field_E78 + 1);
        size.SetX(krB3BuddyTableSize.field_0 - 4.0f);
        ((CB3Panel2dObject *)self->field_E7C)->Prepare(pos, CGtV2d(0.0f, 0.0f), size, 32, 0.0f);
    }
    FEVerticalMove__18CB3HUDSoundManagerFv(&D_01E7A800, 1);
}

// 0x003665B0
extern "C" int func_003665B0(UnkStruct_003665B0 * self)
{
    if (self->field_E84 == 0) {
        return 0;
    }
    if (self->field_E7C != 0) {
        int t0 = self->field_E78;
        if (D_004F50C0.GetMenuUp(0) != 0) {
            if (func_00319360(&self->field_E78) != 0) {
                func_003665B0_inl(self);
            } else if (self->field_E80 > 0) {
                self->field_E80--;
                func_00366980(self, 1);
                func_003665B0_inl(self);
                return 1;
            }
        } else if (D_004F50C0.GetMenuDown(0) != 0) {
            if (func_00319330(&self->field_E78) != 0) {
                func_003665B0_inl(self);
            } else if (self->field_E78 < D_01E3D390.GetNumBuddies() - self->field_E80 - 1) {
                self->field_E80++;
                func_00366980(self, 1);
                func_003665B0_inl(self);
                return 1;
            }
        }
        if (t0 != self->field_E78) {
            func_00366980(self, 0);
            return 1;
        }
    }
    return 0;
}
