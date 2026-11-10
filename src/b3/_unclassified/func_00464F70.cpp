// func_00464F70 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (static inline vtable-call helper (x2); char* p; separate int stack locals; &field_88 local hoisted; r==0?0:r+K returns).

// lifter variant 0
// func_00464F70 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_00464F70_1;
struct UnkStruct_00464F70_2;
struct UnkStruct_00464F70_3;
struct UnkStruct_00464F70_4;
struct UnkStruct_00464F70_5;
struct UnkStruct_00464F70_6;
struct UnkStruct_00464F70_7;
struct UnkStruct_00464F70_8;
struct UnkStruct_D_004D3B70;
struct UnkStruct_D_004E2FBC;

struct UnkStruct_D_004E2FBC {
    UnkStruct_00464F70_1 * field_0;
};

struct UnkStruct_00464F70_1 {
    unsigned char pad_0[0x64];
    int field_64;
    int field_68;
    UnkStruct_00464F70_3 * field_6C;
    unsigned char pad_70[0x8];
    int field_78;
    int field_7C;
    unsigned char pad_80[0x4];
    int field_84;
    int field_88;
    int field_8C;
};

struct UnkStruct_00464F70_2 {
    int field_0;
    int field_4;
    int field_8;
    int field_C;
};

struct UnkStruct_00464F70_3 {
    unsigned char pad_0[0xC];
    int field_C;
};

struct UnkStruct_00464F70_4 {
    unsigned char pad_0[0x10];
    int field_10;
};

struct UnkStruct_00464F70_5 {
    unsigned char pad_0[0x18];
    int field_18;
};

struct UnkStruct_00464F70_6 {
    unsigned char pad_0[0xC];
    int field_C;
};

struct UnkStruct_00464F70_7 {
    unsigned char pad_0[0x10];
    int field_10;
};

struct UnkStruct_00464F70_8 {
    unsigned char pad_0[0x18];
    int field_18;
};

struct UnkStruct_D_004D3B70 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

extern UnkStruct_D_004E2FBC D_004E2FBC;
extern UnkStruct_D_004D3B70 D_004D3B70;

extern "C" int memcmp(const void *, const void *, unsigned int);
extern "C" void * memcpy(void *, const void *, unsigned int);
extern "C" void func_004652B0(int, void *, void *);
extern "C" int func_00467260(UnkStruct_00464F70_1 *, char *, unsigned int);

static inline int a51_call(int a, int b)
{
    UnkStruct_00464F70_1 * g = D_004E2FBC.field_0;
    if (g->field_6C == 0) {
        return 0;
    }
    int r = ((int (*)(int, int))g->field_6C->field_C)(g->field_64, g->field_68);
    if (r == 0) {
        r = ((int (*)(int, int))((UnkStruct_00464F70_4 *)D_004E2FBC.field_0->field_6C)->field_10)(a, b);
        if (r == 0) {
            r = ((int (*)())((UnkStruct_00464F70_5 *)D_004E2FBC.field_0->field_6C)->field_18)();
            if (r == 0) {
                return 0;
            }
        }
    }
    return r == 0 ? 0 : r + 200;
}

// 0x00464F70
extern "C" int func_00464F70()
{
    int c;
    int b;
    int k4;
    int k1;
    D_004E2FBC.field_0->field_78 = 6;
    char * p = (char *)D_004E2FBC.field_0->field_7C - 12;
    if (memcmp(p, &D_004D3B70, 12) != 0) {
        p = 0;
    }
    if (p == 0) {
        return 4;
    }
    UnkStruct_00464F70_1 * t2 = D_004E2FBC.field_0;
    int * q = &t2->field_88;
    b = t2->field_84;
    c = t2->field_8C;
    memcpy(p, &c, 4);
    memcpy(p + 4, &b, 4);
    memcpy(p + 8, q, 4);
    int err = a51_call((int)p, 12);
    if (err != 0) {
        return err;
    }
    err = a51_call(D_004E2FBC.field_0->field_7C, D_004E2FBC.field_0->field_84);
    if (err != 0) {
        return err;
    }
    int t10 = D_004E2FBC.field_0->field_84;
    k4 = 4;
    k1 = 1;
    func_004652B0(2, &k4, &k1);
    unsigned int n = t10 + 12;
    unsigned int a = k1;
    if (n < a) {
        n = a;
    } else {
        n = n + (a - n % a) % a;
    }
    int r = func_00467260(D_004E2FBC.field_0, p, n);
    return r == 0 ? 0 : r + 100;
}
