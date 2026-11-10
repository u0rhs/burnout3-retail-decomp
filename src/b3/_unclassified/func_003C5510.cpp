// func_003C5510 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_003C5510;
struct UnkStruct_003C5510_2;
struct UnkStruct_003C5510_4;
struct UnkStruct_D_0051BA44;
struct UnkStruct_D_0051BA88;
struct UnkStruct_D_01E898E8;
struct UnkStruct_D_01ECDA04;

struct UnkStruct_D_01ECDA04 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003C5510_2 {
    int field_0;
};

struct UnkStruct_D_0051BA88 {
    UnkStruct_003C5510_4 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003C5510_4 {
    unsigned char pad_0[0x1B4];
    int field_1B4;
};

struct UnkStruct_D_0051BA44 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E898E8 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003C5510 {
    unsigned char pad_0[0x38];
    int field_38;
    unsigned char pad_3C[0x4];
    int field_40;
    int field_44;
};

extern UnkStruct_D_01ECDA04 D_01ECDA04;
extern UnkStruct_D_0051BA88 D_0051BA88;
extern UnkStruct_D_0051BA44 D_0051BA44;
extern UnkStruct_D_01E898E8 D_01E898E8;

extern "C" void func_003C58A0(UnkStruct_003C5510 *, int, int, void *);
extern "C" int func_00271A00(void *, int);
extern "C" void *func_001A3AA0(void *, void *, UnkStruct_003C5510_2 *);
extern "C" void func_0032CF60(void *, int, void *, int, int);
extern "C" void func_003905B0(int);

// 0x003C5510
extern "C" int func_003C5510(UnkStruct_003C5510 * self)
{
    UnkStruct_003C5510_2 local;  // [G] the frame's one local (size: up to the frame top)
    func_003C58A0(self, D_01ECDA04.field_0, 0, (void *)(0));
    self->field_38 = 3;
    self->field_40 = 0x41A00000;
    int t0 = self->field_44;
    local.field_0 = (((int)*(float *)&self->field_40) + 1);
    int r1 = func_00271A00(&D_0051BA44, 315);
    func_001A3AA0((void *)(t0), (void *)(r1), &local);
    func_0032CF60(&D_01E898E8, 3, (void *)(self->field_44), 1, 0);
    func_003905B0(D_0051BA88.field_0->field_1B4);
    return 1;
}
