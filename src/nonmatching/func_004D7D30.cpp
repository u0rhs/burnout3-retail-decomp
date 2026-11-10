// NONMATCHING: func_004D7D30 -- retail 57 / ours 75 instructions, 82 in changed runs
// gaps1 (2026-11-02): generated from the retail asm by build/vt/gaps1/gen_sinit.py (symbolic execution of this branch-free
// static initialiser: every global load, store and call in retail's order; the stack staging of 16-byte constants folded).
// A C++ __sinit (.init section, 0x4D3E00-0x4DD81C): the constructor code of one translation unit's globals, kept as its
// asm label (retail's own symbol is a local __sinit_<file>). Declarations are byte arrays; types [G] from store widths.
// TRACK: clean
// EQUIV: [L] generated: every instruction modelled or the generator refuses; behaviour_audit quiet

extern unsigned char D_004C50F0[];
extern unsigned char D_004C5100[];
extern unsigned char D_004C5104[];
extern unsigned char D_004C5110[];
extern unsigned char D_004C5120[];
extern unsigned char D_004C5128[];
extern unsigned char D_004C512C[];
extern unsigned char D_004C5130[];
extern unsigned char D_004C5140[];
extern unsigned char D_004C5148[];
extern unsigned char D_004C514C[];
extern unsigned char D_004C5150[];
extern unsigned char D_004C5160[];
extern unsigned char D_004C5168[];
extern unsigned char D_004C516C[];
extern unsigned char D_004E06CC[];
extern unsigned char D_004E06D8[];

// 0x004D7D30
extern "C" void func_004D7D30()
{
    float t1 = *(float *)D_004E06CC;
    float t2 = *(float *)D_004E06D8;
    *(float *)D_004C5100 = t1;
    *(float *)D_004C5104 = t1;
    unsigned long t3 = *(unsigned long *)D_004C5100;
    *(float *)D_004C5130 = 0.0f;
    *(float *)(D_004C5130 + 0x4) = 0.0f;
    *(float *)(D_004C5130 + 0x8) = 0.0f;
    *(float *)(D_004C5130 + 0xC) = 0.25f;
    *(float *)D_004C50F0 = 0.0f;
    *(float *)(D_004C50F0 + 0x4) = 0.0f;
    *(float *)(D_004C50F0 + 0x8) = 0.0f;
    *(float *)(D_004C50F0 + 0xC) = 0.25f;
    *(float *)D_004C5110 = 0.0f;
    *(float *)(D_004C5110 + 0x4) = 0.0f;
    *(float *)(D_004C5110 + 0x8) = 0.0f;
    *(float *)(D_004C5110 + 0xC) = 0.25f;
    *(float *)D_004C5150 = 0.0f;
    *(float *)(D_004C5150 + 0x4) = 0.0f;
    *(float *)(D_004C5150 + 0x8) = 0.0f;
    *(float *)(D_004C5150 + 0xC) = 0.25f;
    *(float *)D_004C5120 = t2;
    *(float *)(D_004C5120 + 0x4) = t2;
    *(int *)D_004C5128 = (int)t3;
    *(int *)D_004C512C = (int)(t3 >> 32);
    *(unsigned int *)D_004C5140 = 0x40400000;
    *(unsigned int *)(D_004C5140 + 0x4) = 0x40400000;
    *(int *)D_004C5148 = (int)t3;
    *(int *)D_004C5168 = (int)t3;
    *(int *)D_004C514C = (int)(t3 >> 32);
    *(unsigned int *)D_004C5160 = 0x40800000;
    *(unsigned int *)(D_004C5160 + 0x4) = 0x40800000;
    *(int *)D_004C516C = (int)(t3 >> 32);
}
