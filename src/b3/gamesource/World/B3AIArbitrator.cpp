// B3AIArbitrator.cpp -- translation unit regrouped by tools/tu_merge.py from 3 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 3 function(s) named in research/retail_names.csv -> B3AIArbitrator.cpp.
// Area: src/b3/gamesource/World, [L] Revenge (SLUS_212.42) GameSource/World/B4AIArbitrator.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/GtMathPs2.h"

#include "b3/classes/CB3AIArbitrator.h"
#include "b3/classes/UnkStruct__gnAIArbitratorMonitorID.h"

extern UnkStruct__gnAIArbitratorMonitorID _gnAIArbitratorMonitorID;
extern "C" void Release__11CB3AITargetFv(void *);  // CB3AITarget::Release()
extern "C" void Construct__11CB3AITargetFv(void *);  // CB3AITarget::Construct()
extern "C" int Prepare__11CB3AITargetFv(void *);  // CB3AITarget::Prepare()

// CB3AIArbitrator::Release() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3AIArbitrator.cpp.
// 0x0019D6A0
void CB3AIArbitrator::Release()
{
    Release__11CB3AITargetFv(this);
    field_2B0.Release();
}

// CB3AIArbitrator::Prepare() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3AIArbitrator.cpp.
// 0x0019DC40
int CB3AIArbitrator::Prepare()
{
    field_770.Zero();
    field_780 = 0;
    field_784 = 0;
    field_788 = 0;
    field_789 = 1;
    field_78C = 0;
    field_790 = 0;
    field_794 = 0;
    field_798 = 0;
    int r0 = Prepare__11CB3AITargetFv(this);
    if (r0 == 0) {
        return 0;
    }
    int r1 = field_2B0.Prepare();
    return r1;
}

// CB3AIArbitrator::Construct() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3AIArbitrator.cpp.
// 0x0019DCB0
void CB3AIArbitrator::Construct()
{
    if (_gnAIArbitratorMonitorID.field_0 == -1) {
        _gnAIArbitratorMonitorID.field_0 = 0;
    }
    Construct__11CB3AITargetFv(this);
    field_2B0.Construct();
}
