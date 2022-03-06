#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int arr[9][9];
vector<pair<int, int>> v;

void init(int cnt)
{
    vector<pair<int, int>>::iterator i = v.begin() + cnt;
    arr[i[0].first][i[0].second] = 0;
}

bool verti_check(int row, int val)
{
    for (int i = 0; i < 9; i++)
    {
        if (arr[row][i] == val)
        {
            return false;
        }
    }
    return true;
}

bool hori_check(int col, int val)
{
    for (int i = 0; i < 9; i++)
    {
        if (arr[i][col] == val)
        {
            return false;
        }
    }
    return true;
}

bool square_check(int row, int col, int val)
{
    int a = row - (row % 3);
    int b = col - (col % 3);

    for (int i = a; i < a + 3; i++)
    {
        for (int j = b; j < b + 3; j++)
        {
            if (arr[i][j] == val)
            {
                return false;
            }
        }
    }

    return true;
}

void backtrack(int cnt)
{
    if (cnt == v.size())
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cout << arr[i][j];
                if (j == 8)
                    cout << '\n';
                else
                    cout << ' ';
            }
        }
        exit(0);
    }

    int row = v[cnt].first;
    int col = v[cnt].second;

    for (int i = 1; i <= 9; i++)
    {
        arr[row][col] = 0;
        if (verti_check(row, i) && hori_check(col, i) && square_check(row, col, i))
        {
            arr[row][col] = i;
            backtrack(cnt + 1);
        }
    }
    init(cnt);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (arr[i][j] == 0)
            {
                v.push_back(make_pair(i, j));
            }
        }
    }

    backtrack(0);
}