// Hand-written; the lifter refused it (stride-0x90 find; ternary 1:0 for last arm gives retail delay-slot b).

struct UnkStruct_00230EE0_e {
    unsigned char pad_0[0x14];
    int field_14;
    int field_18;
    unsigned char pad_1C[4];
    int field_20;
    unsigned char pad_24[0x6C];
};
struct UnkStruct_00230EE0 {
    UnkStruct_00230EE0_e field_0[8];
};
// 0x00230EE0
// [G] 8-entry (stride 0x90) lookup by field_14; no DNAT name (new_names.csv has no row)
extern "C" int func_00230EE0(UnkStruct_00230EE0 *self, int key, void *a2 /* passed by every caller, not read here */)
{
    UnkStruct_00230EE0_e *e;
    int i;
    for (i = 0; i < 8; i++) {
        e = &self->field_0[i];
        if (key == e->field_14) goto found;
    }
    e = 0;
found:
    int st = e->field_20;
    if (st == 2) return 1;
    if (st == 6 || st == 7) return 0;
    return e->field_18 == -1 ? 1 : 0;
}
