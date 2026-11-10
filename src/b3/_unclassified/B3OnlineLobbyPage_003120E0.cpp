// CB3OnlineLobbyPage::GetCarClass(unsigned long) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3OnlineLobbyPage.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (else-if strncmp chain, uninit r).

class CB3OnlineLobbyPage { public: int GetCarClass(unsigned long); };
extern "C" void func_0021ADF0(unsigned long, char *);
extern "C" int strncmp(const char *, const char *, unsigned int);
struct UnkStruct_D_004C4A80 { const char *field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_004C4A80 D_004C4A80;
struct UnkStruct_D_004C4A84 { const char *field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_004C4A84 D_004C4A84;
struct UnkStruct_D_004C4A88 { const char *field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_004C4A88 D_004C4A88;
struct UnkStruct_D_004C4A8C { const char *field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_004C4A8C D_004C4A8C;
struct UnkStruct_D_004C4A90 { const char *field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_004C4A90 D_004C4A90;
struct UnkStruct_D_004C4A94 { const char *field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_004C4A94 D_004C4A94;
struct UnkStruct_D_004C4A98 { const char *field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_004C4A98 D_004C4A98;
// 0x003120E0
int CB3OnlineLobbyPage::GetCarClass(unsigned long id)
{
    char buf[16];
    int r;
    func_0021ADF0(id, buf);
    if (strncmp(buf, D_004C4A80.field_0, 4) == 0) {
        r = 0;
    }
    else if (strncmp(buf, D_004C4A84.field_0, 4) == 0) {
        r = 1;
    }
    else if (strncmp(buf, D_004C4A88.field_0, 4) == 0) {
        r = 2;
    }
    else if (strncmp(buf, D_004C4A8C.field_0, 4) == 0) {
        r = 3;
    }
    else if (strncmp(buf, D_004C4A90.field_0, 4) == 0) {
        r = 4;
    }
    else if (strncmp(buf, D_004C4A94.field_0, 4) == 0) {
        r = 5;
    }
    else if (strncmp(buf, D_004C4A98.field_0, 4) == 0) {
        r = 6;
    }
    return r;
}
