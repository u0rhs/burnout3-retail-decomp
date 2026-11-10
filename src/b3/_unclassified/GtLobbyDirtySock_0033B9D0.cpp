// CGtLobbyPS2DirtySock::CheckForPlayerKicked() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtLobbyDirtySock.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (a67: block form (&& nest, single return 0), bool found with plain tests, players-row loop).

class CGtLobbyPS2DirtySock;
struct UnkStruct_0033B9D0_1;

struct UnkStruct_0033B9D0_row {
    unsigned char pad_0[0x4];
    char field_4[0x60];
};

struct UnkStruct_0033B9D0_1 {
    unsigned char pad_0[0x1BC];
    int field_1BC;
    UnkStruct_0033B9D0_row field_1C0[1];  // [G] element count unknown
};

class CGtLobbyPS2DirtySock {
public:
    int CheckForPlayerKicked();

    unsigned char pad_0[0x11C];
    unsigned char field_11C;
    unsigned char field_11D;
    unsigned char pad_11E[0xE];
    int field_12C;
    unsigned char pad_130[0x4];
    UnkStruct_0033B9D0_1 * field_134;
    unsigned char pad_138[0x30C];
    unsigned char field_444;
    unsigned char pad_445[0x5F];
    char field_4A4[0x20];
    unsigned char pad_4C4[0x8C];
    void (*field_550)(int, int);
    int field_554;
    void (*field_558)(int, int);
    int field_55C;
    unsigned char pad_560[0xEA];
    unsigned char field_64A;
};

extern "C" int strcasecmp(const char *, const char *);

// 0x0033B9D0
int CGtLobbyPS2DirtySock::CheckForPlayerKicked()
{
    if (field_11C != 0 && field_11D != 0) {
        bool found = false;
        int i = 0;
        for (; i < field_134->field_1BC && !found; i++) {
            if (strcasecmp(field_134->field_1C0[i].field_4, field_4A4) == 0) {
                found = true;
            }
        }
        if (!found) {
            field_11C = 0;
            field_11D = 0;
            field_12C = -1;
            field_134 = 0;
            field_444 = 0;
            if (field_64A != 0) {
                field_558(3, field_55C);
                field_64A = 0;
            } else {
                field_558(0, field_55C);
                field_64A = 0;
            }
            return 1;
        }
    }
    return 0;
}
