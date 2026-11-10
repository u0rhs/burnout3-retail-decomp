// CB3InputManager -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3INPUTMANAGER_H
#define B3_CLASSES_CB3INPUTMANAGER_H

#include "b3/GtMath.h"

class CB3ControllerMapping;
class CB3InputManager;
struct UnkStruct_002144B0_e0;

struct UnkStruct_002144B0_e0 {
    unsigned char pad_0[0xEC];
};

class CB3InputManager {
public:
    void Construct();
    void GenericConstruct();
    void GenericPrepare();
    void GetAvailableControllers(CB3ControllerMapping**, signed char);
    float GetDeadInputTime(signed char);
    signed char GetLockedPlayersPort(signed char p0);
    int GetMenuBack(signed char p0);
    int GetMenuBuddies(signed char p0);
    int GetMenuConfirm(signed char p0);
    int GetMenuDeletePersona(signed char p0);
    int GetMenuDown(signed char p0);
    int GetMenuKeyboardCapsLock(signed char p0);
    int GetMenuKeyboardShift(signed char p0);
    int GetMenuLeft(signed char p0);
    int GetMenuPageDown(signed char p0);
    int GetMenuPageUp(signed char p0);
    int GetMenuRight(signed char p0);
    int GetMenuUp(signed char p0);
    int GetStartButton(bool, signed char);
    void LockPlayerToPort(signed char p0, signed char p1);
    int Prepare();
    void ResetDeadInputTime(signed char p0);

    UnkStruct_002144B0_e0 field_0[1];  // [G] element count unknown
    unsigned char pad_EC[0xEB4];
    unsigned char field_FA0;
    signed char field_FA1[1];  // [G] element count unknown
    unsigned char pad_FA2[0x1];
    unsigned char field_FA3[1];  // [G] element count unknown
};

#endif
