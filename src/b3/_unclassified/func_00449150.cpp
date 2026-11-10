// Hand-written; the lifter refused it (near3: case 1 ends in break (shared return 0xD) instead of default: return 0xD -- MWCC fills only the first branch to the shared stub, so case 2's b keeps its nop).



struct UnkStruct_D_004F50C0_x { unsigned char pad_0[0x10]; };
extern UnkStruct_D_004F50C0_x D_004F50C0;
extern "C" int GetMenuUp__15CB3InputManagerFSc(void *, signed char);
extern "C" int GetMenuDown__15CB3InputManagerFSc(void *, signed char);
extern "C" int GetMenuBack__15CB3InputManagerFSc(void *, signed char);
extern "C" bool GetMenuConfirm__15CB3InputManagerFSc(void *, signed char);
extern "C" int func_00319360(void *);
extern "C" int func_00319330(void *);
extern "C" void func_004482A0(void *, int);
struct UnkStruct_00449150_row { unsigned char field_0; unsigned char pad_1[7]; };
struct UnkStruct_00449150 {
    unsigned char pad_0[0xA];
    unsigned char field_A;
    unsigned char pad_B;
    unsigned short field_C;
    unsigned char pad_E[6];
    UnkStruct_00449150_row field_14[14];
    unsigned char pad_84[0xC];
    signed char field_90;
};

// 0x00449150
extern "C" int func_00449150(UnkStruct_00449150 *self, int pl, int a2 /* passed by every caller, not read here */)
{
    if (self->field_A == 0) return 0xD;
    if (self->field_90 == 0) return 0xD;
    if (GetMenuUp__15CB3InputManagerFSc(&D_004F50C0, pl) != 0) goto up;
down:
    if (GetMenuDown__15CB3InputManagerFSc(&D_004F50C0, pl) != 0) goto dn;
back:
    if (GetMenuBack__15CB3InputManagerFSc(&D_004F50C0, pl) == 0) goto conf;
    return 0xC;
up:
    if (func_00319360((char *)self + 0xC) == 0) goto down;
act:
    if (self->field_90 == 6) goto call;
ret:
    return 0xD;
dn:
    if (func_00319330((char *)self + 0xC) != 0) goto act;
    goto back;
call:
    func_004482A0(self, self->field_C);
    goto ret;
conf:
    bool cf = GetMenuConfirm__15CB3InputManagerFSc(&D_004F50C0, pl);
    if (cf) {
        int idx = self->field_C;
        switch (self->field_90) {
        case 1:
            switch (idx) {
            case 0: return 0;
            case 1: return 1;
            }
            break;
        case 2:
            switch (idx) {
            case 0: return 2;
            }
            break;
        case 3:
            switch (idx) {
            case 0: return 2;
            case 1: return 3;
            }
            break;
        case 4:
            switch (idx) {
            case 0: return 4;
            case 1: return 5;
            }
            break;
        case 5:
            switch (idx) {
            case 0: return 4;
            case 1: return 6;
            case 2: return 7;
            case 3: return 8;
            }
            break;
        case 6:
            if (self->field_14[idx].field_0 == 0) {
                switch (idx) {
                case 0: return 9;
                case 1: return 0xA;
                case 2: return 0xB;
                }
                break;
            }
            return 0xD;
        }
    }
    return 0xD;
}
