// Hand-written; the lifter refused it (hint==1 nest with return 0 last; Construct's status-update inline after lgAudClose).

class CGtLogitechHeadset {
public:
    int HaveHeadsetsChanged();

    char * field_0;
    int field_4;
    char * field_8;
    int field_C;
    int field_10;
    unsigned char pad_14[0x10];
    int field_24;
    unsigned char pad_28[0x154];
    int field_17C;
    int field_180;
};

extern "C" int lgAudEnumHint(int *);
extern "C" int lgAudClose(int);

// 0x002C2600
int CGtLogitechHeadset::HaveHeadsetsChanged()
{
    int hint = 1;
    lgAudEnumHint(&hint);
    if (hint == 1) {
        if (field_17C != -1) {
            lgAudClose(field_17C);
            field_17C = -1;
            // same status update as CGtLogitechHeadset::Construct (inlined; name unknown)
            if (field_17C != -1 && field_180 != 0) {
                field_10 = 2;
            } else if (field_17C == -1) {
                field_10 = 0;
            } else if (field_180 == 0) {
                field_10 = 1;
            }
        }
        return 1;
    }
    return 0;
}
