#ifndef B3_B3STREAMEDTRACK_H
#define B3_B3STREAMEDTRACK_H

// [L] folder: no literal alienbrain path found yet for this class; Area "Race" on semantic fit
// (track-streaming during a race), same evidence tier already used for B3TrackDataStruct in this
// same folder. [L] lineage: Revenge keeps the same class renamed CB3StreamedTrack->CB4StreamedTrack
// (research/R_jul14/map_symbols.csv: CB4StreamedTrack::Construct(void)) -- same CB3->CB4 pattern
// already proven twice (N31/N33).
class CB3StreamedTrack {
public:
    void Destruct();     // 0x003030E0 [C]: decompiled and objdiff-verified (Target #19)
    void Construct();   // 0x003030F0 [C]: decompiled and objdiff-verified
    // ... other known-but-undecompiled methods (config/symbol_addrs_b3names.txt lines 1593-3171):
    // RenderAfterSpecular, RenderAfterVehicles, RenderBeforeVehicles,
    // IsUnitVisibleToMainCamera, DoUnitFrustumTesting, ComputeVehicleRenderData, GetIrradiance,
    // IntersectLineNearestWithUnit, Update, GetUnitOriginalID, UpdateStreamFSM,
    // UpdateStreamHighFSM, UpdateStreamLowFSM

private:
    int field_0;      // = -1
    int field_4;      // = -1
    int field_8;      // = -1
    int field_C;      // = -1
    int field_10;     // = 1
    int field_14;     // = 0
    unsigned char field_18;   // = 0
    unsigned char field_19;   // = 0
    unsigned char pad1A[2];
    int field_1C;     // = -1
    int field_20;     // = -1
    int field_24;     // = -1
    int field_28;     // = -1
    int field_2C;     // = -1
    int field_30;     // = -1
    int field_34;     // = -1
    int field_38;     // = 0
    int field_3C;     // = 0
    int field_40;     // = 0
    unsigned char field_44;   // = 0
    unsigned char field_45;   // = 0
    unsigned char field_46;   // = 0
    unsigned char field_47;   // = 0
    int field_48;     // = -1
    int field_4C;     // = -1
    int field_50;     // = -1
    int field_54;     // = -1
};

#endif
