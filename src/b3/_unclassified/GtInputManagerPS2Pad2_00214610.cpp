// CGtInputManagerPS2Pad2::UpdatePort(EGtPS2InputPort) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtInputManagerPS2Pad2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (sock struct copy, prof 16B struct declared first, if(<= -1) create else if/else-if state).

struct UnkStruct_00214610_sock {
    int field_0;
    int field_4;
    int field_8;
    int field_C;
    char field_10[16];
};
extern UnkStruct_00214610_sock D_0049B0A0;
enum EGtPS2InputPort {};
extern "C" int scePad2GetState(int);
extern "C" int scePad2CreateSocket(void *, void *);
extern "C" void scePad2DeleteSocket(int);
extern "C" int scePad2GetButtonProfile(int, void *);
extern "C" void scePad2Read(int, void *);

struct UnkStruct_00214610_prof {
    int field_0;
    int field_4;
    int field_8;
    int field_C;
};

class CGtInputManagerPS2Pad2 {
public:
    void UpdatePort(EGtPS2InputPort p0);

    unsigned char pad_0[0x210];
    int field_210[2];
    unsigned char field_218[2][32];
    int field_258[2];
};

// 0x00214610
void CGtInputManagerPS2Pad2::UpdatePort(EGtPS2InputPort p0)
{
    UnkStruct_00214610_prof prof;
    UnkStruct_00214610_sock sk = D_0049B0A0;
    switch (p0) {
    case 0:
        sk.field_4 = 0;
        break;
    case 1:
        sk.field_4 = 1;
        break;
    default:
        return;
    }
    if (field_258[p0] <= -1) {
        field_258[p0] = scePad2CreateSocket(&sk, (char *)this + p0 * 256);
    } else {
        int st = scePad2GetState(field_258[p0]);
        if (st == 1) {
            if (field_210[p0] == 0) {
                if (scePad2GetButtonProfile(field_258[p0], &prof) > 0) {
                    if (prof.field_0 == -1) {
                        field_210[p0] = 4;
                    } else if (prof.field_0 == (int)0xFFFF0F00) {
                        field_210[p0] = 3;
                    }
                }
            } else {
                scePad2Read(field_258[p0], field_218[p0]);
            }
        } else if (st == 0) {
            scePad2DeleteSocket(field_258[p0]);
            field_258[p0] = -1;
            field_210[p0] = 0;
        }
    }
}
