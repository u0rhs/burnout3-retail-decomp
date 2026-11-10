// CB3Burn::AddSegment() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3Burn.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a76: plain if (field_30 < 3) block).

// [C] name CB3Burn::AddSegment() (mangled symbol); statics gmarBoostBarSizes/gmarBoostRate/gmarBurnoutBoostMultipliers/gmrMinimumBoostTime (E maps); field layout as in B3Burn_0014E500 [G]. No DNAT row.
class CB3Burn;
class CB3Burn {
public:
    void AddSegment();

    unsigned char pad_0[0x24];
    float field_24;
    float field_28;
    int field_2C;
    int field_30;
    float field_34;
    int field_38;
    int field_3C;
    float field_40;
    float field_44;
    float field_48;
    int field_4C;
    unsigned char field_50;
    unsigned char field_51;
    unsigned char field_52;
    unsigned char field_53;
    unsigned char field_54;
    unsigned char field_55;
    unsigned char field_56;

    static float gmarBoostBarSizes[4];
    static float gmarBurnoutBoostMultipliers[4];
    static float gmarBoostRate[4];
    static float gmrMinimumBoostTime;
};


// 0x0014E1C0
void CB3Burn::AddSegment()
{
    if (field_30 < 3) {
        field_30 = field_30 + 1;
        field_34 = gmarBoostBarSizes[field_30];
        field_40 = gmarBoostRate[field_30];
        field_48 = gmarBurnoutBoostMultipliers[field_30];
        field_44 = field_40 * gmrMinimumBoostTime;
    }
}
