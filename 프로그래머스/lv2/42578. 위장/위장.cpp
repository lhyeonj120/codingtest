#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool cmp(vector<string> v1, vector<string> v2){
    return v1[1] > v2[1];
}

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> m;
    
    sort(clothes.begin(), clothes.end(), cmp);
    int cnt = 1;
    
    for(int i = 0; i < clothes.size() - 1; i++){
        if(clothes[i][1] == clothes[i + 1][1])
            cnt++;
        else{
            m.insert({clothes[i][1], cnt});
            cnt = 1;
        }
    }
    m.insert({clothes[clothes.size() - 1][1], cnt});
    
    for(auto iter = m.begin(); iter != m.end(); iter++)
        answer *= iter->second + 1;
    
    return answer - 1;
}