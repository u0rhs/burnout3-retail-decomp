// Hand-written; the lifter refused it (a163 tiny).

class CB3OfflineSingleCrashLogic { public: bool CanAdjustCameras(); unsigned char pad_0[0x40]; int field_40; };
// 0x00134320
bool CB3OfflineSingleCrashLogic::CanAdjustCameras() { return field_40 == 3; }
