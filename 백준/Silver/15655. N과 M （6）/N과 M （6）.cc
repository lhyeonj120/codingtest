#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int num[10];
bool used[10];

void permutation(int idx, int cnt){
    if(cnt == M){
        for(int i = 0; i < N; i++)
            if(used[i])
                cout << num[i] << ' ';
        cout << '\n';
        return;
    }
    for(int i = idx; i < N; i++){
        if(!used[i]){
            used[i] = true;
            permutation(i + 1, cnt + 1);
            used[i] = false;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;
    for(int i = 0; i < N; i++)
        cin >> num[i];
    sort(num, num + N);
    permutation(0, 0);
    
    return 0;
}