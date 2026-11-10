// Hand-written; the lifter refused it (account-field validity check: merged || conditions share return-0 blocks (len<4||len>16, >16||<4, strchr||strchr, '.'||'@')).

extern "C" unsigned int strlen(const char *);
extern "C" int strcasecmp(const char *, const char *);
extern "C" char * strchr(const char *, int);

struct UnkStruct_0037E440_rec {
    unsigned char pad_0[0xC];
    char field_C[0x20];
    char field_2C[0x20];
    char field_4C[0x20];
};

struct UnkStruct_0037E440 {
    unsigned char pad_0[0x4];
    char field_4[0xC0];
    UnkStruct_0037E440_rec * field_C4;
};

// 0x0037E440
extern "C" int func_0037E440(UnkStruct_0037E440 * self)
{
    if (strlen(self->field_C4->field_C) < 4 || strlen(self->field_C4->field_C) > 16) {
        return 0;
    }
    UnkStruct_0037E440_rec * r = self->field_C4;
    char c = r->field_C[0];
    if (c >= '0' && c <= '9') {
        return 0;
    }
    if (strlen(r->field_2C) > 16 || strlen(self->field_C4->field_2C) < 4) {
        return 0;
    }
    if (strlen(self->field_4) > 16 || strlen(self->field_4) < 4) {
        return 0;
    }
    if (strcasecmp(self->field_C4->field_2C, self->field_4) != 0) {
        return 0;
    }
    if (strlen(self->field_C4->field_4C) < 6) {
        return 0;
    }
    if (strchr(self->field_C4->field_4C, '.') == 0 || strchr(self->field_C4->field_4C, '@') == 0) {
        return 0;
    }
    UnkStruct_0037E440_rec * e = self->field_C4;
    if (e->field_4C[strlen(e->field_4C) - 1] == '.' || self->field_C4->field_4C[strlen(e->field_4C) - 1] == '@') {
        return 0;
    }
    return 1;
}
