// NONMATCHING: func_00234AB0 -- retail 94 / ours 94 instructions, 46 in changed runs
// 94=94 instrs, only s-register allocation differs: retail row=s0,i=s1,self=s2,&a[1..3]=s1/s3/s0; ours i=s0,self=s1,row=s2. field_524 must be int to get bnez-skip layout
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

struct UnkStruct_00234AB0_nm {
    unsigned char pad_0[0x1C];
    char field_1C[1];
};
struct UnkStruct_0022D9F0_blk {
    unsigned char pad_0[0x10];
};
struct UnkStruct_00234AB0_row {
    int field_0;
    int field_4;
    int field_8;
    int field_C;
    int field_10;
    int field_14;
    int field_18;
    int field_1C;
    int field_20;
    int field_24;
    int field_28;
    float field_2C;
    int field_30;
    unsigned char field_34;
    unsigned char pad_35[0x1F];
    float field_54;
    unsigned char field_58;
    unsigned char field_59;
    unsigned char field_5A;
    unsigned char field_5B;
    unsigned char field_5C;
    unsigned char field_5D;
    unsigned char field_5E;
    unsigned char pad_5F;
    UnkStruct_0022D9F0_blk field_60;
    UnkStruct_0022D9F0_blk field_70;
    UnkStruct_0022D9F0_blk field_80;
};
struct UnkStruct_00234AB0 {
    UnkStruct_00234AB0_row field_0[8];
    unsigned char pad_480[0x524 - 0x480];
    int field_524;
    int field_528;
    unsigned char pad_52C[0x55C - 0x52C];
    char field_55C[0x10];
    int field_56C;
    unsigned char pad_570[0xAC2 - 0x570];
    unsigned char field_AC2;
};
struct UnkStruct_D_004BA018 {
    unsigned char pad_0[0x10];
};
extern UnkStruct_D_004BA018 D_004BA018;
extern "C" char *strncpy(char *, const char *, unsigned int);
extern "C" int sscanf(const char *, const void *, ...);
extern "C" void func_0022D9F0(void *);
extern "C" int func_00230600(UnkStruct_00234AB0 *, UnkStruct_00234AB0_nm *, int, float);

// 0x00234AB0
// [L] DNAT: CGtNATDataManager::GetMyNATData(int) (research/proto/new_names.csv, low) -- hint only
extern "C" int func_00234AB0(UnkStruct_00234AB0 *self, UnkStruct_00234AB0_nm *p0, void *p1_, float p2)
{
    int p1 = (int)p1_;
    if (self->field_524 == 0) {
        int a[4];
        self->field_524 = (int)p0;
        self->field_528 = p1;
        strncpy(self->field_55C, ((UnkStruct_00234AB0_nm *)self->field_524)->field_1C, 16);
        sscanf(self->field_55C, &D_004BA018, &a[0], &a[1], &a[2], &a[3]);
        self->field_56C = (a[0] << 24) + (a[1] << 16) + (a[2] << 8) + a[3];
        for (int i = 0; i < 8; i++) {
            UnkStruct_00234AB0_row *r = &self->field_0[i];
            r->field_0 = 4;
            r->field_4 = -1;
            r->field_8 = -1;
            r->field_C = -1;
            r->field_10 = -1;
            r->field_14 = -1;
            r->field_18 = -1;
            r->field_1C = 0;
            r->field_20 = 0;
            r->field_24 = -1;
            r->field_28 = -1;
            r->field_2C = -1.0f;
            r->field_30 = 0;
            r->field_34 = 0;
            r->field_54 = -1.0f;
            r->field_58 = 0;
            r->field_59 = 0;
            r->field_5A = 0;
            r->field_5B = 0;
            r->field_5C = 0;
            r->field_5D = 0;
            r->field_5E = 0;
            func_0022D9F0(&r->field_60);
            func_0022D9F0(&r->field_70);
            func_0022D9F0(&r->field_80);
        }
    }
    self->field_AC2 = 0;
    return func_00230600(self, (UnkStruct_00234AB0_nm *)self->field_524, self->field_528, p2);
}
