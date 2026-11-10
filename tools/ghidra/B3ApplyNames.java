// B3ApplyNames.java -- headless Ghidra script: label functions/data from this repo's symbol tables.
// Args: <symbol file> [<symbol file> ...]; lines `name = 0xADDR; // type:func ...` (splat symbol_addrs format).
// Names come from config/ (E map / retail tables / recorded evidence), so the Ghidra view uses the repo's names only.
//@category B3
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.symbol.SourceType;
import java.io.*;
import java.util.regex.*;

public class B3ApplyNames extends GhidraScript {
    @Override
    public void run() throws Exception {
        Pattern p = Pattern.compile("^\\s*(\\w+)\\s*=\\s*0x([0-9A-Fa-f]+)\\s*;(.*)$");
        int funcs = 0, labels = 0;
        for (String path : getScriptArgs()) {
            BufferedReader r = new BufferedReader(new FileReader(path));
            String line;
            while ((line = r.readLine()) != null) {
                Matcher m = p.matcher(line);
                if (!m.matches()) continue;
                Address a = toAddr(Long.parseLong(m.group(2), 16));
                if (currentProgram.getMemory().getBlock(a) == null) continue;
                boolean isFunc = m.group(3).contains("type:func");
                try {
                    if (isFunc) {
                        Function f = getFunctionAt(a);
                        if (f == null) f = createFunction(a, m.group(1));
                        if (f != null) { f.setName(m.group(1), SourceType.USER_DEFINED); funcs++; }
                    } else {
                        createLabel(a, m.group(1), true, SourceType.USER_DEFINED);
                        labels++;
                    }
                } catch (Exception e) { /* duplicate / invalid names: keep Ghidra's */ }
            }
            r.close();
        }
        println("B3ApplyNames: " + funcs + " functions, " + labels + " labels");
    }
}
