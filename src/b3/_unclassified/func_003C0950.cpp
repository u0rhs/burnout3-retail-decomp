// Hand-written; the lifter refused it (a153: crash-standings Update-style; nested a1/s1 chains for out-of-line blocks, bool flags, shared AllReady inline).

enum EB3MenuFlowFSMEvents {};

class CB3TableComponent;
struct UnkStruct_003C0950;
struct UnkStruct_003C0950_10;
struct UnkStruct_003C0950_12;
struct UnkStruct_003C0950_14;
struct UnkStruct_003C0950_15;
struct UnkStruct_003C0950_16;
struct UnkStruct_003C0950_5;
struct UnkStruct_003C0950_8;
struct UnkStruct_003C0950_9;
struct UnkStruct_D_004F509C;
struct UnkStruct_D_0051BA44;
struct UnkStruct_D_0051BA88;
struct UnkStruct_D_01E32AE0;
struct UnkStruct_D_01E32B08;
struct UnkStruct_D_01E89800;
struct UnkStruct_D_01E8980A;
struct UnkStruct_D_01E898E8;
struct UnkStruct_D_01E898F2;
struct UnkStruct_D_01E90240;
struct UnkStruct_D_01EA5630;
struct UnkStruct_D_01EA6B40;

class CB3TableComponent {
public:
    void RecalculateSize();

    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E898E8 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E8980A {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E89800 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0051BA88 {
    UnkStruct_003C0950_5 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003C0950_5 {
    unsigned char pad_0[0x1B4];
    int field_1B4;
};

struct UnkStruct_D_004F509C {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E32B08 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003C0950_8 {
    unsigned char pad_0[0x6DC];
    UnkStruct_003C0950_9 * field_6DC;
    unsigned char pad_6E0[0x481C];
    unsigned char field_4EFC;
};

struct UnkStruct_003C0950_9 {
    unsigned char pad_0[0x133C];
    int field_133C;
};

struct UnkStruct_003C0950_10 {
    int field_0;
};

struct UnkStruct_D_01E898F2 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003C0950_12 {
    unsigned char pad_0[0xC];
    int field_C;
};

struct UnkStruct_003C0950_14 {
    unsigned char pad_0[0xC];
    int field_C;
};

struct UnkStruct_003C0950_15 {
    unsigned char pad_0[0xC];
    int field_C;
};

struct UnkStruct_D_01EA5630 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EA6B40 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E32AE0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0051BA44 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E90240 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003C0950_16 {
    unsigned char pad_0[0x44];
    short field_44;
    unsigned char pad_46[0x16];
    short field_5C;
};

struct UnkStruct_003C0950 {
    unsigned char pad_0[0x20];
    unsigned char field_20;
    unsigned char field_21;
    unsigned char pad_22[0x2];
    int field_24;
    unsigned char pad_28[0x10];
    unsigned long field_38;
};

extern UnkStruct_D_01E898E8 D_01E898E8;
extern UnkStruct_D_01E8980A D_01E8980A;
extern UnkStruct_D_01E89800 D_01E89800;
extern UnkStruct_D_0051BA88 D_0051BA88;
extern UnkStruct_D_004F509C D_004F509C;
extern UnkStruct_D_01E32B08 D_01E32B08;
extern UnkStruct_D_01E898F2 D_01E898F2;
extern CB3TableComponent D_01E8D450;
extern UnkStruct_D_01EA5630 D_01EA5630;
extern UnkStruct_D_01EA6B40 D_01EA6B40;
extern UnkStruct_D_01E32AE0 D_01E32AE0;
extern UnkStruct_D_0051BA44 D_0051BA44;
extern UnkStruct_D_01E90240 D_01E90240;

extern "C" int AmIHost__17CB3NetworkManagerFv(void *);  // CB3NetworkManager::AmIHost()
extern "C" void StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(void *, EB3MenuFlowFSMEvents, int);  // CB3MenuPageManager::StartLeadOut(EB3MenuFlowFSMEvents), passed 1 more argument(s) [G]
extern "C" int func_0032B2C0(void *, int);
extern "C" int func_0033FF10(void *, void *, void *, void *, int, void *, void *, int);
extern "C" bool func_0031ECD0(void *, unsigned long, int);
extern "C" void func_003904F0();
extern "C" UnkStruct_003C0950_8 * func_002366D0(void *, int);
extern "C" int func_00271A00(void *, int);
extern "C" void *func_001A3AA0(void *, void *, UnkStruct_003C0950_10 *);
extern "C" void func_0032CF60(void *, int, void *, int, int);
extern "C" void func_0032B3D0(void *, int);
extern "C" void func_00390550(int);


static inline bool func_003C0D90_inl1()
{
    for (int i = 0; i < D_01E32B08.field_0; i++) {
        UnkStruct_003C0950_8 * p = func_002366D0(&D_01E32AE0, i);
        if (p == 0) {
            continue;
        }
        if (((p->field_4EFC != 0) ^ 1) == 0) {
            continue;
        }
        if (p->field_6DC->field_133C == 3) {
            continue;
        }
        return false;
    }
    return true;
}

extern "C" int AmIHost__17CB3NetworkManagerFv(void *);
extern "C" void StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(void *, EB3MenuFlowFSMEvents, int);
extern "C" void StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(void *, EB3MenuFlowFSMEvents, bool);
extern "C" void func_0032D080(void *, int, int, int, int);
extern "C" int func_003904E0(void *);
extern "C" UnkStruct_003C0950_8 * func_002366D0(void *, int);
extern "C" void func_00390550(int);

static inline bool func_003C0950_inl1()
{
    for (int i = 0; i < D_01E32B08.field_0; i++) {
        UnkStruct_003C0950_8 * p = func_002366D0(&D_01E32AE0, i);
        if (p == 0) {
            continue;
        }
        if (((p->field_4EFC != 0) ^ 1) == 0) {
            continue;
        }
        if (p->field_6DC->field_133C == 3) {
            continue;
        }
        return false;
    }
    return true;
}

// 0x003C0950
extern "C" void func_003C0950(UnkStruct_003C0950 * self, UnkStruct_003C0950_16 * p1)
{
    bool a2 = false;
    bool a1 = false;
    bool s1 = false;
    unsigned long fl = self->field_38;
    if ((fl & 0x20000) == 0x20000) a2 = true;
    if ((fl & 0x800000) == 0x800000) a1 = true;
    if ((fl & 0x200000) == 0x200000) s1 = true;
    if (self->field_20 != 0 && p1->field_5C != 0) {
        if (a2) {
            self->field_24 = 1;
            ((CB3TableComponent *)&D_01E8D450)->vfunc_C();
            ((UnkStruct_D_01E89800 *)&D_01E89800)->vfunc_C();
            func_0032D080(&D_01E898E8, 7, 0x138, 5, 1);
        } else if (a1) {
          if (func_003C0950_inl1()) {
            if (AmIHost__17CB3NetworkManagerFv(&D_01E32AE0) != 0) {
                func_00390550(D_0051BA88.field_0->field_1B4);
            }
            StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)65, 0);
        } else {
            self->field_24 = 2;
            ((CB3TableComponent *)&D_01E8D450)->vfunc_C();
            ((UnkStruct_D_01E89800 *)&D_01E89800)->vfunc_C();
            func_0032D080(&D_01E898E8, 7, 0x139, 5, 1);
          }
        } else {
            StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(&D_01E90240, (EB3MenuFlowFSMEvents)3, 0);
        }
    }
    if (func_003904E0((void *)(D_0051BA88.field_0->field_1B4)) != 0) {
        if (AmIHost__17CB3NetworkManagerFv(&D_01E32AE0) != 0) {
            func_00390550(D_0051BA88.field_0->field_1B4);
        }
        StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)65, 0);
    }
    if (self->field_21 != 0 && p1->field_44 != 0) {
        if (s1) {
          if (AmIHost__17CB3NetworkManagerFv(&D_01E32AE0) != 0) {
            if (func_003C0950_inl1()) {
                if (AmIHost__17CB3NetworkManagerFv(&D_01E32AE0) != 0) {
                    func_00390550(D_0051BA88.field_0->field_1B4);
                }
                StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)65, 0);
            } else {
                self->field_24 = 2;
                ((CB3TableComponent *)&D_01E8D450)->vfunc_C();
                ((UnkStruct_D_01E89800 *)&D_01E89800)->vfunc_C();
                func_0032D080(&D_01E898E8, 7, 0x139, 5, 1);
            }
          } else {
            self->field_24 = 4;
            ((CB3TableComponent *)&D_01E8D450)->vfunc_C();
            ((UnkStruct_D_01E89800 *)&D_01E89800)->vfunc_C();
            func_0032D080(&D_01E898E8, 3, 0x55B, 1, 1);
          }
        } else {
            StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)1, 0);
        }
    }
}
