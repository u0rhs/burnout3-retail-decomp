// ForAllLobbys__20CGtLobbyPS2DirtySockFPFiPciibPv_bPv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (for(;;i++) with break test at top (unrotated loop); callback p0 typed as function pointer).

// lifter variant 0
// ForAllLobbys__20CGtLobbyPS2DirtySockFPFiPciibPv_bPv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_00338440;
struct UnkStruct_00338440_1;
struct UnkStruct_00338440_2;
struct UnkStruct_func_00338C10;

struct UnkStruct_00338440_1 {
    int field_0;
    unsigned char pad_4[0x8];
    int field_C;
    int field_10;
};

struct UnkStruct_00338440_2 {
    unsigned char pad_0[0x14];
    int field_14;
};

struct UnkStruct_func_00338C10 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00338440 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    unsigned char pad_4[0x55C];
    int field_560;
};

extern UnkStruct_func_00338C10 func_00338C10;

extern "C" void DispListFilt(int, int, int, void *);
extern "C" void DispListOrder(int);
extern "C" int func_0040A5D0(int);
extern "C" UnkStruct_00338440_1 * DispListIndex(int, int);

// 0x00338440
extern "C" void ForAllLobbys__20CGtLobbyPS2DirtySockFPFiPciibPv_bPv(UnkStruct_00338440 * self, int (*p0)(int, void *, int, int, bool, int), int p1)
{
    DispListFilt(self->field_560, 0, 1, &func_00338C10);
    DispListOrder(self->field_560);
    for (int i = 0; ; i++) {
        if (!(i < func_0040A5D0(self->field_560))) break;
        UnkStruct_00338440_1 * r = DispListIndex(self->field_560, i);
        if (r != 0) {
            if (p0(r->field_0, (char *)r + 0x1C, r->field_10, r->field_C, i == func_0040A5D0(self->field_560) - 1, p1) == 0) {
                self->vfunc_14();
                return;
            }
        }
    }
    self->vfunc_14();
}
