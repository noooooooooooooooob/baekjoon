#include <string>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> solution(vector<string> gems) {
    set<string> gemsSet(gems.begin(), gems.end());
    int total = gemsSet.size();
    int n = gems.size();

    unordered_map<string, int> window;
    int left = 0;
    int ansLeft = 0, ansRight = n - 1;

    for (int right = 0; right < n; right++)
    {
        // 오른쪽 확장
        window[gems[right]]++;

        // 윈도우가 모든 보석을 포함하면 왼쪽 줄이기
        while (window.size() == total)
        {
            if (right - left < ansRight - ansLeft)
            {
                ansLeft = left;
                ansRight = right;
            }
            window[gems[left]]--;
            if (window[gems[left]] == 0)
                window.erase(gems[left]);
            left++;
        }
    }

    return {ansLeft + 1, ansRight + 1};
}
