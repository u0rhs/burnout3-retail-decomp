// CB3AILane::FindNoGo(unsigned short*,EAISegmentLinkType) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3AILane.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (1-byte struct local -> plain unsigned char local (struct local gets 4-byte alignment: sp+0x1C vs retail sp+0x1F)).

// from build/vt\try_FindNoGo__9CB3AILaneFPUs18EAISegmentLink_best.cpp
// CB3AILane::FindNoGo(unsigned short*,EAISegmentLinkType) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3AILane.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

enum EAISegmentLinkType {};

class CB3AILane;
struct UnkStruct_00146A70_0;
struct UnkStruct_00146A70_e0;
struct UnkStruct_D_00522660;

struct UnkStruct_00146A70_0 {
    unsigned char field_0;
};

struct UnkStruct_00146A70_e0 {
    unsigned char pad_0[0x8];
};

struct UnkStruct_D_00522660 {
    UnkStruct_00146A70_e0 field_0[1];  // [G] element count unknown
    unsigned char pad_8[0x8];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3AILane {
public:
    void * FindNoGo(unsigned short* p0, EAISegmentLinkType p1);
    void FindNoGo(unsigned short, EAISegmentLinkType, unsigned char*, unsigned short*, bool);

    int field_0;
};

extern UnkStruct_D_00522660 D_00522660;

// 0x00146A70
void * CB3AILane::FindNoGo(unsigned short* p0, EAISegmentLinkType p1)
{
    unsigned char local;
    local = field_0;
    FindNoGo(*p0, p1, &local, (unsigned short*)p0, 1);
    return ((char *)&D_00522660.field_0[local] + 0x2C);
}
