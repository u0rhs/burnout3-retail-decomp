// CB3TitleScreenComponent::Release() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3TitleScreenComponent.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (object fields as pointers (CGt2dObject*, void*); scene = &D_01E90240.field_1A0 after the base Release).

class CGt2dObject;

class CB3TitleScreenComponent;
struct UnkStruct_D_01E90240;
struct UnkStruct_D_01E903E0;

struct UnkStruct_D_01E903E0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E90240 {
    unsigned char pad_0[0x1A0];
    UnkStruct_D_01E903E0 field_1A0;
};

class CB3TitleScreenComponent {
public:
    void Release();

    unsigned char pad_0[0x8];
    short field_8;
    unsigned char pad_A[0x2];
    void * field_C;
    void * field_10;
    CGt2dObject * field_14;
    CGt2dObject * field_18;
    CGt2dObject * field_1C;
    CGt2dObject * field_20;
    CGt2dObject * field_24;
    CGt2dObject * field_28;
};

extern UnkStruct_D_01E90240 D_01E90240;

extern "C" void Release__20CB3MenuComponentBaseFv(void *);  // CB3MenuComponentBase::Release()
extern "C" void DestructObject__10CGt2dSceneFiP11CGt2dObject(void *, int, void *);  // CGt2dScene::DestructObject(int,CGt2dObject*)
extern "C" void Destruct__10CGt2dFrameFv(void *);  // CGt2dFrame::Destruct()

// 0x00343720
void CB3TitleScreenComponent::Release()
{
    Release__20CB3MenuComponentBaseFv(this);
    UnkStruct_D_01E903E0 * scene = &D_01E90240.field_1A0;
    if (field_14 != 0) {
        DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, field_8, field_14);
        field_14 = 0;
    }
    if (field_18 != 0) {
        DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, field_8, field_18);
        field_18 = 0;
    }
    DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, field_8 + 1, field_1C);
    DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, field_8, field_20);
    DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, field_8, field_24);
    DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, field_8, field_28);
    field_1C = 0;
    field_20 = 0;
    field_24 = 0;
    field_28 = 0;
    Destruct__10CGt2dFrameFv(field_10);
    field_10 = 0;
    Destruct__10CGt2dFrameFv(field_C);
    field_C = 0;
}
