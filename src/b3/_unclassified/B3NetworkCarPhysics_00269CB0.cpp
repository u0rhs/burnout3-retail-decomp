// CB3NetworkCarPhysics::Prepare(CB3RaceCar*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3NetworkCarPhysics.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3RaceCar;

class CB3NetworkCarPhysics;

class CB3NetworkCarPhysics {
public:
    int Prepare(CB3RaceCar* p0);

    unsigned char pad_0[0x217];
    unsigned char field_217;
    unsigned char pad_218[0x11E4];
    unsigned char field_13FC;
    unsigned char pad_13FD[0x153];
    CB3RaceCar * field_1550;
    unsigned char field_1554;
};

extern "C" int Prepare__17CB3RaceCarPhysicsFP10CB3RaceCar(void *, void *);  // CB3RaceCarPhysics::Prepare(CB3RaceCar*)

// 0x00269CB0
int CB3NetworkCarPhysics::Prepare(CB3RaceCar* p0)
{
    field_1550 = (CB3RaceCar *)p0;
    Prepare__17CB3RaceCarPhysicsFP10CB3RaceCar(this, (CB3RaceCar*)field_1550);
    field_217 = 0;
    field_13FC = 0;
    field_1554 = 0;
    return 1;
}
