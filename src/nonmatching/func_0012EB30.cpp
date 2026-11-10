// NONMATCHING: func_0012EB30 -- retail 240 / ours 225 instructions, 80 in changed runs
// gaps1: hand-drafted from the asm (boot / main)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// gaps1 (2026-11-02): hand-drafted from the retail asm (0x12EB30..0x12EEEC) with the Ghidra aid. The game's entry point,
// called from crt0 (0x100208 jal) [C]; [L] main(argc, argv): a1 is dereferenced as argv[0]. It initialises the C++
// runtime, constructs the game object D_004EE040, builds the boot path from argv[0], runs func_00133190 every frame until
// it returns nonzero (presenting blank frames), then runs the per-frame update func_00132600 until D_0051BA90 is set, and
// shuts down. Names: asm labels only.
// TRACK: clean
// EQUIV: [L] written from the asm: every call, string, branch and store accounted for (the three boot-path forms, the
// four leading blank frames, the D_0051BAD7 front-end reset with its eight func_00131AC0 updates)

extern "C" int snprintf(char *, unsigned int, const char *, ...);

struct UnkStruct_0012EB30_fsm {
    // [C] D_01EA2970 is a CGtFSM; slots 0x18 / 0x1C called with (fsm, state, 0) (0x12EE1C, 0x12EE68)
    virtual void vfunc_8(); virtual void vfunc_C(); virtual void vfunc_10(); virtual void vfunc_14();
    virtual void vfunc_18(void *, int); virtual void vfunc_1C(void *, int);
};
struct UnkStruct_0012EB30_state { unsigned char pad_0[0x8]; float field_8; };
struct UnkStruct_0012EB30_s { unsigned char pad_0[0x20]; float field_20; };

extern unsigned char D_004EE040[];       // [C] the CB3Game object (Construct__7CB3GameFv a0)
extern unsigned char D_00665EC0[];       // [C] the CB3GraphicsManager
extern unsigned char D_01E32AE0[];       // [C] the CB3NetworkManager
extern char D_0066E980[0x80];            // [C] the boot path, snprintf size 0x80
extern unsigned char D_0051BA90;         // [C] D_004EE040 + 0x2DA50: quit request (the main loop runs while it is 0)
extern unsigned char D_0051BAD7;         // [C] D_004EE040 + 0x2DA97
extern int D_01E900B0;
extern const char D_004B4298[];          // [C] "%s" (retail's copy sits in runtime/libgcc .rodata, 0x4B4298)
extern UnkStruct_0012EB30_fsm D_01EA2970;
extern UnkStruct_0012EB30_state * D_01EA2974;   // [C] the FSM's current state
extern UnkStruct_0012EB30_s * D_01EA2980;
extern float D_01EA2984;
extern unsigned char D_10000[];          // [C] lui/addiu %hi/%lo(D_10000): the value 0x10000
extern unsigned char D_1FF0000[];        // [C] lui/addiu %hi/%lo(D_1FF0000): the address 0x1FF0000

extern "C" void func_00100240(void);     // [C] crt0: __initialize_cpp_rts(D_004DD820, D_004DDA98, D_004E0610, D_004E0610)
extern "C" void func_00100230(void);     // [C] crt0: j __destroy_global_chain
extern "C" void * memset(void *, int, unsigned int);
extern "C" void func_00129198(char *);   // [C] libc (in-place transform of the path; [G] case conversion)
extern "C" char * func_00127BF8(char *, char *);   // [C] libc, prototype from the proven caller func_0043FF50's file
extern "C" void Construct__7CB3GameFv(void *);
extern "C" int GetThreadId(void);
extern "C" int ChangeThreadPriority(int, int);
extern "C" void func_0019DD00(void *, float);
extern "C" void PresentDrawBuffer__18CB3GraphicsManagerFv(void *);
extern "C" void SleepThreadTillVBlank__12CGtThreadMgrFv();
extern "C" int func_00133190(void *);
extern "C" void func_00132600(void *);
extern "C" void func_00132560(void *);
extern "C" void func_00132420(void *);
extern "C" void func_001D3D70(void *);
extern "C" void func_0026F860(void *);
extern "C" void func_00131AC0(void *);
extern "C" void * GetStateFromID__6CGtFSMFUl(void *, unsigned long);

