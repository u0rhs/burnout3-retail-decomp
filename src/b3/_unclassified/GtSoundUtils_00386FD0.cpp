// CGtSoundUtils::GenerateVariantFromVariant(const char*,char*,CGtSoundUtils::ESoundVariantMode,unsigned char,unsigned char) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtSoundUtils.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a130: inlined AsciiVariantToInt (bool, defined in class) x2 + int->ascii; switch 0,1,2,default; max++).

extern "C" char * strcpy(char *, const char *);
struct UnkStruct_00386FD0_rnd { int field_0; int field_4; };
extern "C" UnkStruct_00386FD0_rnd _mRandom__13CGtSoundUtils;
class CGtSoundUtils {
public:
    enum ESoundVariantMode { Mode0, Mode1, Mode2 };
    static inline bool AsciiVariantToInt(char c, unsigned char & out)
    {
        if (c >= 65 && c < 91) {
            out = c - 55;
            return true;
        }
        if (c >= 97 && c < 123) {
            out = c - 87;
            return true;
        }
        if (c >= 48 && c < 58) {
            out = c - 48;
            return true;
        }
        return false;
    }
    static void GenerateVariantFromVariant(const char *, char *, ESoundVariantMode, unsigned char, unsigned char);
};
// 0x00386FD0
void CGtSoundUtils::GenerateVariantFromVariant(const char *src, char *dst, ESoundVariantMode mode, unsigned char idx, unsigned char count)
{
    unsigned char cur;
    unsigned char max;
    if (AsciiVariantToInt(src[idx], cur) && AsciiVariantToInt(src[count], max)) {
        if (max == 0) {
            max++;
        }
        if (cur > max) {
            mode = Mode0;
        }
        switch (mode) {
        case Mode0:
            break;
        case Mode1:
            cur = (cur + 1) % max;
            break;
        case Mode2: {
            int x = _mRandom__13CGtSoundUtils.field_0;
            x = (x << 16) + (x >> 16);
            x += _mRandom__13CGtSoundUtils.field_4;
            _mRandom__13CGtSoundUtils.field_4 += x;
            _mRandom__13CGtSoundUtils.field_0 = x;
            cur = (unsigned)x % max;
            break;
        }
        default:
            break;
        }
    }
    strcpy(dst, src);
    {
        char ch;
        bool ok;
        if (cur >= 10 && cur < 36) {
            ch = cur + 55;
            ok = true;
        } else if (cur < 11) {
            ch = cur + 48;
            ok = true;
        } else {
            ok = false;
        }
        if (ok) {
            dst[idx] = ch;
        }
    }
}
