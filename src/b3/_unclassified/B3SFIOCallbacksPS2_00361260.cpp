// CB3SFIOCallbacks::SFIOCreateCallback(const char*,unsigned int,SFIODeviceE) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SFIOCallbacksPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (SFIO callback).

#include "b3/classes/CB3SFIOCallbacks.h"
struct UnkStruct_D_005185A0 { unsigned char pad_0[0x10]; };
extern UnkStruct_D_005185A0 D_005185A0;
extern "C" int MkDir__16CMemoryDevicePS2FPCc(void *, const char *);
extern "C" void SFIOCreateCallback__16CB3SFIOCallbacksFPCcUi11SFIODeviceE(const char *path, unsigned a1, int dev) {
  if (MkDir__16CMemoryDevicePS2FPCc(&D_005185A0, path) == 0) {
    CB3SFIOCallbacks::gmeLastOperation = 0;
    CB3SFIOCallbacks::gmeProcess = 2;
    CB3SFIOCallbacks::gmeError = 0x11;
  } else {
    CB3SFIOCallbacks::gmeError = 0;
    CB3SFIOCallbacks::gmeLastOperation = 4;
    CB3SFIOCallbacks::gmeProcess = 1;
  }
}