// [G] one blank frame (func_0019DD00 with -1.0f, then present)
static inline void func_0012EB30_inl1()
{
    func_0019DD00(D_00665EC0, -1.0f);
    PresentDrawBuffer__18CB3GraphicsManagerFv(D_00665EC0);
}

// 0x0012EB30
extern "C" int func_0012EB30(int argc, char ** argv)
{
    char path[0x80];

    func_00100240();
    memset(D_1FF0000, 0x65, (unsigned int)D_10000 - 0x1000);   // [C] fills 0x1FF0000..0x1FFF000 with 0x65 (a0, a1, a2)
    Construct__7CB3GameFv(D_004EE040);
    snprintf(path, 0x80, D_004B4298, argv[0]);
    func_00129198(path);
    if (func_00127BF8(path, "cdrom0:") == path) {
        snprintf(D_0066E980, 0x80, D_004B4298, path);
    } else if (func_00127BF8(path, "CDROM0:") == path) {
        path[0] = 'c';                   // [C] five sb: "CDROM0:" -> "cdrom0:"
        path[1] = 'd';
        path[2] = 'r';
        path[3] = 'o';
        path[4] = 'm';
        snprintf(D_0066E980, 0x80, D_004B4298, path);
    } else {
        snprintf(D_0066E980, 0x80, "cdrom0:\\%s;1", path);
    }
    ChangeThreadPriority(GetThreadId(), 10);
    func_0012EB30_inl1();
    func_0012EB30_inl1();
    func_0012EB30_inl1();
    func_0012EB30_inl1();
    while (func_00133190(D_004EE040) == 0) {
        SleepThreadTillVBlank__12CGtThreadMgrFv();
        func_0012EB30_inl1();
    }
    if (D_0051BA90 == 0) {               // [C] tested before the loop and at its bottom
        do {
            func_00132600(D_004EE040);
        } while (D_0051BA90 == 0);
    }
    if (D_0051BAD7 != 0) {
        D_01E900B0 = 1;
        // [C] the FSM state switch of func_0036B0A0's SetScene, state id 0x94413FA737AAA797, second argument 0
        UnkStruct_0012EB30_fsm * fsm = &D_01EA2970;
        UnkStruct_0012EB30_state * s = (UnkStruct_0012EB30_state *)GetStateFromID__6CGtFSMFUl(fsm, 0x94413FA737AAA797UL);
        if (D_01EA2974 != s) {
            fsm->vfunc_18(s, 0);
            UnkStruct_0012EB30_state * old = D_01EA2974;
            D_01EA2974 = s;
            UnkStruct_0012EB30_s * t = D_01EA2980;
            if (t != 0) {
                D_01EA2984 = t->field_20;
                if (s != 0) {
                    s->field_8 = t->field_20;
                }
            }
            fsm->vfunc_1C(old, 0);
        }
        func_00131AC0(D_004EE040);      // [C] eight calls (0x12EE7C..0x12EED0)
        func_00131AC0(D_004EE040);
        func_00131AC0(D_004EE040);
        func_00131AC0(D_004EE040);
        func_00131AC0(D_004EE040);
        func_00131AC0(D_004EE040);
        func_00131AC0(D_004EE040);
        func_00131AC0(D_004EE040);
    }
    func_00132560(D_004EE040);
    func_00132420(D_004EE040);
    if (D_0051BAD7 != 0) {
        func_001D3D70(D_004EE040);
    }
    func_0026F860(D_01E32AE0);
    func_00100230();
    return 0;
}
