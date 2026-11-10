// CB3SoundSkidModelGraph -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3SOUNDSKIDMODELGRAPH_H
#define B3_CLASSES_CB3SOUNDSKIDMODELGRAPH_H

#include "b3/classes/UnkStruct_Graph_pt.h"

class CB3SoundSkidModelGraph;

class CB3SoundSkidModelGraph {
public:
    void CalcVolumeOutput(float p0, float & p1) const;

    UnkStruct_Graph_pt field_0[2];  // [G] element count
};

#endif
