// B3CameraEditor.cpp -- translation unit regrouped by tools/tu_merge.py from 11 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 8 function(s) named in research/retail_names.csv -> B3CameraEditor.cpp, 3 by a medium-confidence name confirmed by a neighbour.
// Area: src/b3/gamesource/Camera/Movie, [L] Revenge (SLUS_212.42) GameSource/Camera/Movie/B4CameraEditor.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3CameraEditor.h"
#include "b3/classes/CB3CameraKeyFrame.h"
#include "b3/classes/CB3EditorParams.h"
#include "b3/classes/CB3PlayerCameraManager.h"

// CB3CameraEditor::Update() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3CameraEditor.cpp.
// 0x003744F0
void CB3CameraEditor::Update()
{
}

// CB3CameraEditor::Release() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3CameraEditor.cpp.
// 0x00374500
void CB3CameraEditor::Release()
{
}

// CB3CameraEditor::Prepare(CB3EditorParams*) -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3CameraEditor.cpp.
// 0x00374510
int CB3CameraEditor::Prepare(CB3EditorParams* p0)
{
    return 1;
}

// CB3CameraEditor::Destruct() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3CameraEditor.cpp.
// 0x00374520
void CB3CameraEditor::Destruct()
{
}

// CB3CameraEditor::Construct(CB3PlayerCameraManager*) -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3CameraEditor.cpp.
// 0x00374530
void CB3CameraEditor::Construct(CB3PlayerCameraManager* p0)
{
    field_3C = 0;
    field_40 = 0;
    field_4 = 1;
}

// CB3CameraKeyFrame::GetEventRecord() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3CameraEditor.cpp.
// 0x00446F90
int CB3CameraKeyFrame::GetEventRecord()
{
    return ((unsigned int)(field_14 & 3072) >> 10);
}

// CB3CameraKeyFrame::GetEventPause() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3CameraEditor.cpp.
// 0x00446FA0
int CB3CameraKeyFrame::GetEventPause()
{
    return ((unsigned int)(field_14 & 768) >> 8);
}

// CB3CameraKeyFrame::GetTypeTransition() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3CameraEditor.cpp.
// 0x00446FB0
int CB3CameraKeyFrame::GetTypeTransition()
{
    return ((unsigned int)(field_14 & 240) >> 4);
}

// CB3CameraKeyFrame::GetTypeBehaviour() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3CameraEditor.cpp.
// 0x00446FC0
int CB3CameraKeyFrame::GetTypeBehaviour()
{
    return (field_14 & 15);
}

// CB3CameraKeyFrame::GetRaceCarIndex() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3CameraEditor.cpp.
// 0x00446FD0
unsigned char CB3CameraKeyFrame::GetRaceCarIndex()
{
    return field_18;
}

// CB3CameraKeyFrame::GetIsSetup() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3CameraEditor.cpp.
// 0x00446FE0
bool CB3CameraKeyFrame::GetIsSetup()
{
    return (((unsigned int)(field_14 & 0x80000000) >> 31) == 1);
}
