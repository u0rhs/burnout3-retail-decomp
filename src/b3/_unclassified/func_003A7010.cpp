// func_003A7010 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (extern C callee decls by mangled name).

struct UnkStruct_D_01E88D40 { unsigned short field_0; unsigned char pad_2[0xE]; };
struct UnkStruct_003A7010_e0 { void * field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_003A7010 {
    unsigned char pad_0[0xB0];
    UnkStruct_003A7010_e0 field_B0[1];
    unsigned char pad_C0[0x826];
    unsigned char field_8E6;
};
extern UnkStruct_D_01E88D40 D_01E88D40;
extern "C" unsigned long GetCrashStageGtID__26CB3HardCodedCrashStageListFi(int);
extern "C" unsigned long GetStageGtID__25CB3HardCodedRaceStageListFii(int, int);
// 0x003A7010
// The selected stage's GtID (64-bit, v0): both branches are tail calls (`j`), so a void draft matched while dropping
// the result -- the native port's World Tour crash (func_003C6360 searched the stage list for garbage, 2026-11-08)
extern "C" unsigned long func_003A7010(UnkStruct_003A7010 * self, int p0, void *p1)
{
    unsigned short t0 = D_01E88D40.field_0;
    void * t1 = self->field_B0[t0].field_0;
    if (self->field_8E6 != 0) {
        return GetCrashStageGtID__26CB3HardCodedCrashStageListFi((int)(t1));
    } else {
        return GetStageGtID__25CB3HardCodedRaceStageListFii((int)(t1), 0);
    }
}
