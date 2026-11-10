// CGtSoundUtils::GenerateVariantPath(const char*,const char*,const char*,char*,CGtSoundUtils::ESoundVariantMode) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtSoundUtils.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (buf[0x100]; sprintf(p3,fmt,p0,buf,p2)).

extern unsigned char ku8FilenameVariantIndexPos;
extern unsigned char ku8FilenameVariantCountPos;
extern char D_004C96D8[];
extern "C" int sprintf(char *, const char *, ...);
class CGtSoundUtils {
public:
    enum ESoundVariantMode { Mode0 };
    static void GenerateVariantFromVariant(const char *, char *, ESoundVariantMode, unsigned char, unsigned char);
    static void GenerateVariantPath(const char *, const char *, const char *, char *, ESoundVariantMode);
};
// 0x00386E70
void CGtSoundUtils::GenerateVariantPath(const char *p0, const char *p1, const char *p2, char *p3, ESoundVariantMode mode)
{
    char buf[0x100];
    GenerateVariantFromVariant(p1, buf, mode, ku8FilenameVariantIndexPos, ku8FilenameVariantCountPos);
    sprintf(p3, D_004C96D8, p0, buf, p2);
}
