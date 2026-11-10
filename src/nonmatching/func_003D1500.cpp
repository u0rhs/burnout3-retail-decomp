// NONMATCHING: func_003D1500 -- retail 82 / ours 81 instructions, 2 in changed runs
// son1: 7 -> 2 off (81/82 instrs): movn fixed by if(==0) k=E1 else k=E0; two find-loops as static inline bool/uchar returns; left: first branch's tail lacks retail's andi 255 (ours 81 vs 82)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// 7 instrs off: retail movn a1,zero,v0 (k=1 then conditional zero) where ours emits beqz/nop/move; and single shared andi 255 tail block vs ours separate
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

enum UnkEnum_003D1500 { E0 = 0, E1 = 1 };

struct UnkStruct_D_00522660_x { unsigned char pad_0[0x10]; };
extern UnkStruct_D_00522660_x D_00522660;
struct UnkStruct_D_01ECDAC6_x { unsigned char pad_0[0x10]; };
extern UnkStruct_D_01ECDAC6_x D_01ECDAC6;
extern unsigned char *D_0064D388[];
extern "C" void func_003D1AA0(void *, int, int, int);
extern "C" void func_003D2160(void *, int, int, int);
static inline bool func_003D1500_inl1(char *self, int p0)
{
    for (int i = 0; i < 5; i++) {
        if (p0 == self[i * 0x30 + 0xA0]) return true;
    }
    return false;
}
static inline unsigned char func_003D1500_inl2(char *self, int p0)
{
    for (int i = 0; i < 5; i++) {
        if (p0 == self[i * 0x1C + 0x14]) return 1;
    }
    return 0;
}
// 0x003D1500
extern "C" bool func_003D1500(char *self, int p0, int p1)
{
    char *base = (char *)&D_00522660 + p0 * 0x27D0 + 0x12AD50;
    UnkEnum_003D1500 k = (UnkEnum_003D1500)1;
    if (p1 == 1) {
        if (*(unsigned char *)&D_01ECDAC6 != 0) return false;
        if (base[0x19AC] == 0) k = E1; else k = E0;
        func_003D1AA0(self + 0x8C, *(int *)(base + 0x1758) + *(int *)(D_0064D388[(int)k] + 0x1758), p0, 3);
        return func_003D1500_inl1(self, p0);
    }
    func_003D2160(self, *(int *)(base + 0x1758), p0, 3);
    return func_003D1500_inl2(self, p0);
}


