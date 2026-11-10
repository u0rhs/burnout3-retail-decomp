// func_00442CF0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (declaration fix only: p0 struct has 0x18-stride element array at +8 and int field_38[]; lifter body otherwise).

// lifter variant 0
// func_00442CF0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_00442CF0;
struct UnkStruct_00442CF0_3;
struct UnkStruct_00442CF0_a1;
struct UnkStruct_00442CF0_e1;

struct UnkStruct_00442CF0_e1 {
    unsigned char pad_0[0x18];
};

struct UnkStruct_00442CF0_a1 {
    unsigned char pad_0[0x8];
    UnkStruct_00442CF0_e1 field_8[1];
    unsigned char pad_20[0x18];
    int field_38[1];  // [G] element count unknown
};

struct UnkStruct_00442CF0_3 {
    int field_0;
};


struct UnkStruct_00442CF0 {
    unsigned char pad_0[0x4];
    int field_4;
    unsigned char field_8;
    unsigned char field_9;
    unsigned char pad_A[0xD6];
    int field_E0;
    int field_E4;
    unsigned char pad_E8[0x4];
    int field_EC;
    unsigned char pad_F0[0x4];
    unsigned char field_F4;
    unsigned char pad_F5[0x3];
    int field_F8;
    int field_FC;
    int field_100;
    int field_104;
    int field_108;
    int field_10C;
    int field_110;
    int field_114;
    int field_118;
    int field_11C;
    int field_120;
    unsigned char pad_124[0xC];
    unsigned char field_130;
    unsigned char pad_131[0x3];
    int field_134;
    int field_138;
    int field_13C;
    int field_140;
    unsigned char pad_144[0xC];
    int field_150;
    int field_154;
    int field_158;
    int field_15C;
    unsigned char pad_160[0xC];
    unsigned char field_16C;
    unsigned char pad_16D[0x3];
    int field_170;
    int field_174;
    unsigned char pad_178[0x30];
    unsigned char field_1A8;
    unsigned char pad_1A9[0x3];
    int field_1AC;
    int field_1B0;
    int field_1B4;
    int field_1B8;
    int field_1BC;
    int field_1C0;
    int field_1C4;
    int field_1C8;
    int field_1CC;
    int field_1D0;
    int field_1D4;
    unsigned char pad_1D8[0x24];
    UnkStruct_00442CF0_3 * field_1FC;
    int field_200;
    unsigned char field_204;
};

extern "C" void lgDevSetDeviceProperty(int, int, int, bool, int);
extern "C" void func_004429F0(UnkStruct_00442CF0 *, float, float);
extern "C" void lgDevDownloadForceEffect(int, void *, void *);
extern "C" void lgDevStartForceEffect(int);

// 0x00442CF0
extern "C" int func_00442CF0(UnkStruct_00442CF0 * self, UnkStruct_00442CF0_a1 * p0, int p1)
{
    int t0 = p0->field_38[p1];
    self->field_E0 = t0;
    self->field_1FC = (UnkStruct_00442CF0_3 *)&p0->field_8[p1];
    UnkStruct_00442CF0_3 * t1 = self->field_1FC;
    int t2 = t1->field_0;
    self->field_9 = (t2 == 17);
    self->field_8 = 1;
    self->field_4 = 5;
    self->field_200 = p1;
    lgDevSetDeviceProperty(self->field_E0, 2, 0, (t2 == 17), t0);
    self->field_16C = 7;
    self->field_170 = -1;
    self->field_174 = 0;
    func_004429F0(self, 0.4f, 0.0f);
    self->field_F4 = 2;
    self->field_F8 = -1;
    self->field_FC = 0;
    self->field_100 = 0;
    self->field_104 = 0;
    self->field_108 = 0;
    self->field_10C = 0;
    self->field_110 = 0;
    self->field_114 = 100;
    self->field_118 = 255;
    self->field_11C = 0;
    self->field_120 = 0;
    self->field_130 = 0;
    self->field_134 = 0;
    self->field_138 = 0;
    self->field_13C = 0;
    self->field_140 = 0;
    self->field_150 = 0;
    self->field_154 = 0;
    self->field_158 = 0;
    self->field_15C = 0;
    self->field_1A8 = 3;
    self->field_1AC = 0;
    self->field_1B0 = 0;
    self->field_1B4 = 0;
    self->field_1B8 = 0;
    self->field_1BC = 0;
    self->field_1C0 = 0;
    self->field_1C4 = 0;
    self->field_1C8 = 0;
    self->field_1CC = 255;
    self->field_1D0 = 0;
    self->field_1D4 = 0;
    lgDevDownloadForceEffect(self->field_E0, ((char *)self + 0xEC), ((char *)self + 0x16C));
    lgDevDownloadForceEffect(self->field_E0, ((char *)self + 0xE4), ((char *)self + 0xF4));
    lgDevDownloadForceEffect(self->field_E0, ((char *)self + 0xE8), ((char *)self + 0x130));
    lgDevDownloadForceEffect(self->field_E0, ((char *)self + 0xF0), ((char *)self + 0x1A8));
    lgDevStartForceEffect(self->field_EC);
    lgDevStartForceEffect(self->field_E4);
    self->field_204 = 0;
    return 1;
}
