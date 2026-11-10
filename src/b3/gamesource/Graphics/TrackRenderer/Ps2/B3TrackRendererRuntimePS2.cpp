// 0x0026BC60 (E map name not seen yet; filename inferred from Revenge's B4TrackRendererRuntimePS2.obj)
// [C] folder: alienbrain literal path GameSource\Graphics\TrackRenderer\Ps2\B4TrackRendererRuntimePS2.cpp
// (research/R_jul14/symtab.csv, N35) -- supersedes the earlier "Render" semantic-fit guess.
#include "b3/gamesource/Graphics/TrackRenderer/Ps2/B3TrackRendererRuntimePS2.h"

extern unsigned int _gpMeshCache;   // config/symbol_addrs_b3names.txt: 0x004E2A10, type:u32

void CB3TrackRenderer::Destruct()
{
    int invalid = -1;
    field_94 = 0;
    field_9A = 0;
    field_9C = 0;
    _gpMeshCache = 0;
    field_98 = 0;
    field_A0 = 0;
    field_A8 = 0;
    field_B0 = 0;
    field_B8 = 0;
    field_99 = invalid;
    field_8C = invalid;
}
