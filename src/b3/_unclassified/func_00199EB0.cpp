// Hand-written; the lifter refused it (diff_vs_retail lui-mask symmetry fix (a83)).

// Hand-written; the lifter refused it (a83: CB3World::SetCarNumbers [L] DNAT; byte-identical (diff tool flags lui at,0x13 spuriously)).

// SetCarNumbers__8CB3WorldFiii -- CB3World::SetCarNumbers(int,int,int) [L] DNAT (research/proto/new_names.csv, medium)
struct UnkStruct_P { unsigned char pad_0[0x10]; };
struct UnkStruct_I { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_00199EB0_car {
    unsigned char pad_0[0x19AC];
    unsigned char field_19AC;
    unsigned char pad_19AD[0x2460 - 0x19AD];
    void * field_2460;
};
struct UnkStruct_00199EB0_a { unsigned char pad_0[0x27D0]; };
struct UnkStruct_00199EB0_b { unsigned char pad_0[0x2460]; };
struct UnkStruct_00199EB0_c { unsigned char pad_0[0x1AA0]; };
struct UnkStruct_00199EB0 {
    unsigned char pad_0[0x12AD1C];
    int field_12AD1C;
    int field_12AD20;
    int field_12AD24;
    UnkStruct_00199EB0_car * field_12AD28[6];
    int field_12AD40;
    int field_12AD44;
    int field_12AD48;
    int field_12AD4C;
    UnkStruct_00199EB0_a field_12AD50[2];
    unsigned char pad_12FCF0[0x13B2D0 - 0x12FCF0 - 0];
    UnkStruct_00199EB0_c field_13B2D0[1];
};
extern UnkStruct_I D_01E32B08;
extern UnkStruct_P D_01E32AE0;
extern UnkStruct_P D_00516DF0;
extern UnkStruct_P D_004EE040;
extern "C" int func_002366D0(void *, int);

// [L] DNAT: CB3World::SetCarNumbers(int,int,int) (research/proto/new_names.csv, medium)
// 0x00199EB0
extern "C" void SetCarNumbers__8CB3WorldFiii(UnkStruct_00199EB0 * self, int p0, int p1, int p2)
{
    self->field_12AD40 = 0;
    self->field_12AD44 = 0;
    self->field_12AD48 = 0;
    self->field_12AD1C = 0;
    self->field_12AD24 = 0;
    if (p2 > 0) {
        self->field_12AD1C = D_01E32B08.field_0;
        for (int i = 0; i < self->field_12AD1C; i++) {
            if (func_002366D0(&D_01E32AE0, i)) {
                self->field_12AD28[i] = (UnkStruct_00199EB0_car *)&self->field_13B2D0[self->field_12AD48];
                self->field_12AD48++;
            } else {
                self->field_12AD28[i] = (UnkStruct_00199EB0_car *)&self->field_12AD50[0];
                self->field_12AD28[i]->field_2460 = &D_00516DF0;
            }
            self->field_12AD28[i]->field_19AC = i;
        }
        self->field_12AD40 = p0;
    } else {
        int n = p0 + p1;
        while (self->field_12AD1C < n) {
            if (self->field_12AD40 < p0) {
                self->field_12AD28[self->field_12AD1C] = (UnkStruct_00199EB0_car *)&self->field_12AD50[self->field_12AD40];
                self->field_12AD28[self->field_12AD1C]->field_2460 = (char *)&D_004EE040 + 0x28DB0 + self->field_12AD40 * 36;
                self->field_12AD40++;
            } else if (self->field_12AD44 < p1) {
                self->field_12AD28[self->field_12AD1C] = (UnkStruct_00199EB0_car *)((char *)self + 0x12FCF0 + self->field_12AD44 * 0x2460);
                self->field_12AD44++;
            }
            self->field_12AD28[self->field_12AD1C]->field_19AC = self->field_12AD1C;
            self->field_12AD1C++;
        }
    }
    for (int i = self->field_12AD1C; i < 6; i++) {
        self->field_12AD28[i] = 0;
    }
}
