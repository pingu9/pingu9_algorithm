#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int A[1000001];
int N, B, C;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    cin >> B >> C;

    long long res = 0;

    for (int i = 0; i < N; i++) {

        res += 1;
        A[i] -= B;

        if (A[i] > 0) {
            res = res + A[i] / C;
            if (A[i] % C != 0) {
                res += 1;
            }
        }
    }

    cout << res << '\n';
}