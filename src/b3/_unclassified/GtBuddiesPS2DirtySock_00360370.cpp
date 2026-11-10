// CGtBuddiesPS2DirtySock::_MessageCallback(DirtySock::HLBApiRefT*,DirtySock::BuddyApiMsgT*,void*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtBuddiesPS2DirtySock.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (FourCC admn/chat message callback).

struct UnkStruct_Msg_b { int field_0; unsigned char pad_4[0x10]; int field_14; };
struct UnkStruct_D_004C72F0 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_004C72F8 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_004C7300 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_004C7308 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_004C7310 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_004C7318 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_004C7320 { unsigned char pad_0[0x10]; };
extern UnkStruct_D_004C72F0 D_004C72F0;
extern UnkStruct_D_004C72F8 D_004C72F8;
extern UnkStruct_D_004C7300 D_004C7300;
extern UnkStruct_D_004C7308 D_004C7308;
extern UnkStruct_D_004C7310 D_004C7310;
extern UnkStruct_D_004C7318 D_004C7318;
extern UnkStruct_D_004C7320 D_004C7320;
extern "C" void * TagFieldFind(int, void *);
extern "C" int TagFieldGetNumber(void *, int);
extern "C" int TagFieldGetString(void *, char *, int, void *);
extern "C" int strcmp(const char *, const char *);
extern "C" void _MessageCallback__22CGtBuddiesPS2DirtySockFPQ29DirtySock10HLBApiRefTPQ29DirtySock12BuddyApiMsgTPv(void *p0, UnkStruct_Msg_b *p1, void *p2)
{
    if (p1->field_0 == 0x61646D6E) {
        char buf[0x80];
        TagFieldGetNumber(TagFieldFind(p1->field_14, &D_004C72F0), -1);
        TagFieldGetString(TagFieldFind(p1->field_14, &D_004C72F8), buf, 0x80, &D_004C7300);
        if (strcmp(buf, (char *)&D_004C7308) == 0) return;
        if (strcmp(buf, (char *)&D_004C7310) == 0) return;
        if (strcmp(buf, (char *)&D_004C7318) == 0) return;
        strcmp(buf, (char *)&D_004C7320);
    } else if (p1->field_0 == 0x63686174) return;
}
