#include <iostream>
#include <cstdlib>
using namespace std;

int N;
int T[16];
int P[16];
bool check[16];
int maxProfit;

void DFS(int day){
    if(day > N){
        int sum = 0;
        for(int i = 1; i <= N; i++)
            if(check[i])
                sum += P[i];
        
        maxProfit = max(maxProfit, sum);
        return;
    }
    for(int i = day; i <= N; i++){
        if(i + T[i] <= N + 1)
            check[i] = true;
        DFS(i + T[i]);
        if(check[i])
            check[i] = false;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    for(int i = 1; i <= N; i++)
        cin >> T[i] >> P[i];
    
    DFS(1);
    cout << maxProfit;
    
    return 0;
}