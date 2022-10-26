#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string a, string b){
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> nums;
    
    for(int i = 0; i < numbers.size(); i++)
        nums.push_back(to_string(numbers[i]));
    
    sort(nums.begin(), nums.end(), cmp);
    
    for(auto num : nums){
        answer += num;
        if(answer == "0")
            break;
    }
            
    return answer;
}