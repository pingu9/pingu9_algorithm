#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K, L;

int board[101][101];
pair<int, char> change_dir[101];

int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

bool wall_collide_check(pair<int, int> head) {
    if (head.first <= 0 || head.first > N || head.second <= 0 || head.second > N) {
        return true;
    }

    return false;
}

bool self_collide_check(vector<pair<int, int>>& v, pair<int, int> head) {

    for (int i = 0; i < v.size() - 1; i++) {
        if (head.first == v[i].first && head.second == v[i].second) {
            return true;
        } 
    }

    return false;
}


int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> K;

    for (int i = 0; i < K; i++) {
        int a, b;
        cin >> a >> b;
        board[a][b] = 1;
    }

    cin >> L;
    for (int i = 0; i < L; i++) {
        int a;
        char c;
        cin >> a >> c;
        change_dir[i] = make_pair(a, c);
    }

    pair<int, char> next_change_info = change_dir[0];
    int next_change_time = next_change_info.first;
    char next_change_dir = next_change_info.second;

    int change_pos = 0;
    int cur_dir_num = 0;

    int res = 0;

    vector<pair<int, int>> v;
    v.push_back(make_pair(1, 1));
    while(1) {
        if (next_change_time == res) {
            if (next_change_dir == 'L') {
                cur_dir_num = (cur_dir_num + 3) % 4;
            }
            if (next_change_dir == 'D') {
                cur_dir_num = (cur_dir_num + 1) % 4;
            }
            change_pos++;
            if (change_pos >= L) {
                next_change_time = -1;
            }
            else {
                next_change_time = change_dir[change_pos].first;
                next_change_dir = change_dir[change_pos].second;
            }
            
        }
        pair<int, int> head = v[v.size() - 1];
        
        pair<int, int> next = make_pair(head.first + dir[cur_dir_num][0], head.second + dir[cur_dir_num][1]);
        
        v.push_back(next);

        if (wall_collide_check(next) || self_collide_check(v, next)){
            break;
        }


        if (board[next.first][next.second] == 1) {
            board[next.first][next.second] = 0;
            
        }
        else if (board[next.first][next.second] == 0) {
            v.erase(v.begin());
        }

        
        res++;
    }

    cout << res + 1 << '\n';
}