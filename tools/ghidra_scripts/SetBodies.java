// Set function bodies explicitly (TSV: entry <TAB> last_byte_address). Creates the function if missing.
//@category B3Decomp
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import java.io.*;

public class SetBodies extends GhidraScript {
    @Override
    public void run() throws Exception {
        FunctionManager fm = currentProgram.getFunctionManager(); int ok = 0, bad = 0;
        try (BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream(getScriptArgs()[0]), "UTF-8"))) {
            String line;
            while ((line = br.readLine()) != null) {
                String[] f = line.trim().split("\t"); if (f.length < 2) continue;
                Address a = toAddr(Long.parseLong(f[0], 16)), z = toAddr(Long.parseLong(f[1], 16));
                Function fn = fm.getFunctionAt(a);
                try {
                    if (fn == null) fn = fm.createFunction(null, a, new AddressSet(a, z), ghidra.program.model.symbol.SourceType.ANALYSIS);
                    else fn.setBody(new AddressSet(a, z));
                    println("body " + a + " -> " + fn.getBody()); ok++;
                } catch (Exception ex) { println("failed " + a + ": " + ex); bad++; }
            }
        }
        println("SetBodies: ok=" + ok + " failed=" + bad);
    }
}
