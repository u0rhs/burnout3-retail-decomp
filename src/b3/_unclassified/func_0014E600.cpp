// Hand-written; the lifter refused it (RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv x5 on CB3Burn static members (gmrMinimumBoostTime gp-rel, arrays lui/addiu)).

extern "C" void *mpToolBase__Q27GtComms16CGtCommsToolBase;
extern "C" void RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(void *a, void *b);
class CB3Burn {
public:
    static float gmarBoostBarSizes[4];
    static float gmarBurnoutBoostMultipliers[4];
    static float gmarBoostRate[4];
    static float gmrMinimumBoostTime;
    static float gmrMinimumBoostRecoveryTime;
};
// 0x0014E600
// [L] DNAT: CB3Burn::UnregisterStaticVariables() (research/proto/new_names.csv, high); static member tables as in B3Burn_0014E500
extern "C" void UnregisterStaticVariables__7CB3BurnFv()
{
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv((char *)mpToolBase__Q27GtComms16CGtCommsToolBase + 0x10, &CB3Burn::gmrMinimumBoostTime);
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv((char *)mpToolBase__Q27GtComms16CGtCommsToolBase + 0x10, &CB3Burn::gmrMinimumBoostRecoveryTime);
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv((char *)mpToolBase__Q27GtComms16CGtCommsToolBase + 0x10, CB3Burn::gmarBoostBarSizes);
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv((char *)mpToolBase__Q27GtComms16CGtCommsToolBase + 0x10, CB3Burn::gmarBurnoutBoostMultipliers);
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv((char *)mpToolBase__Q27GtComms16CGtCommsToolBase + 0x10, CB3Burn::gmarBoostRate);
}
