// CB3Score::RegisterStaticVariables() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3Score.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (draftW: vdb table generated from retail call list; Float count is the last param).

// Hand-written; the lifter refused it (CB3Score::RegisterStaticVariables: 51 AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi + 31 AddEntry__Q27GtComms16CGtCommsDatabaseFPiPCcPCcPCciiii calls, generated
// from the retail call list (build/vt/draftW/seg.py, gen1.py); mirror of UnregisterStaticVariables__8CB3ScoreFv (func_0015CB10)).
// [C] AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi's count is its LAST parameter (t2 after f12/f13), as in the matched CB3Burn::RegisterStaticVariables
// (func_0014E670): with (.., int, int, float, float) MWCC schedules move t2 before mov.s f13 (42 sites differ).
class CB3Score {
public:
    static int gmanAirBP[4];  // [G] type from the prefix; array size from the symbol table
    static int gmanBestRacePositionBP[5];  // [G] type from the prefix; array size from the symbol table
    static int gmanDoubleRevengeTakedownBP[2];  // [G] type from the prefix; array size from the symbol table
    static int gmanDoubleTakedownBP[4];  // [G] type from the prefix; array size from the symbol table
    static int gmanDriftBP[4];  // [G] type from the prefix; array size from the symbol table
    static int gmanGrindingBP[3];  // [G] type from the prefix; array size from the symbol table
    static int gmanNearMissBP[4];  // [G] type from the prefix; array size from the symbol table
    static int gmanOncomingBP[4];  // [G] type from the prefix; array size from the symbol table
    static int gmanRoadRageTakedownBP[8];  // [G] type from the prefix; array size from the symbol table
    static int gmanRubbingBP[3];  // [G] type from the prefix; array size from the symbol table
    static int gmanSlamBP[4];  // [G] type from the prefix; array size from the symbol table
    static int gmanSpreeTakedownBP[4];  // [G] type from the prefix; array size from the symbol table
    static int gmanSuperSlamBP[4];  // [G] type from the prefix; array size from the symbol table
    static int gmanTailgateBP[3];  // [G] type from the prefix; array size from the symbol table
    static float gmarDistanceTravelledMedals[3];  // [G] type from the prefix; array size from the symbol table
    static float gmarMinAir[4];  // [G] type from the prefix; array size from the symbol table
    static float gmarMinDrift[4];  // [G] type from the prefix; array size from the symbol table
    static float gmarMinGrinding[3];  // [G] type from the prefix; array size from the symbol table
    static float gmarMinNearMiss[4];  // [G] type from the prefix; array size from the symbol table
    static float gmarMinOncoming[4];  // [G] type from the prefix; array size from the symbol table
    static float gmarMinRubbing[3];  // [G] type from the prefix; array size from the symbol table
    static float gmarMinTailgate[3];  // [G] type from the prefix; array size from the symbol table
    static int gmnAftertouchTakedownBP;  // [G] type from the prefix; array size from the symbol table
    static int gmnBoostStartBP;  // [G] type from the prefix; array size from the symbol table
    static int gmnBurningSlamExtraBP;  // [G] type from the prefix; array size from the symbol table
    static int gmnBurnoutLapBP;  // [G] type from the prefix; array size from the symbol table
    static int gmnCrashEscapeBP;  // [G] type from the prefix; array size from the symbol table
    static int gmnDeniedBP;  // [G] type from the prefix; array size from the symbol table
    static int gmnLedLapBP;  // [G] type from the prefix; array size from the symbol table
    static int gmnNearMissBP;  // [G] type from the prefix; array size from the symbol table
    static int gmnNoMercyBP;  // [G] type from the prefix; array size from the symbol table
    static int gmnPerfectLapBP;  // [G] type from the prefix; array size from the symbol table
    static int gmnPropHitBP;  // [G] type from the prefix; array size from the symbol table
    static int gmnPsycheOutBP;  // [G] type from the prefix; array size from the symbol table
    static int gmnRevengeBP;  // [G] type from the prefix; array size from the symbol table
    static int gmnRubbingBP;  // [G] type from the prefix; array size from the symbol table
    static int gmnTakedownBP;  // [G] type from the prefix; array size from the symbol table
    static int gmnTradingPaintBP;  // [G] type from the prefix; array size from the symbol table
    static int gmnYouWereLuckyBP;  // [G] type from the prefix; array size from the symbol table
    static float gmrAirDistanceBurnValue;  // [G] type from the prefix; array size from the symbol table
    static float gmrAirMinimumDistanceValue;  // [G] type from the prefix; array size from the symbol table
    static float gmrBoostStartBurnValue;  // [G] type from the prefix; array size from the symbol table
    static float gmrBurnRatioLostInCrash;  // [G] type from the prefix; array size from the symbol table
    static float gmrBurnoutLapBurnValue;  // [G] type from the prefix; array size from the symbol table
    static float gmrCrashEscapeBurnValue;  // [G] type from the prefix; array size from the symbol table
    static float gmrCrashEscapeMinClearTime;  // [G] type from the prefix; array size from the symbol table
    static float gmrCrashEscapeMinimumSpeed;  // [G] type from the prefix; array size from the symbol table
    static float gmrCrashEscapeRadius;  // [G] type from the prefix; array size from the symbol table
    static float gmrCrashNearMissChainTime;  // [G] type from the prefix; array size from the symbol table
    static float gmrDoubleRevengeTakedownTime;  // [G] type from the prefix; array size from the symbol table
    static float gmrDoubleTakedownTime;  // [G] type from the prefix; array size from the symbol table
    static float gmrDriftDistanceBurnValue;  // [G] type from the prefix; array size from the symbol table
    static float gmrDriftMinimumDistanceValue;  // [G] type from the prefix; array size from the symbol table
    static float gmrDriftMinimumSpeed;  // [G] type from the prefix; array size from the symbol table
    static float gmrGrindingExtraBurnValue;  // [G] type from the prefix; array size from the symbol table
    static float gmrGrindingMinTime;  // [G] type from the prefix; array size from the symbol table
    static float gmrMaxNearMissDistance;  // [G] type from the prefix; array size from the symbol table
    static float gmrMaxSlamBurnValue;  // [G] type from the prefix; array size from the symbol table
    static float gmrNearMissBurnValue;  // [G] type from the prefix; array size from the symbol table
    static float gmrNearMissChainTime;  // [G] type from the prefix; array size from the symbol table
    static float gmrNearMissMinimumChainSpeed;  // [G] type from the prefix; array size from the symbol table
    static float gmrNearMissMinimumSpeed;  // [G] type from the prefix; array size from the symbol table
    static float gmrOncomingDistanceBurnValue;  // [G] type from the prefix; array size from the symbol table
    static float gmrOncomingMinimumDistanceValue;  // [G] type from the prefix; array size from the symbol table
    static float gmrOncomingMinimumSpeed;  // [G] type from the prefix; array size from the symbol table
    static float gmrPerfectLapBurnValue;  // [G] type from the prefix; array size from the symbol table
    static float gmrPropHitBurnValue;  // [G] type from the prefix; array size from the symbol table
    static float gmrPropHitChainTime;  // [G] type from the prefix; array size from the symbol table
    static float gmrRubbingBurnValue;  // [G] type from the prefix; array size from the symbol table
    static float gmrRubbingMinTime;  // [G] type from the prefix; array size from the symbol table
    static float gmrSpreeTakedownTime;  // [G] type from the prefix; array size from the symbol table
    static float gmrTailgateConeAngle;  // [G] type from the prefix; array size from the symbol table
    static float gmrTailgateExtraBurnValue;  // [G] type from the prefix; array size from the symbol table
    static float gmrTailgateInitialTime;  // [G] type from the prefix; array size from the symbol table
    static float gmrTailgateMaxDistance;  // [G] type from the prefix; array size from the symbol table
    static float gmrTailgatePsycheOutDistance;  // [G] type from the prefix; array size from the symbol table
    static float gmrTakedownBurnValue;  // [G] type from the prefix; array size from the symbol table
    static float gmrTakedownCollideTimeNoSlam;  // [G] type from the prefix; array size from the symbol table
    static float gmrTakedownCrashTime;  // [G] type from the prefix; array size from the symbol table
    static float gmrTakedownCrashTimeNoSlam;  // [G] type from the prefix; array size from the symbol table
    static float gmrTakedownWaitTime;  // [G] type from the prefix; array size from the symbol table
    static float gmrTradingPaintBurnValue;  // [G] type from the prefix; array size from the symbol table
};

