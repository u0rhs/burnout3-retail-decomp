// GtInputDevicePS2DualShock2.cpp -- translation unit regrouped by tools/tu_merge.py from 1 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 1 function(s) named in research/retail_names.csv -> GtInputDevicePS2DualShock2.cpp.
// Area: src/b3/GameShared/GameClasses/System/Input/Ps2, [L] Revenge (SLUS_212.42) GameShared/GameClasses/System/Input/Ps2/GtInputDevicePS2DualShock2.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CGtInputDevicePS2DualShock.h"
#include "b3/classes/CGtInputDevicePS2DualShock2.h"

extern "C" int Prepare__26CGtInputDevicePS2DualShockFv(void *);  // CGtInputDevicePS2DualShock::Prepare()

// CGtInputDevicePS2DualShock2::Prepare() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtInputDevicePS2DualShock2.cpp.
// 0x00215620
int CGtInputDevicePS2DualShock2::Prepare()
{
    int r0 = Prepare__26CGtInputDevicePS2DualShockFv(this);
    if (r0 == 0) {
        return 0;
    }
    field_4 = 4;
    return 1;
}
