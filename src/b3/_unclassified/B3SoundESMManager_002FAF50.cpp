// CB3SoundESMManager::Construct() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundESMManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a80: High at +8, 5 Low elements (0x90) from +0xC8, unsigned for loop).

struct UnkStruct_002FAF50_low { unsigned char pad_0[0x90]; };
struct UnkStruct_002FAF50 {
    unsigned char pad_0[0xC8];
    UnkStruct_002FAF50_low field_C8[5];
};
extern "C" void Construct__15CB3SoundESMHighFv(void *);
extern "C" void Construct__14CB3SoundESMLowFv(void *);

// 0x002FAF50
extern "C" void Construct__18CB3SoundESMManagerFv(UnkStruct_002FAF50 *self)
{
    Construct__15CB3SoundESMHighFv((char *)self + 8);
    for (unsigned int i = 0; i < 5; i++) {
        Construct__14CB3SoundESMLowFv(&self->field_C8[i]);
    }
}
