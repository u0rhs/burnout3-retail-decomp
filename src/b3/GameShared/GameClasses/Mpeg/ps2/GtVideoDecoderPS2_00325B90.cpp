// GtVideoDecoderPS2.cpp (E map). Local fork unit; names from the E map, members without evidence are field_XX.

struct sceMpeg;
struct sceMpegCbData;
struct UnkStruct_c0;  // ring buffer at CGtVideoDecoder+0xc0 (probably the Sony sample ViBuf [G])
extern "C" int viBufRestartDMA(UnkStruct_c0 *);  // 0x325E90

struct CGtVideoDecoder
{
    char _p[0xc0];
    char field_c0[1];
    static int RestartDMA(sceMpeg *, sceMpegCbData *, void *);
};

// 0x325B90
int CGtVideoDecoder::RestartDMA(sceMpeg *, sceMpegCbData *, void *p)
{
    viBufRestartDMA((UnkStruct_c0 *)((CGtVideoDecoder *)p)->field_c0);
    return 1;
}
