#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    for (int test_case = 1; test_case <= 10; test_case++) {
        int N;
        cin >> N;
        int table[N][N];
        int res = 0;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> table[i][j];
            }
        }

        
        for (int j = 0; j < N; j++) {
            int state = 0; //0 : default, 1 : 빨간색 하나 있는경우
            for (int i = 0 ; i < N; i++) {
                if (table[i][j] == 1) {
                    state = 1;
                }
                if (table[i][j] == 2) {
                    if (state == 1) {
                        res++;
                        state = 0;
                    }
                }
            }
        }


        cout << '#' << test_case << ' ' << res << '\n';
    }


}