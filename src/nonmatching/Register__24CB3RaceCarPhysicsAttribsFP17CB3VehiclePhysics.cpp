// NONMATCHING: Register__24CB3RaceCarPhysicsAttribsFP17CB3VehiclePhysics -- retail 1303 / ours 1210 instructions, 1913 in changed runs
// Structure exact (65 sprintf + 64 AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi in retail order, frame/stack buffers match). Left: MWCC CSEs each repeated dir-string address (&D_004BB900 etc.) into s1 across calls; retail rematerialises lui/addiu every time while still sharing 0.0f (mov.s f13,f12). #pragma opt_common_subs off gives 1303/1303 instrs but loses the mov.s (512 changed). String literals, char[] externs, volatile externs, inline helper, do/while(0) blocks, optimization_level 0-3 all tried.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

class CB3VehiclePhysics;
struct UnkStruct_00252C20_car {
    unsigned char pad_0[0x1960];
    unsigned long field_1960;
};

class CB3VehiclePhysics {
public:
    unsigned char pad_0[0x13F4];
    UnkStruct_00252C20_car * field_13F4;
};

struct UnkStruct_00252C20_s {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3RaceCarPhysicsAttribs {
public:
    void Register(CB3VehiclePhysics * p0);

    char field_0[0xB0];  // [G] the .cfg file name
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
extern UnkStruct_00252C20_s D_004BB8B0;  // string
extern UnkStruct_00252C20_s D_004BB8D8;  // string
extern UnkStruct_00252C20_s D_004BB8E0;  // string
extern UnkStruct_00252C20_s D_004BB8F0;  // string
extern UnkStruct_00252C20_s D_004BB900;  // string
extern UnkStruct_00252C20_s D_004BB920;  // string
extern UnkStruct_00252C20_s D_004BB930;  // string
extern UnkStruct_00252C20_s D_004BB940;  // string
extern UnkStruct_00252C20_s D_004BB950;  // string
extern UnkStruct_00252C20_s D_004BB960;  // string
extern UnkStruct_00252C20_s D_004BB980;  // string
extern UnkStruct_00252C20_s D_004BB9A0;  // string
extern UnkStruct_00252C20_s D_004BB9C0;  // string
extern UnkStruct_00252C20_s D_004BB9E0;  // string
extern UnkStruct_00252C20_s D_004BBA00;  // string
extern UnkStruct_00252C20_s D_004BBA20;  // string
extern UnkStruct_00252C20_s D_004BBA38;  // string
extern UnkStruct_00252C20_s D_004BBA48;  // string
extern UnkStruct_00252C20_s D_004BBA58;  // string
extern UnkStruct_00252C20_s D_004BBA68;  // string
extern UnkStruct_00252C20_s D_004BBA80;  // string
extern UnkStruct_00252C20_s D_004BBA98;  // string
extern UnkStruct_00252C20_s D_004BBAA8;  // string
extern UnkStruct_00252C20_s D_004BBAC0;  // string
extern UnkStruct_00252C20_s D_004BBAE0;  // string
extern UnkStruct_00252C20_s D_004BBAF8;  // string
extern UnkStruct_00252C20_s D_004BBB10;  // string
extern UnkStruct_00252C20_s D_004BBB30;  // string
extern UnkStruct_00252C20_s D_004BBB50;  // string
extern UnkStruct_00252C20_s D_004BBB70;  // string
extern UnkStruct_00252C20_s D_004BBB90;  // string
extern UnkStruct_00252C20_s D_004BBBB0;  // string
extern UnkStruct_00252C20_s D_004BBBC0;  // string
extern UnkStruct_00252C20_s D_004BBBE0;  // string
extern UnkStruct_00252C20_s D_004BBBF8;  // string
extern UnkStruct_00252C20_s D_004BBC08;  // string
extern UnkStruct_00252C20_s D_004BBC10;  // string
extern UnkStruct_00252C20_s D_004BBC20;  // string
extern UnkStruct_00252C20_s D_004BBC30;  // string
extern UnkStruct_00252C20_s D_004BBC58;  // string
extern UnkStruct_00252C20_s D_004BBC60;  // string
extern UnkStruct_00252C20_s D_004BBC68;  // string
extern UnkStruct_00252C20_s D_004BBC78;  // string
extern UnkStruct_00252C20_s D_004BBC88;  // string
extern UnkStruct_00252C20_s D_004BBC98;  // string
extern UnkStruct_00252C20_s D_004BBCA8;  // string
extern UnkStruct_00252C20_s D_004BBCB8;  // string
extern UnkStruct_00252C20_s D_004BBCC8;  // string
extern UnkStruct_00252C20_s D_004BBCE0;  // string
extern UnkStruct_00252C20_s D_004BBD00;  // string
extern UnkStruct_00252C20_s D_004BBD20;  // string
extern UnkStruct_00252C20_s D_004BBD30;  // string
extern UnkStruct_00252C20_s D_004BBD50;  // string
extern UnkStruct_00252C20_s D_004BBD70;  // string
extern UnkStruct_00252C20_s D_004BBD88;  // string
extern UnkStruct_00252C20_s D_004BBD98;  // string
extern UnkStruct_00252C20_s D_004BBDA8;  // string
extern UnkStruct_00252C20_s D_004BBDB8;  // string
extern UnkStruct_00252C20_s D_004BBDC8;  // string
extern UnkStruct_00252C20_s D_004BBDD8;  // string
extern UnkStruct_00252C20_s D_004BBDF0;  // string
extern UnkStruct_00252C20_s D_004BBE10;  // string
extern UnkStruct_00252C20_s D_004BBE30;  // string
extern UnkStruct_00252C20_s D_004BBE48;  // string
extern UnkStruct_00252C20_s D_004BBE60;  // string
extern UnkStruct_00252C20_s D_004BBE70;  // string
extern UnkStruct_00252C20_s D_004BBE90;  // string
extern UnkStruct_00252C20_s D_004BBEA0;  // string
extern UnkStruct_00252C20_s D_004BBED0;  // string
extern UnkStruct_00252C20_s D_004BBEF0;  // string
extern UnkStruct_00252C20_s D_004BBF10;  // string
extern UnkStruct_00252C20_s D_004BBF30;  // string
extern UnkStruct_00252C20_s D_004BBF50;  // string
extern "C" void AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(int, void *, void *, int, int, int, float, float, int);
extern "C" int sprintf(char *, const void *, ...);
extern "C" void func_0021AB40(unsigned long, char *);

// 0x00252C20
void CB3RaceCarPhysicsAttribs::Register(CB3VehiclePhysics * p0)
{
    char id[16];
    char path[128];
    func_0021AB40(p0->field_13F4->field_1960, id);
    sprintf(field_0, (void *)&D_004BB8B0, id);
    field_B0 = p0->field_13F4->field_1960;
    sprintf(path, &D_004BB8D8, id, &D_004BB8E0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_B8, &D_004BB8F0, (int)&D_004BB8E0, (int)field_0, 0, 0.0f, 0.0f, 0);
    sprintf(path, &D_004BB8D8, id, &D_004BB900);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_BC, &D_004BB920, (int)&D_004BB900, (int)field_0, 0, 0.0f, 0.0f, 0);
    sprintf(path, &D_004BB8D8, id, &D_004BB900);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_C8, &D_004BB930, (int)&D_004BB900, (int)field_0, 0, 0.0f, 0.0f, 0);
    sprintf(path, &D_004BB8D8, id, &D_004BB900);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_C0, &D_004BB940, (int)&D_004BB900, (int)field_0, 0, 0.0f, 0.0f, 0);
    sprintf(path, &D_004BB8D8, id, &D_004BB900);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_C4, &D_004BB950, (int)&D_004BB900, (int)field_0, 0, 0.0f, 0.0f, 0);
    sprintf(path, &D_004BB8D8, id, &D_004BB960);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_D8, &D_004BB920, (int)&D_004BB960, (int)field_0, 0, 0.0f, 0.0f, 0);
    sprintf(path, &D_004BB8D8, id, &D_004BB960);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_D4, &D_004BB930, (int)&D_004BB960, (int)field_0, 0, 0.0f, 0.0f, 0);
    sprintf(path, &D_004BB8D8, id, &D_004BB960);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_CC, &D_004BB940, (int)&D_004BB960, (int)field_0, 0, 0.0f, 0.0f, 0);
    sprintf(path, &D_004BB8D8, id, &D_004BB960);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_D0, &D_004BB950, (int)&D_004BB960, (int)field_0, 0, 0.0f, 0.0f, 0);
    sprintf(path, &D_004BB8D8, id, &D_004BB980);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_138, &D_004BB9A0, (int)&D_004BB980, (int)field_0, 0, 0.0f, 0.0f, 0);
    sprintf(path, &D_004BB8D8, id, &D_004BB980);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_13C, &D_004BB9C0, (int)&D_004BB980, (int)field_0, 0, 0.0f, 0.0f, 0);
    sprintf(path, &D_004BB8D8, id, &D_004BB980);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_140, &D_004BB9E0, (int)&D_004BB980, (int)field_0, 0, 0.0f, 0.0f, 0);
    sprintf(path, &D_004BB8D8, id, &D_004BB980);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_144, &D_004BBA00, (int)&D_004BB980, (int)field_0, 0, 0.0f, 0.0f, 0);
    sprintf(path, &D_004BB8D8, id, &D_004BBA20);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_17C, &D_004BBA38, (int)&D_004BBA20, (int)field_0, 0, 0.0f, 0.0f, 0);
    sprintf(path, &D_004BB8D8, id, &D_004BBA20);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_180, &D_004BBA48, (int)&D_004BBA20, (int)field_0, 0, 0.0f, 0.0f, 0);
    sprintf(path, &D_004BB8D8, id, &D_004BBA20);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_184, &D_004BBA58, (int)&D_004BBA20, (int)field_0, 0, 0.0f, 0.0f, 0);
    sprintf(path, &D_004BB8D8, id, &D_004BBA20);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_188, &D_004BBA68, (int)&D_004BBA20, (int)field_0, 0, 0.0f, 0.0f, 0);
    sprintf(path, &D_004BB8D8, id, &D_004BBA80);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_130, &D_004BBA98, (int)&D_004BBA80, (int)field_0, 0, 0.0f, 0.0f, 0);
    sprintf(path, &D_004BB8D8, id, &D_004BBA80);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_134, &D_004BBAA8, (int)&D_004BBA80, (int)field_0, 0, 0.0f, 0.0f, 0);
    sprintf(path, &D_004BB8D8, id, &D_004BBA80);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_178, &D_004BBAC0, (int)&D_004BBA80, (int)field_0, 0, 0.0f, 0.0f, 0);
    sprintf(path, &D_004BB8D8, id, &D_004BBA80);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_18C, &D_004BBAE0, (int)&D_004BBA80, (int)field_0, 0, 0.0f, 0.0f, 0);
    sprintf(path, &D_004BB8D8, id, &D_004BBA80);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_15C, &D_004BBAF8, (int)&D_004BBA80, (int)field_0, 0, 0.0f, 0.0f, 0);
    sprintf(path, &D_004BB8D8, id, &D_004BBA80);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_19C, &D_004BBB10, (int)&D_004BBA80, (int)field_0, 0, 0.0f, 0.0f, 0);
    sprintf(path, &D_004BB8D8, id, &D_004BBA80);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_1A4, &D_004BBB30, (int)&D_004BBA80, (int)field_0, 0, 0.0f, 0.0f, 0);
    sprintf(path, &D_004BB8D8, id, &D_004BBA80);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_1B4, &D_004BBB50, (int)&D_004BBA80, (int)field_0, 0, 0.0f, 0.0f, 0);
    sprintf(path, &D_004BB8D8, id, &D_004BBA80);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_1B0, &D_004BBB70, (int)&D_004BBA80, (int)field_0, 0, 0.0f, 0.0f, 0);
    sprintf(path, &D_004BB8D8, id, &D_004BBB90);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_11C, &D_004BBBB0, (int)&D_004BBB90, (int)field_0, 0, 0.0f, 0.0f, 0);
    sprintf(path, &D_004BB8D8, id, &D_004BBB90);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_120, &D_004BBBC0, (int)&D_004BBB90, (int)field_0, 0, 0.0f, 0.0f, 0);
    sprintf(path, &D_004BB8D8, id, &D_004BBB90);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_124, &D_004BBBE0, (int)&D_004BBB90, (int)field_0, 0, 0.0f, 0.0f, 0);
    sprintf(path, &D_004BB8D8, id, &D_004BBB90);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_104, &D_004BBBF8, (int)&D_004BBB90, (int)field_0, 0, 0.0f, 0.0f, 0);
    sprintf(path, &D_004BB8D8, id, &D_004BBB90);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_118, &D_004BBC08, (int)&D_004BBB90, (int)field_0, 0, 0.0f, 0.0f, 0);
    sprintf(path, &D_004BB8D8, id, &D_004BBB90);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_10C, &D_004BBC10, (int)&D_004BBB90, (int)field_0, 0, 0.0f, 0.0f, 0);
    sprintf(path, &D_004BB8D8, id, &D_004BBB90);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_108, &D_004BBC20, (int)&D_004BBB90, (int)field_0, 0, 0.0f, 0.0f, 0);
    sprintf(path, &D_004BB8D8, id, &D_004BBC30);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_E0, &D_004BBC58, (int)&D_004BBC30, (int)field_0, 0, 0.0f, 0.0f, 0);
    sprintf(path, &D_004BB8D8, id, &D_004BBC30);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_E4, &D_004BBC60, (int)&D_004BBC30, (int)field_0, 0, 0.0f, 0.0f, 0);
    sprintf(path, &D_004BB8D8, id, &D_004BBC30);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_E8, &D_004BBC68, (int)&D_004BBC30, (int)field_0, 0, 0.0f, 0.0f, 0);
    sprintf(path, &D_004BB8D8, id, &D_004BBC30);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_EC, &D_004BBC78, (int)&D_004BBC30, (int)field_0, 0, 0.0f, 0.0f, 0);
    sprintf(path, &D_004BB8D8, id, &D_004BBC30);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_F0, &D_004BBC88, (int)&D_004BBC30, (int)field_0, 0, 0.0f, 0.0f, 0);
    sprintf(path, &D_004BB8D8, id, &D_004BBC30);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_F4, &D_004BBC98, (int)&D_004BBC30, (int)field_0, 0, 0.0f, 0.0f, 0);
    sprintf(path, &D_004BB8D8, id, &D_004BBC30);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_F8, &D_004BBCA8, (int)&D_004BBC30, (int)field_0, 0, 0.0f, 0.0f, 0);
    sprintf(path, &D_004BB8D8, id, &D_004BBC30);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_FC, &D_004BBCB8, (int)&D_004BBC30, (int)field_0, 0, 0.0f, 0.0f, 0);
    sprintf(path, &D_004BB8D8, id, &D_004BBC30);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_100, &D_004BBCC8, (int)&D_004BBC30, (int)field_0, 0, 0.0f, 0.0f, 0);
    sprintf(path, &D_004BB8D8, id, &D_004BBCE0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_128, &D_004BBD00, (int)&D_004BBCE0, (int)field_0, 0, 0.0f, 0.0f, 0);
    sprintf(path, &D_004BB8D8, id, &D_004BBCE0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_12C, &D_004BBD20, (int)&D_004BBCE0, (int)field_0, 0, 0.0f, 0.0f, 0);
    sprintf(path, &D_004BB8D8, id, &D_004BBD30);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_148, &D_004BBD50, (int)&D_004BBD30, (int)field_0, 0, 0.0f, 0.0f, 0);
    sprintf(path, &D_004BB8D8, id, &D_004BBD30);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_14C, &D_004BBD70, (int)&D_004BBD30, (int)field_0, 0, 0.0f, 0.0f, 0);
    sprintf(path, &D_004BB8D8, id, &D_004BBD30);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_150, &D_004BBD88, (int)&D_004BBD30, (int)field_0, 0, 0.0f, 0.0f, 0);
    sprintf(path, &D_004BB8D8, id, &D_004BBD30);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_154, &D_004BBD98, (int)&D_004BBD30, (int)field_0, 0, 0.0f, 0.0f, 0);
    sprintf(path, &D_004BB8D8, id, &D_004BBD30);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_158, &D_004BBDA8, (int)&D_004BBD30, (int)field_0, 0, 0.0f, 0.0f, 0);
    sprintf(path, &D_004BB8D8, id, &D_004BBD30);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_190, &D_004BBA98, (int)&D_004BBD30, (int)field_0, 0, 0.0f, 0.0f, 0);
    sprintf(path, &D_004BB8D8, id, &D_004BBDB8);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_160, &D_004BBDC8, (int)&D_004BBDB8, (int)field_0, 0, 0.0f, 0.0f, 0);
    sprintf(path, &D_004BB8D8, id, &D_004BBDB8);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_164, &D_004BBDD8, (int)&D_004BBDB8, (int)field_0, 0, 0.0f, 0.0f, 0);
    sprintf(path, &D_004BB8D8, id, &D_004BBDB8);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_168, &D_004BBDF0, (int)&D_004BBDB8, (int)field_0, 0, 0.0f, 0.0f, 0);
    sprintf(path, &D_004BB8D8, id, &D_004BBDB8);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_16C, &D_004BBE10, (int)&D_004BBDB8, (int)field_0, 0, 0.0f, 0.0f, 0);
    sprintf(path, &D_004BB8D8, id, &D_004BBDB8);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_170, &D_004BBE30, (int)&D_004BBDB8, (int)field_0, 0, 0.0f, 0.0f, 0);
    sprintf(path, &D_004BB8D8, id, &D_004BBDB8);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_174, &D_004BBE48, (int)&D_004BBDB8, (int)field_0, 0, 0.0f, 0.0f, 0);
    sprintf(path, &D_004BB8D8, id, &D_004BBDB8);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_194, &D_004BBE60, (int)&D_004BBDB8, (int)field_0, 0, 0.0f, 0.0f, 0);
    sprintf(path, &D_004BB8D8, id, &D_004BBDB8);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_198, &D_004BBE70, (int)&D_004BBDB8, (int)field_0, 0, 0.0f, 0.0f, 0);
    sprintf(path, &D_004BB8D8, id, &D_004BBDB8);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_1A0, &D_004BBE90, (int)&D_004BBDB8, (int)field_0, 0, 0.0f, 0.0f, 0);
    sprintf(path, &D_004BB8D8, id, &D_004BBEA0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_1BC, &D_004BBED0, (int)&D_004BBEA0, (int)field_0, 0, 0.0f, 0.0f, 0);
    sprintf(path, &D_004BB8D8, id, &D_004BBEA0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_1C0, &D_004BBEF0, (int)&D_004BBEA0, (int)field_0, 0, 0.0f, 0.0f, 0);
    sprintf(path, &D_004BB8D8, id, &D_004BBEA0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_1C4, &D_004BBF10, (int)&D_004BBEA0, (int)field_0, 0, 0.0f, 0.0f, 0);
    sprintf(path, &D_004BB8D8, id, &D_004BBEA0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_1C8, &D_004BBF30, (int)&D_004BBEA0, (int)field_0, 0, 0.0f, 0.0f, 0);
    sprintf(path, &D_004BB8D8, id, &D_004BBEA0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_1CC, &D_004BBF50, (int)&D_004BBEA0, (int)field_0, 0, 0.0f, 0.0f, 0);
}
