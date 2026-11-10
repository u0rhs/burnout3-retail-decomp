// NONMATCHING: ConvertUTF8toUTF16__10CGtUnicodeFPCUcPUsi -- retail 94 / ours 94 instructions, 49 in changed runs
// gaps1b: hand-drafted from the asm
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// gaps1b (2026-11-02): hand-drafted from the retail asm (0x213A60). UTF-8 -> UTF-16 with checks
// (ConvertUTF-style tables): 0 ok, 1 source truncated, 2 target full (max < 2), 3 above 0xFFFF or a surrogate. A lead byte
// with 4 or 5 trailing bytes is not consumed (retail's switch has no case for them) [C 0x213AF0].
// Name: the asm symbol, which came from a config/symbol_addrs.txt row marked "names are ours" (the earlier research repo, upstream)
// -- not evidence. [L] research/retail_names.csv (high): CGtUnicode::ConvertUTF8toUTF16(const unsigned char*,unsigned short*,int).
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

// 0x00213A60
extern "C" int ConvertUTF8toUTF16__10CGtUnicodeFPCUcPUsi(const unsigned char * src, UnkUChar * dst, int max)
{
    int result = 0;
    const unsigned char * end = src + strlen((const char *)src);
    while (*src != 0) {
        unsigned char c = *src;
        unsigned int extra = _gan8NumTrailingBytesForUTF8[c];
        if (!(src + extra < end)) {
            result = 1;
            break;
        }
        unsigned int ch = 0;
        switch (extra) {
        case 3: ch += *src++; ch <<= 6;
        case 2: ch += *src++; ch <<= 6;
        case 1: ch += *src++; ch <<= 6;
        case 0: ch += *src++;
        default: break;
        }
        ch -= _ganOffsetsFromUTF8[extra];
        if (max < 2) {
            result = 2;
            break;
        }
        if (ch >= 0x10000) {
            result = 3;
            break;
        }
        if (ch >= 0xD800 && ch < 0xE000) {
            result = 3;
            break;
        }
        *dst++ = (UnkUChar)ch;
        max--;
    }
    *dst = 0;
    return result;
}
