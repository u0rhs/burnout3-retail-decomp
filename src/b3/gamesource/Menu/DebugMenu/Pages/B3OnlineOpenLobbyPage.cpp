// B3OnlineOpenLobbyPage.cpp -- translation unit regrouped by tools/tu_merge.py from 1 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 1 function(s) named in research/retail_names.csv -> B3OnlineOpenLobbyPage.cpp.
// Area: src/b3/gamesource/Menu/DebugMenu/Pages, [G] domain word `Page` in the name: 6 of Revenge's 7 files with it are in GameSource/Menu/DebugMenu/Pages/.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3OnlineOpenLobbyPage.h"

extern "C" char * strncpy(char *, const char *, unsigned int);

// CB3OnlineOpenLobbyPage::GetSelectedLobbyPlayerCallback(char*,int,bool,int,int,int,char*,bool,void*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3OnlineOpenLobbyPage.cpp.
// 0x00396830
bool CB3OnlineOpenLobbyPage::GetSelectedLobbyPlayerCallback(char* p0, int p1, bool p2, int p3, int p4, int p5, char* p6, bool p7, void* p8)
{
    strncpy((char *)p8 + 4, p0, 32);
    return true;
}
