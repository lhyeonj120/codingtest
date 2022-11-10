#include <iostream>
using namespace std;

int A[1000001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, B, C;
    long long res;
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> A[i];
    cin >> B >> C;
    
    res = N;
    for(int i = 0; i < N; i++){
        int m = A[i] - B;
        if(m > 0){
            res += m / C;
            if(m % C != 0)
                res++;
        }
    }
    cout << res;
    
    return 0;
}