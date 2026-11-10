// CB3SparkArray::CSparkBank::Prepare() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SparkRendererPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a76: inner j declared before e inside the outer loop).

// [C] name CB3SparkArray::CSparkBank::Prepare() (mangled symbol); 4 slots {data*, count, ...} of 0x90-stride elements reset to -9999.0f (int->float at runtime); layout [G]. No DNAT row.
struct UnkStruct_002640E0_e {
    float field_0;
    float field_4;
    float field_8;
    float field_C;
    unsigned char pad_10[0x80];
};

struct UnkStruct_002640E0_s {
    UnkStruct_002640E0_e * field_0;
    int field_4;
    int field_8;
    int field_C;
};

class CB3SparkArray {
public:
    class CSparkBank {
    public:
        void Prepare();
        UnkStruct_002640E0_s field_0[4];
        int field_40;
        float field_44;
        unsigned char pad_48[4];
    };
};

// 0x002640E0
void CB3SparkArray::CSparkBank::Prepare()
{
    float k = -9999;
    for (int i = 0; i < 4; i++) {
        int j = 0;
        UnkStruct_002640E0_e * e = field_0[i].field_0;
        for (; j < field_0[i].field_4 / 4; j++) {
            e->field_0 = k;
            e->field_4 = k;
            e->field_8 = k;
            e->field_C = k;
            e++;
        }
        field_0[i].field_8 = 0;
    }
    field_40 = 0;
    field_44 = k;
}
