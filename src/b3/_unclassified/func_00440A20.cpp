// func_00440A20 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (list-append inline helper (if (n < 9) arr[n++] = p); &D_0064D3B0 held in a const local ahead of the call).

// lifter variant 0
// func_00440A20 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_00440A20;
struct UnkStruct_00440A20_6;
struct UnkStruct_00440A20_8;
struct UnkStruct_D_004EE040;
struct UnkStruct_D_0051B340;
struct UnkStruct_D_0051B938;
struct UnkStruct_D_0051BA88;
struct UnkStruct_D_0064D3B0;

struct UnkStruct_D_0064D3B0 {
    unsigned char pad_0[0x10C8];
    int field_10C8;
};

struct UnkStruct_D_0051B938 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00440A20_6 {
    unsigned char pad_0[0x14];
    int field_14;
};

struct UnkStruct_D_0051BA88 {
    UnkStruct_00440A20_8 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00440A20_8 {
    unsigned char pad_0[0x1B4];
    int field_1B4;
};

struct UnkStruct_D_004EE040 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0051B340 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00440A20 {
    unsigned char pad_0[0x108];
    void * field_108[1];  // [G] element count unknown
    unsigned char pad_10C[0x20];
    int field_12C;
};

extern UnkStruct_D_0064D3B0 D_0064D3B0;
extern UnkStruct_D_0051B938 D_0051B938;
extern UnkStruct_00440A20_6 * D_01E901DC[];  // [G] element count unknown
extern UnkStruct_D_0051BA88 D_0051BA88;
extern UnkStruct_D_004EE040 D_004EE040;
extern UnkStruct_D_0051B340 D_0051B340;

extern "C" int func_00131CE0(void *);

// [G] inlined helper (name unknown): appends p to the field_108 list (capacity 9)
static inline void func_00440A20_add(UnkStruct_00440A20 * self, void * p)
{
    if (self->field_12C < 9) {
        self->field_108[self->field_12C++] = p;
    }
}

// 0x00440A20
extern "C" void func_00440A20(UnkStruct_00440A20 * self)
{
    UnkStruct_D_0064D3B0 * const g = &D_0064D3B0;
    if (func_00131CE0(&D_004EE040) != 0) {
        if (g->field_10C8 == 0) {
            func_00440A20_add(self, (char *)self + 0x4);
        }
        switch (D_01E901DC[D_0051B938.field_0]->field_14) {
        case 0:
            func_00440A20_add(self, (char *)self + 0x74);
            func_00440A20_add(self, (char *)self + 0x14);
            func_00440A20_add(self, (char *)self + 0x2C);
            func_00440A20_add(self, (char *)self + 0x5C);
            break;
        case 1:
            func_00440A20_add(self, (char *)self + 0x74);
            func_00440A20_add(self, (char *)self + 0x14);
            func_00440A20_add(self, (char *)self + 0x2C);
            func_00440A20_add(self, (char *)self + 0x5C);
            break;
        case 3:
            func_00440A20_add(self, (char *)self + 0x5C);
            func_00440A20_add(self, (char *)self + 0x2C);
            break;
        case 4:
            func_00440A20_add(self, (char *)self + 0x74);
            func_00440A20_add(self, (char *)self + 0x2C);
            break;
        case 6:
            func_00440A20_add(self, (char *)self + 0x44);
            break;
        }
    }
    if (D_0051BA88.field_0 != 0 && D_0051BA88.field_0->field_1B4 == (int)&D_0051B340) {
        func_00440A20_add(self, (char *)self + 0x8C);
    }
    func_00440A20_add(self, (char *)self + 0x98);
    func_00440A20_add(self, (char *)self + 0xB0);
    func_00440A20_add(self, (char *)self + 0xA4);
}
