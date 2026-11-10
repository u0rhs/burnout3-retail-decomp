// Hand-written; the lifter refused it (static member, gp global).

extern "C" int RwRasterRegisterPlugin(int, int, void *, void *, void *);
class CGtTexture {
public:
    static int mgnTextureExtPluginOffset;
    static bool AttachPlugins();
};
// 0x00251680
bool CGtTexture::AttachPlugins()
{
    mgnTextureExtPluginOffset = RwRasterRegisterPlugin(0x38, 0x11F, 0, 0, 0);
    return mgnTextureExtPluginOffset > 0;
}
