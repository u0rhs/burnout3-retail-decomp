// Hand-written; the lifter refused it (a140: hand-written from scratch; bool first, 0<x slt, case order 4..0, case5 break + default return).

struct UnkStruct_0023B000_obj { virtual void vfunc_8(); virtual void vfunc_C();
    virtual void vfunc_10(); virtual void vfunc_14(); virtual void vfunc_18(); virtual void vfunc_1C(); virtual void vfunc_20(); virtual void vfunc_24();
    virtual void vfunc_28(int); };
struct UnkStruct_0023B000_car {
    virtual void vfunc_8(); virtual void vfunc_C();
    virtual void vfunc_10(int, int); virtual void vfunc_14(); virtual void vfunc_18(); virtual void vfunc_1C(); virtual void vfunc_20(); virtual void vfunc_24();
    virtual void vfunc_28(int);
    unsigned char pad_4[0x13F0];
    unsigned char * field_13F4;
    unsigned char pad_13F8[0x213C];
    float field_3534;
};
struct UnkStruct_0023B000_msg {
    unsigned char pad_0[0xC];
    unsigned char field_C;
    unsigned char pad_D[0xA];
    unsigned char field_17;
    unsigned char field_18;
    unsigned char field_19;
    unsigned char field_1A;
    unsigned char pad_1B[9];
    unsigned char field_24;
    unsigned char pad_25[3];
    int field_28;
    int field_2C;
};
struct UnkStruct_0023B000 {
    unsigned char pad_0[0x6DC];
    void * field_6DC;
    UnkStruct_0023B000_obj * field_6E0;
    unsigned char pad_6E4[0x4829];
    unsigned char field_4F0D;
    unsigned char pad_4F0E[6];
    int field_4F14;
};
struct UnkStruct_D_int { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_00522680 { float field_0; unsigned char pad_4[0xC]; };
class CB3RaceCarPhysics;
class CB3CollidingPair;
class CB3CrashStartInfo;
class CB3CrashActionDirector {
public:
    void StartRaceCarCrashing(CB3RaceCarPhysics*, int, CB3CollidingPair*, CB3CrashStartInfo*);
    unsigned char pad_0[0x10];
};
extern UnkStruct_D_int D_00645170;
extern UnkStruct_0023B000_car D_0057BAF0;
struct UnkStruct_D_0064ED5C { signed char field_0; unsigned char pad_1[0xF]; };
extern UnkStruct_D_0064ED5C D_0064ED5C;
extern CB3CrashActionDirector D_0055E948;
extern UnkStruct_D_00522680 D_00522680;
extern void * D_0064D388[];
extern unsigned char D_01E7A800[0x10];
extern "C" int OnEvent__13CB3ScoreBonusF16EScoreBonusEventiib(void *, int, int, int, bool);
extern "C" void func_00284C40(void *);
extern "C" void SetActive__10CB3RaceCarFb(void *, bool);
extern "C" void func_00157360(void *, void *);
extern "C" void func_00157380(void *, void *, float, int);
extern "C" void func_001573C0(void *, void *, float, bool);
extern "C" void func_00157400(void *, void *);

// 0x0023B000
extern "C" void func_0023B000(UnkStruct_0023B000 * self, UnkStruct_0023B000_msg * msg)
{
    bool first;
    if (self->field_4F14 > 0) {
        self->field_4F14 = self->field_4F14 - 1;
        first = false;
    } else {
        first = true;
    }
    if (first && msg->field_17 != 0) {
        self->field_6E0->vfunc_28(0);
        self->field_4F14 = 5;
    }
    if (first && msg->field_18 != 0) {
        UnkStruct_0023B000_car * c = 0 < D_00645170.field_0 ? &D_0057BAF0 : 0;
        int k = D_0064ED5C.field_0;
        D_0055E948.StartRaceCarCrashing((CB3RaceCarPhysics*)c, k, 0, 0);
        c->vfunc_10(k, 0);
        c->vfunc_28(1);
        c->field_3534 = D_00522680.field_0;
        self->field_4F14 = 5;
    }
    if (first && msg->field_19 != 0) {
        UnkStruct_0023B000_car * c = 0 < D_00645170.field_0 ? &D_0057BAF0 : 0;
        OnEvent__13CB3ScoreBonusF16EScoreBonusEventiib(c->field_13F4 + 0x11E4, 0xD0, 0, -1, true);
        func_00284C40(&D_01E7A800);
    }
    self->field_4F0D = msg->field_C;
    if (msg->field_1A != 0 && *((unsigned char *)self->field_6DC + 0x1998) != 0) {
        SetActive__10CB3RaceCarFb(self->field_6DC, false);
    }
    switch (msg->field_2C) {
    case 4: {
        void *t = D_0064D388[msg->field_28];
        if (msg->field_24 != 0) func_00157360((char *)self->field_6DC + 0x10C0, t);
        else func_00157360((char *)t + 0x10C0, self->field_6DC);
        } break;
    case 3: {
        void *t = D_0064D388[msg->field_28];
        if (msg->field_24 != 0) func_00157380((char *)self->field_6DC + 0x10C0, t, 0.0f, 1);
        else func_00157380((char *)t + 0x10C0, self->field_6DC, 0.0f, 1);
        } break;
    case 2: {
        void *t = D_0064D388[msg->field_28];
        if (msg->field_24 != 0) func_001573C0((char *)self->field_6DC + 0x10C0, t, 0.0f, true);
        else func_001573C0((char *)t + 0x10C0, self->field_6DC, 0.0f, true);
        } break;
    case 1: {
        void *t = D_0064D388[msg->field_28];
        if (msg->field_24 != 0) func_001573C0((char *)self->field_6DC + 0x10C0, t, 0.0f, false);
        else func_001573C0((char *)t + 0x10C0, self->field_6DC, 0.0f, false);
        } break;
    case 0: {
        void *t = D_0064D388[msg->field_28];
        if (msg->field_24 != 0) func_00157400((char *)self->field_6DC + 0x10C0, t);
        else func_00157400((char *)t + 0x10C0, self->field_6DC);
        } break;
    case 5: break;
    }
}
