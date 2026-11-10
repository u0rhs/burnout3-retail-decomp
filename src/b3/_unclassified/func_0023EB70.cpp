// Hand-written; the lifter refused it (a120: table of func_0022FE10 calls, generated).

class CGtNetworkPlayerManager { public: unsigned char pad_0[0x10]; };
extern CGtNetworkPlayerManager D_01E32AE0;
extern "C" void func_0022F960();
extern "C" void func_002C1C80(void *, void *, void *, void *, void *);
extern "C" void func_0022FE10(void *, int, int, void *, void *, void *, void *, void *);
extern "C" void GameModeStatusMessageArrivedCallback__17CB3NetworkManagerFP17CGtNetworkMessageiPv(void *, int, void *);
extern "C" void GameModeStatusMessageDeliveredCallback__17CB3NetworkManagerFbP17CGtNetworkMessagePv(bool, void *, void *);
extern "C" void NATDataMessageArrivedCallback__17CB3NetworkManagerFP17CGtNetworkMessageiPv(void *, int, void *);
extern "C" void ReplayBodyMessageArrivedCallback__17CB3NetworkManagerFP17CGtNetworkMessageiPv(void *, int, void *);
extern "C" void ReplayBodyMessageDeliveredCallback__17CB3NetworkManagerFbP17CGtNetworkMessagePv(bool, void *, void *);
extern "C" void ReplayHeaderMessageDeliveredCallback__17CB3NetworkManagerFbP17CGtNetworkMessagePv(bool, void *, void *);
extern "C" void func_0026E400(void *, int, int);
extern "C" void func_0026E460(void *, int, void *);
extern "C" void func_0026E800(void *, int, void *);
extern "C" void RaceReadyMessageArrivedCallback__17CB3NetworkManagerFP17CGtNetworkMessageiPv(void *, int, void *);
struct UnkStruct_0023EB70 {
    unsigned char pad_0[0x1644];
    void * field_1644;
};

// 0x0023EB70
extern "C" void func_0023EB70(UnkStruct_0023EB70 * self)
{
    func_0022F960();
    if (self->field_1644 != 0) {
        func_002C1C80(self->field_1644, self, (char *)self + 0x1650, (char *)self + 0x1780, (char *)self + 0x18B0);
    }
    func_0022FE10(self, 8, 576, (char *)self + 0x6E4, (char *)self + 0x924, 0, 0, 0);
    func_0022FE10(self, 11, 56, (char *)self + 0xBBC, 0, (void *)func_0026E460, 0, &D_01E32AE0);
    func_0022FE10(self, 10, 16, (char *)self + 0xBAC, 0, (void *)RaceReadyMessageArrivedCallback__17CB3NetworkManagerFP17CGtNetworkMessageiPv, 0, &D_01E32AE0);
    func_0022FE10(self, 12, 72, (char *)self + 0xB64, 0, (void *)func_0026E800, 0, &D_01E32AE0);
    func_0022FE10(self, 13, 20, (char *)self + 0xBF4, (char *)self + 0xC08, 0, 0, 0);
    func_0022FE10(self, 14, 20, (char *)self + 0xC1C, (char *)self + 0xC30, 0, 0, 0);
    func_0022FE10(self, 9, 80, (char *)self + 0xC6C, 0, (void *)NATDataMessageArrivedCallback__17CB3NetworkManagerFP17CGtNetworkMessageiPv, 0, &D_01E32AE0);
    func_0022FE10(self, 17, 20, (char *)self + 0xC44, (char *)self + 0xC58, 0, 0, 0);
    func_0022FE10(self, 15, 20, (char *)self + 0xCBC, (char *)self + 0xCD0, 0, 0, 0);
    func_0022FE10(self, 16, 52, (char *)self + 0xCE4, (char *)self + 0xD18, 0, 0, 0);
    func_0022FE10(self, 18, 112, (char *)self + 0xD50, 0, (void *)func_0026E400, (void *)ReplayHeaderMessageDeliveredCallback__17CB3NetworkManagerFbP17CGtNetworkMessagePv, &D_01E32AE0);
    func_0022FE10(self, 19, 1024, (char *)self + 0xE30, 0, (void *)ReplayBodyMessageArrivedCallback__17CB3NetworkManagerFP17CGtNetworkMessageiPv, (void *)ReplayBodyMessageDeliveredCallback__17CB3NetworkManagerFbP17CGtNetworkMessagePv, &D_01E32AE0);
    func_0022FE10(self, 20, 20, (char *)self + 0x1630, 0, (void *)GameModeStatusMessageArrivedCallback__17CB3NetworkManagerFP17CGtNetworkMessageiPv, (void *)GameModeStatusMessageDeliveredCallback__17CB3NetworkManagerFbP17CGtNetworkMessagePv, &D_01E32AE0);
}
