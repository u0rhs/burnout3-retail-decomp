// B3NetworkVoIPManagerPS2.cpp -- translation unit regrouped by tools/tu_merge.py from 1 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 1 function(s) named in research/retail_names.csv -> B3NetworkVoIPManagerPS2.cpp.
// Area not evidenced (no Revenge file), so _unclassified/ (docs/conventions.md).
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3NetworkVoIPManager.h"
#include "b3/classes/CGtNetworkPlayerManager.h"

extern "C" void func_002C1EC0(CB3NetworkVoIPManager *, void *, int, int, CGtNetworkPlayerManager*);

// CB3NetworkVoIPManager::Construct(CGtNetworkPlayerManager*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3NetworkVoIPManagerPS2.cpp.
// 0x0041EAD0
void CB3NetworkVoIPManager::Construct(CGtNetworkPlayerManager* p0)
{
    func_002C1EC0(this, ((char *)this + 0x820C), 7, 3, p0);
}
