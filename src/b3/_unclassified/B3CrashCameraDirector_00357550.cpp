// CB3CrashCameraDirector::Construct(CB3PlayerCameraManager*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3CrashCameraDirector.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3PlayerCameraManager;

class CB3CrashCameraDirector;
struct UnkStruct_00357550_2;
struct UnkStruct_00357550_e0;
struct UnkStruct_D_00522660;
struct UnkStruct__gnFrustumTestID;

struct UnkStruct__gnFrustumTestID {
    int field_0;
};

struct UnkStruct_00357550_2 {
    unsigned char pad_0[0xB90];
    int field_B90;
};

struct UnkStruct_00357550_e0 {
    unsigned char pad_0[0x1050];
};

struct UnkStruct_D_00522660 {
    UnkStruct_00357550_e0 field_0[1];  // [G] element count unknown
};

class CB3CrashCameraDirector {
public:
    void Construct(CB3PlayerCameraManager* p0);

    int field_0;
    int field_4;
    void * field_8;
    UnkStruct_00357550_2 * field_C;
    void * field_10;
    void * field_14;
    unsigned char pad_18[0xC];
    int field_24;
    int field_28;
    unsigned char pad_2C[0x7];
    unsigned char field_33;
};

extern UnkStruct__gnFrustumTestID _gnFrustumTestID;
extern UnkStruct_D_00522660 D_00522660;

// 0x00357550
void CB3CrashCameraDirector::Construct(CB3PlayerCameraManager* p0)
{
    field_4 = 0x2B9D6F8;
    field_0 = 0xFD462907;
    if (_gnFrustumTestID.field_0 == -1) {
        _gnFrustumTestID.field_0 = 0;
    }
    field_C = (UnkStruct_00357550_2 *)p0;
    field_14 = ((char *)field_C + 0x200);
    field_8 = ((char *)&D_00522660.field_0[field_C->field_B90] + 0x128290);
    field_10 = ((char *)field_C + 0x4E0);
    field_24 = 0;
    field_28 = field_C->field_B90;
    field_33 = 0;
}
