// CGtBuddiesPS2DirtySock::GetFoundBuddyName(int,char*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtBuddiesPS2DirtySock.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (drop phantom 3rd arg of func_00418E60, returns char*).

// CGtBuddiesPS2DirtySock::GetFoundBuddyName(int,char*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtBuddiesPS2DirtySock.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CGtBuddiesPS2DirtySock;

class CGtBuddiesPS2DirtySock {
public:
    int GetFoundBuddyName(int p0, char* p1);

    unsigned char pad_0[0x118];
    int field_118;
};

extern "C" char * strncpy(char *, const char *, unsigned int);
extern "C" char *func_00418E60(int, int);

// 0x00360620
int CGtBuddiesPS2DirtySock::GetFoundBuddyName(int p0, char* p1)
{
    char *r0 = func_00418E60(field_118, p0);
    if (r0 != 0) {
        strncpy(p1, r0, 16);
        return 0;
    }
    return 5;
}
