// Hand-written; the lifter refused it (CB3Burn::RegisterStaticVariables: AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi table, mirror of Unregister (UnregisterStaticVariables__7CB3BurnFv); char-array externs for name/dir/file).

// RegisterStaticVariables__7CB3BurnFv -- hand-written from the retail structure (lifter refused: address of a static member).
// [L] DNAT: CB3Burn::RegisterStaticVariables() (research/proto/new_names.csv, high); mirror of UnregisterStaticVariables__7CB3BurnFv (Unregister).

extern "C" void *mpToolBase__Q27GtComms16CGtCommsToolBase;
extern "C" void AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(void *, void *, void *, void *, void *, int, float, float, int);
extern char D_004B5F30[], D_004B5F50[], D_004B5F60[], D_004B5F90[], D_004B5FB0[], D_004B5FD0[];
extern char gacBoostFileName[];
class CB3Burn {
public:
    static float gmarBoostBarSizes[4];
    static float gmarBurnoutBoostMultipliers[4];
    static float gmarBoostRate[4];
    static float gmrMinimumBoostTime;
    static float gmrMinimumBoostRecoveryTime;
};
// 0x0014E670
extern "C" void RegisterStaticVariables__7CB3BurnFv()
{
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi((char *)mpToolBase__Q27GtComms16CGtCommsToolBase + 0x10, &CB3Burn::gmrMinimumBoostTime, D_004B5F30, D_004B5F50, gacBoostFileName, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi((char *)mpToolBase__Q27GtComms16CGtCommsToolBase + 0x10, &CB3Burn::gmrMinimumBoostRecoveryTime, D_004B5F60, D_004B5F50, gacBoostFileName, 0, 0.0f, 0.0f, 0);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi((char *)mpToolBase__Q27GtComms16CGtCommsToolBase + 0x10, CB3Burn::gmarBoostBarSizes, D_004B5F90, D_004B5F50, gacBoostFileName, 0, 0.0f, 720.0f, 4);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi((char *)mpToolBase__Q27GtComms16CGtCommsToolBase + 0x10, CB3Burn::gmarBurnoutBoostMultipliers, D_004B5FB0, D_004B5F50, gacBoostFileName, 0, 0.0f, 10.0f, 4);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi((char *)mpToolBase__Q27GtComms16CGtCommsToolBase + 0x10, CB3Burn::gmarBoostRate, D_004B5FD0, D_004B5F50, gacBoostFileName, 0, 0.0f, 720.0f, 4);
}
