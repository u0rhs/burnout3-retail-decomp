// CB3TrackRenderer::RenderInstances(signed char,const CB3InstanceData*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3TrackRendererRuntimePS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (near6 byte-exact; ctc2.ni normalised in the diff).


// CB3TrackRenderer::RenderInstances(signed char, const CB3InstanceData *) -- hand-matched (near6, from the a185/hdr8 archive).
// field_8A read as a signed char into a local before the loop body's asm; the lqc2 .. vcallms 0x138 hand-asm block sits in
// one `.set noreorder` region (cmpdiff3, N223: otherwise b119 re-extends the lb'd byte before the ctc2 [G]). Retail's
// `ctc2.ni` is the plain ctc2 opcode (N188: display name only). Frame: one N140 pad.
static inline void func_0026A610_inl1(int c) { asm("ctc2.ni %0, $vi4" : : "r"(c)); }
struct UnkStruct_0026A610_pad { unsigned char field_0[4]; UnkStruct_0026A610_pad() {} ~UnkStruct_0026A610_pad() {} };
class CB3InstanceData;
class CB3TrackRenderer {
public:
    int RenderInstances(signed char, const CB3InstanceData *);
    void FlushInstances();
    unsigned char pad_0[0x84];
    signed char field_84;
    unsigned char field_85;
    unsigned char field_86;
    unsigned char pad_87[0x3];
    signed char field_8A;
};
// 0x0026A610
int CB3TrackRenderer::RenderInstances(signed char n, const CB3InstanceData * p)
{
    UnkStruct_0026A610_pad pad;
    signed char i;
    for (i = 0; i < n; i++) {
        int c = field_8A;
        asm(".set noreorder");
        asm("lqc2 $vf15, 0(%0)" : : "r"(p));
        asm("lqc2 $vf16, 16(%0)" : : "r"(p));
        asm("lqc2 $vf17, 32(%0)" : : "r"(p));
        asm("lqc2 $vf18, 48(%0)" : : "r"(p));
        func_0026A610_inl1(c);
        asm("pref 0, 64(%0)" : : "r"(p));
        asm("vcallms 0x138"); asm(".set reorder");
        p = (const CB3InstanceData *)((const char *)p + 0x40);
        int j;
        for (j = 0; (signed char)j < field_84; j = (signed char)(j + 1)) {
            int v;
            asm("ctc2.i %0, $vi3" : : "r"(j));
            asm("vcallms 0x920");
            asm("cfc2.i %0, $vi2" : "=r"(v));
            if ((short)v >= 0x46) {
                field_85 = j;
                field_86 = v;
                FlushInstances();
            }
        }
    }
    return 1;
}
