#include <iostream>
using namespace std;

int n, s;
int cnt;
int arr[22];

void func(int cur, int curSum){
    if(cur == n){
        if(curSum == s)
            cnt++;
        return;
    }
    func(cur + 1, curSum);
    func(cur + 1, curSum + arr[cur]);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> s;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    func(0, 0);
    if(s == 0)
        cnt--;
    
    cout << cnt;
    return 0;
}