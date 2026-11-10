// CGtLobbyPS2DirtySock::PrepareRanking(char*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> GtLobbyDirtySock.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CGtLobbyPS2DirtySock;

class CGtLobbyPS2DirtySock {
public:
    int PrepareRanking(char* p0);

    unsigned char pad_0[0x104];
    int field_104;
    unsigned char pad_108[0x8];
    unsigned char field_110;
    unsigned char field_111;
    unsigned char field_112;
    unsigned char pad_113[0x1];
    int field_114;
    unsigned char pad_118[0x8];
    unsigned char field_120;
    unsigned char pad_121[0x4FB];
    int field_61C;
};

extern "C" void _RankListDownloaded__20CGtLobbyPS2DirtySockFPQ29DirtySock12LobbyApiRefTPQ29DirtySock12LobbyApiMsgTPv(void *, void *, void*);  // CGtLobbyPS2DirtySock::_RankListDownloaded(DirtySock::LobbyApiRefT*,DirtySock::LobbyApiMsgT*,void*), its address taken
extern "C" int func_0040C748(int, int);
extern "C" void func_0040C8A8(int, char*, void *, CGtLobbyPS2DirtySock *);

// 0x00336EA0
int CGtLobbyPS2DirtySock::PrepareRanking(char* p0)
{
    int r0 = func_0040C748(field_104, 0);
    field_61C = r0;
    func_0040C8A8(field_61C, p0, (void *)&_RankListDownloaded__20CGtLobbyPS2DirtySockFPQ29DirtySock12LobbyApiRefTPQ29DirtySock12LobbyApiMsgTPv, this);
    field_110 = 1;
    field_111 = 0;
    field_112 = 0;
    field_120 = 0;
    field_114 = 0;
    return 1;
}
