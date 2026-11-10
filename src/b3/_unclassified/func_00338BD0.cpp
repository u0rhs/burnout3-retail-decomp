// Hand-written; the lifter refused it (a166 match: a vtable tail-call stub plus an unlabelled strcpy function under one label (whole-unit compare)).

class UnkStruct_a166_o { public: virtual void vfunc_0(); virtual void vfunc_4(); virtual void vfunc_8(); virtual void vfunc_C(); };
extern "C" char *strcpy(char *, const char *);
// 0x00338BD0
extern "C" void func_00338BD0(UnkStruct_a166_o *self) { self->vfunc_C(); }
struct UnkStruct_a166_p { unsigned char pad_0[0x578]; char field_578[1]; };
extern "C" int func_00338BE0(UnkStruct_a166_p *self, char *src) { strcpy(src, self->field_578); return 2; }
