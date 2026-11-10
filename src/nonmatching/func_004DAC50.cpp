// NONMATCHING: func_004DAC50 -- retail 136 / ours 149 instructions, 134 in changed runs
// gaps1 (2026-11-02): generated from the retail asm by build/vt/gaps1/gen_sinit.py (symbolic execution of this branch-free
// static initialiser: every global load, store and call in retail's order; the stack staging of 16-byte constants folded).
// A C++ __sinit (.init section, 0x4D3E00-0x4DD81C): the constructor code of one translation unit's globals, kept as its
// asm label (retail's own symbol is a local __sinit_<file>). Declarations are byte arrays; types [G] from store widths.
// TRACK: clean
// EQUIV: [L] generated: every instruction modelled or the generator refuses; behaviour_audit quiet

struct UnkStruct_004DAC50_q { unsigned int w[4]; };   // a 16-byte lq/sq copy
extern unsigned char D_004CA130[];
extern unsigned char D_004CA134[];
extern unsigned char D_004CA138[];
extern unsigned char D_004CA13C[];
extern unsigned char D_004CA160[];
extern unsigned char D_004CA164[];
extern unsigned char D_004CA168[];
extern unsigned char D_004CA16C[];
extern unsigned char D_004CA170[];
extern unsigned char D_004CA174[];
extern unsigned char D_004CA178[];
extern unsigned char D_004CA17C[];
extern unsigned char D_004CA180[];
extern unsigned char D_004CA184[];
extern unsigned char D_004CA188[];
extern unsigned char D_004CA18C[];
extern unsigned char D_004CA190[];
extern unsigned char D_004CA194[];
extern unsigned char D_004CA198[];
extern unsigned char D_004CA19C[];
extern unsigned char D_004CA1A0[];
extern unsigned char D_004CA1A4[];
extern unsigned char D_004CA1A8[];
extern unsigned char D_004CA1AC[];
extern unsigned char D_004CA1B0[];
extern unsigned char D_004CA1B4[];
extern unsigned char D_004CA1B8[];
extern unsigned char D_004CA1BC[];
extern unsigned char D_004CA1C0[];
extern unsigned char D_004CA1C4[];
extern unsigned char D_004CA1C8[];
extern unsigned char D_004CA1CC[];
extern unsigned char D_004CA1D0[];
extern unsigned char D_004CA1D8[];
extern unsigned char D_004CA1E0[];
extern unsigned char D_004CA1E8[];
extern unsigned char D_004CA1F0[];
extern unsigned char D_004CA1F8[];
extern unsigned char D_004CA200[];
extern unsigned char D_004CA204[];
extern unsigned char D_004CA208[];
extern unsigned char D_004CA20C[];
extern unsigned char D_004E06A8[];
extern unsigned char D_004E08B0[];
extern unsigned char krB3GlobeSpherePosition[];
extern unsigned char krB3GlobeZoomEndPosition[];

// 0x004DAC50
extern "C" void func_004DAC50()
{
    *(float *)D_004CA130 = 4.0f;
    *(float *)D_004CA134 = 4.0f;
    *(float *)D_004CA138 = 480.0f;
    *(float *)D_004CA13C = 120.0f;
    UnkStruct_004DAC50_q t1;   // lanes 3: never written, copied as retail does
    *(float *)&t1.w[0] = 75.0f;
    *(float *)&t1.w[1] = -10.0f;
    *(float *)&t1.w[2] = 500.0f;
    *(float *)D_004CA160 = 410.0f;
    UnkStruct_004DAC50_q t2;   // lanes 3: never written, copied as retail does
    *(float *)&t2.w[0] = 0.0f;
    *(float *)&t2.w[1] = 0.0f;
    *(float *)&t2.w[2] = 101.0f;
    *(float *)D_004CA168 = 48.0f;
    *(UnkStruct_004DAC50_q *)krB3GlobeSpherePosition = t1;
    *(float *)D_004CA16C = 48.0f;
    *(UnkStruct_004DAC50_q *)krB3GlobeZoomEndPosition = t2;
    *(float *)D_004CA170 = 0.5f;
    *(float *)D_004CA164 = (float)343;
    *(float *)D_004CA174 = 0.5f;
    *(float *)D_004CA178 = 1.0f;
    *(float *)D_004CA17C = 1.0f;
    *(float *)D_004CA180 = 480.0f;
    *(float *)D_004CA184 = (float)343;
    *(float *)D_004CA18C = (float)343;
    *(float *)D_004CA190 = 32.0f;
    *(float *)D_004CA194 = 32.0f;
    *(float *)D_004CA198 = 140.0f;
    *(float *)D_004CA1A0 = 72.0f;
    *(float *)D_004CA188 = (float)530;
    *(float *)D_004CA1A4 = 72.0f;
    *(float *)D_004CA19C = (float)343;
    *(float *)D_004CA1A8 = 0.5f;
    float t3 = *(float *)D_004E08B0;
    *(float *)D_004CA1B8 = 213.0f;
    *(float *)D_004CA1AC = 0.5f;
    *(float *)D_004CA1B0 = 1.0f;
    *(float *)D_004CA1B4 = 1.0f;
    *(float *)D_004CA1BC = (float)343;
    *(float *)D_004CA1C0 = 255.0f;
    *(float *)D_004CA1C4 = (float)343;
    *(float *)D_004CA1C8 = 32.0f;
    float t4 = *(float *)D_004E06A8;
    *(float *)D_004CA1CC = 32.0f;
    *(float *)D_004CA1D0 = 0.5f;
    *(float *)(D_004CA1D0 + 0x4) = 0.0f;
    *(float *)D_004CA1D8 = 1.0f;
    *(float *)(D_004CA1D8 + 0x4) = 0.5f;
    *(float *)D_004CA1E0 = 0.0f;
    *(float *)(D_004CA1E0 + 0x4) = 0.0f;
    *(float *)D_004CA1E8 = 0.5f;
    *(float *)(D_004CA1E8 + 0x4) = 0.5f;
    *(float *)D_004CA1F0 = 0.0f;
    *(float *)(D_004CA1F0 + 0x4) = 0.5f;
    *(float *)D_004CA1F8 = 0.5f;
    *(float *)(D_004CA1F8 + 0x4) = 1.0f;
    *(float *)D_004CA200 = 1.0f;
    *(float *)D_004CA208 = 0.0f;
    *(float *)D_004CA204 = t4;
    *(float *)D_004CA20C = t3;
}
