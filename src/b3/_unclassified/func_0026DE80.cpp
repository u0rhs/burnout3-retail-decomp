// Hand-written; the lifter refused it ([L] DNAT low: CB3NetworkManager::OnGameStart(); visit field_28 entries, optional func_00235180, reset 8 slots at +0x323E0 (stride 0x50) - declaration fix only (slot struct, no overlapping fields)).

// func_0026DE80 -- hand-written (a69; the lifter refused 'overlapping fields at +0x28'). Unnamed here; [L] DNAT (low):
// CB3NetworkManager::OnGameStart() (research/proto/new_names.csv, 0026DE80, low) -- do not rename. Layout [G] from widths.
// Visits each of the field_28 entries, optionally calls func_00235180, then resets the 8 slot records at +0x323E0 (stride 0x50).
struct UnkStruct_0026DE80_slot {
    int field_0;
    unsigned char field_4;
    unsigned char pad_5[0xF];
    unsigned char field_14[0x18];
    unsigned char pad_2C[0x20];
    unsigned char field_4C;
    unsigned char field_4D;
    unsigned char pad_4E[2];
};
struct UnkStruct_0026DE80 {
    unsigned char pad_0[0x28];
    int field_28;
    unsigned char pad_2C[0x323E0 - 0x2C];
    UnkStruct_0026DE80_slot field_323E0[8];
    int field_32660;
};
extern "C" void *func_002366D0(UnkStruct_0026DE80 *, int);
extern "C" void func_0023F7F0(void *);
extern "C" void func_00235180(UnkStruct_0026DE80 *);
extern "C" void func_00272E50(void *);

// 0x0026DE80
extern "C" void func_0026DE80(UnkStruct_0026DE80 *self, int flag)
{
    for (int i = 0; i < self->field_28; i++) {
        void *p = func_002366D0(self, i);
        if (p != 0) {
            func_0023F7F0(p);
        }
    }
    if (flag != 0) {
        func_00235180(self);
    }
    for (int j = 0; j < 8; j++) {
        self->field_323E0[j].field_0 = -1;
        self->field_323E0[j].field_4 = 0;
        func_00272E50(self->field_323E0[j].field_14);
        self->field_323E0[j].field_4C = 0;
        self->field_323E0[j].field_4D = 0;
    }
    self->field_32660 = 0;
}
