// CGtBuddiesPS2DirtySock::GetPresence(char*,EGtBuddyPresence*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtBuddiesPS2DirtySock.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (DirtySock buddies presence).

struct UnkStruct_GP_self { unsigned char pad_0[0x118]; int field_118; };
extern "C" void *HLBListGetBuddyByName(int, char *);
extern "C" int func_004190D8(void *);
extern "C" int GetPresence__22CGtBuddiesPS2DirtySockFPcP16EGtBuddyPresence(UnkStruct_GP_self *, char *, int *);
extern "C" int GetPresence__22CGtBuddiesPS2DirtySockFPcP16EGtBuddyPresence(UnkStruct_GP_self *self, char *name, int *out)
{
    void *b = HLBListGetBuddyByName(self->field_118, name);
    if (b) {
        switch (func_004190D8(b)) {
        case 0: *out = 0; break;
        case 1: *out = 1; break;
        case 2: *out = 2; break;
        case 3: *out = 3; break;
        case 4: *out = 4; break;
        case 5: *out = 5; break;
        default: return 5;
        }
        return 0;
    }
    return 5;
}
