// Hand-written; the lifter refused it (records page status FSM; switch(st) case1,case2 block form; pmaxw helpers).

struct UnkStruct_D_01E3CD44 { virtual void vfunc_8(); virtual void vfunc_C(); virtual void vfunc_10(); virtual void vfunc_14(); virtual void vfunc_18(); virtual void vfunc_1C(); virtual void vfunc_20(); virtual void vfunc_24(); virtual void vfunc_28(); virtual void vfunc_2C(); virtual void vfunc_30(); virtual void vfunc_34(); virtual void vfunc_38(); virtual void vfunc_3C(); virtual void vfunc_40(); virtual void vfunc_44(); virtual void vfunc_48(); virtual void vfunc_4C(); virtual void vfunc_50(); virtual void vfunc_54(); virtual void vfunc_58(); unsigned char pad_4[0xC]; };
struct UnkStruct_D_01E898E8 { virtual void vfunc_8(); virtual void vfunc_C(); unsigned char pad_4[0xC]; };
struct UnkStruct_D_01E898F2 { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_0x10 { unsigned char pad_0[0x10]; };
struct UnkStruct_7E30 {
    unsigned char pad_0[0xEDC];
    short field_EDC;
    short field_EDE;
    short field_EE0;
    short field_EE2;
    unsigned char pad_EE4[0xC];
    int field_EF0;
    unsigned char pad_EF4[0x4];
    int field_EF8;
    int field_EFC;
    int field_F00;
    unsigned char pad_F04[0x1];
    unsigned char field_F05;
    unsigned short field_F06;
};
extern UnkStruct_D_01E3CD44 D_01E3CD44;
extern UnkStruct_D_01E898E8 D_01E898E8;
extern UnkStruct_D_01E898F2 D_01E898F2;
extern UnkStruct_D_0x10 D_01E32AE0;
extern "C" int GetLobbyStatus__17CB3NetworkManagerFv(void *);
extern "C" int GetNumberRankRecords__20CGtLobbyPS2DirtySockFv(void *);
extern "C" int func_00336780(void *);
extern "C" int func_003367B0(void *);
extern "C" int func_00336790(void *);
extern "C" int func_00376A60(UnkStruct_7E30 *, int);
extern "C" void func_0032D080(void *, int, int, int, int);
static inline int a129_max(int a, int b) { int r; asm("pmaxw %0, %1, %2" : "=r"(r) : "r"(a), "r"(b)); return r; }
static inline unsigned int a129_zx(int a) { unsigned int r; asm("pextlw %0, $0, %1" : "=r"(r) : "r"(a)); return r; }
// 0x00377E30
extern "C" void func_00377E30(UnkStruct_7E30 * self)
{
    int st = GetLobbyStatus__17CB3NetworkManagerFv(&D_01E32AE0);
    if (st == 0) return;
    switch (st) {
    case 1:
        self->field_F05 = 5;
        ((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_58();
        if (D_01E898F2.field_0 != 0) {
            ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
        }
        func_0032D080(&D_01E898E8, 2, 0x4EE, 0, 0);
        break;
    case 2:
        if (func_00336780(&D_01E3CD44) != 0) {
            int s0 = func_003367B0(&D_01E3CD44);
            if (self->field_F06 == 0 && s0 != -1 && GetNumberRankRecords__20CGtLobbyPS2DirtySockFv(&D_01E3CD44) > 5) {
                self->field_EF0 = s0 - 2;
                int e = self->field_EF0 + 5;
                if (e > GetNumberRankRecords__20CGtLobbyPS2DirtySockFv(&D_01E3CD44)) {
                    if (GetNumberRankRecords__20CGtLobbyPS2DirtySockFv(&D_01E3CD44) > 5) {
                        self->field_EF0 = GetNumberRankRecords__20CGtLobbyPS2DirtySockFv(&D_01E3CD44) - 5;
                    }
                }
                if (self->field_EF0 < 0) self->field_EF0 = 0;
                self->field_EDC = (s0 - 2) - self->field_EF0;
                self->field_EDE = 5;
            } else {
                self->field_EF0 = 0;
            }
            if (func_00376A60(self, self->field_EF0) != 0) {
                self->field_F05 = 4;
                self->field_EF8 = func_00336790(&D_01E3CD44);
                self->field_EFC = self->field_EF8;
                int n = GetNumberRankRecords__20CGtLobbyPS2DirtySockFv(&D_01E3CD44);
                self->field_F00 = a129_zx(a129_max(self->field_F00, self->field_EF8 + n));
                int ta = self->field_EF8;
                int tb = self->field_EF0;
                int tc = self->field_F00;
                self->field_EE0 = ta + tb;
                self->field_EE2 = tc;
                if (D_01E898F2.field_0 != 0) {
                    ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
                }
            }
        }
        break;
    }
}
