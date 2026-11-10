// CB3OnlineLobbyPage::OnKeyboardDone() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3OnlineLobbyPage.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (sibling func_00397280 shape: if/else-if 2,5 + inlined OnKeyboardCancel as if/else-if).

// CB3OnlineLobbyPage::OnKeyboardDone() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3OnlineLobbyPage.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished in the shape of the proven sibling func_00397280 (simfind 0.62): if/else-if on the state
// (2 then 5, both buffers at function scope), OnKeyboardCancel inlined as an if/else-if (2 then 5).

class CB3BuddyDisplayComponent;
class CB3OnScreenKeyboardComponent;
class CB3OnlineLobbyPage;
struct UnkStruct_00313230_2;
struct UnkStruct_00313230_6;
struct UnkStruct_D_01E3CD44;
struct UnkStruct_D_01E3D390;
struct UnkStruct_D_01E898E8;
struct UnkStruct_D_01E898F2;
struct UnkStruct_D_01E8CA94;
struct UnkStruct_func_00312330;

class CB3OnScreenKeyboardComponent {
public:
    void Show(bool, bool);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3BuddyDisplayComponent {
public:
    void GetSelectedBuddyName(char*);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E8CA94 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00313230_2 {
    unsigned char pad_0[0x150];
};

struct UnkStruct_D_01E3CD44 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
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
    virtual void vfunc_C8(char *);
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E898F2 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E898E8 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00313230_6 {
    unsigned char pad_0[0xC];
    int field_C;
};

struct UnkStruct_D_01E3D390 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_func_00312330 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3OnlineLobbyPage {
public:
    void OnKeyboardDone();
    void OnKeyboardCancel();

    unsigned char pad_0[0x13AC];
    signed char field_13AC;
};

extern UnkStruct_D_01E8CA94 D_01E8CA94;
extern UnkStruct_D_01E3CD44 D_01E3CD44;
extern UnkStruct_D_01E898F2 D_01E898F2;
extern UnkStruct_D_01E898E8 D_01E898E8;
extern CB3OnScreenKeyboardComponent D_01E899C0;
extern UnkStruct_D_01E3D390 D_01E3D390;
extern UnkStruct_func_00312330 func_00312330;
extern CB3BuddyDisplayComponent D_01E8D670;

extern "C" int Length__10CGtUnicodeFPCUs(int);
extern "C" void ConvertUTF16toUTF8Fast__10CGtUnicodeFPCUsPUci(int, void *, int);
extern "C" void func_00316640(CB3OnlineLobbyPage *);
extern "C" int func_00360240(void *, void *, void *, void *, CB3OnlineLobbyPage *);
extern "C" void func_00366560(void *, void *);
extern "C" void func_0032D080(void *, int, int, int, int);

// [C] OnKeyboardCancel__18CB3OnlineLobbyPageFv (0x003131A0) is this file's own member; MWCC inlines it here.
inline void CB3OnlineLobbyPage::OnKeyboardCancel()
{
    if (field_13AC == 2) {
        D_01E899C0.Show(0, 1);
        func_00316640(this);
    } else if (field_13AC == 5) {
        field_13AC = 3;
        D_01E899C0.Show(0, 1);
    }
}

// 0x00313230
void CB3OnlineLobbyPage::OnKeyboardDone()
{
    char buf[200];
    char msg[128];
    if (field_13AC == 2) {
        if (Length__10CGtUnicodeFPCUs(D_01E8CA94.field_0) > 0) {
            ConvertUTF16toUTF8Fast__10CGtUnicodeFPCUsPUci(D_01E8CA94.field_0, msg, 128);
            ((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_C8(msg);
        } else {
            OnKeyboardCancel();
        }
    } else if (field_13AC == 5) {
        D_01E899C0.Show(0, 1);
        if (Length__10CGtUnicodeFPCUs(D_01E8CA94.field_0) > 0) {
            ConvertUTF16toUTF8Fast__10CGtUnicodeFPCUsPUci(D_01E8CA94.field_0, buf, 200);
            field_13AC = 6;
            if (func_00360240(&D_01E3D390, (char *)this + 0x50, buf, &func_00312330, this) == 0) {
                D_01E8D670.GetSelectedBuddyName(buf);
                func_00366560(&D_01E8D670, buf);
                if (D_01E898F2.field_0 != 0) {
                    ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
                }
                func_0032D080(&D_01E898E8, 0, 27, 15, 0);
            } else {
                if (D_01E898F2.field_0 != 0) {
                    ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
                }
                func_0032D080(&D_01E898E8, 2, 207, 0, 0);
            }
        } else {
            func_00316640(this);
        }
    }
}
