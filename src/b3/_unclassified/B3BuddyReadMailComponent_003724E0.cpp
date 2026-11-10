// CB3BuddyReadMailComponent::Release() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3BuddyReadMailComponent.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (const scene pointer local + CGt2dObject* fields tested directly (sibling CB3BuddyDisplayComponent::Release shape)).

// CB3BuddyReadMailComponent::Release() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3BuddyReadMailComponent.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CGt2dObject;

class CB3BuddyReadMailComponent;
struct UnkStruct_D_01E903E0;

struct UnkStruct_D_01E903E0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3BuddyReadMailComponent {
public:
    void Release();

    unsigned char pad_0[0x8];
    short field_8;
    unsigned char pad_A[0x26];
    CGt2dObject * field_30;
    CGt2dObject * field_34;
    CGt2dObject * field_38;
    CGt2dObject * field_3C;
    CGt2dObject * field_40;
    CGt2dObject * field_44;
    int field_48;
};

extern UnkStruct_D_01E903E0 D_01E903E0;

extern "C" void Release__20CB3MenuComponentBaseFv(void *);  // CB3MenuComponentBase::Release()
extern "C" void DestructObject__10CGt2dSceneFiP11CGt2dObject(void *, int, CGt2dObject *);  // CGt2dScene::DestructObject(int,CGt2dObject*)
extern "C" void Destruct__10CGt2dFrameFv(void *);  // CGt2dFrame::Destruct()

// 0x003724E0
void CB3BuddyReadMailComponent::Release()
{
    UnkStruct_D_01E903E0 * const scene = &D_01E903E0;
    Release__20CB3MenuComponentBaseFv(this);
    if (field_30 != 0) {
        DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, field_8, field_30);
    }
    if (field_34 != 0) {
        DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, field_8 + 1, field_34);
    }
    if (field_38 != 0) {
        DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, field_8 + 1, field_38);
    }
    if (field_3C != 0) {
        DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, field_8 + 1, field_3C);
    }
    if (field_40 != 0) {
        DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, field_8 + 1, field_40);
    }
    if (field_44 != 0) {
        DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, field_8 + 1, field_44);
    }
    field_30 = 0;
    field_34 = 0;
    field_38 = 0;
    field_3C = 0;
    field_40 = 0;
    field_44 = 0;
    Destruct__10CGt2dFrameFv((void *)field_48);
    field_48 = 0;
}
