// viBufStopDMA -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> vibuf.c.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (volatile HW() register macros, sibling of viBufDelete).

struct UnkStruct_c0 { unsigned char pad_0[0x1C]; int field_1C; int field_20; int field_24; int field_28; int field_2C; int field_30; int field_34; int field_38; int field_3C; int field_40; int field_44; };
extern "C" void func_00114E60();
extern "C" int EIntr();
extern "C" int WaitSema(int);
extern "C" int SignalSema(int);
#define HW(a) (*(volatile unsigned int *)(a))
// 0x00326220
extern "C" int viBufStopDMA(UnkStruct_c0 *b, void *a1, void *a2, void *a3 /* passed by every caller, not read here */)
{
    WaitSema(b->field_40);
    b->field_44 = 0;
    func_00114E60();
    HW(0x1000F590) = HW(0x1000F520) | 0x10000;
    HW(0x1000B400) = 5;
    HW(0x1000F590) = HW(0x1000F520) & 0xFFFEFFFF;
    EIntr();
    b->field_1C = HW(0x1000B410);
    b->field_20 = HW(0x1000B430);
    b->field_24 = HW(0x1000B420);
    b->field_28 = HW(0x1000B400);
    while ((HW(0x10002010) & 0xF0) != 0) {}
    func_00114E60();
    HW(0x1000F590) = HW(0x1000F520) | 0x10000;
    HW(0x1000B000) = 0;
    HW(0x1000F590) = HW(0x1000F520) & 0xFFFEFFFF;
    EIntr();
    b->field_2C = HW(0x1000B010);
    b->field_30 = HW(0x1000B020);
    b->field_34 = HW(0x1000B000);
    b->field_38 = HW(0x10002020);
    b->field_3C = HW(0x10002010);
    SignalSema(b->field_40);
    return 1;
}
