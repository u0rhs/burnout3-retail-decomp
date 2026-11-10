// Hand-written; the lifter refused it (hand-written).

struct UnkStruct_00335FD0 {
    unsigned char pad_0[0x638];
    void * field_638;
    int field_63C;
    int field_640;
    char * field_644;
    short field_648;
};
struct UnkStruct__gMemoryAllocator { unsigned char pad_0[0x4]; };
extern UnkStruct__gMemoryAllocator _gMemoryAllocator;
// [C] NUL-terminated strings in .rodata (assembly/asm/data/game/unit_00335DE0.rodata.s): "<!DOCTYPE" at 0x4C5868,
// "<html>" at 0x4C5878; retail passes their addresses to strlen (0x3360C8 / 0x3360F0).
extern const char D_004C5868[];
extern const char D_004C5878[];
extern "C" void func_004038A0(void *);
extern "C" int func_004039E0(void *, char *, int, int);
extern "C" int func_00403950(void *, int);
extern "C" void * Malloc__9CGtMallocFUi(void *, int);
extern "C" int func_00127520(char *, const char *, int);
extern "C" unsigned int strlen(const char *);

// 0x00335FD0
extern "C" int func_00335FD0(UnkStruct_00335FD0 * self)
{
    short t = self->field_648 - 1;
    self->field_648 = t;
    if (t <= 0) return -1;
    func_004038A0(self->field_638);
    if (self->field_640 <= 0) {
        self->field_640 = func_00403950(self->field_638, 0x626F6479);
        if (self->field_640 <= 0) return 0;
    }
    if (self->field_644 == 0) {
        self->field_644 = (char *)Malloc__9CGtMallocFUi(&_gMemoryAllocator, self->field_640 + 1);
    }
    int r = func_004039E0(self->field_638, self->field_644 + self->field_63C, 1, self->field_640 - self->field_63C);
    if (r < 0) return r;
    self->field_63C = self->field_63C + r;
    if (self->field_63C + 1 < self->field_640) return 0;
    const char * const sa = D_004C5868;
    const char * const sb = D_004C5878;
    if (func_00127520(self->field_644, sa, strlen(sa)) == 0) return -1;
    if (func_00127520(self->field_644, sb, strlen(sb)) == 0) return -1;
    self->field_644[self->field_63C] = 0;
    return self->field_63C;
}
