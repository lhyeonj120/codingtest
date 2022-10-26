#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int m;

bool isCmp(int n){
    return n >= m;
}

int solution(vector<int> citations) {
    int answer = 0;
    
    for(int idx = 0; idx <= citations.size(); idx++){
        m = idx;
        int up = count_if(citations.begin(), citations.end(), isCmp);
        
        if(up >= idx)
            answer = max(answer, idx);
        else if(up == 0)
            break;
    }
    
    return answer;
}