#include <string>
#include <vector>
using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    bool graph[101][101] = {};
    
    for(int i = 1; i <= n; i++)
        graph[i][i] = true;
    
    for(auto& r : results)
        graph[r[0]][r[1]] = true;
    
    // 플로이드-워셜로 전이 관계 완성
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                if(graph[i][k] && graph[k][j])
                    graph[i][j] = true;
    
    // 모든 선수와 승패 관계가 있으면 순위 확정
    for(int i = 1; i <= n; i++)
    {
        bool perfect = true;
        for(int j = 1; j <= n; j++)
        {
            if(i == j) continue;
            if(!graph[i][j] && !graph[j][i])
            {
                perfect = false;
                break;
            }
        }
        if(perfect)
            answer++;
    }
    return answer;
}
