// Hand-written; the lifter refused it (a74: static inline find helper returning pointer-or-0, 8 entries stride 0x90).

struct UnkStruct_00231A20_e {
    unsigned char pad_0[0x14];
    int field_14;
    unsigned char pad_18[0x8];
    int field_20;
    unsigned char pad_24[0x35];
    unsigned char field_59;
    unsigned char pad_5A[0x36];
};
struct UnkStruct_00231A20_m {
    unsigned char pad_0[0x8];
    int field_8;
};
struct UnkStruct_00231A20_t {
    UnkStruct_00231A20_e field_0[8];
};

// [L] DNAT: CGtNATDataManager::NATProtoMangleTestConnectionMessageDeliveredCallback(bool,CGtNetworkMessage*,void*) (research/proto/new_names.csv, high)
static inline UnkStruct_00231A20_e * func_00231A20_find(UnkStruct_00231A20_t * t, int key)
{
    for (int i = 0; i < 8; i++) {
        if (t->field_0[i].field_14 == key) {
            return &t->field_0[i];
        }
    }
    return 0;
}

// 0x00231A20
extern "C" void func_00231A20(bool p0, UnkStruct_00231A20_m * p1, UnkStruct_00231A20_t * p2)
{
    if (p0) {
        UnkStruct_00231A20_e * e = func_00231A20_find(p2, p1->field_8);
        e->field_59 = 1;
    } else {
        UnkStruct_00231A20_e * e = func_00231A20_find(p2, p1->field_8);
        if (e->field_20 == 7) {
            e->field_20 = 6;
        }
    }
}
