// CGtLobbyPS2DirtySock::AmIHost() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtLobbyDirtySock.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CGtLobbyPS2DirtySock;

class CGtLobbyPS2DirtySock {
public:
    int AmIHost();

    unsigned char pad_0[0x134];
    int field_134;
};

extern "C" int strcasecmp(int, void *);

// 0x00337AD0
int CGtLobbyPS2DirtySock::AmIHost()
{
    int r0 = strcasecmp((field_134 + 56), ((char *)this + 0x4A4));
    return ((r0 != 0) ^ 1);
}
