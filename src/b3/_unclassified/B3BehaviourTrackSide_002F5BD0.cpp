// CB3BehaviourTrackSide::StepForward(float) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3BehaviourTrackSide.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (two while loops, static extern C).

struct UnkStruct_sf_lane;
extern "C" float GetSegmentLengthFast__9CB3AILaneCFUs(UnkStruct_sf_lane *lane, unsigned short seg);
extern "C" void IncrementSegment__21CB3BehaviourTrackSideFb(UnkStruct_sf_lane **self, unsigned short *idx, int dir, bool fwd);
extern "C" void StepForward__21CB3BehaviourTrackSideFf(float *frac, UnkStruct_sf_lane **lane, unsigned short *idx, int dir, float amt)
{
    while (amt > 0.0f) {
        float len = GetSegmentLengthFast__9CB3AILaneCFUs(*lane, *idx);
        float rem = len * (1.0f - *frac);
        if (rem < amt) {
            IncrementSegment__21CB3BehaviourTrackSideFb(lane, idx, dir, true);
            amt -= rem;
            *frac = 0.0f;
        } else {
            *frac += amt / len;
            amt = 0.0f;
        }
    }
    while (amt < 0.0f) {
        float len = GetSegmentLengthFast__9CB3AILaneCFUs(*lane, *idx);
        float used = len * *frac;
        if (used < -amt) {
            IncrementSegment__21CB3BehaviourTrackSideFb(lane, idx, dir, false);
            amt += used;
            *frac = 1.0f;
        } else {
            *frac += amt / len;
            amt = 0.0f;
        }
    }
}
