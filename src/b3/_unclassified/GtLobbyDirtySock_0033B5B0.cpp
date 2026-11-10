// CGtLobbyPS2DirtySock::CheckGameAttribsHaveArrived() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtLobbyDirtySock.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a66: two find loops with for(;;j++){ if(!(cond)||found) break; } shape; bool found (daddiu) declared after int j; j declared before found gives s0=found/s1=j; game record names stride 100 at +0x1C4).

// CGtLobbyPS2DirtySock::CheckGameAttribsHaveArrived() -- hand-matched (a66).
// [C] name: the mangled symbol in retail's tables; sibling CheckGameStillExists() is in GtLobbyDirtySock.cpp.
class CGtLobbyPS2DirtySock;

struct UnkStruct_0033B4B0_g {
    unsigned char pad_0[0x1BC];
    int field_1BC;
    unsigned char pad_1C0[0x4];
    char field_1C4[100];  // [G] stride 100: names compared with strcasecmp
};

struct UnkStruct_0033B4B0_n {
    int field_0;
};

class CGtLobbyPS2DirtySock {
public:
    int CheckGameAttribsHaveArrived();

    unsigned char pad_0[0x104];
    int field_104;
    unsigned char pad_108[0x9];
    unsigned char field_111;
    unsigned char pad_112[0xB];
    unsigned char field_11D;
    unsigned char pad_11E[0x3];
    unsigned char field_121;
    unsigned char pad_122[0x2];
    int field_124;
    int field_128;
    int field_12C;
    int field_130;
    UnkStruct_0033B4B0_g * field_134;
    unsigned char pad_138[0x36C];
    char field_4A4[1];  // [G] length unknown
    unsigned char pad_4A5[0xBF];
    int field_564;
};

extern "C" void DispListOrder(int);
extern "C" int DispListCount(int);
extern "C" UnkStruct_0033B4B0_n * DispListIndex(int, int);
extern "C" int strcasecmp(const char *, const char *);
extern "C" void LobbyApiDisconnect(int, int);

// 0x0033B5B0
int CGtLobbyPS2DirtySock::CheckGameAttribsHaveArrived()
{
    field_128++;
    if (field_128 >= 601) {
        LobbyApiDisconnect(field_104, 0);
        return 0;
    }
    DispListOrder(field_564);
    if (field_134 == 0) {
        for (int i = 0; ; i++) {
            if (!(i < DispListCount(field_564)) || field_134 != 0) {
                break;
            }
            UnkStruct_0033B4B0_n * r = DispListIndex(field_564, i);
            if (r->field_0 == field_12C) {
                field_134 = (UnkStruct_0033B4B0_g *)r;
            }
        }
        if (field_134 == 0) {
            return 0;
        }
    }
    int j;
    bool found = false;
    for (j = 0; ; j++) {
        if (!(j < field_134->field_1BC) || found) {
            break;
        }
        if (strcasecmp(field_134->field_1C4 + j * 100, field_4A4) == 0) {
            field_11D = 1;
            found = true;
        }
    }
    if (!found) {
        return 0;
    }
    field_111 = 1;
    field_121 = 1;
    field_124 = 0;
    field_130 = 0;
    return 1;
}
