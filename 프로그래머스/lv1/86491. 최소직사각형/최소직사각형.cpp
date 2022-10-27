#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    vector<int> v1, v2;
    
    for(int i = 0; i < sizes.size(); i++)
        sort(sizes[i].begin(), sizes[i].end());
    
    for(auto size : sizes){
        v1.push_back(size[0]);
        v2.push_back(size[1]);
    }
    
    answer = *max_element(v1.begin(), v1.end()) * *max_element(v2.begin(), v2.end());
    
    return answer;
}