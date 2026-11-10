// CB3OnlineRoadRageRaceLogic::OnTakedown(CB3RaceCar*,CB3RaceCar*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3OnlineRoadRageRaceLogic.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (a70: D_0064D3B0 typed CB3RaceCar, &D in const local).

// CB3OnlineRoadRageRaceLogic::OnTakedown(CB3RaceCar*,CB3RaceCar*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3OnlineRoadRageRaceLogic.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3RaceCar;

class CB3OnlineRoadRageRaceLogic;
struct CB3RaceCar;
struct UnkStruct_0038EDF0_3;
struct UnkStruct_D_0064D3B0;

struct CB3RaceCar {
    unsigned char pad_0[0x1160];
    unsigned char field_1160;
};

struct UnkStruct_0038EDF0_3 {
    unsigned char pad_0[0x7C];
    int field_7C;
};

struct UnkStruct_D_0064D3B0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3OnlineRoadRageRaceLogic {
public:
    void OnTakedown(CB3RaceCar* p0, CB3RaceCar* p1);

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
    virtual void vfunc_34();
    virtual void vfunc_38();
    virtual void vfunc_3C();
    virtual void vfunc_40();
    virtual void vfunc_44();
    virtual void vfunc_48();
    virtual void vfunc_4C();
    virtual void vfunc_50();
    virtual void vfunc_54();
    virtual void vfunc_58();
    virtual void vfunc_5C();
    virtual void vfunc_60();
    virtual void vfunc_64();
    virtual void vfunc_68();
    virtual void vfunc_6C();
    virtual void vfunc_70();
    virtual void vfunc_74();
    virtual void vfunc_78();
    virtual void vfunc_7C(void *);
    virtual void vfunc_80();
    virtual void vfunc_84();
    virtual void vfunc_88();
    virtual void vfunc_8C();
    virtual void vfunc_90();
    virtual void vfunc_94();
    virtual void vfunc_98();
    virtual void vfunc_9C();
    virtual void vfunc_A0();
    virtual void vfunc_A4();
    virtual void vfunc_A8();
    virtual void vfunc_AC();
    virtual void vfunc_B0();
    virtual void vfunc_B4();
    virtual void vfunc_B8();
    virtual void vfunc_BC();
    virtual void vfunc_C0();
    virtual void vfunc_C4();
    virtual void vfunc_C8();
    virtual void vfunc_CC();
    virtual void vfunc_D0();
    virtual void vfunc_D4();
    virtual void vfunc_D8();
    virtual void vfunc_DC();
    virtual void vfunc_E0();
    virtual void vfunc_E4();
    virtual void vfunc_E8();
    virtual void vfunc_EC();
    virtual void vfunc_F0();
    virtual void vfunc_F4();
    virtual void vfunc_F8();
    virtual void vfunc_FC();
    virtual void vfunc_100();
    virtual void vfunc_104();
    virtual void vfunc_108(CB3RaceCar *, CB3RaceCar *, int);
};

extern CB3RaceCar D_0064D3B0;

extern "C" void DecrementHealth__8CB3ScoreFf(void *, float);  // CB3Score::DecrementHealth(float)
extern "C" void AddScore__8CB3ScoreFii(void *, int, int, int);  // CB3Score::AddScore(int,int), passed 1 more argument(s) [G]
extern "C" void OnTakedown__19CB3OnlineStageLogicFP10CB3RaceCarP10CB3RaceCar(void *, void *, void *);  // CB3OnlineStageLogic::OnTakedown(CB3RaceCar*,CB3RaceCar*)

// 0x0038EDF0
void CB3OnlineRoadRageRaceLogic::OnTakedown(CB3RaceCar* p0, CB3RaceCar* p1)
{
    CB3RaceCar * const pd = &D_0064D3B0;
    if (p0 == pd) {
        if (p0->field_1160 != 0) {
        } else {
            if (p1->field_1160 == 0) {
            } else {
                DecrementHealth__8CB3ScoreFf(((char *)p0 + 0x10C0), 1.0f);
                vfunc_108(p0, p1, 7);
                vfunc_7C(pd);
            }
        }
    }
    if (p0->field_1160 == 0) {
        if (p1->field_1160 != 0) {
            AddScore__8CB3ScoreFii(((char *)p1 + 0x10C0), 2000, -1, 0);
        }
    }
    OnTakedown__19CB3OnlineStageLogicFP10CB3RaceCarP10CB3RaceCar(this, (CB3RaceCar*)p0, (CB3RaceCar*)p1);
}
