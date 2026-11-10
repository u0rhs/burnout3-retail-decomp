// CB3Burn::SetNumExtraBoostBarSegments(int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3Burn.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a79: sibling of AddSegment (statics as class members)).

class CB3Burn {
public:
    void SetNumExtraBoostBarSegments(int);
    unsigned char pad_0[0x30];
    int field_30;
    float field_34;
    int field_38;
    int field_3C;
    float field_40;
    float field_44;
    float field_48;
    static float gmarBoostBarSizes[4];
    static float gmarBurnoutBoostMultipliers[4];
    static float gmarBoostRate[4];
    static float gmrMinimumBoostTime;
};
// 0x0014DFF0
void CB3Burn::SetNumExtraBoostBarSegments(int n)
{
    field_30 = n;
    field_34 = gmarBoostBarSizes[field_30];
    field_40 = gmarBoostRate[field_30];
    field_48 = gmarBurnoutBoostMultipliers[field_30];
    field_44 = field_40 * gmrMinimumBoostTime;
}
