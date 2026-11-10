// CGtBuddiesPS2DirtySock::GetPresenceText(char*,char*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtBuddiesPS2DirtySock.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (DirtySock buddies presence).

struct UnkStruct_GP_self { unsigned char pad_0[0x118]; int field_118; };
struct UnkStruct_D_004C7328 { unsigned char pad_0[0x10]; };
extern UnkStruct_D_004C7328 D_004C7328;
extern "C" void *HLBListGetBuddyByName(int, char *);
extern "C" void func_00419140(void *, char *);
extern "C" char * strncpy(char *, const char *, unsigned int);
extern "C" int GetPresence__22CGtBuddiesPS2DirtySockFPcP16EGtBuddyPresence(UnkStruct_GP_self *, char *, int *);
extern "C" int GetPresenceText__22CGtBuddiesPS2DirtySockFPcPc(UnkStruct_GP_self *self, char *name, char *out)
{
    void *b = HLBListGetBuddyByName(self->field_118, name);
    if (b == 0) return 5;
    func_00419140(b, out);
    int pres;
    int r = GetPresence__22CGtBuddiesPS2DirtySockFPcP16EGtBuddyPresence(self, name, &pres);
    if (r == 0) return *out == 0 ? 0x11 : 0;
    strncpy(out, (char *)&D_004C7328, 0x64);
    return r;
}
