// CGtPS2LibNet::SendTo(void*,int,int,int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtPS2LibNet.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a119: send-queue push; callee takes 6 args (t1=field_10); float field stored via int pun; sub-struct at +8 for the entry copy).

struct UnkStruct_SendTo_b8 { signed char b[8]; };
struct UnkStruct_SendTo_sub {
    unsigned char field_0;
    unsigned char field_1;
    unsigned short field_2;
    float field_4;
    UnkStruct_SendTo_b8 field_8;
};
struct UnkStruct_SendTo_ent {
    int field_0;
    int field_4;
    UnkStruct_SendTo_sub field_8;
};
class CGtPS2LibNet {
public:
    void SendTo(void *p0, int p1, int p2, int p3);  // [C] void, as defined below (extern "C" SendTo__12CGtPS2LibNetFPviii)
};
struct UnkStruct_SendTo {
    unsigned char pad_0[0x10];
    int field_10;
    unsigned char pad_14[0x41 - 0x14];
    unsigned char field_41[0x73];
    UnkStruct_SendTo_ent field_B4[32];
    int field_3B4;
    int field_3B8;
    unsigned char pad_3BC[0x318];
    unsigned char field_6D4;
    unsigned char field_6D5;
    unsigned short field_6D6;
    float field_6D8;
    UnkStruct_SendTo_b8 field_6DC;
};
extern "C" int func_002514A0(void *, int, int, int, int, int);
extern "C" unsigned short func_00237320(int);
extern "C" int func_002372F8(int);

// 0x0022EDE0
extern "C" void SendTo__12CGtPS2LibNetFPviii(UnkStruct_SendTo *self, int p0, int p1, int p2, int p3)
{
    if (func_002514A0(self->field_41, p0, p1, p2, p3, self->field_10) != 0) {
        return;
    }
    self->field_6D6 = func_00237320((unsigned short)p3);
    *(int *)&self->field_6D8 = func_002372F8(p2);
    int head = self->field_3B4;
    int tail = self->field_3B8;
    bool full;
    if (head == tail - 1) {
        full = true;
    } else if (head == 0x1F && tail == 0) {
        full = true;
    } else {
        full = false;
    }
    if (full) return;
    int i;
    if (head >= tail) {
        for (i = tail; i < head; i++) {
            if (self->field_B4[i].field_0 == p0) return;
        }
    } else {
        for (i = tail; i < 32; i++) {
            if (self->field_B4[i].field_0 == p0) return;
        }
        for (i = 0; i < head; i++) {
            if (self->field_B4[i].field_0 == p0) return;
        }
    }
    self->field_B4[self->field_3B4].field_0 = p0;
    self->field_B4[self->field_3B4].field_4 = p1;
    UnkStruct_SendTo_sub *e = &self->field_B4[self->field_3B4].field_8;
    e->field_0 = self->field_6D4;
    e->field_1 = self->field_6D5;
    e->field_2 = self->field_6D6;
    e->field_4 = self->field_6D8;
    e->field_8 = self->field_6DC;
    if (self->field_3B4 >= 0x1F) {
        self->field_3B4 = 0;
    } else {
        self->field_3B4 = self->field_3B4 + 1;
    }
}