extern int mpToolBase__Q27GtComms16CGtCommsToolBase;
extern char D_004B6310[];
extern char D_004B6330[];
extern char D_004B6340[];
extern char D_004B6370[];
extern char D_004B6390[];
extern char D_004B63B0[];
extern char D_004B63E0[];
extern char D_004B6410[];
extern char D_004B6430[];
extern char D_004B6450[];
extern char D_004B6470[];
extern char D_004B64A0[];
extern char D_004B64C0[];
extern char D_004B64E0[];
extern char D_004B6500[];
extern char D_004B6530[];
extern char D_004B6560[];
extern char D_004B6580[];
extern char D_004B65A0[];
extern char D_004B65C0[];
extern char D_004B65F0[];
extern char D_004B6620[];
extern char D_004B6650[];
extern char D_004B6680[];
extern char D_004B66C0[];
extern char D_004B66E0[];
extern char D_004B6710[];
extern char D_004B6740[];
extern char D_004B6770[];
extern char D_004B67A0[];
extern char D_004B67C0[];
extern char D_004B67F0[];
extern char D_004B6810[];
extern char D_004B6840[];
extern char D_004B6870[];
extern char D_004B68B0[];
extern char D_004B68E0[];
extern char D_004B6920[];
extern char D_004B6960[];
extern char D_004B69A0[];
extern char D_004B69C0[];
extern char D_004B69E0[];
extern char D_004B6A10[];
extern char D_004B6A40[];
extern char D_004B6A50[];
extern char D_004B6A80[];
extern char D_004B6AA0[];
extern char D_004B6AB8[];
extern char D_004B6AD0[];
extern char D_004B6AE8[];
extern char D_004B6B00[];
extern char D_004B6B18[];
extern char D_004B6B30[];
extern char D_004B6B40[];
extern char D_004B6B58[];
extern char D_004B6B68[];
extern char D_004B6B80[];
extern char D_004B6BA0[];
extern char D_004B6BB0[];
extern char D_004B6BC8[];
extern char D_004B6BE0[];
extern char D_004B6C00[];
extern char D_004B6C20[];
extern char D_004B6C30[];
extern char D_004B6C40[];
extern char D_004B6C60[];
extern char D_004B6C70[];
extern char D_004B6C80[];
extern char D_004B6CA0[];
extern char D_004B6CC0[];
extern char D_004B6CE0[];
extern char D_004B6D00[];
extern char D_004B6D20[];
extern char D_004B6D40[];
extern char D_004B6D60[];
extern char D_004B6D80[];
extern char D_004B6DA0[];
extern char D_004B6DC0[];
extern char D_004B6DE0[];
extern char D_004B6E00[];
extern char D_004B6E20[];
extern char D_004B6E40[];
extern char D_004B6E70[];
extern char D_004B6E90[];
extern char D_004B6EC0[];
extern char D_004B6EF0[];
extern char D_004B6F20[];
extern char D_004B6F50[];
extern char D_004B6F80[];
extern char D_004B6FA0[];
extern char D_004B6FE0[];
extern char D_004B7010[];
extern char D_004B7030[];
extern char D_004B7070[];
extern char D_004B70A0[];
extern char D_004B70B0[];
extern char D_004B70E0[];
extern char gacScoreFileName[];
extern "C" void AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(int, void *, const char *, const char *, const char *, int, float, float, int);
extern "C" void AddEntry__Q27GtComms16CGtCommsDatabaseFPiPCcPCcPCciiii(int, void *, const char *, const char *, const char *, int, int, int, int);

