// CGtLobbyPS2DirtySock::GetNumGamesInCurrentLobby() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtLobbyDirtySock.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (early-return shape: if (field) return call(field); return 0;).

// CGtLobbyPS2DirtySock::GetNumGamesInCurrentLobby() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtLobbyDirtySock.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CGtLobbyPS2DirtySock;

class CGtLobbyPS2DirtySock {
public:
    int GetNumGamesInCurrentLobby();

    unsigned char pad_0[0x564];
    int field_564;
};

extern "C" int DispListCount(int);

// 0x00339A60
int CGtLobbyPS2DirtySock::GetNumGamesInCurrentLobby()
{
    if (field_564 != 0) {
        return DispListCount(field_564);
    }
    return 0;
}
