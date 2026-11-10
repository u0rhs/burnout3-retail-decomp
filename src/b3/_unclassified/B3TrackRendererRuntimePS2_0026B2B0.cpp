// CB3TrackRenderer::EndMaterial() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3TrackRendererRuntimePS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (extern C).

struct UnkStruct_026B_a164 { unsigned char pad_0[0x9B]; unsigned char f9B; };
extern "C" void ReallySetMaterial__16CB3TrackRendererFv(void *);
extern "C" void Flush__24CB3TrackRendererSPRCacheFv(void *);
extern void *_gpMeshCache;
extern "C" void EndMaterial__16CB3TrackRendererFv(UnkStruct_026B_a164 *s)
{
    if (s->f9B == 1) {
        ReallySetMaterial__16CB3TrackRendererFv(s);
        Flush__24CB3TrackRendererSPRCacheFv(_gpMeshCache);
    }
}
