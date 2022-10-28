#include <iostream>
using namespace std;

// a : 출발 기둥 번호, b : 도착 기둥 번호, n : 옮길 원판 개수
void hanoi(int a, int b, int n){
    if(n == 1){
        cout << a << ' ' << b << '\n';
        return;
    }
    // 기둥 번호가 1, 2, 3 → 1 + 2 + 3 = 6 이므로 a와 b를 제외한 나머지 기둥 번호는 6 - a - b
    // n - 1개의 원판을 a 기둥에서 6 - a - b 기둥으로 옮기기
    hanoi(a, 6 - a - b, n - 1);
    // n번째 원판 옮기기
    cout << a << ' ' << b << '\n';
    // 6 - a - b 기둥에 있는 n - 1개의 원판을 b로 옮기기
    hanoi(6 - a - b, b, n - 1);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    // 2^n - 1
    cout << (1<<n) - 1 << '\n';
    hanoi(1, 3, n);
    
    return 0;
}