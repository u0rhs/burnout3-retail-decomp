// viBufRestartDMA -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> vibuf.c.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (near34: restructured after the SDK mpeg sample vibuf.c shape (inits before WaitSema, inlined FIFO-index/IsInRegion/WRAP forms, CHCR set helpers); field_2C volatile [G]).

// [G] field_2C volatile: retail reloads it between its null test and the D3 store (BRIEF near15 volatile-read pattern)
struct UnkStruct_r0 { unsigned int field_0; unsigned int field_4; int field_8; int field_C; int field_10; int field_14; unsigned char pad_18[0x4]; unsigned int field_1C; unsigned int field_20; unsigned int field_24; unsigned int field_28; volatile unsigned int field_2C; unsigned int field_30; unsigned int field_34; unsigned int field_38; unsigned int field_3C; int field_40; int field_44; };
extern "C" void func_00114E60();
extern "C" int EIntr();
extern "C" int WaitSema(int);
extern "C" int SignalSema(int);
#define HW(a) (*(volatile unsigned int *)(a))
// [L] shape: the SDK mpeg sample's vibuf.c (same function name); helpers below are placeholders for its inlined helpers
static inline int func_00325E90_inl1(UnkStruct_r0 *f, unsigned int addr)
{
    if (addr == ((f->field_4 + ((f->field_8 + 1) << 4)) & 0x0FFFFFFF)) {
        return 0;
    } else {
        return (addr - f->field_0) / 0x10000;
    }
}
static inline void func_00325E90_inl2(unsigned int v)
{
    func_00114E60();
    HW(0x1000F590) = HW(0x1000F520) | 0x10000;
    HW(0x1000B400) = v;
    HW(0x1000F590) = HW(0x1000F520) & ~0x10000;
    EIntr();
}
static inline void func_00325E90_inl3(unsigned int v)
{
    func_00114E60();
    HW(0x1000F590) = HW(0x1000F520) | 0x10000;
    HW(0x1000B000) = v;
    HW(0x1000F590) = HW(0x1000F520) & ~0x10000;
    EIntr();
}
// 0x00325E90
extern "C" int viBufRestartDMA(UnkStruct_r0 *f)
{
    int bp = f->field_38 & 0x7f;
    int fp = (f->field_38 >> 16) & 0x3;
    int ifc = (f->field_38 >> 8) & 0xf;
    unsigned int madr = f->field_1C - ((fp + ifc) << 4);
    unsigned int qwc = f->field_24 + (fp + ifc);
    unsigned int tadr = f->field_20;
    unsigned int chcr = f->field_28 | 0x100;
    int index;
    int index_next;
    int id;

    WaitSema(f->field_40);

    if (madr < f->field_0) {
        qwc = (f->field_0 - madr) >> 4;
        madr += (unsigned int)(f->field_8 * 0x10000);
        tadr = f->field_4 & 0x0FFFFFFF;
        id = (f->field_1C == f->field_0 || f->field_1C == f->field_0 + 0x10000 * f->field_8) ? 0 : 3;
        chcr = (f->field_28 & 0x0fffffff) | (id << 28) | 0x100;
        if (!((0 <= ((0 + f->field_8 - f->field_C) % f->field_8)) && (((0 + f->field_8 - f->field_C) % f->field_8) < f->field_10))) {
            f->field_C = f->field_8 - 1;
            f->field_10++;
        }
    } else if ((index = func_00325E90_inl1(f, f->field_1C)) != (index_next = func_00325E90_inl1(f, madr))) {
        tadr = (f->field_4 + index * 16) & 0x0FFFFFFF;
        qwc = (f->field_0 + 0x10000 * index - madr) >> 4;
        id = ((f->field_0 + ((f->field_1C - f->field_0) % (0x10000 * f->field_8))) == f->field_0 + 0x10000 * ((f->field_C + f->field_10) % f->field_8)) ? 0 : 3;
        chcr = (f->field_28 & 0x0fffffff) | (id << 28) | 0x100;
        if (!((0 <= ((index_next + f->field_8 - f->field_C) % f->field_8)) && (((index_next + f->field_8 - f->field_C) % f->field_8) < f->field_10))) {
            f->field_C = index_next;
            f->field_10++;
        }
    }

    if (f->field_2C && f->field_30) {
        HW(0x1000B010) = f->field_2C;
        HW(0x1000B020) = f->field_30;
        func_00325E90_inl3(f->field_34 | 0x100);
    }

    if (f->field_10) {
        while ((int)HW(0x10002010) < 0)
            ;
        HW(0x10002000) = bp;
        while ((int)HW(0x10002010) < 0)
            ;
    }

    HW(0x1000B410) = madr;
    HW(0x1000B430) = tadr;
    HW(0x1000B420) = qwc;
    if (f->field_10) {
        func_00325E90_inl2(chcr);
    }

    HW(0x10002010) = f->field_3C;

    f->field_44 = 1;

    SignalSema(f->field_40);

    return 1;
}
