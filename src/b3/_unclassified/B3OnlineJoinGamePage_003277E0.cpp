// CB3OnlineJoinGamePage::SetMode(int,EB3MenuChoicesOnline) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3OnlineJoinGamePage.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a148: switch cases 0,1,4,3,2,5,default (jtbl ok); cb stores field_4 first; bool chain t1/t2/v1/a0 locals; TestFlag inline + 'int z; c = z ^ 1'; u_long128 quad copy via const base pointer).

enum EB3MenuChoicesOnline {};
struct UnkStruct_P { unsigned char pad_0[0x10]; };
struct UnkStruct_B { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_Cb { void * field_0; void * field_4; unsigned char pad_8[0x34]; };
typedef unsigned int u_long128 __attribute__((mode(TI)));
struct UnkStruct_Row { u_long128 field_0; unsigned char pad_10[0x18]; int field_28; unsigned char pad_2C[0x164]; };
struct UnkStruct_Fl { int field_0; int field_4; unsigned char pad_8[0x8]; unsigned char field_10; unsigned char field_11; unsigned char pad_12[0x36]; };
struct UnkStruct_Q { u_long128 field_0; };
class CB3OnlineJoinGamePage {
public:
    void SetMode(int p0, EB3MenuChoicesOnline p1);
    unsigned char pad_0[0x290];
    UnkStruct_Row field_290[1];
    unsigned char pad_420[0x13A0 - 0x420];
    UnkStruct_Cb field_13A0[1];
    unsigned char pad_13DC[0x18A4 - 0x13DC];
    UnkStruct_Fl field_18A4[1];
};
extern UnkStruct_P D_0051BA44;
extern UnkStruct_B D_00665ECE;
extern UnkStruct_Q D_01E90240[];
extern "C" int func_00271A00(void *, int);
extern "C" void RenderText__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv(const void *, const void *, unsigned short *, const void *, const void *);
extern "C" void GetTextSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv(void *, const void *, const void *);

static inline bool TestFlag(unsigned char v, int m)
{
    return (v & m) != 0;
}

// 0x003277E0
void CB3OnlineJoinGamePage::SetMode(int p0, EB3MenuChoicesOnline p1)
{
    UnkStruct_Q * const qb = D_01E90240;
    field_13A0[p0].field_4 = (void *)&GetTextSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv;
    field_13A0[p0].field_0 = (void *)&RenderText__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv;
    switch ((int)p1) {
    case 0:
        field_290[p0].field_28 = func_00271A00(&D_0051BA44, 0x2DA);
        break;
    case 1:
        field_290[p0].field_28 = func_00271A00(&D_0051BA44, 0x2DD);
        break;
    case 4:
        field_290[p0].field_28 = func_00271A00(&D_0051BA44, 0x2DE);
        break;
    case 3:
        field_290[p0].field_28 = func_00271A00(&D_0051BA44, 0x2DB);
        break;
    case 2:
        field_290[p0].field_28 = func_00271A00(&D_0051BA44, 0x2DF);
        break;
    case 5:
        field_290[p0].field_28 = 0;
        field_13A0[p0].field_0 = 0;
        field_13A0[p0].field_4 = 0;
        break;
    default:
        field_13A0[p0].field_0 = 0;
        field_13A0[p0].field_4 = 0;
        break;
    }
    bool a0 = false;
    bool v1 = false;
    bool t2 = false;
    bool t1 = false;
    if (field_18A4[p0].field_0 < field_18A4[p0].field_4) {
        bool k = !TestFlag(field_18A4[p0].field_10, 1);
        if (k) {
            t1 = true;
        }
    }
    if (t1) {
        bool k = !TestFlag(field_18A4[p0].field_10, 4);
        if (k) {
            t2 = true;
        }
    }
    if (t2) {
        if (field_18A4[p0].field_11 != 0) {
            v1 = true;
        }
    }
    if (v1) {
        bool a3 = true;
        bool a2 = false;
        unsigned char fl = field_18A4[p0].field_10;
        if (TestFlag(fl, 0x10)) {
            if (D_00665ECE.field_0 != 0) {
                a2 = a3;
            }
        }
        if (!a2) {
            int c = TestFlag(fl, 0x20);
            if (c) {
                int z = D_00665ECE.field_0 != 0;
                c = z ^ 1;
            }
            if (!c) {
                a3 = false;
            }
        }
        if (a3) {
            a0 = true;
        }
    }
    if (a0) {
        field_290[p0].field_0 = qb[0].field_0;
    } else {
        field_290[p0].field_0 = qb[2].field_0;
    }
}
