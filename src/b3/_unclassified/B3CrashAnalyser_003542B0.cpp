// CB3CrashAnalyser::GetMostInterestingChild(CGtSphereTreeSphere*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3CrashAnalyser.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (recursive max-by-float over intrusive list).

struct UnkStruct_sph_d { unsigned char pad_0[0x60]; float field_60; };
struct UnkStruct_sph_l { UnkStruct_sph_l *field_0; };
struct CGtSphereTreeSphere {
    unsigned char pad_0[0x24];
    void *field_24;
    UnkStruct_sph_l field_28;
    unsigned char pad_2C[8];
    CGtSphereTreeSphere *field_34;
    unsigned char pad_38[0x28];
    float field_60;
};
class CB3CrashAnalyser {
public:
    CGtSphereTreeSphere *GetMostInterestingChild(CGtSphereTreeSphere *);
};
// 0x003542B0
CGtSphereTreeSphere *CB3CrashAnalyser::GetMostInterestingChild(CGtSphereTreeSphere *n)
{
    if (n->field_24 != 0) {
        CGtSphereTreeSphere *best = 0;
        float bf = 0.0f;
        UnkStruct_sph_l *p = n->field_28.field_0;
        while (p != &n->field_28) {
            CGtSphereTreeSphere *c = (CGtSphereTreeSphere *)((char *)p - 0x14);
            p = p->field_0;
            CGtSphereTreeSphere *r = GetMostInterestingChild(c);
            float f = r->field_60;
            if (f > bf) { best = r; bf = f; }
        }
        return best;
    }
    return n->field_34;
}
