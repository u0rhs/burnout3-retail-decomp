// CGtBuddiesPS2DirtySock::SetPresence(EGtBuddyPresence,bool) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtBuddiesPS2DirtySock.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (jtbl switch; force==false nested if).

struct UnkStruct_SP_self { unsigned char pad_0[0x64]; int field_64; unsigned char pad_68[0x68]; int field_D0_pad; };
struct UnkStruct_SP { 
    unsigned char pad_0[0x64];
    unsigned char field_64[0x64];
    unsigned char field_C8[8];
    int field_D0;
    unsigned char pad_D4[0x44];
    int field_118;
    int field_11C;
};
extern "C" void HLBApiPresenceDiff(int, void *, void *);
extern "C" int func_0041A1D0(int, int, int, void *, int);
extern "C" int ConvertHLBError__22CGtBuddiesPS2DirtySockFi(void *, int);
extern "C" int SetPresence__22CGtBuddiesPS2DirtySockF16EGtBuddyPresenceb(UnkStruct_SP *self, int p, bool force)
{
    if (force == false) { if (self->field_D0 == 6) return 0; }
    self->field_D0 = p;
    int v;
    switch (p) {
    case 0: case 6: v = 0; break;
    case 1: v = 1; break;
    case 2: v = 2; break;
    case 3: v = 3; break;
    case 4: v = 4; break;
    case 5: v = 5; break;
    default: return 5;
    }
    HLBApiPresenceDiff(self->field_118, self->field_64, self->field_C8);
    return ConvertHLBError__22CGtBuddiesPS2DirtySockFi(self, func_0041A1D0(self->field_118, v, self->field_11C, self, 0));
}
