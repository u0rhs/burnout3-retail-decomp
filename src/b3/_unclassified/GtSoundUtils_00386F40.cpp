// CGtSoundUtils::AsciiVariantToInt(char,unsigned char&) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtSoundUtils.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (range tests).

class CGtSoundUtils {
public:
    enum ESoundVariantMode { Mode0 };
    static int AsciiVariantToInt(char p0, unsigned char& p1);
};
// 0x00386F40
int CGtSoundUtils::AsciiVariantToInt(char c, unsigned char& out)
{
    if (c >= 65 && c < 91) {
        out = c - 55;
        return 1;
    }
    if (c >= 97 && c < 123) {
        out = c - 87;
        return 1;
    }
    if (c >= 48 && c < 58) {
        out = c - 48;
        return 1;
    }
    return 0;
}
