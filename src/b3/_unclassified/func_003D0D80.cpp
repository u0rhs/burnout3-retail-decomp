// Hand-written; the lifter refused it (a132: 36 tracks x 4 groups x 5 entries; switch(j) cases 0..3 each a k-loop; entry layout from sibling func_003D11D0).

union UnkUnion_D0D80 { int i; float f; };
struct UnkStruct_D0D80_a {
    unsigned short field_0[9];
    unsigned char field_12;
    unsigned char field_13;
    signed char field_14;
    unsigned char field_15;
    unsigned char pad_16[2];
    UnkUnion_D0D80 field_18;
};
struct UnkStruct_D0D80_g { UnkStruct_D0D80_a field_0[5]; };
struct UnkStruct_D0D80_t { UnkStruct_D0D80_g field_0[4]; };
struct UnkStruct_D0D80 { UnkStruct_D0D80_t field_0[0x24]; };
struct UnkStruct_D_004A5240 { unsigned char pad_0[0x10]; };
extern UnkStruct_D_004A5240 D_004A5240;
extern "C" void CopyN__10CGtUnicodeFPUsiPCUs(void *, int, void *);
extern "C" float func_003EA7E0(int, int);
extern "C" int func_003EA7D0(int, int);
extern "C" float func_003EA7C0(int, int);
extern "C" float func_003EA7B0(int, int);

// 0x003D0D80
extern "C" void func_003D0D80(UnkStruct_D0D80 *self)
{
    int i, j, k;
    for (i = 0; i < 0x24; i++) {
        for (j = 0; j < 4; j++) {
            UnkStruct_D0D80_g *g = &self->field_0[i].field_0[j];
            switch (j) {
            case 0:
                for (k = 0; k < 5; k++) {
                    float v = func_003EA7E0(i, k);
                    UnkStruct_D0D80_a *e = &g->field_0[k];
                    CopyN__10CGtUnicodeFPUsiPCUs(e->field_0, 9, &D_004A5240);
                    e->field_12 = 0;
                    e->field_13 = 0;
                    e->field_14 = -1;
                    e->field_15 = 255;
                    e->field_18.f = v;
                }
                break;
            case 1:
                for (k = 0; k < 5; k++) {
                    int v = func_003EA7D0(i, k);
                    UnkStruct_D0D80_a *e = &g->field_0[k];
                    CopyN__10CGtUnicodeFPUsiPCUs(e->field_0, 9, &D_004A5240);
                    e->field_12 = 0;
                    e->field_13 = 0;
                    e->field_14 = -1;
                    e->field_15 = 255;
                    e->field_18.i = v;
                }
                break;
            case 2:
                for (k = 0; k < 5; k++) {
                    float v = func_003EA7C0(i, k);
                    UnkStruct_D0D80_a *e = &g->field_0[k];
                    CopyN__10CGtUnicodeFPUsiPCUs(e->field_0, 9, &D_004A5240);
                    e->field_12 = 0;
                    e->field_13 = 0;
                    e->field_14 = -1;
                    e->field_15 = 255;
                    e->field_18.f = v;
                }
                break;
            case 3:
                for (k = 0; k < 5; k++) {
                    float v = func_003EA7B0(i, k);
                    UnkStruct_D0D80_a *e = &g->field_0[k];
                    CopyN__10CGtUnicodeFPUsiPCUs(e->field_0, 9, &D_004A5240);
                    e->field_12 = 0;
                    e->field_13 = 0;
                    e->field_14 = -1;
                    e->field_15 = 255;
                    e->field_18.f = v;
                }
                break;
            }
        }
    }
}
