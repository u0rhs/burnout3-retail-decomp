// CB3Score::Release() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3Score.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3ScoreBonus {
public:
    void Release();
};

class CB3Burn {
public:
    void Release();
};

class CB3Score {
public:
    void Release();

    unsigned char pad_0[0xCC];
    CB3Burn field_CC;
    unsigned char pad_CD[0x57];
    CB3ScoreBonus field_124;
    unsigned char pad_125[0x16B];
    int field_290;
    int field_294;
    unsigned char pad_298[0x48];
    int field_2E0;
    int field_2E4;
};

// 0x0015AFC0
void CB3Score::Release()
{
    field_124.Release();
    field_CC.Release();
    field_290 = 0;
    field_294 = 0;
    field_2E0 = 0;
    field_2E4 = 0;
}
