// CB3TrackRenderer (E map name not seen yet; this filename is inferred [L]).
// Revenge (Jul 14 2005 prototype) keeps the same class renamed CB3->CB4, compiled from
// "B4TrackRendererRuntimePS2.obj" (research/R_jul14/map_symbols.csv) -- the B3 filename here mirrors
// that exactly (B4->B3). No Burnout 2 counterpart found; Area is "Render" per B2's gamesource tree
// (K18) on semantic fit (track rendering: camera setup, materials, instance meshes), not a literal
// B2 class match [L].
//
// Only Destruct() is implemented so far. The other methods below are named from
// config/symbol_addrs_b3names.txt (retail addresses) but not yet decompiled; listed for reference.
#ifndef B3_B3TRACKRENDERERRUNTIMEPS2_H
#define B3_B3TRACKRENDERERRUNTIMEPS2_H

class CB3TrackRenderer {
public:
    void Destruct();   // 0x0026BC60 [C]: decompiled and objdiff-verified
    // void Construct();                                                    // 0x0026BCA0, not yet named in the map
    // void EndInstanceRender();                                            // 0x0026A1C0
    // void FlushInstances();                                               // 0x0026A240
    // void RenderInstances(signed char, const CB3InstanceData*);           // 0x0026A610
    // void PushCameraForInstanceRendering(EB3RenderableCamera);            // 0x0026A710
    // void BeginInstanceRender(const CB3InstanceMesh*, const CGtAxisAlignedBox*, const CB3TrackMaterial&, float, float, EB3InstanceDistanceCheck, bool); // 0x0026A7E0
    // void EndMaterial();                                                  // 0x0026B2B0
    // void ReallySetMaterial();                                            // 0x0026B2F0
    // void RestoreRenderStatesAfterRenderingTrack();                       // 0x0026B7B0
    // void PrepareRenderStatesForRenderingTrack();                         // 0x0026B8E0
    // void ReallySetupCameraData();                                       // 0x0026BAA0

    // Fields below are placeholders: offsets and sizes are [C] (observed directly in Destruct's
    // stores), types/meanings are [G] (guessed from store width and the -1/0xFF sentinel pattern,
    // typical of "invalid index/handle" cleanup -- not confirmed by any read site yet).
    unsigned char pad0[0x8C];
    int field_8C;           // [G] set to -1 in Destruct -- looks like an invalidated index/handle
    unsigned char pad90[4];
    int field_94;            // [G] set to 0 in Destruct
    unsigned char field_98;   // [G] set to 0 in Destruct (byte)
    signed char field_99;   // [G] set to 0xFF in Destruct -- another invalidated-handle byte
    unsigned char field_9A;   // [G] set to 0 in Destruct (byte)
    unsigned char pad9B;
    unsigned char field_9C;   // [G] set to 0 in Destruct (byte)
    unsigned char pad9D[3];
    unsigned long long field_A0; // [G] 8 bytes, zeroed as one `sd` -- could be one 64-bit value or two 32-bit fields
    unsigned long long field_A8; // [G] same pattern
    unsigned long long field_B0; // [G] same pattern
    unsigned long long field_B8; // [G] same pattern
};

#endif
