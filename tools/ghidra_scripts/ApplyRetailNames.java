// Apply transferred retail names (TSV from tools/make_retail_apply.py: addr name source layer confidence method)
// and create functions at missing entry points (TSV: addr reason).
// high/medium -> function name (IMPORTED) + tags L:<layer> N:<confidence>; low/conflict -> plate comment + bookmark only.
// Missing entry points -> function created, tag "E:missing" (+ reason in plate comment).
//@category B3Decomp
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import java.io.*;

public class ApplyRetailNames extends GhidraScript {
    static String clean(String n) { n = n.replaceAll("\\s+const$", "").replaceAll("\\s+", "_"); return n.isEmpty() ? "_unnamed" : n; }
    void tag(Function fn, String t) throws Exception {
        FunctionTagManager tm = currentProgram.getFunctionManager().getFunctionTagManager();
        if (tm.getFunctionTag(t) == null) tm.createFunctionTag(t, "");
        fn.addTag(t);
    }
    Function ensure(Address a) throws Exception {
        FunctionManager fm = currentProgram.getFunctionManager();
        Function fn = fm.getFunctionAt(a);
        if (fn == null) { disassemble(a); fn = createFunction(a, null); }
        return fn;
    }
    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        int created = 0, createFailed = 0, named = 0, commented = 0, failed = 0;
        // 1. missing entry points first, so names can land on them
        if (args.length > 1) {
            try (BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream(args[1]), "UTF-8"))) {
                String line;
                while ((line = br.readLine()) != null) {
                    String[] f = line.split("\t", -1);
                    Address a = toAddr(Long.parseLong(f[0], 16));
                    boolean existed = currentProgram.getFunctionManager().getFunctionAt(a) != null;
                    Function fn = ensure(a);
                    if (fn == null) { createFailed++; continue; }
                    if (!existed) { created++; tag(fn, "E:missing"); setPlateComment(a, "Entry point added by ApplyRetailNames (" + f[1] + ")"); }
                }
            }
        }
        // 2. names
        try (BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream(args[0]), "UTF-8"))) {
            String line;
            while ((line = br.readLine()) != null) {
                String[] f = line.split("\t", -1);
                Address a = toAddr(Long.parseLong(f[0], 16));
                String raw = f[1], src = f[2], layer = f[3], conf = f[4], method = f[5];
                String plate = raw + "\nSource: " + src + "\nLayer: " + layer + "\nName confidence: " + conf + " (" + method + ", transferred from E/F)";
                if (conf.equals("high") || conf.equals("medium")) {
                    Function fn = ensure(a);
                    if (fn == null) { failed++; continue; }
                    try { fn.setName(clean(raw), SourceType.IMPORTED); } catch (Exception e) { createLabel(a, clean(raw), true, SourceType.IMPORTED); }
                    tag(fn, "L:" + layer); tag(fn, "N:" + conf);
                    setPlateComment(a, plate); named++;
                } else {
                    setPlateComment(a, "CANDIDATE NAME (not applied, " + conf + "):\n" + plate);
                    createBookmark(a, "B3Decomp", "Unconfirmed name (" + conf + "): " + raw); commented++;
                }
            }
        }
        println("ApplyRetailNames: created=" + created + " createFailed=" + createFailed + " named=" + named + " commentOnly=" + commented + " failed=" + failed);
    }
}
