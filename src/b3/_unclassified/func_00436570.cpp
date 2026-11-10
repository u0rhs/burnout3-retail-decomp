// func_00436570 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (sceScfGetAspect takes no args; enum return type keeps the branch form (int/bool give xori/sltiu)).

extern "C" int sceScfGetAspect(void);  // Sony libscf, takes no arguments (phantom a0-t3 dropped)
// [G] the return type is an enum (placeholder): an int or bool return compiles to xori/sltiu, an enum keeps retail's branches
enum UnkEnum_00436570 { UnkEnum_00436570_0, UnkEnum_00436570_1 };

// 0x00436570
extern "C" UnkEnum_00436570 func_00436570()
{
    if (sceScfGetAspect() == 2) {
        return UnkEnum_00436570_1;
    }
    return UnkEnum_00436570_0;
}
