// GetEntryPosition__20CB3CarouselComponentFi -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source ([L] DNAT CB3CarouselComponent::GetEntryPosition(int) (a0 = hidden CGtV2d result, a1 = this); void; if(t0==0) arms, if-else-if chain 1,2,4,3 (not switch), float locals declared ox,oy,v8,v11,v2,v1,v6 for reg numbers).

// lifter variant 0
// GetEntryPosition__20CB3CarouselComponentFi -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_0042C2A0;
struct UnkStruct_0042C2A0_a1;

struct UnkStruct_0042C2A0_a1 {
    unsigned char pad_0[0x230];
    int field_230;
    int field_234;
    int field_238;
    float field_23C;
    int field_240;
    int field_244;
};

struct UnkStruct_0042C2A0 {
    float field_0;
    float field_4;
};

// [L] DNAT: CB3CarouselComponent::GetEntryPosition(int) (research/proto/new_names.csv, high); a0 = hidden CGtV2d result pointer, a1 = this
// 0x0042C2A0
extern "C" void GetEntryPosition__20CB3CarouselComponentFi(UnkStruct_0042C2A0 * self, UnkStruct_0042C2A0_a1 * p0, int p1)
{
    int t0 = p0->field_230;
    float ox;
    float oy;
    float v8;
    float v11;
    float v2;
    float v1;
    float v6;
    if (t0 == 0) {
        v6 = 232.0f;
        v2 = 90.0f;
        v1 = 128.0f;
    } else {
        v6 = 232.0f;
        v2 = 105.0f;
        v1 = 96.0f;
    }
    if (t0 == 1) {
        if (p0->field_234 == 2) {
            v6 = v6 - 0.09765625f;
        }
    }
    if (t0 == 0) {
        v8 = 100.0f;
    } else {
        v8 = 144.0f;
    }
    int t1 = p0->field_238;
    if ((unsigned int)(t1 - 3) < 2) {
        v11 = v6 + v2 * (float)(p1 - p0->field_240);
    } else {
        v11 = v6 + v2 * (float)(p1 - p0->field_244);
    }
    float t2 = p0->field_23C;
    float s = (3.0f - 2.0f * t2) * (t2 * t2);
    float s2 = (3.0f - 2.0f * s) * (s * s);
    ox = v8;
    oy = v11;
    if (t1 == 1) {
        oy = (v11 - v2) + v2 * s2;
    } else if (t1 == 2) {
        oy = (v11 + v2) - v2 * s2;
    } else if (t1 == 4) {
        ox = v8 + v1 * s2;
    } else if (t1 == 3) {
        ox = v8 - v1 * s2;
    }
    self->field_0 = ox;
    self->field_4 = oy;
}
