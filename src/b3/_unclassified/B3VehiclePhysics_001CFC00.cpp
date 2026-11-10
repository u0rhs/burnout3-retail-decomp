// CB3VehiclePhysics::Prepare() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3VehiclePhysics.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (bool Prepare: if(r){memset chain} return r).

extern "C" void * memset(void *, int, unsigned int);
extern "C" bool func_001AD380(void *);

class CB3VehiclePhysics {
public:
    bool Prepare();
    unsigned char pad_0[0x208];
    void * field_208;
    unsigned char field_20C;
    unsigned char pad_20D[0x13];
    unsigned char field_220[0x600];
    unsigned char field_820[0x480];
    unsigned char field_CA0[0x20];
    int field_CC0;
    int field_CC4;
    unsigned char field_CC8[0x18];
    unsigned char field_CE0[0x480];
    short field_1160;
    unsigned char pad_1162[2];
    int field_1164;
    unsigned char field_1168;
    unsigned char field_1169;
    unsigned char field_116A;
    unsigned char field_116B;
    float field_116C;
    unsigned char field_1170[0x40];
    unsigned char field_11B0[0x20];
    unsigned char field_11D0[0x180];
    unsigned char field_1350;
    unsigned char field_1351;
    unsigned char pad_1352[1];
    unsigned char field_1353;
    unsigned char field_1354;
};

// 0x001CFC00
bool CB3VehiclePhysics::Prepare()
{
    bool r = func_001AD380(this);
    if (r) {
    memset(field_220, 0, 0x600);
    memset(field_820, 0, 0x480);
    memset(field_CA0, 0, 0x20);
    field_CC0 = 0;
    field_CC4 = 0;
    memset(field_CC8, 0, 0x18);
    memset(field_CE0, 0, 0x480);
    field_1160 = 0;
    field_1164 = 0;
    field_1168 = 0;
    field_1169 = 0;
    field_116A = 0;
    field_116B = 0;
    field_116C = 9999.0f;
    memset(field_1170, 0, 0x40);
    memset(field_11B0, 0, 0x20);
    memset(field_11D0, 0, 0x180);
    field_1350 = 0;
    field_1351 = 0;
    field_20C = 2;
    field_208 = field_220;
    field_1353 = 0;
    field_1354 = 0;
    }
    return r;
}
