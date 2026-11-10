#ifndef B3_B3VEHICLEPHYSICSATTRIBS_H
#define B3_B3VEHICLEPHYSICSATTRIBS_H

// [L] folder: Physics/, same domain as CB3VehiclePhysics/CB3CollidingBody; no literal alienbrain
// path found yet for this specific class. [L] lineage: Revenge keeps the same class, renamed
// CB4DrivableVehiclePhysicsAttribs (research/R_jul14/map_symbols.csv) -- CB3->CB4 pattern, fourth
// repetition (N31/N33/N36/N40). Its Destruct() is independently confirmed: 8 bytes in both games.

// upstream keeps RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv @ 0x0021B910 / mpToolBase__Q27GtComms16CGtCommsToolBase @ 0x004E2920; E map calls it
// GtComms::CGtCommsDatabase::RemoveEntry(void*) [high], but both symbols already resolve against
// this repo's own still-asm d4/vdb chunk (assembly/asm/d4/vdb.s), so declared here as-is.
extern "C" void *mpToolBase__Q27GtComms16CGtCommsToolBase;
extern "C" void RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(void *a, void *b);

struct CB3VehiclePhysicsAttribs
{
    unsigned char field_0;   // [L] Construct sets 0
    unsigned char pad1[0x88 - 0x1];
    float field_88;   // [L] Construct: 1000.0f (not reused, direct bit-pattern load)
    float field_8C;   // [L] Construct: D_004E1038 (global), reused at field_A8
    float field_90;   // [L] Construct: 60000.0f, reused at field_9C
    float field_94;   // [L] Construct: 5000.0f, reused at field_A0
    float field_98;   // [L] Construct: D_004E0E00 (global), reused at field_A4
    float field_9C;   // [L] same value as field_90
    float field_A0;   // [L] same value as field_94
    float field_A4;   // [L] same value as field_98
    float field_A8;   // [L] same value as field_8C

    void Destruct();   // 0x00252420 [C]: decompiled and objdiff-verified (empty body)
    void Release();    // 0x00252430 [C]: decompiled and objdiff-verified
    void Construct();  // 0x002524E0 [C]: decompiled and objdiff-verified
};

#endif
