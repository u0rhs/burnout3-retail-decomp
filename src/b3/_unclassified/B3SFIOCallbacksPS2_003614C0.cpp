// CB3SFIOCallbacks::SFIOFreeSpaceCallback(SFIODeviceE) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3SFIOCallbacksPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (SFIO callback).

#include "b3/classes/CB3SFIOCallbacks.h"
struct UnkStruct_D_005185A0 { unsigned char pad_0[0x10]; };
extern UnkStruct_D_005185A0 D_005185A0;
extern unsigned char D_004E2E14;
extern "C" int GetFreeSpace__16CMemoryDevicePS2Fv(void *);
extern "C" void SFIOFreeSpaceCallback__16CB3SFIOCallbacksF11SFIODeviceE(int dev) {
  int r = GetFreeSpace__16CMemoryDevicePS2Fv(&D_005185A0);
  CB3SFIOCallbacks::gmnFreeSpace = r;
  if (r == -1) {
    CB3SFIOCallbacks::gmeLastOperation = 0;
    D_004E2E14 = 1;
    CB3SFIOCallbacks::gmeProcess = 1;
    CB3SFIOCallbacks::gmeError = 0;
  } else {
    CB3SFIOCallbacks::gmeError = 0;
    CB3SFIOCallbacks::gmeProcess = 1;
  }
}
