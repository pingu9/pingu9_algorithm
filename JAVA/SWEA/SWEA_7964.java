package JAVA.SWEA;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class SWEA_7964 {

    static int N, D, T;
    static int city[] = new int[N];

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        T = Integer.parseInt(br.readLine());
        for (int testCase = 1; testCase <= T; testCase ++) {
            int result = 0;
            String tmp[] = br.readLine().split(" ");
            N = Integer.parseInt(tmp[0]);
            D = Integer.parseInt(tmp[1]);
            
            tmp = br.readLine().split(" ");

            int zeroCount = 0;
            for (int i = 0; i < N; i++) {
                int now = Integer.parseInt(tmp[i]);
                if (now == 0) {
                    zeroCount++;
                    if (zeroCount == D) {
                        zeroCount = 0;
                        result++;
                    }
                }
                if (now == 1) {
                    zeroCount = 0;
                }
            }


            System.out.printf("#%d %d\n", testCase, result);
        }
        

    }

}