// Hand-written; the lifter refused it (a74: same find-helper shape as func_00231A20 (+0x5B / 5->4)).

struct UnkStruct_00231A20_e {
    unsigned char pad_0[0x14];
    int field_14;
    unsigned char pad_18[0x8];
    int field_20;
    unsigned char pad_24[0x37];
    unsigned char field_5B;
    unsigned char pad_5C[0x34];
};
struct UnkStruct_00231A20_m {
    unsigned char pad_0[0x8];
    int field_8;
};
struct UnkStruct_00231A20_t {
    UnkStruct_00231A20_e field_0[8];
};

// [L] DNAT: CGtNATDataManager::NATTestConnectionMessageDeliveredCallback(bool,CGtNetworkMessage*,void*) (research/proto/new_names.csv, medium)
static inline UnkStruct_00231A20_e * func_00231920_find(UnkStruct_00231A20_t * t, int key)
{
    for (int i = 0; i < 8; i++) {
        if (t->field_0[i].field_14 == key) {
            return &t->field_0[i];
        }
    }
    return 0;
}

// 0x00231920
extern "C" void func_00231920(bool p0, UnkStruct_00231A20_m * p1, UnkStruct_00231A20_t * p2)
{
    if (p0) {
        UnkStruct_00231A20_e * e = func_00231920_find(p2, p1->field_8);
        e->field_5B = 1;
    } else {
        UnkStruct_00231A20_e * e = func_00231920_find(p2, p1->field_8);
        if (e->field_20 == 5) {
            e->field_20 = 4;
        }
    }
}
