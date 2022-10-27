#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    // 주식 가격, 인덱스 담을 스택
    stack<pair<int, int>> s;
    
    for(int i = 0; i < prices.size(); i++){
        if(s.empty()){
            s.push({prices[i], i});
            continue;
        }
        while(!s.empty() && s.top().first > prices[i]){
            answer[s.top().second] = i - s.top().second;
            s.pop();
        }
        s.push({prices[i], i});
    }
    
    while(!s.empty()){
        answer[s.top().second] = prices.size() - 1 - s.top().second;
        s.pop();
    }
    
    return answer;
}