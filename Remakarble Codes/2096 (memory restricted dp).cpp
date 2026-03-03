#include<iostream>
#include<algorithm>
using namespace std;

int N;
int dpmax[3];
int dpmin[3];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;
    
    int row[3];
    for (int j = 0; j < 3; j++)
    {
        cin >> row[j];
        dpmax[j] = row[j];
        dpmin[j] = row[j];
    }

    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < 3; j++)
            cin >> row[j];
        
        int prevMax[3] = {dpmax[0], dpmax[1], dpmax[2]};
        int prevMin[3] = {dpmin[0], dpmin[1], dpmin[2]};
        
        dpmax[0] = max(prevMax[0], prevMax[1]) + row[0];
        dpmax[1] = max({prevMax[0], prevMax[1], prevMax[2]}) + row[1];
        dpmax[2] = max(prevMax[1], prevMax[2]) + row[2];
        
        dpmin[0] = min(prevMin[0], prevMin[1]) + row[0];
        dpmin[1] = min({prevMin[0], prevMin[1], prevMin[2]}) + row[1];
        dpmin[2] = min(prevMin[1], prevMin[2]) + row[2];
    }

    cout << max({dpmax[0], dpmax[1], dpmax[2]});
    cout << " " << min({dpmin[0], dpmin[1], dpmin[2]});
    return 0;
}
