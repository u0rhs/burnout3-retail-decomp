// CB3Burn::Prepare(EB3BoostBarSize) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3Burn.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (statics as class members (float[4] tables, gmrMinimumBoostTime); size arg unused; effect-params Prepare(this,this); field_30=2 if func_00131E40(&D_004EE040)).

// CB3Burn::Prepare(EB3BoostBarSize) -- hand-written (a69; the lifter refused 'static member used as a struct'). [C] name/statics: the
// E maps (CB3Burn::gmarBoostBarSizes 0x488050, gmarBurnoutBoostMultipliers 0x488060, gmarBoostRate 0x488070 (0x10 bytes each),
// gmrMinimumBoostTime 0x4E1444). The size argument is not read (field_30 is cleared and indexes the tables); layouts [G].
enum EB3BoostBarSize {};
struct UnkStruct_D_004EE040 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};
extern UnkStruct_D_004EE040 D_004EE040;
extern "C" int func_00131E40(void *);
class CB3Burn;
extern "C" void Prepare__20CB3BoostEffectParamsFP7CB3Burn(void *, CB3Burn *);  // CB3BoostEffectParams::Prepare(CB3Burn*) (this = &burn)

class CB3Burn {
public:
    bool Prepare(EB3BoostBarSize size);

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

// 0x0014E500
bool CB3Burn::Prepare(EB3BoostBarSize size)
{
    field_2C = 0;
    field_30 = 0;
    field_34 = gmarBoostBarSizes[field_30];
    field_40 = gmarBoostRate[field_30];
    field_48 = gmarBurnoutBoostMultipliers[field_30];
    field_4C = 0;
    field_44 = field_40 * gmrMinimumBoostTime;
    field_38 = 0;
    field_3C = 0;
    field_52 = 0;
    field_53 = 0;
    field_50 = 0;
    field_51 = 0;
    field_54 = 0;
    field_55 = 0;
    field_56 = 0;
    field_24 = -1.0f;
    field_28 = -1.0f;
    Prepare__20CB3BoostEffectParamsFP7CB3Burn(this, this);
    if (func_00131E40(&D_004EE040)) {
        field_30 = 2;
    }
    return true;
}
