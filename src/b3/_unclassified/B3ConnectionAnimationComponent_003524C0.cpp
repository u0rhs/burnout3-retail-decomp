// CB3ConnectionAnimationComponent::Release() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3ConnectionAnimationComponent.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (scene = &D_01E90240.field_1A0 local (keeps the scene address in s1)).

// CB3ConnectionAnimationComponent::Release() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3ConnectionAnimationComponent.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CGt2dObject;

class CB3ConnectionAnimationComponent;
struct UnkStruct_003524C0_e0;
struct UnkStruct_003524C0_e1;
struct UnkStruct_D_01E903E0;

struct UnkStruct_003524C0_e0 {
    int field_0;
    int field_4;
};

struct UnkStruct_003524C0_e1 {
    int field_0;
    int field_4;
};

struct UnkStruct_D_01E903E0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3ConnectionAnimationComponent {
public:
    void Release();

    unsigned char pad_0[0x8];
    short field_8;
    unsigned char pad_A[0x2];
    int field_C;
    UnkStruct_003524C0_e0 field_10[1];  // [G] element count unknown
    unsigned char pad_18[0x18];
    UnkStruct_003524C0_e1 field_30[1];  // [G] element count unknown
};

struct UnkStruct_D_01E90240 {
    unsigned char pad_0[0x1A0];
    UnkStruct_D_01E903E0 field_1A0;  // = D_01E903E0 (N65)
};

extern UnkStruct_D_01E90240 D_01E90240;

extern "C" void Release__20CB3MenuComponentBaseFv(void *);  // CB3MenuComponentBase::Release()
extern "C" void DestructObject__10CGt2dSceneFiP11CGt2dObject(void *, int, void *);  // CGt2dScene::DestructObject(int,CGt2dObject*)

// 0x003524C0
void CB3ConnectionAnimationComponent::Release()
{
    Release__20CB3MenuComponentBaseFv(this);
    UnkStruct_D_01E903E0 * scene = &D_01E90240.field_1A0;
    DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, field_8, (CGt2dObject*)field_C);
    for (int i = 0; i < 4; i++) {
        DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, field_8, (CGt2dObject*)field_10[i].field_0);
        DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, field_8, (CGt2dObject*)field_10[i].field_4);
    }
    for (int i1 = 0; i1 < 4; i1++) {
        DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, field_8 + 1, (CGt2dObject*)field_30[i1].field_0);
        DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, field_8 + 1, (CGt2dObject*)field_30[i1].field_4);
    }
}
