// Hand-written; the lifter refused it (MRU name list (10x16 chars, count at +0xA0): loop bound as (n = count-1) in the test, store n).

struct UnkStruct_0026C7A0 { char field_0[16]; };
struct UnkStruct_0026C7A0_self { UnkStruct_0026C7A0 field_0[10]; unsigned char field_A0; };
extern "C" int strcasecmp(const char *, const char *);
extern "C" char *strncpy(char *, const char *, unsigned long);
// 0x0026C7A0
extern "C" void func_0026C7A0(UnkStruct_0026C7A0_self *self, const char *p0)
{
    unsigned char i = 0;
    for (; i < self->field_A0; i++) {
        if (strcasecmp(self->field_0[i].field_0, p0) == 0) return;
    }
    if (self->field_A0 == 10) {
        int n;
        for (i = 0; i < (n = self->field_A0 - 1); i++) {
            int j = i + 1;
            strncpy(self->field_0[i].field_0, self->field_0[j].field_0, 16);
        }
        self->field_A0 = n;
    }
    strncpy(self->field_0[self->field_A0].field_0, p0, 16);
    if (self->field_A0 < 10) self->field_A0 = self->field_A0 + 1;
}
