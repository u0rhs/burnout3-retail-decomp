// CB3AICar::Update() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3AICar.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (timer if/else flipped (field_1BE0 != 0 first, field_1BD8 a float); early-return guard chain; >200 arm returns explicitly; int temp for the field_1550 test; N140 unused ctor/dtor local for the 0x30 frame).

// CB3AICar::Update() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3AICar.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3AICar;
class CB3AIDriver;
struct UnkStruct_00143B10_4;
struct UnkStruct_D_004E0E8C;
struct UnkStruct_D_0052267C;
struct UnkStruct_D_01E754F0;

class CB3AIDriver {
public:
    void Update();
};

struct UnkStruct_D_0052267C {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004E0E8C {
    float field_0;
};

struct UnkStruct_D_01E754F0 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00143B10_4 {
    unsigned char pad_0[0x1550];
    unsigned char field_1550;
};

class CB3AICar {
public:
    void Update();
    void UpdateAICheckpoint();

    unsigned char pad_0[0x16B8];
    int field_16B8;
    unsigned char pad_16BC[0x1F8];
    int field_18B4;
    unsigned char pad_18B8[0x8];
    int field_18C0;
    unsigned char pad_18C4[0x26];
    unsigned char field_18EA;
    unsigned char pad_18EB[0x9];
    int field_18F4;
    unsigned char pad_18F8[0x18];
    // vptr at +0x1910: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18();
    virtual void vfunc_1C();
    virtual void vfunc_20();
    virtual void vfunc_24();
    virtual void vfunc_28();
    virtual void vfunc_2C();
    int field_1914;
    unsigned char pad_1918[0x80];
    unsigned char field_1998;
    unsigned char pad_1999[0x57];
    CB3AIDriver field_19F0;
    unsigned char pad_19F1[0x1E3];
    float field_1BD4;
    float field_1BD8;
    unsigned char pad_1BDC[0x4];
    unsigned char field_1BE0;
    unsigned char pad_1BE1[0x84F];
    UnkStruct_00143B10_4 * field_2430;
    unsigned char pad_2434[0x8];
    int field_243C;
    unsigned char pad_2440[0xA];
    unsigned short field_244A;
    unsigned char pad_244C[0x2];
    unsigned char field_244E;
    unsigned char pad_244F[0x1];
    int field_2450;
};

struct UnkStruct_00143B10_pad {
    unsigned char field_0[0x4];
    UnkStruct_00143B10_pad() {}
    ~UnkStruct_00143B10_pad() {}
};

extern UnkStruct_D_0052267C D_0052267C;
extern UnkStruct_D_004E0E8C D_004E0E8C;
extern UnkStruct_D_01E754F0 D_01E754F0;

extern "C" void Update__10CB3RaceCarFv(void *);  // CB3RaceCar::Update()
extern "C" void SetActive__10CB3RaceCarFb(void *, bool);  // CB3RaceCar::SetActive(bool)
extern "C" void func_00141D60(CB3AICar *, int, int);
extern "C" void func_001BED00(UnkStruct_00143B10_4 *, float);
extern "C" void func_00141FC0(CB3AICar *);

// 0x00143B10
void CB3AICar::Update()
{
    UnkStruct_00143B10_pad pad;  // [G] an unused local object: retail's frame keeps 0x10 unused bytes at its top (a scoped object with a constructor/destructor reserves its slot, known.md N140)
    if (field_1BE0 != 0) {
        float t = field_1BD8 - D_0052267C.field_0;
        field_1BD8 = t;
        if (t < 0.0f) {
            field_1BE0 = 0;
            field_1BD4 = 50.0f;
        }
    } else {
        float t = field_1BD4 - D_0052267C.field_0;
        field_1BD4 = t;
        if (t < 0.0f) {
            field_1BE0 = 1;
            field_1BD8 = 50.0f;
        }
    }
    Update__10CB3RaceCarFv(this);
    if (field_18B4 == 0 || field_2430 == 0 || field_1998 == 0) {
        return;
    }
    if (field_244E != 0) {
        field_244E = 0;
        return;
    }
    if (field_16B8 != 0) {
        UpdateAICheckpoint();
        if (field_18F4 > 200) {
            func_00141D60(this, (field_244A + -8), 0);
            func_001BED00(field_2430, (D_004E0E8C.field_0 * D_01E754F0.field_0));
            field_18F4 = 0;
            field_2450 = 0;
            return;
        } else if (field_18EA != 0) {
            field_244A = field_18C0;
            field_2450 = 0;
            field_243C = 0;
        } else {
            field_19F0.Update();
            func_00141FC0(this);
            UnkStruct_00143B10_4 * t4 = field_2430;
            int v5;
            if (t4 != 0) {
                v5 = t4->field_1550;
            } else {
                v5 = 0;
            }
            if (v5 == 0) {
                vfunc_2C();
            }
        }
        return;
    }
    if (field_18EA == 0 && field_1914 == 1) {
        SetActive__10CB3RaceCarFb(this, 0);
    }
}
