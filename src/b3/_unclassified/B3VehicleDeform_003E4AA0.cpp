// CB3VehicleDeform::GetIKAngles(float,float,float,float*,float*,float*,float*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3VehicleDeform.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (near10 byte-exact; sqrt.s decode normalised).


// CB3VehicleDeform::GetIKAngles(float,float,float,float*,float*,float*,float*) -- [C] mangled name
extern float D_004E069C;
extern "C" float func_0011E358(float, float);
extern "C" float sqrtf(float);
// N182: `#pragma opt_repositioncode off` ([G] scoped to this function; found by mwperm).
#pragma push
#pragma opt_repositioncode off
extern "C" int GetIKAngles__16CB3VehicleDeformFfffPfPfPfPf(void *self, float x, float y, float d, float *p0, float *p1, float *p2, float *p3)
{
    float zero = 0.0f;
    if (d > zero) {
        float xx = x * x;
        float r = 0.5f * (d + (xx - y * y) / d);
        // [G] two statements: retail does a plain mul.s/sub.s here (no msub fusion)
        float q = r * r;
        q = xx - q;
        if (q >= zero) {
            float s = sqrtf(q);
            if (p0) *p0 = D_004E069C * func_0011E358(s, r);
            if (p1) *p1 = D_004E069C * func_0011E358(s, d - r);
            if (p2) *p2 = r;
            if (p3) *p3 = s;
            return 1;
        }
    } else {
        return 0;
    }
    return 0;
}
#pragma pop
