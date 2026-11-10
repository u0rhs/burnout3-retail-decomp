// CGtInputManagerPS2Pad2::Construct(bool) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtInputManagerPS2Pad2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (local sock struct copy from D_0049B080; sock.field_4=1 for 2nd pad).

struct UnkStruct_00214B70_sock {
    int field_0;
    int field_4;
    int field_8;
    int field_C;
    char field_10[16];
};
extern UnkStruct_00214B70_sock D_0049B080;
extern "C" void *memset(void *, int, unsigned long);
extern "C" int sceDbcInit();
extern "C" int scePad2Init(int);
extern "C" int scePad2CreateSocket(void *, void *);

class CGtInputManagerPS2Pad2 {
public:
    void Construct(bool p0);

    unsigned char pad_0[0x200];
    int field_200[2];
    int field_208;
    unsigned char field_20C;
    unsigned char pad_20D[3];
    int field_210[2];
    unsigned char field_218[2][32];
    int field_258[2];
    unsigned char field_260;
    unsigned char pad_261[3];
    int field_264;
};

// 0x00214B70
void CGtInputManagerPS2Pad2::Construct(bool p0)
{
    UnkStruct_00214B70_sock sk = D_0049B080;
    for (int i = 0; i < 2; i++) {
        field_200[i] = 0;
    }
    field_208 = 0;
    field_20C = 0;
    field_260 = p0;
    for (int j = 0; j < 2; j++) {
        field_210[j] = 0;
        memset(field_218[j], 0, 0x20);
    }
    sceDbcInit();
    scePad2Init(0);
    field_258[0] = scePad2CreateSocket(&sk, this);
    if (field_260 != 0) {
        field_258[1] = -1;
    } else {
        sk.field_4 = 1;
        field_258[1] = scePad2CreateSocket(&sk, (char *)this + 0x100);
    }
    field_264 = -1;
}
