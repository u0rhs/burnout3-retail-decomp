// CB3InputManager::GetAvailableControllers(CB3ControllerMapping**,signed char) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3InputManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (if (p<0){}else if(FA3[p]){}else{} chain puts found block last).

class CB3ControllerMapping {
public:
    unsigned char pad_0[0x12C];
};

class CB3InputManager {
public:
    void GetAvailableControllers(CB3ControllerMapping **, signed char);

    unsigned char pad_0[0xD48];
    CB3ControllerMapping field_D48[2];
    unsigned char pad_FA0[0xFA1 - 0xD48 - 0x258];
    signed char field_FA1[2];
    unsigned char field_FA3[2];
};

// 0x0022C610
void CB3InputManager::GetAvailableControllers(CB3ControllerMapping **p0, signed char p1)
{
    if (p1 < 0) {
        signed char i;
        for (i = 0; i < 2; i++) {
            p0[i] = &field_D48[i];
        }
    } else if (field_FA3[p1] != 0) {
        signed char i;
        for (i = 0; i < 2; i++) {
            p0[i] = 0;
        }
        p0[field_FA1[p1]] = &field_D48[field_FA1[p1]];
    } else {
        signed char i;
        for (i = 0; i < 2; i++) {
            p0[i] = &field_D48[i];
        }
        for (i = 0; i < 2; i++) {
            if (field_FA3[i] != 0) {
                p0[field_FA1[i]] = 0;
            }
        }
    }
}
