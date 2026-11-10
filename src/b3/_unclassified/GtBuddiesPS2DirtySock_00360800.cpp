// CGtBuddiesPS2DirtySock::Connect(char*,char*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtBuddiesPS2DirtySock.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (extra a3/t0 args (snprintf user:pass)).

struct UnkStruct_Conn { 
    unsigned char pad_0[0xCC];
    unsigned char field_CC;
    unsigned char pad_CD[0x4B];
    int field_118;
    unsigned char pad_11C[4];
    unsigned char field_120;
    unsigned char pad_121;
    signed char field_122;
};
struct UnkStruct_D_C { unsigned char pad_0[0x10]; };
extern UnkStruct_D_C D_004C7370;
extern UnkStruct_D_C D_004C7378;
extern UnkStruct_D_C D_004C7388;
extern UnkStruct_D_C D_004C7218;
extern int D_004C7270[];
extern "C" int snprintf(char *, unsigned int, const char *, ...);
extern "C" void HLBApiInitialize(int, void *, int, int);
extern "C" int HLBApiConnect(int, char *, char *, char *, void *);
extern "C" int ConvertHLBError__22CGtBuddiesPS2DirtySockFi(void *, int);
extern "C" int Connect__22CGtBuddiesPS2DirtySockFPcPc(UnkStruct_Conn *self, char *p1, char *p2, char *p3, char *p4)
{
    char buf[0x80];
    if (self->field_120 != 0) return 0;
    if (*p4 != 0) {
        snprintf(buf, 0x80, (char *)&D_004C7370, p3, p4);
    } else {
        snprintf(buf, 0x80, (char *)&D_004C7388, p3);
    }
    self->field_CC = 1;
    HLBApiInitialize(self->field_118, &D_004C7378, 0x62726E35, D_004C7270[self->field_122]);
    return ConvertHLBError__22CGtBuddiesPS2DirtySockFi(self, HLBApiConnect(self->field_118, p1, p2, buf, &D_004C7218));
}
