// Fix functions whose body absorbed other functions (tail-jump targets added as extra ranges, or a following
// function inside the entry range). TSV: owner_entry <TAB> split_address.
// The owner's body is trimmed to its entry range, cut at the first split inside it; then functions are created at
// the split addresses (last to first). Uses setBody, not removeFunction (removeFunction threw
// ConcurrentModificationException in Ghidra 12.1.4 headless). Names/tags on addresses are kept.
//@category B3Decomp
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import java.io.*;
import java.util.*;

public class SplitFunctions extends GhidraScript {
    @Override
    public void run() throws Exception {
        TreeMap<Long, TreeSet<Long>> splits = new TreeMap<>();
        try (BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream(getScriptArgs()[0]), "UTF-8"))) {
            String line;
            while ((line = br.readLine()) != null) {
                String[] f = line.trim().split("\t");
                if (f.length < 2) continue;
                splits.computeIfAbsent(Long.parseLong(f[0], 16), k -> new TreeSet<>()).add(Long.parseLong(f[1], 16));
            }
        }
        FunctionManager fm = currentProgram.getFunctionManager();
        if (fm.getFunctionTagManager().getFunctionTag("E:split") == null) fm.getFunctionTagManager().createFunctionTag("E:split", "");
        int trimmed = 0, created = 0, existed = 0, failed = 0;
        for (Map.Entry<Long, TreeSet<Long>> e : splits.entrySet()) {
            Address entry = toAddr(e.getKey());
            Function own = fm.getFunctionAt(entry);
            if (own == null) { println("no function at " + entry); failed++; continue; }
            AddressRange er = own.getBody().getRangeContaining(entry);
            if (er == null) { println("entry not in body: " + entry + " body=" + own.getBody()); failed++; continue; }
            Address end = er.getMaxAddress();
            for (Long s : e.getValue()) { Address a = toAddr(s); if (a.compareTo(entry) > 0 && a.compareTo(end) <= 0) { end = a.subtract(1); break; } }
            long before = own.getBody().getNumAddresses();
            try { own.setBody(new AddressSet(entry, end)); trimmed++; }
            catch (Exception ex) { println("setBody failed " + entry + ": " + ex); failed++; continue; }
            for (Long s : e.getValue().descendingSet()) {
                Address a = toAddr(s);
                if (fm.getFunctionAt(a) != null) { existed++; continue; }
                Function in = fm.getFunctionContaining(a);
                if (in != null && !in.getEntryPoint().equals(entry)) {  // trim whoever else holds it as an extra range
                    AddressRange r2 = in.getBody().getRangeContaining(in.getEntryPoint());
                    if (!r2.contains(a)) in.setBody(new AddressSet(r2));
                }
                disassemble(a);
                Function fn = createFunction(a, null);
                if (fn == null) { println("create failed " + a); failed++; continue; }
                fn.addTag("E:split"); created++;
            }
            println(String.format("owner %s: body %d -> %d bytes", entry, before, own.getBody().getNumAddresses()));
        }
        println("SplitFunctions: trimmed=" + trimmed + " created=" + created + " existed=" + existed + " failed=" + failed);
    }
}
