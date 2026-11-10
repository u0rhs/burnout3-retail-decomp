// CB3StreamedTrack::UpdateStreamFSM() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3StreamedTrack.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// CB3StreamedTrack has a header in include/ (pads and a few proven fields only): declared locally instead, as the
// hand-matched units of such classes do (B3AITarget_00149140.cpp) [lift3].
// Hand-finished from the lifted source (near3: the vfunc_24 flag is 'bool v0 = false; case 1: v0 = true;' tested '!v0' (retail's andi s0 of the reused compare 1)).


// lifter variant 0
// CB3StreamedTrack::UpdateStreamFSM() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3StreamedTrack.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// CB3StreamedTrack has a header in include/ (pads and a few proven fields only): declared locally instead, as the
// hand-matched units of such classes do (B3AITarget_00149140.cpp) [lift3].

class CB3StreamedTrackHighData;
class CB3StreamedTrackLODAndCollisionData;

class CB3StreamManager;
class CB3StreamedTrack;
struct UnkStruct_003026C0_1;
struct UnkStruct_003026C0_4;
struct UnkStruct_D_0064C994;

class CB3StreamManager {
public:
    void ReleaseHighDetailUnit(CB3StreamedTrackHighData*);
    void ReleaseLODUnit(CB3StreamedTrackLODAndCollisionData*);

    UnkStruct_003026C0_1 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003026C0_1 {
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

struct UnkStruct_D_0064C994 {
    UnkStruct_003026C0_4 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003026C0_4 {
    unsigned char pad_0[0x54];
    short field_54;
};

class CB3StreamedTrack {
public:
    void UpdateStreamFSM();

    unsigned char pad_0[0x8];
    int field_8;
    int field_C;
    unsigned char pad_10[0x10];
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
    unsigned char pad_47[0x9];
    int field_50;
    int field_54;
    unsigned char pad_58[0xFC];
    int field_154[1];  // [G] element count unknown
    unsigned char pad_158[0x24];
    int field_17C[1];  // [G] element count unknown
};

extern CB3StreamManager D_0064CD40;
extern UnkStruct_D_0064C994 D_0064C994;

extern "C" int UpdateStreamHighFSM__16CB3StreamedTrackFv(void *);  // CB3StreamedTrack::UpdateStreamHighFSM()
extern "C" int UpdateStreamLowFSM__16CB3StreamedTrackFv(void *);  // CB3StreamedTrack::UpdateStreamLowFSM(), passed 1 more argument(s) [G]

// 0x003026C0
void CB3StreamedTrack::UpdateStreamFSM()
{
    bool v0 = false;
    int r0 = D_0064CD40.field_0->vfunc_24();
    switch (r0) {
    case 1:
        v0 = true;
        break;
    case 3:
    case 2:
    case 0:
        break;
    }
    if (!v0) {
        return;
    }
    UnkStruct_003026C0_4 * t0 = D_0064C994.field_0;
    int t1 = t0->field_54;
    switch (field_38) {
    case 0:
        if (field_20 < field_28) {
            field_38 = 1;
        } else {
            if (field_24 < field_2C) {
                field_38 = 2;
            }
        }
        if (field_45 != 0 && field_46 != 0 && field_44 == 0) {
            field_44 = 1;
        }
        break;
    case 1:
        if (field_3C == 0) {
            field_3C = 1;
        }
        int r1 = UpdateStreamHighFSM__16CB3StreamedTrackFv(this);
        if (r1 == 0) {
            return;
        }
        if (field_44 != 0) {
            field_38 = 2;
        } else {
            field_20 = (field_20 + 1);
            field_50 = ((field_50 + 1) % t1);
            if (field_20 >= field_28) {
                field_45 = 1;
            }
            field_38 = 0;
        }
        break;
    case 2:
        if (field_40 == 0) {
            field_40 = 1;
        }
        int r2 = UpdateStreamLowFSM__16CB3StreamedTrackFv(this);
        if (r2 == 0) {
            return;
        }
        if (field_44 == 0) {
            field_24 = (field_24 + 1);
            field_54 = ((field_54 + 1) % t1);
            if (field_24 >= field_2C) {
                field_46 = 1;
            }
        }
        field_38 = 3;
        break;
    case 3:
        if (field_44 != 0) {
            field_20 = (field_20 + 1);
            field_24 = (field_24 + 1);
            field_50 = ((field_50 + 1) % t1);
            field_54 = ((field_54 + 1) % t1);
            int i2 = ((field_34 + 1) % field_C);
            int i1 = ((field_30 + 1) % field_8);
            D_0064CD40.ReleaseHighDetailUnit((CB3StreamedTrackHighData*)field_154[i1]);
            D_0064CD40.ReleaseLODUnit((CB3StreamedTrackLODAndCollisionData*)field_17C[i2]);
            field_154[i1] = 0;
            field_17C[i2] = 0;
        }
        field_38 = 0;
        break;
    default:
        break;
    }
}
