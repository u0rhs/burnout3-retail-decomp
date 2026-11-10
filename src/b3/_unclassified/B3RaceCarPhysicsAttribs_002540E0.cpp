// CB3RaceCarPhysicsAttribs::Construct() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3RaceCarPhysicsAttribs.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// CB3RaceCarPhysicsAttribs has a header in include/ (pads and a few proven fields only): declared locally instead, as the
// hand-matched units of such classes do (B3AITarget_00149140.cpp) [lift3].

class CB3RaceCarPhysicsAttribs;

class CB3RaceCarPhysicsAttribs {
public:
    void Construct();

    unsigned char pad_0[0xB8];
    float field_B8;
    float field_BC;
    float field_C0;
    float field_C4;
    float field_C8;
    float field_CC;
    float field_D0;
    float field_D4;
    float field_D8;
    unsigned char pad_DC[0x4];
    float field_E0;
    int field_E4;
    float field_E8;
    float field_EC;
    float field_F0;
    float field_F4;
    float field_F8;
    float field_FC;
    float field_100;
    float field_104;
    float field_108;
    float field_10C;
    unsigned char pad_110[0x8];
    float field_118;
    float field_11C;
    float field_120;
    float field_124;
    float field_128;
    float field_12C;
    float field_130;
    int field_134;
    float field_138;
    float field_13C;
    float field_140;
    float field_144;
    float field_148;
    float field_14C;
    float field_150;
    float field_154;
    float field_158;
    float field_15C;
    float field_160;
    float field_164;
    float field_168;
    float field_16C;
    float field_170;
    float field_174;
    float field_178;
    float field_17C;
    float field_180;
    float field_184;
    float field_188;
    float field_18C;
    float field_190;
    float field_194;
    float field_198;
    float field_19C;
    float field_1A0;
    float field_1A4;
    float field_1A8;
    int field_1AC;
    float field_1B0;
    float field_1B4;
    int field_1B8;
    float field_1BC;
    float field_1C0;
    float field_1C4;
    float field_1C8;
    float field_1CC;
};

extern "C" void Construct__24CB3VehiclePhysicsAttribsFv(void *);  // CB3VehiclePhysicsAttribs::Construct()

// 0x002540E0
void CB3RaceCarPhysicsAttribs::Construct()
{
    Construct__24CB3VehiclePhysicsAttribsFv(this);
    field_B8 = 1000.0f;
    field_C8 = 0.2f;
    field_C0 = ((float)60000);
    field_C4 = ((float)5000);
    field_BC = 0.1f;
    field_D4 = 0.2f;
    field_CC = ((float)60000);
    field_D0 = ((float)5000);
    field_D8 = 0.1f;
    field_E0 = -1.0f;
    field_E4 = 0;
    field_E8 = 5.0f;
    field_EC = 5.0f;
    field_F0 = 5.0f;
    field_F4 = 5.0f;
    field_F8 = 5.0f;
    field_FC = 5.0f;
    field_100 = 5.0f;
    field_104 = 1000.0f;
    field_108 = ((float)6800);
    field_10C = ((float)4200);
    field_118 = ((float)6800);
    field_11C = ((float)630);
    field_120 = ((float)5000);
    field_124 = ((float)6500);
    field_128 = 2.0f;
    field_12C = 1.0f;
    field_130 = 1.9f;
    field_134 = 0;
    field_138 = -0.55f;
    field_13C = -0.35f;
    field_140 = -0.22f;
    field_144 = -0.23f;
    field_1B8 = 0;
    field_148 = 10.5f;
    field_150 = 23.0f;
    field_14C = 14.0f;
    field_154 = 12.0f;
    field_158 = 0.158f;
    field_190 = 2.0f;
    field_160 = 0.85f;
    field_164 = 0.75f;
    field_168 = 800.0f;
    field_16C = ((float)1100);
    field_170 = 0.77f;
    field_174 = 1.2f;
    field_194 = 65.0f;
    field_198 = 0.5f;
    field_1A0 = 45.0f;
    field_17C = 35.0f;
    field_180 = 50.0f;
    field_184 = 1.0f;
    field_188 = 0.9f;
    field_178 = 0.99f;
    field_18C = 4.0f;
    field_15C = 2.0f;
    field_19C = ((float)-5500);
    field_1A4 = 141.0f;
    field_1A8 = 0.8f;
    field_1AC = 0;
    field_1B4 = 5.0f;
    field_1B0 = 0.8f;
    field_1BC = 0.3f;
    field_1C0 = 1.0f;
    field_1C4 = 24.0f;
    field_1C8 = 50.0f;
    field_1CC = 0.5f;
}
