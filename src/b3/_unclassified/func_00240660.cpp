// Hand-written; the lifter refused it (a72: sum=0 hoisted above guard; if (f70>=p0){...} else {return false;} return false; keeps both false blocks separate).

struct UnkStruct_00240660 {
    unsigned char pad_0[0x60];
    float field_60[4];
    int field_70;
    unsigned char pad_74[0x1];
    unsigned char field_75;
};

// 0x00240660
extern "C" bool func_00240660(UnkStruct_00240660 * self, int p0, float p1)
{
    float sum = 0.0f;
    if (self->field_70 >= p0) {
        unsigned char n = self->field_75;
        unsigned char i;
        for (i = 0; i < n; i++) {
            sum += self->field_60[i];
        }
        float avg = sum / n;
        if (avg <= p1) {
            if (avg < -p1) {
                return false;
            }
            return true;
        }
    } else {
        return false;
    }
    return false;
}
