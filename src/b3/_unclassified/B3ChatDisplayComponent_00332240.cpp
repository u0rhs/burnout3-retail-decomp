// CB3ChatDisplayComponent::Release() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3ChatDisplayComponent.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (scene address held in a const pointer local (kept in s1); index (field_8+1) in an int local so the +1 isn't folded).

// lifter variant 0
// CB3ChatDisplayComponent::Release() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3ChatDisplayComponent.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CGt2dObject;

class CB3ChatDisplayComponent;
struct UnkStruct_00332240_e0;
struct UnkStruct_D_01E903E0;

struct UnkStruct_D_01E903E0 {
    unsigned char pad_0[0x2C];
    UnkStruct_00332240_e0 * field_2C;
};

struct UnkStruct_00332240_e0 {
    unsigned char pad_0[0xC];
    int field_C;
};

class CB3ChatDisplayComponent {
public:
    void Release();

    unsigned char pad_0[0x8];
    short field_8;
    unsigned char pad_A[0x856];
    int field_860;
    int field_864;
    int field_868;
};

extern UnkStruct_D_01E903E0 D_01E903E0;

extern "C" void Release__20CB3MenuComponentBaseFv(void *);  // CB3MenuComponentBase::Release()
extern "C" void DestructObject__10CGt2dSceneFiP11CGt2dObject(void *, int, void *);  // CGt2dScene::DestructObject(int,CGt2dObject*)
extern "C" void Destruct__10CGt2dFrameFv(void *);  // CGt2dFrame::Destruct()

// 0x00332240
void CB3ChatDisplayComponent::Release()
{
    Release__20CB3MenuComponentBaseFv(this);
    UnkStruct_D_01E903E0 * const scene = &D_01E903E0;
    DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, (field_8 + 1), (CGt2dObject*)field_860);
    DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, field_8, (CGt2dObject*)field_864);
    int i = field_8 + 1;
    scene->field_2C[i].field_C = 0;
    field_860 = 0;
    field_864 = 0;
    Destruct__10CGt2dFrameFv((void *)field_868);
    field_868 = 0;
}
