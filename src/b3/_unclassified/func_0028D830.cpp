// Hand-written; the lifter refused it (a122: CB3SoundRaceCar::Update-like; abs.s helper, shared 1914 block after if/else).

static inline float fabsf(float x) { float r; asm("abs.s %0, %1" : "=f"(r) : "f"(x)); return r; }
struct UnkStruct_0028D830_car {
    unsigned char pad_0[0x10B3];
    unsigned char field_10B3;
    unsigned char pad_10B4[0x12A];
    unsigned char field_11DE;
    unsigned char pad_11DF[0x161];
    float field_1340;
    unsigned char pad_1344[0x5D0];
    int field_1914;
};
struct UnkStruct_0028D830_voice { unsigned char pad_0[0x10]; };
struct UnkStruct_0028D830_self {
    unsigned char pad_0[8];
    unsigned char field_8[0x64];
    UnkStruct_0028D830_voice *field_6C;
    UnkStruct_0028D830_voice *field_70;
    unsigned char pad_74[0x1C];
    float field_90;
    float field_94;
    unsigned char pad_98[0x24];
    unsigned char field_BC;
};
struct UnkStruct_D_00522680 { float field_0; unsigned char pad_4[12]; };
struct UnkStruct_D_004F509C { float field_0; unsigned char pad_4[12]; };
extern UnkStruct_D_00522680 D_00522680;
extern UnkStruct_D_004F509C D_004F509C;
extern float D_004E06B8;
extern float D_004E06EC;
extern float D_004E06CC;
extern "C" void Update__17CB3SoundSkidModelFPC10CB3RaceCar(void *, UnkStruct_0028D830_car *);
extern "C" void ForgetMe__20CGtSoundVirtualVoiceFf(void *, float);
extern "C" void func_0028CF00(UnkStruct_0028D830_self *, UnkStruct_0028D830_car *);
extern "C" void func_0028D1A0(UnkStruct_0028D830_self *, UnkStruct_0028D830_car *);
extern "C" void StartBoost__15CB3SoundRaceCarFPC10CB3RaceCar(UnkStruct_0028D830_self *, UnkStruct_0028D830_car *);
extern "C" void UpdateBoostIn__15CB3SoundRaceCarFPC10CB3RaceCar(UnkStruct_0028D830_self *, UnkStruct_0028D830_car *);
extern "C" void UpdateHorn__15CB3SoundRaceCarFP10CB3RaceCar(UnkStruct_0028D830_self *, UnkStruct_0028D830_car *);
// 0x0028D830
extern "C" void func_0028D830(UnkStruct_0028D830_self *self, UnkStruct_0028D830_car *car)
{
    Update__17CB3SoundSkidModelFPC10CB3RaceCar(&self->field_8, car);
    float f = self->field_94;
    if (f < 1.0f) {
        self->field_94 = f + D_004F509C.field_0 / 5.0f;
    }
    if (car->field_11DE != 0) {
        StartBoost__15CB3SoundRaceCarFPC10CB3RaceCar(self, car);
        func_0028CF00(self, car);
        self->field_90 = 0.0f;
    } else {
        if (self->field_90 == 0.0f) {
            func_0028D1A0(self, car);
        }
        if (D_00522680.field_0 < self->field_90) {
            if (self->field_6C != 0) {
                func_0028CF00(self, car);
            }
        } else {
            if (self->field_6C != 0) {
                ForgetMe__20CGtSoundVirtualVoiceFf(self->field_6C, D_004E06B8);
                self->field_6C = 0;
            }
            if (self->field_70 != 0) {
                ForgetMe__20CGtSoundVirtualVoiceFf(self->field_70, D_004E06B8);
                self->field_70 = 0;
            }
            self->field_90 = 0.0f;
        }
    }
    if (car->field_1914 == 0 && car->field_10B3 != 0) {
        float d = car->field_1340 - D_00522680.field_0;
        if (fabsf(d) < D_004E06EC) {
            self->field_90 = D_004E06CC + D_00522680.field_0;
            StartBoost__15CB3SoundRaceCarFPC10CB3RaceCar(self, car);
        }
    }
    if (car->field_11DE == 0) {
        self->field_BC = 1;
    }
    UpdateBoostIn__15CB3SoundRaceCarFPC10CB3RaceCar(self, car);
    UpdateHorn__15CB3SoundRaceCarFP10CB3RaceCar(self, car);
}
