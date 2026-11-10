// CB3Burn::Update(CB3RaceCar*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3Burn.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (if (field_52 != 0) first; field_50||field_51 merged; field_53 != 0 arm first).

// CB3Burn::Update(CB3RaceCar*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3Burn.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3RaceCar;

class CB3Burn;
struct CB3RaceCar;
struct UnkStruct_D_0052267C;

struct CB3RaceCar {
    unsigned char pad_0[0x10CC];
    float field_10CC;
};

struct UnkStruct_D_0052267C {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3Burn {
public:
    void Update(CB3RaceCar* p0);
    static float gmrMinimumBoostTime;

    unsigned char pad_0[0x24];
    float field_24;
    float field_28;
    unsigned char pad_2C[0x8];
    float field_34;
    float field_38;
    unsigned char pad_3C[0x4];
    float field_40;
    unsigned char pad_44[0xC];
    unsigned char field_50;
    unsigned char field_51;
    unsigned char field_52;
    unsigned char field_53;
    unsigned char pad_54[0x1];
    unsigned char field_55;
    unsigned char field_56;
};

extern UnkStruct_D_0052267C D_0052267C;

extern "C" void Stop__20CB3BoostEffectParamsFv(void *);  // CB3BoostEffectParams::Stop()
extern "C" void func_0030B190(CB3Burn *, CB3RaceCar *);

// 0x0014E3A0
void CB3Burn::Update(CB3RaceCar* p0)
{
    float t0 = p0->field_10CC;
    float t1 = D_0052267C.field_0;
    if (field_52 != 0) {
        if (field_50 != 0 || field_51 != 0) {
            field_38 = field_34;
        } else {
            field_38 -= t1 * field_40;
        }
        if (field_55 != 0) {
            field_56 = 1;
        }
        if (field_53 != 0) {
            if (!(t0 < field_24 + CB3Burn::gmrMinimumBoostTime)) {
                if (field_38 < 0.0f) {
                    field_38 = 0.0f;
                }
                field_52 = 0;
                field_53 = 0;
                field_28 = t0;
                Stop__20CB3BoostEffectParamsFv(this);
            }
        } else {
            if (field_38 <= 0.0f) {
                field_38 = 0.0f;
                field_52 = 0;
                field_53 = 0;
                field_28 = t0;
                Stop__20CB3BoostEffectParamsFv(this);
            }
        }
    } else {
        if (field_50 != 0 || field_51 != 0) {
            field_38 = field_34;
        }
    }
    func_0030B190(this, p0);
}
