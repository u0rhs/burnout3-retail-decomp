// CB3TrafficDebug -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3TRAFFICDEBUG_H
#define B3_CLASSES_CB3TRAFFICDEBUG_H

class CB3TrafficDebug;

class CB3TrafficDebug {
public:
    void Construct();
    void Destruct();
    void Prepare();
    void RenderNearMissData();
    void RenderSpatialTriggers();
    void RenderWorld();
    void Update();

    unsigned char field_0;
    unsigned char field_1;
    unsigned char field_2;
    unsigned char field_3;
    unsigned char field_4;
};

#endif
