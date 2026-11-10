// Hand-written; the lifter refused it (a163 tiny).

class CGtInputDevicePS2DualShock;
extern "C" int GetPort__26CGtInputDevicePS2DualShockFv(void *);
class CB3ControllerMapping { public: bool PadIsValid(); void *field_0; void *field_4; };
// 0x0012EF50
bool CB3ControllerMapping::PadIsValid() { return GetPort__26CGtInputDevicePS2DualShockFv(field_4) != -1; }
