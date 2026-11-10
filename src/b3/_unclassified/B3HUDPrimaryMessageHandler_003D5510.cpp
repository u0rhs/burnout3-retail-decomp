// CB3HUDPrimaryMessageHandler::ClearMessage(bool) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3HUDPrimaryMessageHandler.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CGt2dObject;

class CB3HUDPrimaryMessageHandler;

class CB3HUDPrimaryMessageHandler {
public:
    void ClearMessage(bool p0);

    int field_0;
    int field_4;
    int field_8;
    void * field_C;
    void * field_10;
    void * field_14;
    unsigned char pad_18[0x134];
    int field_14C;
    float field_150;
    float field_154;
};

extern "C" void DestructObject__10CGt2dSceneFiP11CGt2dObject(void *, int, void *);  // CGt2dScene::DestructObject(int,CGt2dObject*)

// 0x003D5510
void CB3HUDPrimaryMessageHandler::ClearMessage(bool p0)
{
    if (p0) {
        void * t0 = field_C;
        if (t0 != 0) {
            DestructObject__10CGt2dSceneFiP11CGt2dObject((void *)field_0, field_4, (CGt2dObject*)t0);
            field_C = 0;
        }
        void * t1 = field_14;
        if (t1 != 0) {
            DestructObject__10CGt2dSceneFiP11CGt2dObject((void *)field_0, field_4, (CGt2dObject*)t1);
            field_14 = 0;
        }
        void * t2 = field_10;
        if (t2 != 0) {
            DestructObject__10CGt2dSceneFiP11CGt2dObject((void *)field_0, field_8, (CGt2dObject*)t2);
            field_10 = 0;
        }
        field_14C = 3;
    } else {
        float t3 = field_154;
        if (field_150 < t3) {
            field_150 = t3;
        }
    }
}
