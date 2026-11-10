// Hand-written; the lifter refused it (a71: result-variable if/else-if chain (block form puts 2nd branch out of line); >8-byte structs for D_00645170/D_00665EA0 give lui (not gp-rel)).

// [L] DNAT: CB3PlayerCameraManager::GetCurrentUnit() (research/proto/new_names.csv, low: hint only)
struct UnkStruct_00150300_car {
    unsigned char pad_0[0x216];
    signed char field_216;
    unsigned char pad_217[0x4590 - 0x217];
};

struct UnkStruct_D_0055EF70 {
    unsigned char pad_0[0x1CB80];
    UnkStruct_00150300_car field_1CB80[1];  // [G] element count unknown
};

struct UnkStruct_D_00522660_c { unsigned char pad_0[0x1CC]; };
struct UnkStruct_D_00522660 {
    unsigned char pad_0[0x12A348];
    UnkStruct_D_00522660_c field_12A348[1];  // [G] element count unknown
};

struct UnkStruct_D_004EE040_c { unsigned char pad_0[0xBB0]; };
struct UnkStruct_D_004EE040 {
    unsigned char pad_0[0x29020];
    UnkStruct_D_004EE040_c field_29020[1];  // [G] element count unknown
};

struct UnkStruct_00150300 {
    unsigned char pad_0[0x18E4];
    int field_18E4;
    unsigned char pad_18E8[0xED8];
    int field_27C0;
    unsigned char pad_27C4[0x5];
    unsigned char field_27C9;
};

struct UnkStruct_D_00645170 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};
struct UnkStruct_D_00665EA0 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};
extern UnkStruct_D_00645170 D_00645170;
extern UnkStruct_D_00665EA0 D_00665EA0;
extern UnkStruct_D_0055EF70 D_0055EF70;
extern UnkStruct_D_00522660 D_00522660;
extern UnkStruct_D_004EE040 D_004EE040;

extern "C" int TestPosition__16CB3StreamedTrackFQ29GtMathPs26CGtV3d(void *, void *);

// 0x00150300
extern "C" int func_00150300(UnkStruct_00150300 * self)
{
    int r;
    if (self->field_27C9 == 0) {
        UnkStruct_00150300_car * c;
        if (self->field_27C0 < D_00645170.field_0) {
            c = &D_0055EF70.field_1CB80[self->field_27C0];
        } else {
            c = 0;
        }
        r = c->field_216;
    } else if (D_00665EA0.field_0 == 0) {
        r = self->field_18E4;
    } else {
        int i = self->field_27C0;
        r = TestPosition__16CB3StreamedTrackFQ29GtMathPs26CGtV3d(&D_00522660.field_12A348[i], &D_004EE040.field_29020[i]);
    }
    return r;
}
