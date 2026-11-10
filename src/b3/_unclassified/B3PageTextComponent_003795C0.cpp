// CB3PageTextComponent::Release() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3PageTextComponent.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (scene address taken into a const local (keeps it in s1) and the slot index into int i, as sibling CB3ChatDisplayComponent::Release).

class CGt2dObject;

class CB3PageTextComponent;
struct UnkStruct_003795C0_e0;
struct UnkStruct_D_01E903E0;

struct UnkStruct_D_01E903E0 {
    unsigned char pad_0[0x2C];
    UnkStruct_003795C0_e0 * field_2C;
};

struct UnkStruct_003795C0_e0 {
    unsigned char pad_0[0xC];
    int field_C;
};

class CB3PageTextComponent {
public:
    void Release();

    unsigned char pad_0[0x8];
    short field_8;
    unsigned char pad_A[0xE];
    int field_18;
    int field_1C;
    int field_20;
    int field_24;
};

extern UnkStruct_D_01E903E0 D_01E903E0;

extern "C" void Release__20CB3MenuComponentBaseFv(void *);  // CB3MenuComponentBase::Release()
extern "C" void DestructObject__10CGt2dSceneFiP11CGt2dObject(void *, int, void *);  // CGt2dScene::DestructObject(int,CGt2dObject*)
extern "C" void Destruct__10CGt2dFrameFv(void *);  // CGt2dFrame::Destruct()

// 0x003795C0
void CB3PageTextComponent::Release()
{
    Release__20CB3MenuComponentBaseFv(this);
    UnkStruct_D_01E903E0 * const scene = &D_01E903E0;
    DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, (field_8 + 1), (CGt2dObject*)field_18);
    if (field_24 != 0) {
        DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, (field_8 + 1), (CGt2dObject*)field_24);
    }
    DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, field_8, (CGt2dObject*)field_20);
    int i = field_8 + 1;
    scene->field_2C[i].field_C = 0;
    field_18 = 0;
    field_24 = 0;
    field_20 = 0;
    Destruct__10CGt2dFrameFv((void *)field_1C);
    field_1C = 0;
}
