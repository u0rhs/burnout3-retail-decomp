// B3SoundPlayerCar.cpp (E map). Local fork unit; names from the E map, members without evidence are field_XX.

struct CB3SoundTurboModel
{
    void Destruct();
};

struct CB3SoundRaceCar
{
    void Destruct();
};

struct CB3SoundPlayerCar : CB3SoundRaceCar
{
    char _p[0x144];
    CB3SoundTurboModel field_144;  // member type from the call target
    void Destruct();
};

// 0x28CA50
void CB3SoundPlayerCar::Destruct()
{
    field_144.Destruct();
    CB3SoundRaceCar::Destruct();
}
