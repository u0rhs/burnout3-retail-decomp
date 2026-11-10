// func_0030EB10 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_0030EB10;
struct UnkStruct_0030EB10_3;
struct UnkStruct_0030EB10_4;
struct UnkStruct_0030EB10_5;
struct UnkStruct_0030EB10_7;
struct UnkStruct_0030EB10_8;
struct UnkStruct_D_004EE040;
struct UnkStruct_D_0051A6A8;
struct UnkStruct_D_0051BA88;
struct UnkStruct_D_00665E53;
struct UnkStruct_D_01E900B0;

struct UnkStruct_D_0051BA88 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_00665E53 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0030EB10_3 {
    unsigned char pad_0[0x20];
    float field_20;
};

struct UnkStruct_0030EB10_4 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_0030EB10_5 {
    unsigned char pad_0[0x18];
    int field_18;
    int field_1C;
};

struct UnkStruct_D_01E900B0 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0030EB10_7 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_0030EB10_8 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_D_0051A6A8 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004EE040 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0030EB10 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18(void *, int);
    virtual void vfunc_1C(void *, int);
    void * field_4;
    unsigned char pad_8[0x8];
    UnkStruct_0030EB10_3 * field_10;
    float field_14;
};

extern UnkStruct_D_0051BA88 D_0051BA88;
extern UnkStruct_D_00665E53 D_00665E53;
extern UnkStruct_D_01E900B0 D_01E900B0;
extern UnkStruct_D_0051A6A8 D_0051A6A8;
extern UnkStruct_D_004EE040 D_004EE040;

extern "C" int func_00131E40(void *, void *);
extern "C" void * GetStateFromID__6CGtFSMFUl(UnkStruct_0030EB10 *, unsigned long);

// 0x0030EB10
extern "C" void func_0030EB10(UnkStruct_0030EB10 * self)
{
    if (D_0051BA88.field_0 != (int)&D_0051A6A8) {
        if (D_00665E53.field_0 != 0) {
            if (D_01E900B0.field_0 == 3) {
                int r3 = func_00131E40(&D_004EE040, &D_0051A6A8);
                if (r3 != 0) {
                    UnkStruct_0030EB10_8 * r7 = (UnkStruct_0030EB10_8 *)GetStateFromID__6CGtFSMFUl(self, 0x944140403E74F2B0);
                    if (self->field_4 != r7) {
                        self->vfunc_18(r7, 0);
                        void * t0 = self->field_4;
                        self->field_4 = (void *)r7;
                        UnkStruct_0030EB10_3 * t1 = self->field_10;
                        if (t1 != 0) {
                            self->field_14 = t1->field_20;
                            if (r7 != 0) {
                                r7->field_8 = self->field_10->field_20;
                            }
                        }
                        self->vfunc_1C(t0, 0);
                        return;
                    }
                    return;
                }
                UnkStruct_0030EB10_7 * r4 = (UnkStruct_0030EB10_7 *)GetStateFromID__6CGtFSMFUl(self, 0x94414082ECC11C0A);
                if (self->field_4 != r4) {
                    self->vfunc_18(r4, 0);
                    void * t2 = self->field_4;
                    self->field_4 = (void *)r4;
                    UnkStruct_0030EB10_3 * t3 = self->field_10;
                    if (t3 != 0) {
                        self->field_14 = t3->field_20;
                        if (r4 != 0) {
                            r4->field_8 = self->field_10->field_20;
                        }
                    }
                    self->vfunc_1C(t2, 0);
                    return;
                }
                return;
            }
            return;
        }
        UnkStruct_0030EB10_4 * r0 = (UnkStruct_0030EB10_4 *)GetStateFromID__6CGtFSMFUl(self, 0x94413EDB6B01A028);
        if (self->field_4 != r0) {
            self->vfunc_18(r0, 0);
            void * t4 = self->field_4;
            self->field_4 = (void *)r0;
            UnkStruct_0030EB10_3 * t5 = self->field_10;
            if (t5 != 0) {
                self->field_14 = t5->field_20;
                if (r0 != 0) {
                    r0->field_8 = self->field_10->field_20;
                }
            }
            self->vfunc_1C(t4, 0);
            return;
        }
        return;
    }
}
