#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char** argv)
{
	int N;
    vector<int> v;
    cin >> N;
    
    for(int i = 0; i < N; i++){
        int m;
        cin >> m;
        v.push_back(m);
    }
    sort(v.begin(), v.end());
    cout << v[N / 2];
        
	return 0;
}