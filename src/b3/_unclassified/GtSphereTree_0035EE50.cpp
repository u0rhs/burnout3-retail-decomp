// CGtSphereTree::Init(int,int,CGtSphereTreeSphere*,float) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtSphereTree.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CGtSphereTreeSphere;

class CGtSphereTree;
struct UnkStruct_0035EE50_2;
struct UnkStruct_0035EE50_e0;

struct UnkStruct_0035EE50_e0 {
    unsigned char pad_0[0x10];
    int field_10;
    void * field_14;
    void * field_18;
    unsigned char pad_1C[0x8];
    int field_24;
    void * field_28;
    void * field_2C;
    unsigned char pad_30[0x10];
};

struct UnkStruct_0035EE50_2 {
    unsigned char pad_0[0x4];
    void * field_4;
};

class CGtSphereTree {
public:
    void Init(int p0, int p1, CGtSphereTreeSphere* p2, float p3);

    CGtSphereTree * field_0;
    CGtSphereTree * field_4;
    void * field_8;
    void * field_C;
    void * field_10;
    void * field_14;
    UnkStruct_0035EE50_2 * field_18;
    void * field_1C;
    float field_20;
    float field_24;
    float field_28;
    float field_2C;
    float field_30;
    int field_34;
    int field_38;
    int field_3C;
    UnkStruct_0035EE50_e0 * field_40;
};

// 0x0035EE50
void CGtSphereTree::Init(int p0, int p1, CGtSphereTreeSphere* p2, float p3)
{
    field_34 = p0;
    field_38 = p1;
    field_40 = (UnkStruct_0035EE50_e0 *)p2;
    field_20 = p3;
    field_24 = 300.0f;
    field_28 = 150.0f;
    field_2C = 75.0f;
    field_30 = 10.0f;
    field_8 = ((char *)this + 0x8);
    field_C = ((char *)this + 0x8);
    field_10 = ((char *)this + 0x10);
    field_14 = ((char *)this + 0x10);
    field_0 = this;
    field_4 = this;
    field_18 = (UnkStruct_0035EE50_2 *)((char *)this + 0x18);
    field_1C = ((char *)this + 0x18);
    field_3C = field_38;
    for (int i = 0; (i < field_38); i++) {
        UnkStruct_0035EE50_e0 * t0 = field_40;
        t0[i].field_24 = 0;
        t0[i].field_10 = 0;
        t0[i].field_28 = ((char *)&t0[i] + 0x28);
        t0[i].field_2C = ((char *)&t0[i] + 0x28);
        t0[i].field_14 = (void *)field_18;
        t0[i].field_18 = ((char *)this + 0x18);
        field_18->field_4 = ((char *)&t0[i] + 0x14);
        field_18 = (UnkStruct_0035EE50_2 *)((char *)&t0[i] + 0x14);
    }
}
