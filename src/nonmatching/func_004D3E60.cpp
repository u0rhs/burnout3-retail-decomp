// NONMATCHING: func_004D3E60 -- retail 291 / ours 292 instructions, 52 in changed runs
// gaps1e: hand-drafted from the asm (gGame's static initialiser)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// gaps1e (2026-11-02): hand-drafted from the retail asm (0x4D3E60..0x4D42E8). A C++ static initialiser (.init; called
// through the .ctor table), kept as its asm label: the inlined default constructor of the game object D_004EE040
// ([L] gGame, CB3Game -- __register_global_object(&D_004EE040, __dt__7CB3GameFv, &D_004EE010) at the end [C]). It stores
// the vtable pointers of the embedded objects: 2 input devices (stride 0xEC from +0x7300), 2 objects of 0x208 (+0x79B8),
// the vdb database (+0x8870), 2 player-camera managers (stride 0xBB0 from +0x28E00, each with its camera states and
// behaviours and 4 CGtCamera at +0x8D0, stride 0x40), the front end (+0x2C818) and its CGtLinearMalloc (+0x2C980,
// constructed), the stages and the game-mode logic objects. Offsets [C] from the asm; member meanings [L] from the vtables.
// TRACK: clean
// EQUIV: [L] written from the asm: every store, loop bound and call accounted for (store order within an object kept;
// bottom-tested loops as retail)

extern unsigned char D_004EE040[];    // [L] gGame (CB3Game)
extern unsigned char D_004EE010[];
extern unsigned char D_004F5340[];    // [C] = D_004EE040 + 0x7300
extern unsigned char D_004DDD90[];
extern unsigned char D_004DE300[];
extern unsigned char D_004DF250[];
extern unsigned char D_004DF8E0[];
extern unsigned char D_004E0400[];
extern unsigned char D_004E0410[];
extern unsigned char D_004E0470[];
extern unsigned char __vt__11CB3FrontEnd[];
extern unsigned char __vt__14CB3OnlineStage[];
extern unsigned char __vt__17CB3OnePlayerStage[];
extern unsigned char __vt__18CB3BehaviourEffect[];
extern unsigned char __vt__18CB3BehaviourOffset[];
extern unsigned char __vt__18CB3BehaviourRotate[];
extern unsigned char __vt__19CB3BehaviourCluster[];
extern unsigned char __vt__20CB3BehaviourKeyFrame[];
extern unsigned char __vt__20CB3CarViewerGameMode[];
extern unsigned char __vt__21CB3BehaviourFlyAround[];
extern unsigned char __vt__21CB3BehaviourTrackSide[];
extern unsigned char __vt__21CB3Offline2PRaceLogic[];
extern unsigned char __vt__22CB3PlayerCameraManager[];
extern unsigned char __vt__23CB3BehaviourInterpolate[];
extern unsigned char __vt__23CB3OfflineRoadRageLogic[];
extern unsigned char __vt__23CB3OnlineCoOpCrashLogic[];
extern unsigned char __vt__23CB3OnlineCompCrashLogic[];
extern unsigned char __vt__24CB3ChampionshipChallenge[];
extern unsigned char __vt__24CB3OfflineTeamCrashLogic[];
extern unsigned char __vt__24CB3OnlineSingleRaceLogic[];
extern unsigned char __vt__25CB3BehaviourRaceCarFollow[];
extern unsigned char __vt__25CB3Offline2PRoadRageLogic[];
extern unsigned char __vt__25CB3OfflineBurningLapLogic[];
extern unsigned char __vt__25CB3OfflineCrashPartyLogic[];
extern unsigned char __vt__25CB3OfflineSingleRaceLogic[];
extern unsigned char __vt__25CB3PlayerCameraStateCrash[];
extern unsigned char __vt__25CB3PlayerCameraStateDebug[];
extern unsigned char __vt__25CB3PlayerCameraStateIntro[];
extern unsigned char __vt__26CB3OfflineCrashBattleLogic[];
extern unsigned char __vt__26CB3OfflineSingleCrashLogic[];
extern unsigned char __vt__26CB3OnlineRoadRageRaceLogic[];
extern unsigned char __vt__26CB3PlayerCameraStateEditor[];
extern unsigned char __vt__26CB3PlayerCameraStateInGame[];
extern unsigned char __vt__26CB3PlayerCameraStatePlayer[];
extern unsigned char __vt__26CB3PlayerCameraStateReplay[];
extern unsigned char __vt__26CB3TurnBasedCrashChallenge[];
extern unsigned char __vt__27CGtInputDevicePS2DualShock2[];
extern unsigned char __vt__28CB3OfflineLapEliminatorLogic[];
extern unsigned char __vt__28CB3OnlineTurnBasedCrashLogic[];
extern unsigned char __vt__28CB3PlayerCameraStateInactive[];
extern unsigned char __vt__29CB3PlayerCameraStateCrashMode[];
extern unsigned char __vt__9CGtCamera[];
extern unsigned char __vt__Q27GtComms20CGtCommsDatabaseGame[];
extern "C" void __ct__15CGtLinearMallocFv(void *);
extern "C" void __dt__7CB3GameFv();   // its address is passed
extern "C" void __register_global_object(void *, void *, void *);

