// CB3MessageBoxComponent::Release() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3MessageBoxComponent.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (CGt2dObject* fields + element-pointer loops; const scene local; SetCurrentPrompts 64-bit a1 (as func_004546B0); call args through address puns to force field_88 reload [G]).

// lifter variant 0
// CB3MessageBoxComponent::Release() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3MessageBoxComponent.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CGt2dObject;

class CB3MessageBoxComponent;
struct UnkStruct_D_01E89800;
struct UnkStruct_D_01E8980A;
struct UnkStruct_D_01E903E0;
struct UnkStruct_D_01E90424;

struct UnkStruct_D_01E90424 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E8980A {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E89800 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E903E0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3MessageBoxComponent {
public:
    void Release();

    unsigned char pad_0[0x8];
    short field_8;
    unsigned char pad_A[0x16];
    CGt2dObject * field_20[2];
    CGt2dObject * field_28[3];
    unsigned char pad_34[0x10];
    CGt2dObject * field_44;
    unsigned char pad_48[0x18];
    unsigned char field_60;
    unsigned char pad_61[0x1F];
    CGt2dObject * field_80;
    CGt2dObject * field_84;
    unsigned long field_88;
    int field_90;
};

extern UnkStruct_D_01E90424 D_01E90424;
extern UnkStruct_D_01E8980A D_01E8980A;
extern UnkStruct_D_01E89800 D_01E89800;
extern UnkStruct_D_01E903E0 D_01E903E0;

// 0x0032B530
extern "C" void Release__20CB3MenuComponentBaseFv(void *);  // CB3MenuComponentBase::Release()
extern "C" void DestructObject__10CGt2dSceneFiP11CGt2dObject(void *, int, void *);  // CGt2dScene::DestructObject(int,CGt2dObject*)
extern "C" void SetCurrentPrompts__19CB3PromptsComponentFUiUi(void *, unsigned long, unsigned int);  // CB3PromptsComponent::SetCurrentPrompts(unsigned int,unsigned int); first argument declared 64-bit here [G]: retail passes the ld value un-truncated (as func_004546B0)

void CB3MessageBoxComponent::Release()
{
    Release__20CB3MenuComponentBaseFv(this);
    UnkStruct_D_01E903E0 * const scene = &D_01E903E0;
    DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, field_8, field_80);
    DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, (field_8 + 1), field_84);
    if (field_44 != 0) {
        DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, (field_8 + 1), field_44);
        field_44 = 0;
    }
    for (int i = 0; i < 2; i++) {
        CGt2dObject ** pp = &field_20[i];
        if (*pp != 0) {
            DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, (field_8 + 1), *pp);
            *pp = 0;
        }
    }
    for (int i = 0; i < 3; i++) {
        CGt2dObject ** pp = &field_28[i];
        if (*pp != 0) {
            DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, (field_8 + 1), *pp);
            *pp = 0;
        }
    }
    field_80 = 0;
    field_84 = 0;
    if (field_60 == 0 && D_01E90424.field_0 == 5) {
        if (field_88 != 0 || field_90 != 0) {
            // [G] arguments read through address puns: retail reloads field_88 (ld) after the test instead of
            // reusing it, and loads it before field_90; a plain member read is CSE'd. The real source likely
            // reads these through another type (a union or prompt struct) -- unknown.
            SetCurrentPrompts__19CB3PromptsComponentFUiUi(&D_01E89800, *(unsigned long *)&field_88, *(unsigned int *)&field_90);
        } else if (D_01E8980A.field_0 != 0) {
            ((UnkStruct_D_01E89800 *)&D_01E89800)->vfunc_C();
        }
    }
}
