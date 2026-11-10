// CGtLobbyPS2DirtySock::GetHostPlayerID() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtLobbyDirtySock.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a76: plain find loop, -1 default).

// [C] name CGtLobbyPS2DirtySock::GetHostPlayerID() (mangled symbol); host name at lobby+0x38 matched against the player table (+0x1C0, stride 100), -1 if absent; layout [G]. No DNAT row.
struct UnkStruct_00338B40_ent {
    int field_0;
    char field_4[96];
};

struct UnkStruct_00338B40_lobby {
    unsigned char pad_0[0x38];
    char field_38[1];
    unsigned char pad_39[0x1BC - 0x39];
    int field_1BC;
    UnkStruct_00338B40_ent field_1C0[1];
};

class CGtLobbyPS2DirtySock {
public:
    int GetHostPlayerID();
    unsigned char pad_0[0x134];
    UnkStruct_00338B40_lobby * field_134;
};

extern "C" int strcasecmp(const char *, const char *);

// 0x00338B40
int CGtLobbyPS2DirtySock::GetHostPlayerID()
{
    for (int i = 0; i < field_134->field_1BC; i++) {
        if (strcasecmp(field_134->field_38, field_134->field_1C0[i].field_4) == 0) {
            return field_134->field_1C0[i].field_0;
        }
    }
    return -1;
}
