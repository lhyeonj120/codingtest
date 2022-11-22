#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int num[10];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, M;
    cin >> N >> M;
    for(int i = 0; i < N; i++)
        cin >> num[i];
    sort(num, num + N);
    vector<int> v;
    for(int i = 0; i < M; i++)
        v.push_back(0);
    for(int i = 0; i < N - M; i++)
        v.push_back(1);
    do{
        for(int i = 0; i < N; i++)
            if(v[i] == 0)
                cout << num[i] << ' ';
        cout << '\n';
    } while(next_permutation(v.begin(), v.end()));
    
    return 0;
}