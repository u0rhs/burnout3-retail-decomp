// func_003C9210 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_01E900B8.h"
#include "b3/classes/UnkStruct_D_01E900C8.h"
#include "b3/classes/UnkStruct_D_01E900E0.h"
#include "b3/classes/UnkStruct_D_01E90198.h"
#include "b3/classes/UnkStruct_D_01E901F0.h"
#include "b3/classes/UnkStruct_D_01E901FC.h"
#include "b3/classes/UnkStruct_D_01E94E4C.h"
#include "b3/classes/UnkStruct_D_01E94E50.h"
#include "b3/classes/UnkStruct_D_01E94E54.h"
#include "b3/classes/UnkStruct_D_01E94E58.h"
#include "b3/classes/UnkStruct_D_01E94E5C.h"
#include "b3/classes/UnkStruct_D_01E94E60.h"
#include "b3/classes/UnkStruct_D_01E94E64.h"
#include "b3/classes/UnkStruct_D_01E94E68.h"
#include "b3/classes/UnkStruct_D_01E94E84.h"
#include "b3/classes/UnkStruct_D_01E94E85.h"
#include "b3/classes/UnkStruct_D_01E94E86.h"
#include "b3/classes/UnkStruct_D_01E94E87.h"
#include "b3/classes/UnkStruct_D_01E96F78.h"

struct UnkStruct_003C9210;

struct UnkStruct_003C9210 {
    unsigned char pad_0[0x10];
    unsigned char field_10;
};

extern UnkStruct_D_01E900E0 D_01E900E0;
extern UnkStruct_D_01E90198 D_01E90198;
extern UnkStruct_D_01E901F0 D_01E901F0;
extern UnkStruct_D_01E900C8 D_01E900C8;
extern UnkStruct_D_01E901FC D_01E901FC;
extern UnkStruct_D_01E94E50 D_01E94E50;
extern UnkStruct_D_01E94E58 D_01E94E58;
extern UnkStruct_D_01E94E5C D_01E94E5C;
extern UnkStruct_D_01E94E84 D_01E94E84;
extern UnkStruct_D_01E94E60 D_01E94E60;
extern UnkStruct_D_01E94E85 D_01E94E85;
extern UnkStruct_D_01E94E64 D_01E94E64;
extern UnkStruct_D_01E94E86 D_01E94E86;
extern UnkStruct_D_01E94E87 D_01E94E87;
extern UnkStruct_D_01E94E68 D_01E94E68;
extern UnkStruct_D_01E900B8 D_01E900B8;
extern UnkStruct_D_01E94E54 D_01E94E54;
extern UnkStruct_D_01E96F78 D_01E96F78;
extern UnkStruct_D_01E94E4C D_01E94E4C;
extern "C" void func_00433230(void *);
extern "C" void Construct__21CB3GenericVSelectPageFv(void *);
extern "C" int func_003C98D0(void *);

// 0x003C9210
extern "C" void func_003C9210(UnkStruct_003C9210 * self)
{
    self->field_10 = 0;
    D_01E900E0.field_0 = 0;
    D_01E90198.field_0 = 0;
    D_01E901F0.field_0 = 0;
    D_01E900C8.field_0 = 5;
    D_01E901FC.field_0 = 0;
    func_00433230(&D_01E96F78);
    Construct__21CB3GenericVSelectPageFv(&D_01E94E4C);
    D_01E94E50.field_0 = 4;
    D_01E94E58.field_0 = 350;
    D_01E94E5C.field_0 = 351;
    D_01E94E84.field_0 = 0;
    D_01E94E60.field_0 = 353;
    D_01E94E85.field_0 = 0;
    D_01E94E64.field_0 = 352;
    D_01E94E86.field_0 = 0;
    D_01E94E68.field_0 = 357;
    D_01E94E87.field_0 = 0;
    switch (D_01E900B8.field_0) {
    default:
        D_01E94E54.field_0 = 0;
        break;
    case 1:
        D_01E94E54.field_0 = 1;
        break;
    case 2:
        D_01E94E54.field_0 = 2;
        break;
    case 3:
        D_01E94E54.field_0 = 3;
        break;
    }
    func_003C98D0(&D_01E94E4C);
}
