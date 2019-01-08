package airtel;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.*;

public class FileReader {
    private static final ExecutorService executors = Executors.newFixedThreadPool(20);
    private final Reducer reducer;
    public FileReader(Reducer reducer) {
        this.reducer = reducer;
    }

    public void readFile(List<String> files) throws ExecutionException, InterruptedException {
        List<Future<String>> done = new ArrayList<>();
        for(String file : files) {
            done.add(executors.submit(readFile(file)));
        }
        for(Future<String> f : done) {
            System.out.println("file reading done " + f.get());
        }
        executors.shutdown();
    }

    public List<String> getWolrdList() {
        return reducer.finalCommanWorldList();
    }

    private Callable<String> readFile(String fileName) {
         return () -> {
             try {
                 BufferedReader reader = new BufferedReader(new java.io.FileReader(fileName));
                 String line;
                 while ((line = reader.readLine()) != null) {
                     String[] words = line.split("\\s+");
                     reducer.addWords(words, fileName);
                 }
             } catch (FileNotFoundException e) {
                 throw new RuntimeException("file read fail for " + fileName + "\n" + e);
             } catch (IOException e) {
                 throw new RuntimeException("file read fail for " + fileName + "\n" + e);
             }
             return fileName;
         };
    }
}
