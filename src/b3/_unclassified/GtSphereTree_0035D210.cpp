// CGtSphereTree::AddToRecomputeList(CGtSphereTreeSphere*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtSphereTree.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CGtSphereTreeSphere;

class CGtSphereTree;
struct CGtSphereTreeSphere;
struct UnkStruct_0035D210_2;

struct CGtSphereTreeSphere {
    unsigned char pad_0[0x1C];
    void * field_1C;
    void * field_20;
};

struct UnkStruct_0035D210_2 {
    unsigned char pad_0[0x4];
    void * field_4;
};

class CGtSphereTree {
public:
    void AddToRecomputeList(CGtSphereTreeSphere* p0);

    unsigned char pad_0[0x10];
    UnkStruct_0035D210_2 * field_10;
};

// 0x0035D210
void CGtSphereTree::AddToRecomputeList(CGtSphereTreeSphere* p0)
{
    if (p0->field_1C == 0) {
        p0->field_1C = (void *)field_10;
        p0->field_20 = ((char *)this + 0x10);
        field_10->field_4 = ((char *)p0 + 0x1C);
        field_10 = (UnkStruct_0035D210_2 *)((char *)p0 + 0x1C);
    }
}
