#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
//     int answer = 0, remaining_weight = weight, idx = 0;
//     queue<int> bridge;
    
//     for(int i = 0; i < bridge_length; i++)
//         bridge.push(0);
    
//     while(true){
//         if(idx >= truck_weights.size())
//             break;
//         answer++;
//         int n = bridge.front();
//         bridge.pop();
//         remaining_weight += n;
//         if(remaining_weight >= truck_weights[idx]){
//             bridge.push(truck_weights[idx]);
//             remaining_weight -= truck_weights[idx++];
//         }
//         else{
//             bridge.push(0);
//         }
//     }
//     answer += bridge_length;
    int answer = 0, idx = 0, time = 0, total_weight = 0;
    // 트럭 무게, 다리를 건넌 시간
    queue<pair<int, int>> truck_move;
    
    while(true){
        if(weight >= total_weight + truck_weights[idx]){
            truck_move.push({truck_weights[idx], bridge_length + time + 1});
            total_weight += truck_weights[idx++];
        }
        if(idx >= truck_weights.size()){
            answer = truck_move.back().second;
            break;
        }
        else{
            time++;
            if(truck_move.front().second == time + 1){
                total_weight -= truck_move.front().first;
                truck_move.pop();
            }
        }
    }
    
    return answer;
}