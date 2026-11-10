// func_0038D630 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (FAKEMATCH [G]: two dead reads of the index (if (!i && !i) {}) give retail's index-before-value load order; see docs/known.md N144).

struct UnkStruct_0038D630_1 {
    unsigned char pad_0[0x18B8];
    unsigned short field_18B8;
    unsigned char pad_18BA[0xF2];
    signed char field_19AC;
};
struct UnkStruct_0038D630_a1 {
    unsigned char pad_0[0x13F4];
    UnkStruct_0038D630_1 * field_13F4;
};
struct UnkStruct_0038D630 {
    unsigned char pad_0[0x4C];
    short field_4C[1];
};
extern "C" void func_00392030(UnkStruct_0038D630 *, UnkStruct_0038D630_a1 *, void *);
// pass1: an OnCrashStart override (vtable slot of OnCrashStart__24CB3OfflineTeamCrashLogicFP17CB3RaceCarPhysicsP17CB3CrashStartInfo);
// its a2 (the crash-start info) goes to the base handler func_00392030 untouched
extern "C" void func_0038D630(UnkStruct_0038D630 * self, UnkStruct_0038D630_a1 * p0, void * info)
{
    func_00392030(self, p0, info);
    // FAKEMATCH [G]: dead reads of the index give retail's load order (index before value); docs/known.md N144.
    if (!p0->field_13F4->field_19AC && !p0->field_13F4->field_19AC) {}
    self->field_4C[p0->field_13F4->field_19AC] = p0->field_13F4->field_18B8;
}
