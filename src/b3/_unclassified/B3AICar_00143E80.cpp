// CB3AICar::Construct(int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3AICar.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a72: four -1 -> 0 monitor-id guards, raw self-referential pointer stores in retail order; p0 unused).

class CB3AICar;

class CB3AICar {
public:
    void Construct(int p0);

    unsigned char pad_0[0x1914];
    int field_1914;
    unsigned char pad_1918[0xD8];
    void * field_19F0;
    void * field_19F4;
    void * field_19F8;
    unsigned char pad_19FC[0x744];
    void * field_2140;
    void * field_2144;
    void * field_2148;
    unsigned char pad_214C[0x4];
    void * field_2150;
    void * field_2154;
    unsigned char pad_2158[0x38];
    void * field_2190;
    unsigned char pad_2194[0x2C0];
    int field_2454;
};

extern int _gnAITotalMonitorID;
extern int _gnRaceCarMonitorID;
extern int _gnAIMonitorID;
extern int _gnAICarMonitorID;
extern "C" void Construct__11CB3AIDriverFv(void *);
extern "C" void Construct__10CB3RaceCarFv(void *);

// 0x00143E80
void CB3AICar::Construct(int p0)
{
    if (_gnAITotalMonitorID == -1) {
        _gnAITotalMonitorID = 0;
    }
    if (_gnRaceCarMonitorID == -1) {
        _gnRaceCarMonitorID = 0;
    }
    if (_gnAIMonitorID == -1) {
        _gnAIMonitorID = 0;
    }
    if (_gnAICarMonitorID == -1) {
        _gnAICarMonitorID = 0;
    }
    field_2454 = 0;
    Construct__11CB3AIDriverFv(&field_19F0);
    field_2190 = this;
    void * t = &field_19F0;
    field_2150 = this;
    field_2154 = t;
    field_19F0 = t;
    field_19F4 = this;
    field_19F8 = t;
    field_2140 = t;
    field_2144 = this;
    field_2148 = t;
    Construct__10CB3RaceCarFv(this);
    field_1914 = 1;
    field_2454 = 1;
}
