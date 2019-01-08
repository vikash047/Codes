package airtel;

import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.ExecutionException;

public class Main {
    public  static void main(String[] args) throws ExecutionException, InterruptedException {
        List<String> files = new ArrayList<>();
        files.add("C:\\Users\\vikkuma\\Desktop\\VIKASH\\Codes\\JAVA\\src\\main\\java\\airtel\\files\\1.txt");
        files.add("C:\\Users\\vikkuma\\Desktop\\VIKASH\\Codes\\JAVA\\src\\main\\java\\airtel\\files\\2.txt");
        files.add("C:\\Users\\vikkuma\\Desktop\\VIKASH\\Codes\\JAVA\\src\\main\\java\\airtel\\files\\3.txt");
        Hash hash = new Hash(files);
        Reducer reducer = new Reducer(hash);
        FileReader reader = new FileReader(reducer);
        reader.readFile(files);
        List<String> result = reader.getWolrdList();
        for(String word : result) {
            System.out.println("ans is " + word);
        }
        System.out.println("Hello wolrd");
    }
}
