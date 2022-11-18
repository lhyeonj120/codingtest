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
        int n, m;
        cin >> n >> m;
        char op = n > m ? '>' : n == m ? '=' : '<';
        cout << '#' << test_case << ' ' << op << '\n';
	}
	return 0;
}