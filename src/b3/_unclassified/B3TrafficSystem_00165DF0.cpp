// CB3TrafficSystem::VerifyAndLoadVehicleIDs() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3TrafficSystem.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (5 explicit blocks idx=v++ search loops; D_004EE040 struct arrays at 0x2AA68/0x2B068).

struct UnkStruct_00165DF0_ent {
    unsigned long field_0;
    unsigned char pad_8[0x10];
};

struct UnkStruct_00165DF0_dat {
    unsigned long field_0[5];
    unsigned char pad_28[0x2C];
    UnkStruct_00165DF0_ent * field_54;
    unsigned char pad_58[0x5D];
    unsigned char field_B5;
    unsigned char field_B6;
};

struct UnkStruct_D_004EE040 {
    unsigned char pad_0[0x2AA68];
    unsigned long field_2AA68[0x80];
    unsigned char pad_2AE68[0x200];
    int field_2B068[0x80];
};

class CB3TrafficSystem {
public:
    void VerifyAndLoadVehicleIDs();

    UnkStruct_00165DF0_dat * field_0;
    unsigned char pad_4[0x34420 - 4];
    int field_34420[8];
    unsigned char pad_34440[0x10];
    signed char field_34450;
};

extern unsigned long D_00518AA8[0x80];
extern int D_005190A8[0x80];
extern UnkStruct_D_004EE040 D_004EE040;

// 0x00165DF0
void CB3TrafficSystem::VerifyAndLoadVehicleIDs()
{
    int v;
    for (v = 0; v < field_34450 - field_0->field_B6; v++) {
        unsigned long id = field_0->field_54[v].field_0;
        for (int i = 0; i < 0x80; i++) {
            if (id == D_00518AA8[i]) {
                field_34420[v] = D_004EE040.field_2B068[i];
                break;
            }
        }
    }
    if (field_0->field_B6 <= 0) {
        return;
    }
    if ((field_0->field_B5 & 1) != 0) {
        unsigned long id = field_0->field_0[0];
        int idx = v;
        v++;
        for (int i = 0; i < 0x80; i++) {
            if (id == D_004EE040.field_2AA68[i]) {
                field_34420[idx] = D_005190A8[i];
                break;
            }
        }
    }
    if ((field_0->field_B5 & 2) != 0) {
        unsigned long id = field_0->field_0[1];
        int idx = v;
        v++;
        for (int i = 0; i < 0x80; i++) {
            if (id == D_004EE040.field_2AA68[i]) {
                field_34420[idx] = D_005190A8[i];
                break;
            }
        }
    }
    if ((field_0->field_B5 & 4) != 0) {
        unsigned long id = field_0->field_0[2];
        int idx = v;
        v++;
        for (int i = 0; i < 0x80; i++) {
            if (id == D_004EE040.field_2AA68[i]) {
                field_34420[idx] = D_005190A8[i];
                break;
            }
        }
    }
    if ((field_0->field_B5 & 8) != 0) {
        unsigned long id = field_0->field_0[3];
        int idx = v;
        v++;
        for (int i = 0; i < 0x80; i++) {
            if (id == D_004EE040.field_2AA68[i]) {
                field_34420[idx] = D_005190A8[i];
                break;
            }
        }
    }
    if ((field_0->field_B5 & 0x10) != 0) {
        unsigned long id = field_0->field_0[4];
        int idx = v;
        v++;
        for (int i = 0; i < 0x80; i++) {
            if (id == D_004EE040.field_2AA68[i]) {
                field_34420[idx] = D_005190A8[i];
                break;
            }
        }
    }
}
