// CB3TrackRenderer::ReallySetupCameraData() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3TrackRendererRuntimePS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (gif4: mesh-cache push inline (const u_long128&, global-indexed field_0++), D_00667050 16-byte struct, head statement order).

// CB3TrackRenderer::ReallySetupCameraData() -- hand-matched (gif4).
// [C] name: the mangled symbol in retail's tables. Area not evidenced, so _unclassified/ (docs/conventions.md).
// Field names are placeholders and every type is [G] (instruction widths).
// Mesh-cache push = one static inline taking `const u_long128 &` (`m->field_10[m->field_0++] = q` through the
// global each time); statement order D_00667050 store, base address, cache reset, first quad.
typedef unsigned int u_long128 __attribute__((mode(TI)));
struct UnkStruct_gpMeshCache { int field_0; unsigned char pad_4[0xC]; u_long128 field_10[1]; };
struct UnkStruct_D_00665EC0 { u_long128 field_0[35]; };
class CB3TrackRenderer {
public:
    void ReallySetupCameraData();
    unsigned char pad_0[0x99];
    signed char field_99;
    unsigned char pad_9A[0x6];
    unsigned long field_A0;
    unsigned long field_A8;
    unsigned long field_B0;
};
extern UnkStruct_gpMeshCache * _gpMeshCache;
extern UnkStruct_D_00665EC0 D_00665EC0[];
struct UnkStruct_D_00667050 { int field_0; unsigned char pad_4[0xC]; };  // [G] size: retail addresses it with lui/%lo
extern UnkStruct_D_00667050 D_00667050;
static inline void func_0026BAA0_inl1(const u_long128 &q)
{
    _gpMeshCache->field_10[_gpMeshCache->field_0++] = q;
}

// 0x0026BAA0
void CB3TrackRenderer::ReallySetupCameraData()
{
    int i;
    D_00667050.field_0 = field_99;
    char * base = (char *)&D_00665EC0[field_99] + 0x470;
    u_long128 * src = (u_long128 *)(base + 0x120);
    _gpMeshCache->field_0 = 0;
    u_long128 q0;
    asm("pcpyld %0, %2, %1" : "=r"(q0) : "r"(0x1000000AUL), "r"(0x6C0A03F601000404UL));
    func_0026BAA0_inl1(q0);
    for (i = 0; i < 10; i++) {
        func_0026BAA0_inl1(src[i]);
    }
    u_long128 q1;
    asm("pcpyld %0, %2, %1" : "=r"(q1) : "r"(0x10000005UL), "r"(0x5000000500000000UL));
    u_long128 q2;
    asm("pcpyld %0, %2, %1" : "=r"(q2) : "r"(0x1000000000008004UL), "r"(0xE));
    func_0026BAA0_inl1(q1);
    func_0026BAA0_inl1(q2);
    u_long128 q3;
    asm("pcpyld %0, %2, %1" : "=r"(q3) : "r"((unsigned long)*(u_long128 *)(base + 0x1C0) | field_A0), "r"(0x4C));
    func_0026BAA0_inl1(q3);
    u_long128 q4;
    asm("pcpyld %0, %2, %1" : "=r"(q4) : "r"((unsigned long)*(u_long128 *)(base + 0x1D0) | field_B0), "r"(0x4E));
    func_0026BAA0_inl1(q4);
    func_0026BAA0_inl1(*(u_long128 *)(base + 0x1E0));
    func_0026BAA0_inl1(*(u_long128 *)(base + 0x1F0));
}
