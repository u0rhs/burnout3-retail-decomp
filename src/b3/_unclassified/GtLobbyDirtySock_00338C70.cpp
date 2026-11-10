// CGtLobbyPS2DirtySock::BroadcastArbitaryMessage(void*,int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtLobbyDirtySock.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (buf2 declared before buf1).

class CGtLobbyPS2DirtySock {
public:
    void BroadcastArbitaryMessage(void* p0, int p1);
    unsigned char pad_0[0x104];
    int field_104;
};
struct UnkStruct_D_004E2DAC { unsigned char * field_0; };
struct UnkStruct_D_004C5978 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_004C5980 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_004C5998 { unsigned char pad_0[0x10]; };
extern UnkStruct_D_004E2DAC D_004E2DAC;
extern UnkStruct_D_004C5978 D_004C5978;
extern UnkStruct_D_004C5980 D_004C5980;
extern UnkStruct_D_004C5998 D_004C5998;
extern "C" int sprintf(char *, const void *, ...);
extern "C" char * strcat(char *, const char *);
extern "C" void TagFieldSetString(unsigned char *, int, void *, char *);
extern "C" void TagFieldSetFlags(unsigned char *, int, void *, int);
extern "C" void LobbyApiRequestCB(int, int, unsigned char *, void *, int);

// 0x00338C70
void CGtLobbyPS2DirtySock::BroadcastArbitaryMessage(void* p0, int p1)
{
    char buf2[16];
    char buf1[400];
    char * p = (char *)p0;
    D_004E2DAC.field_0[0] = 0;
    buf1[0] = 0;
    sprintf(buf1, &D_004C5998);
    for (int i = 0; i < p1; i++) {
        sprintf(buf2, &D_004C5998, *p);
        strcat(buf1, buf2);
        p++;
    }
    TagFieldSetString(D_004E2DAC.field_0, 1024, &D_004C5978, buf1);
    TagFieldSetFlags(D_004E2DAC.field_0, 1024, &D_004C5980, 0x8004080);
    LobbyApiRequestCB(field_104, 0x6D657367, D_004E2DAC.field_0, 0, 0);
}
