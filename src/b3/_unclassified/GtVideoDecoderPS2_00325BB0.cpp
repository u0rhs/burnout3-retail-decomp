// CGtVideoDecoder::StopDMA(sceMpeg*,sceMpegCbData*,void*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtVideoDecoderPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class sceMpeg;
class sceMpegCbData;

class CGtVideoDecoder;

class CGtVideoDecoder {
public:
    int StopDMA(sceMpeg* p0, sceMpegCbData* p1, void* p2);
};

extern "C" int viBufStopDMA(void *, sceMpeg*, sceMpegCbData*, void*);

// 0x00325BB0
int CGtVideoDecoder::StopDMA(sceMpeg* p0, sceMpegCbData* p1, void* p2)
{
    viBufStopDMA(((char *)p1 + 0xC0), p0, p1, p2);
    return 1;
}
