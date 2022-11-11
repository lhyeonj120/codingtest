#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int A[12];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    vector<char> op;
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> A[i];
    for(int i = 0; i < 4; i++){
        int m;
        char c;
        cin >> m;
        switch(i){
            case 0:
                c = '+';
                break;
            case 1:
                c = '-';
                break;
            case 2:
                c = '*';
                break;
            case 3:
                c = '/';
                break;
        }
        for(int j = 0; j < m; j++)
            op.push_back(c);
    }
    
    int maxRes = -1000000000, minRes = 1000000000;
    sort(op.begin(), op.end());
    do{
        int res = A[0];
        for(int i = 0; i < N - 1; i++){
            switch(op[i]){
                case '+':
                    res += A[i + 1];
                    break;
                case '-':
                    res -= A[i + 1];
                    break;
                case '*':
                    res *= A[i + 1];
                    break;
                case '/':
                    res /= A[i + 1];
                    break;
            }
        }
        maxRes = max(maxRes, res);
        minRes = min(minRes, res);
    } while(next_permutation(op.begin(), op.end()));
    
    cout << maxRes << '\n' << minRes;
    
    return 0;
}