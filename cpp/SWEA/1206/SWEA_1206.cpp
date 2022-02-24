#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int T, N;

    for (int test_case = 1; test_case <= 10; test_case++) {
        int result = 0;
        cin >> N;
        int map[1005] = {0, };
        for (int i = 0; i < N; i++) {
            cin >> map[i];
        }

        for (int i = 2; i < N - 2; i++) {
            int temp[4];
            temp[0] = map[i - 2];
            temp[1] = map[i - 1];
            temp[2] = map[i + 1];
            temp[3] = map[i + 2];
            sort(temp, temp + 4);
            if (temp[3] < map[i]) {
                result += map[i] - temp[3];
            } 
        }

        cout << '#' << test_case << ' ' << result << '\n';
    }


}