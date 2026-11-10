// Hand-written; the lifter refused it (float[2] member for the 0x30/0x38 screen-centre pair (grouped struct copy); func_0019F200 takes self (argread)).

typedef unsigned int u_long128 __attribute__((mode(TI)));
class CGtTexture;
class RwSkyVideoMode;
struct UnkStruct_skyZbuf_1 { unsigned long field_0; };
struct UnkStruct_func_00227B80_og {
    int field_0;
    void (*field_4)(int, int, int, int);
};
struct UnkStruct_ourGlobals { unsigned char pad_0[0x10]; UnkStruct_func_00227B80_og field_10; unsigned char pad_1C[0x4]; };
struct UnkStruct_theMemMgr { unsigned char pad_0[0x10]; };
struct UnkStruct_gTextureCache { unsigned char pad_0[0x10]; };
struct UnkStruct_func_00227B80_v2 { float field_0[2]; };  // [G] sig2: a float[2] member makes the struct copy load both lanes before storing (retail)
extern UnkStruct_skyZbuf_1 skyZbuf_1;
extern UnkStruct_ourGlobals ourGlobals;
extern UnkStruct_theMemMgr theMemMgr;
extern UnkStruct_gTextureCache gTextureCache;
extern int _gnIntcHandler;

class CB3GraphicsManager {
public:
    enum EClutID { UnkEClutID_0 };
    u_long128 Copy8BitTextureAsPSMT8H(CGtTexture *, unsigned int, EClutID, unsigned int);
    u_long128 CopyTextureAs32Bit(CGtTexture *, unsigned int, unsigned int);
    u_long128 Copy4BitTextureAsPSMT4H(CGtTexture *, unsigned int, EClutID, bool, unsigned int);
    void SetVideoModeParams(RwSkyVideoMode *);

    unsigned char pad_0[0x1C];
    unsigned char field_1C[8];
    float field_24_pad;
    float field_28_pad;
    float field_2C_pad;
    UnkStruct_func_00227B80_v2 field_30;
    UnkStruct_func_00227B80_v2 field_38;
    CGtTexture * field_40;
    CGtTexture * field_44;
    CGtTexture * field_48;
    CGtTexture * field_4C;
    unsigned char pad_50[0x368];
    int field_3B8;
    unsigned char pad_3BC[0x14];
    u_long128 field_3D0;
    u_long128 field_3E0;
    u_long128 field_3F0;
    u_long128 field_400;
    unsigned int field_410;
    unsigned int field_414;
    unsigned int field_418;
    unsigned int field_41C;
    int field_420;
    unsigned char pad_424[8];
    int field_42C;
};

extern "C" void func_0019F200(void *);
extern "C" void RpSkyTexCacheRasterUnlockAll();
extern "C" void RpSkyTexCacheFlush();
extern "C" void RemoveIntcHandler(int, int);
extern "C" int AddIntcHandler(int, void *, int);
extern "C" RwSkyVideoMode *RpSkyGetModeStructurePtr();
extern "C" void RwEngineSetVideoMode(int);
extern "C" void ReleaseBlock__19CB3MemoryManagerPS2F14EB3MemoryBlocki(void *, int, int);
extern "C" void Update__19CB3MemoryManagerPS2Fv(void *);
extern "C" int AcquireBlock__19CB3MemoryManagerPS2F14EB3MemoryBlocki(void *, int, int);
extern "C" int GetBlockSize__19CB3MemoryManagerPS2CF14EB3MemoryBlock(void *, int);
extern "C" void sceGsSyncV(int);
extern "C" void RpSkyTexCacheDisable(int);
extern "C" void _rwDMAPreAlloc(int, int, int);
extern "C" void _rwDMAYieldCallbackSet(void *);
extern "C" void func_00228040(int, int);
extern "C" int func_0022B830(int);
extern "C" void func_0019F240(void *);
extern "C" void func_0019E990(void *);
extern "C" unsigned int RpSkyTexCacheGetStartAddress();
extern "C" void RpSkyTexCacheSetStartAddress(unsigned int);
extern "C" void Destruct__15CGtTextureCacheFv(void *);
extern "C" void Construct__15CGtTextureCacheFUiii(void *, unsigned int, int, int);
extern "C" void func_0021D8E0();
extern "C" void func_0024B2A0();
extern "C" void Construct__15CGtScreenCentreFv(void *);
extern "C" float GetPositionX__15CGtScreenCentreFv(void *);
extern "C" float GetPositionY__15CGtScreenCentreFv(void *);

