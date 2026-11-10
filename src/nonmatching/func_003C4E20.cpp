// NONMATCHING: func_003C4E20 -- retail 311 / ours 313 instructions, 13 in changed runs
// left (13 instrs): in case 2 our second test (func_0026C8C0 -> lead-out) is laid out of line behind a b, and retail's extra 'b epilogue' join block (L5208) after the v / field_4A tail is missing. Inline lead-out helper needs 'int r = vfunc_9C(); if (r == 5 || AmIHost())' (the plain || form puts AmIHost out of line); bool v from a daddiu flag
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// lifter variant 0
// func_003C4E20 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

enum EB3MenuFlowFSMEvents {};

class CB3InputManager;
struct UnkStruct_003C4E20;
struct UnkStruct_003C4E20_11;
struct UnkStruct_003C4E20_5;
struct UnkStruct_003C4E20_6;
struct UnkStruct_003C4E20_8;
struct UnkStruct_003C4E20_9;
struct UnkStruct_D_004F509C;
struct UnkStruct_D_0051BA88;
struct UnkStruct_D_01E32AE0;
struct UnkStruct_D_01E65499;
struct UnkStruct_D_01E8954E;
struct UnkStruct_D_01E898E8;
struct UnkStruct_D_01E90240;

class CB3InputManager {
public:
    int GetMenuBack(signed char);
    int GetMenuConfirm(signed char);
    int GetMenuUp(signed char);
    int GetMenuDown(signed char);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E65499 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E8954E {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0051BA88 {
    UnkStruct_003C4E20_5 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003C4E20_5 {
    unsigned char pad_0[0x1B4];
    UnkStruct_003C4E20_6 * field_1B4;
};

struct UnkStruct_003C4E20_6 {
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

struct UnkStruct_D_01E898E8 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003C4E20_8 {
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

struct UnkStruct_003C4E20_9 {
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

struct UnkStruct_D_004F509C {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003C4E20_11 {
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
    virtual int vfunc_9C(int);
};

struct UnkStruct_D_01E90240 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E32AE0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003C4E20 {
    unsigned char pad_0[0x4];
    unsigned short field_4;
    unsigned char pad_6[0x26];
    signed char field_2C[4];  // [G] element count unknown
    unsigned long field_30;
    int field_38;
    float field_3C;
    unsigned char pad_40[0x9];
    unsigned char field_49;
    unsigned char field_4A;
    unsigned char pad_4B[0x1];
    bool field_4C;
};

extern UnkStruct_D_01E65499 D_01E65499;
extern UnkStruct_D_01E8954E D_01E8954E;
extern UnkStruct_D_0051BA88 D_0051BA88;
extern UnkStruct_D_01E898E8 D_01E898E8;
extern UnkStruct_D_004F509C D_004F509C;
extern CB3InputManager D_004F50C0;
extern UnkStruct_D_01E90240 D_01E90240;
extern UnkStruct_D_01E32AE0 D_01E32AE0;

extern "C" void StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(void *, EB3MenuFlowFSMEvents, int);  // CB3MenuPageManager::StartLeadOut(EB3MenuFlowFSMEvents), passed 1 more argument(s) [G]
extern "C" void StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(void *, EB3MenuFlowFSMEvents, bool);  // CB3MenuPageManager::StartLeadOutFore(EB3MenuFlowFSMEvents,bool)
extern "C" int AmIHost__17CB3NetworkManagerFv(void *);  // CB3NetworkManager::AmIHost()
extern "C" int func_00319330(void *);
extern "C" int func_00319360(void *);
extern "C" void func_003C49B0(UnkStruct_003C4E20 *, void *);
extern "C" int func_003904E0(UnkStruct_003C4E20_6 *);
extern "C" void func_00390550(UnkStruct_003C4E20_6 *);
extern "C" int func_0032B2C0(void *, int, int);
extern "C" int func_0026C8C0(void *);
extern "C" void func_003C4C70(UnkStruct_003C4E20 *);

// [G] placeholder for an unnamed inline: the network lead-out (also in func_003C1090's shape)
static inline void func_003C4E20_inl1()
{
    int r = D_0051BA88.field_0->field_1B4->vfunc_9C();
    if (r == 5 || AmIHost__17CB3NetworkManagerFv(&D_01E32AE0) != 0) {
        func_00390550(D_0051BA88.field_0->field_1B4);
    }
    StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)65, 0);
}

extern "C" void func_003C4E20(UnkStruct_003C4E20 * self, void *p0_)
{
    int p0 = (int)p0_;
    if (D_01E65499.field_0 != 0) {
        switch (self->field_38) {
        case 0:
            func_003C49B0(self, (void *)(p0));
            break;
        case 1:
            if (func_003904E0(D_0051BA88.field_0->field_1B4) != 0) {
                func_003C4E20_inl1();
            }
            if (func_0032B2C0(&D_01E898E8, 0, 1) == 5) {
                self->field_38 = 0;
                ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
            }
            if (func_0032B2C0(&D_01E898E8, 0, 1) == 4) {
                StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)66, 0);
            }
            break;
        case 2:
            if (func_003904E0(D_0051BA88.field_0->field_1B4) != 0) {
                func_003C4E20_inl1();
            }
            if (func_0026C8C0(&D_01E32AE0) != 0) {
                func_003C4E20_inl1();
            }
            if (func_0032B2C0(&D_01E898E8, 0, 1) == 5) {
                StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(&D_01E90240, (EB3MenuFlowFSMEvents)69, 0);
            } else if (func_0032B2C0(&D_01E898E8, 0, 1) == 4) {
                StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)68, 0);
            }
            break;
        case 3:
            func_003C4C70(self);
            break;
        }
        if (func_0026C8C0(&D_01E32AE0) == 0) {
            return;
        }
        self->field_3C = self->field_3C + D_004F509C.field_0;
        if (self->field_3C <= 115.0f) {
            return;
        }
        bool v = false;
        if ((self->field_30 & 0x200000) == 0x200000) {
            v = true;
        }
        if (v) {
            func_003C4E20_inl1();
        } else if (self->field_4A != 0) {
            StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)1, 0);
        }
    } else {
        if (self->field_49 != 0 && D_004F50C0.GetMenuBack(0) != 0) {
            StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(&D_01E90240, (EB3MenuFlowFSMEvents)3, self->field_4C);
            return;
        }
        if (D_01E8954E.field_0 != 0) {
            if (D_004F50C0.GetMenuConfirm(0) != 0) {
                StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)self->field_2C[self->field_4], 0);
                return;
            }
            if (D_004F50C0.GetMenuUp(0) != 0 && func_00319360((char *)self + 0x4) != 0) {
                return;
            }
            if (D_004F50C0.GetMenuDown(0) != 0) {
                switch (func_00319330((char *)self + 0x4)) {
                case 0:
                    break;
                default:
                    return;
                }
            }
        } else {
            if (D_004F50C0.GetMenuConfirm(0) != 0) {
                StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)2, 0);
            }
        }
    }
}
