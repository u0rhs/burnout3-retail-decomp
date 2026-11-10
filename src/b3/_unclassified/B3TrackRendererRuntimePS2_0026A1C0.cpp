// CB3TrackRenderer::EndInstanceRender() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3TrackRendererRuntimePS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (ctc2.i/vcallms/cfc2.i inline asm + N140 pad local for the 0x40 frame).

struct UnkStruct_0026A1C0_pad {
    unsigned char field_0[0x4];
    UnkStruct_0026A1C0_pad() {}
    ~UnkStruct_0026A1C0_pad() {}
};
class CB3TrackRenderer {
public:
    int EndInstanceRender();
    void FlushInstances();
    unsigned char pad_0[0x80];
    int field_80;
    signed char field_84;
    unsigned char field_85;
    unsigned char field_86;
};
// 0x0026A1C0
int CB3TrackRenderer::EndInstanceRender()
{
    UnkStruct_0026A1C0_pad pad;  // [G] N140 frame-slot pad
    int i;
    for (i = 0; i < field_84; i++) {
        int v;
        asm volatile("ctc2.i %0, $vi3" : : "r"(i));
        asm volatile("vcallms 0x920");
        asm volatile("cfc2.i %0, $vi2" : "=r"(v));
        if ((unsigned short)v > 0) {
            field_85 = i;
            field_86 = v;
            FlushInstances();
        }
    }
    field_80 = 0;
    field_84 = 0;
    field_85 = 0;
    return 1;
}
