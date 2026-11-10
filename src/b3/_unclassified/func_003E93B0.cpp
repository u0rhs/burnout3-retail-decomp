// Hand-written; the lifter refused it (int i,j,k,f declared at top).

struct UnkStruct_Key { unsigned char pad_0[8]; unsigned long field_8; };
struct UnkStruct_Item { unsigned char pad_0[0x34]; UnkStruct_Key *field_34; unsigned char pad_38[8]; };
struct UnkStruct_Elem { unsigned char pad_0[0x10]; UnkStruct_Item *field_10; int field_14; };
struct UnkStruct_Group { UnkStruct_Elem *field_0; int field_4; };
struct UnkStruct_D_00518690 { unsigned char pad_0[4]; UnkStruct_Group *field_4; int field_8; };
struct UnkStruct_D_00518690_w { UnkStruct_D_00518690 *field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_00518690_w D_00518690;
extern unsigned long kaB3HardCodedCrashStageList[];
// 0x003E93B0
extern "C" UnkStruct_Item * func_003E93B0(int p0)
{
    int i, j, k, f;
    UnkStruct_D_00518690 *r = D_00518690.field_0;
    for (i = 0; i < r->field_8; i++) {
        UnkStruct_Group *g = &r->field_4[i];
        for (j = 0; j < g->field_4; j++) {
            UnkStruct_Elem *e = &g->field_0[j];
            for (k = 0; k < e->field_14; k++) {
                unsigned long key = e->field_10[k].field_34->field_8;
                                for (f = 0; f < 100; f++) {
                    if (key == kaB3HardCodedCrashStageList[f]) goto got;
                }
                f = -1;
            got:
                if (f == p0) return &e->field_10[k];
            }
        }
    }
    return 0;
}
