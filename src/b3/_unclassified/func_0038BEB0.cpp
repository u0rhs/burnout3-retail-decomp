// Hand-written; the lifter refused it (a115: first try; RELOC only splat const D_0012AD28 (a107)).

#include "b3/classes/UnkStruct_D_0064D37C.h"
#include "b3/classes/UnkStruct_D_0064D384.h"

enum EB3ScoreFinishState {};

struct UnkStruct_0038BEB0_car {
    unsigned char pad_0[0x133C];
    int field_133C;
    unsigned char pad_1340[0x8C];
    int field_10C8_dummy;
};

struct UnkStruct_0038BEB0_car2 {
    unsigned char pad_0[0x10C8];
    int field_10C8;
    unsigned char pad_10CC[0x270];
    int field_133C;
    unsigned char pad_1340[0x5AA];
    unsigned char field_18EA;
    unsigned char pad_18EB[0x29];
    int field_1914;
    unsigned char pad_1918[0x80];
    unsigned char field_1998;
};

struct UnkStruct_0038BEB0_g {
    unsigned char pad_0[0x12AD28];
    UnkStruct_0038BEB0_car2 * field_12AD28[1];
};

struct UnkStruct_0038BEB0 {
    unsigned char pad_0[0x4];
};

extern UnkStruct_0038BEB0_g D_00522660;
extern UnkStruct_D_0064D37C D_0064D37C;
extern UnkStruct_D_0064D384 D_0064D384;
extern "C" void SetActive__10CB3RaceCarFb(void *, bool);
extern "C" void SetFinished__10CB3RaceCarF19EB3ScoreFinishState(void *, EB3ScoreFinishState);
extern "C" void func_00389EE0(void *);

// 0x0038BEB0
extern "C" void func_0038BEB0(UnkStruct_0038BEB0 * self)
{
    for (int i = 0; i < D_0064D37C.field_0; i++) {
        UnkStruct_0038BEB0_car2 * c = D_00522660.field_12AD28[i];
        if (c->field_10C8 == 2 && c->field_18EA == 0 && c->field_1998 != 0 && c->field_1914 == 1) {
            SetActive__10CB3RaceCarFb(c, false);
        }
    }
    if (D_0064D384.field_0 == 1) {
        for (int j = 0; j < D_0064D37C.field_0; j++) {
            if (D_00522660.field_12AD28[j]->field_133C == 2) {
                SetFinished__10CB3RaceCarF19EB3ScoreFinishState(D_00522660.field_12AD28[j], (EB3ScoreFinishState)5);
                break;
            }
        }
    }
    func_00389EE0(self);
}
