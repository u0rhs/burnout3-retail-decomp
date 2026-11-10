// Hand-written; the lifter refused it (a74: vptr-at-0x14 virtual, 16-byte struct returned by hidden pointer, .field_C read straight off the call).

struct UnkStruct_002C1EC0_r {
    int field_0;
    int field_4;
    int field_8;
    int field_C;
};
struct UnkStruct_002C1EC0_1 {
    unsigned char pad_0[0x14];
    // vptr at +0x14: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8(int, int, int, int);
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18();
    virtual void vfunc_1C();
    virtual void vfunc_20();
    virtual void vfunc_24();
    virtual void vfunc_28();
    virtual void vfunc_2C();
    virtual UnkStruct_002C1EC0_r vfunc_30(int);
};
struct UnkStruct_002C1EC0 {
    unsigned char pad_0[0x4];
    UnkStruct_002C1EC0_1 * field_4;
    unsigned char pad_8[0x816C - 0x8];
    int field_816C;
    int field_8170;
    int field_8174;
    unsigned char pad_8178[0x81D8 - 0x8178];
    int field_81D8;
    unsigned char pad_81DC[0x8204 - 0x81DC];
    unsigned char field_8204;
};

// 0x002C1EC0
extern "C" void func_002C1EC0(UnkStruct_002C1EC0 * self, UnkStruct_002C1EC0_1 * p0, int p1, int p2, void *p3_)
{
    int p3 = (int)p3_;
    self->field_8204 = 0;
    self->field_81D8 = p3;
    self->field_8174 = p1;
    self->field_4 = p0;
    self->field_4->vfunc_8(0, 512, 0, 512);
    self->field_816C = p2;
    self->field_8170 = self->field_4->vfunc_30(self->field_816C).field_C;
}
