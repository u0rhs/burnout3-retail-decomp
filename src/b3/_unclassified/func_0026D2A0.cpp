// Hand-written; the lifter refused it (L274: from asm after func_0026C480; two state switches in block order, per-site returns, field_329D0 int).

// func_0026D2A0 -- [G] perhaps CB3NetworkManager::UpdateDNASStatus() (research/nahelam_check.csv row marked reject;
// not a name source). File: build/tu_map.json places it in B3NetworkManager.cpp between proven neighbours.
// Hand-written (L274) from the asm after the proven siblings func_0026C480 / func_0026C190 (same object layout at
// +0x329D0, same three-line error-string block). Two state switches (abort path / normal path) with jump-table cases
// in retail's block order; every exit returns the state field; field_329D0 typed int (a pointer keeps the release
// block inline where retail has it out of line). Field names are placeholders; every type is [G].

struct UnkStruct_D_004F60C0_o {
    virtual void vfunc_8();
    virtual int vfunc_C();
};
struct UnkStruct_D_004F60C0 { UnkStruct_D_004F60C0_o *field_0; unsigned char pad[0xC]; };
struct UnkStruct_D_0051BA44 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01E90438 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_004F6100 { unsigned char pad_0[0x10]; };
struct UnkStruct_theMemMgr { unsigned char pad_0[0x10]; };
struct UnkStruct_0026D2A0 {
    unsigned char pad_0[0x329D0];
    int field_329D0;
    char *field_329D4;
    char *field_329D8;
    unsigned short *field_329DC;
    unsigned char field_329E0;
    unsigned char pad_329E1;
    unsigned char field_329E2;
    unsigned char field_329E3;
    void *field_329E4;
    int field_329E8;
    int field_329EC;
    unsigned int field_329F0;
};
extern UnkStruct_D_004F60C0 D_004F60C0;
extern UnkStruct_D_0051BA44 D_0051BA44;
extern UnkStruct_D_01E90438 D_01E90438;
extern UnkStruct_D_004F6100 D_004F6100;
extern UnkStruct_theMemMgr theMemMgr;
extern "C" unsigned short *func_00271A00(void *, int);
extern "C" void CopyN__10CGtUnicodeFPUsiPCUs(unsigned short *, int, unsigned short *);
extern "C" int Length__10CGtUnicodeFPCUs(unsigned short *);
extern "C" unsigned short *AllocUTF16String__19CB3MenuStringBufferFi(void *, int);
extern "C" void ReleaseBlock__19CB3MemoryManagerPS2F14EB3MemoryBlocki(void *, int, int);
extern "C" void Update__17CAsyncLoadManagerFv(void *);
extern "C" void Abort__17CAsyncLoadManagerFUi(void *, unsigned int);
extern "C" int sceCdDiskReady(int);
extern "C" int func_0026BE90(UnkStruct_0026D2A0 *);
extern "C" int func_0026C480(UnkStruct_0026D2A0 *);
extern "C" int func_0026C190(UnkStruct_0026D2A0 *);
extern "C" int func_0026C0A0(UnkStruct_0026D2A0 *);
extern "C" int func_0026BEE0(UnkStruct_0026D2A0 *);

