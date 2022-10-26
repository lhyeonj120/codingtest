#include <string>
#include <vector>
#include <queue>

using namespace std;

int visited[201];

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    queue<int> q;
    
    while(true){
        int idx = -1;
        // 방문 안 한 노드 확인
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                idx = i;
                visited[i] = ++answer;
                break;
            }
        }
        // 모든 노드 방문 완료
        if(idx == -1)
            break;
        // 연결된 노드 확인
        else{
            q.push(idx);
            
            while(!q.empty()){
                auto cur = q.front();
                q.pop();
                
                for(int i = 0; i < n; i++){
                    // 자기 자신 노드일 때 || 이미 방문한 노드일 때 || 연결 안된 노드일 때
                    if(cur == i || visited[i] || computers[cur][i] == 0)
                        continue;
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
    }
    
    return answer;
}