// Hand-written; the lifter refused it (a76: (unsigned char)(255.0f*x) store).

// [G] listener-like object: sub-object at +0x2ED0 prepared via func_0027A900, volume byte +0x7214 = (unsigned char)(255*p) (a66 idiom). No DNAT row.
struct UnkStruct_0028AC80 {
    unsigned char pad_0[0x2ED0];
    unsigned char field_2ED0[0x4344];
    unsigned char field_7214;
};

extern "C" void func_0027A900(void *);

// 0x0028AC80
extern "C" void func_0028AC80(UnkStruct_0028AC80 * self, float p0)
{
    func_0027A900(self->field_2ED0);
    self->field_7214 = (unsigned char)(255.0f * p0);
}
