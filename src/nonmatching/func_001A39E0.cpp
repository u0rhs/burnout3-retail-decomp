// NONMATCHING: func_001A39E0 -- retail 47 / ours 47 instructions, 5 in changed runs
// s314: func_0044A0F0 sibling shape (inl1 sprintf/ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi for p1, then l2.field_0[0]=0; l2.field_3C=p2->field_0; Get()) -- logic+frame exact, 5 off: retail holds &l2.field_3C in v0 and the loaded p2 value in v1, ours swapped; sreg run (2 rounds), ctor/Set/inline/statement-order variants all keep the swap
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// Hand-written; the lifter refused it (written by hand (lifter refused): two 30-wchar string locals filled by a sprintf+ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi static inline; Get() results taken into locals in order).

// func_001A39E0 -- hand-written (lifter refused: sprintf argument counts). Shapes follow the matched sibling
// func_001A3AA0. Unnamed in every table, so a placeholder with C linkage; every type is [G] (instruction widths).

struct UnkStruct_001A39E0_a2 {
    int field_0;
};

struct UnkStruct_001A39E0_1 {
    short field_0[0x1E];
    int field_3C;
    UnkStruct_001A39E0_1() { field_3C = 0; }
    UnkStruct_001A39E0_1 *Get() { return field_3C != 0 ? (UnkStruct_001A39E0_1 *)field_3C : this; }
};

struct UnkStruct_D_004B77F0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

extern UnkStruct_D_004B77F0 D_004B77F0;

extern "C" int sprintf(char *, const void *, ...);
extern "C" void ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(char *, UnkStruct_001A39E0_1 *, int);
extern "C" void _FormatString__10CGtUnicodeFPUsPCUsPCUsPCUsPCUsPCUs(int, int, UnkStruct_001A39E0_1 *, UnkStruct_001A39E0_1 *, int, int);

// [G] inlined helper (name unknown): sprintf the value, then UTF-8 to wide string
static inline void func_001A39E0_inl1(UnkStruct_001A39E0_1 *l, int v)
{
    char buf[0x20];
    sprintf(buf, &D_004B77F0, v);
    ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(buf, l, 30);
}
// 0x001A39E0
extern "C" void func_001A39E0(int n0, int p0, const UnkStruct_001A39E0_a2 * p1, const UnkStruct_001A39E0_a2 * p2)
{
    UnkStruct_001A39E0_1 l1;
    func_001A39E0_inl1(&l1, p1->field_0);
    UnkStruct_001A39E0_1 l2;
    l2.field_0[0] = 0;
    l2.field_3C = p2->field_0;
    UnkStruct_001A39E0_1 *x1 = l1.Get();
    UnkStruct_001A39E0_1 *x2 = l2.Get();
    _FormatString__10CGtUnicodeFPUsPCUsPCUsPCUsPCUsPCUs(n0, p0, x1, x2, 0, 0);
}
