// CB3CrashActionDirector::Construct() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3CrashActionDirector.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (void return; lit4 externs D_004E0E94/D_004E112C -> literals 0.6f/0.0833f written per field).

class CB3CrashActionDirector {
public:
    void Construct();

    unsigned char pad_0[0x8];
    int field_8;
    unsigned char field_C;
    unsigned char pad_D[0x56B];
    unsigned char field_578;
    unsigned char pad_579[0x3];
    float field_57C;
    float field_580;
    float field_584;
    float field_588;
    float field_58C;
    float field_590;
    float field_594;
    int field_598;
};

// 0x001B2A00
void CB3CrashActionDirector::Construct()
{
    field_57C = 0.25f;
    field_580 = 0.6f;
    field_584 = 0.6f;
    field_588 = 0.6f;
    field_58C = 0.6f;
    field_590 = 0.0833f;
    field_594 = 1.0f;
    field_578 = 0;
    field_598 = 0;
    field_C = 0;
    field_8 = 0;
}
