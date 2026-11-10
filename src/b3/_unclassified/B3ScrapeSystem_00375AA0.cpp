// BUILD-HOST: wine
// N165 [C]: temporary exception -- this source matches retail only under wine; under the reference host
// (native Windows / wibo) two registers swap. To do: re-shape the source to match natively, then drop the marker.
// CB3ScrapeSystem::Render() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3ScrapeSystem.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (find-by-name with goto found (N113 block cast); t0 declared before the const pointer to D_01EA4910 (register order); emitter array walked by a pointer passed to Render).

enum EB3ScrapeType {};

class CB3ScrapeEmitter;
class CB3ScrapeParams;
class CB3ScrapeRenderer;
class CB3ScrapeSystem;
struct UnkStruct_00375AA0_1;
struct UnkStruct_00375AA0_e0;
struct UnkStruct_D_00518688;

class CB3ScrapeRenderer {
public:
    static void BeginRender();
    static void Render(CB3ScrapeEmitter**, int, CB3ScrapeParams*, EB3ScrapeType);
    static void EndRender();
};

struct UnkStruct_D_00518688 {
    UnkStruct_00375AA0_1 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00375AA0_1 {
    unsigned char pad_0[0x8];
    int field_8;
    UnkStruct_00375AA0_e0 * field_C;
};

struct UnkStruct_00375AA0_e0 {
    unsigned char pad_0[0x8];
    int field_8;
    unsigned char pad_C[0x4];
};

// [G] the block at +0x90 of each entry's object; a name at +0x18 (cf. N113).
struct UnkStruct_00375AA0_blk {
    unsigned char pad_0[0x18];
    char field_18[8];
};

class CB3ScrapeParams {
public:
    unsigned char pad_0[0x20];
    char field_20[0xC];
    int field_2C;
};

struct UnkStruct_00375AA0_b {
    unsigned char pad_0[0x210];
};

class CB3ScrapeEmitter {
public:
    unsigned char pad_0[0x12];
    short field_12;
    unsigned char pad_14[0xC];
    UnkStruct_00375AA0_b field_20[2];
    UnkStruct_00375AA0_b * field_440;
    UnkStruct_00375AA0_b * field_444;
};

class CB3ScrapeSystem {
public:
    void Render();

    unsigned char pad_0[0x8A8C];
    CB3ScrapeEmitter * field_8A8C[32];
    int field_8B0C;
};

extern UnkStruct_D_00518688 D_00518688;
extern CB3ScrapeParams D_01EA4910;

extern "C" int strcasecmp(const char *, const char *);

// 0x00375AA0
void CB3ScrapeSystem::Render()
{
    UnkStruct_00375AA0_1 * t0 = D_00518688.field_0;
    CB3ScrapeParams * const p = &D_01EA4910;
    int i;
    int t2;
    for (i = 0; i < t0->field_8; i++) {
        t2 = t0->field_C[i].field_8;
        if (strcasecmp(((UnkStruct_00375AA0_blk *)(t2 + 0x90))->field_18, p->field_20) == 0) {
            goto found;
        }
    }
    t2 = 0;
found:
    p->field_2C = t2;
    CB3ScrapeRenderer::BeginRender();
    int n = field_8B0C;
    if (n > 0) {
        CB3ScrapeEmitter ** pp = field_8A8C;
        CB3ScrapeRenderer::Render(pp, n, &D_01EA4910, (EB3ScrapeType)0);
        for (int j = 0; j < n; j++) {
            CB3ScrapeEmitter * e = *pp++;
            e->field_12 = 1 - e->field_12;
            e->field_440 = &e->field_20[e->field_12];
            e->field_444 = &e->field_20[1 - e->field_12];
        }
    }
    CB3ScrapeRenderer::EndRender();
}
