// CGtPS2LibNet::Receive(void*,int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtPS2LibNet.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a80: sceInsockRecv declared long (dsll32/dsra32 narrowing), int local, errno==11 -> 0).

struct UnkStruct_0022E900 { unsigned char pad_0[0xB0]; int field_B0; };
extern "C" int *__sceInsockErrnoLoc(void);
extern "C" long sceInsockRecv(int, void *, int, int);
extern "C" int Receive__12CGtPS2LibNetFPvi(UnkStruct_0022E900 *self, void *p0, int p1)
{
    int r = sceInsockRecv(self->field_B0, p0, p1, 0);
    if (r <= 0) {
        if (*__sceInsockErrnoLoc() == 11) {
            return 0;
        }
    }
    return r;
}
