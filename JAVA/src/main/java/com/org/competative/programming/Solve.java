package com.org.competative.programming;

import java.io.*;
import java.util.StringTokenizer;

public class Solve {
    public void solve(InputReader in, OutPutWritter out) {

    }
    static class InputReader{
        private BufferedReader reader;
        private StringTokenizer token;
        public InputReader(InputStream input) {
            reader = new BufferedReader(new InputStreamReader(input));
        }

        private String next() {
            while(null == token || !token.hasMoreTokens()) {
                try {
                    token = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return token.nextToken();
        }
        public String readString() {
            return next();
        }
        public Long readLong() { return Long.parseLong(next());}
        public Integer readInt() { return Integer.parseInt(next());}
        public Double readDouble() { return Double.parseDouble(next());}
    }

    static class OutPutWritter {
        private PrintWriter writer;
        public OutPutWritter(OutputStream output) {
            writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(output)));
        }
        public OutPutWritter(Writer writer) {
            this.writer = new PrintWriter(writer);
        }
        public void print(Object ... objects) {
            for(int i = 0; i < objects.length; i++) {
                if(i != 0) {
                    writer.print(' ');
                }
                writer.print(objects[i]);
            }
        }
        public void print(int[] array) {
            for(int i = 0; i < array.length; i++) {
                if(i != 0) writer.print(' ');
                writer.print(array[i]);
            }
        }
        public void print(long[] array) {
            for(int i = 0; i < array.length; i++) {
                if(i != 0) writer.print(' ');
                writer.print(array[i]);
            }
        }
        public void printLine(int[] array) {
            print(array);
            writer.println();
        }
        public void printLine(Object ... objects) {
            print(objects);
            writer.println();
        }
        public void printLine(long[] array) {
            print(array);
            writer.println();
        }
        public void close() { writer.close();}
        public Writer getWriter() { return  writer;}
    }
}
