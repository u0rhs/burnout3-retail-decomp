// func_00155280 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (merged early-return guard; accumulate res = m*60; res += s; res += frac (separate statements stop madd fusion)).

// func_00155280 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

// 0x00155280
extern "C" float func_00155280(float f0)
{
    if (3.4028235e+38f == f0 || 0.0f == f0) {
        return f0;
    }
    float r = f0 - 60.0f * (float)(int)(f0 / 60.0f);
    float s = (float)(int)r;
    int h = (int)(100.0f * (r - s));
    float m = (float)(int)(0.016666668f * f0);
    float res = m * 60.0f;
    res += s;
    res += (float)(h % 100) / 100.0f;
    return res;
}
