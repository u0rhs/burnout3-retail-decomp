// CGtBuddiesPS2DirtySock::IsNewMailAvailable() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtBuddiesPS2DirtySock.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (early return on field_120; for-loop over HLBListGetBuddyByIndex returning a pointer).

// CGtBuddiesPS2DirtySock::IsNewMailAvailable() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtBuddiesPS2DirtySock.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CGtBuddiesPS2DirtySock;

class CGtBuddiesPS2DirtySock {
public:
    int IsNewMailAvailable();

    unsigned char pad_0[0x118];
    int field_118;
    unsigned char pad_11C[0x4];
    unsigned char field_120;
};

extern "C" void *HLBListGetBuddyByIndex(int, int);
extern "C" int HLBMsgListGetTotalCount(void *);

// 0x0035F700
int CGtBuddiesPS2DirtySock::IsNewMailAvailable()
{
    if (field_120 == 0) {
        return 0;
    }
    int i = 0;
    for (void *p = HLBListGetBuddyByIndex(field_118, i); p != 0; p = HLBListGetBuddyByIndex(field_118, ++i)) {
        if (HLBMsgListGetTotalCount(p) > 0) {
            return 1;
        }
    }
    return 0;
}
