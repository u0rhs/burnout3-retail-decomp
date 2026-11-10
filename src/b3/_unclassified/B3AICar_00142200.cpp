// CB3AICar::UpdateAICheckpoint() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3AICar.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a91 hand-written, pabsw/pextlw helpers).

// CB3AICar::UpdateAICheckpoint() -- hand-written (lifter refused).
struct UnkStruct_D_0064D344 { int field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_0064D344 D_0064D344;
struct UnkStruct_00142200_e { unsigned short field_0; unsigned char pad_2[0xE]; };
struct UnkStruct_00142200_t { unsigned char pad_0[8]; int field_8; unsigned char pad_C[4]; unsigned int field_10; unsigned char pad_14[0x1C]; UnkStruct_00142200_e arr[1]; };
static inline int a91_pabsw(int x)
{
    int r;
    asm("pabsw %0,%1" : "=r"(r) : "r"(x));
    return r;
}
static inline long a91_pextlw0(int x)
{
    unsigned long r;
    asm("pextlw %0,$0,%1" : "=r"(r) : "r"(x));
    return r;
}
class CB3AICar {
public:
    void UpdateAICheckpoint();
    unsigned char pad_0[0x10CC];
    float field_10CC;
    unsigned char pad_10D0[0x7F0];
    int field_18C0;
    unsigned char pad_18C4[0x10C];
    float field_19D0[4];
    unsigned char pad_19E0[0xA64];
    float field_2444;
    unsigned short field_2448;
    unsigned char pad_244A[2];
    signed char field_244C;
};
// 0x00142200
void CB3AICar::UpdateAICheckpoint()
{
    UnkStruct_00142200_t *t = (UnkStruct_00142200_t *)D_0064D344.field_0;
    if (t == 0 || t->field_10 == 0) {
        return;
    }
    int cur = field_18C0;
    int last = field_2448;
    long dist;
    if (cur < last) {
        dist = a91_pextlw0(a91_pabsw(last - (cur + t->field_8)));
    } else {
        dist = a91_pextlw0(a91_pabsw(last - cur));
    }
    bool found = false;
    if (field_244C != -1 && dist < 2) {
        if (t->arr[field_244C].field_0 == cur) {
            found = true;
        }
    } else {
        for (unsigned int i = 0; i < ((UnkStruct_00142200_t *)D_0064D344.field_0)->field_10; i++) {
            if (((UnkStruct_00142200_t *)D_0064D344.field_0)->arr[i].field_0 < field_18C0) {
                field_244C = i;
            }
        }
        if (field_244C != -1) {
            found = true;
        }
    }
    if (found) {
        field_19D0[field_244C] = field_10CC - field_2444;
        field_2444 = field_10CC;
        field_244C = (field_244C + 1) % ((UnkStruct_00142200_t *)D_0064D344.field_0)->field_10;
    }
    field_2448 = field_18C0;
}
