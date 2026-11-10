// CB3SFIOCallbacks::SFIOMountCallback(SFIODeviceE) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SFIOCallbacksPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (SFIO callback).

#include "b3/classes/CB3SFIOCallbacks.h"
struct UnkStruct_D_005185A0 { unsigned char pad_0[0x10]; };
extern UnkStruct_D_005185A0 D_005185A0;
extern "C" int Sync__16CMemoryDevicePS2F17EMemDevPollOrWaitPi(void *, int, int *);
extern "C" void SFIOMountCallback__16CB3SFIOCallbacksF11SFIODeviceE(int dev) {
  if (Sync__16CMemoryDevicePS2F17EMemDevPollOrWaitPi(&D_005185A0, 1, 0) != 0) {
    CB3SFIOCallbacks::gmeError = 0;
    CB3SFIOCallbacks::gmeLastOperation = 1;
    CB3SFIOCallbacks::gmeProcess = 1;
  } else {
    CB3SFIOCallbacks::gmeLastOperation = 0;
    CB3SFIOCallbacks::gmeProcess = 2;
    CB3SFIOCallbacks::gmeError = 0;
  }
}
