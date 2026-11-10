// Hand-written; the lifter refused it (hand-written from the asm; if (x >= 0) socket shutdowns, ezNetCtlExit(2)).

// func_0022F510
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. [G] self looks like a CGtPS2LibNet (same thread/socket fields 0x8C..0xB0, 0x708), but the
// function sits in no named slot, so it stays a placeholder struct. Field types are [G] (instruction widths).
struct UnkStruct_0022F510_1 {
    unsigned char pad_0[0x50];
    unsigned char field_50[0x3C];
    int field_8C;
    int field_90;
    int field_94;
    int field_98;
    int field_9C;
    unsigned char pad_A0[0xC];
    int field_AC;
    int field_B0;
    unsigned char pad_B4[0x654];
    unsigned char field_708;
};

extern "C" void TerminateThread(int);
extern "C" void DeleteThread(int);
extern "C" void DeleteSema(int);
extern "C" void sceInsockShutdown(int, int);
extern "C" int ezNetCtlInit();
extern "C" int ezNetCtlDownInterface();
extern "C" int ezNetCtlWaitEventTO(int);
extern "C" int ezNetCtlExit(int);
extern "C" void sceLibnetUnregisterHandler(void *, void *);
extern "C" void sceLibnetTerminate(void *);
extern "C" void sceInsockTerminate(int);
extern "C" void func_0022D320(UnkStruct_0022F510_1 *);
extern unsigned char D_01D7B700[];

// 0x0022F510
extern "C" void func_0022F510(UnkStruct_0022F510_1 *self)
{
    TerminateThread(self->field_8C);
    TerminateThread(self->field_90);
    TerminateThread(self->field_94);
    if (self->field_98 != -1) TerminateThread(self->field_98);
    DeleteSema(self->field_9C);
    self->field_9C = -1;
    if (self->field_AC >= 0) { sceInsockShutdown(self->field_AC, 2); self->field_AC = -1; }
    if (self->field_B0 >= 0) { sceInsockShutdown(self->field_B0, 2); self->field_B0 = -1; }
    if (self->field_708) {
        ezNetCtlInit();
        ezNetCtlDownInterface();
        ezNetCtlWaitEventTO(10000);
        ezNetCtlExit(2);
        sceLibnetUnregisterHandler(self->field_50, D_01D7B700);
        sceLibnetTerminate(self->field_50);
        sceInsockTerminate(self->field_94);
        sceInsockTerminate(0);
        self->field_708 = 0;
    }
    DeleteThread(self->field_8C);
    DeleteThread(self->field_90);
    DeleteThread(self->field_94);
    if (self->field_98 != -1) DeleteThread(self->field_98);
    self->field_8C = -1;
    self->field_90 = -1;
    self->field_94 = -1;
    self->field_98 = -1;
    func_0022D320(self);
}
