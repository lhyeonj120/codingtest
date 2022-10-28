#include <iostream>
using namespace std;

int func(int n, int r, int c){
    if(n == 0)
        return 0;
    int half = 1<<(n - 1);
    // (r, c)가 1번 사각형에 들어갈 때
    if(r < half && c < half)
        return func(n - 1, r, c);
    // (r, c)가 2번 사각형에 들어갈 때
    if(r < half && half <= c)
        return half * half + func(n - 1, r, c - half);
    // (r, c)가 3번 사각형에 들어갈 때
    if(half <= r && c < half)
        return 2 * half * half + func(n - 1, r - half, c);
    // (r, c)가 4번 사각형에 들어갈 때
    return 3 * half * half + func(n - 1, r - half, c - half);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, r, c;
    cin >> n >> r >> c;
    cout << func(n, r, c);
    
    return 0;
}