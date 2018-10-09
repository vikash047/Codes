package airtel;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Map;
import java.util.concurrent.ConcurrentHashMap;

public class Reducer {
    private final ConcurrentHashMap<String, String> Words;
    private static final String REGEXFORREMOVINGSPECIALCHAR  = "[^a-zA-Z0-9]";
    private final Hash hash;
    public Reducer(Hash hash) {
        Words = new ConcurrentHashMap();
        this.hash = hash;
    }

    public void addWord(String word, String fileName) {
        String temp = word.replaceAll(REGEXFORREMOVINGSPECIALCHAR, "").toLowerCase();
        //System.out.println(temp);
        //synchronized (Words) {
            if(!Words.contains(temp) || !hash.checkHashExit(Words.get(temp), fileName)) {
                Words.put(temp, hash.calculateHash(fileName, Words.getOrDefault(temp, hash.defaultValue())));
            }
        //}

    }

    public void addWords(String[] word, String fileName) {
        Arrays.asList(word).stream().forEach(f -> addWord(f, fileName));
    }

    public List<String> finalCommanWorldList() {
        List<String> ans = new ArrayList<>();
        for(Map.Entry<String, String> entry : Words.entrySet()) {
            //System.out.println("key is " + entry.getKey() + " and value is " + entry.getValue());
            if(hash.checkComman(entry.getValue())) {
                ans.add(entry.getKey());
            }
        }
        return ans;
    }

}
