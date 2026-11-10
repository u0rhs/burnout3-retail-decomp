// CB3Score::Construct() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3Score.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3Burn;
class CB3Score;
class CB3ScoreBonus;

class CB3Burn {
public:
    void Construct();
};

class CB3ScoreBonus {
public:
    void Construct();
};

class CB3Score {
public:
    void Construct();

    unsigned char pad_0[0xCC];
    CB3Burn field_CC;
    unsigned char pad_CD[0x57];
    CB3ScoreBonus field_124;
    unsigned char pad_125[0x153];
    int field_278;
    unsigned char pad_27C[0x14];
    int field_290;
    int field_294;
    unsigned char pad_298[0x48];
    int field_2E0;
    int field_2E4;
};

// 0x0015CAC0
void CB3Score::Construct()
{
    field_290 = 0;
    field_294 = 0;
    field_2E0 = 0;
    field_2E4 = 0;
    field_CC.Construct();
    field_124.Construct();
    field_278 = 0;
}
