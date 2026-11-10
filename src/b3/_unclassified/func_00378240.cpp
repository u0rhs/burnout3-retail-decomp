// func_00378240 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (Hand-written: lobby-status switch, field_F06 as an if/else chain (t==0 / t==1||!D_01E3D4B0 / t==2 / else) so retail's out-of-line order holds, repeated start block as a static inline, permanent-buddy loop with names[100][16] stack buffers, list[n] = (char*)names + n*16 (keeps only n<<4 in a saved reg), for (i = 0, n = 0;...)).

// from build/vt\try_func_00378240_best.cpp
// func_00378240 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

class CB3HardCodedCrashStageList;
class CB3HardCodedTrackList;
class CGtBuddiesPS2DirtySock;
struct UnkStruct_00378240;
struct UnkStruct_00378240_6;
struct UnkStruct_00378240_7;
struct UnkStruct_00378240_9;
struct UnkStruct_D_01E32AE0;
struct UnkStruct_D_01E3CD44;
struct UnkStruct_D_01E3D4B0;
struct UnkStruct_D_01E898E8;
struct UnkStruct_D_01E898F2;

class CB3HardCodedTrackList {
public:
    static int FindTrack(unsigned long);
};

class CB3HardCodedCrashStageList {
public:
    static int FindCrashStage(unsigned long);
};

class CGtBuddiesPS2DirtySock {
public:
    int GetNumBuddies();
    void GetBuddyName(int, char*);
    void IsPermanentBuddy(char*, bool*);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
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

struct UnkStruct_00378240_6 {
    unsigned char pad_0[0x58];
    int field_58;
};

struct UnkStruct_00378240_7 {
    unsigned char pad_0[0xC];
    int field_C;
};

struct UnkStruct_D_01E3D4B0 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00378240_9 {
    void * field_0[1];  // [G] element count unknown
    unsigned char pad_4[0x7EB];
    unsigned char field_7EF;
};

struct UnkStruct_D_01E32AE0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00378240 {
    unsigned char pad_0[0xEE8];
    unsigned long field_EE8;
    unsigned char pad_EF0[0x14];
    signed char field_F04;
    unsigned char field_F05;
    unsigned short field_F06;
};

extern UnkStruct_D_01E3CD44 D_01E3CD44;
extern UnkStruct_D_01E898F2 D_01E898F2;
extern UnkStruct_D_01E898E8 D_01E898E8;
extern int D_004A4F70[];  // [G] element count unknown
extern UnkStruct_D_01E3D4B0 D_01E3D4B0;
extern UnkStruct_D_01E32AE0 D_01E32AE0;
extern CGtBuddiesPS2DirtySock D_01E3D390;

extern "C" int GetLobbyStatus__17CB3NetworkManagerFv(void *);  // CB3NetworkManager::GetLobbyStatus()
extern "C" char * strncpy(char *, const char *, unsigned int);
extern "C" void func_0032D080(void *, int, int, int, int);
extern "C" void func_00376F60(UnkStruct_00378240 *);
extern "C" int func_00336D00(void *, int, int, int, int, int);
extern "C" int func_00336C20(void *, int, int, int, int);
extern "C" int func_00336B20(void *, int, int, int, int, char **, int, int);

// [G] inlined block, placeholder name
static inline void func_00378240_inl1(UnkStruct_00378240 * self)
{
    self->field_F05 = 5;
    ((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_58();
    if (D_01E898F2.field_0 != 0) {
        ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
    }
    func_0032D080(&D_01E898E8, 2, 1262, 0, 0);
}

// 0x00378240
extern "C" void func_00378240(UnkStruct_00378240 * self)
{
    int id = 0;
    switch (GetLobbyStatus__17CB3NetworkManagerFv(&D_01E32AE0)) {
    case 1:
        func_00378240_inl1(self);
        break;
    case 2:
        func_00376F60(self);
        if (self->field_F04 == 5 || self->field_F04 == 6) {
            id = CB3HardCodedTrackList::FindTrack(self->field_EE8);
        } else if (self->field_F04 == 7 || self->field_F04 == 8) {
            id = CB3HardCodedCrashStageList::FindCrashStage(self->field_EE8);
        }
        unsigned short t = self->field_F06;
        if (t == 0) {
            if (func_00336C20(&D_01E3CD44, 0, D_004A4F70[self->field_F04], id, -1) == 1) {
                func_00378240_inl1(self);
            } else {
                self->field_F05 = 3;
            }
        } else if (t == 1 || D_01E3D4B0.field_0 == 0) {
            if (func_00336D00(&D_01E3CD44, 1, D_004A4F70[self->field_F04], id, 0, -1) == 1) {
                func_00378240_inl1(self);
            } else {
                self->field_F05 = 3;
            }
        } else if (t == 2) {
                bool perm;
                char names[100][16];
                char name[16];
                char * list[100];
                int i;
                int n;
                for (i = 0, n = 0; i < D_01E3D390.GetNumBuddies(); i++) {
                    D_01E3D390.GetBuddyName(i, name);
                    D_01E3D390.IsPermanentBuddy(name, &perm);
                    if (perm) {
                        strncpy(names[n], name, 16);
                        list[n] = (char *)names + n * 16;
                        n++;
                    }
                }
                if (func_00336B20(&D_01E3CD44, 2, D_004A4F70[self->field_F04], id, 0, list, n, -1) == 1) {
                    func_00378240_inl1(self);
                } else {
                    self->field_F05 = 3;
                }
        } else {
            func_00378240_inl1(self);
        }
        break;
    case 0:
        break;
    }
}
