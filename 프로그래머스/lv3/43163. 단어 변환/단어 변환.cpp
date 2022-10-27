#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool isChange(string s1, string s2){
    int n = 0, length = s1.length();
    for(int i = 0; i < length; i++){
        if(s1[i] != s2[i])
            n++;
        if(n >= 2)
            return false;
    }
    return true;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    // 문자열 담을 큐
    queue<string> q;
    // 문자열, 몇 번째 단계 담을 map
    unordered_map<string, int> cnt;
    
    auto iter = find(words.begin(), words.end(), target);
    if(iter == words.end())
        return 0;
    
    q.push(begin);
    cnt[begin] = 0;
    cnt[target] = -1;
    for(auto word : words)
        cnt[word] = -1;
    
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        
        for(int i = 0; i < words.size(); i++){
            if(cnt[words[i]] >= 0)
                continue;
            if(!isChange(cur, words[i]))
                continue;
            q.push(words[i]);
            cnt[words[i]] = cnt[cur] + 1;
        }
        if(cnt[target] != -1)
            break;
    }
    answer = cnt[target];
    
    return answer;
}