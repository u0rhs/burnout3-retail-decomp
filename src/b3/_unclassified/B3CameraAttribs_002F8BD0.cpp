// CB3CameraAttribsCar::Prepare(unsigned long) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3CameraAttribs.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (two CB3CameraAttribsCar slots as an array; pick a free slot into one pointer, then store key, RegisterVariables() (no phantom argument), return it).

class CB3CameraAttribsCar;
class CB3PlayerCameraManager;
struct UnkStruct_002F8BD0_1;

class CB3CameraAttribsCar {
public:
    static CB3CameraAttribsCar * Prepare(unsigned long p0);
    void RegisterVariables();

    unsigned char pad_0[0xA0];
    unsigned long field_A0;
    unsigned char pad_A8[0x108];
};

struct UnkStruct_002F8BD0_1 {
    unsigned char pad_0[0x28D0];
    CB3CameraAttribsCar field_28D0[2];  // [G] two attribute sets 0x1B0 apart (0x28D0, 0x2A80), each with its key at +0xA0
};

class CB3PlayerCameraManager {
public:
    static UnkStruct_002F8BD0_1 * mgpCameraBuffer;
};

// 0x002F8BD0
CB3CameraAttribsCar * CB3CameraAttribsCar::Prepare(unsigned long p0)
{
    UnkStruct_002F8BD0_1 * t0 = CB3PlayerCameraManager::mgpCameraBuffer;
    CB3CameraAttribsCar * a = &t0->field_28D0[0];
    CB3CameraAttribsCar * b = &t0->field_28D0[1];
    if (a->field_A0 == p0) {
        return a;
    }
    if (b->field_A0 == p0) {
        return b;
    }
    CB3CameraAttribsCar * c;
    if (a->field_A0 == 0) {
        c = a;
    } else if (b->field_A0 == 0) {
        c = b;
    } else {
        return 0;
    }
    c->field_A0 = p0;
    c->RegisterVariables();
    return c;
}
