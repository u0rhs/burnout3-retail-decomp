// CB3BuddyDisplayComponent::Release() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3BuddyDisplayComponent.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (scene address in a const local declared before the base Release call; CGt2dObject* fields).

// CB3BuddyDisplayComponent::Release() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3BuddyDisplayComponent.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CGt2dObject;

class CB3BuddyDisplayComponent;
struct UnkStruct_D_01E903E0;

struct UnkStruct_D_01E903E0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3BuddyDisplayComponent {
public:
    void Release();

    unsigned char pad_0[0x8];
    short field_8;
    unsigned char pad_A[0xE62];
    CGt2dObject * field_E6C;
    CGt2dObject * field_E70;
    int field_E74;
    unsigned char pad_E78[0x4];
    CGt2dObject * field_E7C;
};

extern UnkStruct_D_01E903E0 D_01E903E0;

extern "C" void Release__20CB3MenuComponentBaseFv(void *);  // CB3MenuComponentBase::Release()
extern "C" void DestructObject__10CGt2dSceneFiP11CGt2dObject(void *, int, CGt2dObject *);  // CGt2dScene::DestructObject(int,CGt2dObject*)
extern "C" void Destruct__10CGt2dFrameFv(void *);  // CGt2dFrame::Destruct()

// 0x00367040
void CB3BuddyDisplayComponent::Release()
{
    UnkStruct_D_01E903E0 * const scene = &D_01E903E0;
    Release__20CB3MenuComponentBaseFv(this);
    if (field_E70 != 0) {
        DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, field_8, field_E70);
    }
    if (field_E7C != 0) {
        DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, field_8 + 1, field_E7C);
    }
    if (field_E6C != 0) {
        DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, field_8 + 2, field_E6C);
    }
    field_E6C = 0;
    field_E7C = 0;
    field_E70 = 0;
    Destruct__10CGt2dFrameFv((void *)field_E74);
    field_E74 = 0;
}
