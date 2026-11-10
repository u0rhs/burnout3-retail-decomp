// NONMATCHING: func_004D8540 -- retail 78 / ours 78 instructions, 41 in changed runs
// gaps1 (2026-11-02): generated from the retail asm by build/vt/gaps1/gen_sinit.py (symbolic execution of this branch-free
// static initialiser: every global load, store and call in retail's order; the stack staging of 16-byte constants folded).
// A C++ __sinit (.init section, 0x4D3E00-0x4DD81C): the constructor code of one translation unit's globals, kept as its
// asm label (retail's own symbol is a local __sinit_<file>). Declarations are byte arrays; types [G] from store widths.
// TRACK: clean
// EQUIV: [L] generated: every instruction modelled or the generator refuses; behaviour_audit quiet

extern unsigned char D_004C5700[];
extern unsigned char D_004C5704[];
extern unsigned char D_004C5708[];
extern unsigned char D_004C570C[];
extern unsigned char D_004C5710[];
extern unsigned char D_004C5714[];
extern unsigned char D_004C5718[];
extern unsigned char D_004C571C[];
extern unsigned char D_004C5720[];
extern unsigned char D_004C5724[];
extern unsigned char kB3ChatDisplayLobbyHandle[];
extern unsigned char kB3ChatDisplayLobbyMaxSize[];
extern unsigned char kB3ChatDisplayLobbyPos[];
extern unsigned char kB3ChatDisplayLobbySize[];
extern unsigned char kB3ChatDisplayRightHandle[];
extern unsigned char kB3ChatDisplayRightPos[];
extern unsigned char kB3ChatDisplayTopHandle[];
extern unsigned char kB3ChatDisplayTopMaxSize[];
extern unsigned char kB3ChatDisplayTopPos[];
extern unsigned char kB3ChatDisplayTopSize[];

// 0x004D8540
extern "C" void func_004D8540()
{
    *(float *)kB3ChatDisplayTopPos = 48.0f;
    *(float *)(kB3ChatDisplayTopPos + 0x4) = 192.0f;
    *(float *)kB3ChatDisplayTopHandle = 0.0f;
    *(float *)(kB3ChatDisplayTopSize + 0x4) = 96.0f;
    *(float *)(kB3ChatDisplayTopHandle + 0x4) = 1.0f;
    *(float *)kB3ChatDisplayTopSize = 560.0f;
    *(float *)kB3ChatDisplayTopMaxSize = 560.0f;
    *(float *)(kB3ChatDisplayTopMaxSize + 0x4) = 240.0f;
    *(float *)kB3ChatDisplayRightPos = 304.0f;
    *(float *)(kB3ChatDisplayRightPos + 0x4) = 128.0f;
    *(float *)kB3ChatDisplayRightHandle = 0.0f;
    *(float *)(kB3ChatDisplayRightHandle + 0x4) = 0.0f;
    *(float *)D_004C5704 = 241.0f;
    *(float *)D_004C5708 = 0.0f;
    *(float *)D_004C570C = 158.0f;
    *(float *)D_004C5710 = 0.0f;
    *(float *)D_004C5700 = (float)305;
    *(float *)D_004C5714 = 1.0f;
    *(float *)D_004C5718 = 640.0f;
    *(float *)D_004C571C = 80.0f;
    *(float *)D_004C5720 = 528.0f;
    *(float *)kB3ChatDisplayLobbyHandle = 0.0f;
    *(float *)D_004C5724 = 240.0f;
    *(float *)kB3ChatDisplayLobbyPos = 0.0f;
    *(float *)(kB3ChatDisplayLobbyPos + 0x4) = 174.0f;
    *(float *)(kB3ChatDisplayLobbyHandle + 0x4) = 1.0f;
    *(float *)kB3ChatDisplayLobbySize = 640.0f;
    *(float *)(kB3ChatDisplayLobbySize + 0x4) = 96.0f;
    *(float *)kB3ChatDisplayLobbyMaxSize = 528.0f;
    *(float *)(kB3ChatDisplayLobbyMaxSize + 0x4) = 240.0f;
}
