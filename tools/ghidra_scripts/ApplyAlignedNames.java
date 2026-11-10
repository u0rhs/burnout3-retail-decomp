// Apply aligned, audited names (TSV: elf_addr size name source layer subsystem class).
// verified/boundary -> function name (IMPORTED) + tags; inferred/conflict -> comment + bookmark only.
//@category B3Decomp
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import java.io.*;

public class ApplyAlignedNames extends GhidraScript {
    static String clean(String n) { n = n.replaceAll("\s+const$", "").replaceAll("\s+", "_"); return n.isEmpty() ? "_unnamed" : n; }
    void tag(Function fn, String t) throws Exception {
        FunctionTagManager tm = currentProgram.getFunctionManager().getFunctionTagManager();
        if (tm.getFunctionTag(t) == null) tm.createFunctionTag(t, "");
        fn.addTag(t);
    }
    @Override
    public void run() throws Exception {
        FunctionManager fm = currentProgram.getFunctionManager();
        int named = 0, commented = 0, failed = 0;
        try (BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream(getScriptArgs()[0]), "UTF-8"))) {
            String line;
            while ((line = br.readLine()) != null) {
                String[] f = line.split("\t", -1);
                Address a = toAddr(Long.parseLong(f[0], 16));
                String raw = f[2], src = f[3], layer = f[4], sub = f[5], cls = f[6];
                String plate = raw + "\nSource: " + src + "\nLayer: " + layer + "  Subsystem: " + sub + "\nName confidence: " + cls + " (aligned from E link maps)";
                if (cls.equals("verified") || cls.equals("boundary")) {
                    Function fn = fm.getFunctionAt(a);
                    if (fn == null) { disassemble(a); fn = createFunction(a, null); }
                    if (fn == null) { failed++; continue; }
                    try { fn.setName(clean(raw), SourceType.IMPORTED); } catch (Exception e) { createLabel(a, clean(raw), true, SourceType.IMPORTED); }
                    tag(fn, "L:" + layer); tag(fn, "S:" + sub); tag(fn, "N:" + cls);
                    setPlateComment(a, plate); named++;
                } else {
                    setPlateComment(a, "CANDIDATE NAME (not applied, " + cls + "):\n" + plate);
                    createBookmark(a, "B3Decomp", "Unconfirmed name (" + cls + "): " + raw); commented++;
                }
            }
        }
        println("ApplyAlignedNames: named=" + named + " commentOnly=" + commented + " failed=" + failed);
    }
}
