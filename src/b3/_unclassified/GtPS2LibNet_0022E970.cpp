// CGtPS2LibNet::Disconnect() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> GtPS2LibNet.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (switch: case 0 sets 2 and breaks, case 2 break, shared return field_710 tail).

// CGtPS2LibNet::Disconnect() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> GtPS2LibNet.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CGtPS2LibNet;

class CGtPS2LibNet {
public:
    int Disconnect();

    unsigned char pad_0[0x710];
    int field_710;
};

// 0x0022E970
int CGtPS2LibNet::Disconnect()
{
    switch (field_710) {
    case 0:
        field_710 = 2;
        break;
    case 2:
        break;
    case 3:
        field_710 = 0;
        return 3;
    case 4:
        field_710 = 0;
        return 4;
    }
    return field_710;
}
