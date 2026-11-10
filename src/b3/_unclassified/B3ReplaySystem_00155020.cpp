// CB3ReplaySystem::NextFrame(CDrivingControls*,bool) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3ReplaySystem.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (rewritten: frame/crash-frame locals (declared frame first), split GetSpaceFree guard per mode, bool Retrieve result).

class CDrivingControls;
class CGtByteStream {
public:
    int GetSpaceFree() const;
    void ReadMemory(void*, int);
    int GetPosition() const;
    void SetPosition(int);
    void WriteMemory(const void*, int);
};
class CB3ReplayFrame {
public:
    void ArchiveDrivingControls(CDrivingControls*, unsigned char);
    bool RetrieveDrivingControls(CDrivingControls*);
    unsigned char field_0[3];
};
class CB3CrashReplayFrame {
public:
    void ArchiveDrivingControls(CDrivingControls*, unsigned char);
    bool RetrieveDrivingControls(CDrivingControls*);
    unsigned char field_0[8];
};
class CB3ReplaySystem {
public:
    int NextFrame(CDrivingControls* p0, bool p1);
    unsigned char pad_0[0x60];
    CGtByteStream field_60;
    unsigned char pad_61[0x1B];
    int field_7C;
    int field_80;
    unsigned char field_84;
};
extern "C" void * memset(void *, int, unsigned int);

// 0x00155020
int CB3ReplaySystem::NextFrame(CDrivingControls* p0, bool p1)
{
    CB3ReplayFrame frame;
    CB3CrashReplayFrame crash;
    if (p1) {
        if ((unsigned int)field_60.GetSpaceFree() < 8) return 0;
        field_60.ReadMemory(&crash, 8);
    } else {
        if ((unsigned int)field_60.GetSpaceFree() < 3) return 0;
        field_60.ReadMemory(&frame, 3);
    }
    if (field_84 == 0) {
        if (p1) {
            field_60.SetPosition(field_60.GetPosition() - 8);
            crash.ArchiveDrivingControls(p0, 0);
            field_60.WriteMemory(&crash, 8);
        } else {
            field_60.SetPosition(field_60.GetPosition() - 3);
            frame.ArchiveDrivingControls(p0, 0);
            field_60.WriteMemory(&frame, 3);
        }
        field_80++;
    }
    memset(p0, 0, 32);
    bool r;
    if (p1) r = crash.RetrieveDrivingControls(p0);
    else r = frame.RetrieveDrivingControls(p0);
    field_7C++;
    if (r) return 0;
    return 1;
}
