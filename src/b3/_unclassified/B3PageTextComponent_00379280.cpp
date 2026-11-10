// CB3PageTextComponent::HideSelectionBar() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3PageTextComponent.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (scene address taken into a local before the null test).

// CB3PageTextComponent::HideSelectionBar() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3PageTextComponent.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CGt2dObject;

class CB3PageTextComponent;
struct UnkStruct_D_01E903E0;

struct UnkStruct_D_01E903E0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3PageTextComponent {
public:
    void HideSelectionBar();

    unsigned char pad_0[0x8];
    short field_8;
    unsigned char pad_A[0x1A];
    int field_24;
};

extern UnkStruct_D_01E903E0 D_01E903E0;

extern "C" void DestructObject__10CGt2dSceneFiP11CGt2dObject(void *, int, void *);  // CGt2dScene::DestructObject(int,CGt2dObject*)

// 0x00379280
void CB3PageTextComponent::HideSelectionBar()
{
    void *s = &D_01E903E0;
    int t0 = field_24;
    if (t0 == 0) return;
    DestructObject__10CGt2dSceneFiP11CGt2dObject(s, (field_8 + 1), (CGt2dObject*)t0);
    field_24 = 0;
}
