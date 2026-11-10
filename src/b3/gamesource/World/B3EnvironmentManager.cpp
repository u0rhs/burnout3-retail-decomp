// B3EnvironmentManager.cpp -- translation unit regrouped by tools/tu_merge.py from 3 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 3 function(s) named in research/retail_names.csv -> B3EnvironmentManager.cpp.
// Area: src/b3/gamesource/World, [L] Revenge (SLUS_212.42) GameSource/World/B4EnvironmentManager.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3EnvironmentManager.h"
#include "b3/classes/CB3SkyDomeRenderer.h"
#include "b3/classes/CB3SunRenderer.h"

extern "C" void RenderCorona__14CB3SunRendererFv(void *);  // CB3SunRenderer::RenderCorona()
extern "C" void Destruct__18CB3SkyDomeRendererFv(void *);  // CB3SkyDomeRenderer::Destruct()

// CB3EnvironmentManager::RenderSunCorona() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3EnvironmentManager.cpp.
// 0x002BBF50
void CB3EnvironmentManager::RenderSunCorona()
{
    if (field_14C == 0) {
        return;
    }
    if (field_13C != 0) {
        RenderCorona__14CB3SunRendererFv(this);
    }
}

// CB3EnvironmentManager::BeginRender(int) -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3EnvironmentManager.cpp.
// 0x002BC450
void CB3EnvironmentManager::BeginRender(int p0)
{
    field_130 = p0;
}

// CB3EnvironmentManager::Destruct() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3EnvironmentManager.cpp.
// 0x002BCE90
void CB3EnvironmentManager::Destruct()
{
    field_140 = 25;
    Destruct__18CB3SkyDomeRendererFv(this);
    CB3SunRenderer::Destruct();
}
