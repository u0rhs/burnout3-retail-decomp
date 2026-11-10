// CGtLogitechHeadset::Prepare(int,int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtLogitechHeadset.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (vptr at +0x14 (vfunc_34/38); OpenHeadset declared int here (bool adds andi); status-update inline after lgAudClose).

extern "C" void lgAudInit(int, int);
extern "C" void lgAudClose(int);
class CGtLogitechHeadset {
public:
    bool Prepare(int, int);
    int OpenHeadset(int);
    unsigned char pad_0[0x10];
    int field_10;
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18();
    virtual void vfunc_1C();
    virtual void vfunc_20();
    virtual void vfunc_24();
    virtual void vfunc_28();
    virtual void vfunc_2C();
    virtual void vfunc_30();
    virtual void vfunc_34(int);
    virtual int vfunc_38();
    unsigned char pad_18[0x164];
    int field_17C;
    int field_180;
    unsigned char pad_184[0x800];
    unsigned char field_984;
};
// 0x002C26D0
bool CGtLogitechHeadset::Prepare(int a, int dev)
{
    if (field_984 == 0) {
        lgAudInit(0, 0);
        field_984 = 1;
    }
    if (dev == -1) {
        int n = vfunc_38();
        dev = 0;
        while (dev < n) {
            if (OpenHeadset(dev) != 0) break;
            dev++;
        }
        if (dev == n) {
            if (field_17C != -1) {
                lgAudClose(field_17C);
                field_17C = -1;
                if (field_17C != -1 && field_180 != 0) {
                    field_10 = 2;
                } else if (field_17C == -1) {
                    field_10 = 0;
                } else if (field_180 == 0) {
                    field_10 = 1;
                }
            }
            return false;
        }
    } else {
        if (OpenHeadset(dev) == 0) return false;
    }
    vfunc_34(a);
    return true;
}
