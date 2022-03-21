#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;


int selected[3];

int start_map[8][8];

int max_area = -1;

void arr_copy(int arr1[][8], int arr2[][8]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            arr2[i][j] = arr1[i][j];
        }
    }
}

void dfs(int y, int x, bool visited[][8], int arr[][8]) {
    if (y < 0 || x < 0 || y >= N || x >= M) {
        return;
    } 
    if (visited[y][x]) {
        return;
    }
    visited[y][x] = true;
    if (arr[y][x] == 1) {
        return;
    }
    arr[y][x] = 2;
    dfs(y - 1, x, visited, arr);
    dfs(y + 1, x, visited, arr);
    dfs(y, x - 1, visited, arr);
    dfs(y, x + 1, visited, arr);
}

void convert_coord(int* y, int* x, int num) {
    *y = num / M;
    *x = num % M;
}


void fill(int arr[][8], bool visited[][8]) {
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (arr[i][j] == 2 && !visited[i][j]) {
                dfs(i, j, visited, arr);
            }
        }
    }
}


void combination(int cnt, int next) {
    if (cnt == 3) {


        int arr[8][8];
        bool visited[8][8] = {
            false,
         };

        arr_copy(start_map, arr);

        int y, x;
        for (int i = 0; i < 3; i++) {
            convert_coord(&y, &x, selected[i]);
            if (arr[y][x]) {
                return;
            }
            arr[y][x] = 1;
        }

        fill(arr, visited);



        int area = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (arr[i][j] == 0) {
                    area++;
                }
            }
        }
        if (area > max_area) {
            max_area = area;
        }

        return;
    }

    for (int i = next; i < N * M; i++) {
        selected[cnt] = i;
        combination(cnt + 1, i + 1);
    }
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> start_map[i][j];
        }
    }

    combination(0, 0);

    cout << max_area << '\n';
}