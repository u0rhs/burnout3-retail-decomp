// CGtLobbyPS2DirtySock::GetOurPlayerID() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtLobbyDirtySock.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a76: plain find loop).

// [C] name CGtLobbyPS2DirtySock::GetOurPlayerID() (mangled symbol); player table at lobby+0x1C0, stride 100 {id, name[96]}, our name at +0x4A4; layout [G]. No DNAT row.
struct UnkStruct_00338AB0_ent {
    int field_0;
    char field_4[96];
};

struct UnkStruct_00338AB0_lobby {
    unsigned char pad_0[0x1BC];
    int field_1BC;
    UnkStruct_00338AB0_ent field_1C0[1];
};

class CGtLobbyPS2DirtySock {
public:
    int GetOurPlayerID();
    unsigned char pad_0[0x134];
    UnkStruct_00338AB0_lobby * field_134;
    unsigned char pad_138[0x4A4 - 0x138];
    char field_4A4[1];
};

extern "C" int strcasecmp(const char *, const char *);

// 0x00338AB0
int CGtLobbyPS2DirtySock::GetOurPlayerID()
{
    for (int i = 0; i < field_134->field_1BC; i++) {
        if (strcasecmp(field_4A4, field_134->field_1C0[i].field_4) == 0) {
            return field_134->field_1C0[i].field_0;
        }
    }
    return 0;
}
