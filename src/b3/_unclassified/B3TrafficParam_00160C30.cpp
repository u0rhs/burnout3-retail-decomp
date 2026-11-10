// BUILD-HOST: wine
// N165 [C]: temporary exception -- this source matches retail only under wine; under the reference host
// (native Windows / wibo) two registers swap. To do: re-shape the source to match natively, then drop the marker.
// CB3TrafficParam::GetParamInfoFromValve(CB3TrafficLane*,bool,bool) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3TrafficParam.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (rewritten: CB3TrafficValve members, valve declared before loop, lane byte as reference, Formation arg via (int)i+(int)p0 column cast [G], RNG with r += b, && guard + break).

// lifter variant 0
// CB3TrafficParam::GetParamInfoFromValve(CB3TrafficLane*,bool,bool) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3TrafficParam.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

enum ETrafficVehicleCategories {};

class CB3TrafficParam;
struct CB3TrafficLane;
struct UnkStruct_00160C30_6;
struct UnkStruct_00160C30_e2;
struct UnkStruct_00160C30_e4;
struct UnkStruct_D_00522660;
struct UnkStruct_D_0055D788;
struct UnkStruct_D_0055D78C;
struct UnkStruct_D_0055D7F7;
struct UnkStruct_D_0055D7F8;

struct CB3TrafficLane {
    unsigned char pad_0[0x6];
    unsigned char field_6[1];  // [G] element count unknown
    unsigned char pad_7[0x17];
    unsigned char field_1E[1];  // [G] element count unknown
    unsigned char pad_1F[0x29];
    unsigned char field_48;
};

struct UnkStruct_00160C30_col {
    unsigned char pad_0[0x1E];
    unsigned char field_1E;
};

struct UnkStruct_00160C30_6 {
    unsigned char pad_0[0x4];
    int * field_4;
};

class CB3TrafficValve {
public:
    int GetLaneChanges(bool*, ETrafficVehicleCategories, int, float*);
    int GetFormationAfterLaneChange(bool, unsigned char, int, unsigned char*);
    float GetSpeedAfterLaneChange(bool, int, int);

    unsigned char pad_0[0x40];
    UnkStruct_00160C30_6 * field_40;
};

struct UnkStruct_00160C30_e4 {
    unsigned char pad_0[0x118];
};

struct UnkStruct_D_00522660 {
    UnkStruct_00160C30_e4 field_0[1];  // [G] element count unknown
};

struct UnkStruct_D_0055D7F7 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0055D7F8 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0055D788 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0055D78C {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3TrafficParam {
public:
    void GetParamInfoFromValve(CB3TrafficLane* p0, bool p1, bool p2);

    float field_0;
    unsigned char pad_4[0x20];
    float field_24;
    unsigned char pad_28[0x8];
    float field_30;
    unsigned char pad_34[0x4];
    int field_38;
    unsigned char pad_3C[0xB];
    unsigned char field_47;
    unsigned char field_48;
    unsigned char pad_49[0x2];
    unsigned char field_4B;
    bool field_4C;
    unsigned char field_4D;
};

extern UnkStruct_D_00522660 D_00522660;
extern UnkStruct_D_0055D7F7 D_0055D7F7;
extern UnkStruct_D_0055D7F8 D_0055D7F8;
extern UnkStruct_D_0055D788 D_0055D788;
extern UnkStruct_D_0055D78C D_0055D78C;

// 0x00160C30
void CB3TrafficParam::GetParamInfoFromValve(CB3TrafficLane* p0, bool p1, bool p2)
{
    if ((field_4B & 4) != 0) return;
    CB3TrafficValve * valve;
    for (int i = 0; i < p0->field_48; i++) {
        unsigned char v = p0->field_6[i];
        unsigned char & l = p0->field_1E[i];
        valve = (CB3TrafficValve *)((char *)&D_00522660.field_0[v] + 0x4DE4);
        if ((int)field_30 == valve->field_40->field_4[l]) {
            if (!p1 && !p2) {
                if (!p2) {  // [G] retail tests p2 twice
                    field_48 = valve->GetLaneChanges(&field_4C, (ETrafficVehicleCategories)field_4D, l, &field_24);
                    // [G] lane byte re-read through an integer address (i + p0): the indexed and
                    // pointer forms are CSEd with `l` or fold 0x1E into the index
                    field_38 = valve->GetFormationAfterLaneChange(field_4C, field_48, ((UnkStruct_00160C30_col *)((int)i + (int)p0))->field_1E, &field_47);
                }
            }
            field_0 = valve->GetSpeedAfterLaneChange(field_4C, field_48, l);
            if (field_38 == 0 && D_0055D7F7.field_0 == 0 && D_0055D7F8.field_0 == 0) {
                int a = D_0055D788.field_0;
                int b = D_0055D78C.field_0;
                unsigned int r = (a << 16) + (a >> 16);
                r += b;
                D_0055D788.field_0 = r;
                D_0055D78C.field_0 = b + r;
                field_0 += 2.0f * (2.3283064e-10f * (float)r - 0.5f) * (0.15f * field_0);
            }
            break;
        }
    }
}
