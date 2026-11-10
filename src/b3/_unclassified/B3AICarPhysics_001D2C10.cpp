// CB3AICarPhysics::Prepare(CB3RaceCar*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3AICarPhysics.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// CB3AICarPhysics has a header in include/ (pads and a few proven fields only): declared locally instead, as the
// hand-matched units of such classes do (B3AITarget_00149140.cpp) [lift3].
// Hand-finished from the lifted source (bool return (return true): the stored 1 is v0).

// near5: returns bool (`return true;`, [L] like the proven CB3VehiclePhysics::Prepare / CB3RaceCarPhysicsAttribs::Prepare): the 1 stored to +0x1550/+0x1551 is the return value held in v0 (v275 rule).

// CB3AICarPhysics::Prepare(CB3RaceCar*) -- hand-written (a69); standalone declarations (the class header would clash).
// [L] DNAT: not in new_names.csv. Layout [G] from instruction widths.

class CB3RaceCar {
public:
    unsigned char pad_0[0x19AC];
    signed char field_19AC;
};

class CB3AICarPhysics {
public:
    bool Prepare(CB3RaceCar *p0);

    unsigned char pad_0[0x1550];
    unsigned char field_1550;
    unsigned char field_1551;
    unsigned char field_1552;
    unsigned char field_1553;
    unsigned char field_1554;
    unsigned char pad_1555[3];
    int field_1558;
    int field_155C;
    float field_1560;
    float field_1564;
    CB3RaceCar *field_1568;
    int field_156C;
    float field_1570;
    float field_1574;
    float field_1578;
    float field_157C;
};

struct UnkStruct_grSpikeGen_el { int field_0; int field_4; unsigned char pad_8[0x10]; unsigned char field_18; unsigned char pad_19[3]; };
struct UnkStruct_Random { unsigned int field_0; unsigned int field_4; };
extern UnkStruct_Random _gRandom;
extern UnkStruct_grSpikeGen_el _grSpikeGen[];
extern int D_0066DE50[];
extern int D_0066DE70[];
extern int D_0066DE90[];
extern "C" int Prepare__17CB3RaceCarPhysicsFP10CB3RaceCar(void *, CB3RaceCar *);

// 0x001D2C10
bool CB3AICarPhysics::Prepare(CB3RaceCar *p0)
{
    Prepare__17CB3RaceCarPhysicsFP10CB3RaceCar(this, p0);
    field_1568 = p0;
    field_1552 = 0;
    field_1553 = 0;
    field_1550 = 1;
    field_1551 = 1;
    field_1558 = 0;
    field_155C = 0;
    field_1554 = 0;
    field_1560 = 3.402823466e+38f;
    field_1564 = 3.402823466e+38f;
    field_156C = 0;
    field_1570 = -1.0f;
    field_1574 = -1.0f;
    field_157C = -1.0f;
    field_1578 = -1.0f;
    _gRandom.field_4 = 0xDEADF00D;
    _gRandom.field_0 = 0x21520FF2;
    UnkStruct_grSpikeGen_el *e = &_grSpikeGen[p0->field_19AC];
    e->field_4 = 0;
    e->field_18 = 0;
    D_0066DE50[p0->field_19AC] = 0;
    D_0066DE70[p0->field_19AC] = 0;
    D_0066DE90[p0->field_19AC] = 0;
    return true;
}
