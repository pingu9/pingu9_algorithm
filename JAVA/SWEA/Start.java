package JAVA.SWEA;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Start {

    static int T;
    
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        T = Integer.parseInt(br.readLine());
        for (int testCase = 1; testCase <= T; testCase ++) {
            int result = 0;

            System.out.printf("#%d %d\n", testCase, result);
        }

    }

}