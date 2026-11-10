// Hand-written; the lifter refused it (exact; switch jump table retargeted at retail's (tools/jtbl_retarget.py)).

// func_00424C40 -- CB3MyBurnoutDevelopmentPage::Update()
// [L] DNAT: CB3MyBurnoutDevelopmentPage::Update() (research/proto/new_names.csv, medium)

enum EB3MenuFlowFSMEvents {};

class CB3ProfileManager {
public:
    void LockAll();
    void UnlockAll();
    unsigned char pad_0[0x10];
};

struct UnkStruct_00135AF0_e1 {
    unsigned char pad_0[0x12C];
};
struct UnkStruct_D_004F50C0 {
    UnkStruct_00135AF0_e1 field_0[1];
};
struct UnkStruct_D_004F6061 { signed char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_01E90424 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_P { unsigned char pad_0[0x10]; };

struct UnkInput {
    unsigned char pad_0[0x14];
    short field_14;
    unsigned char pad_16[0xA];
    short field_20;
    unsigned char pad_22[0xA];
    short field_2C;
    unsigned char pad_2E[0xA];
    short field_38;
    unsigned char pad_3A[0xA];
    short field_44;
    unsigned char pad_46[0x16];
    short field_5C;
};

struct UnkRec {
    unsigned char pad_0[0x40];
    unsigned int field_40;
    unsigned int field_44;
};
struct UnkStruct_D_0051BF9C { UnkRec * field_0; unsigned char pad_4[0xC]; };

class CB3MyBurnoutDevelopmentPage {
public:
    unsigned char pad_0[0x4];
    int field_4;
    int field_8;
    int field_C;
    unsigned char pad_10[0x4];
    unsigned short field_14;
};

struct UnkStruct_D_004E2A20 { unsigned int field_0; };
struct UnkStruct_D_004E2EDC { unsigned char field_0; };

extern UnkStruct_D_004F50C0 D_004F50C0;
extern UnkStruct_D_004F6061 D_004F6061;
extern UnkStruct_D_01E90424 D_01E90424;
extern UnkStruct_D_0051BF9C D_0051BF9C;
extern CB3ProfileManager D_0051BB00;
extern UnkStruct_P D_01E90240;
extern UnkStruct_D_004E2A20 D_004E2A20;
extern UnkStruct_D_004E2EDC D_004E2EDC;

extern "C" int func_00319360(void *);
extern "C" int func_00319330(void *);
extern "C" void func_00424A60(void *);
extern "C" void func_004248A0(void *, int);
extern "C" void StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(void *, EB3MenuFlowFSMEvents, int);
extern "C" void StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(void *, EB3MenuFlowFSMEvents, bool);

static inline int pabsw(int x)
{
    int r;
    asm("pabsw %0,%1" : "=r"(r) : "r"(x));
    return r;
}
static inline unsigned int pextlw0(unsigned int x)
{
    unsigned int r;
    asm("pextlw %0,$0,%1" : "=r"(r) : "r"(x));
    return r;
}

// 0x00424C40
#define STEP(FIELD, DIR) \
    { \
        int step = (DIR); \
        unsigned int pw = 10; \
        unsigned int val = R->FIELD; \
        while (pw != (unsigned int)-1 && *(const unsigned int *)&R->FIELD >= pw) { \
            step *= 10; \
            pw *= 10; \
        } \
        step = (val + pextlw0(pabsw(step)) < val) ? step / 10 : step; \
        R->FIELD = R->FIELD + step; \
    }

extern "C" void func_00424C40(CB3MyBurnoutDevelopmentPage * self)
{
    if (D_01E90424.field_0 != 5) {
        return;
    }
    UnkInput * p = (UnkInput *)((char *)&D_004F50C0.field_0[D_004F6061.field_0] + 0xD48);
    if (p->field_44 != 0) {
        self->field_4 = self->field_14;
        switch (self->field_4) {
        case 0:
            D_0051BB00.UnlockAll();
            StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)2, 0);
            break;
        case 1:
            D_0051BB00.LockAll();
            StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)2, 0);
            break;
        case 2:
            D_004E2EDC.field_0 = 1;
            StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)2, 0);
            break;
        case 3:
            D_004E2EDC.field_0 = 1;
            StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)2, 0);
            break;
        case 6:
            func_004248A0(self, self->field_8);
            func_00424A60(self);
            break;
        case 7:
            {
                unsigned char * e = (unsigned char *)(self->field_C + (int)D_0051BF9C.field_0);
                unsigned char v = !e[0x433];
                e[0x433] = v;
                func_00424A60(self);
            }
            break;
        case 4:
        case 5:
            break;
        }
    } else {
        if (p->field_5C != 0) {
            StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(&D_01E90240, (EB3MenuFlowFSMEvents)3, 0);
            return;
        }
        if ((p->field_2C != 0 && func_00319360(&self->field_14) != 0) || (p->field_38 != 0 && func_00319330(&self->field_14) != 0)) {
            return;
        }
        if (p->field_14 == 0 && p->field_20 == 0) {
            return;
        }
        UnkRec * R = D_0051BF9C.field_0;
        switch (self->field_14) {
        case 4:
            if (p->field_14 != 0 && R->field_40 != 0) {
                STEP(field_40, -1)
            } else if (p->field_20 != 0 && R->field_40 != (unsigned int)-1) {
                STEP(field_40, 1)
            }
            func_00424A60(self);
            break;
        case 5:
            if (p->field_14 != 0 && R->field_44 != 0) {
                STEP(field_44, -1)
            } else if (p->field_20 != 0 && R->field_44 != (unsigned int)-1) {
                STEP(field_44, 1)
            }
            func_00424A60(self);
            break;
        case 6:
            if (p->field_14 != 0 && self->field_8 > 0) {
                self->field_8--;
            } else if (p->field_20 != 0 && self->field_8 < 0x13) {
                self->field_8++;
            }
            func_00424A60(self);
            break;
        case 7:
            if (p->field_14 != 0 && self->field_C > 0) {
                self->field_C--;
            } else if (p->field_20 != 0 && self->field_C < 0x13) {
                self->field_C++;
            }
            func_00424A60(self);
            break;
        case 8:
            if (p->field_14 != 0 && D_004E2A20.field_0 != 0) {
                D_004E2A20.field_0--;
            } else if (p->field_20 != 0 && D_004E2A20.field_0 < 0x3E8) {
                D_004E2A20.field_0++;
            }
            func_00424A60(self);
            break;
        }
        return;
    }
}
