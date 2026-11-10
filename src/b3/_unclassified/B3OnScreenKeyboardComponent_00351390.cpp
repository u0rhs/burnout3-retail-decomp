// CB3OnScreenKeyboardComponent::Release() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3OnScreenKeyboardComponent.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (CGt2dObject* fields; scene held in a const local pointer).

// lifter variant 0
// CB3OnScreenKeyboardComponent::Release() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3OnScreenKeyboardComponent.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CGt2dObject;

class CB3OnScreenKeyboardComponent;
struct UnkStruct_D_01E7AA38;
struct UnkStruct_D_01E903E0;

struct UnkStruct_D_01E7AA38 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E903E0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3OnScreenKeyboardComponent {
public:
    void Release();

    unsigned char pad_0[0x8];
    short field_8;
    unsigned char pad_A[0x3E];
    CGt2dObject * field_48;
    CGt2dObject * field_4C;
};

extern UnkStruct_D_01E7AA38 D_01E7AA38;
extern UnkStruct_D_01E903E0 D_01E903E0;

extern "C" void Release__20CB3MenuComponentBaseFv(void *);  // CB3MenuComponentBase::Release()
extern "C" void DestructObject__10CGt2dSceneFiP11CGt2dObject(void *, int, void *);  // CGt2dScene::DestructObject(int,CGt2dObject*)

// 0x00351390
void CB3OnScreenKeyboardComponent::Release()
{
    Release__20CB3MenuComponentBaseFv(this);
    UnkStruct_D_01E903E0 * const scene = &D_01E903E0;
    if (field_48 != 0) {
        DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, field_8, field_48);
    }
    if (field_4C != 0) {
        DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, field_8 + 1, field_4C);
    }
    field_48 = 0;
    field_4C = 0;
    D_01E7AA38.field_0 = 1;
}
