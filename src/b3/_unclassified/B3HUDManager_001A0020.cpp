// CB3HUDManager::AddComponent(CB3HUDComponent*,int,int,int,int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3HUDManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a77: layer stride 0x70, pmaxw/pextlw helpers for gnMax*).

struct UnkStruct_001A0020_c {
    unsigned char pad_0[0xC];
    struct UnkStruct_001A0020_c *field_C;
    short field_10;
};
struct UnkStruct_001A0020_l {
    unsigned char pad_0[0x58];
    int field_58;
    int field_5C;
    int field_60;
    unsigned char pad_64[0x4];
    UnkStruct_001A0020_c *field_68;
};
extern unsigned int _gnMaxFrames;
extern unsigned int _gnMaxObjects;
extern unsigned int _gnMaxLayers;

static inline int func_001A0020_max(int a, int b)
{
    int r;
    asm("pmaxw %0, %1, %2" : "=r"(r) : "r"(a), "r"(b));
    return r;
}
static inline unsigned int func_001A0020_zx(int a)
{
    unsigned int r;
    asm("pextlw %0, $0, %1" : "=r"(r) : "r"(a));
    return r;
}

// 0x001A0020
extern "C" void AddComponent__13CB3HUDManagerFP15CB3HUDComponentiiii(void *self, UnkStruct_001A0020_c *p0, int p1, int p2, int p3, int p4)
{
    UnkStruct_001A0020_l *l = (UnkStruct_001A0020_l *)((char *)self + p1 * 112);
    p0->field_10 = l->field_58;
    l->field_58 += p2;
    l->field_5C += p3;
    l->field_60 += p4;
    p0->field_C = l->field_68;
    l->field_68 = p0;
    _gnMaxFrames = func_001A0020_zx(func_001A0020_max(_gnMaxFrames, l->field_60));
    _gnMaxObjects = func_001A0020_zx(func_001A0020_max(_gnMaxObjects, l->field_5C));
    _gnMaxLayers = func_001A0020_zx(func_001A0020_max(_gnMaxLayers, l->field_58));
}
