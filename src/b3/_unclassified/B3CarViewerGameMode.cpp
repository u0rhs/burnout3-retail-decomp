// B3CarViewerGameMode.cpp -- translation unit regrouped by tools/tu_merge.py from 2 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 2 function(s) named in research/retail_names.csv -> B3CarViewerGameMode.cpp.
// Area not evidenced (no Revenge file of that name), so _unclassified/ (docs/conventions.md).
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/UnkStruct_theMemMgr.h"

struct UnkStruct_0024D4D0;
struct UnkStruct_0024D4D0_1;
struct UnkStruct_0024FDA0;
struct UnkStruct_0024FDA0_1;

struct UnkStruct_0024D4D0_1 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
};

struct UnkStruct_0024D4D0 {
    unsigned char pad_0[0x224];
    int field_224;
};

struct UnkStruct_0024FDA0_1 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
};

struct UnkStruct_0024FDA0 {
    unsigned char pad_0[0x224];
    int field_224;
};

extern UnkStruct_theMemMgr theMemMgr;
extern "C" void func_00134600(UnkStruct_0024D4D0 *);
extern "C" void func_003E8750(void *);
extern "C" void func_00134910(UnkStruct_0024FDA0 *);

// func_0024D4D0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x0024D4D0
extern "C" void func_0024D4D0(UnkStruct_0024D4D0 * self)
{
    func_00134600(self);
    ((UnkStruct_0024D4D0_1 *)((char *)self + 0x1C0))->vfunc_14();
    func_003E8750(&theMemMgr);
    self->field_224 = 24;
}

// func_0024FDA0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x0024FDA0
extern "C" void func_0024FDA0(UnkStruct_0024FDA0 * self)
{
    func_00134910(self);
    ((UnkStruct_0024FDA0_1 *)((char *)self + 0x1C0))->vfunc_8();
    self->field_224 = 1;
}
