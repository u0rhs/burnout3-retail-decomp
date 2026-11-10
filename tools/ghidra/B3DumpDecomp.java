// B3DumpDecomp.java -- headless Ghidra script: write the decompiler's pseudo-C for listed functions.
// Args: <out dir> <list file>; the list holds one `0xADDR [name]` per line. Output: <out dir>/<ADDR>.c
// The pseudo-C is a reading aid / starting draft for hand matching (ghidra-emotionengine-reloaded decodes the
// EE's MMI and VU0 macro instructions), never a source of names: rename everything to the repo's conventions.
//@category B3
import ghidra.app.decompiler.*;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import java.io.*;

public class B3DumpDecomp extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        File out = new File(args[0]);
        out.mkdirs();
        DecompInterface ifc = new DecompInterface();
        DecompileOptions opt = new DecompileOptions();
        ifc.setOptions(opt);
        ifc.openProgram(currentProgram);
        BufferedReader r = new BufferedReader(new FileReader(args[1]));
        String line;
        int ok = 0, bad = 0;
        while ((line = r.readLine()) != null) {
            line = line.trim();
            if (line.isEmpty()) continue;
            String[] parts = line.split("\\s+");
            Address a = toAddr(Long.decode(parts[0]));
            Function f = getFunctionAt(a);
            if (f == null) f = createFunction(a, null);
            if (f == null) { bad++; continue; }
            DecompileResults res = ifc.decompileFunction(f, 120, monitor);
            String c = res.decompileCompleted() ? res.getDecompiledFunction().getC() : "// decompile failed: " + res.getErrorMessage();
            PrintWriter w = new PrintWriter(new File(out, String.format("%08X.c", a.getOffset())));
            w.println("// Ghidra 12.1.4 + ghidra-emotionengine-reloaded pseudo-C for " + f.getName() + " @ " + a);
            w.println("// Reading aid only: names here are Ghidra's or the repo's (B3ApplyNames); never adopt Ghidra-invented names.");
            w.print(c);
            w.close();
            ok++;
        }
        r.close();
        ifc.dispose();
        println("B3DumpDecomp: " + ok + " written, " + bad + " without a function");
    }
}
