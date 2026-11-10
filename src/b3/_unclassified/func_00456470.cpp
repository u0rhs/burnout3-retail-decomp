// func_00456470 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (CGt2dObject* array via element pointer; scene const local).

// lifter variant 0
// func_00456470 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

class CGt2dObject;

struct UnkStruct_00456470;
struct UnkStruct_D_01E903E0;

struct UnkStruct_D_01E903E0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00456470 {
    unsigned char pad_0[0x8];
    short field_8;
    unsigned char pad_A[0x2];
     CGt2dObject * field_C[1];  // [G] element count unknown
};

extern unsigned char D_004D34E8[];  // [G] element count unknown
extern UnkStruct_D_01E903E0 D_01E903E0;

extern "C" void Release__20CB3MenuComponentBaseFv(void *);  // CB3MenuComponentBase::Release()
extern "C" void DestructObject__10CGt2dSceneFiP11CGt2dObject(void *, int, void *);  // CGt2dScene::DestructObject(int,CGt2dObject*)

// 0x00456470
extern "C" void func_00456470(UnkStruct_00456470 * self)
{
    Release__20CB3MenuComponentBaseFv(self);
    UnkStruct_D_01E903E0 * const scene = &D_01E903E0;
    for (int i = 0; i < 5; i++) {
         CGt2dObject **pp = &self->field_C[i];
        if (*pp != 0) {
            DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, (self->field_8 + D_004D34E8[i]), *pp);
            *pp = 0;
        }
    }
}
