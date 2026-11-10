// Hand-written; the lifter refused it (a73: extern C def; D_00665ECE as >8-byte struct to avoid gp-rel).

struct UnkStruct_D_004BCE20 { unsigned char pad_0[0x20]; };
struct UnkStruct_func_0026F860 { unsigned char pad_0[0x329AB]; unsigned char field_329AB; };
extern float D_004E19FC;
struct UnkStruct_D_00665ECE { unsigned char field_0; unsigned char pad_1[0xF]; };
extern UnkStruct_D_00665ECE D_00665ECE;
extern UnkStruct_D_004BCE20 D_004BCE20;
extern UnkStruct_D_004BCE20 D_004BCE40;
extern "C" void _rwDMAForceBufferSwap(void);
extern "C" void func_001F43B0(void);
extern "C" void sceGsSyncV(int);
extern "C" int sceCdInit(int);
extern "C" int sceSifExitCmd(void);
extern "C" void func_001154C0(void *, int, void *);

// 0x0026F860
extern "C" void func_0026F860(UnkStruct_func_0026F860 *p0)
{
    if (p0->field_329AB != 0) {
        float f = D_004E19FC;
        int i = 20;
        do {
            _rwDMAForceBufferSwap();
            func_001F43B0();
            sceGsSyncV(0);
            sceGsSyncV(0);
        } while (--i > 0);
        sceCdInit(5);
        sceSifExitCmd();
        if (D_00665ECE.field_0 != 0) {
            func_001154C0(&D_004BCE20, 1, &f);
        } else {
            func_001154C0(&D_004BCE40, 1, &f);
        }
    }
}
