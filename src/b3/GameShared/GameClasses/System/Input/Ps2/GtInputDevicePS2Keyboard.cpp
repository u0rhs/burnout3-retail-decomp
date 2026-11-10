// GtInputDevicePS2Keyboard.cpp -- translation unit regrouped by tools/tu_merge.py from 1 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 1 function(s) named in research/retail_names.csv -> GtInputDevicePS2Keyboard.cpp.
// Area: src/b3/GameShared/GameClasses/System/Input/Ps2, [L] Revenge (SLUS_212.42) GameShared/GameClasses/System/Input/Ps2/GtInputDevicePS2Keyboard.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CGtInputDevicePS2Keyboard.h"
#include "b3/classes/EGtVirtualKeyCodes.h"

extern int kGtVKToHIDTable[];  // [G] element count unknown

// CGtInputDevicePS2Keyboard::IsControlPressed(EGtVirtualKeyCodes) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtInputDevicePS2Keyboard.cpp.
// 0x00303FC0
bool CGtInputDevicePS2Keyboard::IsControlPressed(EGtVirtualKeyCodes p0)
{
    int t0 = kGtVKToHIDTable[p0];
    int v0 = (t0 / 8);
    return ((field_1A[v0] & (1 << (t0 - (v0 << 3)))) != 0);
}
