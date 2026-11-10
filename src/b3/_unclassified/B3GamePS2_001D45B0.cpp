// CB3Game::ConstructHardware() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3GamePS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a72: do{}while(!sceSifRebootIop(..)) / do{}while(!sceSifSyncIop()) loops, SDK calls in retail order).

class CB3Game;
class CGtPS2LibNet;

class CB3Game {
public:
    void ConstructHardware();

    unsigned char pad_0[0x2DA70];
    int field_2DA70;
};

struct UnkStruct_D_004B80F0 { char field_0[0x20]; };
struct UnkStruct_D_004B8110 { char field_0[0x20]; };
struct UnkStruct_D_01E3C620 { unsigned char pad_0[0x20]; };
struct UnkStruct_D_01E3C66D { unsigned char field_0; unsigned char pad_1[0x10]; };

extern UnkStruct_D_004B80F0 D_004B80F0;
extern UnkStruct_D_004B8110 D_004B8110;
extern UnkStruct_D_01E3C620 D_01E3C620;
extern UnkStruct_D_01E3C66D D_01E3C66D;

extern "C" int sceSifInitRpc(int);
extern "C" int sceCdInit(int);
extern "C" int sceSifRebootIop(const char *);
extern "C" int sceSifSyncIop();
extern "C" int sceSifLoadFileReset();
extern "C" int sceFsReset();
extern "C" int sceCdMmode(int);
extern "C" int sceCdDiskReady(int);
extern "C" void SetNetworkConfigFileLocation__12CGtPS2LibNetFPCc(void *, const char *);

// 0x001D45B0
void CB3Game::ConstructHardware()
{
    sceSifInitRpc(0);
    sceCdInit(0);
    do {
    } while (!sceSifRebootIop(D_004B80F0.field_0));
    do {
    } while (!sceSifSyncIop());
    sceSifInitRpc(0);
    sceSifLoadFileReset();
    sceFsReset();
    sceCdInit(0);
    sceCdMmode(2);
    sceCdDiskReady(0);
    SetNetworkConfigFileLocation__12CGtPS2LibNetFPCc(&D_01E3C620, D_004B8110.field_0);
    D_01E3C66D.field_0 = 0;
    field_2DA70 = 1;
}
