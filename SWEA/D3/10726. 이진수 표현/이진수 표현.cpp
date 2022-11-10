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
        
       	int a = (1 << N) - 1;
        if((int)(M & a) != a)
            res = "OFF";

        cout << '#' << test_case << ' ' << res << '\n';
	}
	return 0;
}