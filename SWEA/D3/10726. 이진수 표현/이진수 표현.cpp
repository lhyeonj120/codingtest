#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	//freopen("input.txt", "r", stdin);
	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int N, M;
        string res = "ON";
        cin >> N >> M;
        
       	int a = 0;
        for(int i = 0; i < N; i++)
            a |= (1 << i);
        
        if((a & M) != (1 << N) - 1)
            res = "OFF";
        
        cout << '#' << test_case << ' ' << res << '\n';
	}
	return 0;
}