// 0x004D3E60
extern "C" void func_004D3E60()
{
    unsigned char * g = D_004EE040;
    unsigned char * p;
    p = D_004F5340;
    do {
        *(void **)p = __vt__27CGtInputDevicePS2DualShock2;
        p += 0xEC;
    } while (p != g + 0x74D8);
    p = g + 0x79B8;
    do {
        *(void **)p = D_004E0410;
        p += 0x208;
    } while (p != g + 0x7DC8);
    *(void **)(g + 0x8870) = __vt__Q27GtComms20CGtCommsDatabaseGame;
    p = g + 0x28E00;
    do {
        *(void **)(p + 0x0) = __vt__22CB3PlayerCameraManager;
        *(void **)(p + 0x70) = __vt__21CB3BehaviourFlyAround;
        *(void **)(p + 0x10C) = __vt__28CB3PlayerCameraStateInactive;
        *(void **)(p + 0x124) = D_004DE300;
        *(void **)(p + 0x134) = D_004E0400;
        *(void **)(p + 0x14C) = __vt__25CB3PlayerCameraStateIntro;
        *(void **)(p + 0x17C) = __vt__26CB3PlayerCameraStateInGame;
        *(void **)(p + 0x18C) = __vt__25CB3PlayerCameraStateDebug;
        *(void **)(p + 0x1A4) = __vt__25CB3PlayerCameraStateCrash;
        *(void **)(p + 0x1B4) = __vt__26CB3PlayerCameraStateReplay;
        *(void **)(p + 0x1CC) = __vt__29CB3PlayerCameraStateCrashMode;
        *(void **)(p + 0x1DC) = __vt__26CB3PlayerCameraStateEditor;
        *(void **)(p + 0x1F4) = __vt__26CB3PlayerCameraStatePlayer;
        *(void **)(p + 0x200) = __vt__9CGtCamera;
        *(void **)(p + 0x290) = __vt__18CB3BehaviourRotate;
        *(void **)(p + 0x310) = __vt__25CB3BehaviourRaceCarFollow;
        *(void **)(p + 0x338) = __vt__25CB3BehaviourRaceCarFollow;
        *(void **)(p + 0x360) = __vt__18CB3BehaviourOffset;
        *(void **)(p + 0x3A0) = __vt__18CB3BehaviourOffset;
        *(void **)(p + 0x3E0) = __vt__18CB3BehaviourOffset;
        *(void **)(p + 0x420) = __vt__18CB3BehaviourOffset;
        *(void **)(p + 0x460) = __vt__18CB3BehaviourOffset;
        *(void **)(p + 0x4A0) = __vt__18CB3BehaviourEffect;
        *(void **)(p + 0x4C0) = __vt__18CB3BehaviourEffect;
        *(void **)(p + 0x4E0) = __vt__19CB3BehaviourCluster;
        *(void **)(p + 0x6D0) = __vt__19CB3BehaviourCluster;
        *(void **)(p + 0x8C0) = __vt__23CB3BehaviourInterpolate;
        unsigned char * q = p + 0x8D0;
        do {
            *(void **)q = __vt__9CGtCamera;
            q += 0x40;
        } while (q != p + 0x9D0);
        *(void **)(p + 0xA10) = __vt__20CB3BehaviourKeyFrame;
        *(void **)(p + 0xA1C) = __vt__20CB3BehaviourKeyFrame;
        *(void **)(p + 0xA30) = __vt__21CB3BehaviourFlyAround;
        *(void **)(p + 0xAC0) = __vt__21CB3BehaviourTrackSide;
        *(void **)(p + 0xAF0) = __vt__18CB3BehaviourOffset;
        *(void **)(p + 0xB30) = D_004E0470;
        p += 0xBB0;
    } while (p != g + 0x2A560);
    *(void **)(g + 0x2C818) = __vt__11CB3FrontEnd;
    __ct__15CGtLinearMallocFv(g + 0x2C980);
    *(void **)(g + 0x2CB50) = __vt__20CB3CarViewerGameMode;
    *(void **)(g + 0x2CB60) = __vt__9CGtCamera;
    *(void **)(g + 0x2CE70) = __vt__17CB3OnePlayerStage;
    *(void **)(g + 0x2D030) = D_004DDD90;
    *(void **)(g + 0x2D1F8) = __vt__14CB3OnlineStage;
    *(void **)(g + 0x2D218) = __vt__25CB3OfflineSingleRaceLogic;
    *(void **)(g + 0x2D264) = __vt__25CB3OfflineBurningLapLogic;
    *(void **)(g + 0x2D2B0) = __vt__28CB3OfflineLapEliminatorLogic;
    *(void **)(g + 0x2D300) = __vt__23CB3OfflineRoadRageLogic;
    *(void **)(g + 0x2D374) = __vt__26CB3OfflineSingleCrashLogic;
    *(void **)(g + 0x2D3CC) = __vt__24CB3OfflineTeamCrashLogic;
    *(void **)(g + 0x2D424) = __vt__25CB3OfflineCrashPartyLogic;
    *(void **)(g + 0x2D47C) = __vt__26CB3OfflineCrashBattleLogic;
    *(void **)(g + 0x2D4D4) = __vt__21CB3Offline2PRaceLogic;
    *(void **)(g + 0x2D52C) = __vt__25CB3Offline2PRoadRageLogic;
    *(void **)(g + 0x2D578) = __vt__24CB3OnlineSingleRaceLogic;
    *(void **)(g + 0x2D5EC) = __vt__26CB3OnlineRoadRageRaceLogic;
    *(void **)(g + 0x2D650) = __vt__23CB3OnlineCoOpCrashLogic;
    *(void **)(g + 0x2D6D4) = __vt__23CB3OnlineCompCrashLogic;
    *(void **)(g + 0x2D748) = __vt__28CB3OnlineTurnBasedCrashLogic;
    *(void **)(g + 0x2D7BC) = D_004DF250;
    *(void **)(g + 0x2D8E0) = __vt__24CB3ChampionshipChallenge;
    *(void **)(g + 0x2D8E8) = __vt__26CB3TurnBasedCrashChallenge;
    *(void **)(g + 0x2D948) = D_004DF8E0;
    __register_global_object(D_004EE040, (void *)__dt__7CB3GameFv, D_004EE010);
}
