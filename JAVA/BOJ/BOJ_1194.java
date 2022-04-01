package JAVA.BOJ;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class BOJ_1194 {

	static int N, M;

	static char board[][];
	static boolean visited[][][];
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String line[] = br.readLine().split(" ");
		N = Integer.parseInt(line[0]);
		M = Integer.parseInt(line[1]);
		
		board = new char[N][M];
		visited = new boolean[N][M][64];
		
		Queue<Element> q = new LinkedList<>();
		
		for (int i = 0; i < N; i++) {
			String s = br.readLine();
			board[i] = s.toCharArray();
			
			for (int j = 0; j < M; j++) {
				if (board[i][j] == '0') {
					q.add(new Element(i, j, 0, 0));
				}
			}
		}
		
		
		while (!q.isEmpty()) {
			Element e = q.poll();
			if (e.y < 0 || e.y >= N || e.x < 0 || e.x >= M) {
				continue;
			}	
		
			char cur = board[e.y][e.x];
			if (cur == '1') {
				System.out.println(e.level);
				return;
			}
			
			if (visited[e.y][e.x][e.keyStatus]) {
				continue;
			}
			visited[e.y][e.x][e.keyStatus] = true;
			
			
			int mask = e.keyStatus;
			
			if (cur == '#') {
				continue;
			}
			
			if (cur <= 'F' && cur >= 'A') {
				int num = cur - 'A';
				if ((mask & (1 << num)) == 0) {
					continue;
				}
			}
			
			if (cur <= 'f' && cur >= 'a') {
				int num2 = cur - 'a';
				mask |= (1 << num2);
			}
			
			q.add(new Element(e.y - 1, e.x, e.level + 1, mask));
			q.add(new Element(e.y + 1, e.x, e.level + 1, mask));
			q.add(new Element(e.y, e.x - 1, e.level + 1, mask));
			q.add(new Element(e.y, e.x + 1, e.level + 1, mask));
		}
		
		System.out.println(-1);
		
	
	}
	
	static class Element {
		int y;
		int x;
		int level;
		int keyStatus;
		
		Element(int y, int x, int level, int keyStatus) {
			this.y = y;
			this.x = x;
			this.level = level;
			this.keyStatus = keyStatus;
		}
	}

}
