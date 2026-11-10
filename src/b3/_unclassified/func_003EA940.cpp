// Hand-written; the lifter refused it (FindTrack static inline; int k, int j declared before src).

extern const unsigned long kaB3HardCodedTrackList[];
struct UnkStruct_003EA940_8 { float field_0; float field_4; };
struct UnkStruct_003EA940_row { UnkStruct_003EA940_8 e[5]; };
extern const UnkStruct_003EA940_row D_004CC7A0[];

static inline int func_003EA940_inl1(unsigned long p0)
{
    int i = 0;
    goto test;
body:
    if (p0 == kaB3HardCodedTrackList[i]) return i;
    i++;
test:
    if (i < 36) goto body;
    return -1;
}

// 0x003EA940
extern "C" void func_003EA940(unsigned long n0, UnkStruct_003EA940_8 *out)
{
    int k = func_003EA940_inl1(n0);
    int j = 0;
    const UnkStruct_003EA940_8 *src = D_004CC7A0[k].e;
    for (; j < 5; j++) {
        out[j].field_0 = src[j].field_0;
        out[j].field_4 = src[j].field_4;
    }
}
