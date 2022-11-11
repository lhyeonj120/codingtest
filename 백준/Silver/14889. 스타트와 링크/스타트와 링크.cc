#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

int N;
int S[21][21];
bool check[21];
int minRes = 200;

void DFS(int cnt, int num){
    if(cnt == N / 2){
        int start = 0, link = 0;
        
        for(int i = 1; i <= N; i++)
            for(int j = 1; j <= N; j++){
                if(check[i] && check[j])
                    start += S[i][j];
                if(!check[i] && !check[j])
                    link += S[i][j];
            }
        minRes = min(minRes, abs(start - link));
        return;
    }
    for(int i = num; i < N; i++){
        check[i] = true;
        DFS(cnt + 1, i + 1);
        check[i] = false;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++)
            cin >> S[i][j];
    
    DFS(0, 1);
    
    cout << minRes;
    
    return 0;
}