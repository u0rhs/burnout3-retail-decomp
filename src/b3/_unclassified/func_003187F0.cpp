// Hand-written; the lifter refused it (a258: switch(D_01E900B4) cases 0,2,default in source order; id=0x17F in case 0 before the p2 test (delay-slot li); if (p1 != 9) guards the 0..6 jump table; D_004EE040 as 0x10-byte struct (a 0x28DB4-byte extern breaks jtbl_retarget's objdump -t parse)).

struct UnkStruct_I { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_B { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_P { unsigned char pad_0[0x10]; };
struct UnkStruct_D_004EE040 { unsigned char pad_0[0x10]; };
struct UnkStruct_003187F0_a2 { int field_0; };
extern UnkStruct_I D_01E900B4, D_01E900BC, D_01E900E0;
extern UnkStruct_B D_01E90223;
extern UnkStruct_P D_01E89518, D_01E90438, D_0051BA44;
extern UnkStruct_D_004EE040 D_004EE040;
extern "C" void func_00319C80(void *, int, int);
extern "C" int GetClassString__20CB3CarouselComponentF17EB3MenuCarClasses(int);
extern "C" int func_00271A00(void *, int);
extern "C" int AllocUTF16String__19CB3MenuStringBufferFi(void *, int);
extern "C" void func_003192A0(int, int, const UnkStruct_003187F0_a2 *);
extern "C" void Prepare__19CB3HeadingComponentFPCUsQ219CB3HeadingComponent12EHeadingType(void *, void *, int);
// 0x003187F0
extern "C" void func_003187F0(void *p0, int p1, int p2)
{
    int id;
    switch (D_01E900B4.field_0) {
    case 0:
        id = 0x17F;
        if (p2 != 0) {
            id = GetClassString__20CB3CarouselComponentF17EB3MenuCarClasses(p1);
        } else {
            if (p1 != 9)
            switch (p1) {
            case 0: id = 0xA94; break;
            case 1: id = 0xA95; break;
            case 2: id = 0xA96; break;
            case 3: id = 0xA97; break;
            case 4: id = 0xA98; break;
            case 5: id = 0xA99; break;
            case 6: id = 0xA9A; break;
            }
        }
        func_00319C80(&D_01E89518, id, 0xE);
        break;
    case 2:
        if (D_01E900BC.field_0 == 4) {
            if (D_01E90223.field_0 == 0) {
                UnkStruct_003187F0_a2 loc;
                loc.field_0 = func_00271A00(&D_0051BA44, D_01E900E0.field_0 + 0x309);
                int s1 = func_00271A00(&D_0051BA44, 0x9E3);
                int s0 = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 0x29);
                func_003192A0(s0, s1, &loc);
                Prepare__19CB3HeadingComponentFPCUsQ219CB3HeadingComponent12EHeadingType(&D_01E89518, (void *)(s0), 0xE);
            } else {
                func_00319C80(&D_01E89518, 0x17F, 0xE);
            }
        } else {
            int r = D_01E900E0.field_0 % 2;
            UnkStruct_003187F0_a2 loc;
            loc.field_0 = (int)((char *)&D_004EE040 + r * 36 + 0x28DB4);
            int s1 = func_00271A00(&D_0051BA44, 0x9E3);
            int s0 = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 0x29);
            func_003192A0(s0, s1, &loc);
            Prepare__19CB3HeadingComponentFPCUsQ219CB3HeadingComponent12EHeadingType(&D_01E89518, (void *)(s0), 0xE);
        }
        break;
    default:
        func_00319C80(&D_01E89518, 0x17F, 0xE);
        break;
    }
}
