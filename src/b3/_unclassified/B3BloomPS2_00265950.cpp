// CB3Bloom::SetRenderstates() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3BloomPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (GIF quads into *p++, zero half assigned just before first use).

// CB3Bloom::SetRenderstates() -- hand-matched (gif3).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3BloomPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Field names are placeholders and every type is [G].
// GIF quads (N175): one pcpyld asm per quad straight into *p++ (lo-first), the packet pointer written back once;
// the shared zero half is an unsigned long assigned just before its first use (one daddu, kept in a2).

typedef unsigned int u_long128 __attribute__((mode(TI)));

struct UnkStruct_farFogPlane {
    u_long128 * field_0;
};

class CB3Bloom {
public:
    void SetRenderstates();
};

extern UnkStruct_farFogPlane farFogPlane;

// 0x00265950
void CB3Bloom::SetRenderstates()
{
    u_long128 *p = farFogPlane.field_0;
    unsigned long z;
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0x1000000000000004UL), "r"(14));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0x7FF000007FF0000UL), "r"(64));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0x7FF000007FF0000UL), "r"(65));
    z = 0;
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(z), "r"(24));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(z), "r"(25));
    farFogPlane.field_0 = p;
}
