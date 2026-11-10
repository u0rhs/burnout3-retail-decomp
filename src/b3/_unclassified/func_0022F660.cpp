// Hand-written; the lifter refused it (a118: CGtPS2LibNet init-like (4 threads via CreateThread__12CGtThreadMgrFPFPv_iPviQ212CGtThreadMgr17EThreadPriorities); store field_6CC before the memset call (delay slot), sb=2 after).

struct UnkStruct_0022F660_row { int field_0; unsigned char pad_4[0x14]; };
struct UnkStruct_0022F660_sema { unsigned char pad_0[0x4]; int field_4; int field_8; unsigned char pad_C[0xC]; };
struct UnkStruct_0022F660 {
    unsigned char pad_0[0x48];
    int field_48;
    unsigned char field_4C;
    unsigned char pad_4D[0x57];
    int field_A4;
    unsigned char pad_A8[0x4];
    int field_AC;
    int field_B0;
    UnkStruct_0022F660_row field_B4[32];
    int field_3B4;
    int field_3B8;
    UnkStruct_0022F660_row field_3BC[32];
    int field_6BC;
    int field_6C0;
    int field_6C4;
    int field_6C8;
    int field_6CC;
    int field_6D0;
    unsigned char field_6D4[0x10];
    unsigned char pad_6E4[0x24];
    unsigned char field_708;
    unsigned char pad_709[0x7];
    int field_710;
};
extern void * _gThreadParam;
extern int _gnSendMsgMonitor;
extern int _gnRecvMsgMonitor;
extern "C" void * memset(void *, int, unsigned int);
extern "C" int CreateSema(UnkStruct_0022F660_sema *);
extern "C" int CreateThread__12CGtThreadMgrFPFPv_iPviQ212CGtThreadMgr17EThreadPriorities(void *, void *, int, void *);
extern "C" void func_0022F8B0(void *);
extern "C" void func_0022F8A0(void *);
extern "C" void func_0022F800(void *);
extern "C" void func_0022F890(void *);
extern "C" void func_0022D330(void *);

// 0x0022F660
extern "C" void func_0022F660(UnkStruct_0022F660 * self)
{
    UnkStruct_0022F660_sema sema;
    self->field_48 = 1;
    self->field_4C = 1;
    self->field_A4 = -1;
    self->field_AC = -1;
    self->field_B0 = -1;
    for (int i = 0; i < 32; i++) {
        self->field_B4[i].field_0 = 0;
    }
    self->field_3B4 = 0;
    self->field_3B8 = 0;
    for (int j = 0; j < 32; j++) {
        self->field_3BC[j].field_0 = 0;
    }
    self->field_6BC = 0;
    self->field_6D0 = 0;
    self->field_6C4 = 0;
    self->field_6C0 = 0;
    self->field_6C8 = 0;
    self->field_6CC = 0;
    memset(self->field_6D4, 0, 0x10);
    self->field_6D4[1] = 2;
    _gThreadParam = self;
    memset(&sema, 0, 0x18);
    sema.field_8 = 1;
    sema.field_4 = 1;
    *(int *)((char *)self + 0x9C) = CreateSema(&sema);
    *(int *)((char *)self + 0x8C) = CreateThread__12CGtThreadMgrFPFPv_iPviQ212CGtThreadMgr17EThreadPriorities((void *)func_0022F8B0, &_gThreadParam, 0x3000, (void *)(0x35));
    *(int *)((char *)self + 0x90) = CreateThread__12CGtThreadMgrFPFPv_iPviQ212CGtThreadMgr17EThreadPriorities((void *)func_0022F8A0, &_gThreadParam, 0x3000, (void *)(0x35));
    *(int *)((char *)self + 0x94) = CreateThread__12CGtThreadMgrFPFPv_iPviQ212CGtThreadMgr17EThreadPriorities((void *)func_0022F800, &_gThreadParam, 0x6000, (void *)(0x35));
    *(int *)((char *)self + 0x98) = CreateThread__12CGtThreadMgrFPFPv_iPviQ212CGtThreadMgr17EThreadPriorities((void *)func_0022F890, &_gThreadParam, 0x3000, (void *)(0x20));
    self->field_710 = 5;
    self->field_708 = 0;
    if (_gnSendMsgMonitor == -1) {
        _gnSendMsgMonitor = 0;
    }
    if (_gnRecvMsgMonitor == -1) {
        _gnRecvMsgMonitor = 0;
    }
    func_0022D330(self);
}
