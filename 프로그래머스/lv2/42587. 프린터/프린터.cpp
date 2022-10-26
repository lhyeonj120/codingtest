#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<int> q;
    vector<int> sorted;
    
    for(int i = 0; i < priorities.size(); i++)
        q.push(i);
    
    while(!q.empty()){
        int idx = q.front();
        q.pop();
        
        if(priorities[idx] != *max_element(priorities.begin(), priorities.end()))
            q.push(idx);
        else{
            sorted.push_back(idx);
            priorities[idx] = 0;
        }
    }
    
    for(int i = 0; i < sorted.size(); i++)
        if(sorted[i] == location){
            answer = i + 1;
            break;
        }
    
    return answer;
}