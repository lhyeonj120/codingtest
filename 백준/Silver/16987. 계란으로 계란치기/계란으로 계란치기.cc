#include <iostream>
using namespace std;

int N;
int s[10];
int w[10];
int mx, brokenEgg;

void breakEgg(int a){
    if(a == N){
        mx = max(mx, brokenEgg);
        return;
    }
    if(s[a] <= 0 || brokenEgg == N - 1){
        breakEgg(a + 1);
        return;
    }
    for(int i = 0; i < N; i++){
        if(a == i || s[i] <= 0)
            continue;
        s[a] -= w[i];
        s[i] -= w[a];
        if(s[a] <= 0)
            brokenEgg++;
        if(s[i] <= 0)
            brokenEgg++;
        breakEgg(a + 1);
        if(s[a] <= 0)
            brokenEgg--;
        if(s[i] <= 0)
            brokenEgg--;
        s[a] += w[i];
        s[i] += w[a];
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> s[i] >> w[i];
    
    breakEgg(0);
    cout << mx;
    
    return 0;
}