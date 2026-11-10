// Hand-written; the lifter refused it (direct g->f98 > rec->f40 compares (slt at)).

struct UnkStruct_0042F650 {
    unsigned char pad_0[0xD5];
    unsigned char field_D5;
    unsigned char pad_D6[1];
    unsigned char field_D7;
    unsigned char field_D8;
    unsigned char pad_D9[6];
    signed char field_DF;
};
struct UnkStruct_0042F650_f { unsigned char pad_0[0x73]; unsigned char field_73; };
struct UnkStruct_0042F650_g { unsigned char pad_0[0x1B4]; UnkStruct_0042F650_f *field_1B4; };
struct UnkStruct_D_0051BA88_x { UnkStruct_0042F650_g *field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_0064EA70_x { unsigned char pad_0[0x98]; int field_98; };
struct UnkStruct_D_01E32B08_x { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_0042F650_rec { unsigned char pad_0[0x40]; int field_40; };
struct UnkStruct_D_Pad16 { unsigned char pad_0[0x10]; };
extern UnkStruct_D_0051BA88_x D_0051BA88;
extern UnkStruct_D_0064EA70_x D_0064EA70;
extern UnkStruct_D_01E32B08_x D_01E32B08;
extern UnkStruct_D_Pad16 D_01E32AE0;
extern "C" void *func_002366D0(void *, int);
extern "C" int func_0022FBB0(void *);
extern "C" UnkStruct_0042F650_rec *GetPlayerRecordByID__17CB3NetworkManagerFi(void *, int);
// 0x0042F650
extern "C" void func_0042F650(UnkStruct_0042F650 *self)
{
    if (self->field_DF == 13 && self->field_D8 != 0 && self->field_D7 == 0 && self->field_D5 != 0) {
        UnkStruct_D_0064EA70_x * const g = &D_0064EA70;
        int id = -1;
        for (int i = 0; i < D_01E32B08.field_0; i++) {
            void *r = func_002366D0(&D_01E32AE0, i);
            if (r != 0) {
                id = func_0022FBB0(r);
            }
        }
        UnkStruct_0042F650_rec *rec = GetPlayerRecordByID__17CB3NetworkManagerFi(&D_01E32AE0, id);
        if (rec != 0) {
            if (D_0051BA88.field_0->field_1B4->field_73 != 0) {
                if (rec != 0) {
                    if (g->field_98 > rec->field_40) {
                        self->field_DF = 11;
                    } else if (rec->field_40 > g->field_98) {
                        self->field_DF = 12;
                    } else {
                        self->field_DF = 10;
                    }
                }
            }
        }
    }
}
