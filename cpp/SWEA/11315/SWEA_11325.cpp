#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T, N;

char map[20][20];

bool check(int y, int x, int len, int cmd) {
    if (len == 5) {
        return true;
    }
    if (y < 0 || y < 0 || y >= N || x >= N) {
        return false;
    }
    if (map[y][x] != 'o') {
        return false;
    }
    if (cmd == 0) {
        return check(y + 1, x, len + 1, cmd);
    }
    if (cmd == 1) {
        return check(y, x + 1, len + 1, cmd);
    }
    if (cmd == 2) {
        return check(y + 1, x + 1, len + 1, cmd);
    }
    if (cmd == 3) {
        return check(y + 1, x - 1, len + 1, cmd);
    }
    return false;
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    
    cin >> T;

    for (int test_case = 1; test_case <= T; test_case++) {
        string result = "NO";
        cin >> N;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> map[i][j];
            }
        }
        
        bool flag = false;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                for (int k = 0; k < 4; k++) {
                    if (check(i, j, 0, k)) {
                        flag = true;
                        i = N; j = N; k = 4;
                    }
                }
            }
        }

        if (flag) {
            result = "YES";
        }
        cout << '#' << test_case << ' ' << result << '\n';
    }


}