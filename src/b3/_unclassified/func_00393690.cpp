// OnCrashStart__26CB3OfflineSingleCrashLogicFP17CB3RaceCarPhysicsP17CB3CrashStartInfo -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (decomp-permuter (build/vt/permsetup.py)).

extern "C" {

typedef struct UnkStruct_00393690 UnkStruct_00393690;
typedef struct UnkStruct_00393690_1 UnkStruct_00393690_1;
typedef struct UnkStruct_00393690_a1 UnkStruct_00393690_a1;
struct UnkStruct_00393690;
struct UnkStruct_00393690_1;
struct UnkStruct_00393690_a1;
struct UnkStruct_00393690_a1
{
  unsigned char pad_0[0x13F4];
  UnkStruct_00393690_1 *field_13F4;
};
struct UnkStruct_00393690_1
{
  unsigned char pad_0[0x18B8];
  unsigned short field_18B8;
  unsigned char pad_18BA[0xF2];
  signed char field_19AC;
};
struct UnkStruct_00393690
{
  unsigned char pad_0[0x4C];
  short field_4C[1];
};
void HandleCrashStart__8CB3ScoreFP17CB3CrashStartInfo(void *, void *);
void OnCrashStart__26CB3OfflineSingleCrashLogicFP17CB3RaceCarPhysicsP17CB3CrashStartInfo(UnkStruct_00393690 *self, UnkStruct_00393690_a1 *p0, int p1)
{
  HandleCrashStart__8CB3ScoreFP17CB3CrashStartInfo(((char *) p0->field_13F4) + 0x10C0, (void *)(p1));
  // FAKEMATCH [G] (decomp-permuter, 2026-10-24): two dead reads of the index make retail's load order
  // (index before value); probably the remnant of a compiled-out check (an assert macro?). See docs/known.md N144.
  if (!p0->field_13F4->field_19AC && !p0->field_13F4->field_19AC)
  {
  }
  self->field_4C[p0->field_13F4->field_19AC] = p0->field_13F4->field_18B8;
}

}
