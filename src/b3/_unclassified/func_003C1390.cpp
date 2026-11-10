// func_003C1390 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (Rewritten on siblings func_003C1090/0D90: switch on field_24, static inline all-players-done loop, inline table-refresh block, 0x200000 test as an inline returning a bool local (r = false; if (...) r = true)).

// lifter variant 0
// func_003C1390 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

enum EB3MenuFlowFSMEvents {};

class CB3TableComponent;
struct UnkStruct_003C1390;
struct UnkStruct_003C1390_10;
struct UnkStruct_003C1390_12;
struct UnkStruct_003C1390_13;
struct UnkStruct_003C1390_5;
struct UnkStruct_003C1390_9;
struct UnkStruct_003C1390_a1;
struct UnkStruct_D_004F509C;
struct UnkStruct_D_0051BA88;
struct UnkStruct_D_01E32AE0;
struct UnkStruct_D_01E32B08;
struct UnkStruct_D_01E65499;
struct UnkStruct_D_01E89800;
struct UnkStruct_D_01E8980A;
struct UnkStruct_D_01E898E8;
struct UnkStruct_D_01E90240;
struct UnkStruct_D_01EA5630;
struct UnkStruct_D_01EA6B40;

class CB3TableComponent {
public:
    void RecalculateSize();

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E65499 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003C1390_a1 {
    unsigned char pad_0[0x44];
    short field_44;
    unsigned char pad_46[0x16];
    short field_5C;
};

struct UnkStruct_D_004F509C {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0051BA88 {
    UnkStruct_003C1390_5 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003C1390_5 {
    unsigned char pad_0[0x1B4];
    int field_1B4;
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

struct UnkStruct_003C1390_9 {
    unsigned char pad_0[0xC];
    int field_C;
};

struct UnkStruct_003C1390_10 {
    unsigned char pad_0[0xC];
    int field_C;
};

struct UnkStruct_D_01E32B08 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003C1390_12 {
    unsigned char pad_0[0x6DC];
    UnkStruct_003C1390_13 * field_6DC;
    unsigned char pad_6E0[0x481C];
    unsigned char field_4EFC;
};

struct UnkStruct_003C1390_13 {
    unsigned char pad_0[0x133C];
    int field_133C;
};

struct UnkStruct_D_01E90240 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E32AE0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EA5630 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EA6B40 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003C1390 {
    unsigned char pad_0[0x20];
    unsigned char field_20;
    unsigned char field_21;
    unsigned char pad_22[0x2];
    int field_24;
    float field_28;
    unsigned char pad_2C[0xC];
    int field_38;
};

extern UnkStruct_D_01E65499 D_01E65499;
extern UnkStruct_D_004F509C D_004F509C;
extern UnkStruct_D_0051BA88 D_0051BA88;
extern UnkStruct_D_01E898E8 D_01E898E8;
extern UnkStruct_D_01E8980A D_01E8980A;
extern UnkStruct_D_01E89800 D_01E89800;
extern UnkStruct_D_01E32B08 D_01E32B08;
extern UnkStruct_D_01E90240 D_01E90240;
extern UnkStruct_D_01E32AE0 D_01E32AE0;
extern CB3TableComponent D_01E8D450;
extern UnkStruct_D_01EA5630 D_01EA5630;
extern UnkStruct_D_01EA6B40 D_01EA6B40;

extern "C" void StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(void *, EB3MenuFlowFSMEvents, bool);  // CB3MenuPageManager::StartLeadOutFore(EB3MenuFlowFSMEvents,bool)
extern "C" void StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(void *, EB3MenuFlowFSMEvents, int);  // CB3MenuPageManager::StartLeadOut(EB3MenuFlowFSMEvents), passed 1 more argument(s) [G]
extern "C" int AmIHost__17CB3NetworkManagerFv(void *);  // CB3NetworkManager::AmIHost()
extern "C" void func_003C0950(UnkStruct_003C1390 *, UnkStruct_003C1390_a1 *);
extern "C" int func_003904E0(void *);
extern "C" void func_00390550(int);
extern "C" int func_0032B2C0(void *, int, int);
extern "C" int func_0033FF10(void *, void *, void *, void *, int, void *, void *, int);
extern "C" bool func_0031ECD0(void *, unsigned long, int);
extern "C" void func_003C1090(UnkStruct_003C1390 *);
extern "C" void func_003C0D90(UnkStruct_003C1390 *);
extern "C" UnkStruct_003C1390_12 * func_002366D0(void *, int);

static inline bool func_003C1390_inl1()
{
    for (int i = 0; i < D_01E32B08.field_0; i++) {
        UnkStruct_003C1390_12 * p = func_002366D0(&D_01E32AE0, i);
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

static inline bool func_003C1390_inl2(UnkStruct_003C1390 * self)
{
    bool r = false;
    if ((*(unsigned long *)&self->field_38 & 0x200000) == 0x200000) {
        r = true;
    }
    return r;
}

static inline void func_003C1390_inl3(UnkStruct_003C1390 * self)
{
    unsigned int t1 = self->field_38;
    *(unsigned long *)&self->field_38 = 0;
    ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
    func_0033FF10(&D_01E8D450, ((char *)self + 0x8), ((char *)self + 0x10), ((char *)self + 0x18), 0, &D_01EA5630, &D_01EA6B40, 0);
    D_01E8D450.RecalculateSize();
    unsigned long t0 = t1;
    if (t0 != *(unsigned long *)&self->field_38) {
        *(unsigned long *)&self->field_38 = t0;
        if (D_01E8980A.field_0 != 0) {
            ((UnkStruct_D_01E89800 *)&D_01E89800)->vfunc_C();
        }
        self->field_20 = ((t0 & 0x419E9003) != 0);
        self->field_21 = ((t0 & 0x1C00020681C) != 0);
        func_0031ECD0(&D_01E89800, t0, 3);
    }
}

// 0x003C1390
extern "C" void func_003C1390(UnkStruct_003C1390 * self, UnkStruct_003C1390_a1 * p0)
{
    if (D_01E65499.field_0 != 0) {
        switch (self->field_24) {
        case 0:
            func_003C0950(self, p0);
            break;
        case 1:
            if (func_003904E0((void *)(D_0051BA88.field_0->field_1B4)) != 0) {
                if (AmIHost__17CB3NetworkManagerFv(&D_01E32AE0) != 0) {
                    func_00390550(D_0051BA88.field_0->field_1B4);
                }
                StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)65, 0);
            }
            if (func_0032B2C0(&D_01E898E8, 0, 1) == 5) {
                func_003C1390_inl3(self);
                self->field_24 = 0;
            } else if (func_0032B2C0(&D_01E898E8, 0, 1) == 4) {
                StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)66, 0);
            }
            break;
        case 2:
            func_003C1090(self);
            break;
        case 3:
            func_003C0D90(self);
            break;
        case 4:
            if (func_003904E0((void *)(D_0051BA88.field_0->field_1B4)) != 0) {
                if (AmIHost__17CB3NetworkManagerFv(&D_01E32AE0) != 0) {
                    func_00390550(D_0051BA88.field_0->field_1B4);
                }
                StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)65, 0);
            }
            if (p0->field_44 != 0) {
                func_003C1390_inl3(self);
                self->field_24 = 0;
            }
            break;
        }
        if (func_003C1390_inl1()) {
            self->field_28 += D_004F509C.field_0;
            if (self->field_28 > 115.0f) {
                if (func_003C1390_inl2(self)) {
                    if (AmIHost__17CB3NetworkManagerFv(&D_01E32AE0) != 0) {
                        func_00390550(D_0051BA88.field_0->field_1B4);
                    }
                    StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)65, 0);
                } else {
                    StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)1, 0);
                }
            }
        }
    } else {
        if (self->field_20 != 0 && p0->field_5C != 0) {
            StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(&D_01E90240, (EB3MenuFlowFSMEvents)3, 0);
        }
        if (self->field_21 != 0 && p0->field_44 != 0) {
            StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)1, 0);
        }
        self->field_28 += D_004F509C.field_0;
        if (self->field_28 > 115.0f) {
            StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)1, 0);
        }
    }
}
