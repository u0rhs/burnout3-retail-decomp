// NONMATCHING: func_001CFD20 -- retail 70 / ours 72 instructions, 31 in changed runs
// gaps1c: hand-drafted from the asm
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// gaps1c (2026-11-02): hand-drafted from the retail asm (0x1CFD20..0x1CFE34). Unnamed; file B3VehiclePhysics.cpp per
// research/retail_names.csv (high). [L] a vehicle-physics init by its stores: after func_001AD850 (the colliding-body
// init) six 0xC0-byte wheel blocks get 29.0 / 1.0 / 1.0 (+0x870 / +0x88C / +0x890 of each), two parameter triples
// (+0xCA4.. / +0xCB4..: 5000, 60000, D_004E0E00), the shape at +0x220 is initialised (func_002BAEE0) and linked at +0x208
// (kind 2 at +0x20C), and +0x1C0..+0x1E0 are set from D_004C9CD0 (+0x1C0's w = 2.0).
// TRACK: clean
// EQUIV: [L] written from the asm: every store and call in retail's order

typedef unsigned int u_long128 __attribute__((mode(TI)));
struct UnkStruct_001CFD20_q { float x, y, z, w; };
struct UnkStruct_001CFD20 {
    unsigned char pad_0[0x1C0];
    UnkStruct_001CFD20_q field_1C0;
    u_long128 field_1D0;
    u_long128 field_1E0;
    unsigned char pad_1F0[0x18];
    void * field_208;
    unsigned char field_20C;
    unsigned char pad_20D[0x13];
    unsigned char field_220[0x10];            // [C] a0 of func_002BAEE0 ([L] the collision shape, B3ConvexHull.cpp)
    unsigned char pad_230[0xCA0 - 0x230];
    int field_CA0;
    float field_CA4;
    float field_CA8;
    float field_CAC;
    int field_CB0;
    float field_CB4;
    float field_CB8;
    float field_CBC;
    unsigned char pad_CC0[0x8];
    int field_CC8[6];
    unsigned char pad_CE0[0x1160 - 0xCE0];
    unsigned short field_1160;
    unsigned char pad_1162[0x2];
    int field_1164;
    unsigned char field_1168;
    unsigned char field_1169;
    unsigned char field_116A;
    unsigned char pad_116B[0x1352 - 0x116B];
    unsigned char field_1352;
};

extern float D_004E0E00;                      // [C] gp-relative
extern u_long128 D_004C9CD0;                  // [C] set by the static initialiser func_004DA470 (0, 0, 0, w unset)

extern "C" void func_001AD850(void *);
extern "C" void func_002BAEE0(void *);

// 0x001CFD20
extern "C" void func_001CFD20(UnkStruct_001CFD20 * self)
{
    func_001AD850(self);
    for (int i = 0; i < 6; i++) {
        unsigned char * w = (unsigned char *)self + i * 0xC0;
        *(float *)(w + 0x870) = 29.0f;
        *(float *)(w + 0x88C) = 1.0f;
        *(float *)(w + 0x890) = 1.0f;
        self->field_CC8[i] = 0;
    }
    self->field_1169 = 0;
    self->field_116A = 0;
    self->field_CA0 = 0;
    self->field_CB0 = 0;
    self->field_CAC = D_004E0E00;
    self->field_CA8 = (float)60000;
    self->field_CA4 = (float)5000;
    self->field_CBC = D_004E0E00;
    self->field_CB8 = (float)60000;
    self->field_CB4 = (float)5000;
    self->field_1164 = 0;
    self->field_1168 = 0;
    self->field_1352 = 1;
    self->field_1160 = self->field_1160 & 0xFF00;
    func_002BAEE0(self->field_220);
    self->field_20C = 2;
    self->field_208 = self->field_220;
    self->field_1E0 = D_004C9CD0;
    self->field_1D0 = D_004C9CD0;
    UnkStruct_001CFD20_q * k = (UnkStruct_001CFD20_q *)&D_004C9CD0;
    self->field_1C0.x = k->x;
    self->field_1C0.y = k->y;
    self->field_1C0.z = k->z;
    self->field_1C0.w = 1.0f * 2.0f;
}
