// func_001CBE50 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (dperm (decomp-permuter, background run): signed char *st = &self->field_CC4->field_4B2[part];; if (((unsigned int) ((int) (*st))) < 2); signed char *st;; if (((unsigned int) ((int) (*(&self->field_CC4->field_4B2[part])))) <= (2 - 1)); *st = 2;; *(&self->field_CC4->field_4B2[part]) = 2;).

struct UnkStruct_001CBE50_parts { unsigned char pad_0[0x4B2]; signed char field_4B2[8]; };   
struct UnkStruct_001CBE50 { unsigned char pad_0[0xCC4]; UnkStruct_001CBE50_parts * field_CC4; };
extern "C" void func_001CBE50 ( UnkStruct_001CBE50 * self , int part );




// 0x001CBE50
void func_001CBE50(UnkStruct_001CBE50 *self, int part)
{
  signed char *st;
  if (((unsigned int) ((int) (*(&self->field_CC4->field_4B2[part])))) <= (2 - 1))
  {
    *(&self->field_CC4->field_4B2[part]) = 2;
  }
}
