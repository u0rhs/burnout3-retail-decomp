// Hand-written; the lifter refused it (hand-written; siblings func_00336C20).

struct UnkStruct_func_003369F0 {
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual int vfunc_14();
    unsigned char pad_4[0x10C];
    unsigned char field_110;
    unsigned char field_111;
    unsigned char field_112;
    unsigned char pad_113[0x1];
    int field_114;
    unsigned char pad_118[0x8];
    unsigned char field_120;
    unsigned char pad_121[0x4FB];
    int field_61C;
};
struct UnkStruct_Loc { char * field_0; };
struct UnkStruct_func_003366E0 { unsigned char pad_0[0x10]; };
extern UnkStruct_func_003366E0 func_003366E0;
extern "C" void func_0040CF08(int, int);
extern "C" int func_0040CDB8(int, int, int, int);
extern "C" int func_0040D020(int, int, int, int, void *, int, void *, UnkStruct_func_003369F0 *);

// 0x003369F0
extern "C" int func_003369F0(UnkStruct_func_003369F0 * self, int p0, int p1, int p2)
{
    char buf[2] = {0, 0};
    UnkStruct_Loc loc = {0};
    loc.field_0 = buf;
    func_0040CF08(self->field_61C, 1);
    if (func_0040CDB8(self->field_61C, p0, p1, p2) != 0) {
        return 1;
    }
    self->field_110 = 1;
    self->field_111 = 0;
    self->field_112 = 0;
    self->field_120 = 0;
    self->field_114 = 0;
    if (func_0040D020(self->field_61C, 0, 0, 1, &loc, 1, &func_003366E0, self) != 0) {
        return 1;
    }
    return self->vfunc_14();
}
