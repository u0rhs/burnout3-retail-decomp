// viBufDelete -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> vibuf.c.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (volatile HW() absolute register macros).

struct UnkStruct_c0 { unsigned char pad_0[0x40]; int field_40; };
extern "C" void func_00114E60();
extern "C" int EIntr();
extern "C" int DeleteSema(int);
#define HW(a) (*(volatile unsigned int *)(a))
// 0x00325E10
extern "C" int viBufDelete(UnkStruct_c0 *b)
{
    func_00114E60();
    HW(0x1000F590) = HW(0x1000F520) | 0x10000;
    HW(0x1000B400) = 5;
    HW(0x1000F590) = HW(0x1000F520) & 0xFFFEFFFF;
    EIntr();
    HW(0x1000B420) = 0;
    HW(0x1000B410) = 0;
    HW(0x1000B430) = 0;
    DeleteSema(b->field_40);
    return 1;
}
