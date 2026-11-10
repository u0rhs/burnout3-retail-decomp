// CB3OnlineGameCreatePage::Prepare(CB3LobbyCreateGameParams*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3OnlineGameCreatePage.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (vfunc_34 takes only p0; u16 buf[64]; 8-byte union copies for ld/sd; locals bp,q,q2,buf in that order).

// from build/vt\try_Prepare__23CB3OnlineGameCreatePageFP24CB_best.cpp
// CB3OnlineGameCreatePage::Prepare(CB3LobbyCreateGameParams*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3OnlineGameCreatePage.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3LobbyCreateGameParams;
union UnkPair { unsigned long l; struct { int a; int b; } s; };
enum EB3BackgroundType {};
enum ELobbyKickReason {};

class CB3OnlineGameCreatePage;
class CB3PromptBarComponent;
struct CB3LobbyCreateGameParams;
struct UnkStruct_00327310_2;
struct UnkStruct_D_004C5508;
struct UnkStruct_D_004C5510;
struct UnkStruct_D_004C5518;
struct UnkStruct_D_004C5520;
struct UnkStruct_D_004C5528;
struct UnkStruct_D_0051BA44;
struct UnkStruct_D_00665ECE;
struct UnkStruct_D_01E32AE0;
struct UnkStruct_D_01E3CD44;
struct UnkStruct_D_01E3D596;
struct UnkStruct_D_01E88A80;
struct UnkStruct_D_01E89518;
struct UnkStruct_D_01E89788;
struct UnkStruct_D_01E8D4B0;
struct UnkStruct_D_01E90198;
struct UnkStruct_D_01E901F0;
struct UnkStruct_D_01E90438;

