// CGtSoundWave::GetLength() const -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtSoundWave.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (memcpy(&h,..,0x1C) jal; (uint)(1.75f*(float)u32)).

struct UnkStruct_003894D0_hdr { unsigned int field_0; unsigned int field_4; unsigned int field_8; unsigned int field_C; unsigned int field_10; unsigned int field_14; unsigned int field_18; };
struct UnkStruct_003894D0_wave { unsigned char pad_0[0x10]; UnkStruct_003894D0_hdr field_10; };
struct UnkStruct_003894D0 { unsigned long field_0; UnkStruct_003894D0_wave *field_8; };
extern "C" void * memcpy(void *, const void *, unsigned int);
extern "C" unsigned int GetLength__12CGtSoundWaveCFv(const UnkStruct_003894D0 *self)
{
    UnkStruct_003894D0_hdr h;
    memcpy(&h, &self->field_8->field_10, 0x1C);
    return (unsigned int)(1.75f * (float)h.field_8);
}
