#include <iostream>
using namespace std;

int N, M;
int seq[10];

void func(int cnt){
    if(cnt == M){
        for(int i = 0; i < M; i++)
            cout << seq[i] << ' ';
        cout << '\n';
        return;
    }
    for(int i = 1; i <= N; i++){
        seq[cnt] = i;
        func(cnt + 1);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;
    func(0);
    
    return 0;
}