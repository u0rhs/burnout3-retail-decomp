// Hand-written; the lifter refused it (a89: movz n via ?: ; clamp written lo > hi (slt at); pointer locals).

// func_00423E20 -- [L] DNAT: CB3CrashAftermathPage::UpdateCrashScore(int) (research/proto/new_names.csv, vtable slot 4)
struct UnkStruct_D_004F509C {
    float field_0;
    unsigned char pad_4[0xC];
};
struct UnkStruct_00423E20_blk { unsigned char pad_0[0x10]; };
struct UnkStruct_00423E20 {
    unsigned char pad_0[0x160];
    int field_160[2];
    int field_168[2];
    unsigned char pad_170[8];
    unsigned char field_178;
};
extern UnkStruct_D_004F509C D_004F509C;
extern UnkStruct_00423E20_blk D_01E89788;
extern "C" void func_0031BD60(void *, int, bool);

// 0x00423E20
extern "C" void func_00423E20(UnkStruct_00423E20 * self)
{
    int n = self->field_178 ? 2 : 1;
    float dt = D_004F509C.field_0;
    for (int i = 0; i < n; i++) {
        int *lo = &self->field_160[i];
        int *hi = &self->field_168[i];
        int step = (int)((float)(*hi - *lo) / (0.25f / dt));
        if (step > 0) {
            *lo = *lo + step;
            if (*lo > *hi) *lo = *hi;
            func_0031BD60(&D_01E89788, *lo, i == 1);
        }
    }
}
