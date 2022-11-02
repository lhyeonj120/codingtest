#include <iostream>
using namespace std;

char pattern[2300][2300];

void drawStar(int x, int y, int n){
    if(n == 1){
        pattern[x][y] = '*';
        return;
    }
    n /= 3;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++){
            if(i == 1 && j == 1)
                continue;
            drawStar(x + i * n,  y + j * n, n);
        }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    for(int i = 0; i < N; i++)
        fill(pattern[i], pattern[i] + N, ' ');
    
    drawStar(0, 0, N);
    
    for(int i = 0; i < N; i++)
        cout << pattern[i] << '\n';
    
    return 0;
}