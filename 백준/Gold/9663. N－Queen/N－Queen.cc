#include <iostream>
using namespace std;

int n;
int cnt;
bool used1[15];
bool used2[29];
bool used3[29];

void func(int cur){
    if(cur == n){
        cnt++;
        return;
    }
    for(int i = 0; i < n; i++){
        if(!used1[i] && !used2[cur + i] && !used3[cur - i + n - 1]){
            used1[i] = true;
            used2[cur + i] = true;
            used3[cur - i + n - 1] = true;
            func(cur + 1);
            used1[i] = false;
            used2[cur + i] = false;
            used3[cur - i + n - 1] = false;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    
    func(0);
    
    cout << cnt;
    
    return 0;
}