// func_00131D90 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (dperm (decomp-permuter, background run): if (self->field_2DA48->field_1B4 == 0); if (!self->field_2DA48->field_1B4)).

struct UnkStruct_00131D90_gm { virtual void vfunc_8(); virtual void vfunc_C(); virtual void vfunc_10(); virtual void vfunc_14(); virtual void vfunc_18(); virtual void vfunc_1C(); virtual void vfunc_20(); virtual void vfunc_24(); virtual void vfunc_28(); virtual void vfunc_2C(); virtual void vfunc_30(); virtual void vfunc_34(); virtual void vfunc_38(); virtual void vfunc_3C(); virtual void vfunc_40(); virtual void vfunc_44(); virtual void vfunc_48(); virtual void vfunc_4C(); virtual void vfunc_50(); virtual void vfunc_54(); virtual void vfunc_58(); virtual void vfunc_5C(); virtual void vfunc_60(); virtual void vfunc_64(); virtual void vfunc_68(); virtual void vfunc_6C(); virtual void vfunc_70(); virtual void vfunc_74(); virtual void vfunc_78(); virtual void vfunc_7C(); virtual void vfunc_80(); virtual void vfunc_84(); virtual void vfunc_88(); virtual void vfunc_8C(); virtual void vfunc_90(); virtual void vfunc_94(); virtual void vfunc_98(); virtual void vfunc_9C(); virtual int vfunc_A0(); };
struct UnkStruct_00131D90_st { unsigned char pad_0[0x1B0]; virtual void vfunc_8(); UnkStruct_00131D90_gm * field_1B4; };
struct UnkStruct_00131D90 { unsigned char pad_0[0x2DA48]; UnkStruct_00131D90_st * field_2DA48; };
extern "C" int func_00131D90 ( UnkStruct_00131D90 * self );




// 0x00131D90
int func_00131D90(UnkStruct_00131D90 *self)
{
  if (self->field_2DA48 == 0)
  {
    return 0;
  }
  if (!self->field_2DA48->field_1B4)
  {
    return 0;
  }
  return self->field_2DA48->field_1B4->vfunc_A0();
}
