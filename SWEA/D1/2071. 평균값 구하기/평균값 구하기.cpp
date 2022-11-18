#include<iostream>
#include <cmath>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	//freopen("input.txt", "r", stdin);
	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int n, sum = 0;
        for(int i = 0; i < 10; i++){
            cin >> n;
            sum += n;
        }
        cout << '#' << test_case << ' ' << round(sum / 10.0) << '\n';
	}
	return 0;
}