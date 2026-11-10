// func_00230C50 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (field_34 char array (no CSE); r8==0 then-arm with float if/else; ==1 tests; field_5E store in both arms of r8 block).

// lifter variant 0
// func_00230C50 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

class CGtNetworkPlayerManager;
struct UnkStruct_00230C50;
struct UnkStruct_00230C50_2;
struct UnkStruct_00230C50_4;
struct UnkStruct_00230C50_5;
struct UnkStruct_00230C50_6;
struct UnkStruct_00230C50_a1;
struct UnkStruct_D_004BA030;
struct UnkStruct_D_004BAF10;
struct UnkStruct_D_004BAF28;

class CGtNetworkPlayerManager {
public:
    int GetMyPlayerID() const;

    unsigned char pad_0[0x8C];
    unsigned char field_8C;
};

struct UnkStruct_00230C50_a1 {
    unsigned char pad_0[0x14];
    int field_14;
    unsigned char pad_18[0x4];
    int field_1C;
    unsigned char pad_20[0xC];
    float field_2C;
    int field_30;
    unsigned char field_34[0x2A];
    unsigned char field_5E;
};

struct UnkStruct_00230C50_2 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18(int);
};

struct UnkStruct_00230C50_4 {
    int field_0;
    unsigned char pad_4[0x8];
    int field_C;
};

struct UnkStruct_00230C50_5 {
    int field_0;
    unsigned char pad_4[0x8];
    int field_C;
};

struct UnkStruct_00230C50_6 {
    int field_0;
    unsigned char pad_4[0x8];
    int field_C;
};

struct UnkStruct_D_004BAF10 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004BA030 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004BAF28 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00230C50 {
    unsigned char pad_0[0x524];
    UnkStruct_00230C50_2 * field_524;
    CGtNetworkPlayerManager * field_528;
};

extern UnkStruct_D_004BAF10 D_004BAF10;
extern UnkStruct_D_004BA030 D_004BA030;
extern UnkStruct_D_004BAF28 D_004BAF28;

extern "C" int func_00403C30(void *, int, void *, void *);
extern "C" void * func_002348A0(UnkStruct_00230C50 *, int);
extern "C" void func_002350D0(void *, int, int, unsigned char);
extern "C" void func_00403DA0(int, int, void *);
extern "C" void func_00403E20(int);
extern "C" int func_00403E28(int, void *, void *);

// 0x00230C50
extern "C" int func_00230C50(UnkStruct_00230C50 * self, UnkStruct_00230C50_a1 * p0, int p1, float f0)
{
    switch (p0->field_1C) {
    case 0:
        self->field_524->vfunc_14();
        p0->field_5E = 1;
        p0->field_30 = func_00403C30(&D_004BAF10, 3658, &D_004BA030, &D_004BAF28);
        p0->field_1C = 1;
        break;
    case 1: {
        UnkStruct_00230C50_4 * r2 = (UnkStruct_00230C50_4 *)func_002348A0(self, p1);
        CGtNetworkPlayerManager * t0 = self->field_528;
        func_002350D0(p0->field_34, p0->field_14, t0->GetMyPlayerID(), t0->field_8C);
        if (r2->field_0 == 1) {
            func_00403DA0(p0->field_30, r2->field_C, p0->field_34);
        } else {
            func_00403DA0(p0->field_30, 3658, p0->field_34);
        }
        p0->field_2C = f0;
        p0->field_1C = 2;
        break;
    }
    case 2: {
        func_00403E20(p0->field_30);
        int r8 = func_00403E28(p0->field_30, ((char *)p0 + 0x24), ((char *)p0 + 0x28));
        if (r8 == 0) {
            if ((f0 - p0->field_2C) <= 10.0f) {
                return 0;
            } else {
            p0->field_1C = 4;
            UnkStruct_00230C50_6 * r12 = (UnkStruct_00230C50_6 *)func_002348A0(self, p1);
            if (r12->field_0 == 1) {
                self->field_524->vfunc_18(r12->field_C);
            } else {
                self->field_524->vfunc_18(3658);
            }
            p0->field_5E = 0;
            return 1;
            }
        } else {
            UnkStruct_00230C50_5 * r9 = (UnkStruct_00230C50_5 *)func_002348A0(self, p1);
            if (r9->field_0 == 1) {
                self->field_524->vfunc_18(r9->field_C);
                p0->field_5E = 0;
            } else {
                self->field_524->vfunc_18(3658);
                p0->field_5E = 0;
            }
            if (r8 > 0) {
                p0->field_1C = 3;
                return 1;
            }
            if (r8 < 0) {
                p0->field_1C = 4;
                return 1;
            }
        }
        break;
    }
    case 3:
    case 4:
        return 1;
    }
    return 0;
}
