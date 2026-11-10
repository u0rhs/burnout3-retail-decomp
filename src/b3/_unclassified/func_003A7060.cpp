// func_003A7060 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (extern C callee decls by mangled name).

struct UnkStruct_003A7060 {
    unsigned char pad_0[0x25C];
    void * field_25C;
    unsigned char pad_260[0x686];
    unsigned char field_8E6;
};
extern "C" unsigned long GetStageGtID__25CB3HardCodedRaceStageListFii(int, int);
extern "C" unsigned long GetStageTrackID__25CB3HardCodedRaceStageListFUl(unsigned long);
extern "C" unsigned long GetCrashStageGtID__26CB3HardCodedCrashStageListFi(int);
extern "C" unsigned long GetCrashStageTrackID__26CB3HardCodedCrashStageListFUl(unsigned long);
// 0x003A7060
// w64 (2026-11-02): returns the stage's 64-bit track id [C retail 0x3A70A4: v0 from GetStageTrackID/GetCrashStageTrackID; func_003F9F70 uses it].
extern "C" unsigned long func_003A7060(UnkStruct_003A7060 * self)
{
    if (self->field_8E6 == 0) {
        unsigned long r0 = GetStageGtID__25CB3HardCodedRaceStageListFii((int)(self->field_25C), 0);
        return GetStageTrackID__25CB3HardCodedRaceStageListFUl(r0);
    } else {
        unsigned long r2 = GetCrashStageGtID__26CB3HardCodedCrashStageListFi((int)(self->field_25C));
        return GetCrashStageTrackID__26CB3HardCodedCrashStageListFUl(r2);
    }
}
