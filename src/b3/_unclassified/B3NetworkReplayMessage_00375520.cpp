// CB3NetworkReplayHeaderMessage::Prepare(const CB3ReplayFileHeader*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3NetworkReplayMessage.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (struct assignment: 6 separate int members + u64 pairs + signed char[6] (no tail pad member)).

extern "C" void Prepare__17CB3NetworkMessageFib(void *, int, bool);
struct UnkStruct_Hdr {
    int field_0; int field_4; int field_8; int field_C; int field_10; int field_14;
    unsigned long field_18[2];
    unsigned long field_28[6];
    signed char field_58[6];
};
class CB3ReplayFileHeader : public UnkStruct_Hdr {};
class CB3NetworkReplayHeaderMessage {
public:
    void Prepare(const CB3ReplayFileHeader *p0);
    unsigned char pad_0[0x10];
    UnkStruct_Hdr field_10;
};
// 0x00375520
void CB3NetworkReplayHeaderMessage::Prepare(const CB3ReplayFileHeader *p0)
{
    field_10 = *p0;
    Prepare__17CB3NetworkMessageFib(this, 18, 1);
}
