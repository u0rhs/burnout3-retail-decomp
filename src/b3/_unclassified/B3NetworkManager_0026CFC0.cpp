// CB3NetworkManager::GetErrorString(int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3NetworkManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md).
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3NetworkManager.h"

// 0x0026CFC0
int CB3NetworkManager::GetErrorString(int e)
{
    if (!(e > -1000)) return GetDirtySockErrorString(e);
    switch (e) {
    case 0:
        return 0x6D;
    case -1:
        return 0x6D;
    case -2:
        return 0x59;
    case -3:
        return 0x63;
    case -4:
        return 0x6D;
    case -5:
        return 0x6F;
    case -6:
        return 0x470;
    case -7:
        return 0x457;
    case -8:
        return 0x4A8;
    case -9:
        return 0x423;
    case -10:
        return 0x471;
    case -11:
        return 0x471;
    case -12:
        return 0x480;
    case -13:
        return 0x53;
    case -14:
        return 0x49B;
    case -15:
        return 0x466;
    case -16:
        return 0x469;
    case -17:
        return 0x479;
    case -18:
        return 0x453;
    case -19:
        return 0x4A8;
    case -20:
        return 0x453;
    case -21:
        return 0x455;
    case -22:
        return 0x456;
    case -23:
        return 0x45D;
    case -24:
        return 0x45F;
    case -25:
        return 0x53;
    case -26:
        return 0x461;
    case -27:
        return 0x465;
    case -28:
        return 0x466;
    case -29:
        return 0x467;
    case -30:
        return 0x45E;
    case -31:
        return 0x460;
    case -32:
        return 0x468;
    case -33:
        return 0x469;
    case -34:
        return 0x46A;
    case -35:
        return 0x46B;
    case -36:
        return 0x46F;
    case -37:
        return 0x471;
    case -38:
        return 0x472;
    case -39:
        return 0x473;
    case -40:
        return 0x478;
    case -41:
        return 0x48C;
    case -42:
        return 0x48D;
    case -43:
        return 0x48F;
    case -44:
        return 0x490;
    case -45:
        return 0x491;
    case -46:
        return 0x492;
    case -47:
        return 0x496;
    case -48:
        return 0x497;
    case -49:
        return 0x498;
    case -50:
        return 0x49B;
    case -51:
        return 0x49C;
    case -52:
        return 0x49D;
    case -53:
        return 0x49E;
    case -54:
        return 0x4A5;
    case -55:
        return 0x4AB;

    default: return 0x6D;
    }
}
