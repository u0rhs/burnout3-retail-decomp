// Apply Metrowerks link-map symbols (TSV: addr size section name source layer subsystem) to the current program.
// Creates functions for .text, labels for other sections, tags functions with layer/subsystem, adds plate comments.
//@category B3Decomp
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import java.io.*;
import java.util.*;

public class ApplyMwMap extends GhidraScript {
    static String clean(String n) {
        n = n.replaceAll("\s+const$", "").replaceAll("\s+", "_");
        return n.isEmpty() ? "_unnamed" : n;
    }
    @Override
    public void run() throws Exception {
        String path = getScriptArgs()[0];
        FunctionManager fm = currentProgram.getFunctionManager();
        SymbolTable st = currentProgram.getSymbolTable();
        Map<String, FunctionTag> tags = new HashMap<>();
        int nf = 0, nl = 0, skipped = 0, failed = 0;
        try (BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream(path), "UTF-8"))) {
            String line;
            while ((line = br.readLine()) != null) {
                String[] f = line.split("\t", -1);
                if (f.length < 7) continue;
                Address a = toAddr(Long.parseLong(f[0], 16));
                long size = Long.parseLong(f[1], 16);
                String sec = f[2], raw = f[3], src = f[4], layer = f[5], sub = f[6];
                if (!currentProgram.getMemory().contains(a)) { skipped++; continue; }
                String name = clean(raw);
                if (sec.equals(".text")) {
                    if (size == 0) { createLabel(a, name, false, SourceType.IMPORTED); nl++; continue; }
                    Function fn = fm.getFunctionAt(a);
                    if (fn == null) {
                        disassemble(a);
                        fn = createFunction(a, name);
                    }
                    if (fn == null) { failed++; createLabel(a, name, true, SourceType.IMPORTED); continue; }
                    try { fn.setName(name, SourceType.IMPORTED); } catch (Exception e) { createLabel(a, name, true, SourceType.IMPORTED); }
                    for (String t : new String[] { "L:" + layer, "S:" + sub }) {
                        FunctionTag ft = tags.get(t);
                        if (ft == null) {
                            ft = fm.getFunctionTagManager().getFunctionTag(t);
                            if (ft == null) ft = fm.getFunctionTagManager().createFunctionTag(t, "");
                            tags.put(t, ft);
                        }
                        fn.addTag(t);
                    }
                    setPlateComment(a, raw + "\nSource: " + src + "\nLayer: " + layer + "  Subsystem: " + sub + "\n(from DNAT_200.MAP)");
                    nf++;
                } else if (sec.equals(".vutext")) {
                    createLabel(a, "vu_" + name, false, SourceType.IMPORTED); nl++;
                } else {
                    createLabel(a, name, false, SourceType.IMPORTED); nl++;
                }
            }
        }
        println("ApplyMwMap: functions=" + nf + " labels=" + nl + " skipped(out of memory)=" + skipped + " failed=" + failed);
    }
}
