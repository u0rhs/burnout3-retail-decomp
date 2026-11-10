// func_0033B710 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (rewritten from the draft: no phantom LobbyApiDisconnect args (field_104, 0); default: break to the shared return 1; case 2 written with the clear-and-set-3 tail once after if (112) {...} else if (!111) return 1; case 3 as one for loop with both conditions).

struct UnkStruct_0033B710;
struct UnkStruct_0033B710_1;
struct UnkStruct_0033B710_5;

struct UnkStruct_0033B710_1 {
    int field_0;
    unsigned char pad_4[0x1C];
    int field_20;
    unsigned char pad_24[0x10C];
    int field_130;
};

struct UnkStruct_0033B710_5 {
    int field_0;
    unsigned char pad_4[0x18];
    char field_1C[1];  // [G] length unknown
};

struct UnkStruct_D_004E2DAC {
    char * field_0;
};

struct UnkStruct_D_004C59E8 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004C5850 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0033B710 {
    unsigned char pad_0[0x104];
    int field_104;
    unsigned char pad_108[0x4];
    int field_10C;
    unsigned char field_110;
    unsigned char field_111;
    unsigned char field_112;
    unsigned char pad_113[0x1];
    int field_114;
    unsigned char pad_118[0x4];
    unsigned char field_11C;
    unsigned char pad_11D[0x3];
    unsigned char field_120;
    unsigned char field_121;
    unsigned char pad_122[0x2];
    int field_124;
    int field_128;
    int field_12C;
    int field_130;
    int field_134;
    unsigned char pad_138[0x124];
    UnkStruct_0033B710_5 * field_25C;
    int field_260;
    unsigned char pad_264[0x2FC];
    int field_560;
    unsigned char pad_564[0x14];
    char field_578[1];  // [G] length unknown
};

extern UnkStruct_D_004E2DAC D_004E2DAC;
extern UnkStruct_D_004C59E8 D_004C59E8;
extern UnkStruct_D_004C5850 D_004C5850;

extern "C" char * strcpy(char *, const char *);
extern "C" void ReJoinLobbyCallback__20CGtLobbyPS2DirtySockFPQ29DirtySock12LobbyApiRefTPQ29DirtySock12LobbyApiMsgTPv(void *, void *, void *);  // CGtLobbyPS2DirtySock::ReJoinLobbyCallback(DirtySock::LobbyApiRefT*,DirtySock::LobbyApiMsgT*,void*), its address taken
extern "C" void func_0033AC60(void *, void *, void *);
extern "C" int func_00338C10(int, int, void *);
extern "C" UnkStruct_0033B710_1 * LobbyApiInfoPtr(int, int);
extern "C" const char * SocketInAddrGetText(int);
extern "C" void TagFieldSetNumber(char *, int, void *, int);
extern "C" void TagFieldSetString(char *, int, void *, char *);
extern "C" void LobbyApiRequestCB(int, int, char *, void *, UnkStruct_0033B710 *);
extern "C" void LobbyApiDisconnect(int, int);
extern "C" void DispListFilt(int, int, int, void *);
extern "C" void DispListOrder(int);
extern "C" int func_0040A5D0(int);
extern "C" UnkStruct_0033B710_5 * DispListIndex(int, int);

// 0x0033B710
extern "C" int func_0033B710(UnkStruct_0033B710 * self)
{
    switch (self->field_10C) {
    case 0:
        return 0;
    case 1: {
        UnkStruct_0033B710_1 * info = LobbyApiInfoPtr(self->field_104, 0x73656C66);
        if (info->field_0 == 0) {
            return 1;
        }
        strcpy(self->field_578, SocketInAddrGetText(info->field_20));
        if (info->field_130 == 0) {
            self->field_134 = 0;
            self->field_111 = 1;
            self->field_10C = 0;
            return 1;
        }
        self->field_10C = 2;
        self->field_12C = info->field_130;
        self->field_121 = 0;
        self->field_124 = 0;
        self->field_130 = 0;
        *D_004E2DAC.field_0 = 0;
        TagFieldSetNumber(D_004E2DAC.field_0, 0x400, &D_004C59E8, info->field_130);
        LobbyApiRequestCB(self->field_104, 0x67676574, D_004E2DAC.field_0, (void *)&func_0033AC60, self);
        break;
    }
    case 2:
        if (self->field_112 != 0) {
            self->field_10C = 0;
            LobbyApiDisconnect(self->field_104, 0);
        } else if (self->field_111 == 0) {
            return 1;
        }
        self->field_111 = 0;
        self->field_10C = 3;
        return 1;
    case 3: {
        DispListFilt(self->field_560, 0, 1, (void *)&func_00338C10);
        DispListOrder(self->field_560);
        self->field_25C = 0;
        for (int i = 0; i < func_0040A5D0(self->field_560) && self->field_25C == 0; i++) {
            UnkStruct_0033B710_5 * e = DispListIndex(self->field_560, i);
            if (e != 0 && e->field_0 == self->field_260) {
                self->field_25C = e;
                *D_004E2DAC.field_0 = 0;
                TagFieldSetString(D_004E2DAC.field_0, 0x400, &D_004C5850, self->field_25C->field_1C);
                TagFieldSetNumber(D_004E2DAC.field_0, 0x400, &D_004C59E8, self->field_25C->field_0);
                LobbyApiRequestCB(self->field_104, 0x6D6F7665, D_004E2DAC.field_0, (void *)&ReJoinLobbyCallback__20CGtLobbyPS2DirtySockFPQ29DirtySock12LobbyApiRefTPQ29DirtySock12LobbyApiMsgTPv, self);
                self->field_10C = 4;
                self->field_110 = 1;
                self->field_111 = 0;
                self->field_112 = 0;
                self->field_120 = 0;
                self->field_114 = 0;
            }
        }
        break;
    }
    case 4:
        if (self->field_111 != 0) {
            self->field_10C = 0;
            self->field_128 = 0;
            self->field_11C = 1;
            self->field_111 = 0;
        } else if (self->field_112 != 0) {
            LobbyApiDisconnect(self->field_104, 0);
            self->field_10C = 0;
        }
        break;
    default:
        break;
    }
    return 1;
}
