// func_00302D20 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (state switch with case fallthrough and shared UpdateStreamFSM tail after the switch; unit arrays typed as CB3StreamedTrack*Data pointers (pointer null test keeps the release call inline); int t9; element pointers in case 4).

// from build/vt\try_func_00302D20_best.cpp
// func_00302D20 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

class CB3StreamedTrackHighData;
class CB3StreamedTrackLODAndCollisionData;

class CB3StreamManager;
struct UnkStruct_00302D20;
struct UnkStruct_00302D20_13;
struct UnkStruct_00302D20_15;
struct UnkStruct_D_004E2D48;
struct UnkStruct_D_0064C994;
struct UnkStruct_D_0064CD44;
struct UnkStruct_D_0064CE38;

class CB3StreamManager {
public:
    void ReleaseHighDetailUnit(CB3StreamedTrackHighData*);
    void ReleaseLODUnit(CB3StreamedTrackLODAndCollisionData*);

    UnkStruct_00302D20_13 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004E2D48 {
    int field_0;
};

struct UnkStruct_D_0064CD44 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0064C994 {
    UnkStruct_00302D20_15 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00302D20_13 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18();
    virtual void vfunc_1C();
    virtual void vfunc_20();
    virtual int vfunc_24();
};

struct UnkStruct_00302D20_15 {
    unsigned char pad_0[0x54];
    short field_54;
};

struct UnkStruct_D_0064CE38 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00302D20 {
    int field_0;
    int field_4;
    int field_8;
    int field_C;
    int field_10;
    int field_14;
    unsigned char field_18;
    unsigned char field_19;
    unsigned char pad_1A[0x2];
    int field_1C;
    int field_20;
    int field_24;
    int field_28;
    int field_2C;
    int field_30;
    int field_34;
    int field_38;
    int field_3C;
    int field_40;
    unsigned char field_44;
    unsigned char field_45;
    unsigned char field_46;
    unsigned char field_47;
    int field_48;
    int field_4C;
    int field_50;
    int field_54;
    unsigned char pad_58[0xFC];
    CB3StreamedTrackHighData * field_154[1];  // [G] element count unknown
    unsigned char pad_158[0x24];
    CB3StreamedTrackLODAndCollisionData * field_17C[1];  // [G] element count unknown
    unsigned char pad_180[0x44];
    int field_1C4;
    int field_1C8;
};

extern UnkStruct_D_004E2D48 D_004E2D48;
extern UnkStruct_D_0064CD44 D_0064CD44;
extern CB3StreamManager D_0064CD40;
extern UnkStruct_D_0064C994 D_0064C994;
extern UnkStruct_D_0064CE38 D_0064CE38;

extern "C" void * memset(void *, int, unsigned int);
extern "C" void UpdateStreamFSM__16CB3StreamedTrackFv(void *);  // CB3StreamedTrack::UpdateStreamFSM()
extern "C" CB3StreamedTrackHighData * func_003C3250(void *);
extern "C" CB3StreamedTrackLODAndCollisionData * func_003C3150(void *);

// 0x00302D20
extern "C" int func_00302D20(UnkStruct_00302D20 * self, int p0, int p1)
{
    switch (self->field_10) {
    case 1:
    case 24:
        D_004E2D48.field_0 = -1;
        self->field_18 = p0;
        self->field_1C = p1;
        self->field_47 = 0;
        self->field_44 = 0;
        self->field_45 = 0;
        self->field_46 = 0;
        self->field_38 = 0;
        self->field_3C = 0;
        self->field_40 = 0;
        self->field_14 = 0;
        self->field_34 = -1;
        self->field_30 = -1;
        self->field_24 = -1;
        self->field_20 = -1;
        self->field_2C = -1;
        self->field_28 = -1;
        self->field_4C = -1;
        self->field_48 = -1;
        self->field_8 = 10;
        self->field_C = 18;
        self->field_19 = 1;
        self->field_10 = 2;
    case 2:
        memset(((char *)self + 0x58), 0, 36);
        memset(((char *)self + 0x7C), 0, 72);
        memset(((char *)self + 0xC4), 0, 72);
        memset(((char *)self + 0x10C), 0, 72);
        self->field_1C4 = 0;
        self->field_1C8 = 0;
        if (self->field_19 != 0 || D_0064CD44.field_0 != 0) {
            D_004E2D48.field_0 = -1;
            self->field_47 = 0;
            for (int i = 0; i < self->field_8; i++) {
                CB3StreamedTrackHighData * t0 = self->field_154[i];
                if (t0 != 0) {
                    D_0064CD40.ReleaseHighDetailUnit(t0);
                    self->field_154[i] = 0;
                }
            }
            for (int i = 0; i < self->field_C; i++) {
                CB3StreamedTrackLODAndCollisionData * t1 = self->field_17C[i];
                if (t1 != 0) {
                    D_0064CD40.ReleaseLODUnit(t1);
                    self->field_17C[i] = 0;
                }
            }
            self->field_10 = 4;
            return 0;
        }
        self->field_10 = 5;
        break;
    case 4: {
        int t9 = D_0064C994.field_0->field_54;
        if (D_0064CD40.field_0->vfunc_24() != 1) {
            return 0;
        }
        for (int i = 0; i < self->field_8 - 1; i++) {
            CB3StreamedTrackHighData ** p = &self->field_154[i];
            if (*p == 0) {
                *p = func_003C3250(&D_0064CD40);
            }
            if (*p == 0) {
                return 0;
            }
        }
        for (int i = 0; i < self->field_C - 1; i++) {
            CB3StreamedTrackLODAndCollisionData ** p = &self->field_17C[i];
            if (*p == 0) {
                *p = func_003C3150(&D_0064CD40);
            }
            if (*p == 0) {
                return 0;
            }
        }
        self->field_44 = 0;
        self->field_45 = 0;
        self->field_46 = 0;
        self->field_38 = 0;
        self->field_3C = 0;
        self->field_40 = 0;
        self->field_20 = 0;
        self->field_24 = 0;
        self->field_4C = 0;
        self->field_48 = 0;
        self->field_54 = D_0064CE38.field_0 - 8;
        self->field_54 = (self->field_54 + t9) % t9;
        self->field_50 = D_0064CE38.field_0 - 4;
        self->field_50 = (self->field_50 + t9) % t9;
        self->field_2C = 17;
        self->field_28 = 9;
        self->field_19 = 0;
        self->field_10 = 5;
        break;
    }
    case 5:
        break;
    default:
        return 1;
    }
    UpdateStreamFSM__16CB3StreamedTrackFv(self);
    if (self->field_44 != 0) {
        self->field_4 = 8;
        self->field_0 = 4;
        self->field_4C = 8;
        self->field_48 = 4;
        self->field_10 = 2;
        return 1;
    }
    return 0;
}
