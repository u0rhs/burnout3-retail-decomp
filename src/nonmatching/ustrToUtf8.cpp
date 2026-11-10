// NONMATCHING: ConvertUTF16toUTF8Fast__10CGtUnicodeFPCUsPUci -- retail 87 / ours 88 instructions, 24 in changed runs
// gaps1b: hand-drafted from the asm
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// gaps1b (2026-11-02): hand-drafted from the retail asm (0x213CB0). UTF-16 -> UTF-8: stops (terminated)
// at the end or when max < 2; a character that does not fit (n >= max) returns without a terminator [C 0x213D48].
// Name: the asm symbol, which came from a config/symbol_addrs.txt row marked "names are ours" (the earlier research repo, upstream)
// -- not evidence. [L] research/retail_names.csv (high): CGtUnicode::ConvertUTF16toUTF8Fast(const unsigned short*,unsigned char*,int).
// TRACK: clean
// EQUIV: [L] written from the retail asm: every branch, store and call accounted for

typedef unsigned short UnkUChar;          // [C] UTF-16 code units (lhu / sh)
extern UnkUChar thousandsSep;             // [C] gp-relative u16 globals
extern UnkUChar decimalPoint;
extern UnkUChar plusSign;
extern UnkUChar minusSign;
extern float powersOf10[];                // [C] lwc1 powersOf10[decimals]
extern unsigned char _gan8NumTrailingBytesForUTF8[];
extern unsigned int _ganOffsetsFromUTF8[];
extern unsigned char _ganFirstByteMark[];
extern "C" unsigned int strlen(const char *);
extern "C" int _CopyUntilNextParameter__FPPUsPPCUs(UnkUChar **, const UnkUChar **);

// [G] the digit loop shared by the PrintInt family (inlined in each): up to 12 digits, least significant first,
// a separator after every third when sep != 0; then zero padding to minDigits; then the digits reversed
static inline UnkUChar * func_002135C0_inl1(UnkUChar * d, unsigned int v, int minDigits, UnkUChar sep)
{
    UnkUChar buf[16];
    int group = 0, count = 0, idx = 0;
    while (count < 12) {
        unsigned int q = v / 10;
        buf[idx] = (UnkUChar)('0' + v - q * 10);
        if (q == 0) {
            count++;
            idx++;
            break;
        }
        if (sep != 0) {
            group++;
            if (group == 3) {
                idx++;
                group = 0;
                buf[idx] = sep;
            }
        }
        v = q;
        count++;
        idx++;
    }
    while (count < minDigits) {
        *d++ = '0';
        minDigits--;
    }
    while (idx > 0) {
        idx--;
        *d++ = buf[idx];
    }
    *d = 0;
    return d;
}

// [G] ustrFromFloat / NoSep: the integer part through the separator global set to sep for the call, then the fraction
static inline UnkUChar * func_00213100_inl1(UnkUChar * d, float f, int decimals, int plus, int nosep)
{
    UnkUChar sep0 = thousandsSep;          // read first in the separator form (0x213108)
    UnkUChar dp = decimalPoint;
    if (f < 0.0f) {
        *d++ = minusSign;
        f = -f;
    } else if (plus == 1) {
        *d++ = plusSign;
    }
    int ip = (int)f;                       // cvt.w.s: truncation (EE FPU)
    UnkUChar save = thousandsSep;
    thousandsSep = nosep ? 0 : sep0;
    unsigned int u = ip;
    if (ip < 0) {
        *d++ = minusSign;
        u = -ip;
    }
    d = func_002135C0_inl1(d, u, 0, thousandsSep);
    thousandsSep = save;
    if (decimals == 0) {
        return d;
    }
    *d = dp;
    d++;
    int frac = (int)((f - (float)ip) * powersOf10[decimals]);
    return func_002135C0_inl1(d, frac, decimals, 0);
}

// 0x00213CB0
extern "C" void ConvertUTF16toUTF8Fast__10CGtUnicodeFPCUsPUci(const UnkUChar * src, unsigned char * dst, int max)
{
    for (;;) {
        unsigned int ch = *src;
        if (ch == 0 || max < 2) {
            *dst = 0;
            return;
        }
        src++;
        unsigned char n = 0;
        if (ch < 0x80) n = 1;
        else if (ch < 0x800) n = 2;
        else if (ch < 0x10000) n = 3;
        else if (ch < 0x200000) n = 4;
        if (!(n < max)) {
            return;
        }
        dst += n;
        switch (n) {
        case 4: *--dst = (unsigned char)((ch | 0x80) & 0xBF); ch >>= 6;
        case 3: *--dst = (unsigned char)((ch | 0x80) & 0xBF); ch >>= 6;
        case 2: *--dst = (unsigned char)((ch | 0x80) & 0xBF); ch >>= 6;
        case 1: *--dst = (unsigned char)(ch | _ganFirstByteMark[n]);
            dst += n;
            break;
        default:
            dst += n;
            break;
        }
        max -= n;
    }
}
