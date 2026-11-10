// Remove IMPORTED non-function labels (and their EOL comments) at the addresses of a previous data-name apply TSV,
// so a corrected data-name table can be applied cleanly. TSV: addr <TAB> name ... (research/retail_data_apply.tsv format).
//@category B3Decomp
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import java.io.*;

public class ClearDataLabels extends GhidraScript {
    @Override
    public void run() throws Exception {
        SymbolTable st = currentProgram.getSymbolTable(); Listing L = currentProgram.getListing(); int removed = 0;
        try (BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream(getScriptArgs()[0]), "UTF-8"))) {
            String line;
            while ((line = br.readLine()) != null) {
                String[] f = line.split("\t", -1);
                Address a = toAddr(Long.parseLong(f[0], 16));
                for (Symbol s : st.getSymbols(a)) {
                    if (s.getSymbolType() == SymbolType.LABEL && s.getSource() == SourceType.IMPORTED) { s.delete(); removed++; }
                }
                L.setComment(a, CodeUnit.EOL_COMMENT, null);
                L.setComment(a, CodeUnit.PRE_COMMENT, null);
                Bookmark b = currentProgram.getBookmarkManager().getBookmark(a, "B3Decomp", "B3Decomp");
                if (b != null) currentProgram.getBookmarkManager().removeBookmark(b);
            }
        }
        println("ClearDataLabels: removed=" + removed);
    }
}
