#include <algorithm>
#include <vector>
using namespace std;

int parent[101];

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

bool unite(int a, int b) {
    a = find(a); b = find(b);
    if (a == b) return false;  // 이미 같은 집합 (사이클)
    parent[b] = a;
    return true;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;

    for (int i = 0; i < n; i++) parent[i] = i;

    sort(costs.begin(), costs.end(), [](auto& a, auto& b) {
        return a[2] < b[2];  // 비용 오름차순
    });

    for (auto& v : costs) {
        if (unite(v[0], v[1])) {
            answer += v[2];
        }
    }
    return answer;
}
