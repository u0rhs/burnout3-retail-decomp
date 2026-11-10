// func_0023BD20 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (unsigned short frame deltas; merged v4<0 || field_6D8>=v4 return; v4 = f-m; v4 += r1).

// lifter variant 0
// func_0023BD20 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

class CGtNetworkPlayerManager;
struct UnkStruct_0023BD20;
struct UnkStruct_0023BD20_a1;
struct UnkStruct_D_004E2A14;
struct UnkStruct_D_01E654A0;

class CGtNetworkPlayerManager {
public:
    int GetPlayerIndexByID(int);
    int GetMyPlayerIndex() const;

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0023BD20_a1 {
    int field_0;
};

struct UnkStruct_D_004E2A14 {
    unsigned short field_0;
};

struct UnkStruct_D_01E654A0 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0023BD20 {
    unsigned char pad_0[0xC];
    CGtNetworkPlayerManager * field_C;
    unsigned char pad_10[0x6C6];
    short field_6D6;
    int field_6D8;
    unsigned char pad_6DC[0x8];
    unsigned char field_6E4;
    unsigned char pad_6E5[0x4804];
    signed char field_4EE9;
};

extern UnkStruct_D_004E2A14 D_004E2A14;
extern UnkStruct_D_01E654A0 D_01E654A0;
extern CGtNetworkPlayerManager D_01E32AE0;

extern "C" int func_0022FBB0(UnkStruct_0023BD20 *);

// 0x0023BD20
extern "C" int func_0023BD20(UnkStruct_0023BD20 * self, UnkStruct_0023BD20_a1 * p0)
{
    p0->field_0 = -1;
    int r1 = D_01E32AE0.GetPlayerIndexByID(func_0022FBB0(self));
    int r2 = self->field_C->GetMyPlayerIndex();
    int t0 = D_01E654A0.field_0;
    unsigned short v0 = D_004E2A14.field_0;
    if (v0 == 65535) {
        v0 = 0;
    }
    unsigned short v1 = v0 - t0;
    if (v1 == 65535) {
        v1 = 0;
    }
    int f = v1;
    if ((self->field_6E4 & 1) == 1) {
        return 0;
    }
    if (self->field_4EE9 > 0) {
        self->field_4EE9--;
        self->field_6D8 = f;
        p0->field_0 = self->field_6D8;
        return 1;
    }
    int t2 = self->field_6D6;
    int m = f % t2;
    if (r1 == 5) {
        r1 = r2;
    }
    if (m == r1) {
        self->field_6D8 = f;
        p0->field_0 = self->field_6D8;
        return 1;
    }
    int v4 = f - m;
    v4 += r1;
    if (v4 > f) {
        v4 -= (short)t2;
    }
    if (v4 < 0 || self->field_6D8 >= v4) {
        return 0;
    }
    self->field_6D8 = v4;
    p0->field_0 = self->field_6D8;
    return 1;
}
