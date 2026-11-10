// Hand-written; the lifter refused it (a135: if(c44==0){goto chk1/chk2 out-of-line shared st block}else{...}; main flow goto fin; StartLeadOutFore takes bool).

#include "b3/classes/UnkStruct_D_004F50C0.h"
#include "b3/classes/UnkStruct_D_004F6061.h"
enum EB3MenuFlowFSMEvents {};
struct UnkStruct_P16 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01E90424 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_Ctl {
    unsigned char pad_0[0x2C];
    short field_2C;
    unsigned char pad_2E[0xA];
    short field_38;
    unsigned char pad_3A[0xA];
    short field_44;
    unsigned char pad_46[0x16];
    short field_5C;
};
struct UnkStruct_0043F850 {
    int field_0;
    int field_4;
    int field_8;
    unsigned short field_C;
    unsigned char pad_E[0x56];
    int field_64;
    int field_68;
    int field_6C;
};
extern UnkStruct_D_01E90424 D_01E90424;
extern UnkStruct_D_004F6061 D_004F6061;
extern UnkStruct_D_004F50C0 D_004F50C0;
extern UnkStruct_P16 D_01E90240;
extern "C" void StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(void *, EB3MenuFlowFSMEvents, int);
extern "C" void StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(void *, EB3MenuFlowFSMEvents, bool);
extern "C" int func_00319360(void *);
extern "C" int func_00319330(void *);
extern "C" void func_0043F680(UnkStruct_0043F850 *);

// 0x0043F850
extern "C" void func_0043F850(UnkStruct_0043F850 * self)
{
    int v;
    if (D_01E90424.field_0 != 5) return;
    UnkStruct_Ctl *c = (UnkStruct_Ctl *)((char *)&D_004F50C0.field_0[D_004F6061.field_0] + 0xD48);
    if (c->field_44 == 0) {
        if (c->field_2C != 0) goto chk1;
back1:
        if (c->field_38 != 0) goto chk2;
back2:
        if (c->field_5C == 0) return;
        switch (self->field_64) {
        case 0:
            StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(&D_01E90240, (EB3MenuFlowFSMEvents)3, 0);
            break;
        case 1:
            switch (self->field_6C) {
            case 0: self->field_68 = 0; break;
            case 1: self->field_68 = 1; break;
            case 2: self->field_68 = 2; break;
            }
            self->field_64 = 0;
            func_0043F680(self);
            break;
        }
    } else {
        self->field_68 = self->field_C;
        switch (self->field_64) {
        case 0:
            switch (self->field_68) {
            case 0: self->field_4 = 0; break;
            case 1: self->field_4 = 1; break;
            case 2: self->field_4 = 2; break;
            }
            self->field_6C = self->field_4;
            self->field_64 = 1;
            self->field_68 = 0;
            func_0043F680(self);
            break;
        case 1:
            switch (self->field_68) {
            case 0: self->field_8 = 0; break;
            case 1: self->field_8 = 1; break;
            case 2: self->field_8 = 2; break;
            }
            StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)0, 0);
            break;
        }
    }
    goto fin;
chk1:
    if (func_00319360((char *)self + 0xC) == 0) goto back1;
    v = self->field_C;
st:
    self->field_68 = v;
    goto fin;
chk2:
    if (func_00319330((char *)self + 0xC) == 0) goto back2;
    v = self->field_C;
    goto st;
fin:
    return;
}
