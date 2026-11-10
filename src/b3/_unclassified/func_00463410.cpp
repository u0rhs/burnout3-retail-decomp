// func_00463410 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (buffer param as char* advanced in place (p += 9/12, += strlen, += 2), switch with break to one return p).

// lifter variant 0
// func_00463410 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_00463410_1;
struct UnkStruct_D_004D3B18;
struct UnkStruct_D_004D3B28;
struct UnkStruct_D_004D3B38;
struct UnkStruct_D_004D3B40;
struct UnkStruct_D_004D3B50;
struct UnkStruct_D_004D3B58;
struct UnkStruct_D_004D3B68;
struct UnkStruct_D_004E2FCC;

struct UnkStruct_D_004E2FCC {
    UnkStruct_00463410_1 * field_0;
};

struct UnkStruct_00463410_1 {
    unsigned char pad_0[0x48];
    int field_48;
};

struct UnkStruct_D_004D3B18 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004D3B28 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004D3B38 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004D3B40 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004D3B50 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004D3B58 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004D3B68 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

extern UnkStruct_D_004E2FCC D_004E2FCC;
extern UnkStruct_D_004D3B18 D_004D3B18;
extern UnkStruct_D_004D3B28 D_004D3B28;
extern UnkStruct_D_004D3B38 D_004D3B38;
extern UnkStruct_D_004D3B40 D_004D3B40;
extern UnkStruct_D_004D3B50 D_004D3B50;
extern UnkStruct_D_004D3B58 D_004D3B58;
extern UnkStruct_D_004D3B68 D_004D3B68;

extern "C" void * memset(void *, int, unsigned int);
extern "C" void * memcpy(void *, const void *, unsigned int);
extern "C" unsigned int strlen(const char *);

// 0x00463410
extern "C" char * func_00463410(char * p, void *p0_, void *p1_)
{
    int p0 = (int)p0_;
    int p1 = (int)p1_;
    memset(p, 0, 32);
    switch (((int (*)())D_004E2FCC.field_0->field_48)()) {
    case 0:
        memcpy(p, &D_004D3B18, 9);
        p += 9;
        memcpy(p, (const void *)p1, strlen((const char *)p1));
        p += strlen((const char *)p1);
        break;
    case 1:
        memcpy(p, &D_004D3B28, 12);
        p += 12;
        memcpy(p, (const void *)p1, strlen((const char *)p1));
        p += strlen((const char *)p1);
        memcpy(p, &D_004D3B38, strlen((const char *)&D_004D3B38));
        p += 2;
        break;
    case 2:
        memcpy(p, &D_004D3B40, 12);
        p += 12;
        memcpy(p, (const void *)p1, strlen((const char *)p1));
        p += strlen((const char *)p1);
        memcpy(p, &D_004D3B50, strlen((const char *)&D_004D3B50));
        p += 2;
        break;
    case 3:
        memcpy(p, &D_004D3B58, 12);
        p += 12;
        memcpy(p, (const void *)p1, strlen((const char *)p1));
        p += strlen((const char *)p1);
        memcpy(p, &D_004D3B68, strlen((const char *)&D_004D3B68));
        p += 2;
        break;
    }
    return p;
}
