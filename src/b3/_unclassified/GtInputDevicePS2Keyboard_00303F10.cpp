// CGtInputDevicePS2Keyboard::GetLEDState() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtInputDevicePS2Keyboard.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (unsigned char result initialised before the call, unsigned short LED local, |= per bit; unsigned char return).

// from build/vt\try_GetLEDState__25CGtInputDevicePS2Keyboard_best.cpp
// CGtInputDevicePS2Keyboard::GetLEDState() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtInputDevicePS2Keyboard.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CGtInputDevicePS2Keyboard;
struct UnkStruct_00303F10_0;

struct UnkStruct_00303F10_0 {
    short field_0;
};

class CGtInputDevicePS2Keyboard {
public:
    unsigned char GetLEDState();

    unsigned char pad_0[0x118];
    int field_118;
};

extern "C" int lgKbdGetLedState(int, unsigned short *);

// 0x00303F10
unsigned char CGtInputDevicePS2Keyboard::GetLEDState()
{
    unsigned short leds = 0;
    unsigned char r = 0;
    if (lgKbdGetLedState(field_118, &leds) == 0) {
        if (leds & 1) r |= 2;
        if (leds & 2) r |= 4;
        if (leds & 4) r |= 8;
        if (leds & 8) r |= 16;
        if (leds & 16) r |= 32;
        return r;
    }
    return 0;
}
