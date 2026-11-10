"""Classify map symbols into layer + subsystem from their source file. Writes classified CSV + docs/subsystems.md.
Layer: PLATFORM-LIB (3rd-party/Sony/RW/CRT: replace), ENGINE-PS2 (hardware-specific Gt/B3 *PS2* + VU code: shim/replace),
       ENGINE-CORE (Criterion 'Gt' engine, portable), GAME (B3*)."""
import csv, re, sys, collections
rows = list(csv.DictReader(open(sys.argv[1])))
LIBRE = re.compile(r'^\S+\.(a|lib)\s', re.I)
SUB = [  # first match wins; evidence = file name only unless noted
 ("demo_build",      r'^B3(Demo|MSDemo|OPMDemo|CrashDemo)'),
 ("debug_tools",     r'Debug|CameraEditor|CPUMonitors|^GtPerfMon|^B3MyBurnoutDevelopment'),
 ("vehicle_physics", r'^B3(VehiclePhysics|PlayerCarPhysics|RaceCarPhysics|NetworkCarPhysics|BodyPartPhysics|PropPhysics|Transmission|PhysicsConstants|PhysicsManager|CollidingBody|VehicleDeform|RumbleAttribs)|^B3(PlayerCar|RaceCar|NetworkCar)\.'),
 ("collision",       r'ConvexHull|^GtCollisionKDTree|^GtIntersection|^GtIntsec|^GtPolygonSoup|^GtSphereTree|OrientedBox|TrackCollision|^B3BoundingBox'),
 ("score_boost",     r'^B3(Score|ScoreBonus|Burn|BoostEffectParams|HUDBoostBar|HUDScore|HUDEscape|HUDTakedowns)'),
 ("crash_takedown",  r'^B3Crash(?!Demo)|^B3TurnBasedCrash|^B3HardCodedCrash|^B3HardCodedTakedown|^B3HUDCrash|^B3HUDImpact|^B3ExplosionManager|^B3Behaviour(Aftermath)'),
 ("rival_ai",        r'^B3AI'),
 ("traffic",         r'^B3Traffic|^B3StopJunction|^B3SpatialTrigger'),
 ("camera",          r'Camera(?!Editor)|^B3Behaviour|^GtFrustumBuilder|^GtCameraFrustum'),
 ("replay",          r'^B3Replay'),
 ("world_props",     r'^B3(PropManager|TriggerStruct)'),
 ("race_modes",      r'^B3(Player\.|WrongWayWall|Offline|OnlineStageLogic|Online\w*Logic|StageLogic|Challenge|ChampionshipChallenge|SingleChallenge|OnePlayerStage|OnlineStage|TwoPlayer|EndOfRace|RacePosition|SplitTime|StartFinish|StartPoint|EventState|Game(?!Data)|NormalGameModes|GameMode|GameState|World|Progression|Records|MenuFinishedEvent)|^B3OnlineEndOfRace'),
 ("save_data",       r'MemoryCard|AutoSave|^B3Profile|^B3Settings|^GTMemoryDevice|^B3MemoryCard'),
 ("network_online",  r'Network|^GtLobby|^GtBuddies|^GtNAT|Headset|^GtSyncTime|^GtPS2LibNet|^B3DNAS|SharedLogin|^B3OnlineConnecting|VoIP|^GtComms'),
 ("audio",           r'^B3Sound|^GtSound'),
 ("input",           r'^B3(Input|Controller)|^GtInput|ControllerRemoved'),
 ("asset_loading",   r'AsyncDataLoader|StreamManager|^B3Stream|^B3StaticTrack|^GtFileSystem|SFIOCallbacks|TextureCollection|^GtTexture|^B3EnvironmentData|^B3TrackDataStruct|^B3GameData|^B3DataLists|^B3LoadingState|^B3LoadingScreen'),
 ("rendering",       r'Renderer|\.dsm$|^B3(VehicleReflectivityData|Bloom|Fog|DirectionalBlur|RadialBlur|Im3|Shadow|GraphicsManager|Viewport|ScrapeSystem|ScrapeRender|TrailSystem|TrailRender|Corona|TrackMaterial|Popcorn|EnvironmentManager|EffectsManager)|^Gt(Viewport|ScreenCentre|WideLine)|^G3_|Corona'),
 ("hud_ui_widgets",  r'^B3HUD|2dObject|^Gt2d|Component|^B3MenuInput|^B3MenuImages|^B3MenuString|^B3Strings|^GtUnicode|^B3PromptBar'),
 ("frontend_menus",  r'Page\.|State\.|^B3Menu|^B3FrontEnd|^B3GenericV|^B3Splash|^B3Online|^B3MyBurnout|^B3MyStats|^B3Car(Select|Viewer)|^B3ClassSelect|^B3RegionSelect|^B3Stage(Select)|^B3TrackSelect|^B3Award|^B3Post|^B3Party|^B3Pause|^B3InGame|^B3Event|^B3Race(Finished)|^B3Results|^B3RoadRage|^B3ImageVignette|^B3PlayVideo|^B3ErrorPage|^B3VListC|^B3HardCoded'),
 ("core_util",       r'^Gt|^B3(MemoryManager|MainPS2|BoundingBox)|crt0|mwUtils|vibuf'),
]
def classify(src):
    if LIBRE.match(src): return "PLATFORM-LIB", "library:" + src.split()[0]
    for name, rx in SUB:
        if re.search(rx, src): break
    else: name = "unclassified"
    ps2 = bool(re.search(r'PS2|\.dsm$|VU0|crt0|mwUtils|vibuf', src))
    layer = "ENGINE-PS2" if ps2 else ("ENGINE-CORE" if src.startswith("Gt") or name == "core_util" else "GAME")
    return layer, name
out = []; cnt = collections.defaultdict(lambda: collections.Counter()); files = collections.defaultdict(set)
for r in rows:
    layer, sub = classify(r["source"] or "(none)"); r["layer"], r["subsystem"] = layer, sub; out.append(r)
    if r["section"] == ".text": cnt[(layer, sub)]["funcs"] += 1; cnt[(layer, sub)]["bytes"] += int(r["size"], 16)
    if r["source"]: files[(layer, sub)].add(r["source"])
w = csv.DictWriter(open(sys.argv[2], "w", newline=""), fieldnames=list(out[0].keys())); w.writeheader(); w.writerows(out)
una = sorted(files[("GAME", "unclassified")] | files[("ENGINE-CORE", "unclassified")] | files[("ENGINE-PS2", "unclassified")])
print("unclassified:", una)
md = ["# Subsystem map (build E, `DNAT_200.45`, from link map)\n",
      "Evidence: **source file name** from `DNAT_200.MAP` (Likely, since file names are reliable but a file can contain unrelated helpers) + symbol-name keyword hits listed below. Function/byte counts are `.text` only.\n",
      "| Layer | Subsystem | Funcs | Code bytes | Source files |", "|---|---|---:|---:|---:|"]
for k in sorted(cnt, key=lambda k: (k[0], -cnt[k]["bytes"])):
    md.append(f"| {k[0]} | {k[1]} | {cnt[k]['funcs']} | {cnt[k]['bytes']:,} | {len(files[k])} |")
md.append("\n## Files per subsystem\n")
for k in sorted(files, key=lambda k: (k[0], k[1])):
    if k[0] == "PLATFORM-LIB": continue
    md.append(f"**{k[0]} / {k[1]}** ({len(files[k])}): " + ", ".join(sorted(files[k])) + "\n")
open(sys.argv[3], "w").write("\n".join(md))
