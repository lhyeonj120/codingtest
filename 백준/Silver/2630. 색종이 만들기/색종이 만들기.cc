#include <iostream>
using namespace std;

int paper[130][130];
int cnt[2];

bool isAllSameColor(int x, int y, int n){
    for(int i = x; i < x + n; i++)
        for(int j = y; j < y + n; j++)
            if(paper[x][y] != paper[i][j])
                return false;
    return true;
}

void func(int x, int y, int n){
    if(isAllSameColor(x, y, n)){
        cnt[paper[x][y]]++;
        return;
    }
    n /= 2;
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            func(x + i * n, y + j * n, n);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin >> paper[i][j];
    
    func(0, 0, N);
    
    for(int i = 0; i < 2; i++)
        cout << cnt[i] << '\n';
    
    return 0;
}