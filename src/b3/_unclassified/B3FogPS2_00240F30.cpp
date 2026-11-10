// CB3Fog::RestoreRenderstates(const CB3CameraData*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3FogPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (static, quads read via const CB3CameraData* p0, *p++ GIF asm).

// CB3Fog::RestoreRenderstates(const CB3CameraData*) -- hand-matched (gif3).
// [C] name: the mangled symbol in retail's tables (high). Area not evidenced, so _unclassified/ (docs/conventions.md).
// Field names are placeholders and every type is [G] (instruction widths).
// [L] static: retail reads the saved GS register quads off a0 (= p0) and schedules those loads past the packet
// stores, which MWCC only does through a const pointer (N206); a `this` read keeps them in source order.
// GIF quads (N175): pcpyld asm straight into *p++, loaded low halves register-first.

typedef unsigned int u_long128 __attribute__((mode(TI)));

struct CB3CameraData {
    unsigned char pad_0[0x1C0];
    u_long128 field_1C0;
    u_long128 field_1D0;
    u_long128 field_1E0;
    u_long128 field_1F0;
};

struct UnkStruct_farFogPlane { u_long128 * field_0; };
struct UnkStruct_skyAlpha_1 { unsigned long field_0; };
struct UnkStruct_skyTest_1 { unsigned long field_0; };
struct UnkStruct_skyTex1_1 { unsigned long field_0; };

class CB3Fog {
public:
    static void RestoreRenderstates(const CB3CameraData* p0);
};

extern UnkStruct_farFogPlane farFogPlane;
extern UnkStruct_skyAlpha_1 skyAlpha_1;
extern UnkStruct_skyTest_1 skyTest_1;
extern UnkStruct_skyTex1_1 skyTex1_1;
extern "C" void _rwDMAOpenVIFPkt(int, int);

// 0x00240F30
void CB3Fog::RestoreRenderstates(const CB3CameraData* p0)
{
    _rwDMAOpenVIFPkt(0x80000000, 8);
    u_long128 *p = farFogPlane.field_0;
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0x1000000000008007UL), "r"(14));
    *p++ = p0->field_1E0;
    *p++ = p0->field_1C0;
    *p++ = p0->field_1D0;
    *p++ = p0->field_1F0;
    asm("pcpyld %0, %1, %2" : "=r"(*p++) : "r"(66), "r"(skyAlpha_1.field_0));
    asm("pcpyld %0, %1, %2" : "=r"(*p++) : "r"(71), "r"(skyTest_1.field_0));
    asm("pcpyld %0, %1, %2" : "=r"(*p++) : "r"(71), "r"(skyTex1_1.field_0));
    farFogPlane.field_0 = p;
}
