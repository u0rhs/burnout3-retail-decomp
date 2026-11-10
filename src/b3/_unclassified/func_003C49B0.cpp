// Hand-written; the lifter refused it (a132: flag bools + inlined leadout helper x4; copied sibling func_003C4C70 decls).

enum EB3MenuFlowFSMEvents {};

struct UnkStruct_003C4C70;
struct UnkStruct_003C4C70_1;
struct UnkStruct_003C4C70_5;
struct UnkStruct_003C4C70_6;
struct UnkStruct_003C4C70_8;
struct UnkStruct_D_004F509C;
struct UnkStruct_D_0051BA44;
struct UnkStruct_D_0051BA88;
struct UnkStruct_D_01E32AE0;
struct UnkStruct_D_01E898E8;
struct UnkStruct_D_01E898F2;
struct UnkStruct_D_01E90240;

struct UnkStruct_D_0051BA88 {
    UnkStruct_003C4C70_1 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003C4C70_1 {
    unsigned char pad_0[0x1B4];
    UnkStruct_003C4C70_5 * field_1B4;
};

struct UnkStruct_D_01E898E8 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004F509C {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003C4C70_5 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18();
    virtual void vfunc_1C();
    virtual void vfunc_20();
    virtual void vfunc_24();
    virtual void vfunc_28();
    virtual void vfunc_2C();
    virtual void vfunc_30();
    virtual void vfunc_34();
    virtual void vfunc_38();
    virtual void vfunc_3C();
    virtual void vfunc_40();
    virtual void vfunc_44();
    virtual void vfunc_48();
    virtual void vfunc_4C();
    virtual void vfunc_50();
    virtual void vfunc_54();
    virtual void vfunc_58();
    virtual void vfunc_5C();
    virtual void vfunc_60();
    virtual void vfunc_64();
    virtual void vfunc_68();
    virtual void vfunc_6C();
    virtual void vfunc_70();
    virtual void vfunc_74();
    virtual void vfunc_78();
    virtual void vfunc_7C();
    virtual void vfunc_80();
    virtual void vfunc_84();
    virtual void vfunc_88();
    virtual void vfunc_8C();
    virtual void vfunc_90();
    virtual void vfunc_94();
    virtual void vfunc_98();
    virtual int vfunc_9C();
};

struct UnkStruct_003C4C70_6 {
    int field_0;
};

struct UnkStruct_D_01E898F2 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003C4C70_8 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18();
    virtual void vfunc_1C();
    virtual void vfunc_20();
    virtual void vfunc_24();
    virtual void vfunc_28();
    virtual void vfunc_2C();
    virtual void vfunc_30();
    virtual void vfunc_34();
    virtual void vfunc_38();
    virtual void vfunc_3C();
    virtual void vfunc_40();
    virtual void vfunc_44();
    virtual void vfunc_48();
    virtual void vfunc_4C();
    virtual void vfunc_50();
    virtual void vfunc_54();
    virtual void vfunc_58();
    virtual void vfunc_5C();
    virtual void vfunc_60();
    virtual void vfunc_64();
    virtual void vfunc_68();
    virtual void vfunc_6C();
    virtual void vfunc_70();
    virtual void vfunc_74();
    virtual void vfunc_78();
    virtual void vfunc_7C();
    virtual void vfunc_80();
    virtual void vfunc_84();
    virtual void vfunc_88();
    virtual void vfunc_8C();
    virtual void vfunc_90();
    virtual void vfunc_94();
    virtual void vfunc_98();
    virtual int vfunc_9C();
};

struct UnkStruct_D_01E90240 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E32AE0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0051BA44 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003C4C70 {
    unsigned char pad_0[0x40];
    float field_40;
    int field_44;
};

extern UnkStruct_D_0051BA88 D_0051BA88;
extern UnkStruct_D_01E898E8 D_01E898E8;
extern UnkStruct_D_004F509C D_004F509C;
extern UnkStruct_D_01E898F2 D_01E898F2;
extern UnkStruct_D_01E90240 D_01E90240;
extern UnkStruct_D_01E32AE0 D_01E32AE0;
extern UnkStruct_D_0051BA44 D_0051BA44;

extern "C" void StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(void *, EB3MenuFlowFSMEvents, int);  // CB3MenuPageManager::StartLeadOut(EB3MenuFlowFSMEvents), passed 1 more argument(s) [G]
extern "C" int AmIHost__17CB3NetworkManagerFv(void *);  // CB3NetworkManager::AmIHost()
extern "C" int func_0032B2C0(void *, int);
extern "C" void func_003904F0();
extern "C" void func_00390550(UnkStruct_003C4C70_5 *);
extern "C" int func_0026C8C0(void *);
extern "C" int func_00271A00(void *, int);
extern "C" void *func_001A3AA0(void *, void *, int *);
extern "C" void func_0032B3D0(void *, int);
extern "C" void func_0032CF60(void *, int, void *, int, int);


extern "C" void StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(void *, EB3MenuFlowFSMEvents, bool);
extern "C" int func_003904E0(UnkStruct_003C4C70_5 *);
struct UnkStruct_49B0_pad { unsigned char pad_0[0x5C]; short field_5C; };
struct UnkStruct_49B0_pb { unsigned char pad_0[0x44]; short field_44; };
struct UnkStruct_49B0_self { unsigned char pad_0[0x30]; unsigned long field_30; unsigned char pad_38[0x11]; unsigned char field_49; unsigned char field_4A; };

static inline void func_003C49B0_inl1()
{
    int r = D_0051BA88.field_0->field_1B4->vfunc_9C();
    if (r == 5 || AmIHost__17CB3NetworkManagerFv(&D_01E32AE0) != 0) {
        func_00390550(D_0051BA88.field_0->field_1B4);
    }
}

// 0x003C49B0
extern "C" void func_003C49B0(UnkStruct_49B0_self *self, void *p1)
{
    unsigned long f = self->field_30;
    bool a = false, b = false, c = false;
    if ((f & 0x20000) == 0x20000) a = true;
    if ((f & 0x800000) == 0x800000) b = true;
    if ((f & 0x200000) == 0x200000) c = true;
    if (self->field_49 != 0 && ((UnkStruct_49B0_pad *)p1)->field_5C != 0) {
        if (a) {
            StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)0x46, 0);
        } else if (b) {
            if (func_0026C8C0(&D_01E32AE0) != 0) {
                func_003C49B0_inl1();
                StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)0x41, 0);
            } else {
                StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)0x43, 0);
            }
        } else {
            StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(&D_01E90240, (EB3MenuFlowFSMEvents)3, 0);
        }
    }
    if (func_003904E0(D_0051BA88.field_0->field_1B4) != 0) {
        func_003C49B0_inl1();
        StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)0x41, 0);
    }
    if (self->field_4A != 0 && ((UnkStruct_49B0_pb *)p1)->field_44 != 0) {
        if (c) {
            if (func_0026C8C0(&D_01E32AE0) != 0) {
                func_003C49B0_inl1();
                StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)0x41, 0);
            } else {
                StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)0x43, 0);
            }
        } else {
            StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)1, 0);
        }
    }
}
