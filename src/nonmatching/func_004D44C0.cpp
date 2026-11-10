// NONMATCHING: func_004D44C0 -- retail 71 / ours 78 instructions, 117 in changed runs
// gaps1 (2026-11-02): generated from the retail asm by build/vt/gaps1/gen_sinit.py (symbolic execution of this branch-free
// static initialiser: every global load, store and call in retail's order; the stack staging of 16-byte constants folded).
// A C++ __sinit (.init section, 0x4D3E00-0x4DD81C): the constructor code of one translation unit's globals, kept as its
// asm label (retail's own symbol is a local __sinit_<file>). Declarations are byte arrays; types [G] from store widths.
// TRACK: clean
// EQUIV: [L] generated: every instruction modelled or the generator refuses; behaviour_audit quiet

extern unsigned char D_004E0C90[];
extern unsigned char D_004E0D5C[];
extern unsigned char D_004E0D64[];
extern unsigned char _gTargetParamPosMtx[];
extern unsigned char _gTargetParamVelMtx[];

// 0x004D44C0
extern "C" void func_004D44C0()
{
    float t1 = *(float *)D_004E0D5C;
    float t2 = *(float *)D_004E0D64;
    float t3 = *(float *)D_004E0D64;
    float t4 = *(float *)D_004E0C90;
    float t5 = *(float *)D_004E0D64;
    *(float *)(_gTargetParamPosMtx + 0x10) = 0.5f;
    *(float *)(_gTargetParamPosMtx + 0x14) = -1.0f;
    *(float *)(_gTargetParamPosMtx + 0x18) = 0.5f;
    *(float *)(_gTargetParamPosMtx + 0x1C) = 0.0f;
    *(float *)(_gTargetParamPosMtx + 0x20) = -0.5f;
    *(float *)(_gTargetParamPosMtx + 0x24) = 0.0f;
    *(float *)(_gTargetParamPosMtx + 0x28) = 0.5f;
    *(float *)(_gTargetParamPosMtx + 0x2C) = 0.0f;
    *(float *)_gTargetParamPosMtx = t1;
    *(float *)(_gTargetParamPosMtx + 0x4) = 0.5f;
    *(float *)(_gTargetParamPosMtx + 0x8) = -0.5f;
    *(float *)(_gTargetParamPosMtx + 0xC) = t2;
    *(float *)(_gTargetParamPosMtx + 0x30) = t3;
    *(float *)(_gTargetParamPosMtx + 0x34) = t4;
    *(float *)(_gTargetParamPosMtx + 0x38) = t5;
    *(float *)(_gTargetParamPosMtx + 0x3C) = 0.0f;
    *(float *)_gTargetParamVelMtx = 0.0f;
    *(float *)(_gTargetParamVelMtx + 0x4) = 0.0f;
    *(float *)(_gTargetParamVelMtx + 0x8) = 0.0f;
    *(float *)(_gTargetParamVelMtx + 0xC) = 0.0f;
    *(float *)(_gTargetParamVelMtx + 0x10) = -0.5f;
    *(float *)(_gTargetParamVelMtx + 0x14) = 1.5f;
    *(float *)(_gTargetParamVelMtx + 0x18) = -1.5f;
    *(float *)(_gTargetParamVelMtx + 0x1C) = 0.5f;
    *(float *)(_gTargetParamVelMtx + 0x20) = 1.0f;
    *(float *)(_gTargetParamVelMtx + 0x24) = -2.0f;
    *(float *)(_gTargetParamVelMtx + 0x28) = 1.0f;
    *(float *)(_gTargetParamVelMtx + 0x2C) = 0.0f;
    *(float *)(_gTargetParamVelMtx + 0x30) = -0.5f;
    *(float *)(_gTargetParamVelMtx + 0x34) = 0.0f;
    *(float *)(_gTargetParamVelMtx + 0x38) = 0.5f;
    *(float *)(_gTargetParamVelMtx + 0x3C) = 0.0f;
}
