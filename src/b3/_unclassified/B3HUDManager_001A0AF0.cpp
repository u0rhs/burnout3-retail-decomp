// CB3HUDManager::PrepareNormalComponents() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3HUDManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (hand-written from asm: switch w/ fallthrough chains; first try).

// a159: CB3HUDManager::PrepareNormalComponents
enum EHUDAlign {};
struct UnkStruct_PNC_big { unsigned char pad_0[0x10]; };
struct UnkStruct_PNC_flag { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_PNC_self { unsigned char pad_0[0x174]; int field_174; };
extern UnkStruct_PNC_big D_0066B550, _gScoreComponentP1, _gSpeedoComponentP1, _gPosComponentP1, _gBoostBarComponentP1, _gLapComponentP1;
extern UnkStruct_PNC_big _gCrashHeading, _gTakedownsComponentP1, _gTimerComponentP1, _gScoreListComponentP1, _gLapTimerComponentP1;
extern UnkStruct_PNC_big _gBoostBarComponentP2, _gSpeedoComponentP2, _gScoreComponentP2, D_0066B6F0, D_0066B750, D_0066C000, D_004EE040;
extern UnkStruct_PNC_flag D_0064D378;
extern "C" int func_00435AB0(void *, int, int, int);
extern "C" void Prepare__11CB3HUDScoreFi9EHUDAlignii(void *, int, EHUDAlign, int, int);
extern "C" int func_001A3C70(void *, int, int, int);
extern "C" int func_00335AB0(void *, int, int, int, int, int, int);
extern "C" bool Prepare__14CB3HUDBoostBarFi9EHUDAlignibPC13CB3HUDHeading(void *, int, EHUDAlign, int, bool, bool, const void *);
extern "C" int func_00335450(void *, int, int, int, int);
extern "C" void Prepare__15CB3HUDTakedownsFi9EHUDAlignibb(void *, int, EHUDAlign, int, bool, bool);
extern "C" int func_00131CE0(void *);
extern "C" int Prepare__11CB3HUDTimerFi9EHUDAligni(void *, int, EHUDAlign, int, int);
extern "C" void Prepare__15CB3HUDScoreListF9EHUDAligni(void *, EHUDAlign, int);
extern "C" int func_00394870(void *, int, int, int, int, int);

#define BOOST(p, a, b, c, d, e) Prepare__14CB3HUDBoostBarFi9EHUDAlignibPC13CB3HUDHeading(&_gBoostBarComponent##p, a, (EHUDAlign)b, c, d, e, &_gCrashHeading)

extern "C" void PrepareNormalComponents__13CB3HUDManagerFv(UnkStruct_PNC_self * self)
{
    switch (self->field_174) {
    case 3:
        func_00435AB0(&D_0066B550, 0, 5, 1);
    case 1:
        Prepare__11CB3HUDScoreFi9EHUDAlignii(&_gScoreComponentP1, 0, (EHUDAlign)0, 1, 0xEF);
        func_001A3C70(&_gSpeedoComponentP1, 0, 5, 1);
        func_00335AB0(&_gPosComponentP1, 0, 1, 1, 0, 0, 0);
        BOOST(P1, 0, 3, 1, 1, 0);
        if (D_0064D378.field_0 == 0) func_00335450(&_gLapComponentP1, 0, 7, 1, 0);
        break;
    case 6:
        Prepare__11CB3HUDScoreFi9EHUDAlignii(&_gScoreComponentP1, 0, (EHUDAlign)0, 1, 0xEF);
        func_001A3C70(&_gSpeedoComponentP1, 0, 5, 1);
        func_00335AB0(&_gPosComponentP1, 0, 1, 1, 1, 0, 0);
        func_00335450(&_gLapComponentP1, 0, 7, 1, 0);
        BOOST(P1, 0, 3, 1, 1, 0);
        break;
    case 7:
        Prepare__11CB3HUDScoreFi9EHUDAlignii(&_gScoreComponentP1, 0, (EHUDAlign)0, 1, 1);
        func_001A3C70(&_gSpeedoComponentP1, 0, 5, 1);
        Prepare__15CB3HUDTakedownsFi9EHUDAlignibb(&_gTakedownsComponentP1, 0, (EHUDAlign)1, 1, 1, 0);
        BOOST(P1, 0, 3, 1, 1, 0);
        if (func_00131CE0(&D_004EE040) != 0) Prepare__11CB3HUDTimerFi9EHUDAligni(&_gTimerComponentP1, 0, (EHUDAlign)7, 1, 0);
        break;
    case 9:
        Prepare__11CB3HUDScoreFi9EHUDAlignii(&_gScoreComponentP1, 0, (EHUDAlign)0, 1, 0);
        Prepare__15CB3HUDScoreListF9EHUDAligni(&_gScoreListComponentP1, (EHUDAlign)1, 1);
        BOOST(P1, 0, 3, 1, 1, 0);
        func_001A3C70(&_gSpeedoComponentP1, 0, 5, 1);
        func_00435AB0(&D_0066B550, 0, 5, 1);
        break;
    case 4:
    case 5:
        BOOST(P1, 0, 3, 1, 1, 0);
        func_001A3C70(&_gSpeedoComponentP1, 0, 5, 1);
        func_00394870(&_gLapTimerComponentP1, 0, 1, 1, 1, func_00131CE0(&D_004EE040));
        if (self->field_174 == 4) {
            Prepare__11CB3HUDScoreFi9EHUDAlignii(&_gScoreComponentP1, 0, (EHUDAlign)0, 1, 0xEF);
            func_00335450(&_gLapComponentP1, 0, 7, 1, 0);
        } else {
            Prepare__11CB3HUDScoreFi9EHUDAlignii(&_gScoreComponentP1, 0, (EHUDAlign)0, 1, 0xEF);
        }
        break;
    case 11:
    case 13:
    case 15:
        func_00435AB0(&D_0066B550, 0, 5, 1);
    case 10:
    case 12:
        BOOST(P1, 0, 3, 1, 0, 0);
        func_001A3C70(&_gSpeedoComponentP1, 0, 5, 1);
        break;
    case 14:
        BOOST(P1, 0, 3, 1, 0, 1);
        func_001A3C70(&_gSpeedoComponentP1, 0, 5, 1);
        BOOST(P2, 1, 3, 1, 0, 1);
        func_001A3C70(&_gSpeedoComponentP2, 1, 5, 1);
        break;
    case 2:
        Prepare__11CB3HUDScoreFi9EHUDAlignii(&_gScoreComponentP1, 0, (EHUDAlign)0, 1, 0x1E);
        BOOST(P1, 0, 3, 1, 0, 1);
        func_001A3C70(&_gSpeedoComponentP1, 0, 5, 1);
        func_00335AB0(&_gPosComponentP1, 0, 1, 1, 0, 0, 1);
        if (D_0064D378.field_0 == 0) func_00335450(&_gLapComponentP1, 0, 7, 1, 1);
        Prepare__11CB3HUDScoreFi9EHUDAlignii(&_gScoreComponentP2, 1, (EHUDAlign)0, 1, 0x1E);
        BOOST(P2, 1, 3, 1, 0, 1);
        func_001A3C70(&_gSpeedoComponentP2, 1, 5, 1);
        func_00335AB0(&D_0066B6F0, 1, 1, 1, 0, 0, 1);
        if (D_0064D378.field_0 == 0) func_00335450(&D_0066B750, 1, 7, 1, 1);
        break;
    case 8:
        Prepare__11CB3HUDScoreFi9EHUDAlignii(&_gScoreComponentP1, 0, (EHUDAlign)0, 1, 0x10);
        BOOST(P1, 0, 3, 1, 0, 1);
        func_001A3C70(&_gSpeedoComponentP1, 0, 5, 1);
        Prepare__15CB3HUDTakedownsFi9EHUDAlignibb(&_gTakedownsComponentP1, 0, (EHUDAlign)1, 1, 0, 0);
        Prepare__11CB3HUDScoreFi9EHUDAlignii(&_gScoreComponentP2, 1, (EHUDAlign)0, 1, 0x10);
        BOOST(P2, 1, 3, 1, 0, 1);
        func_001A3C70(&_gSpeedoComponentP2, 1, 5, 1);
        Prepare__15CB3HUDTakedownsFi9EHUDAlignibb(&D_0066C000, 1, (EHUDAlign)1, 1, 0, 0);
        break;
    }
}
