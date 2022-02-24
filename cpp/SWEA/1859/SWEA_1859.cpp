#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int price[1000000];
pair<int, int> sorted_price[1000000];

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int T, N;

    cin >> T;

    for (int test_case = 1; test_case <= T; test_case++) {
        long long result = 0;
        cin >> N;
        
        for (int i = 0; i < N; i++) {
            cin >> price[i];
            sorted_price[i] = make_pair(price[i], i);
        }

        sort(sorted_price, sorted_price + N + 5, greater<pair<int, int>>());
        int cur_max = 0;
        for (int i = 0; i < N; i++) {
            while (i >= sorted_price[cur_max].second && cur_max < N) {
                cur_max++;
            }
            int max_price = sorted_price[cur_max].first;
            result += max_price > price[i] ? max_price - price[i] : 0;
        }

        cout << '#' << test_case << ' ' << result << '\n';
    }


}