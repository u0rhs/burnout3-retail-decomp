// CB3GameData::Update() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3GameData.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3GameData;
struct UnkStruct_0014EF60_2;
struct UnkStruct_0014EF60_5;
struct UnkStruct_0014EF60_e1;
struct UnkStruct_0014EF60_e2;
struct UnkStruct_D_00522680;
struct UnkStruct_D_0064D37C;

struct UnkStruct_D_0064D37C {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0014EF60_2 {
    float field_0;
    float field_4;
};

struct UnkStruct_D_00522680 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0014EF60_5 {
    unsigned char pad_0[0x3FC];
    int field_3FC;
};

struct UnkStruct_0014EF60_e1 {
    unsigned char pad_0[0x10];
};

struct UnkStruct_0014EF60_e2 {
    unsigned char pad_0[0x70];
};

class CB3GameData {
public:
    void Update();

    UnkStruct_0014EF60_e1 field_0[1];  // [G] element count unknown
    unsigned char pad_10[0x418];
    int field_428[1];  // [G] element count unknown
    unsigned char pad_42C[0x140];
    UnkStruct_0014EF60_5 * field_56C;
    unsigned char pad_570[0x1C];
    unsigned char field_58C;
};

extern UnkStruct_D_0064D37C D_0064D37C;
extern UnkStruct_D_00522680 D_00522680;

extern "C" void Update__14CB3CrashPickupFf(void *, float);  // CB3CrashPickup::Update(float)
extern "C" void Update__12CB3CrashRampFPfPfi(void *, float*, float*, int);  // CB3CrashRamp::Update(float*,float*,int)

// 0x0014EF60
void CB3GameData::Update()
{
    UnkStruct_0014EF60_2 local;  // [G] the frame's one local (size: up to the frame top)
    if (field_56C == 0) return;
    int t0 = D_0064D37C.field_0;
    local.field_4 = 20.0f;
    float t1 = D_00522680.field_0;
    local.field_0 = 20.0f;
    for (int i = 0; (i < field_58C); i++) {
        Update__14CB3CrashPickupFf(&field_0[i], t1);
    }
    for (int i1 = 0; (i1 < 2); i1++) {
        field_428[i1] = 4;
    }
    for (int i2 = 0; (i2 < field_56C->field_3FC); i2++) {
        Update__12CB3CrashRampFPfPfi(((char *)((char *)this + ((i2 * 7) << 4)) + 0x140), (float*)((char *)&local + 0x4), (float*)&local, t0);
    }
}
