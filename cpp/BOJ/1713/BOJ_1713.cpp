#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

pair<int, int> recommend[101];

int candidate_num = 0;

int find_min_pos()
{
    int mn = 99999999;
    int order_min = 99999999;
    int pos = 0;
    for (int i = 1; i <= 100; i++) {
        if (recommend[i].first) {
            if (recommend[i].first < mn) {
                mn = recommend[i].first;
                order_min = recommend[i].second;
                pos = i;
            }
            else if (recommend[i].first == mn) {
                if (recommend[i].second < order_min) {
                    order_min = recommend[i].second;
                    pos = i;
                }
            }
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

    int order = 1;

    for (int i = 0; i < T; i++) {
        int cur = 0;
        cin >> cur;

        if (recommend[cur].first) {
            recommend[cur].first++;
        }
        else if (candidate_num == N) {
            int pos = find_min_pos();
            recommend[pos].first = 0;
            recommend[cur] = make_pair(1, order++);
        }
        else {
            recommend[cur] = make_pair(1, order++);
            candidate_num++;
        }
        
    }

    int count = N - 1;
    for (int i = 1; i <= 100; i++) {
        if (recommend[i].first) {
            cout << i;
            if (count) {
                cout << ' ';
                count--;
            }
        }
        
    }



}