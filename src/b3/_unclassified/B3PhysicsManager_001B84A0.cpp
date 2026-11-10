// CB3PhysicsManager::RemoveTrafficVehicle(CB3TrafficVehicle*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3PhysicsManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (mwperm: +'UnkStruct_001B84A0_ent * s; bool t5; CB3TrafficVehicle * v0 = p0; int t0; t0 = t'; 'field_1CB70 = field_1CB70 - 1;' -> 'char t4; int t6 = field_1CB70 -1; t0 = t6; field_1CB70 = t0;'; 'p0->field_16C = 0; int cnt = field_1CB70; if (idx == cnt) { ' -> 'v0->field_16C = 0; bool t10; if ((t10 = idx != ((int)field_1CB70))) { s = &field').

// CB3PhysicsManager::RemoveTrafficVehicle -- hand-matched (a66).
typedef unsigned int u_long128 __attribute__((mode(TI)));

struct UnkStruct_001B84A0_ent;

struct UnkStruct_001B84A0_obj {
    unsigned char pad_0[0x16C];
    UnkStruct_001B84A0_ent * field_16C;
    unsigned char pad_170[0x22B9];
    unsigned char field_2429;
};

struct UnkStruct_001B84A0_ent {
    signed char field_0;
    unsigned char field_1;
    unsigned char field_2;
    unsigned char pad_3[0x1];
    int field_4;
    int field_8;
    UnkStruct_001B84A0_obj * field_C;
    u_long128 field_10;
    u_long128 field_20;
};

struct CB3TrafficVehicle {
    unsigned char pad_0[0x16C];
    UnkStruct_001B84A0_ent * field_16C;
};

struct UnkStruct_D_01E65499 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_001B84A0_e2 {
    UnkStruct_001B84A0_ent * field_0;
    unsigned char pad_4[0x17C];
};

struct UnkStruct_D_00539D7C {
    UnkStruct_001B84A0_e2 field_0[1];  // [G] element count unknown
};

class CB3PhysicsManager {
public:
    void RemoveTrafficVehicle(CB3TrafficVehicle* p0);
    void ExtractActiveBody(int);

    unsigned char pad_0[0x70];
    UnkStruct_001B84A0_ent field_70[1];  // [G] element count unknown
    unsigned char pad_A0[0x1CAD0];
    int field_1CB70;
};

extern UnkStruct_D_01E65499 D_01E65499;
extern UnkStruct_D_00539D7C D_00539D7C;

// 0x001B84A0
void CB3PhysicsManager::RemoveTrafficVehicle(CB3TrafficVehicle* p0)
{
    UnkStruct_001B84A0_ent * s;
    bool t5;
    CB3TrafficVehicle * v0 = p0;
    int t0;
    int idx = p0->field_16C - field_70;
    char t4;
    int t6 = field_1CB70 -1;
    t0 = t6;
    field_1CB70 = t0;
    ExtractActiveBody(idx);
    v0->field_16C = 0;
    bool t10;
    if ((t10 = idx != ((int)field_1CB70))) {
        s = &field_70[(field_1CB70 ^ 0)];
        field_70[idx].field_0 = s->field_0;
        if (!(1)) {
        } else {
            field_70[idx].field_1 = s->field_1;
            field_70[idx].field_2 = s->field_2;
            field_70[idx].field_4 = s->field_4;
        }
        __int128 * t1;
        field_70[idx].field_8 = s->field_8;
        field_70[idx].field_C = s->field_C;
        field_70[idx].field_10 = (*(t1 = &s->field_10));
        field_70[idx].field_20 = s->field_20;
        bool t12 = 3 != field_70[idx].field_0;
        if (t12) {
            if (!((*(&D_01E65499.field_0)))) {
            } else {
                signed char t8 = field_70[idx].field_0;
                t4 = t8;
                t5 = ((0 ^ t4)) != 4;
                if (t5) {
                } else {
                    UnkStruct_001B84A0_obj * t2 = ((UnkStruct_001B84A0_ent *)((char *)field_70 + idx * 48))->field_C;
                    unsigned int t7 = 48 * idx;
                    unsigned char t3 = t2->field_2429;
                    char * t9 = (char *)field_70 - -(t7);
                    D_00539D7C.field_0[t3].field_0 = ((UnkStruct_001B84A0_ent *)((t9)));
                }
            }
        } else {
            unsigned int t13 = 48 * idx;
            ((UnkStruct_001B84A0_ent *)((char *)field_70 - -(idx * 48)))->field_C->field_16C = ((UnkStruct_001B84A0_ent *)(t13 + (char *)field_70));
        }
    }
}
