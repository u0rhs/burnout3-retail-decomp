// Hand-written; the lifter refused it (hand-written from the near-census source: if/else on the error field, >=0 test with error path last, char[0x24] field at 0x5BC).

// func_00338540 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

class CGtLobbyPS2DirtySock;
struct UnkStruct_00338540_3;
struct UnkStruct_00338540_a1;
struct UnkStruct_00338540_a2;
struct UnkStruct_D_004C5968;
struct UnkStruct_D_004C59E8;
struct UnkStruct_D_004C59F0;
struct UnkStruct_D_004C59F8;
struct UnkStruct_D_004C5A00;
struct UnkStruct_D_004E2DAC;
struct UnkStruct_func_00338700;

class CGtLobbyPS2DirtySock {
public:
    static int ConvertDirtySockError(int);
};

struct UnkStruct_00338540_a1 {
    unsigned char pad_0[0xC];
    int field_C;
    int field_10;
};

struct UnkStruct_00338540_a2 {
    unsigned char pad_0[0x104];
    int field_104;
    unsigned char pad_108[0x8];
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

struct UnkStruct_D_004E2DAC {
    UnkStruct_00338540_3 * field_0;
};

struct UnkStruct_00338540_3 {
    unsigned char field_0;
};

struct UnkStruct_D_004C59F0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004C59F8 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004C5A00 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004C5968 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004C59E8 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_func_00338700 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

extern UnkStruct_D_004E2DAC D_004E2DAC;
extern UnkStruct_D_004C59F0 D_004C59F0;
extern UnkStruct_D_004C59F8 D_004C59F8;
extern UnkStruct_D_004C5A00 D_004C5A00;
extern UnkStruct_D_004C5968 D_004C5968;
extern UnkStruct_D_004C59E8 D_004C59E8;
extern UnkStruct_func_00338700 func_00338700;

extern "C" int TagFieldFind(int, void *);
extern "C" int TagFieldGetNumber(int, int);
extern "C" void TagFieldGetString(int, void *, int, void *);
extern "C" void TagFieldSetNumber(UnkStruct_00338540_3 *, int, void *, int);
extern "C" void LobbyApiRequestCB(int, int, UnkStruct_00338540_3 *, void *, UnkStruct_00338540_a2 *);

// 0x00338540
extern "C" void func_00338540(int n0, UnkStruct_00338540_a1 * p0, UnkStruct_00338540_a2 * p1)
{
    if (p0->field_C != 0) {
        if (p1->field_5B4 != 0) {
            ((void (*)(int, int, int, int, int, int, int, int))p1->field_5B4)(0, 0, 0, -1, -1, 0, 0, p1->field_5B8);
            p1->field_5B4 = 0;
            p1->field_5B8 = 0;
        }
        int r11 = CGtLobbyPS2DirtySock::ConvertDirtySockError(p0->field_C);
        p1->field_112 = 1;
        p1->field_110 = 0;
        p1->field_114 = r11;
    } else {
    p1->field_5E4 = TagFieldGetNumber(TagFieldFind(p0->field_10, &D_004C59F0), -1);
    if (p1->field_5E4 >= 0) {
        p1->field_5E0 = TagFieldGetNumber(TagFieldFind(p0->field_10, &D_004C59F8), 0);
        TagFieldGetString(TagFieldFind(p0->field_10, &D_004C5A00), p1->field_5BC, 36, &D_004C5968);
        if (p1->field_5E4 == 0) {
            p1->field_111 = 1;
            if (p1->field_5B4 != 0) {
                ((void (*)(int, int, void *, signed char, int, int, int, int))p1->field_5B4)(1, 0, p1->field_5BC, p1->field_5E0, 0, 0, 0, p1->field_5B8);
                p1->field_5B4 = 0;
                p1->field_5B8 = 0;
            }
        } else {
            D_004E2DAC.field_0->field_0 = 0;
            TagFieldSetNumber(D_004E2DAC.field_0, 1024, &D_004C59E8, p1->field_5E4);
            LobbyApiRequestCB(p1->field_104, 0x67676574, D_004E2DAC.field_0, &func_00338700, p1);
        }
    } else {
        int r2 = CGtLobbyPS2DirtySock::ConvertDirtySockError(0x7567616D);
        p1->field_112 = 1;
        p1->field_110 = 0;
        p1->field_114 = r2;
    }
    }
}
