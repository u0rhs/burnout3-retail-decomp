// Hand-written; the lifter refused it (a89: loop counters declared at function top in order a,b,c then s).

// Prepare__26CB3HardCodedCrashStageListFv -- [L] DNAT: CB3HardCodedCrashStageList::Prepare() (research/proto/new_names.csv, high)
struct UnkStruct_003E9580_k {
    unsigned char pad_0[8];
    unsigned long field_8;
};
struct UnkStruct_003E9580_e {
    unsigned char pad_0[0x34];
    UnkStruct_003E9580_k *field_34;
    unsigned char pad_38[0x8];
};
struct UnkStruct_003E9580_s {
    unsigned char pad_0[0x10];
    UnkStruct_003E9580_e *field_10;
    int field_14;
};
struct UnkStruct_003E9580_t {
    UnkStruct_003E9580_s *field_0;
    int field_4;
};
struct UnkStruct_003E9580_r {
    unsigned char pad_0[8];
    UnkStruct_003E9580_t field_8;
};
struct UnkStruct_003E9580_g {
    UnkStruct_003E9580_r *field_0;
    unsigned char pad_4[0xC];
};
struct UnkStruct_003E9580_h {
    unsigned char pad_0[4];
    UnkStruct_003E9580_r *field_4;
};
struct UnkStruct_003E9580_d {
    UnkStruct_003E9580_h *field_0;
    unsigned char pad_4[0xC];
};
extern UnkStruct_003E9580_d D_00518690;
extern unsigned long kaB3HardCodedCrashStageList[];

// 0x003E9580
extern "C" void Prepare__26CB3HardCodedCrashStageListFv()
{
    UnkStruct_003E9580_r *r = D_00518690.field_0->field_4;
    UnkStruct_003E9580_t *t = &r->field_8;
    for (int i = 0; i < 100; i++) {
        int v = i;
        for (int j = 0; j < t->field_4; j++) {
            if (v < t->field_0[j].field_14) break;
            v -= t->field_0[j].field_14;
        }
    }
    int a, b, c;
    UnkStruct_003E9580_s *s;
    for (a = 0; a < t->field_4; a++) {
        s = &t->field_0[a];
        for (b = 0; b < s->field_14; b++) {
            unsigned long id = s->field_10[b].field_34->field_8;
            for (c = 0; c < 100; c++) {
                if (id == kaB3HardCodedCrashStageList[c]) break;
            }
        }
    }
}
