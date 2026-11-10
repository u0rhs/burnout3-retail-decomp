// CB3OfflineStageLogic::OnTakedown(CB3RaceCar*,CB3RaceCar*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3OfflineStageLogic.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (near15: records at this+0x20 as array member field_20[idx] indexed at each use).

// CB3OfflineStageLogic::OnTakedown(CB3RaceCar*, CB3RaceCar*) -- hand-written (a115 + near15): after the base
// OnTakedown, a qualifying takedown (victim not yet crashed, vfunc_10C, distance window) triggers func_00395060 on the
// victim's 16-byte record at this+0x20. The records are an array member indexed at each use (array members are not
// CSE'd: retail recomputes the record address for the call). Types and fields are placeholders [G].

// a115: 83 vs 84 instrs, 11 in changed runs; retail keeps idx*16 in a3 and recomputes self+a3 for the call arg (addu v0,s2,a3) -- every form CSEs it into one slot pointer; schedule of slot/at/a0 lui/li differs

struct UnkStruct_5_car {
    unsigned char pad_0[0x10CC];
    float field_10CC;
    unsigned char pad_10D0[0x32C];
    float field_13FC;
    unsigned char pad_1400[0x4EA];
    unsigned char field_18EA;
    unsigned char pad_18EB[0x29];
    int field_1914;
    unsigned char pad_1918[0x1A8];
    unsigned char field_1AC0_dummy;
};

struct UnkStruct_5_victim {
    unsigned char pad_0[0x1914];
    int field_1914;
    unsigned char pad_1918[0xEA8];
    int field_27C0;
};

struct UnkStruct_5_car1 {
    unsigned char pad_0[0x18EA];
    unsigned char field_18EA;
    unsigned char pad_18EB[0xAA9];
};

struct UnkStruct_5_cam {
    UnkStruct_5_car * field_0;
    int field_4;
    int field_8;
    unsigned char field_C;
    unsigned char field_D;
    unsigned char field_E;
    unsigned char field_F;
};

struct UnkStruct_5_g { unsigned char pad_0[0x12AD50]; unsigned char pad_x; };
struct UnkStruct_5_row { unsigned char pad_0[0x1594]; UnkStruct_5_car * field_1594; };

struct UnkStruct_5_self {
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
    virtual void vfunc_9C();
    virtual void vfunc_A0();
    virtual void vfunc_A4();
    virtual void vfunc_A8();
    virtual void vfunc_AC();
    virtual void vfunc_B0();
    virtual void vfunc_B4();
    virtual void vfunc_B8();
    virtual void vfunc_BC();
    virtual void vfunc_C0();
    virtual void vfunc_C4();
    virtual void vfunc_C8();
    virtual void vfunc_CC();
    virtual void vfunc_D0();
    virtual void vfunc_D4();
    virtual void vfunc_D8();
    virtual void vfunc_DC();
    virtual void vfunc_E0();
    virtual void vfunc_E4();
    virtual void vfunc_E8();
    virtual void vfunc_EC();
    virtual void vfunc_F0();
    virtual void vfunc_F4();
    virtual void vfunc_F8();
    virtual void vfunc_FC();
    virtual void vfunc_100();
    virtual void vfunc_104();
    virtual void vfunc_108();
    virtual bool vfunc_10C(void *, void *);
    unsigned char pad_4[0x1C];
    UnkStruct_5_cam field_20[8];   // [G] count unknown: one 16-byte record per player index (field_27C0)
};

struct UnkStruct_5_D { signed char field_0; unsigned char pad_1[0xF]; };
extern UnkStruct_5_g D_00522660;
extern UnkStruct_5_D D_004F507B;
extern "C" void OnTakedown__13CB3StageLogicFP10CB3RaceCarP10CB3RaceCar(void *, void *, void *);
extern "C" void func_00395060(void *);

extern "C" void OnTakedown__20CB3OfflineStageLogicFP10CB3RaceCarP10CB3RaceCar(UnkStruct_5_self * self, UnkStruct_5_victim * p1, UnkStruct_5_victim * p2)
{
    OnTakedown__13CB3StageLogicFP10CB3RaceCarP10CB3RaceCar(self, p1, p2);
    if (p2->field_1914 == 0) {
        int idx = p2->field_27C0;
        if (p1 != 0) {
            if (D_004F507B.field_0 != 0) {
                if (self->vfunc_10C(p2, p1)) {
                    UnkStruct_5_row * r = (UnkStruct_5_row *)((char *)&D_00522660 + self->field_20[idx].field_8 * 0x27D0 + 0x12AD50);
                    UnkStruct_5_car * c = r->field_1594;
                    float d;
                    bool ok;
                    if (c != 0 && c->field_18EA != 0 && ((UnkStruct_5_car1 *)r)->field_18EA == 0 && self->field_20[idx].field_E == 0 && c != self->field_20[idx].field_0 && (d = c->field_10CC - c->field_13FC, d >= 0.0f) && d <= 1.5f) ok = true; else ok = false;
                    if (ok) {
                        func_00395060(&self->field_20[idx]);
                    }
                }
            }
        }
    }
}
