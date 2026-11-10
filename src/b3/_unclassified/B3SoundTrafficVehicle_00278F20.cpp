// CB3SoundTrafficVehicle::Activate(int,CB3TrafficVehicle*,signed char) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundTrafficVehicle.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (sprintf buffer char[12] declared first: an 8-aligned slot above the u64 results (16+ bytes is 16-aligned and goes below)).

struct UnkStruct_00278F20_f { float f; unsigned char pad_4[0xC]; };
struct UnkStruct_00278F20_r { int field_0; int field_4; unsigned char pad_8[0x8]; };
struct UnkStruct_00278F20_b { unsigned char pad_0[0x10]; };
class CB3TrafficVehicle { public: unsigned char pad_0[0x173]; signed char field_173; };
class CB3SoundTrafficVehicle {
public:
    void Deactivate();
    void Activate(int p0, CB3TrafficVehicle * p1, signed char p2);

    CB3TrafficVehicle * field_0;
    unsigned char pad_4[0xC];
    unsigned char field_10[0xBC];
    int field_CC;
    int field_D0;
    unsigned char pad_D4[0x14];
    float field_E8;
    float field_EC;
    float field_F0;
    unsigned char pad_F4[0xC];
    float field_100;
    float field_104;
    float field_108;
    float field_10C;
    int field_110;
    unsigned int field_114;
    unsigned char pad_118[0x8];
    int field_120;
    unsigned char field_124;
    unsigned char pad_125[0x2];
    unsigned char field_127;
    unsigned char field_128;
    unsigned char field_129;
    unsigned char field_12A;
    unsigned char field_12B;
    signed char field_12C;
};
extern UnkStruct_00278F20_r D_01E78E58;
extern UnkStruct_00278F20_f D_01E78EF8, D_01E78F00, D_01E78F08;
extern UnkStruct_00278F20_b D_01E75648;
extern char D_004BE4D0[], D_004BE4E0[], D_004BE4F0[];
extern UnkStruct_00278F20_f D_01E78E60;
extern UnkStruct_00278F20_f D_01E78E64;
extern UnkStruct_00278F20_f D_01E78E68;
extern UnkStruct_00278F20_f D_01E78E6C;
extern UnkStruct_00278F20_f D_01E78E70;
extern UnkStruct_00278F20_f D_01E78E74;
extern UnkStruct_00278F20_f D_01E78E78;
extern UnkStruct_00278F20_f D_01E78E7C;
extern UnkStruct_00278F20_f D_01E78E80;
extern UnkStruct_00278F20_f D_01E78E84;
extern UnkStruct_00278F20_f D_01E78E88;
extern UnkStruct_00278F20_f D_01E78E8C;
extern float _grLTrainRailsVolume, _grLTrainSqueakVolumeBase;
extern int _gnUpdatesBetweenSqueaks, _gnCarriageCount;
extern char kLTrainRailID[], kLTrainSqueakID[];
extern "C" int rand();
extern "C" int sprintf(char *, const char *, ...);
extern "C" unsigned long GtIDCompress__FPCc(const char *);
extern "C" void Prepare__19CB3SoundTrafficPassF25ETrafficVehicleCategoriesi(void *, int, signed char);
extern "C" int FindWave__19CGtSoundBankManagerCFRCUlb(void *, const void *, bool);

// [G] inlined random-number step (same as StartSkidVoices): D_01E78E58 = { x, y }
static inline unsigned int func_00278F20_inl1()
{
    UnkStruct_00278F20_r * const r = &D_01E78E58;
    int x = r->field_0;
    x = (x << 16) + (x >> 16);
    x += r->field_4;
    r->field_0 = x;
    r->field_4 += x;
    return x;
}

