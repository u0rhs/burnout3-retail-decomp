// CB3HUDPrimaryMessageHandler::Update(float) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3HUDPrimaryMessageHandler.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (early return on state 3; fall-through state switch with function-pointer callbacks taking only this; inlined ClearMessage(true) body as static helper; void* handles).

// from build/vt\try_Update__27CB3HUDPrimaryMessageHandlerFf_best.cpp
// CB3HUDPrimaryMessageHandler::Update(float) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3HUDPrimaryMessageHandler.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CGt2dObject;

class CB3HUDPrimaryMessageHandler;

class CB3HUDPrimaryMessageHandler {
public:
    void Update(float p0);

    void * field_0;
    int field_4;
    int field_8;
    void * field_C;
    void * field_10;
    void * field_14;
    unsigned char pad_18[0x134];
    int field_14C;
    float field_150;
    unsigned char pad_154[0x4];
    int (* field_158)(CB3HUDPrimaryMessageHandler *);
    int (* field_15C)(CB3HUDPrimaryMessageHandler *);
    int (* field_160)(CB3HUDPrimaryMessageHandler *);
};

extern "C" void DestructObject__10CGt2dSceneFiP11CGt2dObject(void *, int, void *);  // CGt2dScene::DestructObject(int,CGt2dObject*)

// [L] inlined body of CB3HUDPrimaryMessageHandler::ClearMessage(true) (0x003D5510, defined earlier in the same
// retail file): a static helper here so this unit does not redefine the member.
static inline void func_003D55B0_inl1(CB3HUDPrimaryMessageHandler * h)
{
    if (h->field_C != 0) {
        DestructObject__10CGt2dSceneFiP11CGt2dObject(h->field_0, h->field_4, h->field_C);
        h->field_C = 0;
    }
    if (h->field_14 != 0) {
        DestructObject__10CGt2dSceneFiP11CGt2dObject(h->field_0, h->field_4, h->field_14);
        h->field_14 = 0;
    }
    if (h->field_10 != 0) {
        DestructObject__10CGt2dSceneFiP11CGt2dObject(h->field_0, h->field_8, h->field_10);
        h->field_10 = 0;
    }
    h->field_14C = 3;
}
// 0x003D55B0
void CB3HUDPrimaryMessageHandler::Update(float p0)
{
    if (field_14C == 3) {
        return;
    }
    field_150 += p0;
    switch (field_14C) {
    case 0:
        if (field_158(this) != 0) {
            break;
        }
        field_14C = 1;
    case 1:
        if (field_15C(this) != 0) {
            break;
        }
        field_14C = 2;
    case 2:
        if (field_160(this) != 0) {
            break;
        }
        field_14C = 3;
        func_003D55B0_inl1(this);
        break;
    }
}
