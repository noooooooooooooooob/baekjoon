#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

// 일반인의 BFS
void BFS(const vector<vector<char>>& arr, vector<vector<bool>>& visited, int N, char color, int startX, int startY) {
    queue<pair<int, int>> q;
    q.push({startX, startY});
    visited[startX][startY] = true;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || nx >= N || ny < 0 || ny >= N)
                continue;
            if (visited[nx][ny] || arr[nx][ny] != color)
                continue;

            visited[nx][ny] = true;
            q.push({nx, ny});
        }
    }
}

// 적록색약용 BFS
void RBFS(const vector<vector<char>>& arr, vector<vector<bool>>& visited, int N, char color, int startX, int startY) {
    queue<pair<int, int>> q;
    q.push({startX, startY});
    visited[startX][startY] = true;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || nx >= N || ny < 0 || ny >= N)
                continue;
            if (visited[nx][ny])
                continue;

            // R-G 같은 색 취급
            bool sameColor = (color == 'R' || color == 'G')
                             ? (arr[nx][ny] == 'R' || arr[nx][ny] == 'G')
                             : (arr[nx][ny] == color);
            if (!sameColor)
                continue;

            visited[nx][ny] = true;
            q.push({nx, ny});
        }
    }
}

int main() {
    int N;
    cin >> N;

    vector<vector<char>> arr(N, vector<char>(N));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> arr[i][j];

    vector<vector<bool>> visited(N, vector<bool>(N, false));
    int normalCount = 0;

    // 일반인 시야
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (!visited[i][j]) {
                BFS(arr, visited, N, arr[i][j], i, j);
                normalCount++;
            }

    // visited 초기화
    fill(visited.begin(), visited.end(), vector<bool>(N, false));
    int colorBlindCount = 0;

    // 적록색약 시야
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (!visited[i][j]) {
                RBFS(arr, visited, N, arr[i][j], i, j);
                colorBlindCount++;
            }

    cout << normalCount << " " << colorBlindCount << '\n';
    return 0;
}
