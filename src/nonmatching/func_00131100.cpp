// NONMATCHING: func_00131100 -- retail 114 / ours 110 instructions, 7 in changed runs
// gaps1c: hand-drafted from the asm
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// gaps1c (2026-11-02): hand-drafted from the retail asm (0x131100..0x1312C4). Unnamed; file B3FrontEnd.cpp per
// research/retail_names.csv (high). [L] the front end's Release by its calls: stops the intro video at +0x1C8 (unless
// +0x2F8 is already 0x18), frees the music stream and the three memory blocks func_00131480 took (0x10, 0x11, 0x12),
// releases the environment / static track, leaves front-end frame rate and resets +0x2F4 to 0x18 (func_00131480's
// first state).
// TRACK: clean
// EQUIV: [L] written from the asm: every store and call in retail's order

struct UnkStruct_00131100_lob { virtual void vfunc_8(); virtual void vfunc_C(); virtual void vfunc_10(); virtual void vfunc_14();
                                virtual void vfunc_18(); virtual void vfunc_1C(); };
struct UnkStruct_00131100 {
    unsigned char pad_0[0x1C0];
    void * field_1C0;
    void * field_1C4;
    unsigned char field_1C8[0x12C];           // [C] a CGtVideoDecoder (Update__15CGtVideoDecoderFv a0) [G] size
    int field_2F4;
    int field_2F8;                            // [C] 0x18 = no video to stop
    unsigned char pad_2FC[0x10];
    void * field_30C;                         // [C] the CGtSoundStream
    void * field_310;
    unsigned char pad_314[0x1];
    unsigned char field_315;
    unsigned char field_316;
    unsigned char field_317;
    unsigned char field_318[0x10];            // [C] a CGtLinearMalloc (Destroy__15CGtLinearMallocFv a0)
};

extern unsigned char D_01E3C660;
extern unsigned char theMemMgr[];
extern unsigned char D_01E774E0[];            // [C] the CGtSoundStreamManager
extern unsigned char D_01E3D390[];
extern UnkStruct_00131100_lob D_01E3CD44;
extern unsigned char D_01E85900[];            // [C] the CB3EnvironmentManager
extern unsigned char D_0064C990[];            // [C] the CB3StaticTrack
extern unsigned char D_004EE040[];            // [C] gGame
extern unsigned char D_01E7A888[];
extern unsigned char D_0051B928[];
extern unsigned char D_01ECD9F0[];

extern "C" void func_00324ED0(void *);
extern "C" int func_00324EE0(void *);
extern "C" void Update__15CGtVideoDecoderFv(void *);
extern "C" void Release__15CGtVideoDecoderFv(void *);
extern "C" void Destroy__15CGtLinearMallocFv(void *);
extern "C" void Stop__14CGtSoundStreamFv(void *);
extern "C" void Release__14CGtSoundStreamFv(void *);
extern "C" void FreeStream__21CGtSoundStreamManagerFP14CGtSoundStream(void *, void *);
extern "C" void ReleaseBlock__19CB3MemoryManagerPS2F14EB3MemoryBlocki(void *, int, int);
extern "C" void func_003608F0(void *);
extern "C" void Release__21CB3EnvironmentManagerFv(void *);
extern "C" void Release__14CB3StaticTrackFv(void *);
extern "C" void SetFrontendFrameRate__7CB3GameFb(void *, int);
extern "C" void func_00134600(void *);
extern "C" void func_003E8750(void *);
extern "C" void func_003F8C00(void *, int);
extern "C" void func_003FA600(void *, int);
extern "C" void func_003BB0F0(void *);
extern "C" void func_0042FA60(void *);

// 0x00131100
extern "C" void func_00131100(UnkStruct_00131100 * self)
{
    if (self->field_2F8 != 0x18) {
        func_00324ED0(self->field_1C8);
        while (func_00324EE0(self->field_1C8) == 0) {
            Update__15CGtVideoDecoderFv(self->field_1C8);
        }
        Release__15CGtVideoDecoderFv(self->field_1C8);
        Destroy__15CGtLinearMallocFv(self->field_318);
    }
    self->field_2F8 = 0x18;
    if (self->field_30C != 0) {
        Stop__14CGtSoundStreamFv(self->field_30C);
        Release__14CGtSoundStreamFv(self->field_30C);
        FreeStream__21CGtSoundStreamManagerFP14CGtSoundStream(D_01E774E0, self->field_30C);
        self->field_30C = 0;
    }
    ReleaseBlock__19CB3MemoryManagerPS2F14EB3MemoryBlocki(theMemMgr, 0x11, 0);
    self->field_310 = 0;
    Destroy__15CGtLinearMallocFv(self->field_318);
    if (D_01E3C660 != 0) {
        func_003608F0(D_01E3D390);
        ((UnkStruct_00131100_lob *)&D_01E3CD44)->vfunc_1C();
    }
    ReleaseBlock__19CB3MemoryManagerPS2F14EB3MemoryBlocki(theMemMgr, 0x10, 0);
    self->field_1C0 = 0;
    self->field_315 = 0;
    ReleaseBlock__19CB3MemoryManagerPS2F14EB3MemoryBlocki(theMemMgr, 0x12, 0);
    self->field_1C4 = 0;
    self->field_316 = 0;
    Release__21CB3EnvironmentManagerFv(D_01E85900);
    Release__14CB3StaticTrackFv(D_0064C990);
    SetFrontendFrameRate__7CB3GameFb(D_004EE040, 0);
    func_00134600(self);
    func_003E8750(theMemMgr);
    func_003F8C00(D_01E7A888, 0);
    func_003FA600(D_01E7A888, 0);
    self->field_2F4 = 0x18;
    self->field_317 = 0;
    func_003BB0F0(D_0051B928);
    func_0042FA60(D_01ECD9F0);
}
