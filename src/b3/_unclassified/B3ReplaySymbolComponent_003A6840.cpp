// CB3ReplaySymbolComponent::Release() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3ReplaySymbolComponent.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (const scene pointer local; int layer = field_8 and int i = layer + 1 locals (no short re-extension); object fields CGt2dObject*).

// CB3ReplaySymbolComponent::Release() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3ReplaySymbolComponent.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CGt2dObject;

class CB3ReplaySymbolComponent;
struct UnkStruct_D_004EE040;
struct UnkStruct_D_01E903E0;

struct UnkStruct_D_01E903E0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004EE040 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3ReplaySymbolComponent {
public:
    void Release();

    unsigned char pad_0[0x8];
    short field_8;
    unsigned char pad_A[0x2];
    CGt2dObject * field_C;
    CGt2dObject * field_10;
    CGt2dObject * field_14;
    CGt2dObject * field_18;
};

extern UnkStruct_D_01E903E0 D_01E903E0;
extern UnkStruct_D_004EE040 D_004EE040;

extern "C" void Release__20CB3MenuComponentBaseFv(void *);  // CB3MenuComponentBase::Release()
extern "C" void DestructObject__10CGt2dSceneFiP11CGt2dObject(void *, int, void *);  // CGt2dScene::DestructObject(int,CGt2dObject*)
extern "C" int func_00131CA0(void *);

// 0x003A6840
void CB3ReplaySymbolComponent::Release()
{
    Release__20CB3MenuComponentBaseFv(this);
    UnkStruct_D_01E903E0 * const s = &D_01E903E0;
    int t0 = field_8;
    int i = t0 + 1;
    DestructObject__10CGt2dSceneFiP11CGt2dObject(s, i, field_C);
    field_C = 0;
    DestructObject__10CGt2dSceneFiP11CGt2dObject(s, i, field_10);
    field_10 = 0;
    if (func_00131CA0(&D_004EE040) == 0) {
        DestructObject__10CGt2dSceneFiP11CGt2dObject(s, t0, field_14);
        field_14 = 0;
        DestructObject__10CGt2dSceneFiP11CGt2dObject(s, t0, field_18);
        field_18 = 0;
    }
}
