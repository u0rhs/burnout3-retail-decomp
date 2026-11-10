// CB3AILane::IncrementSegmentIndexClamped(unsigned short,short) const -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3AILane.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (pmaxw/pminw/pextlw asm helpers + (t+cnt)%cnt wrap).

struct UnkStruct_00145E70_road {
    unsigned char pad_0[0xC];
    unsigned short field_C;
    unsigned char field_E;
};
static inline int func_00145E70_max(int a, int b)
{
    int r;
    asm("pmaxw %0, %1, %2" : "=r"(r) : "r"(a), "r"(b));
    return r;
}
static inline int func_00145E70_min(int a, int b)
{
    int r;
    asm("pminw %0, %1, %2" : "=r"(r) : "r"(a), "r"(b));
    return r;
}
static inline unsigned int func_00145E70_zx(int a)
{
    unsigned int r;
    asm("pextlw %0, $0, %1" : "=r"(r) : "r"(a));
    return r;
}
class CB3AILane {
public:
    unsigned short IncrementSegmentIndexClamped(unsigned short, short) const;
    unsigned char pad_0[4];
    UnkStruct_00145E70_road *field_4;
};
// 0x00145E70
unsigned short CB3AILane::IncrementSegmentIndexClamped(unsigned short p0, short p1) const
{
    if (p1 == 0) {
        return p0;
    }
    UnkStruct_00145E70_road *r = field_4;
    int t = p0 + p1;
    int v;
    if (r->field_E != 0) {
        v = (t + r->field_C) % r->field_C;
    } else {
        v = func_00145E70_zx(func_00145E70_min(func_00145E70_max(t, 0), r->field_C - 1));
    }
    return (unsigned short)(short)v;
}
