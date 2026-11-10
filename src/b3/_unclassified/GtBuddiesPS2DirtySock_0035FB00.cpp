// CGtBuddiesPS2DirtySock::IsPermanentBuddy(char*,bool*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtBuddiesPS2DirtySock.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (drop phantom a2; pointer return type; early-return shape (as sibling IsBuddyIgnored)).

// CGtBuddiesPS2DirtySock::IsPermanentBuddy(char*,bool*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtBuddiesPS2DirtySock.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CGtBuddiesPS2DirtySock;

class CGtBuddiesPS2DirtySock {
public:
    int IsPermanentBuddy(char* p0, bool* p1);

    unsigned char pad_0[0x118];
    int field_118;
};

struct UnkStruct_0035FB00_0;
extern "C" UnkStruct_0035FB00_0 *HLBListGetBuddyByName(int, char*);  // [C] a2 not read (as GetBuddyByName in IsBuddyIgnored)
extern "C" int func_004190A8(UnkStruct_0035FB00_0 *);

// 0x0035FB00
int CGtBuddiesPS2DirtySock::IsPermanentBuddy(char* p0, bool* p1)
{
    UnkStruct_0035FB00_0 *r0 = HLBListGetBuddyByName(field_118, p0);
    if (r0 != 0) {
        *p1 = (func_004190A8(r0) == 1);
        return 0;
    }
    *p1 = false;
    return 5;
}
