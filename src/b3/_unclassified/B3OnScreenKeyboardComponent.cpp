// B3OnScreenKeyboardComponent.cpp -- translation unit regrouped by tools/tu_merge.py from 2 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 2 function(s) named in research/retail_names.csv -> B3OnScreenKeyboardComponent.cpp.
// Area not evidenced (no Revenge file), so _unclassified/ (docs/conventions.md).
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3OnScreenKeyboardComponent.h"
#include "b3/classes/EGlobalStrings.h"
#include "b3/classes/UnkStruct_D_004F5518.h"
#include "b3/classes/UnkStruct_D_004F551C.h"
#include "b3/classes/UnkStruct_D_004F5520.h"
#include "b3/classes/UnkStruct_D_004F5524.h"

extern UnkStruct_D_004F5518 D_004F5518;
extern UnkStruct_D_004F551C D_004F551C;
extern UnkStruct_D_004F5520 D_004F5520;
extern UnkStruct_D_004F5524 D_004F5524;
extern "C" void KeyboardEventCallback__28CB3OnScreenKeyboardComponentFiiiiPv(int, int, int, int, void*);  // CB3OnScreenKeyboardComponent::KeyboardEventCallback(int,int,int,int,void*), its address taken
extern "C" void KeyboardCharacterCallback__28CB3OnScreenKeyboardComponentFcPv(char, void*);  // CB3OnScreenKeyboardComponent::KeyboardCharacterCallback(char,void*), its address taken

// CB3OnScreenKeyboardComponent::UnRegisterKeyboardCallbacks() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3OnScreenKeyboardComponent.cpp.
// 0x0034D8A0
void CB3OnScreenKeyboardComponent::UnRegisterKeyboardCallbacks()
{
    D_004F5518.field_0 = 0;
    D_004F551C.field_0 = 0;
    D_004F5520.field_0 = 0;
    D_004F5524.field_0 = 0;
}

// CB3OnScreenKeyboardComponent::RegisterKeyboardCallbacks() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3OnScreenKeyboardComponent.cpp.
// 0x0034D8D0
void CB3OnScreenKeyboardComponent::RegisterKeyboardCallbacks()
{
    D_004F5518.field_0 = (void *)&KeyboardEventCallback__28CB3OnScreenKeyboardComponentFiiiiPv;
    D_004F551C.field_0 = this;
    D_004F5520.field_0 = (void *)&KeyboardCharacterCallback__28CB3OnScreenKeyboardComponentFcPv;
    D_004F5524.field_0 = this;
}
