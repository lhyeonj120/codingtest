#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int num[10];
int arr[10];

void permutation(int cnt){
    if(cnt == M){
        for(int i = 0; i < M; i++)
            cout << num[arr[i]] << ' ';
        cout << '\n';
        return;
    }
    for(int i = 0; i < N; i++){
        arr[cnt] = i;
        if(cnt >= 1 && arr[cnt - 1] > arr[cnt])
            continue;
        permutation(cnt + 1);
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