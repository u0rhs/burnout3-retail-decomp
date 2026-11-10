// CGtBuddiesPS2DirtySock::IsWannaBeMyBuddy(char*,bool*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtBuddiesPS2DirtySock.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (drop phantom 3rd arg; HLBListGetBuddyByName returns a pointer (int return flips the branch)).

// CGtBuddiesPS2DirtySock::IsWannaBeMyBuddy(char*,bool*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtBuddiesPS2DirtySock.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CGtBuddiesPS2DirtySock;

class CGtBuddiesPS2DirtySock {
public:
    int IsWannaBeMyBuddy(char* p0, bool* p1);

    unsigned char pad_0[0x118];
    int field_118;
};

extern "C" void *HLBListGetBuddyByName(int, char*);
extern "C" int func_00419048(void *);

// 0x0035FAA0
int CGtBuddiesPS2DirtySock::IsWannaBeMyBuddy(char* p0, bool* p1)
{
    void *r0 = HLBListGetBuddyByName(field_118, p0);
    if (r0 != 0) {
        *p1 = func_00419048(r0) == 1;
        return 0;
    }
    *p1 = 0;
    return 5;
}
