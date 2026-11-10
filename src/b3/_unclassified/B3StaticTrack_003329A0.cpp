// BUILD-HOST: wine
// N165 [C]: temporary exception -- this source matches retail only under wine; under the reference host
// (native Windows / wibo) two registers swap. To do: re-shape the source to match natively, then drop the marker.
// CB3StaticTrack::Update() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3StaticTrack.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (frame-anim update: names via blk->field_18 (N113) for strlen/atoi; count>1 branch first; dir==-1 block first; element pointer e declared outside the loop (inside, MWCC swaps i/e registers); backward-step frame number as signed char).

// CB3StaticTrack::Update() -- hand-finished.
class CB3StaticTrack;
struct UnkStruct_003329A0_2;
struct UnkStruct_003329A0_e1;

struct UnkStruct_D_00522680 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003329A0_2 {
    unsigned char pad_0[0x8];
    UnkStruct_003329A0_e1 * field_8;
    unsigned char pad_C[0x2];
    short field_E;
    short * field_10;
};

struct UnkStruct_003329A0_e1 {
    unsigned char pad_0[0xC];
    int * field_C;
    signed char field_10;
    signed char field_11;
    signed char field_12;
    signed char field_13;
    float field_14;
    float field_18;
    float field_1C;
    unsigned char pad_20[0x4];
    unsigned short field_24;
    unsigned char pad_26[0x2];
};

class CB3StaticTrack {
public:
    void Update();

    unsigned char pad_0[0x4];
    UnkStruct_003329A0_2 * field_4;
};

// [G] the block at +0x90 of each record; a name at +0x18 (cf. N113, B3SunRendererPS2_0024D390).
struct UnkStruct_003329A0_blk {
    unsigned char pad_0[0x18];
    char field_18[8];
};

extern UnkStruct_D_00522680 D_00522680;

extern "C" unsigned int strlen(const char *);
extern "C" int atoi(const char *);

// 0x003329A0
void CB3StaticTrack::Update()
{
    float t = D_00522680.field_0;
    if (field_4 == 0) return;
    if (field_4->field_E <= 0) return;
    UnkStruct_003329A0_e1 * e;
    for (int i = 0; i < field_4->field_E; i++) {
        e = &field_4->field_8[field_4->field_10[i]];
        if (e->field_11 > 1) {
            if (!(t <= e->field_1C + e->field_18)) {
                e->field_1C = t;
                if (e->field_24 & 0x100) {
                    e->field_10 += e->field_13;
                    signed char d = e->field_13;
                    if (d == 1 && !(e->field_10 < e->field_11 - 1)) {
                        e->field_13 = -1;
                    } else if (d == -1 && e->field_10 <= 0) {
                        e->field_13 = 1;
                        e->field_12 = 1;
                    }
                    signed char k = e->field_10;
                    signed char n = (k + 1) % e->field_11;
                    if (e->field_13 == -1) {
                        if (n != 0) {
                            const char * s = ((UnkStruct_003329A0_blk *)(e->field_C[k] + 0x90))->field_18;
                            signed char r = atoi(s + strlen(((UnkStruct_003329A0_blk *)(e->field_C[0] + 0x90))->field_18));
                            e->field_18 = e->field_14 * (float)(e->field_12 - r);
                            e->field_12 = r;
                        } else {
                            e->field_18 = e->field_14;
                        }
                    } else {
                        const char * s = ((UnkStruct_003329A0_blk *)(e->field_C[n] + 0x90))->field_18;
                        int r = atoi(s + strlen(((UnkStruct_003329A0_blk *)(e->field_C[0] + 0x90))->field_18));
                        e->field_18 = e->field_14 * (float)((signed char)r - e->field_12);
                        e->field_12 = r;
                    }
                } else {
                    e->field_10 = (e->field_10 + 1) % e->field_11;
                    signed char n = (e->field_10 + 1) % e->field_11;
                    signed char v;
                    if (n != 0) {
                        const char * s = ((UnkStruct_003329A0_blk *)(e->field_C[n] + 0x90))->field_18;
                        v = atoi(s + strlen(((UnkStruct_003329A0_blk *)(e->field_C[0] + 0x90))->field_18));
                        e->field_18 = e->field_14 * (float)(v - e->field_12);
                    } else {
                        e->field_18 = e->field_14;
                        v = 1;
                    }
                    e->field_12 = v;
                }
            }
        } else {
            if (e->field_24 & 0x200) {
                float f = t * e->field_14;
                if (!(f < e->field_1C + e->field_18)) {
                    if (0.0f == e->field_18) {
                        e->field_1C = f;
                    } else {
                        e->field_1C += e->field_18;
                    }
                }
            }
        }
    }
}
