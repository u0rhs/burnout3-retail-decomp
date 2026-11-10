// func_003900E0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (player-record pointer return types; direct call-result stores; store-then-test field).

// lifter variant 0
// func_003900E0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

class CGtNetworkPlayerManager;
struct UnkStruct_003900E0_3;
struct UnkStruct_003900E0_5;
struct UnkStruct_003900E0_7;
struct UnkStruct_003900E0_8;
struct UnkStruct_003900E0_e1;
struct UnkStruct_D_0051BA88;
struct UnkStruct_D_01E32B08;
struct UnkStruct_func_00390320;

class CGtNetworkPlayerManager {
public:
    int GetMyPlayerID() const;

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E32B08 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003900E0_e1 {
    int field_0;
    unsigned char pad_4[0x4];
    int field_8;
};

struct UnkStruct_003900E0_3 {
    UnkStruct_003900E0_e1 field_0[1];  // [G] element count unknown
    unsigned char pad_C[0x54];
};

struct UnkStruct_003900E0_5 {
    unsigned char pad_0[0x44];
    int field_44;
};

struct UnkStruct_D_0051BA88 {
    UnkStruct_003900E0_7 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003900E0_7 {
    unsigned char pad_0[0x1B4];
    UnkStruct_003900E0_8 * field_1B4;
};

struct UnkStruct_003900E0_8 {
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
    virtual void vfunc_C8();
    virtual void vfunc_CC();
    virtual void vfunc_D0();
    virtual void vfunc_D4();
    virtual void vfunc_D8();
    virtual void vfunc_DC();
    virtual void vfunc_E0();
    virtual void vfunc_E4();
    virtual void vfunc_E8();
    virtual void vfunc_EC();
    virtual int vfunc_F0();
};

struct UnkStruct_func_00390320 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

extern UnkStruct_D_01E32B08 D_01E32B08;
extern int D_01EA4B80[];  // [G] element count unknown
extern UnkStruct_D_0051BA88 D_0051BA88;
extern CGtNetworkPlayerManager D_01E32AE0;
extern UnkStruct_func_00390320 func_00390320;

extern "C" UnkStruct_003900E0_5 * GetPlayerRecordByID__17CB3NetworkManagerFi(void *, int);  // CB3NetworkManager::GetPlayerRecordByID(int)
extern "C" void *func_002366D0(void *, int);
extern "C" int func_0022FBB0(void *);
extern "C" void qsort(UnkStruct_003900E0_3 *, int, int, void *);

// 0x003900E0
extern "C" int func_003900E0(void *n0_, int p0, int p1)
{
    int n0 = (int)n0_;
    UnkStruct_003900E0_3 local;  // [G] the frame's one local (size: up to the frame top)
    int m0 = 0;
    for (int i = 0; (i < D_01E32B08.field_0); i++) {
         void *r0 = func_002366D0(&D_01E32AE0, i);
        if (r0 != 0) {
            int r1 = func_0022FBB0(r0);
            UnkStruct_003900E0_5 * r2 = GetPlayerRecordByID__17CB3NetworkManagerFi(&D_01E32AE0, r1);
            if (r2 == 0) {
                local.field_0[m0].field_0 = D_01EA4B80[i];
            } else {
                 local.field_0[m0].field_0 = r2->field_44;
                if (local.field_0[m0].field_0 < 0) {
                    local.field_0[m0].field_0 = D_01EA4B80[i];
                }
            }
            int r3 = func_0022FBB0(r0);
            local.field_0[m0].field_8 = r3;
            m0 = (m0 + 1);
        }
    }
     local.field_0[m0].field_0 = D_0051BA88.field_0->field_1B4->vfunc_F0();
    local.field_0[m0].field_8 = D_01E32AE0.GetMyPlayerID();
    qsort(&local, (m0 + 1), 12, &func_00390320);
    for (int i1 = 0; (i1 < (m0 + 1)); i1++) {
        if (p0 != local.field_0[i1].field_0) {
            continue;
        }
        if (p1 != local.field_0[i1].field_8) {
            continue;
        }
        return i1;
    }
    return 7;
}
