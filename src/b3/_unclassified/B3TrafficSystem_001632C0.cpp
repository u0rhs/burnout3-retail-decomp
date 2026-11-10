// CB3TrafficSystem::ResetMemberVariables() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3TrafficSystem.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (straight struct-offset reset; loops mapped to arrays (free lists at 0x127D0 stride 0x180, params 0x2A4D0 stride 0x50)).

struct UnkStruct_001632C0_e {
    unsigned char pad_0[0x108];
    UnkStruct_001632C0_e * field_108;
    unsigned char pad_10C[0x74];
};

struct UnkStruct_001632C0_p {
    unsigned char pad_0[0x44];
    unsigned char field_44;
    unsigned char pad_45[0xB];
};

extern unsigned char gauTrafficSegmentLock8[];
extern unsigned char D_0051D7C0[];

class CB3TrafficSystem {
public:
    void ResetMemberVariables();

    unsigned char pad_0[0x127D0];
    UnkStruct_001632C0_e field_127D0[1];
    unsigned char pad_12950[0x17B80];
    UnkStruct_001632C0_p field_2A4D0[1];
    unsigned char pad_2A520[0x34454 - 0x2A520];
    int field_34454[6][254];
    unsigned char field_35C24[6][254];
    unsigned char field_36218[6][25];
    unsigned char field_362AE[6][8];
    unsigned char pad_362DE[2];
    int field_362E0[8];
    int field_36300[8];
    int field_36320[8];
    int field_36340;
    unsigned char pad_36344[4];
    int field_36348;
    int field_3634C;
    unsigned char field_36350[6];
    unsigned char field_36356[6];
    unsigned char field_3635C[6];
    unsigned char pad_36362[2];
    UnkStruct_001632C0_e * field_36364;
    UnkStruct_001632C0_e * field_36368;
    UnkStruct_001632C0_p * field_3636C;
    int field_36370;
    int field_36374;
    unsigned char field_36378[0x20];
    unsigned char field_36398;
    unsigned char field_36399;
    unsigned char pad_3639A[2];
    unsigned char * field_3639C;
    int field_363A0;
    short field_363A4;
    unsigned char field_363A6;
    unsigned char field_363A7[2];
    unsigned char field_363A9[2];
    unsigned char field_363AB;
    unsigned char field_363AC;
    unsigned char field_363AD;
    unsigned char field_363AE;
    unsigned char field_363AF;
    unsigned char field_363B0;
    unsigned char field_363B1;
    unsigned char pad_363B2[0xA];
    unsigned char field_363BC;
};

// 0x001632C0
void CB3TrafficSystem::ResetMemberVariables()
{
    field_3634C = 0x2B9D6F8;
    field_36348 = 0xFD462907;
    field_363A0 = 0;
    field_363A4 = 0;
    field_363A6 = 0;
    for (int i = 0; i < 2; i++) {
        field_363A9[i] = 0;
        field_363A7[i] = 0;
    }
    field_363AB = 0;
    field_363AC = 0;
    field_363AD = 0;
    field_363AE = 0;
    field_363AF = 0;
    field_363B0 = 0;
    field_363B1 = 0;
    field_363BC = 1;
    field_36364 = &field_127D0[0];
    for (int i = 0; i < 0xFE; i++) {
        if (i < 0xFD) {
            field_127D0[i].field_108 = &field_127D0[i + 1];
        } else {
            field_127D0[i].field_108 = 0;
            field_36368 = &field_127D0[i];
        }
    }
    field_36370 = 0;
    field_36374 = 0;
    for (int i = 0; i < 0x20; i++) {
        field_36378[i] = 0;
    }
    field_36398 = 0;
    field_36399 = 0;
    field_3636C = &field_2A4D0[0];
    for (int i = 0; i < 0xFE; i++) {
        if (i < 0xFD) {
            field_2A4D0[i].field_44 = i + 1;
        }
    }
    for (int i = 0; i < 8; i++) {
        field_362E0[i] = 0;
    }
    for (int i = 0; i < 8; i++) {
        field_36300[i] = 0;
    }
    for (int i = 0; i < 8; i++) {
        field_36320[i] = 0;
    }
    for (int j = 0; j < 6; j++) {
        field_36350[j] = 0;
        field_36356[j] = 0;
        field_3635C[j] = 0;
        for (int i = 0; i < 0xFE; i++) {
            field_34454[j][i] = 0;
            field_35C24[j][i] = 0;
        }
        for (int i = 0; i < 0x19; i++) {
            field_36218[j][i] = 0;
        }
        for (int i = 0; i < 8; i++) {
            field_362AE[j][i] = 0;
        }
    }
    field_3639C = D_0051D7C0;
    field_36340 = 0;
    for (unsigned short i = 0; i < 0x3E80; i++) {
        field_3639C[i] = 0xFF;
    }
    for (unsigned short i = 0; i < 0xFA0; i++) {
        gauTrafficSegmentLock8[i] = 0;
    }
}
