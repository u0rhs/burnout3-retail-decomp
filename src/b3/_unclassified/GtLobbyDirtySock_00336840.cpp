// CGtLobbyPS2DirtySock::GetUserRankingData(int,char*,int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtLobbyDirtySock.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (two inlines: func_003367B0's find loop, then GetRankingData's body with idx < 0 || idx >= count merged into one return 1).

// CGtLobbyPS2DirtySock::GetUserRankingData(int,char*,int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtLobbyDirtySock.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CGtLobbyPS2DirtySock;
struct UnkStruct_00336840_1;

struct UnkStruct_00336840_1 {
    int field_0;
};

class CGtLobbyPS2DirtySock {
public:
    int GetUserRankingData(int p0, char* p1, int p2);

    unsigned char pad_0[0x61C];
    int field_61C;
};

extern "C" int func_0040D730(int);
extern "C" int func_0040D698(int, int, UnkStruct_00336840_1 *);
extern "C" int func_0040D7A0(int, int, int, char*, int);

// [L] func_003367B0's body (the same loop, out of line at 0x3367B0), inlined here.
static inline int func_003367B0_inl1(CGtLobbyPS2DirtySock * self)
{
    UnkStruct_00336840_1 local;
    for (int i = 0; i < func_0040D730(self->field_61C); i++) {
        if (func_0040D698(self->field_61C, i, &local) != 0) {
            return -1;
        }
        if ((local.field_0 & 1) != 0) {
            return i;
        }
    }
    return -1;
}

// [L] CGtLobbyPS2DirtySock::GetRankingData(int,int,char*,int)'s body (out of line at 0x336950), inlined here.
static inline int func_00336950_inl2(CGtLobbyPS2DirtySock * self, int idx, int p0, char * p1, int p2)
{
    if (idx < 0 || idx >= func_0040D730(self->field_61C)) return 1;
    if (func_0040D7A0(self->field_61C, p0, idx, p1, p2) != 0) return 2;
    return 1;
}

// 0x00336840
int CGtLobbyPS2DirtySock::GetUserRankingData(int p0, char* p1, int p2)
{
    int idx = func_003367B0_inl1(this);
    if (idx == -1) return 1;
    return func_00336950_inl2(this, idx, p0, p1, p2);
}
