// Hand-written; the lifter refused it (page Prepare(int,int,int): vdb one-time registration, two do-while stream loads (func_003865A0), func_003EB060 takes int).

struct UnkStruct_D_16 { unsigned char pad_0[0x10]; };
extern UnkStruct_D_16 D_01E7A888;
extern UnkStruct_D_16 D_01E75640;
extern UnkStruct_D_16 D_01E774E0;
extern UnkStruct_D_16 D_01E8EB40;
extern UnkStruct_D_16 D_01E8F2D8;
extern UnkStruct_D_16 D_01E89518;
extern UnkStruct_D_16 D_01E88A80;
extern UnkStruct_D_16 D_0051BA44;
extern UnkStruct_D_16 D_01E89788;
extern UnkStruct_D_16 D_01E89800;
extern UnkStruct_D_16 D_01E894FC;
struct UnkStruct_gVdbDatabase { int field_0; };
extern UnkStruct_gVdbDatabase mpToolBase__Q27GtComms16CGtCommsToolBase;
extern unsigned char D_004E2FB8;
extern int D_004E2644;
extern float D_004E2648;
extern float D_004E264C;
extern int D_004E2650;
extern int D_004E2654;
extern char D_004D33F0[];
extern char D_004D3400[];
extern "C" void AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(int, void *, void *, int, int, int, float, float, int);
extern "C" void func_003FA600(void *, int);
extern "C" void func_003FC470(void *);
extern "C" void func_0028B160(void *);
extern "C" int func_003865A0(void *, void *, int, int, int, int);
extern "C" int AllocStream__21CGtSoundStreamManagerFb(void *, int);
extern "C" void Prepare__15CB3MenuPageBaseFb(void *, bool);
extern "C" int func_003EB060(unsigned long);
extern "C" int func_003EAEA0(int);
extern "C" int func_003EAED0(int);
extern "C" int func_0042B030(void *, int, int);
extern "C" void func_0042B010(void *, unsigned long, int);
extern "C" int func_00456550(void *, int, int);
extern "C" void func_00319C80(void *, int, int);
extern "C" int Prepare__22CB3BackgroundComponentF17EB3BackgroundType(void *, int);
extern "C" const unsigned short *func_00271A00(void *, int);
extern "C" void Prepare__19CB3HelpBarComponentFPCUsbf(void *, const unsigned short *, bool, float);
extern "C" bool func_0031ECD0(void *, unsigned long, int);
extern "C" void Prepare__21CB3PromptBarComponentFv(void *);
struct UnkStruct_004547C0 {
    unsigned char pad_0[4];
    int field_4;
    int field_8;
    int field_C;
};

// 0x004547C0
extern "C" int func_004547C0(UnkStruct_004547C0 *self, unsigned long a1, int a2, int a3)
{
    if (D_004E2FB8 == 0) {
        AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase.field_0 + 16, &D_004E2648, D_004D33F0, D_004E2654, D_004E2650, 0, 0.0f, 0.0f, 0);
        AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase.field_0 + 16, &D_004E264C, D_004D3400, D_004E2654, D_004E2650, 0, 0.0f, 0.0f, 0);
        D_004E2FB8 = 1;
    }
    func_003FA600(&D_01E7A888, 3);
    func_003FC470(&D_01E7A888);
    if (self->field_C != 0x3E7) {
        self->field_4 = 0;
        self->field_8 = 0;
        self->field_C = 0x3E7;
    }
    if (self->field_4 == 0) self->field_4 = AllocStream__21CGtSoundStreamManagerFb(&D_01E774E0, 0);
    if (self->field_8 == 0) self->field_8 = AllocStream__21CGtSoundStreamManagerFb(&D_01E774E0, 0);
    do {
        func_0028B160(&D_01E75640);
    } while (!func_003865A0((void *)(self->field_4), (void *)(D_004E2644), 0, 0, 1, 4));
    do {
        func_0028B160(&D_01E75640);
    } while (!func_003865A0((void *)(self->field_8), (void *)(D_004E2644), 0, 0, 0x21, 4));
    Prepare__15CB3MenuPageBaseFb(self, 0);
    int id = func_003EB060(a1);
    int s4 = func_003EAEA0(id);
    int s3 = func_003EAED0(id);
    func_0042B030(&D_01E8EB40, 1, 0);
    func_0042B010(&D_01E8EB40, a1, a2);
    func_00456550(&D_01E8F2D8, 7, id);
    func_00319C80(&D_01E89518, s3, a3);
    Prepare__22CB3BackgroundComponentF17EB3BackgroundType(&D_01E88A80, 0xB);
    Prepare__19CB3HelpBarComponentFPCUsbf(&D_01E89788, func_00271A00(&D_0051BA44, s4), 0, 80.0f);
    func_0031ECD0(&D_01E89800, 0, 3);
    Prepare__21CB3PromptBarComponentFv(&D_01E894FC);
    return 1;
}
