// CB3EffectsManager::EndUpdate() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3EffectsManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3EffectsManager;
struct UnkStruct_002623F0_e0;
struct UnkStruct_D_00522680;
struct UnkStruct_D_01EA4BB0;

struct UnkStruct_D_00522680 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EA4BB0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_002623F0_e0 {
    unsigned char pad_0[0x150];
};

class CB3EffectsManager {
public:
    void EndUpdate();

    UnkStruct_002623F0_e0 field_0[1];  // [G] element count unknown
    unsigned char pad_150[0x1F6D0];
    int field_1F820;
    unsigned char pad_1F824[0x4];
    int field_1F828;
    int field_1F82C;
    unsigned char pad_1F830[0x18];
    float field_1F848;
    float field_1F84C;
};

extern UnkStruct_D_00522680 D_00522680;
extern UnkStruct_D_01EA4BB0 D_01EA4BB0;

extern "C" void EndUpdate__16CB3ParticleArrayFfRCQ29GtMathPs26CGtV2d(void *, float, const void *);  // CB3ParticleArray::EndUpdate(float,const GtMathPs2::CGtV2d&)
extern "C" void func_0039AD20(void *, float);

struct UnkStruct_002623F0_pad {
    unsigned char field_0[0x4];
    UnkStruct_002623F0_pad() {}
    ~UnkStruct_002623F0_pad() {}
};

// 0x002623F0
void CB3EffectsManager::EndUpdate()
{
    UnkStruct_002623F0_pad pad;  // [G] an unused local object: retail's frame keeps 0x10 unused bytes at its top (a scoped object with a constructor/destructor reserves its slot, known.md N140)
    func_0039AD20(&D_01EA4BB0, field_1F84C);
    field_1F848 = D_00522680.field_0;
    for (int i = 0; (i < 24); i++) {
        EndUpdate__16CB3ParticleArrayFfRCQ29GtMathPs26CGtV2d(((char *)&field_0[i] + 0x170), field_1F848, ((char *)this + 0x1F840));
    }
    field_1F828 = ((field_1F828 << 16) + (field_1F828 >> 16));
    field_1F828 = (field_1F828 + field_1F82C);
    field_1F82C = (field_1F82C + field_1F828);
    field_1F820 = field_1F828;
}
