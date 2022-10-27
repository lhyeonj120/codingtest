#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool visited[50];

bool isPossible(string a, string b){
    int n = 0;
    
    for(int i = 0; i < a.length(); i++)
        if(a[i] != b[i])
            n++;
    if(n == 1)
        return true;
    return false;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    // 문자열, 횟수 담을 큐
    queue<pair<string, int>> q;
    
    auto iter = find(words.begin(), words.end(), target);
    if(iter == words.end())
        return 0;
    
    q.push({begin, 0});
    
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        
        if(cur.first == target){
            answer = cur.second;
            break;
        }
        
        for(int i = 0; i < words.size(); i++){
            if(visited[i])
                continue;
            if(!isPossible(cur.first, words[i]))
                continue;
            q.push({words[i], cur.second + 1});
            visited[i] = true;
        }
    }
    
    return answer;
}