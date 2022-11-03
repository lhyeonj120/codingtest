#include <iostream>
using namespace std;

int n, m;
int arr[8];
bool used[8];

void func(int idx){
    if(idx == m){
        for(int i = 0; i < m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
    }
    for(int i = 0; i < n; i++){
        if(!used[i]){
            arr[idx] = i + 1;
            used[i] = true;
            func(idx + 1);
            used[i] = false;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    
    func(0);
    
    return 0;
}