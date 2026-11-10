// func_004661C0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (rewritten as error-code chain: if/else on r, switch with default last, two separate int locals, function-pointer fields).

// func_004661C0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_004661C0;
struct UnkStruct_004661C0_0;
struct UnkStruct_004661C0_3;
struct UnkStruct_D_004E2FC4;

struct UnkStruct_004661C0_0 {
    unsigned char pad_0[0x4];
    int field_4;
};

struct UnkStruct_D_004E2FC4 {
    UnkStruct_004661C0_3 * field_0;
};

struct UnkStruct_004661C0_3 {
    unsigned char pad_0[0x100];
    int (*field_100)(int);
    int (*field_104)(int);
};

struct UnkStruct_004661C0 {
    int field_0;
};

extern UnkStruct_D_004E2FC4 D_004E2FC4;

extern "C" int func_00463850(int *, int *);
extern "C" int func_00465320(int);

// 0x004661C0
extern "C" int func_004661C0(UnkStruct_004661C0 * self)
{
    int b = 0;
    int a;
    int r = 0;
    if (self == 0) {
        r = 7;
    }
    if (r == 0) {
        r = func_00465320(func_00463850(&b, &a));
    }
    if (r == 0) {
        self->field_0 = 0;
        switch (b) {
        
        case 0:
            r = 23;
            break;
        case 1:
            self->field_0 = 1;
            break;
        case 2:
            if (D_004E2FC4.field_0->field_100 != 0) {
                r = D_004E2FC4.field_0->field_100(r);
                D_004E2FC4.field_0->field_100 = 0;
            }
            if (r == 0) {
                self->field_0 = 2;
            }
            break;
        default:
            r = 18;
            break;
        }
    } else {
        if (D_004E2FC4.field_0->field_104 != 0) {
            r = D_004E2FC4.field_0->field_104(r);
            D_004E2FC4.field_0->field_104 = 0;
        }
    }
    return r;
}
