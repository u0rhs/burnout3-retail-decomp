// Export per-function features for cross-build matching: entry, size, name, raw words, ordered call targets, referenced strings.
// Output: JSON lines to the path given as first script arg.
//@category B3Decomp
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.mem.*;
import ghidra.program.model.symbol.*;
import java.io.*;

public class ExportFeatures extends GhidraScript {
    static String esc(String s) { return s.replace("\\", "\\\\").replace("\"", "\\\"").replace("\n", "\n").replace("\r", "").replace("\t", " "); }
    @Override
    public void run() throws Exception {
        Listing L = currentProgram.getListing(); Memory mem = currentProgram.getMemory();
        ReferenceManager rm = currentProgram.getReferenceManager();
        try (PrintWriter pw = new PrintWriter(new OutputStreamWriter(new FileOutputStream(getScriptArgs()[0]), "UTF-8"))) {
            for (Function fn : currentProgram.getFunctionManager().getFunctions(true)) {
                Address e = fn.getEntryPoint(); AddressSetView full = fn.getBody();
                // extent = entry .. end of the last body range that starts before the next function's entry.
                // Ghidra splits normal MW functions into several ranges (unreachable gaps), so the entry range alone
                // is too short (checked against E's map: wrong for 697/699); but ranges at or beyond the next
                // function (tail-jump targets added to the body) must not count, or the extent spans other functions.
                Function nxt = getFunctionAfter(e);  // FlatProgramAPI
                Address lim = nxt == null ? null : nxt.getEntryPoint();
                Address max = null;
                for (AddressRange r : full) {
                    if (r.getMinAddress().compareTo(e) < 0) continue;
                    if (lim != null && r.getMinAddress().compareTo(lim) >= 0) continue;
                    Address m = r.getMaxAddress();
                    if (lim != null && m.compareTo(lim) >= 0) m = lim.subtract(1);
                    if (max == null || m.compareTo(max) > 0) max = m;
                }
                if (max == null) continue;
                AddressSet body = new AddressSet(e, max).intersect(full);
                long size = max.subtract(e) + 1;
                if (size <= 0 || size > 0x40000) continue;
                byte[] b = new byte[(int) size];
                try { mem.getBytes(e, b); } catch (Exception ex) { continue; }
                StringBuilder hex = new StringBuilder(); for (byte x : b) hex.append(String.format("%02x", x & 0xff));
                StringBuilder calls = new StringBuilder(), strs = new StringBuilder();
                for (Instruction ins : L.getInstructions(body, true)) {
                    for (Reference r : ins.getReferencesFrom()) {
                        if (r.getReferenceType().isCall()) { if (calls.length() > 0) calls.append(','); calls.append("\"").append(r.getToAddress()).append("\""); }
                        else if (r.getReferenceType().isData()) {
                            Data d = L.getDataAt(r.getToAddress());
                            if (d != null && d.hasStringValue()) { if (strs.length() > 0) strs.append(','); strs.append("\"").append(esc(String.valueOf(d.getValue()))).append("\""); }
                        }
                    }
                }
                pw.println("{\"entry\":\"" + e + "\",\"size\":" + size + ",\"name\":\"" + esc(fn.getName()) + "\",\"src\":\"" + fn.getSymbol().getSource() + "\",\"bytes\":\"" + hex + "\",\"calls\":[" + calls + "],\"strings\":[" + strs + "]}");
            }
        }
        println("ExportFeatures done");
    }
}
