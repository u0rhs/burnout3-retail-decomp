// CB3BehaviourOffset::Destruct() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3BehaviourOffset.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3BehaviourOffset;
class CB3CameraAttribsCar;

class CB3CameraAttribsCar {
public:
    static void Release(unsigned long);
};

class CB3BehaviourOffset {
public:
    void Destruct();

    unsigned char pad_0[0x20];
    unsigned long field_20;
};

// 0x002E2710
void CB3BehaviourOffset::Destruct()
{
    CB3CameraAttribsCar::Release(field_20);
}
