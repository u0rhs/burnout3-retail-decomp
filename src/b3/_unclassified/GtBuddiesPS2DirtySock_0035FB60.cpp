// CGtBuddiesPS2DirtySock::IsTemporaryBuddy(char*,bool*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> GtBuddiesPS2DirtySock.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (buddy handle typed void* (int gave inverted branch layout), early returns, phantom a2 arg dropped).

class CGtBuddiesPS2DirtySock {
public:
    int IsTemporaryBuddy(char* p0, bool* p1);
    unsigned char pad_0[0x118];
    int field_118;
};
extern "C" void *HLBListGetBuddyByName(int, char*);
extern "C" int func_00418FA8(void *);

// 0x0035FB60
int CGtBuddiesPS2DirtySock::IsTemporaryBuddy(char* p0, bool* p1)
{
    void *r0 = HLBListGetBuddyByName(field_118, p0);
    if (r0 != 0) {
        *p1 = (func_00418FA8(r0) == 1);
        return 0;
    }
    *p1 = 0;
    return 5;
}
