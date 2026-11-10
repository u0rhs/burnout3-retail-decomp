// CB3Score::SetNumLives(int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3Score.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3Score;
struct UnkStruct_D_0064D384;

struct UnkStruct_D_0064D384 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3Score {
public:
    void SetNumLives(int p0);

    unsigned char pad_0[0x5F8];
    int field_5F8;
};

extern UnkStruct_D_0064D384 D_0064D384;

// 0x001561C0
void CB3Score::SetNumLives(int p0)
{
    int t0 = field_5F8;
    field_5F8 = p0;
    if ((t0 == 0) == (field_5F8 == 0)) return;
    if ((t0 == 0) != false) {
        D_0064D384.field_0 = (D_0064D384.field_0 + 1);
    } else {
        D_0064D384.field_0 = (D_0064D384.field_0 + -1);
    }
}
