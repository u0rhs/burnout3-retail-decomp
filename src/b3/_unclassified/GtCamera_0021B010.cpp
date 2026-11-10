// CGtCamera::Release() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtCamera.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CGtCamera;
struct UnkStruct_0021B010_2;
struct UnkStruct_0021B010_e0;

struct UnkStruct_0021B010_e0 {
    UnkStruct_0021B010_2 * field_0;
    int field_4;
};

struct UnkStruct_0021B010_2 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14(int);
};

class CGtCamera {
public:
    void Release();

    unsigned char pad_0[0x34];
    UnkStruct_0021B010_e0 * field_34;
    int field_38;
    unsigned char field_3C;
};

// 0x0021B010
void CGtCamera::Release()
{
    for (int i = 0; (i < field_38); i++) {
        field_34[i].field_0->vfunc_14(field_34[i].field_4);
    }
    field_3C = 0;
}
