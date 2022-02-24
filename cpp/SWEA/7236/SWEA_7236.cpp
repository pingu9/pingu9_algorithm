#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

char map[100][100];

int count_depth(int y, int x)
{
    int cnt = 0;
    bool flag = false;
    for (int i = y - 1; i <= y + 1; i++) {
        for (int j = x - 1; j <= x + 1; j++) {
            if (map[i][j] == 'W' && !(i == y && j == x)) {
                flag = true;
                cnt++;
            }
        }
    }
    if (!flag) {
        if (map[y][x] == 'W') {
            cnt = 1;
        }        
    }
    return cnt;
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int T, N;
    cin >> T;

    for (int test_case = 1; test_case <= T; test_case++) {
        int result = -1;
        cin >> N;
        

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> map[i][j];
            }
        }

        
        for (int i = 1; i < N - 1; i++) {
            for (int j = 1; j < N - 1; j++) {
                int depth = count_depth(i, j);
                if (depth > result) {
                    result = depth;
                }
            }
        }

        cout << '#' << test_case << ' ' << result << '\n';
    }


}