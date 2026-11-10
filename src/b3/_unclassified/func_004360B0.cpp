// func_004360B0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (a76: field_24/28 char* declarations).

// [G] declaration fix only: field_24/field_28 are char* (the lifter typed field_24 int). No DNAT row.

enum EHUDAlign {};

struct UnkStruct_004360B0;
struct UnkStruct_004360B0_e0;
struct UnkStruct_D_00522660;

struct UnkStruct_004360B0_e0 {
    unsigned char pad_0[0x27D0];
};

struct UnkStruct_D_00522660 {
    UnkStruct_004360B0_e0 field_0[1];  // [G] element count unknown
};

struct UnkStruct_004360B0 {
    unsigned char pad_0[0x20];
    int field_20;
    char * field_24;
    char * field_28;
    float field_2C;
};

extern UnkStruct_D_00522660 D_00522660;

extern "C" void Prepare__15CB3HUDComponentFiiii9EHUDAligni(void *, int, int, int, int, EHUDAlign, int);  // CB3HUDComponent::Prepare(int,int,int,int,EHUDAlign,int)

// 0x004360B0
extern "C" int func_004360B0(UnkStruct_004360B0 * self, int p0, int p1, int p2)
{
    Prepare__15CB3HUDComponentFiiii9EHUDAligni(self, 1, 1, 1, p0, (EHUDAlign)p1, p2);
    self->field_28 = ((char *)&D_00522660.field_0[p0] + 0x12AD50);
    self->field_24 = ((char *)self->field_28 + 5824);
    self->field_2C = -1.0f;
    self->field_20 = 0;
    return 1;
}
