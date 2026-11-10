// NONMATCHING: PrepareHardware__7CB3GameFv -- retail 241 / ours 241 instructions, 12 in changed runs
// a139: layout/regs exact except (1) retail puts the 'else Load(buf70,0,0)' arm out of line at function end (b back to the v<0 test) while ours emits it inline with a b over it (tried if/else swaps, ternary, goto zero label: all worse or equal); (2) diff flags two 'sw/lw a0,-32640(v0)' (self+0x8080 fs pointer) lines though text is equal, unknown reloc cause. Goto-based stage layout: switch(st){case 1: case 0x18: break; default: goto fin;} stage2 block inline in the middle, rest: block at end.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

struct UnkStruct_001D41E0_self {
    unsigned char pad_0[0x7080];
    unsigned char field_7080[0x10];
    unsigned char pad_7090[0x8080 - 0x7090];
    void *field_8080;
    unsigned char pad_8084[0x2DA60 - 0x8084];
    int field_2DA60;
    unsigned char pad_2DA64[0xC];
    int field_2DA70;
    unsigned char pad_2DA74[0xD];
    unsigned char field_2DA81;
};
struct UnkStruct_D_01E3D597 { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_001D41E0_out { char *field_0; char *field_4; int field_8; };
extern char *D_0049A120[];
extern char D_004B7F90[], D_004B7FC0[], D_004B7FD0[], D_004B7FE8[], D_004B7FF0[], D_004B8000[], D_004B8018[], D_004B8020[], D_004B8040[];
extern char D_004B8050[], D_004B8068[], D_004B8078[], D_004B8080[], D_004B8090[], D_004B80A0[], D_004B80D0[], D_0066EA00[];
extern char D_0066E100[0x20], D_0066E120[0x20], D_0066E180[0x20], D_01E75640[0x10], D_01E33A8C[0x10], D_01E32AE0[0x10], D_01E3C620[0x10];
extern UnkStruct_D_01E3D597 D_01E3D597;
extern "C" int mpIOPFileFuncs__19CGtFileSystemPS2DVD;
extern "C" int sceSifLoadModule(const char *, int, const char *);
extern "C" void sceSifInitIopHeap(void);
extern "C" int sprintf(char *, const char *, ...);
extern "C" int snprintf(char *, unsigned int, const char *, ...);
extern "C" char *strcat(char *, const char *);
extern "C" int strcmp(const char *, const char *);
extern "C" unsigned int strlen(const char *);
extern "C" void func_0028B580(void *);
extern "C" bool Init__19CGtFileSystemPS2DVDFUiP13CGtFilePS2DVDP19CGtFileBufferPS2DVDPCciiiPc(void *, unsigned int, void *, void *, const char *, int, int, int, char *);
extern "C" void SetAsDefaultFilesystem__13CGTFileSystemFv(void *);
extern "C" void InstallToRenderWare__13CGTFileSystemFv(void);
extern "C" void RwaPS2SetIOPFileInterface(int);
extern "C" int sceMc2Init(int);
extern "C" void Construct__21CB3NetworkVoIPManagerFP23CGtNetworkPlayerManager(void *, void *);
extern "C" int func_0022E6C0(void *, void *, int, int);
extern "C" void Construct__15CB3InputManagerFv(void *);
extern "C" void Prepare__15CB3InputManagerFv(void *);

extern "C" int PrepareHardware__7CB3GameFv(UnkStruct_001D41E0_self * self)
{
    char buf70[0x100];
    char buf50[0x20];
    UnkStruct_001D41E0_out o;
    int i;
    int s0 = 0;
    int v, r;
    int st = self->field_2DA70;
    if (st == 2) goto stage2;
    switch (st) {
    case 1:
    case 0x18:
        break;
    default:
        goto fin;
    }
    sceSifInitIopHeap();
    i = 0;
    goto test;
body:
    if (sceSifLoadModule(D_0049A120[i], 0, 0) < 0) return 0;
    i++;
test:
    if (i < 10) goto body;
    sprintf(buf50, D_004B7F90);
    strcat(buf50, D_004B7FC0);
    if (sceSifLoadModule(D_004B7FD0, 0x3B, buf50) < 0) return 0;
    goto rest;
stage2:
    func_0028B580(D_01E75640);
    self->field_8080 = D_0066E100;
    Init__19CGtFileSystemPS2DVDFUiP13CGtFilePS2DVDP19CGtFileBufferPS2DVDPCciiiPc(D_0066E100, 1, D_0066E120, D_0066E180, D_004B7FE8, 3, 0x20, 0x10, 0);
    SetAsDefaultFilesystem__13CGTFileSystemFv(self->field_8080);
    InstallToRenderWare__13CGTFileSystemFv();
    RwaPS2SetIOPFileInterface(mpIOPFileFuncs__19CGtFileSystemPS2DVD);
    self->field_2DA70 = 3;
    sceMc2Init(0);
    Construct__21CB3NetworkVoIPManagerFP23CGtNetworkPlayerManager(D_01E33A8C, D_01E32AE0);
fin:
    self->field_2DA60 = 0x17;
    return 1;
rest:
    sprintf(buf50, D_004B7FF0, 0x800);
    strcat(buf50, D_004B7FC0);
    if (sceSifLoadModule(D_004B8000, strlen(buf50) + 2, buf50) < 0) return 0;
    sprintf(buf70, D_004B8018, D_0066EA00, D_004B8020);
    sprintf(buf50, D_004B8040);
    if (sceSifLoadModule(D_004B8020, 0xE, buf50) < 0) return 0;
    {
        r = func_0022E6C0(D_01E3C620, &o, 0, 1);
        s0++;
        while (r != 0) {
            snprintf(buf70, 0x100, D_004B8050, D_004B8068, o.field_0, D_004B8078);
            int v;
            if (o.field_8 != 0) v = sceSifLoadModule(buf70, o.field_8, o.field_4);
            else v = sceSifLoadModule(buf70, 0, 0);
            if (v < 0) {
                if (strcmp(o.field_0, D_004B8080) != 0) return 0;
                D_01E3D597.field_0 = 0;
            } else {
                if (strcmp(o.field_0, D_004B8080) == 0) D_01E3D597.field_0 = 1;
            }
            r = func_0022E6C0(D_01E3C620, &o, s0, 1);
            s0++;
        }
    }
    sprintf(buf50, D_004B8090);
    strcat(buf50, D_004B7FC0);
    if (sceSifLoadModule(D_004B80A0, 0x13, D_004B80D0) < 0) return 0;
    self->field_2DA81 = 1;
    Construct__15CB3InputManagerFv(self->field_7080);
    Prepare__15CB3InputManagerFv(self->field_7080);
    self->field_2DA70 = 2;
    goto stage2;
}

