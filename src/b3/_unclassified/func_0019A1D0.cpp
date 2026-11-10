// Destruct__8CB3WorldFv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

class CB3CrashAnalyser;
class CB3EffectsManager;
class CB3EnvironmentManager;
class CB3GameData;
class CB3RacePosition;
class CB3ReplaySystem;
class CB3StaticTrack;
class CB3StreamManager;
struct UnkStruct_0019A1D0;

class CB3GameData {
public:
    void Destruct();
};

class CB3RacePosition {
public:
    void Destruct();
};

class CB3ReplaySystem {
public:
    void Destruct();
};

class CB3EnvironmentManager {
public:
    void Destruct();

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3EffectsManager {
public:
    void Destruct();

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3CrashAnalyser {
public:
    void Destruct();
};

class CB3StaticTrack {
public:
    void Destruct();
};

class CB3StreamManager {
public:
    void Destruct();
};

struct UnkStruct_0019A1D0 {
    unsigned char pad_0[0x3C888];
    CB3ReplaySystem field_3C888;
    unsigned char pad_3C889[0xE92B7];
    CB3GameData field_125B40;
    unsigned char pad_125B41[0x58F];
    CB3RacePosition field_1260D0;
    unsigned char pad_1260D1[0x21BF];
    CB3CrashAnalyser field_128290;
    unsigned char pad_128291[0x104F];
    CB3CrashAnalyser field_1292E0;
    unsigned char pad_1292E1[0x104F];
    CB3StaticTrack field_12A330;
    unsigned char pad_12A331[0x3AF];
    CB3StreamManager field_12A6E0;
    unsigned char pad_12A6E1[0x62F];
    unsigned long field_12AD10;
};

extern CB3EnvironmentManager D_01E85900;
extern CB3EffectsManager D_01D9D200;

extern "C" void Destruct__16CB3StreamedTrackFv(void *);  // CB3StreamedTrack::Destruct()
extern "C" void func_001B8B70(void *);
extern "C" void func_002B7280(void *);

// 0x0019A1D0
extern "C" void Destruct__8CB3WorldFv(UnkStruct_0019A1D0 * self)
{
    func_001B8B70(((char *)self + 0x3C910));
    self->field_125B40.Destruct();
    self->field_1260D0.Destruct();
    func_002B7280(((char *)self + 0x1281F4));
    self->field_3C888.Destruct();
    D_01E85900.Destruct();
    D_01D9D200.Destruct();
    self->field_128290.Destruct();
    self->field_1292E0.Destruct();
    self->field_12A330.Destruct();
    if (self->field_12AD10 != 0) {
        Destruct__16CB3StreamedTrackFv(((char *)self + 0x12A348));
        Destruct__16CB3StreamedTrackFv(((char *)self + 0x12A514));
        self->field_12A6E0.Destruct();
    }
}
