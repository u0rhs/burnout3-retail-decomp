// Hand-written; the lifter refused it (a95: hand-written; do-while devctl poll, reverse-order switch with per-case assignments, gp-rel struct D_004E2748).

struct UnkStruct_D_004E2918 { int field_0; };
struct UnkStruct_D_004E2748 { char * field_0; char * field_4; };
extern UnkStruct_D_004E2918 D_004E2918;
extern UnkStruct_D_004E2748 D_004E2748;
extern char D_004B7F50[];
extern char D_004B7F58[];
extern char D_004B7F30[];
extern char D_004B7F10[];
extern char D_0066EB00[];
extern "C" int sceDevctl(const char *, int, void *, int, void *, int);
extern "C" int sprintf(char *, const char *, ...);
extern "C" void _rwDMAForceBufferSwap(void);
extern "C" void func_001F43B0(void);
extern "C" void sceGsSyncV(int);
extern "C" int sceCdInit(int);
extern "C" int sceSifExitCmd(void);
extern "C" void func_001154C0(void *, int, void *);

// 0x001D3D70
extern "C" void func_001D3D70(void)
{
    int r;
    do {
        r = sceDevctl(D_004B7F50, 0x4402, 0, 0, 0, 0);
        if (r == -0x13) break;
    } while (r < 0);
    int n;
    switch (D_004E2918.field_0) {
    default:
    case 0: n = 0; break;
    case 4: n = 1; break;
    case 3: n = 2; break;
    case 5: n = 3; break;
    case 6: n = 4; break;
    case 10: n = 5; break;
    case 11: n = 6; break;
    }
    sprintf(D_0066EB00, D_004B7F58, n);
    D_004E2748.field_0 = D_0066EB00;
    D_004E2748.field_4 = D_004B7F30;
    int i = 20;
    do {
        _rwDMAForceBufferSwap();
        func_001F43B0();
        sceGsSyncV(0);
        sceGsSyncV(0);
    } while (--i > 0);
    sceCdInit(5);
    sceSifExitCmd();
    func_001154C0(D_004B7F10, 2, &D_004E2748);
}
