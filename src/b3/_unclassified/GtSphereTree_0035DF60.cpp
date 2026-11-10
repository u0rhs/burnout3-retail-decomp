// CGtSphereTree::Update() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtSphereTree.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (list drain loops).

struct UnkStruct_Upd_n { UnkStruct_Upd_n *field_0; UnkStruct_Upd_n *field_4; };
struct RwLinkList;
struct CGtSphereTreeSphere { unsigned char pad_0[0x14]; };
class CGtSphereTree {
public:
    void Update();
    void Integrate(CGtSphereTreeSphere *, RwLinkList *, CGtSphereTreeSphere *, int);
    void Recompute(CGtSphereTreeSphere *);
    unsigned char pad_0[0x8];
    UnkStruct_Upd_n field_8;
    UnkStruct_Upd_n field_10;
    unsigned char pad_18[0x1C];
    int field_34;
    int field_38;
    int field_3C;
};
// 0x0035DF60
void CGtSphereTree::Update()
{
    UnkStruct_Upd_n *n = field_8.field_4;
    while (n != &field_8) {
        CGtSphereTreeSphere *s = (CGtSphereTreeSphere *)((char *)n - 0x14);
        if (field_3C < field_34) break;
        n->field_4->field_0 = n->field_0;
        n->field_0->field_4 = n->field_4;
        Integrate(0, (RwLinkList *)this, s, 1);
        n = field_8.field_4;
    }
    UnkStruct_Upd_n *m = field_10.field_4;
    while (m != &field_10) {
        Recompute((CGtSphereTreeSphere *)((char *)m - 0x1C));
        m->field_4->field_0 = m->field_0;
        m->field_0->field_4 = m->field_4;
        m->field_4 = 0;
        m->field_0 = 0;
        m = field_10.field_4;
    }
}
