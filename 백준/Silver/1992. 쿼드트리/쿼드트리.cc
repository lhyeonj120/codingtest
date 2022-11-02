#include <iostream>
using namespace std;

string movie[65];
string res;

bool isAllSame(int x, int y, int n){
    for(int i = x; i < x + n; i++)
        for(int j = y; j < y + n; j++)
            if(movie[x][y] != movie[i][j])
                return false;
    return true;
}

void func(int x, int y, int n){
    if(isAllSame(x, y, n)){
        res += movie[x][y];
        return;
    }
    res += '(';
    n /= 2;
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            func(x + i * n, y + j * n, n);
    res += ')';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> movie[i];
    
    func(0, 0, N);
    
    cout << res;
    
    return 0;
}