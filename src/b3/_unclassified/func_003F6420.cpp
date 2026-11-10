// Hand-written; the lifter refused it (a89: 4-case switch with direct returns, falls off end for default).

// GetLockedRewardString__23CB3RewardImageComponentF18EB3RewardImageTypei -- [L] DNAT: CB3RewardImageComponent::GetLockedRewardString(EB3RewardImageType,int) (research/proto/new_names.csv, high)
struct UnkStruct_003F6420 {
    unsigned char pad_0[0x18];
    int field_18[1];  // [G] element count unknown
};
struct UnkStruct_003F6420_blk { unsigned char pad_0[0x10]; };
extern UnkStruct_003F6420_blk D_0051BA44;
extern "C" int func_003F5EB0(int);
extern "C" int func_003F5F30(int);
extern "C" int func_003F5FB0(int);
extern "C" int func_00271A00(void *, int);

// 0x003F6420
extern "C" int GetLockedRewardString__23CB3RewardImageComponentF18EB3RewardImageTypei(UnkStruct_003F6420 * self, int type, int p1)
{
    switch (type) {
    case 0:
        return self->field_18[p1];
    case 1:
        return func_00271A00(&D_0051BA44, func_003F5EB0(p1));
    case 2:
        return func_00271A00(&D_0051BA44, func_003F5F30(p1));
    case 3:
        return func_00271A00(&D_0051BA44, func_003F5FB0(p1));
    }
}
