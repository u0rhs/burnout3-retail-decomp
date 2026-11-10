// CB3OnlineLobbyPage::SetPlayerName(int,char*,bool,bool) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3OnlineLobbyPage.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (const colour-table pointer; merged range guard with assignment in || (slti at/beqz); if/else-if on (i==field_4 && field_13AC==1), p2).

// lifter variant 0
// CB3OnlineLobbyPage::SetPlayerName(int,char*,bool,bool) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3OnlineLobbyPage.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

typedef unsigned int u_long128 __attribute__((mode(TI)));

class CB3OnlineLobbyPage;
struct UnkStruct_003139B0_e1;
struct UnkStruct_D_01E90240;
struct UnkStruct_kB3OnlineLobbyRagerTextColour;
struct UnkStruct_kB3OnlineLobbyRagerTextDisabledColour;
struct UnkStruct_kB3OnlineLobbyRagerTextSelectedColour;

struct UnkStruct_D_01E90240 {
    u_long128 field_0;
    u_long128 field_10;
    u_long128 field_20;
};

struct UnkStruct_003139B0_e1 {
    unsigned char pad_0[0x20];
    u_long128 field_20;
    unsigned char pad_30[0x20];
};

struct UnkStruct_kB3OnlineLobbyRagerTextColour {
    u_long128 field_0;
};

struct UnkStruct_kB3OnlineLobbyRagerTextDisabledColour {
    u_long128 field_0;
};

struct UnkStruct_kB3OnlineLobbyRagerTextSelectedColour {
    u_long128 field_0;
};

class CB3OnlineLobbyPage {
public:
    void SetPlayerName(int p0, char* p1, bool p2, bool p3);

    unsigned char pad_0[0x4];
    unsigned short field_4;
    unsigned char pad_6[0x36A];
    UnkStruct_003139B0_e1 field_370[1];  // [G] element count unknown
    unsigned char pad_3C0[0xF84];
    int field_1344[1];  // [G] element count unknown
    unsigned char pad_1348[0x48];
    int field_1390;
    unsigned char pad_1394[0x18];
    signed char field_13AC;
};

extern UnkStruct_D_01E90240 D_01E90240;
extern UnkStruct_kB3OnlineLobbyRagerTextColour kB3OnlineLobbyRagerTextColour;
extern UnkStruct_kB3OnlineLobbyRagerTextDisabledColour kB3OnlineLobbyRagerTextDisabledColour;
extern UnkStruct_kB3OnlineLobbyRagerTextSelectedColour kB3OnlineLobbyRagerTextSelectedColour;

extern "C" void ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(char*, int, int);

// 0x003139B0
void CB3OnlineLobbyPage::SetPlayerName(int p0, char* p1, bool p2, bool p3)
{
    UnkStruct_D_01E90240 * const cols = &D_01E90240;
    int i;
    if (p0 < field_1390 || (i = p0 - field_1390) > 5) {
        return;
    }
    ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(p1, field_1344[i], 16);
    if (i == field_4 && field_13AC == 1) {
        if (p3) {
            field_370[i].field_20 = kB3OnlineLobbyRagerTextSelectedColour.field_0;
        } else {
            field_370[i].field_20 = cols->field_10;
        }
    } else if (p2) {
        if (p3) {
            field_370[i].field_20 = kB3OnlineLobbyRagerTextDisabledColour.field_0;
        } else {
            field_370[i].field_20 = cols->field_20;
        }
    } else {
        if (p3) {
            field_370[i].field_20 = kB3OnlineLobbyRagerTextColour.field_0;
        } else {
            field_370[i].field_20 = cols->field_0;
        }
    }
}
