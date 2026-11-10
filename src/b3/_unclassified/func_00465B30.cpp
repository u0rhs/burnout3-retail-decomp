// Hand-written; the lifter refused it (near16: scoped opt_removeemptyloops off [G] + entry-jump goto empty loop i<=2 (MWCC tiny-loop nop padding)).

struct UnkStruct_00465B30_v3 { float x; float y; float z; };
struct UnkStruct_00465B30_s { int field_0; UnkStruct_00465B30_v3 field_4; void *field_10; void *field_14; };
struct UnkStruct_00465B30_g {
    unsigned char pad_0[0xDC];
    int field_DC;
    unsigned char pad_E0[0x10];
    UnkStruct_00465B30_s field_F0;
    unsigned char pad_108[0x1C];
    UnkStruct_00465B30_s field_124;
};
struct UnkStruct_D_004E2FC4_b { UnkStruct_00465B30_g *field_0; };
extern UnkStruct_D_004E2FC4_b D_004E2FC4;
extern "C" void func_00466620(); extern "C" void func_004665D0(); extern "C" void func_004664E0();
extern "C" void func_00466430(); extern "C" void func_004663A0(); extern "C" void func_00466310();
extern "C" void func_004662D0(); extern "C" void func_00466590();
extern "C" int func_004661C0(void *); extern "C" int func_004661B0();

// N182 [G] scoped to this function: retail keeps an empty counted loop (b test; addiu; slti; 3 nops = MWCC tiny-loop
// padding; bnez) that opt_removeemptyloops would delete. Entry-jump goto form (N24).
#pragma push
#pragma opt_removeemptyloops off
// 0x00465B30
extern "C" int func_00465B30()
{
    int r = 0;
    int i = 0;
    D_004E2FC4.field_0->field_F0.field_0 = 4;
    UnkStruct_00465B30_g *g = D_004E2FC4.field_0;
    g->field_124 = g->field_F0;
    goto t3; b3: i++; t3: if (i <= 2) goto b3;
    g = D_004E2FC4.field_0;
    switch (g->field_DC) {
    case 0: *(void **)&g->field_F0.field_4.x = (void *)func_00466620; break;
    case 1: *(void **)&g->field_F0.field_4.x = (void *)func_004665D0; break;
    case 2: *(void **)&g->field_F0.field_4.x = (void *)func_004664E0; break;
    case 3: *(void **)&g->field_F0.field_4.x = (void *)func_00466430; break;
    case 4: *(void **)&g->field_F0.field_4.x = (void *)func_004663A0; break;
    case 5: *(void **)&g->field_F0.field_4.x = (void *)func_00466310; break;
    case 6: case 7: *(void **)&g->field_F0.field_4.x = (void *)func_004662D0; break;
    case 8: *(void **)&g->field_F0.field_4.x = (void *)func_00466590; break;
    default: r = 0xD; break;
    }
    if (r == 0) {
        g = D_004E2FC4.field_0;
        switch (g->field_DC) {
        case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8:
            *(void **)&g->field_F0.field_4.y = (void *)func_004661C0; break;
        default: r = 0xD; break;
        }
    }
    if (r == 0) {
        g = D_004E2FC4.field_0;
        switch (g->field_DC) {
        case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8:
            *(void **)&g->field_F0.field_4.z = (void *)func_004661B0; break;
        default: r = 0xD; break;
        }
    }
    D_004E2FC4.field_0->field_F0.field_10 = 0;
    D_004E2FC4.field_0->field_F0.field_14 = 0;
    return r;
}

#pragma pop
