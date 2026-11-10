// Hand-written; the lifter refused it (a88: GenerateRandomJunction sibling).

// Hand-written; lifter refused (a88: GenerateRandomJunction).
#include "b3/_unclassified/GtRandom.h"

class CB3HardCodedCrashStageList {
public:
    static unsigned long GetCrashStageGtID(int);
};
struct UnkStruct_D_0051BF9C { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_00518680 { CGtRandom r; unsigned char pad[0x100]; };
struct UnkStruct_J { unsigned char pad_0[0x4]; };
extern UnkStruct_D_0051BF9C D_0051BF9C;
extern UnkStruct_D_00518680 D_00518680;
extern "C" int func_0013AD70(void *, int, int);

// 0x00433250
extern "C" unsigned long func_00433250(UnkStruct_J * self)
{
    unsigned long id;
    int i = 0;
    int count = 0;
    int p = D_0051BF9C.field_0;
    do {
        if (func_0013AD70((void *)(p), i, 0) == 0) count++;
        i++;
    } while (i < 100);
    if (count > 0) {
        count = D_00518680.r.Random() % count;
        int k = 0;
        i = 0;
        for (; i < 100; i++) {
            id = CB3HardCodedCrashStageList::GetCrashStageGtID(i);
            if (func_0013AD70((void *)(p), i, 0) == 0) {
                if (count == k) break;
                k++;
            }
        }
    } else {
        id = 0;
    }
    return id;
}
