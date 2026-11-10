// CB3HUDTimer::Update(float) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3HUDTimer.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (void return (f0=field_30 is the compare's leftover, not a result); search loop with break; call PrepareTimerObject() with no extra args).

// lifter variant 0
// CB3HUDTimer::Update(float) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3HUDTimer.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3HUDTimer;
struct UnkStruct_003C2640_1;
struct UnkStruct_003C2640_5;
struct UnkStruct_003C2640_6;
struct UnkStruct_D_00522660;
struct UnkStruct_D_0064D37C;

struct UnkStruct_003C2640_1 {
    unsigned char pad_0[0xC];
    float field_C;
    unsigned char pad_10[0x90];
    unsigned char field_A0;
    unsigned char pad_A1[0x22F];
    float field_2D0;
};

struct UnkStruct_D_0064D37C {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_00522660 {
    unsigned char pad_0[0x12AD28];
    UnkStruct_003C2640_5 * field_12AD28[1];  // [G] element count unknown
};

struct UnkStruct_003C2640_5 {
    unsigned char pad_0[0x1160];
    unsigned char field_1160;
};

struct UnkStruct_003C2640_6 {
    unsigned char pad_0[0xC];
    float field_C;
    unsigned char pad_10[0x2C0];
    float field_2D0;
};

class CB3HUDTimer {
public:
    void Update(float p0);
    void PrepareTimerObject();

    unsigned char pad_0[0x2C];
    UnkStruct_003C2640_1 * field_2C;
    float field_30;
};

extern UnkStruct_D_0064D37C D_0064D37C;
extern UnkStruct_D_00522660 D_00522660;

extern "C" float PrepareTimerObject__11CB3HUDTimerFv(void *);  // CB3HUDTimer::PrepareTimerObject(), passed 4 more argument(s) [G]

// 0x003C2640
void CB3HUDTimer::Update(float p0)
{
    if (field_2C->field_A0 != 0) {
        int n = D_0064D37C.field_0;
        for (int i = 0; i < n; i++) {
            UnkStruct_003C2640_5 * t1 = D_00522660.field_12AD28[i];
            if (t1->field_1160 == 0) {
                field_2C = (UnkStruct_003C2640_1 *)((char *)t1 + 0x10C0);
                break;
            }
        }
    }
    if (field_30 != field_2C->field_2D0 - field_2C->field_C) {
        PrepareTimerObject();
    }
}
