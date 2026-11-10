// GetFOV__17CB3CameraKeyFrameFv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (decomp-permuter (build/vt/permsetup.py)).

extern "C" {

typedef struct UnkStruct_004469E0 UnkStruct_004469E0;
struct UnkStruct_004469E0;
struct UnkStruct_004469E0
{
  unsigned char pad_0[0x19];
  unsigned char field_19;
};
// 0x004469E0
float GetFOV__17CB3CameraKeyFrameFv(UnkStruct_004469E0 *self)
{
  unsigned char t0 = self->field_19;
  float v1;
  if (t0 >= 0)
  {
    v1 = (float) t0;
  }
  else
  {
    v1 = ((float) ((((unsigned int) t0) >> 1) | (t0 & 1))) + ((float) ((((unsigned int) t0) >> 1) | (t0 & 1)));
    v1 = (float) t0;
  }
  return (120.0f * v1) / 255.0f;
}

}
