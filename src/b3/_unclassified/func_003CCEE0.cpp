// Hand-written; the lifter refused it (written by hand (lifter refused): switch on mode with an int*float static inline helper; one-case switch on the global (-1 -> computed value)).

// func_003CCEE0 -- hand-written (the lifter refused: else-branch shape).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Every type is [G] (instruction widths).

struct UnkStruct_D_0064CE48 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

extern UnkStruct_D_0064CE48 D_0064CE48;

// [G] inlined helper (name unknown): int scaled by a float factor
static inline int func_003CCEE0_inl1(int v, float k)
{
    return (int)((float)v * k);
}

// 0x003CCEE0
extern "C" int func_003CCEE0(void *n0_, int p0, int p1, int p2)
{
    int n0 = (int)n0_;
    int v = p1 + p0;
    switch (p2) {
    case -2:
        v = func_003CCEE0_inl1(v, 0.5f);
        break;
    case 2:
        v = func_003CCEE0_inl1(v, 2.0f);
        break;
    case 4:
        v = func_003CCEE0_inl1(v, 4.0f);
        break;
    }
    int r = D_0064CE48.field_0;
    switch (r) {
    case -1:
        r = v;
        break;
    }
    return r;
}
