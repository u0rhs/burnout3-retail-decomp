// CGtBuddiesPS2DirtySock::GetAndRemoveMail(char*,int,char*,char*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtBuddiesPS2DirtySock.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (six int out-params (frame 0x78); goto-form return-5 stubs + scoped opt_repositioncode off [G] (N182)).

// lifter variant 0
// CGtBuddiesPS2DirtySock::GetAndRemoveMail(char*,int,char*,char*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtBuddiesPS2DirtySock.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CGtBuddiesPS2DirtySock;
struct UnkStruct_0035FC00_1;
struct UnkStruct_0035FC00_2;
struct UnkStruct_D_004C72A0;
struct UnkStruct_D_004C72A8;
struct UnkStruct_D_004C72B8;
struct UnkStruct_D_004C72C0;

struct UnkStruct_0035FC00_1 {
    unsigned char pad_0[0x14];
    int field_14;
};

struct UnkStruct_0035FC00_2 {
    unsigned char pad_0[0xC];
    int field_C;
    int field_10;
    int field_14;
};

struct UnkStruct_D_004C72A0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004C72A8 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004C72B8 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004C72C0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CGtBuddiesPS2DirtySock {
public:
    int GetAndRemoveMail(char* p0, int p1, char* p2, char* p3);

    unsigned char pad_0[0x118];
    int field_118;
};

extern UnkStruct_D_004C72A0 D_004C72A0;
extern UnkStruct_D_004C72A8 D_004C72A8;
extern UnkStruct_D_004C72B8 D_004C72B8;
extern UnkStruct_D_004C72C0 D_004C72C0;

extern "C" int HLBListGetBuddyByName(int, char*, int, char*, char*);
extern "C" UnkStruct_0035FC00_1 * HLBMsgListGetMsgByIndex(int, int, int);
extern "C" int TagFieldFind(int, void *);
extern "C" int LobbyZone();
extern "C" void TagFieldGetDate(int, int *, int *, int *, int *, int *, int *, int);
extern "C" void snprintf(char*, int, void *, int, int, int);
extern "C" void TagFieldGetString(int, char*, int, void *);
extern "C" void HLBMsgListDelete(int, int);

// 0x0035FC00
// N182: `#pragma opt_repositioncode off` ([G] scoped to this function): with the goto-form exits it keeps
// retail's two out-of-line `return 5` stubs after the main return (L268).
#pragma push
#pragma opt_repositioncode off
int CGtBuddiesPS2DirtySock::GetAndRemoveMail(char* p0, int p1, char* p2, char* p3)
{
    int v14;
    int v10;
    int vC;
    int v8;
    int v4;
    int v0;
    UnkStruct_0035FC00_1 * r1;
    int r0 = HLBListGetBuddyByName(field_118, p0, p1, p2, p3);
    if (r0 == 0) goto f1;  // [G] goto: retail's return stubs sit after the main return
    r1 = HLBMsgListGetMsgByIndex(r0, p1, 1);
    if (r1 == 0) goto f2;
    {
            int r2 = TagFieldFind(r1->field_14, &D_004C72A0);
            int r3 = LobbyZone();
            TagFieldGetDate(r2, &v14, &v10, &vC, &v8, &v4, &v0, r3);
            snprintf(p3, 11, &D_004C72A8, vC, v10, v14);
            int r6 = TagFieldFind(r1->field_14, &D_004C72B8);
            TagFieldGetString(r6, p2, 200, &D_004C72C0);
            HLBMsgListDelete(r0, p1);
    }
    return 0;
f1:
    return 5;
f2:
    return 5;
}
#pragma pop
