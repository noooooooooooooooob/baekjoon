#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

class charge {
public:
    vector<pair<int,int>> arr; // {도착 도시, 비용}
};

int N, M;
charge charges[1001];
int Dijk[1001];
int startCity, finishCity;

void dijkstra() {
    // {비용, 도시} 최소힙
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, startCity});
    Dijk[startCity] = 0;

    while (!pq.empty()) {
        auto [cost, now] = pq.top();
        pq.pop();

        // 이미 더 짧은 경로로 처리된 경우 스킵
        if (cost > Dijk[now]) continue;

        for (auto [next, nextCost] : charges[now].arr) {
            int newCost = Dijk[now] + nextCost;
            if (Dijk[next] > newCost) {
                Dijk[next] = newCost;
                pq.push({newCost, next});
            }
        }
    }
}

void initialize() {
    for (int i = 1; i <= N; i++) {
        Dijk[i] = 100000000;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    int start, finish, c;
    for (int i = 0; i < M; i++) {
        cin >> start >> finish >> c;
        charges[start].arr.push_back({finish, c});
    }
    cin >> startCity >> finishCity;

    initialize();
    dijkstra();

    cout << Dijk[finishCity] << "\n";
    return 0;
}
