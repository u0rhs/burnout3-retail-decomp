// Apply transferred retail data names (research/retail_data_names.csv converted to TSV:
// addr name section source size confidence method). high/medium -> primary label (IMPORTED) + EOL comment;
// low/conflict -> pre-comment + bookmark only.
//@category B3Decomp
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import java.io.*;

public class ApplyRetailData extends GhidraScript {
    static String clean(String n) { return n.replaceAll("\\s+", "_"); }
    @Override
    public void run() throws Exception {
        int named = 0, commented = 0, failed = 0;
        SymbolTable st = currentProgram.getSymbolTable(); Listing L = currentProgram.getListing();
        try (BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream(getScriptArgs()[0]), "UTF-8"))) {
            String line;
            while ((line = br.readLine()) != null) {
                String[] f = line.split("\t", -1);
                Address a = toAddr(Long.parseLong(f[0], 16));
                String name = f[1], sec = f[2], src = f[3], size = f[4], conf = f[5], method = f[6];
                String note = name + " (" + sec + ", " + size + " bytes in E, " + src + "; " + conf + ", " + method + ")";
                try {
                    if (conf.equals("high") || conf.equals("medium")) {
                        Symbol s = st.createLabel(a, clean(name), SourceType.IMPORTED);
                        s.setPrimary();
                        L.setComment(a, CodeUnit.EOL_COMMENT, note);
                        named++;
                    } else {
                        L.setComment(a, CodeUnit.PRE_COMMENT, "CANDIDATE DATA NAME (not applied): " + note);
                        createBookmark(a, "B3Decomp", "Unconfirmed data name (" + conf + "): " + name);
                        commented++;
                    }
                } catch (Exception ex) { failed++; }
            }
        }
        println("ApplyRetailData: named=" + named + " commentOnly=" + commented + " failed=" + failed);
    }
}
