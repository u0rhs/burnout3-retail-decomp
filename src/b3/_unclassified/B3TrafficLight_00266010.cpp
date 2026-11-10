// CB3TrafficLight::Update(float) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3TrafficLight.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (void; switch cases 2/0/1 with if/else-if (x>0) arms; static inline getter (if (i==255) return 0; return (T*)(int)&arr[i])).

// lifter variant 0
// CB3TrafficLight::Update(float) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3TrafficLight.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3TrafficLight;
struct UnkStruct_00266010_1;
struct UnkStruct_00266010_2;
struct UnkStruct_00266010_4;
struct UnkStruct_00266010_e1;
struct UnkStruct_D_00522660;

struct UnkStruct_00266010_1 {
    unsigned char pad_0[0x4];
    float field_4;
    float field_8;
    float field_C;
};

struct UnkStruct_00266010_2 {
    unsigned char pad_0[0x15];
    unsigned char field_15;
};

struct UnkStruct_00266010_4 {
    unsigned char pad_0[0x10];
    float field_10;
    unsigned char pad_14[0x32];
    unsigned char field_46;
    unsigned char pad_47[0x9];
};

struct UnkStruct_00266010_e1 {
    unsigned char pad_0[0x50];
};

struct UnkStruct_D_00522660 {
    unsigned char pad_0[0x2F2B0];
    UnkStruct_00266010_4 field_2F2B0[1];  // [G] element count unknown
};

class CB3TrafficLight {
public:
    void Update(float p0);
    void StopCars();

    UnkStruct_00266010_2 * field_0;
    UnkStruct_00266010_1 * field_4;
    float field_8;
    float field_C;
    unsigned char field_10[1];  // [G] element count unknown
    unsigned char pad_11[0x3];
    unsigned char field_14;
};

extern UnkStruct_D_00522660 D_00522660;

// 0x00266010
// [G] an inlined getter (name unknown): index 255 = none; the (int) cast keeps the 0x2F2B0 offset apart from the
// element fields (lui/ori/addu, as retail)
static inline UnkStruct_00266010_4 *func_00266010_inl1(unsigned char i)
{
    if (i == 255) return 0;
    return (UnkStruct_00266010_4 *)(int)&D_00522660.field_2F2B0[i];
}

void CB3TrafficLight::Update(float p0)
{
    float t = p0 - field_8;
    switch (field_14) {
    case 2:
        StopCars();
        if (t < field_C) return;
        if (field_4->field_8 > 0.0f) {
            field_14 = 0;
            field_C = field_4->field_8;
            field_8 = p0;
        } else if (field_4->field_C > 0.0f) {
            field_14 = 1;
            field_C = field_4->field_C;
            field_8 = p0;
        }
        break;
    case 0:
        for (int i = 0; i < field_0->field_15; i++) {
            if (field_10[i] != 255) {
                UnkStruct_00266010_4 *c = func_00266010_inl1(field_10[i]);
                if (c->field_46 == 2) {
                    c->field_46 = 1;
                    c->field_10 = -1.0f;
                }
                field_10[i] = 255;
            }
        }
        if (t < field_C) return;
        if (field_4->field_C > 0.0f) {
            field_14 = 1;
            field_C = field_4->field_C;
            field_8 = p0;
        } else if (field_4->field_4 > 0.0f) {
            field_14 = 0;
            field_C = field_4->field_4;
            field_8 = p0;
        }
        break;
    case 1:
        StopCars();
        if (t < field_C) return;
        if (field_4->field_4 > 0.0f) {
            field_14 = 2;
            field_C = field_4->field_4;
            field_8 = p0;
        } else if (field_4->field_8 > 0.0f) {
            field_14 = 0;
            field_C = field_4->field_8;
            field_8 = p0;
        }
        break;
    }
}
