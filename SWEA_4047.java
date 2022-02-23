
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class SWEA_4047 {

    static boolean S[] = new boolean[14];
    static boolean D[] = new boolean[14];
    static boolean H[] = new boolean[14];
    static boolean C[] = new boolean[14];

    static int sCount = 13;
    static int dCount = 13;
    static int hCount = 13;
    static int cCount = 13;

    static int T;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        T = Integer.parseInt(br.readLine());
        for (int i = 0; i < T; i++) {
            S = new boolean[14];
            D = new boolean[14];
            H = new boolean[14];
            C = new boolean[14];
            sCount = 13;
            dCount = 13;
            hCount = 13;
            cCount = 13;

            char[] letters = br.readLine().toCharArray();
            boolean flag = true;
            for (int j = 0; j < letters.length / 3; j++) {
                char first = letters[3 * j];
                int second = letters[3 * j + 1] - '0';
                int third = letters[3 * j + 2] - '0';
                int value = second * 10 + third;
                if (first == 'S') {
                    if (S[value]) {
                        flag = false;
                    } else {
                        S[value] = true;
                        sCount--;
                    }
                }
                if (first == 'D') {
                    if (D[value]) {
                        flag = false;
                    } else {
                        D[value] = true;
                        dCount--;
                    }
                }
                if (first == 'H') {
                    if (H[value]) {
                        flag = false;
                    } else {
                        H[value] = true;
                        hCount--;
                    }
                }
                if (first == 'C') {
                    if (C[value]) {
                        flag = false;
                    } else {
                        C[value] = true;
                        cCount--;
                    }
                }

            }

            System.out.printf("#%d ", i + 1);

            if (flag) {
                System.out.printf("%d ", sCount);
                System.out.printf("%d ", dCount);
                System.out.printf("%d ", hCount);
                System.out.printf("%d\n", cCount);
            } else {
                System.out.println("ERROR");
            }
        }

    }

}