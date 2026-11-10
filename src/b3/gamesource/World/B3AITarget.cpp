#include "b3/gamesource/World/B3AITarget.h"

extern int _gnAITargetMonitorID;   // config/symbol_addrs_b3names.txt: 0x004E1440, type:u32

void CB3AITarget::Construct()
{
    if (_gnAITargetMonitorID == -1)
    {
        _gnAITargetMonitorID = 0;
    }
    field_170.Construct();
}
