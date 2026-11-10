// GetNumAttachedHeadsets__18CGtLogitechHeadsetFv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_002C20E0_0;

struct UnkStruct_002C20E0_0 {
    unsigned char pad_0[0x160];
};

extern "C" int lgAudEnumerate(int, UnkStruct_002C20E0_0 *);

// 0x002C20E0
extern "C" int GetNumAttachedHeadsets__18CGtLogitechHeadsetFv()
{
    UnkStruct_002C20E0_0 local;  // [G] the frame's one local (size: up to the frame top)
    int m0 = 0;
    while (lgAudEnumerate(m0, &local) == 0) {
        m0 = (m0 + 1);
    }
    return m0;
}
