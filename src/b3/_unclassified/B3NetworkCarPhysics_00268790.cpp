// CB3NetworkCarPhysics::GetDrivingControls() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3NetworkCarPhysics.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (rewritten from the lifted source: unsigned-int-to-float conversions of the packed control byte, merged && flag test, if(flag&8) set 1 else 0).

// lifter variant 0
// CB3NetworkCarPhysics::GetDrivingControls() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3NetworkCarPhysics.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3NetworkCarPhysics;
struct UnkStruct_00268790_1;
struct UnkStruct_D_00665ECC;

struct UnkStruct_00268790_1 {
    unsigned char pad_0[0x18ED];
    unsigned char field_18ED;
    unsigned char pad_18EE[0x122];
    unsigned char field_1A10;
    signed char field_1A11;
    unsigned char field_1A12;
};

struct UnkStruct_D_00665ECC {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3NetworkCarPhysics {
public:
    void GetDrivingControls();

    unsigned char pad_0[0x13BC];
    float field_13BC;
    unsigned char pad_13C0[0x3C];
    unsigned char field_13FC;
    unsigned char pad_13FD[0x3];
    float field_1400;
    float field_1404;
    float field_1408;
    unsigned char pad_140C[0x8];
    float field_1414;
    unsigned char pad_1418[0xB0];
    int field_14C8;
    unsigned char pad_14CC[0x84];
    UnkStruct_00268790_1 * field_1550;
};

extern UnkStruct_D_00665ECC D_00665ECC;

extern "C" void GetDrivingControls__17CB3RaceCarPhysicsFv(void *);  // CB3RaceCarPhysics::GetDrivingControls()

// 0x00268790
void CB3NetworkCarPhysics::GetDrivingControls()
{
    field_1414 = (float)(unsigned int)(field_1550->field_1A10 & 31) / 31.0f;
    field_1404 = (float)(unsigned int)(unsigned char)((unsigned char)(field_1550->field_1A10 & 224) >> 5) / 7.0f;
    field_1408 = (float)field_1550->field_1A11 / 127.0f;
    field_13FC = 0;
    if (D_00665ECC.field_0 != 0) {
        field_1408 = -field_1408;
    }
    if ((field_1550->field_1A12 & 8) == 8 && field_14C8 > 0) {
        field_13FC |= 4;
    }
    if ((field_1550->field_1A12 & 16) == 16) {
        field_13FC |= 8;
    }
    field_1400 = field_1414 * field_13BC;
    if (!(field_1400 <= 1.0f)) {
        field_1400 = 1.0f;
    }
    if (field_13FC & 8) {
        field_1550->field_18ED = 1;
    } else {
        field_1550->field_18ED = 0;
    }
    GetDrivingControls__17CB3RaceCarPhysicsFv(this);
}
