// CAsyncLoadManager::Abort(unsigned int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3AsyncDataLoader.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a90: hand-written; unsigned h index; bool return).

struct UnkStruct_0013D410_1 {
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18();
    virtual void vfunc_1C(int);
    virtual void vfunc_20();
    virtual int vfunc_24();
};
struct UnkStruct_0013D4D0_e0 {
    unsigned char field_0;
    unsigned char pad_1[0x3F];
    int field_40;
    int field_44;
    int field_48;
    int field_4C;
};
class CAsyncLoadManager {
public:
    bool Abort(unsigned int);
    UnkStruct_0013D4D0_e0 field_0[1];
    unsigned char pad_50[0x730];
    UnkStruct_0013D410_1 * field_780;
    unsigned char field_784;
    unsigned char field_785;
    unsigned char pad_786[0x2];
    int field_788;
    int field_78C;
    int field_790;
};

// 0x0013CE20
bool CAsyncLoadManager::Abort(unsigned int p0)
{
    unsigned int h = field_788;
    if (p0 == field_0[h].field_4C) {
        if (field_780 != 0) {
            if (field_780->vfunc_24() == 2 || field_780->vfunc_24() == 3) {
                field_780->vfunc_20();
            }
        }
        field_784 = 1;
        field_785 = 0;
        return true;
    }
    int t = field_78C;
    if (h == t) {
        if (field_0[h].field_4C == 0) {
            return false;
        }
    }
    for (;;) {
        h++;
        if (h == 24) {
            h = 0;
        }
        int * e = &field_0[h].field_4C;
        if (p0 == *e) {
            *e = 0;
            if (h == field_78C) {
                while (field_0[field_78C].field_4C == 0 && field_78C != field_788) {
                    if (field_78C == 0) {
                        field_78C = 24;
                    }
                    field_78C = field_78C - 1;
                }
            }
            return true;
        }
        if (h == t) {
            return false;
        }
    }
}