// 0x00227B80
extern "C" void func_00227B80(CB3GraphicsManager * self, int mode)
{
    if (self->field_3B8 == mode) return;
    self->field_3B8 = mode;
    UnkStruct_func_00227B80_og * const og = &ourGlobals.field_10;
    func_0019F200(self);
    RpSkyTexCacheRasterUnlockAll();
    RpSkyTexCacheFlush();
    int h = _gnIntcHandler;
    if (h != -1) {
        RemoveIntcHandler(2, h);
        _gnIntcHandler = -1;
    }
    og->field_4(0x12, 0, 0, 0);
    og->field_4(3, 0, 0, 0);
    self->SetVideoModeParams(RpSkyGetModeStructurePtr());
    RwEngineSetVideoMode(-1);
    ReleaseBlock__19CB3MemoryManagerPS2F14EB3MemoryBlocki(&theMemMgr, 0x19, 0);
    self->field_42C = 0;
    for (int i = 0; i < 2; i++) {
        Update__19CB3MemoryManagerPS2Fv(&theMemMgr);
        sceGsSyncV(0);
    }
    RpSkyTexCacheDisable(1);
    self->field_42C = AcquireBlock__19CB3MemoryManagerPS2F14EB3MemoryBlocki(&theMemMgr, 0x19, 0);
    _rwDMAPreAlloc(GetBlockSize__19CB3MemoryManagerPS2CF14EB3MemoryBlock(&theMemMgr, 0x19), 0x180, self->field_42C);
    _rwDMAYieldCallbackSet((void *)func_00228040);
    self->field_420 = GetBlockSize__19CB3MemoryManagerPS2CF14EB3MemoryBlock(&theMemMgr, 0x19);
    og->field_4(2, 0, 0, 0);
    og->field_4(0x11, 0, 0, 0);
    _gnIntcHandler = AddIntcHandler(2, (void *)func_0022B830, 0);
    func_0019F240(self);
    func_0019E990(self);
    self->field_410 = RpSkyTexCacheGetStartAddress();
    self->field_414 = self->field_410 + 0x6000;
    self->field_418 = self->field_414 + 0x800;
    self->field_41C = self->field_418 + 0x10000;
    unsigned int sa = self->field_41C + 0x10000;
    RpSkyTexCacheSetStartAddress(sa);
    Destruct__15CGtTextureCacheFv(&gTextureCache);
    Construct__15CGtTextureCacheFUiii(&gTextureCache, sa, 0x1E, 0x180);
    self->field_410 = self->field_410 >> 6;
    self->field_414 = self->field_414 >> 6;
    self->field_418 = self->field_418 >> 6;
    self->field_41C = self->field_41C >> 6;
    func_0021D8E0();
    func_0024B2A0();
    if (self->field_4C != 0) {
        self->field_3D0 = self->Copy8BitTextureAsPSMT8H(self->field_4C, (int)(skyZbuf_1.field_0 & 0x1FF) << 5, (CB3GraphicsManager::EClutID)4, 0);
    }
    if (self->field_40 != 0) {
        self->field_3E0 = self->CopyTextureAs32Bit(self->field_40, self->field_410 + 0x11C, 0);
    }
    if (self->field_44 != 0) {
        self->field_3F0 = self->Copy4BitTextureAsPSMT4H(self->field_44, self->field_410, (CB3GraphicsManager::EClutID)2, false, 3);
    }
    if (self->field_48 != 0) {
        self->field_400 = self->Copy4BitTextureAsPSMT4H(self->field_48, self->field_410 + 0xC0, (CB3GraphicsManager::EClutID)2, true, 3);
    }
    Construct__15CGtScreenCentreFv(self->field_1C);
    self->field_30.field_0[0] = GetPositionX__15CGtScreenCentreFv(self->field_1C);
    self->field_30.field_0[1] = GetPositionY__15CGtScreenCentreFv(self->field_1C);
    self->field_38 = self->field_30;
}
