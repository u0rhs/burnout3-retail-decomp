// Hand-written; the lifter refused it (a83: pause-page state switch (jtbl); case 5 explicit break, no default; func_00342090(self,p) takes p).

// func_00341D30 -- pause-page Update-style state dispatcher (DNAT row is low similarity, hint only: CB3PausePage::Release()).
enum EB3MenuFlowFSMEvents {};
enum EB3ScoreFinishState {};
struct UnkStruct_P { unsigned char pad_0[0x10]; };
struct UnkStruct_I { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01E898E8 {
    virtual void vfunc_8();
    virtual void vfunc_C();
    unsigned char pad_4[0xC];
};
struct UnkStruct_00341D30_e0 { unsigned char pad_0[0x12C]; };
class CB3InputManager {
public:
    UnkStruct_00341D30_e0 field_0[1];
};
struct UnkStruct_00341D30 {
    unsigned char pad_0[0x40];
    int field_40;
    unsigned char pad_44[0x1C];
    unsigned char field_60;
};
extern UnkStruct_I D_01E90424;
extern UnkStruct_I D_0051BA94;
extern UnkStruct_I D_0051B938;
extern signed char D_004F6061[];
extern CB3InputManager D_004F50C0;
extern UnkStruct_D_01E898E8 D_01E898E8;
extern UnkStruct_P D_01E90240;
extern UnkStruct_P D_01E7A800;
extern UnkStruct_P D_004EE040;
extern UnkStruct_P D_0064D3B0;
extern "C" void func_00342090(UnkStruct_00341D30 *, void *);
extern "C" int func_0032B2C0(void *, int, int);
extern "C" int func_00131CE0(void *);
extern "C" void FEBack__18CB3HUDSoundManagerFv(void *);
extern "C" void SetFinished__10CB3RaceCarF19EB3ScoreFinishState(void *, EB3ScoreFinishState);
extern "C" void StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(void *, EB3MenuFlowFSMEvents, int);
extern "C" void StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(void *, EB3MenuFlowFSMEvents, bool);

// 0x00341D30
extern "C" void func_00341D30(UnkStruct_00341D30 * self)
{
    if (D_01E90424.field_0 != 5) {
        return;
    }
    int a3;
    if (self->field_60 != 0) {
        a3 = 0;
    } else {
        a3 = D_0051BA94.field_0;
        if (a3 < 0) {
            StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(&D_01E90240, (EB3MenuFlowFSMEvents)6, 1);
            return;
        }
    }
    char *p = (char *)&D_004F50C0.field_0[D_004F6061[(signed char)a3]] + 0xD48;
    switch (self->field_40) {
    case 6:
        func_00342090(self, p);
        break;
    case 1:
        switch (func_0032B2C0(&D_01E898E8, a3, 1)) {
        case 4:
            StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)9, 0);
            break;
        case 5:
            self->field_40 = 6;
            ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
            FEBack__18CB3HUDSoundManagerFv(&D_01E7A800);
            break;
        }
        break;
    case 0:
        switch (func_0032B2C0(&D_01E898E8, a3, 1)) {
        case 4:
            StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)11, 0);
            break;
        case 5:
            self->field_40 = 6;
            ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
            FEBack__18CB3HUDSoundManagerFv(&D_01E7A800);
            break;
        }
        break;
    case 2:
    case 3:
        switch (func_0032B2C0(&D_01E898E8, a3, 1)) {
        case 4:
            if (func_00131CE0(&D_004EE040) != 0 && D_0051B938.field_0 > 0 && self->field_40 == 2) {
                StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)8, 0);
            } else {
                StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)7, 0);
            }
            break;
        case 5:
            self->field_40 = 6;
            ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
            FEBack__18CB3HUDSoundManagerFv(&D_01E7A800);
            break;
        }
        break;
    case 4:
        switch (func_0032B2C0(&D_01E898E8, a3, 1)) {
        case 4:
            SetFinished__10CB3RaceCarF19EB3ScoreFinishState(&D_0064D3B0, (EB3ScoreFinishState)1);
            StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)6, 1);
            break;
        case 5:
            self->field_40 = 6;
            ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
            FEBack__18CB3HUDSoundManagerFv(&D_01E7A800);
            break;
        }
        break;
    case 5:
        break;
    }
}
