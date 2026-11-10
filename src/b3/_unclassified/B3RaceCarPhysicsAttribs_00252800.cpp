// CB3RaceCarPhysicsAttribs::Unregister() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3RaceCarPhysicsAttribs.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (generated from the retail call list: 64 RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv calls in retail order).

class CB3RaceCarPhysicsAttribs {
public:
    void Unregister();

    char field_0[0xB0];  // [G] the .cfg file name (Register sprintf()s it)
    unsigned long field_B0;
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
    float field_E4;
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
    float field_134;
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
    unsigned char pad_1A8[0x8];
    float field_1B0;
    float field_1B4;
    unsigned char pad_1B8[0x4];
    float field_1BC;
    float field_1C0;
    float field_1C4;
    float field_1C8;
    float field_1CC;
};

extern int mpToolBase__Q27GtComms16CGtCommsToolBase;
extern "C" void RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(int, void *);

// 0x00252800
void CB3RaceCarPhysicsAttribs::Unregister()
{
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_B8);
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_BC);
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_C8);
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_C0);
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_C4);
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_D8);
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_D4);
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_CC);
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_D0);
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_138);
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_13C);
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_140);
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_144);
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_17C);
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_180);
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_184);
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_188);
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_130);
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_134);
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_178);
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_18C);
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_15C);
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_19C);
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_1A4);
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_1B4);
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_1B0);
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_11C);
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_120);
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_124);
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_104);
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_118);
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_10C);
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_108);
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_E0);
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_E4);
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_E8);
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_EC);
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_F0);
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_F4);
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_F8);
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_FC);
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_100);
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_128);
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_12C);
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_148);
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_14C);
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_150);
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_154);
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_158);
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_190);
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_160);
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_164);
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_168);
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_16C);
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_170);
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_174);
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_194);
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_198);
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_1A0);
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_1BC);
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_1C0);
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_1C4);
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_1C8);
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_1CC);
}
