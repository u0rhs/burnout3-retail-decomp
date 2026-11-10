// CGtLobbyPS2DirtySock::Update() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> GtLobbyDirtySock.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (early-return on func_0033BB90; field_62C void*; >60 / >-1 compares; ==0 then-arms).

// lifter variant 0
// CGtLobbyPS2DirtySock::Update() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> GtLobbyDirtySock.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CGtLobbyPS2DirtySock;
struct UnkStruct_0033B1B0_1;

struct UnkStruct_0033B1B0_1 {
    unsigned char pad_0[0x14];
    int field_14;
    unsigned char pad_18[0xC0];
    int field_D8;
};

class CGtLobbyPS2DirtySock {
public:
    int Update();
    int CheckGameStillExists();
    int CheckForPlayerKicked();
    int CheckForPlayerListChange();
    void CheckGameAttribsHaveArrived();

    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual int vfunc_14();
    virtual void vfunc_18();
    virtual void vfunc_1C();
    virtual void vfunc_20();
    virtual void vfunc_24();
    virtual void vfunc_28();
    virtual void vfunc_2C();
    virtual void vfunc_30();
    virtual void vfunc_34();
    virtual void vfunc_38();
    virtual void vfunc_3C();
    virtual void vfunc_40();
    virtual void vfunc_44();
    virtual void vfunc_48();
    virtual void vfunc_4C();
    virtual void vfunc_50();
    virtual void vfunc_54();
    virtual void vfunc_58();
    virtual void vfunc_5C();
    virtual void vfunc_60();
    virtual void vfunc_64();
    virtual void vfunc_68();
    virtual void vfunc_6C();
    virtual void vfunc_70();
    virtual void vfunc_74();
    virtual void vfunc_78();
    virtual void vfunc_7C();
    virtual void vfunc_80();
    virtual void vfunc_84();
    virtual void vfunc_88();
    virtual void vfunc_8C();
    virtual void vfunc_90();
    virtual void vfunc_94();
    virtual void vfunc_98();
    virtual void vfunc_9C();
    virtual void vfunc_A0();
    virtual void vfunc_A4();
    virtual void vfunc_A8();
    virtual void vfunc_AC();
    virtual void vfunc_B0();
    virtual void vfunc_B4();
    virtual void vfunc_B8();
    virtual void vfunc_BC();
    virtual void vfunc_C0();
    virtual void vfunc_C4();
    virtual void vfunc_C8();
    virtual void vfunc_CC();
    virtual void vfunc_D0();
    virtual void vfunc_D4();
    virtual int vfunc_D8();
    unsigned char pad_4[0x100];
    int field_104;
    unsigned char pad_108[0x8];
    unsigned char field_110;
    unsigned char field_111;
    unsigned char field_112;
    unsigned char pad_113[0x1];
    int field_114;
    int field_118;
    unsigned char pad_11C[0x3];
    unsigned char field_11F;
    unsigned char pad_120[0x1];
    unsigned char field_121;
    unsigned char pad_122[0x42E];
    int field_550;
    int field_554;
    unsigned char pad_558[0x10];
    int field_568;
    unsigned char pad_56C[0x8C];
    int field_5F8;
    int field_5FC;
    int field_600;
    unsigned char pad_604[0x28];
    void * field_62C;
    unsigned char field_630;
    unsigned char pad_631[0x1A];
    unsigned char field_64B;
};

extern "C" void RpcDone(CGtLobbyPS2DirtySock *);
extern "C" void LobbyApiUpdate(int);
extern "C" int func_004022E8(int, int, int);
extern "C" int func_0033BB90(CGtLobbyPS2DirtySock *);
extern "C" int DispListChange(int, int);
extern "C" int DispListCount(int);
extern "C" int func_0033B710(CGtLobbyPS2DirtySock *);
extern "C" int func_0033BAE0(CGtLobbyPS2DirtySock *);
extern "C" int func_0033B4B0(CGtLobbyPS2DirtySock *);
extern "C" int func_0040E738(void *, int);
extern "C" void func_0040E508(void *);

// 0x0033B1B0
int CGtLobbyPS2DirtySock::Update()
{
    if (field_104 != 0) {
        RpcDone(this);
        LobbyApiUpdate(field_104);
        int r2 = func_004022E8(0x706C7567, 0, 0);
        if (r2 == 0) {
            field_118++;
        } else {
            field_118 = 0;
            field_64B = 1;
        }
        if (field_118 > 60) {
            if (field_11F != 0) {
                vfunc_2C();
            }
            field_64B = 0;
        }
        if (func_0033BB90(this) != 0) {
            void * t2 = field_62C;
            if (t2 != 0) {
                func_0040E508(t2);
                field_62C = 0;
            }
            return vfunc_14();
        }

        if (field_5F8 > -1) {
            int r5 = DispListChange(field_568, 0);
            if (r5 > 0) {
                int t0 = field_5F8;
                int r6 = DispListCount(field_568);
                if (t0 == r6) {
                    int t1 = field_5FC;
                    if (t1 != 0) {
                        ((void (*)(int, int))t1)(t0, field_600);
                        field_5FC = 0;
                        field_600 = 0;
                    }
                }
            }
        }
        func_0033B710(this);
        if (vfunc_D8() != 0) {
            if (field_121 == 0) {
                CheckGameAttribsHaveArrived();
            } else {
                int r10 = CheckGameStillExists();
                if (r10 != 0) {
                    int r11 = CheckForPlayerKicked();
                    if (r11 == 0) {
                        int r12 = func_0033BAE0(this);
                        if (r12 != 0) {
                            int r13 = CheckForPlayerListChange();
                            if (r13 != 0) {
                                ((void (*)(int, int))field_550)(-1, field_554);
                            }
                            func_0033B4B0(this);
                        }
                    }
                }
            }
        }
        if (field_630 != 0) {
            int r17 = func_0040E738(field_62C, 0);
            if (r17 <= 0) {
                if (r17 < 0) {
                    field_630 = 0;
                    field_112 = 1;
                    field_110 = 0;
                    field_114 = -1;
                }
            } else {
                field_630 = 0;
                field_111 = 1;
            }
        }
        int r18 = vfunc_14();
        return r18;
        }
    return 2;
}
