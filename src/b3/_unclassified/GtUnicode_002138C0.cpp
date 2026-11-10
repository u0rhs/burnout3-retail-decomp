// CGtUnicode::AppendN(unsigned short*,int,const unsigned short*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtUnicode.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (gaps1b: hand-written from the asm, exact).

// gaps1b (2026-11-02): hand-drafted from the retail asm (0x2138C0). Appends src within n units (terminator
// included); returns the terminator's address (dst + n - 1 when truncated).
// Name: the asm symbol, which came from a config/symbol_addrs.txt row marked "names are ours" (the earlier research repo, upstream)
// -- not evidence. [L] research/retail_names.csv (high): CGtUnicode::AppendN(unsigned short*,int,const unsigned short*).

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

// 0x002138C0
extern "C" UnkUChar * AppendN__10CGtUnicodeFPUsiPCUs(UnkUChar * dst, int n, const UnkUChar * src)
{
    UnkUChar * end = dst + (n - 1);
    while (*dst != 0) {
        dst++;
    }
    *dst = *src;
    while (dst < end) {
        if (*src == 0) {
            return dst;
        }
        src++;
        dst++;
        *dst = *src;
    }
    *end = 0;
    return end;
}
