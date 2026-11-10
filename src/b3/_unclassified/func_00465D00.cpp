// Hand-written; the lifter refused it (re-queued after the jtbl_retarget 2-table fix (from build/vt/hand/func_00465D00_rsw90199630.cpp)).


struct UnkStruct_00465D00_r { int field_0; int field_4; int field_8; int field_C; int field_10; int field_14[6]; };
struct UnkStruct_00465D00_g {
    unsigned char pad_0[0xDC];
    UnkStruct_00465D00_r field_DC;
    unsigned char pad_108[8];
    UnkStruct_00465D00_r field_110;
};
struct UnkStruct_D_004E2FC4_c { UnkStruct_00465D00_g *field_0; };
extern UnkStruct_D_004E2FC4_c D_004E2FC4;
extern "C" void func_00466850(int *, int *); extern "C" void func_004667D0(); extern "C" void func_00466750();
extern "C" void func_004669E0(void *, void *); extern "C" void func_00466970(); extern "C" void func_00466A10();
extern "C" int func_00465B30();

// 0x00465D00
extern "C" int func_00465D00(int p0, int p1)
{
    int r = 0;
    UnkStruct_00465D00_g *g = D_004E2FC4.field_0;
    g->field_DC.field_0 = p0;
    if (p1 != 0) goto copy;
main:
    g = D_004E2FC4.field_0;
    switch (g->field_DC.field_0) {
    case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8:
        goto setA;
    default: r = 0xD; break;
    }
after1:
    if (r == 0) {
        g = D_004E2FC4.field_0;
        switch (g->field_DC.field_0) {
        case 0: case 1: case 2: case 3: case 4: case 5:
            *(void **)&g->field_DC.field_8 = (void *)func_00466850; break;
        case 6: case 8:
            *(void **)&g->field_DC.field_8 = (void *)func_004667D0; break;
        case 7:
            *(void **)&g->field_DC.field_8 = (void *)func_00466750; break;
        default: r = 0xD; break;
        }
    }
    if (r == 0) {
        g = D_004E2FC4.field_0;
        switch (g->field_DC.field_0) {
        case 0: case 1: case 2: case 3: case 4: case 5:
            *(void **)&g->field_DC.field_C = (void *)func_004669E0; break;
        case 6: case 8:
            *(void **)&g->field_DC.field_C = (void *)func_00466970; break;
        case 7:
            *(void **)&g->field_DC.field_C = (void *)func_00466750; break;
        default: break;
        }
    }
    return func_00465B30();
copy:
    {
        UnkStruct_00465D00_g *q = D_004E2FC4.field_0;
        UnkStruct_00465D00_r *src = &q->field_DC;
        UnkStruct_00465D00_r *dst = &q->field_110;
        *dst = *src;
    }
    goto main;
setA:
    *(void **)&g->field_DC.field_4 = (void *)func_00466A10;
    goto after1;
}
