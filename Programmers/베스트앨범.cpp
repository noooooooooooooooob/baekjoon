# 개선 전 버전 #

#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    unordered_map<string,int> genrePlayCnts;
    unordered_map<string,vector<pair<int,int>>> playCnts;
    
    for(int i = 0;i < genres.size();i++)
    {
        genrePlayCnts[genres[i]] += plays[i];
        playCnts[genres[i]].push_back({i, plays[i]});
    }
    
    for(auto& v : playCnts)
    {
        sort(v.second.begin(), v.second.end(), [](pair<int,int> a, pair<int,int> b) {
            return a.second > b.second;
        });
    }
    
    vector<pair<string,int>> genreVector(genrePlayCnts.begin(),genrePlayCnts.end());
    
    sort(genreVector.begin(), genreVector.end(), [](pair<string,int> a, pair<string,int> b) {
		return a.second > b.second;
		});
    
    for(auto& v : genreVector)
    {
        for(auto& mp : playCnts)
        {
            if(mp.first == v.first)
            {
                int cnt = 0;
                for(auto& vc : mp.second)
                {
                    cnt++;
                    answer.push_back(vc.first);
                    if(cnt >= 2)
                        break;
                }
            }
        }
    }
    return answer;
}


# AI 개선 후 버전 #

#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    unordered_map<string, int> genrePlayCnts;
    unordered_map<string, vector<pair<int,int>>> playCnts;
    
    // 1. 장르별 총 재생수 & (고유번호, 재생수) 저장
    for (int i = 0; i < genres.size(); i++) {
        genrePlayCnts[genres[i]] += plays[i];
        playCnts[genres[i]].push_back({i, plays[i]});
    }
    
    // 2. 장르별 노래 정렬: 재생수 내림차순, 같으면 고유번호 오름차순
    for (auto& [genre, songs] : playCnts) {
        sort(songs.begin(), songs.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
            if (a.second == b.second)
                return a.first < b.first;
            return a.second > b.second;
        });
    }
    
    // 3. 장르를 총 재생수 내림차순 정렬
    vector<pair<string,int>> genreVector(genrePlayCnts.begin(), genrePlayCnts.end());
    sort(genreVector.begin(), genreVector.end(), [](const pair<string,int>& a, const pair<string,int>& b) {
        return a.second > b.second;
    });
    
    // 4. 장르 순서대로 상위 2곡 추출
    for (auto& [genre, cnt] : genreVector) {
        auto& songs = playCnts[genre];
        for (int i = 0; i < min((int)songs.size(), 2); i++) {
            answer.push_back(songs[i].first);
        }
    }
    
    return answer;
}
