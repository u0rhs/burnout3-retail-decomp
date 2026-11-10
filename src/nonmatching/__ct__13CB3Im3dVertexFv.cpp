// NONMATCHING: __ct__13CB3Im3dVertexFv -- retail 9 / ours 3 instructions, 8 in changed runs
// gaps1c: hand-drafted from the asm
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// gaps1c (2026-11-02): hand-drafted from the retail asm (0x130BF0..0x130C10). Name [C]: the mangled symbol in retail's tables
// (research/retail_names.csv: B3DebugManager.cpp, medium). Sets the first quad's w lane to 0 (retail: vsubw.w + vaddx.w
// on the loaded quad, written back whole) and returns this.
// TRACK: clean
// EQUIV: [L] written from the asm: every branch, store and call accounted for

class CB3Im3dVertex {
public:
    CB3Im3dVertex();
    float field_0;
    float field_4;
    float field_8;
    float field_C;
};

// 0x00130BF0
CB3Im3dVertex::CB3Im3dVertex()
{
    field_C = 0.0f;
}
