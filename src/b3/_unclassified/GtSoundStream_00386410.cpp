// CGtSoundStream::Update() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtSoundStream.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a130: do{ if(pos<X) pos=X; }while(pos<X) via float& pos; if(s==3) after the if(field_1C4) block).

struct UnkStruct_00386410_p { int field_0; int field_4; float field_8; int field_C; };
class CGtVideoDecoder {
public:
    void SetExternalSync(float p0);
};
class CGtSoundStream {
public:
    void Update();
    void ApplyVolumesAndPitch();
    unsigned char pad_0[0x1C4];
    CGtVideoDecoder *field_1C4;
    float field_1C8;
    int field_1CC;
    int field_1D0;
    unsigned char pad_1D4[0x20];
    unsigned char field_1F4;
};
extern float D_004E0CAC;
extern "C" int _rwaStreamGetStatus(int);
extern "C" void _rwaStreamGetStreamPos(int, void *);
// 0x00386410
void CGtSoundStream::Update()
{
    if (field_1F4 == 0) {
        return;
    }
    int s = _rwaStreamGetStatus(field_1CC);
    if (s == 9 || s == 2 || s == 0) {
        return;
    }
    switch (field_1D0) {
    case 1:
        field_1C8 = -1.0f;
        if (s == 5) {
            field_1D0 = 2;
        }
        break;
    case 5:
        if (s == 3) {
            field_1D0 = 4;
        }
        break;
    case 8:
        if (s == 5) {
            field_1D0 = 7;
        }
        break;
    case 6:
        if (field_1C4 != 0) {
            UnkStruct_00386410_p p;
            p.field_4 = 3;
            p.field_C = 1;
            _rwaStreamGetStreamPos(field_1CC, &p);
            float k = D_004E0CAC;
            float &pos = p.field_8;
            do {
                if (pos < field_1C8 + k) {
                    pos = field_1C8 + k;
                }
            } while (pos < field_1C8 + k);
            field_1C8 = pos;
            field_1C4->SetExternalSync(pos);
        }
        if (s == 3) {
            field_1D0 = 4;
        }
        break;
    case 4:
        break;
    }
    ApplyVolumesAndPitch();
}
