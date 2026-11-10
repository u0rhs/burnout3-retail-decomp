// CGtLobbyPS2DirtySock::GetRankingData(int,int,char*,int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtLobbyDirtySock.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (|| merged, ==0?1:2 gives movn).

class CGtLobbyPS2DirtySock {
public:
    int GetRankingData(int p0, int p1, char* p2, int p3);
    unsigned char pad_0[0x61C];
    void * field_61C;
};
extern "C" int func_0040D730(void *);
extern "C" int func_0040D7A0(void *, int, int, char *, int);

// 0x00336950
int CGtLobbyPS2DirtySock::GetRankingData(int p0, int p1, char* p2, int p3)
{
    if (p0 < 0 || p0 >= func_0040D730(field_61C)) return 1;
    return func_0040D7A0(field_61C, p1, p0, p2, p3) == 0 ? 1 : 2;
}
