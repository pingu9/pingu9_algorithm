package JAVA.SWEA;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class SWEA_2805 {

	static int T;
	static int N;
	
	static int arr[][];
	static int answer;
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		T = Integer.parseInt(br.readLine());
		
		for (int i = 0; i < T; i++) {
			N = Integer.parseInt(br.readLine());
			arr = new int[N][N];
			answer = 0;
			
			for (int j = 0; j < N; j++) {
				char[] lineChars = br.readLine().toCharArray();
				for (int k = 0; k < N; k++) {
					arr[j][k] = lineChars[k] - '0';
				}
			}
			
			spread(0, N/2, 1, 1);
			System.out.printf("#%d %d\n", i + 1, answer);
			

		}
	}

	
	public static void spread(int y, int x, int direction, int level) {

		int loopCount = direction == 1 ? N / 2  + 1 : N / 2;
		
		if (level > N) {
			return;
		}
		
		for (int i = 0; i < loopCount; i++) {
			answer += arr[y + i][x - i];
		}
		
		if (direction == 1) {
			spread(y + 1, x, -1, level + 1);
		}
		if (direction == -1) {
			spread(y, x + 1, 1, level + 1);
		}
	}
	
	
}
