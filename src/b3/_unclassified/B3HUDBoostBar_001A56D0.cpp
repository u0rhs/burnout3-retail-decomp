// CB3HUDBoostBar::CBoostBarObjectData::Prepare() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3HUDBoostBar.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a79: nested class, two stride-0x20 float arrays set to -9999.0f in one loop, then zero fields).

struct UnkStruct_001A56D0_e {
    unsigned char pad_0[0x10];
    float field_10;
    unsigned char pad_14[0xC];
};
class CB3HUDBoostBar {
public:
    class CBoostBarObjectData {
    public:
        void Prepare();
        UnkStruct_001A56D0_e field_0[20];
        UnkStruct_001A56D0_e field_280[20];
        int field_500;
        int field_504;
        int field_508;
        int field_50C;
        int field_510;
        int field_514;
        unsigned char field_518;
        unsigned char field_519;
        unsigned char field_51A;
        unsigned char field_51B;
        int field_51C;
        int field_520;
        int field_524;
        int field_528;
        int field_52C;
    };
};
// 0x001A56D0
void CB3HUDBoostBar::CBoostBarObjectData::Prepare()
{
    for (int i = 0; i < 20; i++) {
        field_0[i].field_10 = -9999.0f;
        field_280[i].field_10 = -9999.0f;
    }
    field_500 = 0;
    field_504 = 0;
    field_508 = 0;
    field_50C = 0;
    field_510 = 0;
    field_514 = 0;
    field_518 = 0;
    field_519 = 0;
    field_51A = 0;
    field_51B = 0;
    field_51C = 0;
    field_520 = 0;
    field_524 = 0;
    field_528 = 0;
    field_52C = 0;
}
