package airtel;

import java.util.HashMap;
import java.util.List;

public class Hash {
    private final HashMap<String, Integer> mapping;
    private static Integer MOD = 101;
    private final Integer totalFiles;
    private String FinalHashForEveryWord = "";
    private String defaultValue = "";

    public Hash(List<String> fileNames) {
        mapping = new HashMap<>();
        totalFiles = fileNames.size();
        for(int i = 0; i < fileNames.size(); i++) {
            mapping.put(fileNames.get(i), i);
            FinalHashForEveryWord += "1";
            defaultValue += "0";
        }
       // System.out.println("final hash value is " + FinalHashForEveryWord);
    }

    public String calculateHash(String fileName, String existingValue) {
        Integer index = mapping.getOrDefault(fileName, -1);
        if(index == -1) {
            throw new IllegalArgumentException("file name is not correct " + fileName);
        }
       // System.out.println("existing value is " + existingValue);
        StringBuilder s = new StringBuilder(existingValue);
        s.setCharAt(index,'1');
        return s.toString();
    }

    public Boolean checkHashExit(String value, String fileName) {
        Integer index = mapping.getOrDefault(fileName, -1);
        if(index == -1) {
            throw new IllegalArgumentException("file name is not correct " + fileName);
        }
        return value.charAt(index) == '1';
    }

    public Boolean checkComman(String value) {
        return FinalHashForEveryWord.equals(value);
    }
    public String defaultValue() {
        return defaultValue;
    }

    /*private Integer calculatePower(Integer a, Integer b) {
        Integer ans = 1;
        while(b > 0) {
            if(b%2 == 1) {
                ans  = (ans%MOD*a%MOD)%MOD;
            }
            a = (a%MOD*a%MOD)%MOD;
            b >>= 1;
        }
        return ans;
    }*/

}
