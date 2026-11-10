// B3NetworkReplayMessage.cpp -- translation unit regrouped by tools/tu_merge.py from 4 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 3 function(s) named in research/retail_names.csv -> B3NetworkReplayMessage.cpp, 1 placed between two of them by address contiguity (N2).
// Area not evidenced (no Revenge file), so _unclassified/ (docs/conventions.md).
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3NetworkMessage.h"
#include "b3/classes/CB3NetworkReplayBodyMessage.h"
#include "b3/classes/CB3NetworkReplayHeaderMessage.h"
#include "b3/classes/CB3ReplayFileHeader.h"

extern "C" void * memcpy(void *, const void *, unsigned int);
extern "C" void Prepare__17CB3NetworkMessageFib(void *, int, bool);  // CB3NetworkMessage::Prepare(int,bool)

// CB3NetworkReplayBodyMessage::Retrieve(unsigned char*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3NetworkReplayMessage.cpp.
// 0x003753F0
int CB3NetworkReplayBodyMessage::Retrieve(unsigned char* p0)
{
    if ((field_0 & 1) != 1) {
        return 0;
    }
    memcpy(p0, ((char *)this + 0x18), field_10);
    field_0 = (field_0 & -2);
    return 1;
}

// CB3NetworkReplayBodyMessage::Prepare(const unsigned char*,int,int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3NetworkReplayMessage.cpp.
// 0x00375450
void CB3NetworkReplayBodyMessage::Prepare(const unsigned char* p0, int p1, int p2)
{
    memcpy(((char *)this + 0x18), p0, p2);
    field_10 = p2;
    field_14 = p1;
    Prepare__17CB3NetworkMessageFib(this, 19, 1);
}

// func_003754B0 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x003754B0
extern "C" void func_003754B0(CB3NetworkMessage *self)
{
    self->Construct();
}

// CB3NetworkReplayHeaderMessage::Retrieve(CB3ReplayFileHeader*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3NetworkReplayMessage.cpp.
// 0x003754C0
int CB3NetworkReplayHeaderMessage::Retrieve(CB3ReplayFileHeader* p0)
{
    if ((field_0 & 1) != 1) {
        return 0;
    }
    memcpy(p0, ((char *)this + 0x10), 96);
    field_0 = (field_0 & -2);
    return 1;
}
