#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct q_info
{
    int red_pos_y;
    int red_pos_x;
    int blue_pos_y;
    int blue_pos_x;
    int direction;
};

int N, M;

char map[10][10];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int red_pos_y, red_pos_x, blue_pos_y, blue_pos_x;

bool progress_red(int y, int x, int direction)
{
    if (map[y][x] == 'O')
    {
        red_pos_y = y;
        red_pos_x = x;
        return true;
    }
    if (map[y][x] == '#')
    {
        return false;
    }
    if (blue_pos_y == y && blue_pos_x == x)
    {
        return false;
    }
    if (map[y][x] == '.')
    {
        red_pos_y = y;
        red_pos_x = x;
        return (y + dy[direction], x + dx[direction], direction);
    }
    return false;
}

bool progress_blue(int y, int x, int direction)
{
    if (map[y][x] == 'O')
    {
        blue_pos_y = y;
        blue_pos_x = x;
        return true;
    }
    if (map[y][x] == '#')
    {
        return false;
    }
    if (red_pos_y == y && red_pos_x == x)
    {
        return false;
    }
    if (map[y][x] == '.')
    {
        blue_pos_y = y;
        blue_pos_x = x;
        return (y + dy[direction], x + dx[direction], direction);
    }
    return false;
}

bool progress(int r_y, int r_x, int direction, queue<q_info> q)
{
    bool result_red = false;
    bool result_blue = false;
    result_red = progress_red(r_y, r_x, direction);
    result_blue = progress_red(r_y, r_x, direction);
    result_red = progress_red(r_y, r_x, direction);

    if (result_red && result_blue)
    {
        return false;
    }
    if (result_blue)
    {
        return false;
    }
    if (result_red)
    {
        return true;
    }

    for (int i = 0; i < 4; i++)
    {
        struct q_info info;
        info.red_pos_y = red_pos_y;
        info.red_pos_x = red_pos_x;
        info.blue_pos_y = blue_pos_y;
        info.blue_pos_x = blue_pos_x;
        info.direction = i;
        q.push(info);
    }

    return false;
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 'R')
            {
                red_pos_y = i;
                red_pos_x = j;
                map[i][j] = '.';
            }
            if (map[i][j] == 'B')
            {
                blue_pos_y = i;
                blue_pos_x = j;
                map[i][j] = '.';
            }
        }
    }

    queue<q_info> q;

    for (int i = 0; i < 4; i++)
    {
        struct q_info info;
        info.red_pos_y = red_pos_y;
        info.red_pos_x = red_pos_x;
        info.blue_pos_y = blue_pos_y;
        info.blue_pos_x = blue_pos_x;
        info.direction = i;
        q.push(info);
    }

    int level = 0;
    while (!q.empty())
    {
        if (level > 10)
            break;
        for (int i = 0; i < q.size(); i++)
        {
            struct q_info info = q.front();
            q.pop();
            int r_y = info.red_pos_y;
            int r_x = info.red_pos_x;
            int b_y = info.blue_pos_y;
            int b_x = info.blue_pos_x;
            int direction = info.direction;

            if (progress(r_y, r_x, direction, q))
            {
                cout << level << '\n';
                return 0;
            }
        }
        level++;
    }

    cout << -1 << '\n';
}