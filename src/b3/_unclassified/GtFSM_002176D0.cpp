// CGtFSM::ApplyEvent(unsigned int,void*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtFSM.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CGtFSM;
struct UnkStruct_002176D0_1;

struct UnkStruct_002176D0_1 {
    unsigned char pad_0[0xC];
    // vptr at +0xC: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8(int, int, unsigned int, void*);
};

class CGtFSM {
public:
    void ApplyEvent(unsigned int p0, void* p1);

    unsigned char pad_0[0x4];
    UnkStruct_002176D0_1 * field_4;
    int field_8;
};

// 0x002176D0
void CGtFSM::ApplyEvent(unsigned int p0, void* p1)
{
    UnkStruct_002176D0_1 * t0 = field_4;
    if (t0 == 0) return;
    t0->vfunc_8(5, field_8, p0, p1);
}
