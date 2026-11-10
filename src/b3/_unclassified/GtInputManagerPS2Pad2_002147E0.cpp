// CGtInputManagerPS2Pad2::UnbindFromPort(CGtInputDevicePS2Pad2*,EGtPS2InputPort) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtInputManagerPS2Pad2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (bound=(p0!=0) declared before valid; if (valid && bound) bound = eq; final test != false; vfunc_18 takes no args (phantoms)).

// CGtInputManagerPS2Pad2::UnbindFromPort(CGtInputDevicePS2Pad2*,EGtPS2InputPort) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtInputManagerPS2Pad2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CGtInputDevicePS2Pad2;
enum EGtPS2InputPort {};

class CGtInputManagerPS2Pad2;
struct CGtInputDevicePS2Pad2;

struct CGtInputDevicePS2Pad2 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18();
};

class CGtInputManagerPS2Pad2 {
public:
    void UnbindFromPort(CGtInputDevicePS2Pad2* p0, EGtPS2InputPort p1);

    unsigned char pad_0[0x200];
    int field_200[1];  // [G] element count unknown
    unsigned char pad_204[0x4];
    int field_208;
};

// 0x002147E0
void CGtInputManagerPS2Pad2::UnbindFromPort(CGtInputDevicePS2Pad2* p0, EGtPS2InputPort p1)
{
    bool bound = p0 != 0;
    bool valid = p1 >= 0 && p1 < 2;
    if (valid && bound) {
        bound = field_200[p1] == (int)p0;
    }
    if (bound != false && valid != false) {
        field_200[p1] = 0;
        field_208--;
        p0->vfunc_18();
    }
}
