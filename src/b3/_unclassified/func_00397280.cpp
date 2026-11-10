// func_00397280 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (if/else-if on field_45D (1, 5); sibling OnKeyboardCancel__22CB3OnlineOpenLobbyPageFv's matched body as a static inline helper [G]; Length__10CGtUnicodeFPCUs()>0 arms first; char buffers in reverse frame order).

// lifter variant 0
// func_00397280 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

enum EB3ChatDisplayOrientation {};

class CB3BuddyDisplayComponent;
class CB3ChatDisplayComponent;
class CB3OnScreenKeyboardComponent;
struct UnkStruct_00397280;
struct UnkStruct_00397280_2;
struct UnkStruct_00397280_6;
struct UnkStruct_D_01E3CD44;
struct UnkStruct_D_01E3D390;
struct UnkStruct_D_01E898E8;
struct UnkStruct_D_01E898F2;
struct UnkStruct_D_01E8CA94;
struct UnkStruct_func_003961B0;

class CB3OnScreenKeyboardComponent {
public:
    void Show(bool, bool);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3ChatDisplayComponent {
public:
    void SetOrientation(EB3ChatDisplayOrientation);

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

struct UnkStruct_00397280_2 {
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

struct UnkStruct_00397280_6 {
    unsigned char pad_0[0xC];
    int field_C;
};

struct UnkStruct_D_01E3D390 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_func_003961B0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00397280 {
    unsigned char pad_0[0x4];
    char field_4[0x458];
    unsigned char field_45C;
    unsigned char field_45D;
};

extern UnkStruct_D_01E8CA94 D_01E8CA94;
extern UnkStruct_D_01E3CD44 D_01E3CD44;
extern UnkStruct_D_01E898F2 D_01E898F2;
extern UnkStruct_D_01E898E8 D_01E898E8;
extern CB3OnScreenKeyboardComponent D_01E899C0;
extern CB3ChatDisplayComponent D_01E8CBE0;
extern UnkStruct_D_01E3D390 D_01E3D390;
extern UnkStruct_func_003961B0 func_003961B0;
extern CB3BuddyDisplayComponent D_01E8D670;

extern "C" int Length__10CGtUnicodeFPCUs(int);
extern "C" void ConvertUTF16toUTF8Fast__10CGtUnicodeFPCUsPUci(int, char *, int);
extern "C" void func_00396D30(UnkStruct_00397280 *);
extern "C" void func_00396E50(UnkStruct_00397280 *);
extern "C" void func_00396A90(UnkStruct_00397280 *);
extern "C" int func_00360240(void *, char *, char *, void *, UnkStruct_00397280 *);
extern "C" void func_00366560(void *, char *);
extern "C" void func_0032D080(void *, int, int, int, int);


// [G] inlined func_00397280's sibling OnKeyboardCancel__22CB3OnlineOpenLobbyPageFv (its matched body)
static inline void func_003971C0_inl(UnkStruct_00397280 * self)
{
    unsigned char t0 = self->field_45D;
    if (t0 != 1 && t0 != 5) {
        return;
    }
    self->field_45D = self->field_45C;
    D_01E899C0.Show(0, 0);
    D_01E8CBE0.SetOrientation((EB3ChatDisplayOrientation)1);
    unsigned char t1 = self->field_45D;
    if (t1 == 0) {
        func_00396E50(self);
    } else if (t1 == 2) {
        func_00396D30(self);
    } else if (t1 == 3) {
        func_00396A90(self);
    }
}

// 0x00397280
extern "C" void func_00397280(UnkStruct_00397280 * self)
{
    char buf[200];
    char msg[128];
    if (self->field_45D == 1) {
        if (Length__10CGtUnicodeFPCUs(D_01E8CA94.field_0) > 0) {
            ConvertUTF16toUTF8Fast__10CGtUnicodeFPCUsPUci(D_01E8CA94.field_0, msg, 128);
            ((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_C8(msg);
        } else {
            func_003971C0_inl(self);
        }
    } else if (self->field_45D == 5) {
        D_01E899C0.Show(0, 0);
        if (Length__10CGtUnicodeFPCUs(D_01E8CA94.field_0) > 0) {
            ConvertUTF16toUTF8Fast__10CGtUnicodeFPCUsPUci(D_01E8CA94.field_0, buf, 200);
            self->field_45D = 6;
            if (func_00360240(&D_01E3D390, self->field_4, buf, &func_003961B0, self) == 0) {
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
            func_00396E50(self);
        }
    }
}
