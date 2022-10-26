#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    vector<int> vec = priorities;
    
    while(true){
        int max = *max_element(vec.begin(), vec.end());
        if(vec[0] != max){
            vec.push_back(vec[0]);
            vec.erase(vec.begin());
            location = location == 0 ? vec.size() - 1 : location - 1;
        }
        else{
            vec.erase(vec.begin());
            answer++;
            if(location == 0)
                break;
            location--;
        }
        cout << location << ' ';
    }
    
    return answer;
}