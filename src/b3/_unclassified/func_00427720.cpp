// Hand-written; the lifter refused it ([L] DNAT CB3ImageReward2dObject::GetTexture; D_01EA4710 as 0x10 struct stops lui CSE; uninit idx for default).

extern void * D_01EA4470[];  // [G] element count unknown
struct UnkStruct_D_01EA4710 { void * field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_01EA4710 D_01EA4710;
extern "C" int func_003F5F10(int);

// 0x00427720
extern "C" void * GetTexture__22CB3ImageReward2dObjectF18EB3RewardImageTypei(int n0, int n1)
{
    if (n1 == -1) {
        return D_01EA4710.field_0;
    }
    int idx;
    switch (n0) {
    case 0:
        idx = n1 + 0x15;
        break;
    case 1:
        idx = n1 + 0x25;
        break;
    case 2:
        idx = func_003F5F10(n1);
        break;
    case 3:
        idx = n1 + 0x20;
        break;
    }
    return D_01EA4470[idx];
}
