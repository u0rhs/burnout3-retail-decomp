// CB3DebugMipMaps::Update() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3DebugMipMaps.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (float return -> void; if (mgrFlashTime >= 0.0f) mgrFlashTime -= 24.0f * D_004F509C.field_0;).

struct UnkStruct_D_004F509C {
    float field_0;
    unsigned char pad_4[0xC];
};
class CB3DebugMipMaps {
public:
    void Update();
    static float mgrFlashTime;
};
extern UnkStruct_D_004F509C D_004F509C;

void CB3DebugMipMaps::Update()
{
    if (mgrFlashTime >= 0.0f) {
        mgrFlashTime -= 24.0f * D_004F509C.field_0;
    }
}
