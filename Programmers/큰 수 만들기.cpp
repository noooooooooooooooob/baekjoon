#include <string>
#include <vector>
using namespace std;

string solution(string number, int k) {
    string answer = "";
    int n = number.size();
    int pick = n - k; // 뽑아야 할 개수
    
    int start = 0;
    for (int i = 0; i < pick; i++) {
        // i번째 숫자는 [start, k+i] 범위에서 최대값 선택
        int maxIdx = start;
        for (int j = start; j <= k + i; j++) {
            if (number[j] > number[maxIdx])
                maxIdx = j;
        }
        answer += number[maxIdx];
        start = maxIdx + 1; // 다음 선택은 maxIdx 이후부터
    }
    
    return answer;
}
