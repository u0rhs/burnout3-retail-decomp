// Hand-written; the lifter refused it (locals as one struct {err,pad,bufA[0x40],bufB[0x100],bufC[0x440]} (err lowest); ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(char* in, ushort* out, n) CR/LF normalisation; if/else with shared return 1).

extern "C" int func_0041BE30(int);
extern "C" void func_0041BE38(int *);
extern "C" void DirtyDnasShutdown();
extern "C" void ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(char *, unsigned short *, int);
extern "C" int Length__10CGtUnicodeFPCUs(unsigned short *);
struct UnkStruct_26BEE0 {
    unsigned char pad_0[0x329DC];
    unsigned short *field_329DC;
    unsigned char pad_329E0[0x329EC - 0x329E0];
    int field_329EC;
    unsigned char pad_329F0[0x329F8 - 0x329F0];
    int field_329F8;
};
// 0x0026BEE0
extern "C" int func_0026BEE0(UnkStruct_26BEE0 *self)
{
    struct { int err; int pad; char bufA[0x40]; char bufB[0x100]; char bufC[0x440]; } L;
    bool busy = func_0041BE30(0) != 0;
    if (busy) return 0;
    func_0041BE38(&L.err);
    DirtyDnasShutdown();
    if (L.err >= 0) {
        self->field_329EC = 9;
    } else {
        self->field_329EC = 10;
        ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(L.bufA, self->field_329DC, 0x544);
        int n = Length__10CGtUnicodeFPCUs(self->field_329DC);
        if (self->field_329DC[n - 1] == 0xD) n--;
        self->field_329DC[n] = 0xA;
        n = n + 1;
        ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(L.bufB, self->field_329DC + n, 0x544 - n);
        n = Length__10CGtUnicodeFPCUs(self->field_329DC);
        if (self->field_329DC[n - 1] == 0xD) n--;
        self->field_329DC[n] = 0xA;
        n = n + 1;
        ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(L.bufC, self->field_329DC + n, 0x544 - n);
        if (L.err == -0x69 || L.err == -0x269 || L.err == -0x25B) {
            self->field_329F8 = self->field_329F8 << 1;
        }
    }
    return 1;
}
