// NONMATCHING: func_001312D0 -- retail 59 / ours 51 instructions, 36 in changed runs
// gaps1c: hand-drafted from the asm
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// gaps1c (2026-11-02): hand-drafted from the retail asm (0x1312D0..0x1313B8). Unnamed; file B3FrontEnd.cpp per
// research/retail_names.csv (high). Sets +0x2E8 = D_006662DC + 0x300, calls func_001E1FF0(D_00666228, a zeroed 4-byte
// local, 3), then -- when the current menu page D_01E90430 is one of D_01E94EF0 / D_01E95CB8 / D_01E98404, or is
// D_01E959C8 with its +4 byte set -- func_00275EF0(the world, D_01E8EBDE).
// TRACK: clean
// EQUIV: [L] written from the asm: every branch, store and call accounted for; [C] the local is zeroed byte by byte
// behind a null test of its own address (an inlined constructor's shape), kept

struct UnkStruct_001312D0 { unsigned char pad_0[0x2E8]; void * field_2E8; };

extern unsigned char * D_006662DC;
extern void * D_00666228;
extern void * D_01E90430;                     // [C] compared with page objects: the current menu page [L]
extern unsigned char D_01E94EF0[];
extern unsigned char D_01E95CB8[];
extern unsigned char D_01E98404[];
extern unsigned char D_01E959C8[];
extern unsigned char D_01E959CC;
extern signed char D_01E8EBDE;
extern unsigned char D_00522660[];            // [C] the CB3World

extern "C" void func_001E1FF0(void *, unsigned char *, int);
extern "C" void func_00275EF0(void *, int);

// 0x001312D0
extern "C" void func_001312D0(UnkStruct_001312D0 * self)
{
    self->field_2E8 = D_006662DC + 0x300;
    unsigned char k[4];
    unsigned char * q = k;
    if (q != 0) {
        int n = 4;
        do {
            *q = 0;
            n--;
            q++;
        } while (n != 0);
    }
    func_001E1FF0(D_00666228, k, 3);
    int on = 0;
    void * m = D_01E90430;
    if (m == D_01E94EF0 || m == D_01E95CB8 || m == D_01E98404) {
        on = 1;
    } else if (m == D_01E959C8) {
        on = D_01E959CC;
    }
    if (on != 0) {
        func_00275EF0(D_00522660, D_01E8EBDE);
    }
}
