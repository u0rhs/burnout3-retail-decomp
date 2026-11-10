// func_00463070 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (char* cursor local p advanced by strlen (string build); case 0 writes dst+9 directly).

// func_00463070 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_00463070_1;
struct UnkStruct_D_004D3B18;
struct UnkStruct_D_004D3B28;
struct UnkStruct_D_004D3B38;
struct UnkStruct_D_004D3B40;
struct UnkStruct_D_004D3B50;
struct UnkStruct_D_004D3B58;
struct UnkStruct_D_004D3B68;
struct UnkStruct_D_004E2FCC;

struct UnkStruct_D_004E2FCC {
    UnkStruct_00463070_1 * field_0;
};

struct UnkStruct_00463070_1 {
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

// 0x00463070
extern "C" void func_00463070(char * n0, char * p0, void *p1_, const char * name)
{
    int p1 = (int)p1_;
    char * p;
    memset(n0, 0, 32);
    int r1 = ((int (*)())D_004E2FCC.field_0->field_48)();
    switch (r1) {
    case 0:
        memcpy(n0, &D_004D3B18, 9);
        memcpy(n0 + 9, name, strlen(name));
        p = n0 + 9 + strlen(name);
        break;
    case 1:
        memcpy(n0, &D_004D3B28, 12);
        p = n0 + 12;
        memcpy(p, name, strlen(name));
        p += strlen(name);
        memcpy(p, &D_004D3B38, strlen((const char *)&D_004D3B38));
        break;
    case 2:
        memcpy(n0, &D_004D3B40, 12);
        p = n0 + 12;
        memcpy(p, name, strlen(name));
        p += strlen(name);
        memcpy(p, &D_004D3B50, strlen((const char *)&D_004D3B50));
        break;
    case 3:
        memcpy(n0, &D_004D3B58, 12);
        p = n0 + 12;
        memcpy(p, name, strlen(name));
        p += strlen(name);
        memcpy(p, &D_004D3B68, strlen((const char *)&D_004D3B68));
        break;
    default:
        break;
    }
    memset(p0, 0, 32);
    switch (r1) {
    case 0:
        memcpy(p0, &D_004D3B18, 9);
        memcpy(p0 + 9, name, strlen(name));
        p = p0 + 9 + strlen(name);
        break;
    case 1:
        memcpy(p0, &D_004D3B28, 12);
        p = p0 + 12;
        memcpy(p, name, strlen(name));
        p += strlen(name);
        memcpy(p, &D_004D3B38, strlen((const char *)&D_004D3B38));
        break;
    case 2:
        memcpy(p0, &D_004D3B40, 12);
        p = p0 + 12;
        memcpy(p, name, strlen(name));
        p += strlen(name);
        memcpy(p, &D_004D3B50, strlen((const char *)&D_004D3B50));
        break;
    case 3:
        memcpy(p0, &D_004D3B58, 12);
        p = p0 + 12;
        memcpy(p, name, strlen(name));
        p += strlen(name);
        memcpy(p, &D_004D3B68, strlen((const char *)&D_004D3B68));
        break;
    default:
        break;
    }
}