// 0x0015D0A0
extern "C" void RegisterStaticVariables__8CB3ScoreFv()
{
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &CB3Score::gmrAirMinimumDistanceValue, D_004B6310, D_004B6330, gacScoreFileName, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &CB3Score::gmrAirDistanceBurnValue, D_004B6340, D_004B6330, gacScoreFileName, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &CB3Score::gmrOncomingMinimumSpeed, D_004B6370, D_004B6390, gacScoreFileName, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &CB3Score::gmrOncomingMinimumDistanceValue, D_004B63B0, D_004B6390, gacScoreFileName, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &CB3Score::gmrOncomingDistanceBurnValue, D_004B63E0, D_004B6390, gacScoreFileName, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &CB3Score::gmrDriftMinimumSpeed, D_004B6410, D_004B6430, gacScoreFileName, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &CB3Score::gmrDriftMinimumDistanceValue, D_004B6450, D_004B6430, gacScoreFileName, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &CB3Score::gmrDriftDistanceBurnValue, D_004B6470, D_004B6430, gacScoreFileName, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &CB3Score::gmrMaxNearMissDistance, D_004B64A0, D_004B64C0, gacScoreFileName, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &CB3Score::gmrNearMissMinimumSpeed, D_004B64E0, D_004B64C0, gacScoreFileName, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &CB3Score::gmrNearMissMinimumChainSpeed, D_004B6500, D_004B64C0, gacScoreFileName, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &CB3Score::gmrNearMissBurnValue, D_004B6530, D_004B64C0, gacScoreFileName, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &CB3Score::gmrNearMissChainTime, D_004B6560, D_004B64C0, gacScoreFileName, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &CB3Score::gmrCrashEscapeRadius, D_004B6580, D_004B65A0, gacScoreFileName, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &CB3Score::gmrCrashNearMissChainTime, D_004B65C0, D_004B65A0, gacScoreFileName, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &CB3Score::gmrCrashEscapeMinClearTime, D_004B65F0, D_004B65A0, gacScoreFileName, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &CB3Score::gmrCrashEscapeMinimumSpeed, D_004B6620, D_004B65A0, gacScoreFileName, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &CB3Score::gmrCrashEscapeBurnValue, D_004B6650, D_004B65A0, gacScoreFileName, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &CB3Score::gmrMaxSlamBurnValue, D_004B6680, D_004B66C0, gacScoreFileName, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &CB3Score::gmrRubbingBurnValue, D_004B66E0, D_004B66C0, gacScoreFileName, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &CB3Score::gmrRubbingMinTime, D_004B6710, D_004B66C0, gacScoreFileName, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &CB3Score::gmrTradingPaintBurnValue, D_004B6740, D_004B66C0, gacScoreFileName, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &CB3Score::gmrBoostStartBurnValue, D_004B6770, D_004B67A0, gacScoreFileName, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &CB3Score::gmrTakedownBurnValue, D_004B67C0, D_004B67F0, gacScoreFileName, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &CB3Score::gmrTakedownCrashTime, D_004B6810, D_004B67F0, gacScoreFileName, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &CB3Score::gmrTakedownCrashTimeNoSlam, D_004B6840, D_004B67F0, gacScoreFileName, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &CB3Score::gmrTakedownCollideTimeNoSlam, D_004B6870, D_004B67F0, gacScoreFileName, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &CB3Score::gmrTakedownWaitTime, D_004B68B0, D_004B67F0, gacScoreFileName, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &CB3Score::gmrDoubleTakedownTime, D_004B68E0, D_004B67F0, gacScoreFileName, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &CB3Score::gmrSpreeTakedownTime, D_004B6920, D_004B67F0, gacScoreFileName, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &CB3Score::gmrDoubleRevengeTakedownTime, D_004B6960, D_004B67F0, gacScoreFileName, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &CB3Score::gmrPropHitChainTime, D_004B69A0, D_004B69C0, gacScoreFileName, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &CB3Score::gmrPropHitBurnValue, D_004B69E0, D_004B69C0, gacScoreFileName, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &CB3Score::gmrPerfectLapBurnValue, D_004B6A10, D_004B6A40, gacScoreFileName, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &CB3Score::gmrBurnoutLapBurnValue, D_004B6A50, D_004B6A40, gacScoreFileName, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &CB3Score::gmrBurnRatioLostInCrash, D_004B6A80, D_004B6AA0, gacScoreFileName, 2, 0.0f, 1.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPiPCcPCcPCciiii(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &CB3Score::gmnPropHitBP, D_004B6AB8, D_004B6AD0, gacScoreFileName, 0, 0, 0, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPiPCcPCcPCciiii(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &CB3Score::gmnRubbingBP, D_004B6AE8, D_004B6AD0, gacScoreFileName, 0, 0, 0, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPiPCcPCcPCciiii(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &CB3Score::gmnTradingPaintBP, D_004B6B00, D_004B6AD0, gacScoreFileName, 0, 0, 0, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPiPCcPCcPCciiii(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &CB3Score::gmnBoostStartBP, D_004B6B18, D_004B6AD0, gacScoreFileName, 0, 0, 0, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPiPCcPCcPCciiii(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &CB3Score::gmnCrashEscapeBP, D_004B6B30, D_004B6AD0, gacScoreFileName, 0, 0, 0, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPiPCcPCcPCciiii(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &CB3Score::gmnBurningSlamExtraBP, D_004B6B40, D_004B6AD0, gacScoreFileName, 0, 0, 0, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPiPCcPCcPCciiii(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &CB3Score::gmnPerfectLapBP, D_004B6B58, D_004B6AD0, gacScoreFileName, 0, 0, 0, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPiPCcPCcPCciiii(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &CB3Score::gmnTakedownBP, D_004B6B68, D_004B6AD0, gacScoreFileName, 0, 0, 0, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPiPCcPCcPCciiii(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &CB3Score::gmnRevengeBP, D_004B6B80, D_004B6AD0, gacScoreFileName, 0, 0, 0, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPiPCcPCcPCciiii(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &CB3Score::gmnPsycheOutBP, D_004B6BA0, D_004B6AD0, gacScoreFileName, 0, 0, 0, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPiPCcPCcPCciiii(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &CB3Score::gmnAftertouchTakedownBP, D_004B6BB0, D_004B6AD0, gacScoreFileName, 0, 0, 0, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPiPCcPCcPCciiii(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &CB3Score::gmnNoMercyBP, D_004B6BC8, D_004B6AD0, gacScoreFileName, 0, 0, 0, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPiPCcPCcPCciiii(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &CB3Score::gmnYouWereLuckyBP, D_004B6BE0, D_004B6AD0, gacScoreFileName, 0, 0, 0, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPiPCcPCcPCciiii(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &CB3Score::gmnDeniedBP, D_004B6C00, D_004B6AD0, gacScoreFileName, 0, 0, 0, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPiPCcPCcPCciiii(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &CB3Score::gmnBurnoutLapBP, D_004B6C20, D_004B6AD0, gacScoreFileName, 0, 0, 0, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPiPCcPCcPCciiii(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &CB3Score::gmnNearMissBP, D_004B6C30, D_004B6AD0, gacScoreFileName, 0, 0, 0, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPiPCcPCcPCciiii(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &CB3Score::gmnLedLapBP, D_004B6C40, D_004B6AD0, gacScoreFileName, 0, 0, 0, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPiPCcPCcPCciiii(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, CB3Score::gmanAirBP, D_004B6C60, D_004B6AD0, gacScoreFileName, 0, 0, 0, 4);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPiPCcPCcPCciiii(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, CB3Score::gmanSlamBP, D_004B6C70, D_004B6AD0, gacScoreFileName, 0, 0, 0, 4);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPiPCcPCcPCciiii(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, CB3Score::gmanSuperSlamBP, D_004B6C80, D_004B6AD0, gacScoreFileName, 0, 0, 0, 4);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPiPCcPCcPCciiii(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, CB3Score::gmanOncomingBP, D_004B6CA0, D_004B6AD0, gacScoreFileName, 0, 0, 0, 4);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPiPCcPCcPCciiii(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, CB3Score::gmanDriftBP, D_004B6CC0, D_004B6AD0, gacScoreFileName, 0, 0, 0, 4);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPiPCcPCcPCciiii(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, CB3Score::gmanTailgateBP, D_004B6CE0, D_004B6AD0, gacScoreFileName, 0, 0, 0, 3);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPiPCcPCcPCciiii(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, CB3Score::gmanRubbingBP, D_004B6D00, D_004B6AD0, gacScoreFileName, 0, 0, 0, 3);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPiPCcPCcPCciiii(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, CB3Score::gmanGrindingBP, D_004B6D20, D_004B6AD0, gacScoreFileName, 0, 0, 0, 3);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPiPCcPCcPCciiii(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, CB3Score::gmanNearMissBP, D_004B6D40, D_004B6AD0, gacScoreFileName, 0, 0, 0, 4);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPiPCcPCcPCciiii(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, CB3Score::gmanBestRacePositionBP, D_004B6D60, D_004B6AD0, gacScoreFileName, 0, 0, 0, 5);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPiPCcPCcPCciiii(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, CB3Score::gmanDoubleTakedownBP, D_004B6D80, D_004B6AD0, gacScoreFileName, 0, 0, 0, 4);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPiPCcPCcPCciiii(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, CB3Score::gmanSpreeTakedownBP, D_004B6DA0, D_004B6AD0, gacScoreFileName, 0, 0, 0, 4);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPiPCcPCcPCciiii(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, CB3Score::gmanDoubleRevengeTakedownBP, D_004B6DC0, D_004B6AD0, gacScoreFileName, 0, 0, 0, 2);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPiPCcPCcPCciiii(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, CB3Score::gmanRoadRageTakedownBP, D_004B6DE0, D_004B6AD0, gacScoreFileName, 0, 0, 0, 8);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, CB3Score::gmarMinAir, D_004B6E00, D_004B6E20, gacScoreFileName, 0, 0.0f, 0.0f, 4);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, CB3Score::gmarMinOncoming, D_004B6E40, D_004B6E20, gacScoreFileName, 0, 0.0f, 0.0f, 4);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, CB3Score::gmarMinDrift, D_004B6E70, D_004B6E20, gacScoreFileName, 0, 0.0f, 0.0f, 4);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, CB3Score::gmarMinTailgate, D_004B6E90, D_004B6E20, gacScoreFileName, 0, 0.0f, 0.0f, 3);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, CB3Score::gmarMinRubbing, D_004B6EC0, D_004B6E20, gacScoreFileName, 0, 0.0f, 0.0f, 3);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, CB3Score::gmarMinGrinding, D_004B6EF0, D_004B6E20, gacScoreFileName, 0, 0.0f, 0.0f, 3);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, CB3Score::gmarMinNearMiss, D_004B6F20, D_004B6E20, gacScoreFileName, 0, 0.0f, 0.0f, 4);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &CB3Score::gmrTailgateMaxDistance, D_004B6F50, D_004B6F80, gacScoreFileName, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &CB3Score::gmrTailgatePsycheOutDistance, D_004B6FA0, D_004B6F80, gacScoreFileName, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &CB3Score::gmrTailgateConeAngle, D_004B6FE0, D_004B6F80, gacScoreFileName, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &CB3Score::gmrTailgateExtraBurnValue, D_004B7010, D_004B6F80, gacScoreFileName, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &CB3Score::gmrTailgateInitialTime, D_004B7030, D_004B6F80, gacScoreFileName, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &CB3Score::gmrGrindingMinTime, D_004B7070, D_004B70A0, gacScoreFileName, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &CB3Score::gmrGrindingExtraBurnValue, D_004B7010, D_004B70A0, gacScoreFileName, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, CB3Score::gmarDistanceTravelledMedals, D_004B70B0, D_004B70E0, gacScoreFileName, 0, 0.0f, 0.0f, 3);
}