// 0x0026D2A0
extern "C" int func_0026D2A0(UnkStruct_0026D2A0 *self)
{
    if (self->field_329E2 != 0 || self->field_329E3 != 0) {
        switch (self->field_329E8) {
        case 8:
            self->field_329E8 = 7;
        case 7:
            self->field_329E8 = 5;
            break;
        case 6:
            if (func_0026BE90(self) == 0) return self->field_329E8;
            self->field_329E8 = 5;
        case 5:
            self->field_329E8 = 4;
        case 4:
            self->field_329E8 = 3;
        case 3:
            self->field_329E8 = 2;
        case 2:
            if (self->field_329F0 != 0) {
                Abort__17CAsyncLoadManagerFUi(&D_004F6100, self->field_329F0);
                self->field_329F0 = 0;
            }
            self->field_329D4 = 0;
            self->field_329D8 = 0;
            Update__17CAsyncLoadManagerFv(&D_004F6100);
            Update__17CAsyncLoadManagerFv(&D_004F6100);
            self->field_329E8 = 1;
        case 1:
            if (self->field_329D0 != 0) {
                ReleaseBlock__19CB3MemoryManagerPS2F14EB3MemoryBlocki(&theMemMgr, 0x18, 0);
                self->field_329D0 = 0;
            }
            Update__17CAsyncLoadManagerFv(&D_004F6100);
            Update__17CAsyncLoadManagerFv(&D_004F6100);
            self->field_329E8 = 0;
        case 0:
            Update__17CAsyncLoadManagerFv(&D_004F6100);
            Update__17CAsyncLoadManagerFv(&D_004F6100);
            if (self->field_329E2 != 0) {
                self->field_329E8 = 0xB;
            } else {
                self->field_329E8 = 0xA;
            }
            break;
        }
        return self->field_329E8;
    }
    switch (self->field_329E8) {
    case 0:
        self->field_329EC = 10;
        self->field_329DC = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 0x544);
        self->field_329F0 = 0;
        self->field_329E4 = 0;
        switch (D_004F60C0.field_0->vfunc_C()) {
        case 0:
        case 1:
        case 5:
            break;
        case 2:
        case 3:
        case 4:
        default:
            self->field_329E3 = 1;
            break;
        }
        {
            self->field_329EC = 10;
            CopyN__10CGtUnicodeFPUsiPCUs(self->field_329DC, 0x544, func_00271A00(&D_0051BA44, 0xD50));
            int n = Length__10CGtUnicodeFPCUs(self->field_329DC);
            self->field_329DC[n] = 0xA;
            CopyN__10CGtUnicodeFPUsiPCUs(self->field_329DC + (n + 1), 0x544 - (n + 1), func_00271A00(&D_0051BA44, 0xD51));
            n = Length__10CGtUnicodeFPCUs(self->field_329DC);
            self->field_329DC[n] = 0xA;
            CopyN__10CGtUnicodeFPUsiPCUs(self->field_329DC + (n + 1), 0x544 - (n + 1), func_00271A00(&D_0051BA44, 0xD52));
        }
        self->field_329E8 = 1;
    case 1:
        if (func_0026C480(self) == 0) return self->field_329E8;
        self->field_329E8 = 2;
    case 2:
        if (func_0026C190(self) == 0) return self->field_329E8;
        self->field_329E8 = 3;
    case 3:
        self->field_329E8 = 4;
    case 4:
        switch (D_004F60C0.field_0->vfunc_C()) {
        case 0:
        case 1:
        case 5:
            break;
        case 2:
        case 3:
        case 4:
        default:
            self->field_329E3 = 1;
            break;
        }
        {
            self->field_329EC = 10;
            CopyN__10CGtUnicodeFPUsiPCUs(self->field_329DC, 0x544, func_00271A00(&D_0051BA44, 0xD50));
            int n = Length__10CGtUnicodeFPCUs(self->field_329DC);
            self->field_329DC[n] = 0xA;
            CopyN__10CGtUnicodeFPUsiPCUs(self->field_329DC + (n + 1), 0x544 - (n + 1), func_00271A00(&D_0051BA44, 0xD51));
            n = Length__10CGtUnicodeFPCUs(self->field_329DC);
            self->field_329DC[n] = 0xA;
            CopyN__10CGtUnicodeFPUsiPCUs(self->field_329DC + (n + 1), 0x544 - (n + 1), func_00271A00(&D_0051BA44, 0xD52));
        }
        if (sceCdDiskReady(1) != 2) return self->field_329E8;
        self->field_329E8 = 5;
    case 5:
        if (func_0026C0A0(self) == 0) return self->field_329E8;
        self->field_329E8 = 6;
    case 6:
        if (func_0026BEE0(self) == 0) return self->field_329E8;
        self->field_329E8 = 8;
    case 8:
        self->field_329E8 = 7;
    case 7:
        ReleaseBlock__19CB3MemoryManagerPS2F14EB3MemoryBlocki(&theMemMgr, 0x18, 0);
        self->field_329D0 = 0;
        self->field_329E8 = self->field_329EC;
        break;
    }
    return self->field_329E8;
}
