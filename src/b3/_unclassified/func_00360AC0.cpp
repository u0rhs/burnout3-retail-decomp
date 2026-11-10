// Hand-written; the lifter refused it (a244 exact; linker 16-byte padding between per-function sections (a146_cmp now pads)).


#include "b3/classes/CB3SFIOCallbacks.h"
struct UnkStruct_ourGlobals {
    unsigned char pad_0[0x134];
    void *(*field_134)(int, int);
    void (*field_138)(int);
};
extern UnkStruct_ourGlobals ourGlobals;
// 0x00360AC0
extern "C" void func_00360AC0(int p0, int p1)
{
    ourGlobals.field_138(p1);
}
// 0x00360AE0
// [C] returns what ourGlobals.field_134 returns: retail 0x360AF0 is `jr $v0` into it (a tail call, so v0 is the callee's).
// Callers use it as a pointer: func_004699B0 tests it (0x4699E4 `beqz $v0`), func_004636E0 stores it (0x463794
// `sw $v0, 0($s2)`), func_00465960 stores it in D_004E2FC4 (0x465988). [L] an allocator (heap p1, flag 0).
extern "C" void * func_00360AE0(int p0, int p1, int a2 /* passed by every caller, not read here */)
{
    return ourGlobals.field_134(p1, 0);
}
// 0x00360B00
extern "C" int func_00360B00()
{
    CB3SFIOCallbacks::gmeLastOperation = 0;
    return 0;
}
