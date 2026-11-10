// CGtRandom -- declarations only, for its inline Random(). Folder: _unclassified/ (docs/conventions.md: no evidence of its Area).
#ifndef B3_GTRANDOM_H
#define B3_GTRANDOM_H

// [C] class/method names: E-build B3O0PCH map (CGtRandom::Random(), RandomReal(), Init(), SetSeed(unsigned int); out of
// line only there -- inlined in retail). [L] layout and member names: Burnout Revenge prototype stabs (types.h, size 8).
// [G] Random()'s body: reconstructed from retail's inlined copies (func_00321500, 0x30B560, ...): a rotate-and-add step.
class CGtRandom {
public:
    unsigned int Random()
    {
        mnHigh = (mnHigh << 16) + (mnHigh >> 16);  // in two steps: retail's final addu has the rotated value first
        mnHigh += mnLow;
        mnLow += mnHigh;
        return mnHigh;
    }
    // gapN (2026-11-01): [C] name: CGtRandom::RandomReal() (B3O0PCH map, 0x17FCF0, 112 bytes). [L] body: Random() as an unsigned int to
    // float times 2^-32 (retail _Render__17C2dObjectBoostBar 0x1A6FFC..0x1A705C x6: the bltz/srl/or/add.s unsigned conversion, then
    // mul.s by 2.3283064e-10f).
    float RandomReal() { return 2.3283064e-10f * (float)Random(); }
    int mnHigh;
    int mnLow;
};

#endif
