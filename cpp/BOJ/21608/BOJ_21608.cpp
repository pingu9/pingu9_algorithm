#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int prefer_list[21][4];
int student_order[401];
int map[21][21];
int N;
int cur_y, cur_x;
int blank_count;
int prefer_count;

int check_prefer(int y, int x, int current_student_num)
{
    if (y < 0 || x < 0 || y >= N || x >= N)
    {
        return 0;
    }
    for (int i = 0; i < 4; i++)
    {
        if (map[y][x] == prefer_list[current_student_num][i])
        {
            prefer_count++;
            return 1;
        }
    }
    blank_count++;
    return 0;
}

void fill_map(int current_student_num)
{
    int max_prefer_count = -1;
    int max_blank_count = -1;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int prefer = 0;
            prefer_count = 0;
            blank_count = 0;
            check_prefer(i - 1, j, current_student_num);
            check_prefer(i + 1, j, current_student_num);
            check_prefer(i, j - 1, current_student_num);
            check_prefer(i, j + 1, current_student_num);
            if (prefer_count > max_prefer_count)
            {
                max_prefer_count = prefer_count;
                cur_y = i;
                cur_x = j;
            }
            else if (prefer_count == max_prefer_count)
            {
                if (blank_count > max_blank_count)
                {
                    max_blank_count = blank_count;
                    cur_y = i;
                    cur_x = j;
                }
            }
        }
    }
    cout << cur_y << ' ' << cur_x << '\n';
    map[cur_y][cur_x] = current_student_num;
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;

    for (int i = 0; i < N * N; i++)
    {
        int cur_student;
        cin >> cur_student;
        student_order[i] = cur_student;

        for (int j = 0; j < 4; j++)
        {
            cin >> prefer_list[cur_student][j];
        }
    }

    for (int i = 0; i < N * N; i++)
    {
        fill_map(student_order[i]);
    }

    int score = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int prefer = 0;
            int current_student_num = map[i][j];
            prefer += check_prefer(i - 1, j, current_student_num);
            prefer += check_prefer(i + 1, j, current_student_num);
            prefer += check_prefer(i, j - 1, current_student_num);
            prefer += check_prefer(i, j + 1, current_student_num);
            switch (prefer)
            {
            case 1:
                score += 1;
                break;
            case 2:
                score += 10;
                break;
            case 3:
                score += 100;
                break;
            case 4:
                score += 1000;
                break;
            }
        }
    }

    cout << score << '\n';
}