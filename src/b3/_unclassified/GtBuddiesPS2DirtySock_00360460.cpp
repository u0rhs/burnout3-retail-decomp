// CGtBuddiesPS2DirtySock::IsBuddyIgnored(char*,bool*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtBuddiesPS2DirtySock.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (HLBListGetBuddyByName returns a pointer (int return inverted the branch layout); phantom a2 dropped; early returns).

// CGtBuddiesPS2DirtySock::IsBuddyIgnored(char*,bool*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtBuddiesPS2DirtySock.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CGtBuddiesPS2DirtySock;

class CGtBuddiesPS2DirtySock {
public:
    int IsBuddyIgnored(char* p0, bool* p1);

    unsigned char pad_0[0x118];
    int field_118;
};

struct UnkStruct_00360460_0;
extern "C" UnkStruct_00360460_0 *HLBListGetBuddyByName(int, char*);  // [C] a2 not read (dirtysock.s: only a0/a1 used)
extern "C" int HLBBudIsBlocked(UnkStruct_00360460_0 *);

// 0x00360460
int CGtBuddiesPS2DirtySock::IsBuddyIgnored(char* p0, bool* p1)
{
    UnkStruct_00360460_0 *r0 = HLBListGetBuddyByName(field_118, p0);
    if (r0 != 0) {
        *p1 = (HLBBudIsBlocked(r0) == 1);
        return 0;
    }
    *p1 = false;
    return 5;
}
