// viBufAddDMA -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> vibuf.c.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a208 source; exact once diff_vs_retail stopped masking a real addiu rX,rY,0).


struct UnkStruct_r0 { unsigned int field_0; char *field_4; int field_8; int field_C; int field_10; int field_14; unsigned char pad_18[0x28]; int field_40; int field_44; };
extern "C" void func_00114E60();
extern "C" int EIntr();
extern "C" int WaitSema(int);
extern "C" int SignalSema(int);
extern "C" int printf(const char *, ...);
extern char D_004C54D0[];
extern char D_004C54E8[];
extern char D_004C54F0[];
#define HW(a) (*(volatile unsigned int *)(a))
static inline void func_00326340_inl1(UnkStruct_r0 *b, int idx, unsigned int id)
{
    unsigned long hi = (unsigned long)(unsigned int)(b->field_0 + (idx << 16)) << 32;
    *(unsigned long *)(b->field_4 + (idx << 4)) = hi | ((unsigned long)id << 28) | 0x1000;
}
// 0x00326340
extern "C" int viBufAddDMA(UnkStruct_r0 *b)
{
    unsigned int chcr;
    int started = 0;
    WaitSema(b->field_40);
    if (b->field_44 == 0) {
        printf(D_004C54D0, D_004C54E8, 0xFF, D_004C54F0);
        for (;;) {
            asm volatile("nop");
            asm volatile("nop");
            asm volatile("nop");
            asm volatile("nop");
            asm volatile("nop");
        }
    }
    func_00114E60();
    HW(0x1000F590) = HW(0x1000F520) | 0x10000;
    HW(0x1000B400) = 5;
    HW(0x1000F590) = HW(0x1000F520) & 0xFFFEFFFF;
    EIntr();
    chcr = HW(0x1000B400);
    unsigned int madr = HW(0x1000B410);
    int done;
    if (madr == ((unsigned int)(b->field_4 + ((b->field_8 + 1) << 4)) & 0x0FFFFFFF)) {
        done = 0;
    } else {
        done = (madr - b->field_0) >> 16;
    }
    int adv = (done + b->field_8 - b->field_C) % b->field_8;
    b->field_C = (b->field_C + adv) % b->field_8;
    b->field_10 = b->field_10 - adv;
    int wr = (b->field_C + b->field_10) % b->field_8;
    int n = b->field_14 / 0x10000;
    b->field_14 = b->field_14 % 0x10000;
    if (n > 0) {
        int last = (b->field_C + b->field_10 - 1 + b->field_8) % b->field_8;
        started = 1;
        func_00326340_inl1(b, last, 3);
        started = 1;
    }
    for (int i = 0; i < n; i++) {
        func_00326340_inl1(b, wr, (i == n - 1) ? 0 : 3);
        wr = (wr + 1) % b->field_8;
    }
    b->field_10 = b->field_10 + n;
    if (b->field_10 != 0) {
        if (started != 0) {
            chcr = (chcr & 0x0FFFFFFF) | 0x30000000;
        }
        func_00114E60();
        HW(0x1000F590) = HW(0x1000F520) | 0x10000;
        HW(0x1000B400) = chcr | 0x100;
        HW(0x1000F590) = HW(0x1000F520) & 0xFFFEFFFF;
        EIntr();
    }
    SignalSema(b->field_40);
    return 1;
}
