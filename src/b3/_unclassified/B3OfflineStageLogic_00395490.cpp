// CB3OfflineStageLogic::Update() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3OfflineStageLogic.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3InputManager;
class CB3OfflineStageLogic;
struct UnkStruct_00395490_e0;
struct UnkStruct_D_0051BA98;
struct UnkStruct_D_00665E53;
struct UnkStruct_D_01E90430;

class CB3InputManager {
public:
    float GetDeadInputTime(signed char);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_00665E53 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E90430 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0051BA98 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00395490_e0 {
    unsigned char pad_0[0x10];
};

class CB3OfflineStageLogic {
public:
    void Update();

    UnkStruct_00395490_e0 field_0[1];  // [G] element count unknown
};

extern UnkStruct_D_00665E53 D_00665E53;
extern UnkStruct_D_01E90430 D_01E90430;
extern UnkStruct_D_0051BA98 D_0051BA98;
extern CB3InputManager D_004F50C0;

extern "C" void Update__24CB3TakedownCameraManagerFv(void *);  // CB3TakedownCameraManager::Update()

// 0x00395490
void CB3OfflineStageLogic::Update()
{
    for (int i = 0; (i < 2); i++) {
        Update__24CB3TakedownCameraManagerFv(((char *)&field_0[i] + 0x20));
    }
    float r1 = D_004F50C0.GetDeadInputTime(0);
    if (!(r1 <= 300.0f)) {
        float r2 = D_004F50C0.GetDeadInputTime(1);
        if (r2 <= 300.0f) {
        } else {
            if (D_00665E53.field_0 != 0) {
            } else {
                if (D_01E90430.field_0 != 0) {
                } else {
                    D_0051BA98.field_0 = 0;
                }
            }
        }
    } else {
    }
}
