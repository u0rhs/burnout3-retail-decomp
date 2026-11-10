// CGtBuddiesPS2DirtySock::GetBuddyName(int,char*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtBuddiesPS2DirtySock.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (drop phantom a2 arg; pointer return types for HLBListGetBuddyByIndex/HLBBudGetName (int returns flip block order)).

// CGtBuddiesPS2DirtySock::GetBuddyName(int,char*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtBuddiesPS2DirtySock.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CGtBuddiesPS2DirtySock;

class CGtBuddiesPS2DirtySock {
public:
    int GetBuddyName(int p0, char* p1);

    unsigned char pad_0[0x118];
    int field_118;
};

extern "C" char * strncpy(char *, const char *, unsigned int);
struct UnkStruct_00360670_0;
extern "C" UnkStruct_00360670_0 *HLBListGetBuddyByIndex(int, int);
extern "C" char *HLBBudGetName(UnkStruct_00360670_0 *);

// 0x00360670
int CGtBuddiesPS2DirtySock::GetBuddyName(int p0, char* p1)
{
    UnkStruct_00360670_0 *r0 = HLBListGetBuddyByIndex(field_118, p0);
    if (r0 != 0) {
        strncpy(p1, HLBBudGetName(r0), 16);
        return 0;
    }
    return 5;
}
