// B3AIDriver.cpp -- translation unit regrouped by tools/tu_merge.py from 1 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 1 function(s) named in research/retail_names.csv -> B3AIDriver.cpp.
// Area: src/b3/gamesource/World, [L] Revenge (SLUS_212.42) GameSource/World/B4AIDriver.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3AIArbitrator.h"
#include "b3/classes/CB3AIDriver.h"
#include "b3/classes/UnkStruct__gnAIDriverMonitorID.h"

extern UnkStruct__gnAIDriverMonitorID _gnAIDriverMonitorID;
extern "C" void Construct__15CB3AIArbitratorFv(void *);  // CB3AIArbitrator::Construct()

// CB3AIDriver::Construct() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3AIDriver.cpp.
// 0x00145E30
void CB3AIDriver::Construct()
{
    if (_gnAIDriverMonitorID.field_0 == -1) {
        _gnAIDriverMonitorID.field_0 = 0;
    }
    Construct__15CB3AIArbitratorFv(this);
}
