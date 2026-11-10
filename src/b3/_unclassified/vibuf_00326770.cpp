// viBufReset -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> vibuf.c.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (vibuf reset, HW macros, 16-byte tag stride).

struct UnkStruct_r1 { long long field_0; long long field_8; int field_10; int field_14; };
struct UnkStruct_r0 { unsigned int field_0; char *field_4; int field_8; int field_C; int field_10; int field_14; unsigned char pad_18[0x2C]; int field_44; unsigned char pad_48[8]; UnkStruct_r1 *field_50; int field_54; int field_58; int field_5C; };
extern "C" void func_00114E60();
extern "C" int EIntr();
#define HW(a) (*(volatile unsigned int *)(a))
// 0x00326770
extern "C" int viBufReset(UnkStruct_r0 *b)
{
    int i = 0;
    b->field_C = 0;
    b->field_10 = 0;
    b->field_14 = 0;
    b->field_44 = 1;
    b->field_58 = 0;
    b->field_5C = 0;
    for (; i < b->field_54; i++) {
        b->field_50[i].field_0 = -1;
        b->field_50[i].field_8 = -1;
        b->field_50[i].field_10 = 0;
        b->field_50[i].field_14 = 0;
    }
    int j = 0;
    for (; j < b->field_8; j++) {
        *(unsigned long *)(b->field_4 + j * 16) = ((unsigned long)((b->field_0 + (j << 16)) & 0x0FFFFFFF) << 32) | 0x30001000;
    }
    *(unsigned long *)(b->field_4 + j * 16) = ((unsigned long)((unsigned int)b->field_4 & 0x0FFFFFFF) << 32) | 0x20000000;
    HW(0x1000B420) = 0;
    HW(0x1000B410) = b->field_0 & 0x0FFFFFFF;
    HW(0x1000B430) = (unsigned int)b->field_4 & 0x0FFFFFFF;
    func_00114E60();
    HW(0x1000F590) = HW(0x1000F520) | 0x10000;
    HW(0x1000B400) = 5;
    HW(0x1000F590) = HW(0x1000F520) & 0xFFFEFFFF;
    EIntr();
    return 1;
}
