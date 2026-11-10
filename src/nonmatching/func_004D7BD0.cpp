// NONMATCHING: func_004D7BD0 -- retail 88 / ours 93 instructions, 96 in changed runs
// gaps1 (2026-11-02): generated from the retail asm by build/vt/gaps1/gen_sinit.py (symbolic execution of this branch-free
// static initialiser: every global load, store and call in retail's order; the stack staging of 16-byte constants folded).
// A C++ __sinit (.init section, 0x4D3E00-0x4DD81C): the constructor code of one translation unit's globals, kept as its
// asm label (retail's own symbol is a local __sinit_<file>). Declarations are byte arrays; types [G] from store widths.
// TRACK: clean
// EQUIV: [L] generated: every instruction modelled or the generator refuses; behaviour_audit quiet

extern unsigned char D_004C4FD0[];
extern unsigned char D_004C4FD4[];
extern unsigned char D_004C4FD8[];
extern unsigned char D_004C4FDC[];
extern unsigned char D_004C4FE0[];
extern unsigned char D_004C4FE4[];
extern unsigned char D_004E0B84[];
extern unsigned char D_004E0B88[];
extern unsigned char D_004E0B8C[];
extern unsigned char D_004E0B90[];
extern unsigned char D_004E0B94[];
extern unsigned char D_004E0B98[];
extern unsigned char D_004E0B9C[];
extern unsigned char D_004E0BA0[];
extern unsigned char D_004E0BA4[];
extern unsigned char kB3OnlineLobbyRagerTextColour[];
extern unsigned char kB3OnlineLobbyRagerTextDisabledColour[];
extern unsigned char kB3OnlineLobbyRagerTextSelectedColour[];
extern unsigned char maOffsetTable__14CB3MenuFlowFSM[];

// 0x004D7BD0
extern "C" void func_004D7BD0()
{
    *(float *)(maOffsetTable__14CB3MenuFlowFSM + 0x418) = 48.0f;
    *(float *)(maOffsetTable__14CB3MenuFlowFSM + 0x420) = 0.0f;
    *(float *)(maOffsetTable__14CB3MenuFlowFSM + 0x41C) = 192.0f;
    *(float *)(maOffsetTable__14CB3MenuFlowFSM + 0x424) = 0.0f;
    *(float *)(maOffsetTable__14CB3MenuFlowFSM + 0x428) = 544.0f;
    *(float *)(maOffsetTable__14CB3MenuFlowFSM + 0x42C) = 176.0f;
    float t1 = 48.0f + 544.0f;
    *(float *)(maOffsetTable__14CB3MenuFlowFSM + 0x434) = 192.0f;
    *(float *)(maOffsetTable__14CB3MenuFlowFSM + 0x43C) = 0.0f;
    float t2 = 8.0f + t1;
    *(float *)(maOffsetTable__14CB3MenuFlowFSM + 0x440) = 176.0f;
    *(float *)(maOffsetTable__14CB3MenuFlowFSM + 0x44C) = 176.0f;
    *(float *)(maOffsetTable__14CB3MenuFlowFSM + 0x438) = 0.5f;
    *(float *)(maOffsetTable__14CB3MenuFlowFSM + 0x430) = t2;
    *(float *)(maOffsetTable__14CB3MenuFlowFSM + 0x450) = 0.5f;
    float t3 = *(float *)D_004E0B84;
    float t4 = *(float *)D_004E0B88;
    *(float *)(maOffsetTable__14CB3MenuFlowFSM + 0x454) = 0.5f;
    float t5 = *(float *)D_004E0B8C;
    float t6 = *(float *)D_004E0B90;
    float t7 = *(float *)D_004E0B94;
    *(float *)D_004C4FD0 = 48.0f;
    float t8 = *(float *)D_004E0B98;
    *(float *)D_004C4FD4 = 192.0f;
    float t9 = *(float *)D_004E0B9C;
    float t10 = *(float *)D_004E0BA0;
    *(float *)D_004C4FE0 = 544.0f;
    float t11 = *(float *)D_004E0BA4;
    *(float *)D_004C4FE4 = 176.0f;
    *(float *)(maOffsetTable__14CB3MenuFlowFSM + 0x448) = 320.0f;
    *(float *)D_004C4FD8 = 0.0f;
    *(float *)D_004C4FDC = 0.0f;
    *(float *)kB3OnlineLobbyRagerTextColour = t3;
    *(float *)(kB3OnlineLobbyRagerTextColour + 0x4) = t4;
    *(float *)(kB3OnlineLobbyRagerTextColour + 0x8) = t5;
    *(float *)(kB3OnlineLobbyRagerTextColour + 0xC) = 1.0f;
    *(float *)kB3OnlineLobbyRagerTextSelectedColour = t6;
    *(float *)(kB3OnlineLobbyRagerTextSelectedColour + 0x4) = t7;
    *(float *)(kB3OnlineLobbyRagerTextSelectedColour + 0x8) = t8;
    *(float *)(kB3OnlineLobbyRagerTextSelectedColour + 0xC) = 1.0f;
    *(float *)kB3OnlineLobbyRagerTextDisabledColour = t9;
    *(float *)(kB3OnlineLobbyRagerTextDisabledColour + 0x4) = t10;
    *(float *)(kB3OnlineLobbyRagerTextDisabledColour + 0x8) = t11;
    *(float *)(kB3OnlineLobbyRagerTextDisabledColour + 0xC) = 1.0f;
}
