// CB3ActiveBody::GetInteractionTypeAgainst(CB3ActiveBody*) const -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3PhysicsManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (near7: compare value in a function-top int t declared before a/b, 'if (o->field_242B == t)' (near3 decl-order beq rule)).

// lifter variant 0
// CB3ActiveBody::GetInteractionTypeAgainst(CB3ActiveBody*) const -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3PhysicsManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3ActiveBody;

class CB3ActiveBody;
struct UnkStruct_001BA950_2;
struct UnkStruct_001BA950_3;
struct UnkStruct_001BA950_4;
struct UnkStruct_001BA950_5;
struct UnkStruct_001BA950_6;
struct UnkStruct_001BA950_e0;
struct UnkStruct_kaaPhysicsType;

struct UnkStruct_001BA950_2 {
    unsigned char pad_0[0x13F4];
    UnkStruct_001BA950_4 * field_13F4;
    unsigned char pad_13F8[0x1033];
    signed char field_242B;
};

struct UnkStruct_001BA950_3 {
    unsigned char pad_0[0x13F4];
    UnkStruct_001BA950_4 * field_13F4;
    unsigned char pad_13F8[0x1033];
    signed char field_242B;
};

struct UnkStruct_001BA950_4 {
    unsigned char pad_0[0x19AC];
    signed char field_19AC;
};

struct UnkStruct_001BA950_5 {
    unsigned char pad_0[0x19AC];
    signed char field_19AC;
};

struct UnkStruct_001BA950_6 {
    unsigned char pad_0[0x19AC];
    signed char field_19AC;
};

struct UnkStruct_001BA950_e0 {
    int field_0[1];  // [G] element count unknown
    unsigned char pad_4[0x18];
};

struct UnkStruct_kaaPhysicsType {
    UnkStruct_001BA950_e0 field_0[1];  // [G] element count unknown
};

class CB3ActiveBody {
public:
    int GetInteractionTypeAgainst(CB3ActiveBody* p0) const;
    int GetNetworkCollBodyType() const;

    unsigned char pad_0[0xC];
    UnkStruct_001BA950_2 * field_C;
};

extern UnkStruct_kaaPhysicsType kaaPhysicsType;

extern "C" int GetNetworkCollBodyType__13CB3ActiveBodyCFv(void *);  // CB3ActiveBody::GetNetworkCollBodyType() const

// 0x001BA950
int CB3ActiveBody::GetInteractionTypeAgainst(CB3ActiveBody* p0) const
{
    int t;
    int a = GetNetworkCollBodyType();
    int b = p0->GetNetworkCollBodyType();
    if (a == 1 && b == 5) {
        t = field_C->field_13F4->field_19AC;
        if (p0->field_C->field_242B == t) {
            b = 4;
        }
    } else if (b == 1 && a == 5) {
        t = p0->field_C->field_13F4->field_19AC;
        if (field_C->field_242B == t) {
            a = 4;
        }
    }
    return kaaPhysicsType.field_0[a].field_0[b];
}
