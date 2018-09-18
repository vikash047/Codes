package com.org.competative.programming.DP;

import java.io.*;
import java.util.StringTokenizer;


public class LIS {
    public static void main(String[] args) {
        InputStream input = System.in;
        OutputStream output = System.out;
        InputReader in = new InputReader(input);
        OutPutWritter out = new OutPutWritter(output);
        Solve solve = new Solve();
        solve.solve(in, out);
        out.close();
    }
    static class Solve {
        public void solve(InputReader in, OutPutWritter out) {
            int n = in.readInt();
            int[] a = new int[n];
            for(int i = 0; i < n; i++) a[i] = in.readInt();
            int[] pre = new int[n+1];
            for(int i = 0; i < n; i++) pre[i] = 1;
            int res = 0;
            for(int i = 0; i < n; i++) {
                for(int j = 0; j <= i; j++) {
                    if(a[j] < a[i] && pre[i] < pre[j] + 1) pre[i] = pre[j] + 1;
                }
                res = res < pre[i] ? pre[i] : res;
            }
            for(int i = 0; i < n; i++) out.getWriter().print(pre[i]);
            out.getWriter().println();
            out.getWriter().println(res);
        }
    }

    static class InputReader {
        private BufferedReader reader;
        private StringTokenizer token;

        public InputReader(InputStream input) {
            reader = new BufferedReader(new InputStreamReader(input));
        }

        private String next() {
            while (null == token || !token.hasMoreTokens()) {
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

        public Long readLong() {
            return Long.parseLong(next());
        }

        public Integer readInt() {
            return Integer.parseInt(next());
        }

        public Double readDouble() {
            return Double.parseDouble(next());
        }
    }

    static class OutPutWritter {
        private PrintWriter writer;

        public OutPutWritter(OutputStream output) {
            writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(output)));
        }

        public OutPutWritter(Writer writer) {
            this.writer = new PrintWriter(writer);
        }

        public void print(Object... objects) {
            for (int i = 0; i < objects.length; i++) {
                if (i != 0) {
                    writer.print(' ');
                }
                writer.print(objects[i]);
            }
        }

        public void print(int[] array) {
            for (int i = 0; i < array.length; i++) {
                if (i != 0) writer.print(' ');
                writer.print(array[i]);
            }
        }

        public void print(long[] array) {
            for (int i = 0; i < array.length; i++) {
                if (i != 0) writer.print(' ');
                writer.print(array[i]);
            }
        }

        public void printLine(int[] array) {
            print(array);
            writer.println();
        }

        public void printLine(Object... objects) {
            print(objects);
            writer.println();
        }

        public void printLine(long[] array) {
            print(array);
            writer.println();
        }

        public void close() {
            writer.close();
        }

        public PrintWriter getWriter() {
            return writer;
        }
    }
}
