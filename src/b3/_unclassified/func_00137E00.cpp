// Hand-written; the lifter refused it (a90: hand-written; bool s0/s1 flags).

class CB3HardCodedCrashStageList {
public:
    static int FindCrashStage(unsigned long);
};
struct UnkStruct_00137E00 {
    unsigned char pad_0[0x386];
    signed char field_386[1];
    unsigned char pad_387[0x48];
    signed char field_3CF[1];
};
struct UnkStruct_D_0051C0FF { bool field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_0051C100 { bool field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_0051C101 { bool field_0; unsigned char pad_1[0xF]; };
extern UnkStruct_D_0051C0FF D_0051C0FF;
extern UnkStruct_D_0051C100 D_0051C100;
extern UnkStruct_D_0051C101 D_0051C101;
extern "C" int FindChallengeIndex__25CB3HardCodedRaceStageListFUl(unsigned long);

// 0x00137E00
extern "C" void func_00137E00(UnkStruct_00137E00 * self)
{
    bool s1 = true;
    bool s0 = s1;
    for (int i = 0; i < 0x49; i++) {
        if (self->field_386[i] != 3) {
            s1 = false;
            break;
        }
    }
    for (int i = 0; i < 0x64; i++) {
        if (self->field_3CF[i] != 3) {
            s0 = false;
            break;
        }
    }
    int a = FindChallengeIndex__25CB3HardCodedRaceStageListFUl(0x11E910E5664BF854UL);
    D_0051C0FF.field_0 = self->field_386[a] > 0;
    int b = CB3HardCodedCrashStageList::FindCrashStage(0x1A0F3A891F1A3A94UL);
    D_0051C100.field_0 = self->field_3CF[b] > 0;
    D_0051C101.field_0 = s0 && s1;
}
