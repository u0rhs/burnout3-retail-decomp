// Hand-written; the lifter refused it (hand-written (lifter refused): DirtySock lobby callback like func_00338540; 4 stack buffers in declaration order; 9-entry parse loop).

class CGtLobbyPS2DirtySock;
struct UnkStruct_00338700_a1;
struct UnkStruct_00338700_a2;
struct UnkStruct_D_004C5850;
struct UnkStruct_D_004C5858;
struct UnkStruct_D_004C5968;
struct UnkStruct_D_004C5990;
struct UnkStruct_D_004C59C0;

class CGtLobbyPS2DirtySock {
public:
    static int ConvertDirtySockError(int);
};

struct UnkStruct_00338700_a1 {
    unsigned char pad_0[0xC];
    int field_C;
    int field_10;
};

struct UnkStruct_00338700_a2 {
    unsigned char pad_0[0x110];
    unsigned char field_110;
    unsigned char field_111;
    unsigned char field_112;
    unsigned char pad_113[0x1];
    int field_114;
    unsigned char pad_118[0x49C];
    int field_5B4;
    int field_5B8;
    char field_5BC[0x24];
    signed char field_5E0;
    unsigned char pad_5E1[0x3];
    int field_5E4;
};

struct UnkStruct_D_004C5850 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004C5858 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004C5968 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004C5990 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004C59C0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

extern UnkStruct_D_004C5850 D_004C5850;
extern UnkStruct_D_004C5858 D_004C5858;
extern UnkStruct_D_004C5968 D_004C5968;
extern UnkStruct_D_004C5990 D_004C5990;
extern UnkStruct_D_004C59C0 D_004C59C0;

extern "C" int TagFieldFind(int, void *);
extern "C" int TagFieldGetNumber(int, int);
extern "C" void TagFieldGetString(int, void *, int, void *);
extern "C" void * memset(void *, int, unsigned int);
extern "C" char * strcpy(char *, const char *);
extern "C" int atoi(const char *);
extern "C" unsigned int strlen(const char *);
extern "C" void func_00128BE8(char *, void *);

// 0x00338700
extern "C" void func_00338700(int n0, UnkStruct_00338700_a1 * p0, UnkStruct_00338700_a2 * p1)
{
    char name[0x24];
    char list[0x84];
    int vals[9];
    char tmp[0x90];
    if (p0->field_C != 0) {
        if (p1->field_5B4 != 0) {
            ((void (*)(int, char *, char *, signed char, int, int, int, int))p1->field_5B4)(0, 0, p1->field_5BC, p1->field_5E0, p1->field_5E4, 0, 0, p1->field_5B8);
            p1->field_5B4 = 0;
            p1->field_5B8 = 0;
        }
        int r = CGtLobbyPS2DirtySock::ConvertDirtySockError(p0->field_C);
        p1->field_112 = 1;
        p1->field_110 = 0;
        p1->field_114 = r;
    } else {
        TagFieldGetString(TagFieldFind(p0->field_10, &D_004C5850), name, 36, &D_004C5968);
        TagFieldGetString(TagFieldFind(p0->field_10, &D_004C59C0), list, 132, &D_004C5968);
        int flag = (TagFieldGetNumber(TagFieldFind(p0->field_10, &D_004C5858), 0) & 0x10000) != 0;
        memset(vals, 0, sizeof(vals));
        char * s = list;
        for (int i = 0; i < 9; i++) {
            strcpy(tmp, s);
            func_00128BE8(tmp, &D_004C5990);
            vals[i] = atoi(tmp);
            s += strlen(tmp) + 1;
        }
        p1->field_111 = 1;
        if (p1->field_5B4 != 0) {
            ((void (*)(int, char *, char *, signed char, int, int, int, int))p1->field_5B4)(1, name, p1->field_5BC, p1->field_5E0, p1->field_5E4, flag, vals[3], p1->field_5B8);
            p1->field_5B4 = 0;
            p1->field_5B8 = 0;
        }
    }
}
