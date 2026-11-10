// Hand-written; the lifter refused it (a153: CB3MyBurnoutProfileLoadPage::Update [L]; 13-entry jtbl; cases in block-address order, default first in the inner state switch).

enum EB3MenuFlowFSMEvents {};
struct UnkStruct_D_01E8F360 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01E90240 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01ECD520 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01E7A800 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01E90424 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_0051A998 { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_003ED460 { unsigned char pad_0[0x4]; int field_4; };
extern UnkStruct_D_01E8F360 D_01E8F360;
extern UnkStruct_D_01E90240 D_01E90240;
extern UnkStruct_D_01ECD520 D_01ECD520;
extern UnkStruct_D_01E7A800 D_01E7A800;
extern UnkStruct_D_01E90424 D_01E90424;
extern UnkStruct_D_0051A998 D_0051A998;
extern "C" int func_00449150(void *, int, int);
extern "C" void func_00421000(void *, int);
extern "C" void func_003ECCD0(void *, int);
extern "C" void FESelect__18CB3HUDSoundManagerFv(void *);
extern "C" void StartLoadProfileFlow__24CB3MemCardControllerBaseFv(void *);
extern "C" void StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(void *, EB3MenuFlowFSMEvents, bool);
extern "C" void StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(void *, EB3MenuFlowFSMEvents, int);

// 0x003ED460
extern "C" void func_003ED460(UnkStruct_003ED460 * self)
{
    if (D_01E90424.field_0 != 5) return;
    int v = func_00449150(&D_01E8F360, 0, 1);
    switch (v) {
    case 12:
        switch (self->field_4) {
        default:
            return;
        case 0:
        case 2:
        case 8:
            StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(&D_01E90240, (EB3MenuFlowFSMEvents)3, 0);
            break;
        case 4:
            StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(&D_01E90240, (EB3MenuFlowFSMEvents)3, 0);
            break;
        }
        break;
    case 9:
        switch (self->field_4) {
        case 4:
            func_00421000(&D_01ECD520, 0);
            func_003ECCD0(self, 4);
            self->field_4 = 6;
            FESelect__18CB3HUDSoundManagerFv(&D_01E7A800);
            break;
        }
        break;
    case 10:
        switch (self->field_4) {
        case 4:
            func_00421000(&D_01ECD520, 1);
            func_003ECCD0(self, 4);
            self->field_4 = 6;
            FESelect__18CB3HUDSoundManagerFv(&D_01E7A800);
            break;
        }
        break;
    case 11:
        switch (self->field_4) {
        case 4:
            func_00421000(&D_01ECD520, 2);
            func_003ECCD0(self, 4);
            self->field_4 = 6;
            FESelect__18CB3HUDSoundManagerFv(&D_01E7A800);
            break;
        }
        break;
    case 0:
        switch (self->field_4) {
        case 0:
            self->field_4 = 1;
            func_003ECCD0(self, 1);
            StartLoadProfileFlow__24CB3MemCardControllerBaseFv(&D_01ECD520);
            FESelect__18CB3HUDSoundManagerFv(&D_01E7A800);
            break;
        }
        break;
    case 1:
        switch (self->field_4) {
        case 0:
            StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)3, 0);
            break;
        }
        break;
    case 2:
        switch (self->field_4) {
        case 2:
            StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)3, 0);
            break;
        case 6:
            if (D_0051A998.field_0 != 0) {
                StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)4, 0);
            } else {
                StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)3, 0);
            }
            break;
        case 8:
            StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)3, 0);
            break;
        case 9:
            break;
        }
        break;
    case 3:
        switch (self->field_4) {
        case 8:
            self->field_4 = 1;
            func_003ECCD0(self, 1);
            StartLoadProfileFlow__24CB3MemCardControllerBaseFv(&D_01ECD520);
            FESelect__18CB3HUDSoundManagerFv(&D_01E7A800);
            break;
        }
        break;
    case 4:
        switch (self->field_4) {
        case 9:
            self->field_4 = 1;
            func_003ECCD0(self, 1);
            StartLoadProfileFlow__24CB3MemCardControllerBaseFv(&D_01ECD520);
            break;
        }
        break;
    }
}
