#include <iostream>
#include <algorithm>
using namespace std;

int num[10];
int N, M;
int arr[10];
bool used[10];

void permutation(int cnt){
    if(cnt == M){
        for(int i = 0; i < M; i++)
            cout << num[arr[i]] << ' ';
        cout << '\n';
        return;
    }
    for(int i = 0; i < N; i++){
        if(!used[i]){
            arr[cnt] = i;
            used[i] = true;
            permutation(cnt + 1);
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
    permutation(0);
    
    return 0;
}