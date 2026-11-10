// CB3DebrisRenderer::UploadCodeAndCameraData() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3DebrisRendererPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (GIF quads as pcpyld asm into *p++ throughout (incl. the copy loop)).

// CB3DebrisRenderer::UploadCodeAndCameraData() -- hand-matched (gif3).
// [C] name: the mangled symbol in retail's tables (high). Area not evidenced, so _unclassified/ (docs/conventions.md).
// Field names are placeholders and every type is [G] (instruction widths).
// GIF/VIF packet (N175): one pcpyld asm per quad straight into *p++ (constants lo-first, literal halves; MWCC
// shares the lui 0x1000 between halves itself), the camera block copied with *p++ = *src++, pointer written back once.
typedef unsigned int u_long128 __attribute__((mode(TI)));
struct UnkStruct_farFogPlane { u_long128 *field_0; };
struct UnkStruct_skyUserSwitch1 { void *field_0; };
struct UnkStruct_D_00667050 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_00665EC0 { unsigned char pad_0[0x10]; };
extern UnkStruct_farFogPlane farFogPlane;
extern UnkStruct_skyUserSwitch1 skyUserSwitch1;
extern UnkStruct_D_00667050 D_00667050;
extern UnkStruct_D_00665EC0 D_00665EC0;
extern char vu_game_00475910[];
class CB3DebrisRenderer { public: void UploadCodeAndCameraData(); };
// 0x002F3B60
void CB3DebrisRenderer::UploadCodeAndCameraData()
{
    u_long128 *p = farFogPlane.field_0;
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(((unsigned long)(unsigned int)vu_game_00475910 << 32) | 0x50000000UL), "r"(0UL));
    skyUserSwitch1.field_0 = vu_game_00475910;
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0x10000000UL), "r"(0x15000000UL));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0x1000000AUL), "r"(0x6C0A03F601000101UL));
    u_long128 *src = (u_long128 *)((char *)&D_00665EC0 + D_00667050.field_0 * 0x230 + 0x590);
    for (int i = 0; i < 10; i++) {
        *p++ = *src++;
    }
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0x10000003UL), "r"(0x5000000300000000UL));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0x1000000000008002UL), "r"(0xEUL));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0x44UL), "r"(0x42UL));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0x70003UL), "r"(0x47UL));
    farFogPlane.field_0 = p;
}
