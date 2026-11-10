#include "b3/gamesource/Menu/DebugMenu/Pages/B3LoadingScreenPage.h"
#include "b3/gamesource/Menu/DebugMenu/Components/B3BackgroundComponent.h"
#include "b3/gamesource/Menu/DebugMenu/Components/B3HeadingComponent.h"
#include "b3/_unclassified/GtRandom.h"

extern "C" int strncmp(const char *a, const char *b, unsigned int n);
extern "C" int atoi(const char *s);

extern CB3BackgroundComponent D_01E88A80;  // unnamed global: the background component (func_0031D920's callers)
extern CB3HeadingComponent D_01E89518;     // unnamed global: the heading component

// [L] the random generator instance (unnamed); padded for N51.
struct UnkStruct_D_00518680 {
    CGtRandom r;
    unsigned char pad[0x100];
};
extern UnkStruct_D_00518680 D_00518680;

// [L] the current event/track record; the block at +0x90 holds a 4-character tag + number at +0x18 ("GNRL", "CARS<n>",
// otherwise another tag + <n>) [C by the strncmp/atoi calls]. [G] the record's address is held as an integer: retail
// adds 0x90 and then 0x18 separately, which only integer arithmetic before the cast reproduces (a pointer member, a
// local pointer, accessors, or a base-class conversion are all folded into one +0xA8).
struct UnkStruct_D_01EA477C_Block {
    unsigned char pad0[0x18];
    char field_18[8];
};
struct UnkStruct_D_01EA477C {
    unsigned int value;
    unsigned char pad[0x100];
};
extern UnkStruct_D_01EA477C D_01EA477C;

// [L] string-id tables, indexed by the tag's number (this file's .rodata, still asm: their extent and E's single 56-byte
// kaLoadingString don't line up).
extern const int D_004C539C[];
extern const int D_004C53BC[];

struct UnkStruct_D_01E8D520;
extern UnkStruct_D_01E8D520 D_01E8D520;
extern "C" int func_00342F80(UnkStruct_D_01E8D520 *self, int type, int id);

// 0x00321500
void func_00321500(CB3LoadingScreenPage *self)
{
    // Through a pointer: retail dispatches Release() through the vtable (slot 1).
    CB3BackgroundComponent *bg = &D_01E88A80;
    bg->Release();
    D_01E88A80.Prepare((EB3BackgroundType)5);
    UnkStruct_D_01EA477C_Block *blk = (UnkStruct_D_01EA477C_Block *)(D_01EA477C.value + 0x90);
    const char *tag = blk->field_18;
    // Declared id, tip, type: retail's registers ($s0, $s2, $s1).
    int id;
    int tip;
    int type;
    if (strncmp(tag, "GNRL", 4) == 0) {
        if (D_00518680.r.Random() & 1) {
            id = 0x918;
            type = 1;
            tip = id;
        } else {
            id = 0x8EA;
            type = 0;
            tip = id;
        }
    } else if (strncmp(tag, "CARS", 4) == 0) {
        id = 0x8E1;
        tip = D_004C53BC[atoi(tag + 4)];
        type = 3;
    } else {
        id = 0x8E1;
        tip = D_004C539C[atoi(tag + 4)];
        type = 2;
    }
    D_01E89518.Prepare((EGlobalStrings)id, (CB3HeadingComponent::EHeadingType)5);
    func_00342F80(&D_01E8D520, type, tip);
}
