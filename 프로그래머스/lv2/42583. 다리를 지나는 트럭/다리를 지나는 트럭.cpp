#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0, remaining_weight = weight, idx = 0;
    queue<int> bridge;
    
    for(int i = 0; i < bridge_length; i++)
        bridge.push(0);
    
    while(true){
        if(idx >= truck_weights.size())
            break;
        answer++;
        int n = bridge.front();
        bridge.pop();
        remaining_weight += n;
        if(remaining_weight >= truck_weights[idx]){
            bridge.push(truck_weights[idx]);
            remaining_weight -= truck_weights[idx++];
        }
        else{
            bridge.push(0);
        }
    }
    answer += bridge_length;
    
    return answer;
}