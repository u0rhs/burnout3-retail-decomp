// CB3AITargetSpline::GetSplineIndices(const CB3AILaneStruct*,unsigned short,int*) const -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3AITarget.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a91 hand-written; pmaxw/pminw clamp, wrap arm first).

// CB3AITargetSpline::GetSplineIndices(const CB3AILaneStruct*, unsigned short, int*) const -- hand-written (lifter refused).
struct CB3AILaneStruct {
    unsigned char pad_0[0xC];
    unsigned short field_C;
    unsigned char field_E;
};
static inline int a91_max(int a, int b)
{
    int r;
    asm("pmaxw %0, %1, %2" : "=r"(r) : "r"(a), "r"(b));
    return r;
}
static inline int a91_min(int a, int b)
{
    int r;
    asm("pminw %0, %1, %2" : "=r"(r) : "r"(a), "r"(b));
    return r;
}
static inline unsigned int a91_zx(int a)
{
    unsigned int r;
    asm("pextlw %0, $0, %1" : "=r"(r) : "r"(a));
    return r;
}
class CB3AITargetSpline {
public:
    bool GetSplineIndices(const CB3AILaneStruct *, unsigned short, int *) const;
};
// 0x00149B50
bool CB3AITargetSpline::GetSplineIndices(const CB3AILaneStruct *ls, unsigned short seg, int *out) const
{
    int n = ls->field_C;
    if (n < 6) {
        return false;
    }
    if (ls->field_E != 0) {
        int s = seg;
        out[0] = s - 1;
        out[1] = s;
        out[2] = s + 1;
        out[3] = s + 2;
        out[4] = s + 3;
        out[5] = s + 4;
        if (s == n - 4) {
            out[5] = 0;
        } else if (s == n - 3) {
            out[4] = 0;
            out[5] = 1;
        } else if (s == n - 2) {
            out[3] = 0;
            out[4] = 1;
            out[5] = 2;
        } else if (s == n - 1) {
            out[2] = 0;
            out[3] = 1;
            out[4] = 2;
            out[5] = 3;
        } else if (s == 0) {
            out[0] = n - 1;
        }
    } else {
        int c = (unsigned short)a91_zx(a91_min(a91_max(seg, 1), n - 5));
        out[0] = c - 1;
        out[1] = c;
        out[2] = c + 1;
        out[3] = c + 2;
        out[4] = c + 3;
        out[5] = c + 4;
    }
    return true;
}
