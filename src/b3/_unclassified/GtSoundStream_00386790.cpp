// CGtSoundStream::AttachMedia(const char*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtSoundStream.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (extern C with extra int param; int c=*p; (char)c compare gives dsll32/dsra32).

extern "C" char *strncpy(char *, const char *, unsigned);
extern "C" int _rwaStreamGetStatus(int);
extern "C" void _rwaStreamSetMedia(int, void *);
struct UnkStruct_00386790_media {
    void *field_0;
    int field_4;
    int field_8;
    int field_C;
    int field_10;
    int field_14;
    int field_18;
    int field_1C;
    int field_20;
    int field_24;
    int field_28;
    int field_2C;
};
class CGtSoundStream {
public:
    unsigned char pad_0[0x100];
    UnkStruct_00386790_media field_100;
    unsigned char pad_130[0x4];
    int field_134;
    int field_138;
    unsigned char pad_13C[0x90];
    int field_1CC;
    int field_1D0;
    unsigned char pad_1D4[0x18];
    unsigned char field_1EC;
    unsigned char field_1ED;
    unsigned char pad_1EE[6];
    unsigned char field_1F4;
    unsigned char field_1F5;
    unsigned char field_1F6;
};
extern "C" bool AttachMedia__14CGtSoundStreamFPCc(CGtSoundStream *self, const char *path, int p1)
{
    self->field_1F5 = 0;
    self->field_1F6 = 0;
    self->field_1EC = 0;
    self->field_1ED = 0;
    int status = _rwaStreamGetStatus(self->field_1CC);
    if (self->field_1F4 == 0) {
        if (status != 9) return false;
        strncpy((char *)self, path, 0x100);
        for (char *p = (char *)self; *p != 0; p++) {
            int c = *p;
            if ((char)c == 0x2F) *p = 0x5C;
        }
        self->field_100.field_4 = 1;
        self->field_100.field_C = 0;
        self->field_100.field_10 = 0;
        self->field_100.field_8 = 0;
        self->field_100.field_14 = self->field_134;
        self->field_100.field_1C = self->field_138;
        self->field_100.field_18 = *(int *)((char *)self + 0x130);
        self->field_100.field_20 = 0;
        self->field_100.field_28 = p1;
        self->field_100.field_2C = 0;
        self->field_100.field_24 = 2;
        self->field_100.field_0 = self;
        _rwaStreamSetMedia(self->field_1CC, &self->field_100);
        self->field_1D0 = 1;
        self->field_1F4 = 1;
    }
    return status == 3;
}
