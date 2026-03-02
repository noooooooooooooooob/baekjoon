#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

int map[101];
bool visited[101];
int N, M;

void bfs()
{
    queue<pair<int, int>> q;
    visited[1] = 1;
    q.push({ 1,0 });

    while (!q.empty())
    {
        int x = q.front().first;
        int cnt = q.front().second;
        q.pop();

        for (int i = 1; i <= 6; i++)
        {
            int nx = x + i;
            if (nx > 100)
                continue;
            if (nx == 100)
            {
                cout << cnt + 1;
                return;
            }
            else if (!visited[nx])
            {
                visited[nx] = true;
                if (map[nx] != 0)
                {
                    nx = map[nx];
                    visited[nx] = 1;
                }

                q.push({ nx,cnt + 1 });
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M;

    int x, y;
    for (int i = 0; i < 101; i++)
        map[i] = 0;
    for (int i = 0; i < N + M; i++)
    {
        cin >> x >> y;
        map[x] = y;
    }
    bfs();
    return 0;
}
