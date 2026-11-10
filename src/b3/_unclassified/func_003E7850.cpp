// Hand-written; the lifter refused it (a85: GetBlockSize switch (22 cases, jtbl), block order 13,12 / 20,18,19 follows retail).

// [L] DNAT: CB3MemoryManager::GetBlockSize(EB3MemoryBlock) const (research/proto/new_names.csv, high)
struct UnkStruct_003E7850 {
    unsigned char pad_0[0xC];
    int field_C;
    unsigned char pad_10[0xC];
    int field_1C;
    unsigned char pad_20[0xC];
    int field_2C;
    unsigned char pad_30[0xC];
    int field_3C;
    unsigned char pad_40[0xC];
    int field_4C;
    unsigned char pad_50[0xC];
    int field_5C;
    unsigned char pad_60[0xC];
    int field_6C;
    unsigned char pad_70[0xC];
    int field_7C;
    unsigned char pad_80[0x7C];
    int field_FC;
    unsigned char pad_100[0xC];
    int field_10C;
    unsigned char pad_110[0x5C];
    int field_16C;
    unsigned char pad_170[0xC];
    int field_17C;
    unsigned char pad_180[0xC];
    int field_18C;
    unsigned char pad_190[0x9C];
    int field_22C;
    unsigned char pad_230[0x11C];
    int field_34C;
    unsigned char pad_350[0xC];
    int field_35C;
    unsigned char pad_360[0xC];
    int field_36C;
    unsigned char pad_370[0xBC];
    int field_42C;
    unsigned char pad_430[0x5C];
    int field_48C;
    unsigned char pad_490[0xC];
    int field_49C;
    unsigned char pad_4A0[0xC];
    int field_4AC;
    unsigned char pad_4B0[0x12C];
    int field_5DC;
    unsigned char pad_5E0[0x22C];
    int field_80C;
    unsigned char pad_810[0xC];
    int field_81C;
    unsigned char pad_820[0xC];
    int field_82C;
    unsigned char pad_830[0xBC];
    int field_8EC;
    unsigned char pad_8F0[0x1C];
    int field_90C;
    unsigned char pad_910[0xC];
    int field_91C;
    unsigned char pad_920[0x1C];
    int field_93C;
    unsigned char pad_940[0xC];
    int field_94C;
    unsigned char pad_950[0xC];
    int field_95C;
    unsigned char pad_960[0xC];
    int field_96C;
    unsigned char pad_970[0xC];
    int field_97C;
    unsigned char pad_980[0x4];
    int field_984;
};

// 0x003E7850
extern "C" int GetBlockSize__16CB3MemoryManagerCF14EB3MemoryBlock(const UnkStruct_003E7850 *self, int block)
{
    switch (block) {
    case 0:
        return self->field_5C;
    case 1:
        if (self->field_984 == 0) return self->field_8EC;
        return self->field_984 == 2 ? self->field_42C : self->field_10C;
    case 2:
        return self->field_984 == 2 ? self->field_82C : self->field_36C;
    case 3:
        if (self->field_984 == 0) return self->field_91C;
        return self->field_984 == 2 ? self->field_48C : self->field_16C;
    case 5:
        if (self->field_984 == 0) return self->field_93C;
        return self->field_984 == 2 ? self->field_49C : self->field_17C;
    case 6:
        return self->field_984 == 2 ? self->field_4AC : self->field_18C;
    case 7:
        return self->field_984 == 2 ? self->field_5DC : self->field_22C;
    case 8:
        return self->field_6C;
    case 9:
        return self->field_984 == 2 ? self->field_80C : self->field_34C;
    case 10:
        return self->field_1C;
    case 11:
        return self->field_2C;
    case 13:
        return self->field_984 == 2 ? self->field_81C : self->field_35C;
    case 12:
        return self->field_3C;
    case 14:
        return self->field_C;
    case 15:
        return self->field_4C;
    case 16:
        return self->field_94C;
    case 17:
        return self->field_96C;
    case 20:
        return self->field_95C;
    case 18:
        return self->field_97C;
    case 19:
        return self->field_90C;
    case 21:
        return self->field_7C;
    case 22:
        return self->field_FC;
    case 4:
    default:
        return -1;
    }
}
