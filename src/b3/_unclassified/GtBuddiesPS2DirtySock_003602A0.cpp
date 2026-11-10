// CGtBuddiesPS2DirtySock::_ConnectCallback(DirtySock::HLBApiRefT*,int,int,void*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtBuddiesPS2DirtySock.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (jtbl switch, uninit e for cases 1,2).

struct UnkStruct_Conn_self {
    unsigned char pad_0[0xCC];
    unsigned char field_CC;
    unsigned char pad_CD[7];
    int field_D4;
    unsigned char pad_D8[0x48];
    unsigned char field_120;
};
extern "C" int SetPresence__22CGtBuddiesPS2DirtySockF16EGtBuddyPresenceb(void *, int, bool);
extern "C" void _ConnectCallback__22CGtBuddiesPS2DirtySockFPQ29DirtySock10HLBApiRefTiiPv(void *p0, int p1, int p2, UnkStruct_Conn_self *self)
{
    int e;
    switch (p2) {
    case 0: e = 0x10; break;
    case 3: e = 0xC; break;
    case 4: e = 2; break;
    case 5: e = 0xB; break;
    case 6: e = 9; break;
    case 7: e = 0xD; break;
    case 1: case 2: break;
    default: e = 0x11; break;
    }
    if (p2 != 1) {
        if (p2 == 2) {
            SetPresence__22CGtBuddiesPS2DirtySockF16EGtBuddyPresenceb(self, 1, false);
            self->field_120 = 1;
            self->field_CC = 0;
            self->field_D4 = 0;
        } else {
            self->field_120 = 0;
            self->field_CC = 0;
            self->field_D4 = e;
        }
    }
}
