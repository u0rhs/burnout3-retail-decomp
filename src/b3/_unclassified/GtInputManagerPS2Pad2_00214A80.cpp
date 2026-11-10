// CGtInputManagerPS2Pad2::Update() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtInputManagerPS2Pad2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a70: field_200 as 2-element array of vtable objects (declaration fix), UpdatePort(1) in if(field_260==0)).

// CGtInputManagerPS2Pad2::Update()
enum EGtPS2InputPort {};

struct UnkStruct_00214A80_2 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
};

class CGtInputManagerPS2Pad2 {
public:
    void Update();
    void UpdatePort(EGtPS2InputPort p0);

    unsigned char pad_0[0x200];
    UnkStruct_00214A80_2 * field_200[2];
    unsigned char pad_208[0x58];
    unsigned char field_260;
    unsigned char pad_261[0x3];
    int field_264;
};

// 0x00214A80
void CGtInputManagerPS2Pad2::Update()
{
    UpdatePort((EGtPS2InputPort)0);
    if (field_260 == 0) {
        UpdatePort((EGtPS2InputPort)1);
    }
    for (int i = 0; i < 2; i++) {
        if (field_200[i] != 0) {
            field_200[i]->vfunc_8();
        }
    }
    if (field_264 == 0) {
        if (field_200[1] != 0) {
            field_200[1]->vfunc_C();
        }
        field_264 = 1;
    } else {
        if (field_200[0] != 0) {
            field_200[0]->vfunc_C();
        }
        field_264 = 0;
    }
}
