// CB3AILane::FindNoGo(unsigned short,EAISegmentLinkType,unsigned char*,unsigned short*,bool) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3AILane.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a154: field_8[cur].field_6[type] element form fixes addu order).


// CB3AILane::FindNoGo(unsigned short, EAISegmentLinkType, unsigned char*, unsigned short*, bool) -- hand-written (lifter refused).
enum EAISegmentLinkType {};
class CB3AILane;
struct UnkStruct_00146AC0_e {
    unsigned char pad_0[3];
    unsigned char field_3;
    unsigned char field_4[2];
    unsigned short field_6[2];
};
struct UnkStruct_00146AC0_road {
    unsigned char pad_0[8];
    UnkStruct_00146AC0_e *field_8;
};
class CB3AILane {
public:
    void FindNoGo(unsigned short, EAISegmentLinkType, unsigned char *, unsigned short *, bool);
    int field_0;
    UnkStruct_00146AC0_road *field_4;
};
struct UnkStruct_D_00522660 {
    unsigned char pad_0[0x2C];
    CB3AILane field_2C[1];
};
extern UnkStruct_D_00522660 D_00522660;
// 0x00146AC0
void CB3AILane::FindNoGo(unsigned short seg, EAISegmentLinkType type, unsigned char *outLane, unsigned short *outSeg, bool flag)
{
    unsigned char link;
    unsigned short cur = seg;
    if (field_4->field_8[cur].field_4[type] == 255) {
        *outLane = field_0;
        *outSeg = seg;
        return;
    }
    CB3AILane *lane = this;
    unsigned char done = 0;
    while (!done) {
        link = *((unsigned char *)lane->field_4->field_8 + type + cur * 10 + 4);
        cur = lane->field_4->field_8[cur].field_6[type];
        lane = &D_00522660.field_2C[link];
        if (flag) {
            int f = lane->field_4->field_8[cur].field_3 & 7;
            bool r = true;
            if (f != 5 && f != 4) {
                r = false;
            }
            done = r;
        } else {
            bool r = false;
            if ((lane->field_4->field_8[cur].field_3 & 7) == 5) {
                if (*((unsigned char *)lane->field_4->field_8 + type + cur * 10 + 4) == 255) {
                    r = true;
                }
            }
            done = r;
        }
    }
    *outSeg = cur;
    *outLane = link;
}
