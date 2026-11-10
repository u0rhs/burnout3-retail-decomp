// Hand-written; the lifter refused it (near8: D_004E2918 read into a local through a const pun before the F0 reload).

// func_0039FA70 -- hand-written from retail (lifter refused); input handler of the options page (confirm/back/up/down/left/right)
enum EB3MenuFlowFSMEvents {};
class CB3InputManager {
public:
    int GetMenuConfirm(signed char);
    int GetMenuBack(signed char);
    int GetMenuUp(signed char);
    int GetMenuDown(signed char);
    int GetMenuLeft(signed char);
    int GetMenuRight(signed char);
    unsigned char pad_0[0x10];
};
struct UnkStruct_P { unsigned char pad_0[0x10]; };
struct UnkStruct_G { unsigned char field_0; unsigned char pad_1[0xF]; };
union UnkPairU { unsigned long l; struct { int a; int b; } s; };
struct UnkStruct_0039FA70_f0 {
    unsigned char pad_0[0xC];
    int field_C;
    unsigned char pad_10[0x4];
    int field_14;
    unsigned int field_18;
    unsigned int field_1C;
    int field_20;
};
struct UnkStruct_0039FA70_row {
    unsigned char pad_0[0x16];
    unsigned char field_16;
};
struct UnkStruct_0039FA70 {
    unsigned char pad_0[0x4];
    unsigned short field_4;
    unsigned char pad_6[0xE];
    unsigned char field_14;
    unsigned char pad_15[3];
    unsigned char * field_18;
    unsigned char pad_1C[0xA8];
    unsigned int field_C4[9];
    unsigned char pad_E8[0x8];
    UnkStruct_0039FA70_f0 * field_F0;
    unsigned char pad_F4[0x2C];
    unsigned long field_120[20];
    unsigned char pad_1C0[0x520];
    int field_6E0;
    int field_6E4;
    int field_6E8;
    int field_6EC;
    int field_6F0;
    int field_6F4;
    int field_6F8;
    int field_6FC;
    signed char field_700;
    unsigned char field_701;
    unsigned char field_702;
};
extern CB3InputManager D_004F50C0;
extern UnkStruct_P D_01E90240;
extern unsigned char D_004E2918;
extern "C" void StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(void *, EB3MenuFlowFSMEvents, int);
extern "C" void StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(void *, EB3MenuFlowFSMEvents, bool);
extern "C" int func_00319360(void *);
extern "C" int func_00319330(void *);
extern "C" void func_0039F490(void *);

static inline int func_0039FA70_inl1(UnkStruct_0039FA70 * self, int i)
{
    unsigned char *p = self->field_18;
    if (p == 0 || i < 0 || i > self->field_14) return 0;
    return *(unsigned char *)((char *)p + i);
}

// 0x0039FA70
extern "C" void func_0039FA70(UnkStruct_0039FA70 * self)
{
    if (D_004F50C0.GetMenuConfirm(0) != 0) {
        if (func_0039FA70_inl1(self, self->field_6E4) == 0) {
            self->field_701 = self->field_6E8 == 0;
            self->field_702 = self->field_6EC == 0;
            self->field_F0->field_14 = self->field_6E4;
            UnkPairU q;
            q.l = self->field_120[self->field_6EC];
            {
                UnkStruct_0039FA70_f0 *f = self->field_F0;
                f->field_C = q.s.a;
                f->field_20 = q.s.b;
            }
            {
                unsigned int t = self->field_6F0;
                UnkStruct_0039FA70_f0 *f = self->field_F0;
                f->field_1C &= 0xFFFFFF;
                f->field_1C |= t << 24;
            }
            {
                unsigned int t = self->field_C4[self->field_6F4];
                UnkStruct_0039FA70_f0 *f = self->field_F0;
                f->field_1C &= 0xFFFF00FF;
                f->field_1C |= t << 8;
            }
            {
                unsigned int t = self->field_C4[self->field_6F8];
                UnkStruct_0039FA70_f0 *f = self->field_F0;
                f->field_18 &= 0xFFFF00FF;
                f->field_18 |= t << 8;
            }
            {
                unsigned int t = *(const unsigned char *)&D_004E2918;  // [G] const pun (near8): lets retail's lbu hoist above the F0 reload
                UnkStruct_0039FA70_f0 *f = self->field_F0;
                f->field_18 &= 0xFFFFFF;
                f->field_18 |= t << 24;
            }
            if (self->field_6FC == 1) {
                UnkStruct_0039FA70_f0 *f = self->field_F0;
                f->field_18 &= 0xFF00FFFF;
                f->field_18 |= 0x10000;
            } else {
                UnkStruct_0039FA70_f0 *f = self->field_F0;
                f->field_18 &= 0xFF00FFFF;
            }
            StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)1, 0);
            return;
        }
    }
    if (D_004F50C0.GetMenuBack(0) != 0) {
        StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(&D_01E90240, (EB3MenuFlowFSMEvents)3, 0);
        return;
    }
    if (func_0039FA70_inl1(self, self->field_6E4) == 0) {
        if (D_004F50C0.GetMenuUp(0) != 0) {
            if (func_00319360((char *)self + 4) != 0) {
                return;
            }
        }
        if (D_004F50C0.GetMenuDown(0) != 0) {
            if (func_00319330((char *)self + 4) != 0) {
                return;
            }
        }
    }
    if (((UnkStruct_0039FA70_row *)((char *)self + self->field_4 * 20))->field_16 == 0) {
        if (D_004F50C0.GetMenuLeft(0) != 0 || D_004F50C0.GetMenuRight(0) != 0) {
            func_0039F490(self);
            return;
        }
    }
}