// 0x00278F20
void CB3SoundTrafficVehicle::Activate(int p0, CB3TrafficVehicle * p1, signed char p2)
{
    // [G] stack investigator: any size 9..15 (8-aligned slot, placed with the 8-byte locals in declaration order)
    // puts the buffer above the GtIDCompress__FPCc results as in retail; 16+ bytes goes below them (16-aligned locals).
    char name[12];
    unsigned long t1, t2, t3, t4, t5, t6, t7, t8;
    field_110 = p0;
    field_124 = 1;
    field_0 = p1;
    field_120 = p1->field_173;
    Prepare__19CB3SoundTrafficPassF25ETrafficVehicleCategoriesi(&field_10, field_120, p2);
    sprintf(name, D_004BE4D0, rand() % 5 + 1);
    field_114 = 0;
    field_12C = p2;
    field_128 = func_00278F20_inl1() % 10;
    field_127 = 0;
    if ((func_00278F20_inl1() & 1) == 0) {
        field_114 |= 0x20;
    }
    if (func_00278F20_inl1() % 100 < 60) {
        field_114 |= 0x10;
    }
    field_114 |= 8;
    field_12B = 0;
    field_12A = 0;
    field_EC = (float)func_00278F20_inl1() * 2.3283064e-10f;
    field_EC = (0.0f + (1.0f - D_01E78F00.f)) + (2.0f * field_EC) * D_01E78F00.f;
    field_F0 = (float)func_00278F20_inl1() * 2.3283064e-10f;
    field_F0 = (0.0f + 0.5f) + 0.5f * (2.0f * field_F0);
    field_F0 = field_F0 * D_01E78EF8.f;
    switch (field_120) {
    case 5:
        field_100 = D_01E78E70.f;
        field_104 = D_01E78E60.f;
        field_10C = D_01E78E84.f;
        field_108 = D_01E78E80.f;
        {
            t1 = GtIDCompress__FPCc(D_004BE4E0);
            field_D0 = FindWave__19CGtSoundBankManagerCFRCUlb(&D_01E75648, &t1, false);
            t2 = GtIDCompress__FPCc(name);
            field_CC = FindWave__19CGtSoundBankManagerCFRCUlb(&D_01E75648, &t2, false);
        }
        field_E8 = D_01E78F08.f;
        break;
    case 2:
    case 3:
        field_100 = D_01E78E78.f;
        field_104 = D_01E78E68.f;
        field_D0 = 0;
        {
            t3 = GtIDCompress__FPCc(name);
            field_CC = FindWave__19CGtSoundBankManagerCFRCUlb(&D_01E75648, &t3, false);
        }
        field_E8 = D_01E78E6C.f;
        break;
    case 4:
        field_100 = D_01E78E74.f;
        field_104 = D_01E78E64.f;
        field_10C = D_01E78E8C.f;
        field_108 = D_01E78E88.f;
        {
            t4 = GtIDCompress__FPCc(D_004BE4F0);
            field_D0 = FindWave__19CGtSoundBankManagerCFRCUlb(&D_01E75648, &t4, false);
            t5 = GtIDCompress__FPCc(name);
            field_CC = FindWave__19CGtSoundBankManagerCFRCUlb(&D_01E75648, &t5, false);
        }
        field_E8 = D_01E78F08.f;
        break;
    case 1:
        field_100 = D_01E78E7C.f;
        field_104 = D_01E78E6C.f;
        field_D0 = 0;
        {
            t6 = GtIDCompress__FPCc(name);
            field_CC = FindWave__19CGtSoundBankManagerCFRCUlb(&D_01E75648, &t6, false);
        }
        field_E8 = D_01E78E6C.f;
        break;
    case 11:
        field_114 &= ~8;
        field_100 = D_01E78E74.f;
        field_104 = D_01E78E64.f;
        field_D0 = 0;
        {
            t7 = GtIDCompress__FPCc(name);
            field_CC = FindWave__19CGtSoundBankManagerCFRCUlb(&D_01E75648, &t7, false);
        }
        field_E8 = 0;
        break;
    case 7:
        field_100 = 1.0f;
        field_104 = _grLTrainSqueakVolumeBase;
        field_10C = _grLTrainRailsVolume;
        field_108 = 1.0f;
        field_D0 = FindWave__19CGtSoundBankManagerCFRCUlb(&D_01E75648, kLTrainRailID, false);
        field_CC = FindWave__19CGtSoundBankManagerCFRCUlb(&D_01E75648, kLTrainSqueakID, false);
        field_129 = func_00278F20_inl1() % (unsigned int)_gnUpdatesBetweenSqueaks;
        field_114 &= ~7;
        if (_gnCarriageCount % 3 == 0) {
            field_114 |= 2;
            field_114 |= 4;
            field_114 |= 1;
        }
        _gnCarriageCount = _gnCarriageCount + 1;
        field_E8 = 0;
        break;
    case 8:
    case 9:
        field_100 = D_01E78E7C.f;
        field_104 = 0.0f;
        field_D0 = 0;
        {
            t8 = GtIDCompress__FPCc(name);
            field_CC = FindWave__19CGtSoundBankManagerCFRCUlb(&D_01E75648, &t8, false);
        }
        field_E8 = 0;
        break;
    case 6:
    case 10:
        Deactivate();
        return;
    case 0:
        break;
    }
}
