// Gt2dRenderer::SetZ(float,float,float) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> Gt2dRendererPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a80: a71 clamp helpers; ourGlobals.field_0 is a pointer; statics as extern C mangled data).

// [L] DNAT: no row in new_names.csv for SetZ (clamp via pmaxw/pminw/pextlw helpers, a71 pattern)
static inline int SetZ_max(int a, int b)
{
    int r;
    asm("pmaxw %0, %1, %2" : "=r"(r) : "r"(a), "r"(b));
    return r;
}
static inline int SetZ_min(int a, int b)
{
    int r;
    asm("pminw %0, %1, %2" : "=r"(r) : "r"(a), "r"(b));
    return r;
}
static inline int SetZ_zx(int a)
{
    int r;
    asm("pextlw %0, $0, %1" : "=r"(r) : "r"(a));
    return r;
}
struct UnkStruct_ourGlobals_SetZ_p {
    unsigned char pad_0[0x8C];
    float field_8C;
    float field_90;
};
struct UnkStruct_ourGlobals_SetZ {
    UnkStruct_ourGlobals_SetZ_p *field_0;
    unsigned char pad_4[0xC];
};
extern UnkStruct_ourGlobals_SetZ ourGlobals;
extern "C" int _gnNearZ__12Gt2dRenderer;
extern "C" int _gnUserDefinedZ__12Gt2dRenderer;
extern "C" int _gnZ__12Gt2dRenderer;
extern "C" unsigned char _gbIsZTestEnabled__12Gt2dRenderer;

// 0x00217880
extern "C" void SetZ__12Gt2dRendererFfff(float p0, float p1, float p2)
{
    int v = (int)(ourGlobals.field_0->field_90 + ourGlobals.field_0->field_8C / p0);
    int z = SetZ_zx(SetZ_min(SetZ_max(v, 0), _gnNearZ__12Gt2dRenderer));
    _gnUserDefinedZ__12Gt2dRenderer = z;
    if (_gbIsZTestEnabled__12Gt2dRenderer) {
        _gnZ__12Gt2dRenderer = z;
    }
}
