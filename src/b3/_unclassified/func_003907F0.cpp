// Hand-written; the lifter refused it (a86: FinishSyncReplay; byte-offset casts into D_00522660, changed flag as bool, store order a0/flag/a4/a8).

// func_003907F0 -- [L] DNAT: CB3OnlineStageLogic::FinishSyncReplay() (research/proto/new_names.csv, medium)
// Modeled on func_00391B80 (same D_00665E50 / D_00522660 timer idiom).

struct UnkStruct_003907F0_P {
    unsigned long field_0;
    unsigned long field_8[12];
    unsigned char pad_68[0x8];
    int field_70[12];
    int field_A0;
    int field_A4;
    int field_A8;
};

struct UnkStruct_D_0051BA88 {
    UnkStruct_003907F0_P * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0055EEF4 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0055EEF8 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0055EF00 {
    unsigned long field_0;
    unsigned char pad_8[0x8];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0051BACC {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_00665E50 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_00665E51 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E32AE0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_00522660 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

extern UnkStruct_D_0051BA88 D_0051BA88;
extern UnkStruct_D_0055EEF4 D_0055EEF4;
extern UnkStruct_D_0055EEF8 D_0055EEF8;
extern UnkStruct_D_0055EF00 D_0055EF00;
extern UnkStruct_D_0051BACC D_0051BACC;
extern UnkStruct_D_00665E50 D_00665E50;
extern UnkStruct_D_00665E51 D_00665E51;
extern UnkStruct_D_01E32AE0 D_01E32AE0;
extern UnkStruct_D_00522660 D_00522660;

extern "C" void func_0026FAA0(void *, int);
extern "C" void Stop__8CGtTimerFv(void *);
extern "C" void Start__8CGtTimerFv(void *);

// 0x003907F0
extern "C" void func_003907F0(void *a0 /* passed by every caller, not read here */)
{
    func_0026FAA0(&D_01E32AE0, 0);
    UnkStruct_003907F0_P * p = D_0051BA88.field_0;
    int n = D_0055EEF4.field_0;
    int m = D_0055EEF8.field_0;
    bool changed = false;
    if (p->field_A0 != n || p->field_A4 != m || p->field_A8 != 0) {
        p->field_A0 = n;
        changed = true;
        p->field_A4 = m;
        p->field_A8 = 0;
    }
    if (p->field_0 != D_0055EF00.field_0) {
        p->field_0 = D_0055EF00.field_0;
        changed = true;
    }
    for (int i = 0; i < n; i++) {
        unsigned long id = *(unsigned long *)((char *)&D_00522660 + i * 8 + 0x3C8B0);
        if (p->field_8[i] != id || p->field_70[i] != *((signed char *)&D_00522660 + i + 0x3C8E0)) {
            p->field_8[i] = id;
            changed = true;
            p->field_70[i] = *((signed char *)&D_00522660 + i + 0x3C8E0);
        }
    }
    D_00665E50.field_0 = 0;
    if (D_00665E50.field_0 != 0) {
        Stop__8CGtTimerFv(&D_00522660);
    } else if (D_00665E51.field_0 == 0) {
        Start__8CGtTimerFv(&D_00522660);
    }
    if (changed) {
        D_0051BACC.field_0 = 10;
    } else {
        D_0051BACC.field_0 = 12;
    }
}
