// CGtCamera::Update(float) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtCamera.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CGtCamera;
struct UnkStruct_0021B440_2;
struct UnkStruct_0021B440_e0;

struct UnkStruct_0021B440_e0 {
    UnkStruct_0021B440_2 * field_0;
    unsigned char pad_4[0x4];
};

struct UnkStruct_0021B440_2 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18(CGtCamera *, float);
};

class CGtCamera {
public:
    void Update(float p0);

    unsigned char pad_0[0x34];
    UnkStruct_0021B440_e0 * field_34;
    int field_38;
};

// 0x0021B440
void CGtCamera::Update(float p0)
{
    for (int i = 0; (i < field_38); i++) {
        field_34[i].field_0->vfunc_18(this, p0);
    }
}
