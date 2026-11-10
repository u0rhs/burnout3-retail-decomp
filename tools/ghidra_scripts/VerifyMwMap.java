// Verify map application: per-section hit counts and function stats.
//@category B3Decomp
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import java.io.*;
import java.util.*;

public class VerifyMwMap extends GhidraScript {
    @Override
    public void run() throws Exception {
        FunctionManager fm = currentProgram.getFunctionManager();
        Map<String, int[]> st = new TreeMap<>();
        try (BufferedReader br = new BufferedReader(new FileReader(getScriptArgs()[0]))) {
            String l;
            while ((l = br.readLine()) != null) {
                String[] f = l.split("\t", -1);
                Address a = toAddr(Long.parseLong(f[0], 16));
                int[] c = st.computeIfAbsent(f[2], k -> new int[4]);
                c[0]++;
                if (!currentProgram.getMemory().contains(a)) { c[1]++; continue; }
                if (f[2].equals(".text")) { Function fn = fm.getFunctionAt(a); if (fn != null) c[2]++; else c[3]++; }
            }
        }
        for (var e : st.entrySet()) println("SECTION " + e.getKey() + " total=" + e.getValue()[0] + " outOfMemory=" + e.getValue()[1] + (e.getKey().equals(".text") ? " funcAtAddr=" + e.getValue()[2] + " noFunc=" + e.getValue()[3] : ""));
        int total = 0, def = 0;
        for (Function fn : fm.getFunctions(true)) { total++; if (fn.getName().startsWith("FUN_")) def++; }
        println("FUNCTIONS total=" + total + " unnamed(FUN_)=" + def);
        println("BLOCKS:"); for (var b : currentProgram.getMemory().getBlocks()) println("  " + b.getName() + " " + b.getStart() + "-" + b.getEnd() + " init=" + b.isInitialized());
    }
}
