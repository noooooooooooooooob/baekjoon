#include <string>
#include <vector>
#include <set>
using namespace std;

set<set<int>> results;

bool canBan(string a, string b)
{
    if(a.length() != b.length())
        return false;
    
    for(int i = 0; i < a.length(); i++)
    {
        if(b[i] == '*' || a[i] == b[i])
            continue;
        else
            return false;
    }
    return true;
}

void backtrack(int depth, vector<vector<bool>>& arr, vector<bool>& visited, 
               set<int>& current, int bannedSize, int userSize)
{
    if(depth == bannedSize)
    {
        results.insert(current);
        return;
    }
    
    for(int j = 0; j < userSize; j++)
    {
        if(arr[depth][j] && !visited[j])
        {
            visited[j] = true;
            current.insert(j);
            backtrack(depth+1, arr, visited, current, bannedSize, userSize);
            current.erase(j);
            visited[j] = false;
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    results.clear();
    
    vector<vector<bool>> arr(banned_id.size(), vector<bool>(user_id.size(), false));
    
    for(int i = 0; i < banned_id.size(); i++)
        for(int j = 0; j < user_id.size(); j++)
            if(canBan(user_id[j], banned_id[i]))
                arr[i][j] = true;
    
    vector<bool> visited(user_id.size(), false);
    set<int> current;
    backtrack(0, arr, visited, current, banned_id.size(), user_id.size());
    
    return results.size();
}
