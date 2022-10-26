#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool cmp1(const pair<string, int>& a, const pair<string, int>& b){
    return a.second > b.second;
}

bool cmp2(const pair<int, int>& a, const pair<int, int>& b){
    if(a.second == b.second)
        return a.first < b.first;
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> genre_m;
    
    for(int i = 0; i < genres.size(); i++)
        genre_m[genres[i]] += plays[i];
    
    vector<pair<string, int>> vec(genre_m.begin(), genre_m.end());
    sort(vec.begin(), vec.end(), cmp1);
    
    for(auto v : vec){
        auto iter = find(genres.begin(), genres.end(), v.first);
        map<int, int> m;
        while(iter != genres.end()){
            int idx = iter - genres.begin();
            m[idx] = plays[idx];
            iter = find(iter + 1, genres.end(), v.first);
        }
        vector<pair<int, int>> sortVec(m.begin(), m.end());
        sort(sortVec.begin(), sortVec.end(), cmp2);
        if(sortVec.size() > 2)
            sortVec.erase(sortVec.begin() + 2, sortVec.end());
        for(auto sortv : sortVec)
            answer.push_back(sortv.first);
            
    }
    
    return answer;
}