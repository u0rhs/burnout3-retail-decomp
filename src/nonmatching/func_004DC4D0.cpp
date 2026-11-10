// NONMATCHING: func_004DC4D0 -- retail 64 / ours 70 instructions, 72 in changed runs
// gaps1 (2026-11-02): generated from the retail asm by build/vt/gaps1/gen_sinit.py (symbolic execution of this branch-free
// static initialiser: every global load, store and call in retail's order; the stack staging of 16-byte constants folded).
// A C++ __sinit (.init section, 0x4D3E00-0x4DD81C): the constructor code of one translation unit's globals, kept as its
// asm label (retail's own symbol is a local __sinit_<file>). Declarations are byte arrays; types [G] from store widths.
// TRACK: clean
// EQUIV: [L] generated: every instruction modelled or the generator refuses; behaviour_audit quiet

extern unsigned char _kTransposedLeftSubCurveMatrix[];
extern unsigned char _kTransposedRightSubCurveMatrix[];

// 0x004DC4D0
extern "C" void func_004DC4D0()
{
    *(float *)_kTransposedLeftSubCurveMatrix = 1.0f;
    *(float *)(_kTransposedLeftSubCurveMatrix + 0x4) = 0.5f;
    *(float *)(_kTransposedLeftSubCurveMatrix + 0x8) = 0.25f;
    *(float *)(_kTransposedLeftSubCurveMatrix + 0xC) = 0.125f;
    *(float *)(_kTransposedLeftSubCurveMatrix + 0x10) = 0.0f;
    *(float *)(_kTransposedLeftSubCurveMatrix + 0x14) = 0.5f;
    *(float *)(_kTransposedLeftSubCurveMatrix + 0x18) = 0.5f;
    *(float *)(_kTransposedLeftSubCurveMatrix + 0x1C) = 0.375f;
    *(float *)(_kTransposedLeftSubCurveMatrix + 0x20) = 0.0f;
    *(float *)(_kTransposedLeftSubCurveMatrix + 0x24) = 0.0f;
    *(float *)(_kTransposedLeftSubCurveMatrix + 0x28) = 0.25f;
    *(float *)(_kTransposedLeftSubCurveMatrix + 0x2C) = 0.375f;
    *(float *)_kTransposedRightSubCurveMatrix = 0.125f;
    *(float *)(_kTransposedRightSubCurveMatrix + 0x4) = 0.0f;
    *(float *)(_kTransposedRightSubCurveMatrix + 0x8) = 0.0f;
    *(float *)(_kTransposedRightSubCurveMatrix + 0xC) = 0.0f;
    *(float *)(_kTransposedRightSubCurveMatrix + 0x10) = 0.375f;
    *(float *)(_kTransposedRightSubCurveMatrix + 0x14) = 0.25f;
    *(float *)(_kTransposedRightSubCurveMatrix + 0x18) = 0.0f;
    *(float *)(_kTransposedRightSubCurveMatrix + 0x1C) = 0.0f;
    *(float *)(_kTransposedLeftSubCurveMatrix + 0x30) = 0.0f;
    *(float *)(_kTransposedLeftSubCurveMatrix + 0x34) = 0.0f;
    *(float *)(_kTransposedLeftSubCurveMatrix + 0x38) = 0.0f;
    *(float *)(_kTransposedLeftSubCurveMatrix + 0x3C) = 0.125f;
    *(float *)(_kTransposedRightSubCurveMatrix + 0x20) = 0.375f;
    *(float *)(_kTransposedRightSubCurveMatrix + 0x24) = 0.5f;
    *(float *)(_kTransposedRightSubCurveMatrix + 0x28) = 0.5f;
    *(float *)(_kTransposedRightSubCurveMatrix + 0x2C) = 0.0f;
    *(float *)(_kTransposedRightSubCurveMatrix + 0x30) = 0.125f;
    *(float *)(_kTransposedRightSubCurveMatrix + 0x34) = 0.25f;
    *(float *)(_kTransposedRightSubCurveMatrix + 0x38) = 0.5f;
    *(float *)(_kTransposedRightSubCurveMatrix + 0x3C) = 1.0f;
}
