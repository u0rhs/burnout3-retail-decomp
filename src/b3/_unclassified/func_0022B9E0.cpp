// func_0022B9E0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (local is CB3ControllerMapping*[2]; loop body as one && test).

// func_0022B9E0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

class CB3ControllerMapping;

class CB3InputManager;
struct UnkStruct_0022B9E0_0;

struct UnkStruct_0022B9E0_0 {
    int field_0[1];  // [G] element count unknown
    unsigned char pad_4[0x4];
};

class CB3InputManager {
public:
    void GetAvailableControllers(CB3ControllerMapping**, signed char);
};

extern "C" int func_0012EF40(CB3ControllerMapping *);

extern "C" int func_0022B9E0(CB3InputManager * self)
{
    CB3ControllerMapping * local[2];
    self->GetAvailableControllers(local, -1);
    for (signed char i = 0; i < 2; i++) {
        CB3ControllerMapping * m = local[i];
        if (m != 0 && func_0012EF40(m) != 0) {
            return 1;
        }
    }
    return 0;
}
