// CB3CameraEditor -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3CAMERAEDITOR_H
#define B3_CLASSES_CB3CAMERAEDITOR_H

#include "b3/GtMath.h"

class CB3CameraEditor;
class CB3EditorParams;
class CB3PlayerCameraManager;

class CB3CameraEditor {
public:
    void Construct(CB3PlayerCameraManager* p0);
    void Destruct();
    int Prepare(CB3EditorParams* p0);
    void Release();
    void Update();

    unsigned char pad_0[0x4];
    int field_4;
    unsigned char pad_8[0x34];
    int field_3C;
    int field_40;
};

#endif
