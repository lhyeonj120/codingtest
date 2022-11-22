#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int num[10];
int arr[10];

void permutation(int idx, int cnt){
    if(cnt == M){
        for(int i = 0; i < M; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    int tmp = 0;
    for(int i = idx; i < N; i++){
        if(tmp != num[i]){
            arr[cnt] = num[i];
            tmp = arr[cnt];
            permutation(i, cnt + 1);
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