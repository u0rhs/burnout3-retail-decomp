// CB3CameraEditor::LoadMungedKeyFrames(void*,EB3KeyFrameType) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3CameraEditor.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (file loader FSM; FAKEMATCH pad16 frame slot; switch(s) 3/2/0 default break).

struct UnkStruct_4550_file { virtual void vfunc_8(); virtual void vfunc_C(); virtual void vfunc_10(void *, int); virtual void vfunc_14(); virtual void vfunc_18(); virtual void vfunc_1C(); virtual void vfunc_20(); virtual int vfunc_24(); };
struct UnkStruct_4550 { unsigned char pad_0[0x3C]; UnkStruct_4550_file *field_3C; int field_40; int field_44; };
struct UnkStruct_4550_row { unsigned long field_0; int field_8; int field_C; };
struct UnkStruct_4550_hdr { int field_0; unsigned char pad_4[0x4]; UnkStruct_4550_row field_8[1]; };
struct UnkStruct_D_004F60C0 { void *field_0; unsigned char pad[0xC]; };
struct UnkStruct_D_UL { unsigned long field_0; unsigned char pad[0x8]; };
extern UnkStruct_D_004F60C0 D_004F60C0;
extern UnkStruct_D_UL D_01E901F0, D_0064D370;
extern char D_004C8FB0[], D_004C8FC0[], D_004C8FD0[], D_004C8FE0[];
extern "C" char * strcpy(char *, const char *);
extern "C" void * memset(void *, int, unsigned int);
extern "C" int sprintf(char *, const char *, ...);
extern "C" unsigned long GtIDCompress__FPCc(char *);
extern "C" int FindCrashStage__26CB3HardCodedCrashStageListFUl(unsigned long);
extern "C" UnkStruct_4550_file * Open__13CGTFileSystemFPCcUi(void *, const char *, unsigned int);
extern "C" void FSeek__13CGTFileSystemFPvii(void *, int, int);
extern "C" int LoadMungedKeyFrames__15CB3CameraEditorFPv15EB3KeyFrameType(UnkStruct_4550 * self, void * buf, void *type_)
{
    int type = (int)type_;
    char key[16];
    char name[64];
    char pad16[16];  // FAKEMATCH [G]: unused 16-byte frame slot below name[] (retail frame 0xC0, source needs 0xB0)
    if (self->field_3C != 0) {
        int s = self->field_3C->vfunc_24();
        switch (s) {
        case 3:
            self->field_40 = 0;
            return 0;
        case 2:
        case 0:
            return 1;
        default:
            break;
        }
    }
    switch (self->field_40) {
    case 0:
        if (type == 1) {
            strcpy(name, D_004C8FD0);
        } else if (type == 3) {
            strcpy(name, D_004C8FB0);
        } else {
            strcpy(name, D_004C8FC0);
        }
        self->field_3C = Open__13CGTFileSystemFPCcUi(D_004F60C0.field_0, name, 0x11);
        self->field_40 = 1;
        break;
    case 1:
        if (self->field_3C == 0) {
            self->field_40 = 0;
            return 0;
        }
        self->field_3C->vfunc_10(buf, 0x800);
        self->field_40 = 2;
        break;
    case 2: {
        int count = *(int *)buf;
        UnkStruct_4550_row *rows = (UnkStruct_4550_row *)((char *)buf + 8);
        unsigned long id;
        bool found = false;
        if (type == 3) {
            int n = FindCrashStage__26CB3HardCodedCrashStageListFUl(D_01E901F0.field_0);
            sprintf(key, D_004C8FE0, n + 1);
            id = GtIDCompress__FPCc(key);
        } else if (type == 1) {
            id = D_01E901F0.field_0;
        } else {
            id = D_0064D370.field_0;
        }
        int i;
        for (i = 0; i < count; i++) {
            if (id == rows[i].field_0) {
                found = true;
                break;
            }
        }
        if (!found) {
            memset(buf, 0, 0x800);
            self->field_3C->vfunc_C();
            self->field_3C = 0;
            self->field_40 = 0;
            return 0;
        }
        FSeek__13CGTFileSystemFPvii(self->field_3C, rows[i].field_C, 1);
        self->field_44 = rows[i].field_8;
        self->field_40 = 3;
        break;
    }
    case 3:
        self->field_3C->vfunc_10(buf, self->field_44);
        self->field_40 = 4;
        break;
    case 4:
        self->field_3C->vfunc_C();
        self->field_3C = 0;
        self->field_40 = 0;
        return 2;
    }
    return 1;
}
