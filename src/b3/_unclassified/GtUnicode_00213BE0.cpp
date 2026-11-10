// CGtUnicode::ConvertUTF8toUTF16Fast(const unsigned char*,unsigned short*,int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtUnicode.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (dperm (decomp-permuter, background run): while (((*src) != 0) && (!(max < 2))); while (((*src) != 0) && (!(max <= (2 - 1))))).

typedef unsigned short UnkUChar;          
extern UnkUChar thousandsSep;             
extern UnkUChar decimalPoint;
extern UnkUChar plusSign;
extern UnkUChar minusSign;
extern float powersOf10[];                
extern unsigned char _gan8NumTrailingBytesForUTF8[];
extern unsigned int _ganOffsetsFromUTF8[];
extern unsigned char _ganFirstByteMark[];
extern "C" unsigned int strlen(const char *);
extern "C" int _CopyUntilNextParameter__FPPUsPPCUs(UnkUChar **, const UnkUChar **);



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


static inline UnkUChar * func_00213100_inl1(UnkUChar * d, float f, int decimals, int plus, int nosep)
{
    UnkUChar sep0 = thousandsSep;          
    UnkUChar dp = decimalPoint;
    if (f < 0.0f) {
        *d++ = minusSign;
        f = -f;
    } else if (plus == 1) {
        *d++ = plusSign;
    }
    int ip = (int)f;                       
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
extern "C" void ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi ( const unsigned char * src , UnkUChar * dst , int max );




// 0x00213BE0
void ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(const unsigned char *src, UnkUChar *dst, int max)
{
  while (((*src) != 0) && (!(max <= (2 - 1))))
  {
    unsigned char c = *src;
    unsigned char extra = _gan8NumTrailingBytesForUTF8[c];
    unsigned int ch = 0;
    switch (extra)
    {
      case 3:
        ch += *(src++);
        ch <<= 6;

      case 2:
        ch += *(src++);
        ch <<= 6;

      case 1:
        ch += *(src++);
        ch <<= 6;

      case 0:
        ch += *(src++);

      default:
        break;

    }

    max--;
    *(dst++) = (UnkUChar) (ch - _ganOffsetsFromUTF8[extra]);
  }

  *dst = 0;
}