class CB3PromptBarComponent {
public:
    void Prepare();

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct CB3LobbyCreateGameParams {
    int field_0;
    unsigned char pad_4[0x8];
    int field_C;
    unsigned char pad_10[0x8];
    int field_18;
    unsigned char pad_1C[0x4];
    int field_20;
    int field_24;
    int field_28;
    void * field_2C;
    void * field_30;
    void * field_34;
    void * field_38;
};

struct UnkStruct_00327310_2 {
    unsigned char pad_0[0x88];
    int field_88;
    int field_8C;
    int field_90;
    int field_94;
    unsigned char pad_98[0x4];
    void * field_9C;
};

struct UnkStruct_D_00665ECE {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E90198 {
    unsigned long field_0;
    unsigned char pad_8[0x8];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E901F0 {
    unsigned long field_0;
    unsigned char pad_8[0x8];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E3D596 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E3CD44 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18();
    virtual void vfunc_1C();
    virtual void vfunc_20();
    virtual void vfunc_24();
    virtual void vfunc_28();
    virtual void vfunc_2C();
    virtual void vfunc_30();
    virtual void vfunc_34(CB3LobbyCreateGameParams *);
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E90438 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E89518 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E88A80 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0051BA44 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E8D4B0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004C5508 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004C5510 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004C5518 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004C5520 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004C5528 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E89788 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E32AE0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3OnlineGameCreatePage {
public:
    int Prepare(CB3LobbyCreateGameParams* p0);

    unsigned char pad_0[0x4];
    int field_4;
    unsigned char pad_8[0x24];
    unsigned char field_2C;
};

extern UnkStruct_D_00665ECE D_00665ECE;
extern UnkStruct_D_01E90198 D_01E90198;
extern UnkStruct_D_01E901F0 D_01E901F0;
extern UnkStruct_D_01E3D596 D_01E3D596;
extern UnkStruct_D_01E3CD44 D_01E3CD44;
extern UnkStruct_D_01E90438 D_01E90438;
extern UnkStruct_D_01E89518 D_01E89518;
extern UnkStruct_D_01E88A80 D_01E88A80;
extern CB3PromptBarComponent D_01E894FC;
extern UnkStruct_D_0051BA44 D_0051BA44;
extern UnkStruct_D_01E8D4B0 D_01E8D4B0;
extern UnkStruct_D_004C5508 D_004C5508;
extern UnkStruct_D_004C5510 D_004C5510;
extern UnkStruct_D_004C5518 D_004C5518;
extern UnkStruct_D_004C5520 D_004C5520;
extern UnkStruct_D_004C5528 D_004C5528;
extern UnkStruct_D_01E89788 D_01E89788;
extern UnkStruct_D_01E32AE0 D_01E32AE0;

extern "C" void Prepare__15CB3MenuPageBaseFb(void *, bool);  // CB3MenuPageBase::Prepare(bool)
extern "C" int Prepare__22CB3BackgroundComponentF17EB3BackgroundType(void *, EB3BackgroundType);  // CB3BackgroundComponent::Prepare(EB3BackgroundType)
extern "C" void Prepare__19CB3HelpBarComponentFPCUsbf(void *, const unsigned short*, bool, float);  // CB3HelpBarComponent::Prepare(const unsigned short*,bool,float)
extern "C" bool PlayerListChangedCallback__17CB3NetworkManagerFiPv(int, void*);  // CB3NetworkManager::PlayerListChangedCallback(int,void*), its address taken
extern "C" int PlayerBootedCallback__17CB3NetworkManagerF16ELobbyKickReasonPv(ELobbyKickReason, void*);  // CB3NetworkManager::PlayerBootedCallback(ELobbyKickReason,void*), its address taken
extern "C" char * strncpy(char *, const char *, unsigned int);
extern "C" int AllocUTF16String__19CB3MenuStringBufferFi(void *, int);
extern "C" void func_00319C80(void *, int, int);
extern "C" void ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(int, UnkStruct_00327310_2 *, int);
extern "C" int func_00271A00(void *, int);
extern "C" void func_003180A0(void *, void *, void *);
extern "C" bool func_00351E40(void *, void *, void *, void *, void *, void *, void *, int, int, int, int, float, float);
extern "C" void func_00235D90(void *);
extern "C" void func_0022D3F0();
extern "C" void ClearAllPlayers__23CGtNetworkPlayerManagerFv(void *);

// [L] name per retail tables; no DNAT row
// 0x00327310
int CB3OnlineGameCreatePage::Prepare(CB3LobbyCreateGameParams* p0)
{
    void * bp;
    UnkPair q;
    UnkPair q2;
    unsigned short buf[0x40];
    Prepare__15CB3MenuPageBaseFb(this, 0);
    field_4 = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 64);
    func_00319C80(&D_01E89518, 1068, 14);
    Prepare__22CB3BackgroundComponentF17EB3BackgroundType(&D_01E88A80, (EB3BackgroundType)0);
    D_01E894FC.Prepare();
    ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(p0->field_0, (UnkStruct_00327310_2 *)buf, 64);
    bp = buf;
    func_003180A0((void *)(field_4), (void *)(func_00271A00(&D_0051BA44, 96)), &bp);
    func_00351E40(&D_01E8D4B0, &D_004C5508, &D_004C5510, &D_004C5518, &D_004C5520, &D_004C5528, (void *)(field_4), 3, 1, 103, 0, 32.0f, 496.0f);
    Prepare__19CB3HelpBarComponentFPCUsbf(&D_01E89788, (const unsigned short*)field_4, 1, 80.0f);
    field_2C = 0;
    func_00235D90(&D_01E32AE0);
    func_0022D3F0();
    ClearAllPlayers__23CGtNetworkPlayerManagerFv(&D_01E32AE0);
    if (D_00665ECE.field_0 != 0) {
        p0->field_18 = (p0->field_18 & -256);
        p0->field_18 = (p0->field_18 | 20);
    } else {
        p0->field_18 = (p0->field_18 & -256);
        p0->field_18 = (p0->field_18 | 36);
    }
    p0->field_2C = (void *)&PlayerListChangedCallback__17CB3NetworkManagerFiPv;
    p0->field_30 = &D_01E32AE0;
    p0->field_34 = (void *)&PlayerBootedCallback__17CB3NetworkManagerF16ELobbyKickReasonPv;
    p0->field_38 = &D_01E32AE0;
    q.l = D_01E90198.field_0;
    p0->field_C = q.s.a;
    p0->field_20 = q.s.b;
    q2.l = D_01E901F0.field_0;
    p0->field_24 = q2.s.a;
    p0->field_28 = q2.s.b;
    D_01E3D596.field_0 = 0;
    ((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_34(p0);
    strncpy((char *)((char *)this + 0xC), (const char *)p0->field_0, 32);
    return 1;
}
