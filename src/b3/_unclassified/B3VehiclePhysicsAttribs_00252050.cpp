// CB3VehiclePhysicsAttribs::CopyToPhysics(CB3VehiclePhysics*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3VehiclePhysicsAttribs.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (hand-written: 9 field copies then per-wheel loop with i<2 split, 0xC0 stride).

class CB3VehiclePhysics;
class CB3VehiclePhysicsAttribs {
public:
    void CopyToPhysics(CB3VehiclePhysics *);
    unsigned char pad_0[0x88];
    float field_88;
    float field_8C;
    float field_90;
    float field_94;
    float field_98;
    float field_9C;
    float field_A0;
    float field_A4;
    float field_A8;
};
class CB3VehiclePhysics {
public:
    unsigned char pad_0[0x1F0];
    float field_1F0;
    unsigned char pad_1F4[0x894 - 0x1F4];
    struct { float field_0; unsigned char pad_4[0xBC]; } field_894[1];
    unsigned char pad_954[0xCA0 - 0x954];
    float field_CA0;
    float field_CA4;
    float field_CA8;
    float field_CAC;
    float field_CB0;
    float field_CB4;
    float field_CB8;
    float field_CBC;
    unsigned char pad_CC0[0x1169 - 0xCC0];
    signed char field_1169;
};

// 0x00252050
void CB3VehiclePhysicsAttribs::CopyToPhysics(CB3VehiclePhysics * p0)
{
    p0->field_1F0 = field_88;
    p0->field_CAC = field_98;
    p0->field_CA8 = field_90;
    p0->field_CA4 = field_94;
    p0->field_CA0 = field_8C;
    p0->field_CBC = field_A4;
    p0->field_CB8 = field_9C;
    p0->field_CB4 = field_A0;
    p0->field_CB0 = field_A8;
    for (int i = 0; i < p0->field_1169; i++) {
        if (i < 2) {
            p0->field_894[i].field_0 = p0->field_CA0;
        } else {
            p0->field_894[i].field_0 = p0->field_CB0;
        }
    }
}
