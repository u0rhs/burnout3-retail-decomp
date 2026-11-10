// func_0037C570 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (early-return name checks; stack buffers declared in reverse frame order; D_01EA3078 as a char-array struct through a const pointer (s0)).

// lifter variant 0
// func_0037C570 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

class CB3OnScreenKeyboardComponent;
class CGtLobbyPS2DirtySock;
struct UnkStruct_0037C570;
struct UnkStruct_0037C570_1;
struct UnkStruct_0037C570_e0;
struct UnkStruct_D_004C9248;
struct UnkStruct_D_004C9258;
struct UnkStruct_D_004C9260;
struct UnkStruct_D_01E898E8;
struct UnkStruct_D_01E8CA94;
struct UnkStruct_D_01E94C40;
struct UnkStruct_D_01EA2878;
struct UnkStruct_D_01EA3078;

class CB3OnScreenKeyboardComponent {
public:
    void Show(bool, bool);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CGtLobbyPS2DirtySock {
public:
    void CreatePersona(char*);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0037C570_1 {
    void * field_0;
    void * field_4;
    void * field_8;
    void * field_C;
    void * field_10;
    void * field_14;
    void * field_18;
    void * field_1C;
    unsigned char field_20;
    unsigned char field_21;
    unsigned char pad_22[0xE];
};

struct UnkStruct_D_01E8CA94 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EA2878 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EA3078 {
    int field_0;
    int field_4;
    int field_8;
    char field_C[0x20];
    char field_2C[0x20];
    char field_4C[0x40];
    char field_8C[0x40];
    char field_CC[0x3];
    char field_CF[0x3];
    unsigned char field_D2;
    unsigned char field_D3;
    unsigned char field_D4;
};

struct UnkStruct_D_01E898E8 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0037C570_e0 {
    unsigned char pad_0[0x20];
};

struct UnkStruct_D_01E94C40 {
    UnkStruct_0037C570_e0 field_0[1];  // [G] element count unknown
};

struct UnkStruct_D_004C9248 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004C9260 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004C9258 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0037C570 {
    unsigned char pad_0[0x4C];
    int field_4C;
    unsigned char field_50;
    unsigned char field_51;
};

extern UnkStruct_D_01E8CA94 D_01E8CA94;
extern UnkStruct_D_01EA2878 D_01EA2878;
extern UnkStruct_D_01EA3078 D_01EA3078;
extern CB3OnScreenKeyboardComponent D_01E899C0;
extern UnkStruct_D_01E898E8 D_01E898E8;
extern UnkStruct_D_01E94C40 D_01E94C40;
extern CGtLobbyPS2DirtySock D_01E3CD44;
extern UnkStruct_D_004C9248 D_004C9248;
extern UnkStruct_D_004C9260 D_004C9260;
extern UnkStruct_D_004C9258 D_004C9258;

extern "C" unsigned int strlen(const char *);
extern "C" char * strncpy(char *, const char *, unsigned int);
extern "C" char * strcpy(char *, const char *);
extern "C" void ConvertUTF16toUTF8Fast__10CGtUnicodeFPCUsPUci(int, void *, int);
extern "C" void ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(void *, int, int);
extern "C" void func_0032D080(void *, int, int, int, int);
extern "C" int snprintf(char *, unsigned int, const char *, ...);
extern "C" void func_0033AE60(void *, UnkStruct_0037C570_1 *);

// 0x0037C570
extern "C" void func_0037C570(UnkStruct_0037C570 * self)
{
    char c[4];
    char b[12];
    char name[16];
    UnkStruct_0037C570_1 info;
    if (self->field_50 == 1) {
        D_01E899C0.Show(0, 0);
        ConvertUTF16toUTF8Fast__10CGtUnicodeFPCUsPUci(D_01E8CA94.field_0, name, 16);
        ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(name, self->field_4C, 32);
        if (strlen(name) > 16 || strlen(name) < 4) {
            self->field_50 = 3;
            D_01E899C0.Show(0, 0);
            func_0032D080(&D_01E898E8, 2, 1001, 0, 0);
            return;
        }
        if (name[0] >= '0' && name[0] <= '9') {
            self->field_50 = 3;
            D_01E899C0.Show(0, 0);
            func_0032D080(&D_01E898E8, 2, 1002, 0, 0);
            return;
        }
        {
            if (self->field_51 != 0) {
                UnkStruct_D_01EA3078 * const p = &D_01EA3078;
                snprintf(b, 9, (const char *)&D_004C9248, p->field_8, p->field_0, p->field_4);
                if (p->field_D4 != 0) {
                    strcpy(c, (const char *)&D_004C9258);
                } else {
                    strcpy(c, (const char *)&D_004C9260);
                }
                strncpy(p->field_C, name, 32);
                info.field_0 = p->field_C;
                info.field_4 = p->field_2C;
                info.field_8 = p->field_4C;
                info.field_C = p->field_8C;
                info.field_10 = b;
                info.field_14 = c;
                info.field_18 = p->field_CC;
                info.field_1C = p->field_CF;
                info.field_20 = p->field_D2;
                info.field_21 = p->field_D3;
                func_0033AE60(&D_01E3CD44, &info);
            } else {
                strncpy((char *)&D_01E94C40.field_0[D_01EA2878.field_0] + 0xDC3C, name, 32);
                D_01EA2878.field_0++;
                D_01E3CD44.CreatePersona(name);
            }
            self->field_50 = 2;
            func_0032D080(&D_01E898E8, 0, 190, 15, 0);
        }
    }
}
