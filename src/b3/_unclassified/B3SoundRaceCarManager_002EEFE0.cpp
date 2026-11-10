// CB3SoundRaceCarManager::RequestRaceCar(EB3RaceCarType) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundRaceCarManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (two element arrays (0x198/0x160 strides, in-use byte at +0xBD); case 0 falls into case 1/2; unsigned for loops; default: break; || for the two global tests).

enum EB3RaceCarType {};

class CB3SoundRaceCarManager;
struct UnkStruct_002EEFE0_e2;
struct UnkStruct_002EEFE0_e3;
struct UnkStruct_D_0051A6A8;
struct UnkStruct_D_0051A9E0;
struct UnkStruct_D_0051BA88;

struct UnkStruct_D_0051BA88 {
    void * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0051A9E0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0051A6A8 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

// [G] two car-sound arrays (strides 0x198 and 0x160), each element with an in-use byte at +0xBD
struct UnkStruct_002EEFE0_e2 {
    unsigned char pad_0[0xBD];
    unsigned char field_BD;
    unsigned char pad_BE[0xDA];
};

struct UnkStruct_002EEFE0_e3 {
    unsigned char pad_0[0xBD];
    unsigned char field_BD;
    unsigned char pad_BE[0xA2];
};

class CB3SoundRaceCarManager {
public:
    void * RequestRaceCar(EB3RaceCarType p0);

    unsigned char pad_0[0x210];
    UnkStruct_002EEFE0_e2 field_210[2];
    UnkStruct_002EEFE0_e3 field_540[5];
};

extern UnkStruct_D_0051BA88 D_0051BA88;
extern UnkStruct_D_0051A9E0 D_0051A9E0;
extern UnkStruct_D_0051A6A8 D_0051A6A8;

// 0x002EEFE0
void * CB3SoundRaceCarManager::RequestRaceCar(EB3RaceCarType p0)
{
    if (D_0051BA88.field_0 == &D_0051A9E0 || D_0051BA88.field_0 == &D_0051A6A8) {
        return 0;
    }
    unsigned int i;
    switch (p0) {
    case 0:
        for (i = 0; i < 2; i++) {
            if (field_210[i].field_BD == 0) {
                field_210[i].field_BD = 1;
                return &field_210[i];
            }
        }
    case 1:
    case 2:
        for (i = 0; i < 5; i++) {
            if (field_540[i].field_BD == 0) {
                field_540[i].field_BD = 1;
                return &field_540[i];
            }
        }
        break;
    case 3:
        break;
    default:
        break;
    }
    return 0;
}
