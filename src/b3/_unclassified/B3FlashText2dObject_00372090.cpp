// CB3FlashText2dObject::SetVFlashTimeScale(float) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3FlashText2dObject.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (void; sub-struct at 0x20 via hoisted pointer local (field_C)).

// CB3FlashText2dObject::SetVFlashTimeScale(float) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3FlashText2dObject.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3FlashText2dObject;

struct UnkStruct_00372090_0 {
    unsigned char pad_0[0xC];
    float field_C;
};

class CB3FlashText2dObject {
public:
    void SetVFlashTimeScale(float p0);

    unsigned char pad_0[0x20];
    UnkStruct_00372090_0 field_20;
};

// 0x00372090
void CB3FlashText2dObject::SetVFlashTimeScale(float p0)
{
    UnkStruct_00372090_0 *s = &field_20;
    if (p0 >= 0.0f) {
        s->field_C = 2.0f + p0;
    } else {
        s->field_C = -1.0f;
    }
}
