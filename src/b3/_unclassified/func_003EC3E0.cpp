// Hand-written; the lifter refused it (FSM Action; one-case switch on D_01E95C74 gives beqz;b exit).

struct UnkStruct_003EC3E0 { unsigned char pad_0[0x10]; int field_10; };
struct UnkStruct_D_x { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01E95C74 { int field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_x D_01E95C70;
extern UnkStruct_D_01E95C74 D_01E95C74;
extern UnkStruct_D_x D_01E95CA8;
extern UnkStruct_D_x D_01E98418;
extern "C" void func_003F1160(void *);
extern "C" int func_003F0FF0(void *);
extern "C" int func_003F2330(void *);
extern "C" int func_00454120(void *, int, int, int);
extern "C" void Action__24CB3MyBurnoutRewardsStateF14EGtStateActionPvPvPv(void *, int);
// 0x003EC3E0
extern "C" void func_003EC3E0(UnkStruct_003EC3E0 *self, int p0, int p1, int p2)
{
    switch (p0) {
    case 0:
        func_003F1160(&D_01E95C70);
        break;
    case 3:
        func_003F0FF0(&D_01E95C70);
        self->field_10 = 0;
        break;
    case 5:
        int st = self->field_10;
        switch (st) {
        case 1:
            switch (p2) {
            case 2:
            case 0:
                switch (D_01E95C74.field_0) {
                case 0: {
                    int v = func_003F2330(&D_01E95CA8);
                    func_00454120(&D_01E98418, 1, v, 1);
                    self->field_10 = 2;
                }
                }
                break;
            case 3:
                func_003F0FF0(&D_01E95C70);
                self->field_10 = 0;
                break;
            }
            break;
        case 0:
            Action__24CB3MyBurnoutRewardsStateF14EGtStateActionPvPvPv(self, p2);
            break;
        case 2:
            switch (p2) {
            case 2:
            case 0:
            case 3:
                self->field_10 = 0;
                Action__24CB3MyBurnoutRewardsStateF14EGtStateActionPvPvPv(self, 0);
                break;
            }
            break;
        }
        break;
    default:
        return;
    }
}
