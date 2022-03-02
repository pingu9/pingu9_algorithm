#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int recommend[101];

int candidate_num = 0;

int find_min_pos()
{
    int mn = 99999999;
    int pos = 0;
    for (int i = 1; i <= 100; i++) {
        if (recommend[i] < mn) {
            mn = recommend[i];
            pos = i;
        }
    }

    return pos;
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int N, T;
    cin >> N >> T;

    for (int i = 0; i < T; i++) {
        int cur = 0;
        cin >> cur;

        if (recommend[cur]) {
            recommend[cur]++;
        }
        else if (candidate_num == N) {
            int pos = find_min_pos();
            recommend[pos] = 0;
            recommend[cur] = 1;
        }
        else {
            recommend[cur] = 1;
            candidate_num++;
        }
        
    }

    for (int i = 1; i <= N; i++) {
        if (recommend[i]) {
            cout << i;
            if (i != N) {
                cout << ' ';
            }
        }
        
    }



}